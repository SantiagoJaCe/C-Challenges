/* Challenge: Write a program that creates a variadic function that will add up the integer arguments passed */
#include "stdio.h"
#include "stdarg.h"

int addNums(int count,...);

int main(void){

    addNums(2,10,20);
    addNums(3,10,20,30);
    addNums(4,10,20,30,40);
    addNums(12,5,2,3,4,7,8,9,6,1,2,4,6);

}

int addNums(int count,...){

    va_list arguments;
    va_start(arguments,count);

    int sum=0;
    for(int i=0;i<count;i++,sum+=va_arg(arguments,int));

    va_end(arguments);

    printf("The sum is: %d\n",sum);

}