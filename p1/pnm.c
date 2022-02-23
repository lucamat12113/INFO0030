#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pnm.h"


/**
 * Définition du type opaque PNM
 *
 */
struct PNM_t {

   int type;
   int largeur;
   int longueur;
   int max;
   int **tab;

};




int lecturedimensions(char *lettre, int *numero,int *largeur, int *longueur, int *max, char *nomfichier, FILE **fp){

    char tmp[100];

    (*fp)=fopen(nomfichier, "r");
    if((*fp) == NULL)
        return -1;

    //premiere ligne

    fscanf((*fp), "%s", tmp);
    if(tmp[0] == "#"){
         fgets(tmp, 100, (*fp));
         fscanf((*fp), "%c %d", lettre, numero);
    }
    else{
        *lettre= tmp[0];
        *numero= atoi(&tmp[1]);
    }

    //deuxieme ligne

    fscanf((*fp), "%s", tmp );
    if(tmp[0]== "#"){
        fgets(tmp, 100, (*fp));
        fscanf((*fp), "%d %d", largeur, longueur);
    }
    else{
        *largeur= atoi(tmp);
        fscanf((*fp), "%d", longueur);
    }

    //trosieme ligne

    if(*numero != 1){
        fscanf((*fp), "%s", tmp);
        if(tmp[0]== "#"){
            fgets(tmp, 100, (*fp));
            fscanf((*fp), "%d", max);
        }else{
        *max= atoi(tmp);
        }

    }// fin if

    if(*numero == 3)
        (*largeur)*=3;

    return 0;

}// fin dimensions


PNM *allocation_struct(int largeur, int longueur, int max, int numero){

    PNM *image= malloc(sizeof(PNM));
    image->tab= malloc(largeur*sizeof(int*));

    for(int i; i<largeur; i++){
        image->tab[i]= malloc(longueur*sizeof(int));
    }//fin for

    image->type = numero;
    image->largeur = largeur;
    if(numero == 3)
        image->largeur= largeur/3;
    image->longueur = longueur;
    image->max = max;

    return image;



}// fin allocation


int load_pnm(PNM **image, char* filename) {

   /* Insérez le code ici */

   return 0;
}

int write_pnm(PNM *image, char* filename) {

   /* Insérez le code ici */

   return 0;
}
