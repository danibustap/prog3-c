#include <stdio.h>
#define BITS 16 /*define a constant, #define has no datatype, it can be wathever*/
void schreibbit(unsigned int numero) { /*Transform the decimal number into bits*/
    int i;
    for (i=BITS-1; i>=0; i--) { 
        printf("%d", (numero >> i) & 1);/*Print the bits one by one from the most significant to the less significant*/
    }                                   /*with &1 it's possible to print the numbers in bits instead of decimal*/
    printf("\n");
}

unsigned int liesbit(void) {
    char binary[BITS + 1];  /* + 1 = terminador nulo (marks the end of the string)*/
    unsigned int numero = 0;
    int i;

    /*Leer entrada ignorando espacios al inicio*/
    scanf(" %16s", binary);

    for (i = 0; i < strlen(binary); i++) { /*strlen returns the lenght of a string (before the null terminator)*/
        numero = (numero << 1) | (binary[i] - '0');  /*move the last bit at the right, one position to the left to make space for the new bit*/
        /*do the OR operation to get the bits from number and add the bits of binary[1]
        '0' = 48, '1' = 49; '0'-'0'= 48-48 = 0 */
    }

    return numero;
}

int main() {
    unsigned int a, b;

    printf("Ingrese el primer número binario (hasta 16 bits): ");
    a = liesbit();

    printf("Ingrese el segundo número binario (hasta 16 bits): ");
    b = liesbit();

    printf("\nResultados en binario (16 bits):\n");

    printf("a & b  = ");
    schreibbit(a & b); 

    printf("a | b  = ");
    schreibbit(a | b);

    printf("a ^ b  = ");
    schreibbit(a ^ b);

    return 0;
}