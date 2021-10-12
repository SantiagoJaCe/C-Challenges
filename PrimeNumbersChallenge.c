/* Challenge: Create a program that finds and stores all
prime numbers from 3 to 300 and stores it in an array as they're
generated. */

#include <stdio.h>

int main(){

int p=0;
int c=1;

    for (int i=0;i<=300;++i){
        for (int x=i-1;x>=2;--x){
            if (i%x==0)
            break;

            else if (x==2)
            p+=1;
        }
    }
p+=1;
int prime[p];
prime[0]=2;
prime[1]=3;

    for (int i=0;i<=300;++i){
        for (int x=i-1;x>=2;--x){
            if (i%x==0)
            break;

            else if (x==2)
            c+=1;
            prime[c]=i;
        }
    }

for (int z=0; z<p;++z){
    printf("Element %d is the prime number %d\n",z,prime[z]);
}


}
