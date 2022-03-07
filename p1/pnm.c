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
      int i;

   	while((val=getopt(argc, argv, optstring))!=EOF){
   		switch(val){
   			case 'f':
   				printf("Le format est %s\n",optarg);
   				break;
   			case 'i':
   				printf("input %s\n", optarg);
   				break;
   			case 'o':
   				printf("output %s\n", optarg);
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
   format = argv[2];
   nom_fichier = argv[3];

   for(i=0; nom_fichier[i]!='.'; i++){
   }//fin for(i)

   if(format[1] != nom_fichier[i+2]){
      printf("le format encodé et l'extension du fichier ne correspondent pas \n");
      return -1;
   }// fin if

return 0;
}// fin verification des arguments


int load_pnm(PNM **image, char* filename) {



   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

