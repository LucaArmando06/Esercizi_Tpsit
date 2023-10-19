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

void scambio(int *n1, int *n2){
    int temp; 
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubbleSort3(int vett[], int n) {
    int k, sup, sca;
    sup = n - 1 ;
    while (sup > 0) {
        sca = 0 ;
        for (k = 0; k < sup ; k++) {
            if ((*(vett + k)) > (*(vett + k + 1))){
                scambio(&(*(vett + k)),&(*(vett + k + 1)));
            sca = k ;
            }
        }
        sup = sca ;
    }
}

void visVett(int vett[]){
    for(int k = 0; k < DIM; k++){
        printf("%d ", (*(vett + k)));
    }
}

int main(){
    int vett[DIM];
    
    caricaVett(vett);
    int somma = sommaVett(vett);
    printf("somma vettore = %d\n", somma);
    bubbleSort3(vett, DIM);
    visVett(vett);

    return 0;
}
