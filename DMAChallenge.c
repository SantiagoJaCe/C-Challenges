/*Challenge: Write a program that tests your understanding of Dynamic Memory Allocation.
The program allows the user to input a text string, must be stored by using DMA, and print this text.
The user can enter the limit of the string they are entering.
The program should create a char pointer only, no character arrays. 
RELEASE THE MEMORY WHEN YOU'RE DONE USING IT */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main(void){

    char *str=NULL;
    int limit=0;
    printf("Remember the size of:\n int: %d bytes\n char: %d bytes\n",sizeof(int),sizeof(char));
    printf("Type in the amount of bytes you want to occupy: \n");
    scanf("%d",&limit);
    str=(char *)malloc(limit);

    //Check for NULL
    if (str!=NULL){

        printf("Now type the string, NO SPACES: ");
        scanf("%s",str);
        printf("\n#####The input was: %s#####",str);

    }

    else
        printf("########################Error####################");

    free(str);
    
}