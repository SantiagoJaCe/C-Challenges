/* Challenge: Given a roman numeral, convert it to an integer. */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int romanToInt(char *s);

void main(void){

    char *roman=(char*)calloc(15,sizeof(char));
    scanf("%s",roman);
    printf("\n%d",romanToInt(roman));
}

int romanToInt(char *s){

    int *numbers=(int*)malloc(strlen(s)*(sizeof(int)));

    for(int i=0;i<strlen(s);i++){
        if (*(s+i)=='I') *(numbers+i)=1;
        else if (*(s+i)=='V') *(numbers+i)=5;
        else if (*(s+i)=='X') *(numbers+i)=10;
        else if (*(s+i)=='L') *(numbers+i)=50;
        else if (*(s+i)=='C') *(numbers+i)=100;
        else if (*(s+i)=='D') *(numbers+i)=500;
        else if (*(s+i)=='M') *(numbers+i)=1000;
    }

    int i=0;
    int sum=0;

    while(i<strlen(s)){
        if (*(numbers+i)<*(numbers+(i+1))){
            sum+=(*(numbers+(i+1))-*(numbers+i));
            i++;
        }

        else sum+=*(numbers+i);
        i++;

    }

    return sum;
}