#include <stdio.h>
int main(){
    int num, i, index1, index2, value;
    do{
        printf("Geben Sie eine Zahl ein:");
        scanf("%d", &num);
    } while(num > 9 || num%2 != 1);

    int magic_square [num][num];

    int middle = (num/2)+1;
    magic_square[middle][middle] = 1;

    for(i=1; i<num*2-1; i++){
        magic_square[middle-1][middle+1] = i+1;
    }




}