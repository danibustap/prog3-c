#include <stdio.h>
int main(int argc, char *argv[]){ /*argc = number of arguments passed from the command line*/
    /*argv[] = contains the arguments as pointers*/
    /*to save strings we have to use pointers (they point to the first element of the string? because the strings will be saved in the static memory, so they can't be modified*/

    char input[100];
    char encrypt_table[26] = {'w', 'g', 's', 'n', 'q', 'c', 'd', 'v', 'm', 'e', 'y', 'l', 'u', 'z', 'o', 'a', 'b', 'h', 'r', 'j', 'f', 'k', 'x', 'i', 'p', 't'};
    char decrypt_table[26] = {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'};
    char output;
    int i;

    printf("Geben Sie Ihre Text zum Entschluessseln ein:");
    while(scanf("%s", &input) != EOF){
        scanf("%s", &input);
    }
    
    if(argc>1 && strcmp(argv[1], "encrypt")){ /*argv[0] contiene el nombre del programa*/
        for(i=0; i<100; i++){
            if(input[i]>'a' && input[i]<'z'){
                /* 'a' */
            }
        }
    } 
    else if(argc>1 && strcmp(argv[1], "decrypt")){ /*check argc>1 in case there are no arguments(arv[1] wouldn't exist)*/

    } else{
        printf("Invalid command");
    }
    return 0;
}