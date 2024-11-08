#include <stdio.h>
#define MAX_ANZAHL 20
int main(){
    int arr[MAX_ANZAHL], num, count=0;
    int i,j, min_idx, temp_value;
    printf("Geben Sie bis 20 Zahlen ein:\n");

    while (count < MAX_ANZAHL && scanf("%d", &num) == 1){
        arr[count] = num;
        count++; 
    }
    
    for(i=0; i<count-1; i++){
        min_idx = i;
        for(j=i+1; j<count; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        temp_value = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp_value;
    }

    printf("sortierte Array:\n");

    for(i=0; i<count; i++){
        printf("%6d\n", arr[i]);
    }

    return 0;  
}
