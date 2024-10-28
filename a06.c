#include <stdio.h>
int main(){
    char c;

    while (scanf("%c", &c) == 1){
        if (c>='a' && c<='z'){
            c = ((c - 'a' + 13) % 26) + 'a'; /*c-'a' because: 26 letters = 0 to 25 positions*/
        } 
        else if (c >= 'A' && c <= 'Z'){
            c = ((c -'A' + 13) % 26) + 'A'; /*%26 to reset the alphabet when the next letter value is bigger than 25*/
        }
        putchar(c);
    }
    return 0;
}