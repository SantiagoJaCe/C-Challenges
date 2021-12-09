/* Challenge: Write a c program to convert uppercase to lowercase and viceversa
in a file*/

#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"

int main(){

    char* name=(char*)calloc(15,sizeof(char));
    printf("Enter the name of the file: ");
    scanf("%s",name);
    FILE *fp=fopen(name,"r");
    FILE *temp=fopen("temp.txt","w");
    char check=fgetc(fp);
    for(;check!=EOF;check=fgetc(fp)){
        if(check=='\n'||check=='\0') fputc('\n',temp);
        else if(isupper(check)){
            check=tolower(check);
            fputc(check,temp);

        }

        else if(islower(check)){
            check=toupper(check);
            fputc(check,temp);

        }
    }
    fclose(temp);
    fclose(fp);
    remove(name);
    rename("temp.txt",name);
    free(name);
    

}