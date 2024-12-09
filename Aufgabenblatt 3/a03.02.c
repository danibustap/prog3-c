#include <stdio.h>
int main(int argc, char *argv[]){ /*argc = number of arguments passed from the command line*/
    /*argv[] = contains the arguments as pointers*/
    /*we have to use pointers to save strings (they point to the first element of the string) because the strings will be saved in the static memory, so they can't be modified*/

    char input;
    char encrypt_table[26] = {'w', 'g', 's', 'n', 'q', 'c', 'd', 'v', 'm', 'e', 'y', 'l', 'u', 'z', 'o', 'a', 'b', 'h', 'r', 'j', 'f', 'k', 'x', 'i', 'p', 't'};
    char decrypt_table[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char output;

    if (argc <= 1) {
        printf("Usage: %s encrypt|decrypt\n", argv[0]);
        return 1;
    }

    printf("Geben Sie Ihre Text zum Entschluessseln ein:");
    while((input = getchar()) != EOF){ 
        if(argc > 1 && strcmp(argv[1], "encrypt") == 0){ /*argv[0] contiene el nombre del programa*/
            if(input>='a' && input<='z'){
                output = encrypt_table[input - 'a'];
            }else{
                output = input;
            }
           putchar(output);
        } else if(argc > 1 && strcmp(argv[1], "decrypt") == 0){ /*check argc>1, bc in case there are no arguments, arv[1] wouldn't exist */
            if(input >= 'a' && input<='z'){
                output = decrypt_table[input - 'a']; 
            }else{
                output = input;
            }
            putchar(output);
        } else{
            printf("Invalid command\n");
        }

    }
    
    
    return 0;
}

/*while(scanf("%s", &input) != EOF){
        if(argc>1 && strcmp(argv[1], "encrypt")){ /*argv[0] contiene el nombre del programa
            if(input[i]>='a' && input[i]<='z'){
                output = encrypt_table[input[i] - 'a'];
            }else{
                output = input_c;
            }
           putchar(output);
        } 
        else if(argc>1 && strcmp(argv[1], "decrypt")){ /*check argc>1, bc in case there are no arguments, arv[1] wouldn't exist 

        } else{
            printf("Invalid command");
        }
    }*/