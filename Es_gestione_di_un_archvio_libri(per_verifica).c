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
#define LUNG 100
#define DIM_RIGA 300

typedef struct {
    char *titolo;
    char *autore; //char autore[LUNG];
    int anno_pubblicazione;
} Libro;

int contaRighe(Libro archvio[], char filename[]){
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

void caricaArchivio(Libro archivio[], int nRighe, char filename[]){
    FILE *fp;
    char riga[DIM_RIGA];
    char *campo;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
        exit(1); //esce dal programma
    } else {
        for(Libro *p = archivio; p < archivio + nRighe; p++){  
            fgets(riga, DIM_RIGA, fp); // fgets() per leggere tutta la linea
            campo = strtok(riga, ","); //strtok() per spezzare i campi
            p->titolo = strdup(campo); //strdup() ritorna la copia

            campo = strtok(NULL, ",");
            p->autore = strdup(campo);

            campo = strtok(NULL, ",");
            p->anno_pubblicazione = atoi(campo); //atoi() converte ad intero
        }
    }
    fclose(fp);
}

void stampaArchivio(Libro archivio[], int nRighe) {
   for (Libro *p = archivio; p < archivio + nRighe; p++){
        printf("%s %s %d\n", p->titolo, p->autore, p->anno_pubblicazione);
   }
}

void scambio(Libro *l1, Libro *l2){
    Libro temp; 
    temp = *l1;
    *l1 = *l2;
    *l2 = temp;
}

void ordinaArchivio(Libro archivio[], int nRighe) {
    int k, sup, sca;
    sup = nRighe - 1 ;
    while (sup > 0) {
        sca = 0 ;
        for (k = 0; k < sup ; k++) {
            if ((archivio + k)->anno_pubblicazione < (archivio + k + 1)->anno_pubblicazione){
                scambio((archivio + k), (archivio + k + 1));
            sca = k ;
            }
        }
        sup = sca ;
    }
}

void stampaAnno(Libro archivio[], int nRighe, int anno){
    for (Libro *p = archivio; p < archivio + nRighe; p++){
        if(p->anno_pubblicazione == anno)
            printf("%s %s %d\n", p->titolo, p->autore, p->anno_pubblicazione);
   }
}

int main(){
    Libro *archivio;
    char filename[] = "archivio_libri.csv";
    int anno;

    int nRighe = contaRighe(archivio, filename);

    archivio = (Libro*) malloc(nRighe * sizeof(Libro));

    caricaArchivio(archivio, nRighe, filename);

    ordinaArchivio(archivio, nRighe);

    printf("Archvio completo in ordine di pubblicazione (dal piu' recente al meno recente): \n");
    stampaArchivio(archivio, nRighe);

    printf("\nInserisici l'anno di pubblicazione:");
    scanf("%d", &anno);
    stampaAnno(archivio, nRighe, anno);

    free(archivio);

    return 0;
}