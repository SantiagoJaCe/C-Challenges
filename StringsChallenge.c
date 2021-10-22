/* Challenge: Write a program that tests your understanding of char arrays:

Write a function to count the number of characters in a string, but WITHOUT the strlen() function.
This function should take a character array as a parameter and should return an int, the length.

Write another function to concatenate two character strings WITHOUT
the strcat() function, it should take 3 parameters, the resulting array, 
the string1 and the string2. It can return void.

Write another function that determines if two strings are equal,
WITHOUT the strcmp() function, it should take two char arrays as parameters and return
a boolean value. */

#include "stdio.h"

int length (char stringlen[]);
void concatenate (char result[],char string1[],char string2[]);
int comp (char string1[],char string2[]);



int stringlength (char stringlen[]){
    int count=0;
    int i=0;
    while(stringlen[i]!='\0'){
        count+=1;
        i++;
    }
    count+=1;
    return count;
}

void concatenate (char result[],char string1[],char string2[]){
    int length1=0;
    int length2=0;
    length1=(stringlength(string1))-1;
    length2=stringlength(string2);
    char conca[length1+length2];

    for(int i=0;i<length1;i++){
        conca[i]=string1[i];
    }

    int n=0;

    for(int i=length1;i<(length1+length2-1);i++){
        conca[i]=string2[n];
        n++;
    }

   
    for(int i=0;i<(length1+length2);i++){
        result[i]=conca[i];

    }
}


int comp (char string1[],char string2[]){
    int sum1=0;
    int sum2=0;
    int length1=0;
    int length2=0;
    length1=stringlength(string1);
    length2=stringlength(string2);

    int i=0;
    while(string1[i]!='\0'){
        sum1+=string1[i];
        i++;
    }
    i=0;
    while(string2[i]!='\0'){
        sum2+=string2[i];
        i++;
    }

    if (sum1<sum2){
        return -1;
    }

    else if (sum1>sum2){
        return 1;
    }

    else if (sum1==sum2){
        return 0;
    }
    
    else return 99;
}


void main (void){

    char testString1[50];
    char testString2[50];

//Input
    printf("\nEnter the first string you want to use (max 50 characters): ");
    scanf("%s",testString1);

    printf("\nEnter the second string you want to use (max 50 characters): ");
    scanf("%s",testString2);

//Length Test
    int length1=0;
    length1=stringlength(testString1);
    printf("\nLength for string 1 is %d",length1);

    int length2=0;
    length2=stringlength(testString2);
    printf("\nLength for string 2 is %d",length2);

//Concatenate Test
    char concat[100];
    concatenate(concat,testString1,testString2);
    printf("\nString concatenated is %s",concat);

//Compare Test
    int result=0;
    result=comp(testString1,testString2);
    printf("\nWhen comparing like strncomp(), the result is %d",result);


}