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

typedef struct node{
    int valore;
    struct node* next;
}Node;

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lunghezza = 0;
    while(l != NULL){
        lunghezza++;
        l = l->next;
    }
    return lunghezza;
}

int calcolaLunghezzaRicorsiva(Node *lista){
    Node* l = lista;
    if (l == NULL) {
        return 0;
    } else {
        return 1 + calcolaLunghezzaRicorsiva(l->next);
    }
}

void stampaLista(Node *lista){
    Node* l = lista;  //per non perdere la head creo l per scorrere la lista cosi la head resta sempre puntata in lista 
    while(l != NULL){ //controllo che l non è NULL per vedere se la lista non è finita
        printf("%d ", l->valore);
        l = l -> next; //assegno a l il puntatore al prossimo nodo della lista
    }
    printf("\n");
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
    printf("\n");
}

void aggiungiElementoFine(Node **lista, int num){
    Node *l = *lista;
    while(l->next != NULL){
        l = l->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l = l->next;
    l->valore = num;
    l->next = NULL;
} 

void aggiungiElementoInizio(Node **lista, int num){
    Node *head;
    head = (Node*) malloc(sizeof(Node));
    head->next = *lista;
    head->valore = num;
    *lista = head;
}

void eliminaUltimoElemento(Node **lista){
    Node *l = *lista;
    Node *l2 = l;
    while(l->next != NULL){
        l2 = l;
        l = l->next;
    }
    l2->next = NULL;
}

int main(){
    int n, n2;
    Node* lista = NULL; //lista punta al primo nodo quindi inizializzo a null perchè è vuota all'inizio
    Node* l; //head(punta alla testa della lista) puntatore temporaneo per modificare la lista 

    do{
        printf("Inserisci un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista; //punta alla testa della lista perchè è vuota 
            }
            else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next; //punta all'ultimo nodo aggiunto perchè l->next rappresenta il nodo corrente
            }
            l->valore = n;
            l->next = NULL; //per mettere NULL all'ultimo nodo aggiunto 
        }
    }  while(n >= 0);

    printf("Numeri inseriti: ");
    stampaLista(lista);

    printf("Lunghezza: %d", calcolaLunghezza(lista));

    printf("\nInserisci un nuovo numero naturale o -1 per terminare: ");
    scanf("%d", &n2);
    aggiungiElementoInizio(&lista, n2);

    printf("Lunghezza: %d", calcolaLunghezzaRicorsiva(lista));

    printf("\nNumeri inseriti: ");
    stampaListaRicorsiva(lista);

    return 0;
}