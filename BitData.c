/* Challenge: Setting and Reading beats:
Create a program that takes any number as input,
the program should check whether the nTH bit of the given number is set to 1 or not,
the program should set the nTH bit of the given number as 1*/

#include "stdio.h"

unsigned int bitman(unsigned int num, unsigned int bit);

int main(void){
    printf("Enter any positive number: ");
    int unsigned number;
    scanf("%d",&number);
    printf("Enter the nTh bit to check and set (0-31): ");
    int unsigned bitcheck;
    scanf("%d",&bitcheck);

    unsigned int result=bitman(number,bitcheck);
    printf("The number before setting %d bit: %d\n",bitcheck,number);
    printf("The number after setting %d bit: %d\n",bitcheck,result);

    return 0;

}

unsigned int bitman(unsigned int num, unsigned int bit){

    if ((num>>bit)&1){
        printf("The %d° bit is set to 1\n",bit);
        return num;
    }

    else {
        printf("The %d° bit is set to 0\n",bit);
        unsigned int mask=1;
        mask=mask<<bit;
        num=num|mask;
        return num;
    }

    printf("\n#ERROR WITH IFS#\n");
    return 69;

}