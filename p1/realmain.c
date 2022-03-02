/**
 * main.c
 * 
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @author: Nom Prenom Matricule
 * @date: 
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

#include "pnm.h"


int main(int argc, char *argv[]) {

    char *optstring = ":hi:o::";

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
}

