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

    char lettre;;
    int numero;
    int largeur;
    int longueur;
    int max = 0;
    FILE* fp;
    char tmp[100];
    int tmp2;

    //lecture des dimensions

    int i= lecturedimensions(&lettre, &numero, &largeur, &longueur, &max, filename, &fp);
    if(i == -1)
        return -1;

    *image= allocation_struct(largeur, longueur, max, numero);

    for(int i = 0; i < longueur; i++){
        for(int j = 0; j<largeur; j++){
            fscanf(fp, "%s", tmp);

            if(tmp[0] == '#'){
                fgets(tmp, 100, fp);
                fscanf(fp, "%s", tmp);
                tmp2= atoi(tmp);
                (*image)->tab[j][i] = tmp2;
            }
            else{
                tmp2= atoi(tmp);
                (*image)->tab[j][i] = tmp2;

            }
        }
    }

    fclose(fp);
    return 0;
}

int write_pnm(PNM *image, char* filename) {
    FILE *fp= fopen(filename,"w");
    if(fp == NULL)
        return -1;


    fprintf(fp, "%d\n", image->type);
    fprintf(fp, "%d %d\n", image->largeur, image->longueur);

    if(image->type != 1)
        fprintf(fp, "%d\n", image->max);
    
    if(image->type == 3){
        for(int i=0; i<(image->longueur);i++){
            for(int j; j<(image->largeur);j++){
                fprintf(fp, "%d ", image->tab[j][i]);
            }
            fprintf(fp, "\n");
        }
    }
    fclose(fp);
    return 0;
}

int freestruct(PNM *image){
    if (image == NULL)
        return -1;

    if(image->type==3){
        for(int i = 0; i<((image->largeur)*3); i++){
            if(image->tab[i] == NULL)
                return -1;
            free(image->tab[i]);
        }
        free(image->tab);
        free(image);
    }else{
        for(int i=0; i<image->largeur; i++){
           if(image->tab[i] == NULL)
                return -1;
            free(image->tab[i]);
        }
        free(image->tab);
        free(image); 
    }
    return 0;
}

int test_caract(char *filename){
    char *caract_interdits = "/\\ \":*?<>|";
    for(int i=0; filename[i] |= '\0'; i++){
        for(int j=0; filename[j] |= '\0';j++){
            if(filename[i] == caract_interdits[j]){
                return -1;
            }
        }
    }
    return 0;
}


