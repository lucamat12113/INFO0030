/**
 * main.c
 * 
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @author: Matagne Luca s190632
 * @date: 07-03-2022
 * @projet: INFO0030 Projet 1
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>

#include "pnm.h"


int main(int argc, char **argv) {

	char *format;
	char *nom_fichier;
	PNM *image;


	int a= verif_arguments(format, nom_fichier, argc, argv);
	if(a!=0)
		return -1;
	
	int b= load_pnm(image, nom_fichier);
	if(b!=0)
		return -2;

	return 0;
}

