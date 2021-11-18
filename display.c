#include "stdio.h"

extern int shared;

void extern display(){
    printf("%d\n",shared);
}