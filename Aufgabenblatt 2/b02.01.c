#include <stdio.h>
int power(int base, int exponent){
    int i, answer=1;
    for(i=0; i<exponent; i++){
        answer *= base; /*answer = answer*base*/
    }
    return answer;
}
int main(){
    double x;
    double tolerance = 1e-17; /*e = multiplied by 10^x */
    double w, previous_w, difference;

    printf("Geben Sie eine Zahl ein: ");
    scanf("%lf", &x);
    w = (1+x)/2;
    do{
        previous_w = w;
        w = (w+(x/w))/2;
        difference = (w>previous_w) ? (w-previous_w):(previous_w-w); /*(if this is true) ? (execute this) : (if not, execute this)*/
    } while(difference >= tolerance);

    printf ("Der Quadratwurzel von %.4f ist: %10.4f", x, w);
    /*10 = output field lenght (to align numbers to the right)
    .4 = how many digits after the comma
    f = float*/
    return 0;
}