#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main(void){

    char myString[50];
    char operadores[4]={'*','+','-','/'};
    printf("Enter the string you want to check (NO SPACES): ");
    scanf("%s",myString);

    int i=0;
    int check=0;
    int result=1;

    while(myString[i]!='\0'){
        if (myString[i]==operadores[0]||myString[i]==operadores[1]||myString[i]==operadores[2]||myString[i]==operadores[3]){
            check+=1;
            if(check==2){
                result=0;
                break;
            }
        }

        else if(check==1&&myString[i]!=operadores[0]&&myString[i]!=operadores[1]&&myString[i]!=operadores[2]&&myString[i]!=operadores[3]){
            check-=1;
        }

        i++;

    }

    if(result==1)
        printf("True");

    else
        printf("False");

}