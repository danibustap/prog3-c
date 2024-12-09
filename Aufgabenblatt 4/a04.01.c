#include <stdio.h>
#include <stdlib.h> /*for malloc, free, exit*/
#include <string.h> /*for strncpy*/

typedef struct Node{ /*structs is like a class without methods*/
    char name[26];   /*typedef creates a name for a datatype*/
    struct Node* next;
}Node;

int main(int argc, char* argv[]){
    Node* head = NULL; /*head must be initialized*/
    Node* tail = NULL; /*tail always point to the last node of the list*/
    char input[25];

    printf("Geben Sie die Namen ein:");
    /*scanf recognizes the separators automatically (' ',\t, \n) */
    while(scanf("%25s", &input) != EOF){
        Node* new_node = malloc(sizeof(Node)); /*allocate the node in a memory space*/
        if(!new_node){ 
            perror("Error assigning memory");
            return 1;
        }
        /*char* strcpy(destiny name, origin name)*/
        strncpy(new_node->name, input, 25);

        if(head == NULL){
            head = new_node;
            tail = new_node; /* */
        }else{
            tail ->next = new_node;
            tail = new_node;
        }
    }

    /*print names*/
    int i = 0;
    Node* current = head;
    while(i <argc && current){
        printf("%s\n", &current->name);
        Node* temp = current;
        current = current->next;
        if(current == NULL){
            current = head;
        }
        i++;
    }
    printf("Verlierer: %s", current->name);
    
    /* Free memory */
    current = head;
    while(current){
        Node* temp = current; /* save current node address */
        current = current->next;
        free(temp); /* releases the memory that was assigned with malloc */
    }
    return 0;
}
