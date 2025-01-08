#include <stdio.h>
#include <stdlib.h> /*for malloc, free, exit*/
#include <string.h> /*for strncpy*/

typedef struct Node{ /*structs is like a class without methods*/
    char name[26];   /*typedef creates a name for a datatype*/
    struct Node* next;
}Node;

Node* createNode(const char* input){ /*const to avoid that the pointer change the content of the list*/
    Node* new_node = malloc(sizeof(Node)); /*allocate the node in a memory space. malloc allows this variable to stay in the memory, otherwise it will be deleted when the function ends*/
   
    /*char* strcpy(destiny name, origin name, destiny size)*/
    strncpy(new_node->name, input, 25);
    new_node->name[25] = '\0'; /*add null pointer at the end*/
    new_node->next = NULL; /*Null marks the end of the list (useful to iterate)*/
    return new_node;
}

int main(int argc, char* argv[]){
    Node* head = NULL; /*points to the first node of the list*/
    Node* tail = NULL; /*tail always points to the last node of the list*/
    Node* current = NULL;
    Node* prev = NULL;
    char input[25];
    int i; 

    printf("Geben Sie die Namen ein:\n");
    while(scanf("%25s", &input) != EOF){
        Node* new_node = createNode(input);
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node; /*access to the 'next' address pointed by tail*/
            tail = new_node;
        }
    }
    tail->next = head; /*make the list circular*/
    /*head > [Alice|Bob] > [Bob|Charlie] > [Charlie|NULL] 
    tail > [Charlie|NULL]*/
    
    /*print names*/
    printf("Number of args: %d\n", argc);
    current = head;
    while(current->next != current){ /*mientras haya más de un nodo en la lista*/
        for(i=0; i<argc-1; i++){ 
            prev = current;
            current = current->next;
        }
        printf(" Ausgezaehlt: %s\n", &current->name); /*se elimina y se vuelve a contar hasta que quede solo un nodo*/
        prev->next = current->next;
        free(current);
        current = prev->next;
    }
    printf("Verlierer: %s", current->name);
    
    /* Free memory */
    current = head;
    while(current){
        prev = current;
        current = current->next;
        free(prev); /* releases the memory that was assigned with malloc */
    }
    return 0;
}
