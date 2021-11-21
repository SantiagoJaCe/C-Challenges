/* Write a program that uses all the bitwise operators shown in class */

#include "stdio.h"
#include "stdlib.h"

long long DtoB(int dec);


int main(){
    printf("Enter an integer: ");
    int num1=0;
    scanf("%d",&num1);
    printf("Enter another integer: ");
    int num2=0;
    scanf("%d",&num2);


    long long bin1=DtoB(num1);
    long long bin2=DtoB(num2);



    printf("\nThe result of applying the ~ operator on number %d (%lld) is: %lld\n",num1,bin1,DtoB((~num1)));

    printf("\nThe result of applying the ~ operator on number %d (%lld) is: %lld\n",num2,bin2,DtoB((~num2)));

    printf("\nThe result of applying the & operator on number %d (%lld) and number %d (%lld) is: %lld\n",num1,bin1,num2,bin2,DtoB((num1&num2)));

    printf("\nThe result of applying the | operator on number %d (%lld) and number %d (%lld) is: %lld\n",num1,bin1,num2,bin2,DtoB((num1|num2)));

    printf("\nThe result of applying the ^ operator on number %d (%lld) and number %d (%lld) is: %lld\n",num1,bin1,num2,bin2,DtoB((num1^num2)));

    printf("\nThe result of applying the <<1 operator on number %d (%lld) is: %lld\n",num1,bin1,DtoB((num1<<1)));

    printf("\nThe result of applying the <<1 operator on number %d (%lld) is: %lld\n",num2,bin2,DtoB((num2<<1)));

}

long long DtoB(int dec)
{
    long long binaryNumber = 0;
    int remainder, i = 1;
    while (dec!=0)
    {
        remainder = dec%2;
        dec /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}