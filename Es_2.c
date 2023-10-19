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
#define DIM 10

void caricaVett(int vett[]){
    for(int k = 0; k < DIM; k++){
        printf("inserisci un numero [%d]: ", k);
        scanf("%d", (vett + k));
    }
}

int sommaVett(int vett[]){
    int somma = 0;
    for(int k = 0; k < DIM; k++){
        somma = somma + (*(vett + k));
    }
    return somma; 
}

int main(){
    int vett[DIM];
    
    caricaVett(vett);
    int somma = sommaVett(vett);
    printf("somma vettore = %d", somma);

    return 0;
}
