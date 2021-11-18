/* Challenge: Write a small program that declares:
An int variable with block scope and temporary storage
A global float variable that is accesible within the entire program
A float local variable with permanent storage
a register int variable
a function that is only accessible with the file it is defined */

    static float f=0;
    static foo(void){
        //Function
    }

int main(void){
    int x=5;
    static float perm=22;
    register int reg=10;
    
}