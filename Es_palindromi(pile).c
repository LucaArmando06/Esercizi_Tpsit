/*
auhor: Luca Armando
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
    char valore;
    struct node* next;
}Node;

int is_empty(Node *head){
    if(head == NULL)
        return 1;
    else 
        return 0;
}

void push(Node **head, Node *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    } else {
        element->next = *head;
        *head = element;
    }
}

Node* pop(Node **head){
    Node *ret = *head;
    if(is_empty(*head))
        return NULL;
    else{
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Node *head){
    Node* l = head;
    while(l != NULL){
        printf("%c ", l->valore);
        l = l->next;
    }
    printf("\n");
}

int main(){
    char* parola;
    Node* head = NULL;

    printf("inserisci una parola: "); 
    scanf("%s", parola);

    int n = strlen(parola);

    for (int k = 0; k < n; k++) {
        Node* element = (Node*) malloc(sizeof(Node));
        element->valore = parola[k];
        push(&head, element);
    }

    bool palindroma = true;

    for (int k = 0; k < n; k++) { 
        Node *removed = pop(&head);
        if(parola[k] == removed->valore){
            palindroma = true;
        } else {
            palindroma = false; 
        }
    }

    if(palindroma)
        printf("la parola %s è palindroma", parola);
    else
        printf("la parola %s NON è palindroma", parola);
    
    return 0;
}