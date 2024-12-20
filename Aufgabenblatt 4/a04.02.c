#include <stdio.h>

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    char *data;
}Node;

typedef Node *nodep; /*pointer to the struct*/

void printList(nodep lst){
    nodep current = lst;
    while(current != NULL){
        printf("Adress: %p Content: %s\n", current, current->data);
        current =  current->next;
    }
}

nodep insertAt (nodep lst, int pos, char *inhalt){
    Node *head = NULL;
    Node *tail = NULL;
    head = lst;
    if (!head){

    }
}

int main(){
    nodep list = NULL;
    printList(list);
}