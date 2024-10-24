#include <stdio.h>
int main (){
    int zahl, j;
    int c, l, x, v, i;
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &zahl);
    
    c = zahl / 100;
    zahl = zahl % 100;

    l = zahl / 50;
    zahl = zahl % 50;

    x = zahl / 10;
    zahl = zahl % 10;

    v = zahl / 5;
    zahl = zahl % 5;

    i = zahl / 1;
    
    printf("umgewandelte Zahl: ");
    
    for (j=0; j<c; j++){
        printf("C");
    }
    
    for (j=0; j<l; j++){
        printf("L");
    }
    
    for (j=0; j<x; j++){
        printf("X");
    }
    
    for (j=0; j<v; j++){
        printf("V");
    }
    
    for (j=0; j<i; j++){
        printf("I");
    }
    
    return 0;

    /*
    % = format specifier
    %d = decimal number
    %f = float
    %c = character
    %s = string ("%s", str)
    */
}