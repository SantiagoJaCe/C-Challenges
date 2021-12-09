/* Challenge: Write a program to coun the number of words and characters
in a file or standard input */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void filestream(void);
void standardstream(void);

int main(){

    printf("Do you want to read in from a file? (y/n)\n");
    char answer=getchar();
    if (answer=='y'||answer=='Y') filestream();
    else standardstream();
}

void standardstream(void){

    printf("Type in words and press enter, if you want to stop type \"stop\"\n");
    unsigned int charcount=0;
    unsigned int wordcount=0;
    char *str=(char*)calloc(30,sizeof(char));
    scanf("%s",str);
    while(strcmp(str,"stop")!=0){
        for(unsigned int i=0;*(str+i)!='\0';i++,charcount++);
        wordcount++;
        scanf("%s",str);
    }

    printf("charcount: %d\n",charcount);
    printf("wordcount: %d\n",wordcount);
    free(str);
}

void filestream(void){

    char name[15];
    printf("Enter the name of the file including \".txt\":");
    scanf("%s",&name);
    FILE* fp=fopen(name,"r");

    char check=fgetc(fp);
    unsigned int charcount=0;
    unsigned int wordcount=0;
    while(check!=EOF){
        if (check==' '){
            wordcount++;
            check=fgetc(fp);
            continue;
        }
        else if (check=='\n'){
            charcount-=1;
            wordcount++;
            check=fgetc(fp);
            continue;
        }
        charcount++;
        check=fgetc(fp);
    }

    wordcount++;
    printf("charcount: %d\n",charcount);
    printf("wordcount: %d\n",wordcount);


    fclose(fp);
}