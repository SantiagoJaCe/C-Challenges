#include "stdio.h"

int main(){
    char s[100];
    int n;

    printf("Enter a value, followed by your name (Num Name): ");

    scanf("%d %s", &n,s);

    printf("\nYou entered: %d::::%s\n",n,s);

    return 0;

}