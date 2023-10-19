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
    for(int *p = vett; p < vett + DIM; p++){
        somma = somma + *p;
    }
    return somma; 
}

void scambio(int n1, int n2){
    int temp; 
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void bubbleSort3(int vett[], int n) {
    int k,sup,sca;
    sup = n - 1 ;
    while (sup > 0) {
        sca = 0 ;
        for (int *p = vett; p < vett + n; p++) {
            if (*p > *(p + 1)){
                scambio(p, p + 1);
            sca = p - vett;
            }
        }
        sup = sca ;
    }
}

void visVett(int vett[]){
    for(int p = vett; p < vett + DIM; p++){
        printf("%d", p);
    }
}

int main(){
    int vett[DIM];
    
    caricaVett(vett);
    int somma = sommaVett(vett);
    printf("somma vettore = %d", somma);
    bubbleSort3(vett, DIM);
    visVett(vett);

    return 0;
}
