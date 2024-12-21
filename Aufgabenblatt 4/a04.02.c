#include <stdio.h>

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    char *data;
}Node;

typedef Node *nodep; /*nodep is an alias for Node* (and pointer to Node*) */

void printList(nodep lst){
    nodep current = lst;
    while(current != NULL){
        printf("Adress: %p Content: %s\n", current, current->data);
        current = current->next;
    }
}

nodep insertAt (nodep lst, int pos, char *inhalt){
    nodep new_node = malloc(sizeof(Node)); /* nodep new_node => Node* new_node */
    new_node->data = inhalt;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (lst == NULL){
        return new_node;
    }
    
    if(pos == 0){
        new_node->next = lst;
        new_node->prev = lst;
        return new_node; /*heree*/
    }
}

int main(){
    nodep list = NULL;
    printList(list);
}