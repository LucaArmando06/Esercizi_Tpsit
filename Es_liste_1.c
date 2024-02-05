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

typedef struct El {
    int dato;
    struct El *next;
}Elemento;

int somma(Elemento *head, int n){
    if(head == NULL)
        return -1;

    int somma = 0;
    Elemento *l = head;
    while(l!)
}

int main(){
    int n;
    Elemento* lista = NULL;
    Elemento* l; //head

    do{
        printf("Inserisci un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Elemento*) malloc(sizeof(Elemento));
                l = lista;
            }
            else {
                l->next = (Elemento*) malloc(sizeof(Elemento));
                l = l->next;
            }
            l->dato = n;
            l->next = NULL;
        }
    }  while(n >= 0);

    printf("inserisci il numero M: ");
    scanf("%d", )

    return 0;
}
