/**
 * pnm.c
 *
 * Ce fichier contient les définitions de types et
 * les fonctions de manipulation d'images PNM.
 *
 * @author: Matagne Luca S190632
 * @date: 23/01/21
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>


#include "pnm.h"

/**
 * Définition du type opaque PNM
 *
 */
struct PNM_t {
   int **matrice;
   int colonnes;
   int lignes;
   int puissance;
   int type;


};

//On verifie les arguments entres par l utilisateur
int verifArgu(char type[], char filename[], int argc, char *argv[]){
   int val;
   char *optstring= "f:i:o:";

   while((val=getopt(argc, argv, optstring)) != EOF){
      switch(val){
         case 'f':
            printf("help\n"); break;
         case 'i':
            printf("input: %s\n", optarg); break;
         case 'o':
            printf("output: %s\n", optarg); break;

         return -1;

     }// fin if

   }// fin while



   if(argc != 4){
     return -1;

   }//fin if

   strcpy(type, argv[2]);
   int a=strlen(argv[3]);
   if(a>21){
     return -1;

   }//fin if a

   int b = 0;
   if(type[b]!= 'p' || type[b+1] != 'g' || type[b+1] != 'b' || type[b+2] != 'm' ){
      printf("Erreur au niveau du format encodé par l'utilisateur\n");
      return -2;

   }//fin if

// Gestion des majuscules du format
   strcpy(filename, argv[3]);
   int c = 0;
   while(c<=2){
      switch(type[c]){
         case'P':
            type[c]='p'; break;
          case'B':
             type[c]='b'; break;
          case'G':
             type[c]='g'; break;
          case'M':
            type[c]='m'; break;
          default:
             return -3;

      }//fin switch

      c++;
   }//fin while c

   int d = 0;
   while(filename[d]!= '.')
     d++;
   if(filename[d+1] != 'p' || filename[d+2] != 'n'|| filename[d+2] != 'b' || filename[d+3] != 'm' ){
      printf("L'extension du fichier n'est pas bonne\n");
      return -2;
   }//fin while d

   if(type[1] == filename[d+2]){
   }else{
      printf("Le format encodé et l'extension du fichier ne correspondent pas\n");
      return -1;
   }//fin else

   return 0;

}//fin fct verifArgu

// On gere les donnes en en tete du fichier
int gestionEnTete(int *colonnes, int *lignes, int *puissance, int *typeChiffre, char *typeLettre, char filename[], FILE **fp){

   char tempon[100];
   (*fp) = fopen(filename, "r");
   if ((*fp) == NULL)
      return -1;

//format p1 p2 p3
   fscanf((*fp),"%s", tempon);
   if(tempon[0] == '#'){
     fgets(tempon, 100, (*fp));
     fscanf((*fp), "*%c %d",typeLettre, typeChiffre);
   }else{
      *typeLettre = tempon[0];
      *typeChiffre = atoi(&tempon[1]);

   }//fin else

//dimmensions de l image
   fscanf((*fp),"%s", tempon);
   if(tempon[0] == '#'){
     fgets(tempon, 100, (*fp));
     fscanf((*fp), "%d %d",colonnes, lignes);
   }else{
      *colonnes = atoi(tempon);
      fscanf((*fp), "%d", lignes);

}//fin else


//puissance du gris ou 255 pour les ppm
   if(*typeChiffre == 2 || *typeChiffre == 3){
      fscanf((*fp),"%s", tempon);
      if(tempon[0] == '#'){
         fgets(tempon, 100, (*fp));
         fscanf((*fp), "%d", puissance);
      }else{
          *puissance = atoi(tempon);
      }//fin else
      if(*typeChiffre != 2){
         (*colonnes) *= 3;

      }// fin if

   }//fin if

}//fin gestion en tete

//On alloue la mémoire
PNM *allocDynamique(int colonnes, int lignes, int puissance, int typeChiffre){
   PNM *image = (PNM*)malloc(sizeof(PNM));
   image->matrice = (int**)malloc(colonnes*sizeof(int*));
   for(int e = 0; e < colonnes ; e++){
      image->matrice[e] = (int*)malloc(lignes*sizeof(int));
   }//fin for

   image->lignes = lignes;
   image->puissance = puissance;
   image->type = typeChiffre;
   image->colonnes = colonnes;
   if(typeChiffre == 3)
      image->colonnes = (colonnes/3);

   return image;

}//fin allocDynamique

//On charge l'image
int load_pnm(PNM **image, char* filename) {
   char typeLettre;
   int typeChiffre;
   char tempon[100];
   int colonnes;
   int lignes;
   int puissance;
   FILE* fp;
   int secondTempon;
   int d = 0;
   int h = 0;
   int i = 0;

   d = gestionEnTete(&colonnes, &lignes, &puissance, &typeChiffre, &typeLettre, filename, &fp);
   if(d == -1)
      return -1;

   *image = allocDynamique(colonnes, lignes, puissance, typeChiffre);

   for(h = 0; h < lignes ; h++){
      for(i = 0; i < colonnes; i++){
         fscanf(fp, "%s", tempon);
         if(tempon[0] == '#'){
            fgets(tempon, 100, (fp));
            fscanf((fp), "%s", tempon);
         }else{
            secondTempon = atoi(tempon);
            (*image)->matrice[i][h] = secondTempon;

          }//fin else

      }//fin for 'i'

   }//fin for 'h'

   fclose(fp);
   return 0;
}//fin load_pnm

int write_pnm(PNM *image, char* filename) {
   FILE *fp = fopen(filename, "w");
   if(fp == NULL)
      return -1;

   fprintf(fp, "P%d\n", image->type);
   fprintf(fp, "%d %d\n", image->colonnes, image->lignes);

   if(image->type == 2 || image->type == 3)
      fprintf(fp, "%d\n", image->puissance);

   if(image->type == 3){
      for(int h = 0; h<(image->lignes); h++){
         for(int i =0; i<(image->colonnes*3); i++){
            fprintf(fp,"%d\n", image->matrice[i][h]);
         }//fin for 'i'
         fprintf(fp,"\n");
      } //fin for 'h'
   }else{
      for(int h = 0;h<(image->lignes); h++){
         for(int i =0; i<(image->colonnes); i++){
            fprintf(fp,"%d\n", image->matrice[i][h]);
         }//fin for 'i'
         fprintf(fp,"\n");
      }// fi  for 'h'
   }//fin else

   fclose(fp);
   return 0;
}//fin write_pnm

//Celui qui cree est celui qui detruit
int libererEspace(PNM *image){
   if(image == NULL)
      return -1;

   if(image->type == 3){
      for(int h = 0; h<((image->colonnes)*3); h++){
         if(image->matrice[h] == NULL)
            return -1;
         free(image->matrice[h]);
      }//fin for 'h'
      free(image->matrice);
      free(image);
   }else{
     for(int h = 0; h<(image->colonnes); h++){
        if(image->matrice[h] == NULL)
           return -1;
        free(image->matrice[h]);
     }//fin for 'h'
     free(image->matrice);
     free(image);

     return 0;
   }//fin else




}//fin libererEspace
