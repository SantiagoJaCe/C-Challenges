/* Challenge: Write a program that takes two command-line arguments.
The first is a character, the second is a filename-
The requirements of the program are that it should print only
those lines in the file containing the given character.
Lines are identified by the newline character '\n'.
Assume no line is more than 256 characters long */ 

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[]){

    if (argc==1){
        puts("ERROR IN ARGUMENTS");
        exit(1);
    }

    FILE* fp=fopen(argv[2],"r");
    char* buffer=NULL;
    size_t bufsize=256*sizeof(char);
    size_t characters;
    buffer=(char*)malloc(256*sizeof(char));
    characters=getline(&buffer,&bufsize,fp);

    while (characters<256){
        for(int i=0;*(buffer+i)!='\n';i++){
            if(*(buffer+i)==*argv[1]){
            puts(buffer);
            break;
            }
        }

        characters=getline(&buffer,&bufsize,fp);
    }

    fclose(fp);
    free(buffer);
    
}