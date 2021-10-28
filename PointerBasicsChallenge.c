/* Challenge: Write a program that creates an integer value with a hard-coded value,
assign that variable's address to a pointer variable, then display as output the address
of the pointer, the value of the pointer, and the value of what the pointer is pointing to.*/

#include "stddef.h"
#include "stdio.h"

void main(void){

    int number=150;
    int * pnumber=&number;


    printf("The address of the number is %p",&number);
    printf("\nThe address of the pointer is %p",&pnumber);
    printf("\nThe value of the pointer is %p",pnumber);
    printf("\nThe value of what the pointer is pointing to is %d",*pnumber);
    
}