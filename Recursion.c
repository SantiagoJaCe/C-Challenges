//Challenge 1: Write a program that calculates the sum of numbers from 1 to n using recursion.
//Challenge 2: Write a program which will find the GCD of two numbers using recursion.
//Challenge 3: Write a program which will find the reverse of a string using recursion.
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int sumrecur(int n);
int GCD(int num1, int num2);
void reverse(char* str,int last, int i);

int main(void){

    system("clear");
    int num;
    int num2;
    puts("Options:");
    printf("(1) Sum from 1 to n\n(2) GCD\n(3) Reverse of a string\n");
    unsigned short int answer=0;
    scanf("%d",&answer);
    fflush(stdin);

    if(answer==1){
        puts("Type in a number:");
        scanf("%d",&num);
        printf("The sum of numbers from 1 to %d is %d\n",num,sumrecur(num));
    }

    else if (answer==2){

        puts("Type in two numbers:");
        scanf("%d",&num);
        scanf("%d",&num2);

        printf("The GCD of %d and %d is %d",num,num2,GCD(num,num2));

    }

    else{
        puts("Type in a string (max 30 characters):");
        static char* str=NULL;
        str=(char*)malloc(30*sizeof(char));
        size_t strsize=30;
        scanf("%s",str);
        short unsigned int length=strlen(str);
        short unsigned int last=length-1;

        printf("%s reversed is ",str);
        reverse(str,last,0);
        printf("%s",str);


    }

}

int sumrecur(int n){
    int sum=0;
    if (n==1) sum=1;
    else sum=n+sumrecur(n-1);

    return sum;
}

int GCD(int num1, int num2){

    int A,B,result;
    if (num1>num2){
        A=num1;
        B=num2;
    }
    else{
        A=num2;
        B=num1;
    }

    if (A%B==0) result=B;

    else{
        result=GCD(B,A%B);
    }

    return result;
}

void reverse(char* str, int last, int i){

    if (last>i){
        char temp=*(str+i);
        *(str+i)=*(str+last);
        *(str+last)=temp;

        last--;
        i++;
        reverse(str,last,i);
    }

}