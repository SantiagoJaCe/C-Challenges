/* Challenge: Write a program to read the elements in a variable
length array and find the sum of the elements */

#include "stdio.h"

int main(void){

    int size=0;
    printf("Type in the size of the array\n");
    scanf("%d",&size);

    int VLA[size];
    int sum=0;
    printf("An array of %d elements has been created, type in the elements: \n",size);
    for (int i=0;i<size;i++){
        printf("Element %d:\n",i);
        scanf("%d",&VLA[i]);
        sum+=VLA[i];
    }

    printf("The sum of the elements in the array is %d\n",sum);

}