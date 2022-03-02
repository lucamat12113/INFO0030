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


    char type[4];
    char filename[21];
    PNM *image;


    int j = test_caract(filename);
    if(j == -1){
        printf("erreur dans la  ligne d'execution: ./pnm -f <format> <fichier>\n");
        return -2;
    }

    int k = load_pnm(&image, filename);
    if(k == -1){
        printf("erreur à l'ouverture du  fichier\n");
        return -3;
    }

    int l = write_pnm(image, filename);
    if(l = -1){
        printf("erreur à l'écriture du fichier\n");
        return -4;
    }

    int m = freestruct(image);
    if(m == -1){
        printf("erreur lors de la lbération de l'espace\n");
        return -5;
    }


return 0;

}// fin main