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
}Elemento;

int FirstEven(Elemento* lista) {
    Elemento* l = lista;
    int cont = 0;

    while (l != NULL) {
        if (l->s % 2 == 0)
            return cont;   /* il primo pari è in lista-+ */
       else{
            l = l -> next;
            cont++;
       }
    }
}

ElementoLista* FirstEven(Elemento *lis){
    while(lis != NULL){

    }
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