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
                  *nom_fichier = optarg;
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
                  *nom_fichier = optarg;
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

   // verification dela correspondance des formats
   strcpy(format, argv[2]);
   strcpy(nom_fichier, argv[3]);
   strcpy(nom_sortie, argv[4]);

   for(i=0; nom_fichier[i]!='.'; i++){}//fin for(i)

   for(j=0; nom_sortie[j]!='.'; i++){}// fin for(j)

   if(format[i] != nom_fichier[i+2]){
      printf("le format encodé et l'extension du fichier d'entrée ne correspondent pas \n");
      return -1;
   }// fin if

   if(format[i] != nom_sortie[j+2]){
      printf("le format encodé et l'extension du fichier de sortie ne correspondent pas \n");
      return -1;
   }// fin if

   if(nom_fichier[i+2] != nom_sortie[j+2]){
      printf("le format encodé et l'extension du fichier de sortie ne correspondent pas \n");
      return -1;

return 0;
}// fin verification des arguments


int load_pnm(PNM **image, char* filename) {



   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

