/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: Matagne Luca s190632
 * @date: 07-03-2022
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>

#include "pnm.h"


/**
 * Définition du type opaque PNM
 *
 */
struct PNM_t {

   int hor;//dimension horizontal
   int ver;//dimension vertical
   int max;
   int **tab;
   int type;

};


int verif_arguments(char **format, char **nom_fichier, char **nom_sortie, int argc, char **argv){
   char *optstring = ":f:i:o:";

   	int val;
      
      int i;
      int j;

   	while((val=getopt(argc, argv, optstring))!=EOF){
   		switch(val){
   			case 'f':
               if(optarg!= NULL){
                  *format = optarg;
   				   printf("Le format est %s\n",optarg);
               }
   				break;
   			case 'i':
               if(optarg!= NULL){
                  *nom_fichier = optarg;
   				   printf("input %s\n", optarg);
               }
   				break;
   			case 'o':
               if(optarg!= NULL){
                  *nom_sortie = optarg;
   				   printf("output %s\n", optarg);
               }
   				break;
   			case ':':
   				printf("Missing arguments for %c\n", optopt);
   				break;
   			case '?':
   				printf("Unknown option: %c!\n", optopt);
   				break;
   		}//fin switch
   	}//fin while


return 0;
}// fin verification des arguments



int gestion_en_tete(char *nom_fichier, int *numero_magique, int *max, int *hor, int *ver){

   char tmp[100];
   FILE *fp;


   fp= fopen(nom_fichier, "r");
      if(fp== NULL)
         return -1;

//nombre magique
   fscanf(fp, "%s", tmp);
   if(tmp[0]=='p'){
      numero_magique = atoi(tmp[1]);
   }else{
      return -1;
   }


//dimensions
   fscanf(fp, "%d %d", hor, ver);

   if(numero_magique == 3)
      (*hor) *= 3;


//valeur maximum
   fscanf(fp, "%d", max);


   
return 0;

}// fin gestion de l en tete

int alloc_memoire(PNM *image, int hor, int ver, int max, int numero_magique){

   
   int m;
   image= malloc(sizeof(PNM));
   if(image == NULL)
      return -1;
   image->tab= malloc(hor*sizeof(int*));
   if(image->tab == NULL)
      return -1;
   for(m=0; m<hor; m++){
      image->tab[m]=malloc(ver*sizeof(int));
   }

   image->type= numero_magique;
   if(numero_magique == 3){
      image->hor= (hor/3);
   }else{   
      image->hor= hor;
   }
   image->max= max;//max verstappen est champion du monde mai love ferrari
   image->ver= ver;
   return 0;


}//fin allocation de la memoire

int load_pnm(PNM **image, char* filename) {

   
   char lettre_magique;
   int numero_magique;
   int hor;
   int ver;
   int max;
   FILE *fp;

   int o;
   int p;
   char tmp2[100];

   
   gestion_en_tete(filename, &numero_magique, &max, &hor, &ver);

   image = alloc_memoire(image, hor, ver, max, numero_magique);

   for(o=0; o<ver; o++){
      for(p=0; p<hor; p++){
         fscanf(fp, "%s", tmp2);
         if(tmp2[0]!='#'){
            fscanf(fp, "%d", (*image)->tab[p][o]);
         }else{            
            fgets(tmp2, hor, fp);
         }


      }//fin for(p)

   }//fin for(o)
   fclose(fp);
   return 0;
}// fin load()

int write_pnm(PNM *image, char* filename) {


   int f;
   int g;
   FILE *fp =fopen(filename, "w");
   if(fp== NULL)
      return -1;

   fprintf(fp, "P%d\n%d %d\n", image->type, image->hor, image->ver);
   if(image->type>1)
      fprintf(fp, "%d\n", image->max);

   if(image->type<2){
      for(g=0; g<image->ver; g++){
         for(f=0; f<image->hor; f++){
            fprintf(fp, "%d", image->tab[f][g]);
         }//fin for(f)
         fprintf(fp,"\n");
      }//fin for(g)
   }else{
      for(g=0; g<image->ver; g++){
         for(f=0; f<((image->hor)*3); f++){
            fprintf(fp, "%d", image->tab[f][g]);
         }//fin for(f)
         fprintf(fp,"\n");
      }//fin for(g)

   }

   fclose(fp);
   return 0;
}//fin write()


