/*Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.
*/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

bool isPalindrome(int x);

int main(){
    int number=0;
    printf("\nEnter a number: \n");
    scanf("%d",&number);

    bool result=isPalindrome(number);
    if (result==true) printf("%d is a palindrome\n",number);
    else printf("%d is NOT a palindrome\n",number);
}

bool isPalindrome(int x){
    
    char *str=(char*)malloc(sizeof(x)/sizeof(int));
    sprintf(str,"%d",x);
    const char *last=str;

    last=str+strlen(str)-1;


    for (int i=0;i<strlen(str);i++){
        if(*(str+i)!=*(last-i)){
            return false;
        }
        else{
            continue;
        }
    }
    free(str);
    return true;
}
