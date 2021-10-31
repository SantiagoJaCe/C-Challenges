/* Challenge: Write a program that tests your understanding of pass by reference.
Write a function that squares a number by itself, the function should define as a parameter an int pointer,
it shouldn't return the result, it must return void and modify the value in the function. */

#include "stdio.h"

void square(int *const value);

void main(void){


    int input=0;

    printf("Insert the value you want to calculate the square of: \n");
    scanf("%d",&input);

    printf("The square of %d is ",input);
    square(&input);
    printf("%d\n",input);

}

void square(int *const value){

    *value=(*value)*(*value);

}