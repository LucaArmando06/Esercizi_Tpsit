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
    for(int *p = vett; p < vett + DIM; p++){
        printf("inserisci un numero [%d]: ", p);
        scanf("%d", p);
    }
}

int sommaVett(int vett[]){
    int somma = 0;
    for(int *p = vett; p < vett+ DIM; p++){
        somma = somma + *p;
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
