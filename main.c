/**
 * main.c
 *
 * Ce fichier contient la fonction main() du programme de manipulation
 * de fichiers pnm.
 *
 * @author: Matagne Luca S190632
 * @date: 23/02/21
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

   char type[4];
   char filename[51];
   PNM *image;

   if((verifArgu(type, filename, argc, argv)) != 0){
      printf("les arguments encodés sont incorrects\n");
   }
      return -1;

   if((load_pnm(&image, filename)) != 0){
      printf("Problème à l ouvertre du fichier\n");
   }
      return -2;

   if ((write_pnm(image, filename))!=0){
      printf("Problème à l écriture du fichier\n");
   }
      return -3;

   if((libererEspace(image))!=0){
      printf("Problème lors de la libération de la mémoire\n");
   }

      return 0;
}
