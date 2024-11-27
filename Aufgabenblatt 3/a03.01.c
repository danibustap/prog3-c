#include <stdio.h>
int main(void) {
    char *a = NULL; /* a is a pointer to a char*/
    int *b = NULL, v[17];
    double *c = NULL;
   
    printf("\n%ld %ld %ld\n%ld %ld %ld\n\n",
    (long) (a+1), (long)(b+1), (long)(c+1), /* *a+1 moves the pointer one position (1 byte) forward */
    (long) (a+5), (long)(b+7), (long)(c+17));

    printf("%p %p %p\n", (void*)v, /*v points to the array's first element*/
    (void*)&v[0],  /*converts pointer v to a generic pointer "void*"" */
    (void*)&v[10]); /*without & it would be a pointer to the value v[10] and not to the address of v */
    /* cast is necessary because %p expects a generic pointer*/
    
    return 0;
}
