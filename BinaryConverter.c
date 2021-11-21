/* Challenge: Write two functions, one that converts from binary to decimal
and another one from decimal to binary */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int BtoD(long long int bin);
long long int DtoB(int dec);

int main(void){
    long long int binarynum=0;
    printf("\nEnter a binary number: ");
    scanf("%lld",&binarynum);
    printf("%lli in decimal is %d",binarynum,BtoD(binarynum));

    int decimalnum=0;
    printf("\nEnter a decimal number: ");
    scanf("%d",&decimalnum);
    printf("\n%d in binary is %lld",decimalnum,DtoB(decimalnum));

    return 0;
}

int BtoD(long long int bin){

    int decimal=0;
    int num=0;
    int counter=0;

    while  ((bin/10)!=0){
        if(counter!=0) bin/=10;
        num=(bin%10);
        decimal+=num*(pow(2,counter));
        counter++;
    }

    return decimal;
}

long long int DtoB(int dec){

    int *bin=(int*)calloc(dec,sizeof(char));
    int counter=0;
    int num=0;
    long long int binary=0;
    while ((dec/2)!=0){
        if (counter!=0) 
            dec/=2;
        *(bin+counter)=dec%2;
        counter++;
    }
    counter-=1;
    for (;counter>=0;counter--){
        binary=(binary+(*(bin+counter)))*10;
        if (counter==0) binary/=10;
    }

    free(bin);
    return binary;
}