/** Challenge: 
-Write a function that finds the greatest common
divisor of two non-negative integer values, and to return the result.
-Write a function to calculate the absolute value of a number,
with parameters as a signed float.
-Write a function to compute the square root of a number
without libraries. Should use the absolute value function if a value is
negative. */

#include "stdio.h"

//Greatest Common Divisor Function
int GCD(int x,int y){
    //Using Euclid's Algorithm
    int r=0;
    int q=0;
    int gcd=0;

loop:

    if (x==y)
        gcd=x;
    
    else if (x%y==0){
        gcd=y;
    }

    else if (y%x==0){
        gcd=x;
    }


    else if (x>y){
        label:
        r=x%y;
        if (r==0){
            gcd=y;
        }

        else{
            q=y%r;
            if(q==0){
                gcd=r;
            }

            else{
                x=r%q;
                if(x==0){
                    gcd=q;
                }

                else{
                    y=q%x;
                    if (y==0){
                        gcd=x;
                    }

                    else{goto label;}
                }
            }
        }
    }

    else if(x<y){
        r=x;
        q=y;

        x=q;
        y=r;

        goto loop;
    }

    return gcd;
    //END OF GCD FUNCTION
}

//Absolute value function
float absVal(float x){

    float absValue=0;

    if (x>0){
    absValue=x;
    }

    else{
        absValue=(x*-1);
    }

    return absValue;
    //End of AbsoluteValue function
}

//Square Root Function
float sqroot(float x){
    if (x<0){
        x=absVal(x);
    }

    float n=x;
    float a=0;
    float b=n;
//Newton-Raphson Method
    for (int i=0;i<99999;++i){
            a=(b+(n/b))/2;
            b=(a+(n/a))/2;
    }

    return a;

}

int main(void){

    int sel=0;

    printf("Options:\nCalculate GCD of two positive integers: type 1\n");
    printf("Calculate the absolute value of any number: type 2\n");
    printf("Calculate the square root of the absolute value of any number: type 3\n");

start:

    printf("Select option:\n");
    scanf("%d",&sel);


    if (sel==1){
        printf("You selected GCD.\nType the two numbers separated by a single space:\n");
        int a=0;
        int b=0;

        int gcd=0;

        scanf("%d %d",&a,&b);
        a=absVal(a);
        b=absVal(b);

        gcd=GCD(a,b);
        printf("The GCD of %d and %d is %d",a,b,gcd);
    }

    else if (sel==2){
        printf("You selected Absolute Value.\nType any number you want to find the absolute value of:\n");
        float a=0;
        scanf("%f",&a);
        a=absVal(a);
        printf("The absolute value is %f",a);
    }

    else if (sel==3){
        printf("You selected Square Root.\nType any number you want to find the square root of:\n");
        float a=0;
        scanf("%f",&a);
        a=sqroot(a);
        printf("The square root is %f",a);
    }

    else{
    printf("Error, you didn't select any option, try again\n");
    goto start;
    }


}