/* LeetCode Challenge: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order. */

#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"

bool isValid(char * s);

int main(void){
    char * s ="([]){";
    bool result=isValid(s);
    if (result) printf("VALID\n");
    else printf("INVALID\n");
}

bool isValid(char * s){
    char *queue = (char*)calloc(strlen(s)+5,sizeof(char));
    int q=0;
    int counter=0;
    while (*(s+counter)!='\0'){
        if ((*(s+counter)==')'||*(s+counter)==']'||*(s+counter)=='}')&&(counter==0)){
            free(queue);
            return false;
        }

        else if (*(s+counter)=='('||*(s+counter)=='['||*(s+counter)=='{'){
            (*(queue+q))=(*(s+counter));
            q++;
        }
        
        if (*(s+counter)==')'||*(s+counter)==']'||*(s+counter)=='}'){

            if (q==0){
                free(queue);
                return false;
            }

            if(((int)(*(s+counter)))-((int)(*(queue+q-1)))>2||((int)(*(s+counter)))-((int)(*(queue+q-1)))<-2){
                free(queue);
                return false;
            }
            else q--;
        }
        counter++;
    }

    if (counter==q){
        free(queue);
        return false;
    }
    
    free(queue);
    
    if(q>=1){
        return false;
    }
    return true;
}