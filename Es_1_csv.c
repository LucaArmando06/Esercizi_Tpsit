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
#define NUM_RIGHE 20000

typedef struct{
    int num;
    char* titolo; //char[10]
    char* genere;
    int anno;
    char* disponibilita;
}film;

int main(){
    char filename[] = "listaFilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo; //variabile per leggere i campi di una riga
    film array_film[NUM_RIGHE];
    int counter = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
        exit(1); //esce dal programma
    } else {
        while(fgets(riga, DIM_RIGA, fp)){  // fgets() per leggere tutta la linea

            campo = strtok(riga, ",");  //strtok() per spezzare i campi
            array_film[counter].num = atoi(campo);  //atoi() converte ad intero

            campo = strtok(NULL, ",");
            array_film[counter].titolo = strdup(campo);  //strdup() ritorna la copia

            campo = strtok(NULL, ",");
            array_film[counter].genere = strdup(campo);

            campo = strtok(NULL, ",");
            array_film[counter].anno = atoi(campo);

            campo = strtok(NULL, ",");
            array_film[counter].disponibilita = strdup(campo);

            counter++;
        }

        for(int k = 0; k < counter; k++){
            printf("%d %s %s %d %s", array_film[k].num, array_film[k].titolo, array_film[k].genere, array_film[k].anno, array_film[k].disponibilita);
        }
    }

    return 0;
}
