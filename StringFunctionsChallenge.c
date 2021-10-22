/* Write a program that displays a string in reverse order,
it should take input from the keyboard.
Write another program that sorts the strings of an array by their ASCII value,
using bubble sorting. */

#include "string.h"
#include "stdio.h"


//Reverse order function.
void reverse(char string1[],char string2[]){
    int i=0;
    int length=strlen(string1);
    int try=strlen(string1)-1;

    for (i=0;i<length;i++){

        string2[i]=string1[try];
        try-=1;

    }
}


//Swapping for sorting function
void swap(char word1[],char word2[]){
    char temp[50];
        strcpy(temp,word2);
        strcpy(word2,word1);
        strcpy(word1,temp);
}

//Sorting strings function.
void sorting(char word1[],char word2[], char word3[]){
    int check1=strcmp(word1,word2);
    int check2=strcmp(word2,word3);

    while(check1>0||check2>0){
        if (check1>0){
            swap(word1,word2);
        }

        else if(check2>0){
            swap(word2,word3);
        }

        check1=strcmp(word1,word2);
        check2=strcmp(word2,word3);
    }
}

void main(void){

    char myStr[50];
    char strReversed[50];

    printf("Type the string you want to reverse (Max 50 characters): ");
    scanf("%s",myStr);

    reverse(myStr,strReversed);
    printf("\nThe string \"%s\" reversed is \"%s\"\n",myStr,strReversed);

    char word1[50], word2[50], word3[50];
    printf("\nType the first word on the list: \n");
    scanf("%s",word1);

    printf("\nType the second word on the list: \n");
    scanf("%s",word2);

    printf("\nType the third word on the list: \n");
    scanf("%s",word3);

    sorting(word1,word2,word3);

    printf("\nThe order is: \n1)%s\n2)%s\n3)%s\n",word1,word2,word3);
}