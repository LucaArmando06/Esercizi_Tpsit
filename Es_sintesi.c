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

typedef struct {
    char* cognome;
    char* nome;
    int anno;
    int mese;
    int giorno;
} Persona;

int contaRighe(Persona persone[], char filename[]){
    FILE *fp;
    int cont = 0;
    char riga[DIM_RIGA];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
    } else {
        while(fgets(riga, DIM_RIGA, fp)){  
            cont++;
        }
    }
    fclose(fp);
    return cont;
}

void caricaPersone(Persona persone[], char filename[]){
    FILE *fp;
    int cont = 0;
    char* campo; 
    char riga[DIM_RIGA];
    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("errore nell'apertura del file");
    } else {
        while(fgets(riga, DIM_RIGA, fp)){  
            campo = strtok(riga, " ");  
            (persone + cont)->cognome = strdup(campo); 

            campo = strtok(NULL, " ");
            (persone + cont)->nome = strdup(campo);  

            campo = strtok(NULL, " ");
            (persone + cont)->anno = atoi(campo);

            campo = strtok(NULL, " ");
            (persone + cont)->mese = atoi(campo);

            campo = strtok(NULL, " ");
            (persone + cont)->giorno = atoi(campo);

            cont++;
        }
    }
    fclose(fp);
}

void scambio(Persona *p1, Persona *p2){
    Persona temp; 
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void ordinaPersone(Persona persone[], int nRighe) {
    int k, sup, sca;
    sup = nRighe - 1 ;
    while (sup > 0) {
        sca = 0 ;
        for (k = 0; k < sup ; k++) {
            if ((persone + k)->anno > (persone + k + 1)->anno){
                scambio(&(*(persone + k)), &(*(persone + k + 1)));
            sca = k ;
            }
        }
        sup = sca ;
    }
}

void visPersone(Persona persone[], int nRighe){
    for(int k = 0; k < nRighe; k++){
        printf("%s %s %d/%d/%d\n", (persone + k)->cognome, (persone + k)->nome, (persone + k)->anno, (persone + k)->mese, (persone + k)->giorno);
    }
}

int main(){
    char filename[] = "nomi.csv";
    Persona *persone;

    int nRighe = contaRighe(persone, filename);
    
    persone = (Persona*) malloc (nRighe * sizeof(Persona));
    
    caricaPersone(persone, filename);

    ordinaPersone(persone, nRighe);

    visPersone(persone, nRighe);

    free(persone);

    return 0;
}