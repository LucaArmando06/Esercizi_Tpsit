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

void caricaFilm(film array_film[], char filename[]){
    FILE *fp;
    char riga[DIM_RIGA];
    char* campo;
    int counter = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
        exit(1); //esce dal programma
    } else {
        while(fgets(riga, DIM_RIGA, fp)){  // fgets() per leggere tutta la linea

            campo = strtok(riga, ",");  //strtok() per spezzare i campi
            (array_film + counter)->num = atoi(campo);  //atoi() converte ad intero

            campo = strtok(NULL, ",");
            (array_film + counter)->titolo = strdup(campo);  //strdup() ritorna la copia

            campo = strtok(NULL, ",");
            (array_film + counter)->genere = strdup(campo);

            campo = strtok(NULL, ",");
            (array_film + counter)->anno = atoi(campo);

            campo = strtok(NULL, ",");
            (array_film + counter)->disponibilita = strdup(campo);

            counter++;
        }
    }
    fclose(fp);
}

void cercaAnno(film array_film[], int anno, int nRighe){
    for(int k = 0; k < nRighe; k++){
        if((array_film + k)->anno == anno)                
            printf("%d %s %s %d %s", (array_film + k)->num, (array_film + k)->titolo, (array_film + k)->genere, (array_film + k)->anno, (array_film + k)->disponibilita);
    }
}

int main(){
    char filename[] = "listafilm.csv";   
    film *array_film;
    int anno;

    int nRighe = contaRighe(array_film, filename);

    array_film = (film*) malloc (nRighe * sizeof(film)); 

    caricaFilm(array_film, filename);

    printf("inserisci un anno: ");
    scanf("%d", &anno);

    cercaAnno(array_film, anno, nRighe);

    free(array_film);

    return 0;
}