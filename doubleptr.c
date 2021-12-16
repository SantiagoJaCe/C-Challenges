/* Challenge: Write a program that includes a function that modifies a pointers value
NOT the value that the pointer is pointing to, the actual value of the pointer (The address).
Simulate pass by reference essentially */

#include "stdlib.h"
#include "stdio.h"

void memAlloc(int **ptr);

int main(){

    int *pint=NULL;
    int a=5;
    pint=&a;
    printf("Before going into the function pointer points to %d with adress of %p",*pint,pint);
    memAlloc(&pint);
    printf("\nAfter going into the function pointer points to %d with adress of %p",*pint,pint);
    free(pint);
}

void memAlloc(int **ptr){
    *ptr=(int*)malloc(sizeof(int));
    int b=52;
    **ptr=b;
}