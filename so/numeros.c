#include <stdio.h>

int main(){
    long int i;

    printf("100000000\n");
    for(i=100000000; i>0; i--)
        printf("%ld ", i);
    printf("\n");
    return 0;
}
