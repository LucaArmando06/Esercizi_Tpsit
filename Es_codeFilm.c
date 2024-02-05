#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct film{
    char* titolo;
    int anno;
    char* genere;
    struct film* next;
}Film;

bool is_empty(Film* head){
    return head == NULL;
}

void enqueue(Film** head, Film** tail, Film* elem){
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Film* dequeue(Film** head, Film** tail){
    Film* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}

int calcolaLunghezza(Film* head){
    Film* h = head;
    int lung = 0;
    while (h != NULL)
    {
        lung++;
        h = h->next;
    }
    return lung; 
}

void stampaCoda(Film* head){
    Film* l = head;
    printf("\nCoda: ");
    while (l != NULL){
        printf("\n%s ", l->titolo);
        printf("\n%d ", l->anno);
        printf("\n%s\n ", l->genere);
        l = l ->next;
    }
}

void freeCodaRicorsiva(Film* head) {
    if(head->next != NULL)
        freeCodaRicorsiva(head -> next);
    
    free(head);
}

int main() {
    Film* head = (Film*)malloc(sizeof(Film));
    Film* tail = (Film*)malloc(sizeof(Film));

    head = NULL;
    tail = NULL;

    Film* elemento = (Film*)malloc(sizeof(Film));

    /*
    printf("Inserisci il titolo: ");
    scanf("%s", elemento->titolo);
    printf("Inserisci l'anno: ");
    scanf("%d", &elemento->anno);
    printf("Inserisci il genere: ");
    scanf("%s", elemento->genere);
    */

    elemento->titolo = "Leon";
    elemento->anno = 1994;
    elemento->genere = "Azione";    
    elemento->next = NULL;

    enqueue(&head, &tail, elemento); //carico il primo elemento nella coda

    stampaCoda(head);
    printf("\nDimensione della coda: %d", calcolaLunghezza(head));

    Film* temp = dequeue(&head, &tail); //tolgo il primo elemento della coda
    printf("\nfilm rimosso:");
    printf("\n%s ", temp->titolo);
    printf("\n%d ", temp->anno);
    printf("\n%s\n ", temp->genere);

    stampaCoda(head);
    printf("\nDimensione della coda: %d", calcolaLunghezza(head));

    freeCodaRicorsiva(head);

    return 0;
}