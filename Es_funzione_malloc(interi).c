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
#define NUM 10

void caricaVett(int vett[]){
    for(int k = 0; k < NUM; k++){
        printf("Inserisci un numero[%d]: ", k);
        scanf("%d", (vett + k));
    }
}

void stampaVett(int vett[]){
    for(int k = 0; k < NUM; k++){
        printf("%d ", (*(vett + k)));
    }
}

int main(){
    int *vett;

    vett = (int*) malloc (NUM * sizeof(int));

    caricaVett(vett);

    stampaVett(vett);

    free(vett);

    return 0;
}