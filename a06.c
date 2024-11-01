#include <stdio.h>
int main(){
    char c;

    while (scanf("%c", &c) == 1){
        if (c>='a' && c<='z'){
            c = ((c - 'a' + 13) % 26) + 'a'; /*c-'a' to change the range to 0 to 25 ('a' = 97, 'A' = 65 in ASCII)*/
        } 
        else if (c >= 'A' && c <= 'Z'){
            c = ((c -'A' + 13) % 26) + 'A'; /*%26 to reset the alphabet when the new value of a letter is bigger than 25 (n to z)*/
        }
        putchar(c);
    }
    return 0;
}