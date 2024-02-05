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
#define DIM_RIGA 300 
#define TOTALE 2200
#define TOTALE_SINGOLO 100

typedef struct {
    char *data;
    char *cognome;
    int quota_pagata;
} Alunno;

int contaRighe(Alunno *classe, char *filename){
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

void caricaClasse(Alunno *classe, int nRighe, char filename[]){
    FILE *fp;
    char riga[DIM_RIGA];
    char *campo;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
        exit(1);
    } else {
        for(Alunno *p = classe; p < classe + nRighe; p++){  
            fgets(riga, DIM_RIGA, fp); 
            campo = strtok(riga, ";"); 
            p->data = strdup(campo); 

            campo = strtok(NULL, ";");
            p->cognome = strdup(campo);

            campo = strtok(NULL, ";");
            p->quota_pagata = atoi(campo); 
        }
    }
    fclose(fp);
}

void stampaClasse(Alunno *classe, int nRighe) {
   for (Alunno *p = classe; p < classe + nRighe; p++){
        if(p->quota_pagata < TOTALE_SINGOLO){
            printf("%s %s %d DA CONTROLLARE\n", p->data, p->cognome, p->quota_pagata);
        } else {
            printf("%s %s %d\n", p->data, p->cognome, p->quota_pagata);
        }
   }
}

void calcolaQuoteVersate(Alunno *classe, int nRighe){
    int quota_totale = 0; 
    int mancanti;
    
    for(Alunno *p = classe; p < classe + nRighe; p++){
        quota_totale += p->quota_pagata;
    }

    printf("La quota totale pagata e' di: %d\n", quota_totale);

    if(quota_totale < TOTALE){
        mancanti = TOTALE - quota_totale;
        printf("Mancano %d euro: \n", mancanti);
        for(Alunno *p = classe; p < classe + nRighe; p++){
            if(p->quota_pagata < TOTALE_SINGOLO){
                printf("L' alunno %s ha versato solamente %d euro\n", p->cognome, p->quota_pagata);
            }
        }
    }
}

void cercaAlunno(Alunno *classe, int nRighe, char *cognome_cercato){
    int mancanti;
    for (Alunno *p = classe; p < classe + nRighe; p++){
        if(p->cognome == cognome_cercato){
            printf("%s %s %d\n", p->data, p->cognome, p->quota_pagata);
            if(p->quota_pagata < TOTALE_SINGOLO)
                mancanti = TOTALE_SINGOLO - p->quota_pagata;
                printf("Mancano %d euro", mancanti);
        }
   }
}

int main(){
    Alunno *classe;
    char filename[] = "4AROB_GITA.csv";
    char *cognome_cercato;

    int nRighe = contaRighe(classe, filename);

    classe = (Alunno*) malloc(nRighe * sizeof(Alunno));

    caricaClasse(classe, nRighe, filename);

    calcolaQuoteVersate(classe, nRighe);

    printf("Inserisci il tuo cognome: ");
    scanf("%s", &cognome_cercato);
    cercaAlunno(classe, nRighe, cognome_cercato);

    stampaClasse(classe, nRighe);

    free(classe);

    return 0;
}