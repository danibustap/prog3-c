#include <stdio.h>
#define MAX_ANZAHL 20
void main(){
    int unsortiert[MAX_ANZAHL], sortiert[MAX_ANZAHL], number, count=0;
    printf("Geben Sie bis 20 Zahlen ein: ");
    
    while (scanf("%d", &number) == 1){
        if(count < MAX_ANZAHL){
            unsortiert[count] = number;
            count++;
        } else{
            printf("Array ist voll");
        }
        
    }
    
}