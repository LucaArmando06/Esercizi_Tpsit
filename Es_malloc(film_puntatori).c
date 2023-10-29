/*
author: Luca Armando
date:
es.
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#define DIM_RIGA 200    

typedef struct{
    int num;
    char* titolo; //char[10]
    char* genere;
    int anno;
    char* disponibilita;
}film;

int contaRighe(film array_film[], char filename[]){
    FILE *fp;
    int nRighe = 0;
    char riga[DIM_RIGA];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
    } else {
        while(fgets(riga, DIM_RIGA, fp)){
            nRighe++;
        }
    }
    fclose(fp);
    return nRighe;
}

void caricaFilm(film array_film[], char filename[], int nRighe){
    FILE *fp;
    char riga[DIM_RIGA];
    char* campo;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
        exit(1); //esce dal programma
    } else {
        for(film *p = array_film; p < array_film + nRighe; p++){  // fgets() per leggere tutta la linea
            campo = strtok(riga, ",");  //strtok() per spezzare i campi
            p->num = atoi(campo);  //atoi() converte ad intero

            campo = strtok(NULL, ",");
            p->titolo = strdup(campo);  //strdup() ritorna la copia

            campo = strtok(NULL, ",");
            p->genere = strdup(campo);

            campo = strtok(NULL, ",");
            p->anno = atoi(campo);

            campo = strtok(NULL, ",");
            p->disponibilita = strdup(campo);
        }
    }
    fclose(fp);
}

void stampaFilm(film array_film[], int nRighe) {
   for (film *p = array_film; p < array_film + nRighe; p++){
        printf("%d %s %s %d %s\n", p->num, p->titolo, p->genere, p->anno, p->disponibilita);
    }
}

int main(){
    char filename[] = "listafilm.csv";   
    film *array_film;
     
    int nRighe = contaRighe(array_film, filename);
   
    array_film = (film*) malloc (nRighe * sizeof(film)); 
     
    caricaFilm(array_film, filename, nRighe);
    
    stampaFilm(array_film, nRighe);
        
    free(array_film);
     
    return 0;
}  
