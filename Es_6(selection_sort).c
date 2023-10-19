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

void scambio(int n1, int n2){
    int temp; 
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void selectionSort(int vett[], int n) {
    int k, kmin, j;
    for(int *p = vett; p < vett + n - 1; p++) {
        kmin = *p;
        for(int *j = p + 1; j < vett + n; j++){
            if(*j > kmin)
                kmin = *j;
        }
    if(kmin != *p)
        scambio(*p, kmin);
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
    selectionSort(vett, DIM);
    visVett(vett);

    return 0;
}