#include <stdio.h>
#include <stdlib.h> /*for malloc, free, exit*/
#include <string.h> /*for strncpy*/

typedef struct Node{ /*structs is like a class without methods*/
    char name[26];   /*typedef creates a name for a datatype*/
    struct Node* next;
}Node;

Node* createNode(const char* input){ /*const to avoid that the pointer change the content of the list*/
    Node* new_node = malloc(sizeof(Node)); /*allocate the node in a memory space. malloc allows this variable to stay in the memory, otherwise it will be deleted when the function ends*/
    if(!new_node){ 
        perror("Error assigning memory");
        return 1;
    }
    /*char* strcpy(destiny name, origin name, destiny size)*/
    strncpy(new_node->name, input, 25);
    new_node->name[25] = '\0'; /*add null pointer*/
    new_node->next = NULL; /*Null marks the end of the list (helpful to iterate)*/
    return new_node;
}

int main(int argc, char* argv[]){
    Node* head = NULL; /*points to the first node of the list*/
    Node* tail = NULL; /*tail always points to the last node of the list*/
    char input[25];

    printf("Geben Sie die Namen ein:");
    while(scanf("%25s", &input) != EOF){
        Node* new_node = createNode(input);
        if(head == NULL){
            head = new_node;
            tail = new_node;
        }else{
            tail->next = new_node; /*access to 'next' pointed by tail*/
            tail = new_node;
        }
    }
    tail->next = head; /*make the list circular*/
    /*head > [Alice|Bob] > [Bob|Charlie] > [Charlie|NULL] */
    
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
