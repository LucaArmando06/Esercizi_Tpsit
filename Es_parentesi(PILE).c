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
    Node* head = NULL;

    char* stringa = "{1+[2+3]*5)";

    int n = strlen(stringa);

    bool errore = true;

    for(int k = 0; k < n; k++){
        if(stringa[k] == '{' || stringa[k] == '[' || stringa[k] == '('){
            Node* element = (Node*) malloc(sizeof(Node));
            element->valore = stringa[k];
            push(&head, element);
        }

        if (stringa[k] == '}' || stringa[k] == ']' || stringa[k] == ')') {
            Node *removed = pop(&head);
            if ((stringa[k] == '}' && removed->valore != '{') || (stringa[k] == ']' && removed->valore != '[') ||
                (stringa[k] == ')' && removed->valore != '(')) { // controllo per vedere la corrispondenza tra le parentesi
                errore = false;
            }
        }
    }

    if (errore && is_empty(head)) { //controllo la corrispondenza tra le parentesi se no {[]) mi da che è corretto se controllo solamente che la pila è vuota 
        printf("Corretto!\n");
    } else {
        printf("Errore!\n");
    }

    return 0;
}
