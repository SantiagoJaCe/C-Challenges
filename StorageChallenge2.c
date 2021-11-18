/* Challenge: Write a program that finds the sum of various numbers.
You cannot pass any variable representing the running total to the sum() function */
#include "stdio.h"

int sum (int number){
    static int sum;
    sum+=number;
    return sum;
}

int main(void){
    printf("%d\n",sum(25));
    printf("%d\n",sum(15));
    printf("%d\n",sum(30));
    return 1;
}