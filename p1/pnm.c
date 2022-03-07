/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

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


int verif_arguments(char *format, char *nom_fichier, int argc, char **argv){
   char *optstring = ":f:i:o:";

   	int val;
   	char *format;
   	char *nom_fichier;
      char *nom_sortie;
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



int gestion_en_tete(char *nom_fichier, char *lettre_magique, int *numero_magique, int *max, int *hor, int *ver){

   char *tmp;

   FILE **fp= fopen(nom_fichier, "r");
      if((*fp)== NULL)
         return -1;

//nombre magique
   fscanf((*fp), "%s", tmp);
   *lettre_magique =tmp[0];
   *numero_magique = atoi(&tmp[1]);

//dimensions
   fscanf((*fp), "%d %d", hor, ver);

   if(numero_magique == 3)
      (*hor) *= 3;
   
//aleur maximum
   fscanf((*fp), "%d", max);

return 0;

}// fin gestion de l en tete



int load_pnm(PNM **image, char* filename) {



   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

