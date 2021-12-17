/* 14. Longest Common Prefix: Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". */
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#define SIZE 4

char * longestCommonPrefix(char ** strs, int strsSize);

int main(){

    char **strs=(char**)malloc(SIZE*200*sizeof(char));
    for(int i=0;i<SIZE;i++){
        *(strs+i)=malloc(200*sizeof(char));
    }

    strcpy(*strs,"flower");
    strcpy(*(strs+1),"flower");
    strcpy(*(strs+2),"flower");
    strcpy(*(strs+3),"flower");

    puts("########");
    puts(longestCommonPrefix(strs,SIZE));
    puts("########");

}

char * longestCommonPrefix(char ** strs, int strsSize){
    char* prefix=(char*)calloc(200,sizeof(char));
    if(strsSize==1) return strs[0];
    int check=0;
    for(int i=0; i<strlen(*strs)+1;i++){ 
        if (check==(strsSize-1)) prefix[i-1]=strs[0][i-1];
        check=0;
        for (int j=1;j<strsSize;j++){
            if(strs[0][i]==strs[j][i]){
                check++;
            }
            else goto end;
        }
    }

    end:
    return prefix;
    }