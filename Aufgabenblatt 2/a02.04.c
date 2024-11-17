#include <stdio.h>
int main(){
    int num, i, j, index1, value;
    do{
        printf("Geben Sie eine Zahl ein:\n");
        scanf("%d", &num);
    } while(num > 9 || num%2 != 1);

    int square [num][num]; /* [Zeilen] [Spalten] */
    
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            square[i][j] = 0;
        }
    }

    int row = num/2;
    int column = num/2;
    square[row][column] = 1;

    for(i=2; i<num*num; i++){
        if(square[(row+1)%num][(column-1+num)%num] == 0){
            row = (row+1)%num;
            column = (column-1+num)%num;
       } else{
        row = (row+2)%num;
       }
       square[row][column] = i;
    }
    printf("Magic cube:\n");
    for(i=0; i<num; i++){
        for(j=0; j<num; j++){
            printf("%3d", square[i][j]);
        }
        printf("\n");
    }
}