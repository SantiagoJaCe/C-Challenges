/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. 
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. */
#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"

int* twoSum(int* nums, int numsSize, int target,int* result);

void main(){

    int* pNums=NULL;
    int Nums[]={2,7,11,15};
    int NumsSize=sizeof(Nums)/sizeof(int);
    int target=9;
    pNums=(int*)malloc(sizeof(Nums));
    pNums=Nums;
    int* result=(int*)malloc(2*sizeof(int));
    result=twoSum(pNums,NumsSize,target,result);
    printf("\n###%d and %d###",*(result),*(result+1));

}

int* twoSum(int* nums, int numsSize, int target,int* returnSize){

    int* result=(int*)malloc(2*sizeof(int));
    *returnSize=2;
    
    for(int i=0;i<numsSize;i++){
        for(int x=0;x<numsSize;x++){

            if(i==x) continue;

            else if (target==*(nums+i)+*(nums+x)){
                *result=i;
                *(result+1)=x;
                goto END;
            }
        }
    }
    
    END:
    return result;
    
}