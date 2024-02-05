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
    int s;
    struct El *next;
}ElementoLista;

ListaDiInteri FirstEven(ListaDiInteri lis) {
    while (lis != NULL) {
        if (lis->s % 2 == 0)
            return lis;
            /* il primo pari è in lis */
        else
            lis = lis -> next;
    }
    return NULL;
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
            l->s = n;
            l->next = NULL;
        }
    }  while(n >= 0);

    printf("%d", FirstEven(lista));

    ElementoLista
    printf("valore: %d", posPrimoPari->s);
    return 0;
}