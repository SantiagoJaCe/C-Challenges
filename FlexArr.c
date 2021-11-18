/* Challenge: Write a Program that uses a flexible array member
inside a structure */

#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

struct myarr{
    int length;
    int flexArr[];
};

int main(void){

    int size=0;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    struct myarr *ptr=NULL;

    ptr=malloc(sizeof( struct myarr )+size*sizeof(int));

    ptr->length=size;
    printf("\nEnter the array elements:\n");
    for (int i=0;i<size;i++){
        printf("Element %d\n",i);
        scanf("%d",&(ptr->flexArr[i]));
    }

    printf("The elements are: \n");
    for (int i=0;i<size;i++){
        printf("Element %d is %d\n",i,ptr->flexArr[i]);
    }
    
    return 1;
}