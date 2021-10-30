//Challenge: Write a program that tests your understanding of pointer arithmetic and the const modifier.
/* Write a function that calculates the length of a string, it should
take as a parameter a const char pointer, the function can only determine the length of the
string using pointer arithmetic and a while loop.
It should return an int that is the length of the string passed into the function.*/

#include "stdio.h"

int getlength(const char *ptr);

int main(){

    char str1[50];
    printf("Type in a string: \n");
    scanf("%s",str1);
    printf("The length of \"%s\" is %d",str1,getlength(str1));

}

int getlength(const char *ptr){
    const char *last=ptr;
    int sum=0;

    while(*last){
        last+=1;
    }



    sum=last-ptr;
    return sum;

}

