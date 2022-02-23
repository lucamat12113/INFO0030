/**
 * pnm.c
 * 
 * Ce fichier contient les définitions de types et 
 * les fonctions de manipulation d'images PNM.
 * 
 * @author: Matagne Luca S190632
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

   /* Insérez ici les champs de la structure PNM */

};



//verification des arguments
int VerifArgu(int argc, char **argv){

const char *optstring = ":hi:o::";
int val;

while((val=getopt(argc, argv, optstring))!=EOF){
	switch(val){
		case 'h':
			printf("help\n");
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

return 0;
}//fin verif argu

int load_pnm(PNM **image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}
