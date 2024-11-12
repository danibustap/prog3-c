#include <stdio.h>
#define BITS 16 /*define a constant, #define has no datatype, it can be wathever*/
void imprimirBinario(unsigned int numero) {
    int i;
    for (i=BITS-1; i>=0; i--) {
        printf("%d", (numero >> i) & 1);
    }
    printf("\n");
}

unsigned int leerBinario(void) {
    char binario[BITS + 1];  // + 1 = terminador nulo (marks the end of the string)
    unsigned int numero = 0;
    int i;

    // Leer entrada ignorando espacios al inicio
    scanf(" %16s", binario);

    // Convertir cadena binaria a unsigned int
    for (i = 0; i < strlen(binario); i++) { // strlen returns the lenght of a string (before the null terminator)
        numero = (numero << 1) | (binario[i] - '0');  // move the last bit at the right one position to the left to make space for the new bit
        //do the OR operation to get the bits from number and add the bits of binary[1]
        // '0' = 48, '1' = 49; '0'-'0'= 48-48 = 0
    }

    return numero;
}

int main() {
    unsigned int a, b;

    printf("Ingrese el primer número binario (hasta 16 bits): ");
    a = leerBinario();

    printf("Ingrese el segundo número binario (hasta 16 bits): ");
    b = leerBinario();

    // Mostrar resultados de las operaciones en formato binario de 16 bits
    printf("\nResultados en binario (16 bits):\n");

    printf("a & b  = ");
    imprimirBinario(a & b); // The result of this operation is the argument

    printf("a | b  = ");
    imprimirBinario(a | b);

    printf("a ^ b  = ");
    imprimirBinario(a ^ b);

    return 0;
}