#include <stdio.h>
#include <stdlib.h>

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
    nodep new_node = malloc(sizeof(Node)); /* nodep new_node it's equivalent to Node* new_node. malloc always must be freed with "free"*/
    new_node->data = inhalt;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (lst == NULL){
        return new_node;
    }
    
    if(pos == 0){
        if(lst != NULL){
            lst->prev = new_node;
        }
        new_node->next = lst;
        return new_node; /*new_node is now the start node*/
    } else if (pos == -1){
        nodep current = lst; /*first known node in the list*/
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
        return lst; /*always return first node*/
    }
}

void freeList(nodep lst){
    nodep current = lst;
    while(current != NULL){
        nodep next = current->next;
        free(current);
        current = next;
    }
}

nodep deleteAt (nodep lst, int pos){

}
  
int main(){
    nodep list = NULL;
    list = insertAt(list, 0, "hola soy un nodo");
    list = insertAt(list, -1, "soy el nodo 2");
    printList(list);

    freeList(list);
    return 0;
}