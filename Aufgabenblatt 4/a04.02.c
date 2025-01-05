#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next; 
    struct Node *prev;
    char *data; /*8 bytes*/
}Node;
 
typedef Node *nodep; /*nodep is an alias for Node* (and pointer to Node*) */

void printList(nodep lst){
    nodep current = lst;
    while(current != NULL){
        printf("Adress: %p \nContent: %s\n", current, current->data);
        current = current->next;
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

nodep insertAt (nodep lst, int pos, char *inhalt){
    nodep new_node = malloc(sizeof(Node)); /* nodep new_node == to Node* new_node. malloc always must be freed with "free"*/
    nodep current = lst; /*first known node in the list*/
    nodep prev_node = NULL;
    nodep next_node = NULL;
    int i;

    new_node->data = inhalt; /*indirect bytes: memory that malloc points to (data = 8 bytes)*/
    new_node->next = NULL;
    new_node->prev = NULL;

    if (lst == NULL){
        if(pos == 0){
            return new_node;
        } else{
            printf("The list is empty. You can only insert in position 0");
            free(new_node);
            return lst;
        }
    }
    
    if(pos == 0){
        lst->prev = new_node; /*lst (in second position) now points with prev to the previous node (new_node)*/
        new_node->next = lst; /*new_node points with next to the node that was in the first position before (lst)*/
        return new_node; 
    } 
    else if (pos == -1){
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
        return lst; /*always return first node*/
    }
    else if (pos > 0){
        for(i=0; i<pos; i++){
            if(current == NULL){
                printf("Invalid position. The list is too short.\n");
                free(new_node);
                return lst;
            }
            prev_node = current;
            current = current->next;
        }
        prev_node->next = new_node;
        new_node->prev = prev_node;

        if(current != NULL){ /* if there is a node after the one that we just inserted*/
            new_node->next = current;
            current->prev = new_node;   
        }
        return lst;
    }
    printf("(Insert) Invalid position. Valid positions: 0, > 0 and -1.\n");
    return lst;
}

nodep deleteAt(nodep lst, int pos){
    int i;
    nodep current = lst;
    nodep prev_node = NULL;
    nodep next_node = NULL;
    nodep temp;

    if(lst == NULL){
        printf("The list you are trying to delete from is empty.\n");
        return lst;
    }

    if (pos == 0){
        temp = lst->next; /*save the second node*/
        free(lst);
        lst = temp;
        if (lst != NULL){
            lst->prev = NULL;
        }
        return lst;
    } 
    else if(pos == -1){
        while (current->next != NULL){
            current = current->next;
        }
        prev_node = current->prev;
        if (prev_node != NULL){
            prev_node->next = NULL;
        }
        else{
            lst = NULL; /*if there was only one node, the list is now empty*/
        }
        free(current);
        return lst;

    }
    else if (pos > 0){
        for(i=0; i<pos; i++){
            if(current == NULL){
                printf("The requested position exceed the number of available nodes");
                return lst;  
            }
            current = current->next;     
        }
        if(current == NULL){
            printf("The requested position exceed the number of available nodes");
            return lst;  
        }
        prev_node = current->prev;
        next_node = current->next;
        
        if(next_node != NULL){
            prev_node->next = next_node;
            next_node->prev = prev_node;
        }else{
            prev_node->next = NULL;
        }
        
        free(current);
        return lst; 
    }
    printf("(Delete) Invalid position. Valid positions: 0, > 0 and -1.\n");
    return lst;
}
  
int main(){
    nodep list = NULL;
    nodep lista = NULL;
    lista = insertAt(lista, 0, "");
    list = insertAt(list, 0, "soy el nodo 0");
    list = insertAt(list, 1, "soy el nodo 1");
    list = insertAt(list, 2, "soy el nodo 2");
    list = insertAt(list, -1, "soy el nodo 3");
    
    printList(list);
    list = deleteAt(lista, 0);
    printList(list);
   
    return 0;
}