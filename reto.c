/* Reto: Programa que imprima el tamaño de byte
de tipos de datos básicos */

#include <stdio.h>

int main(){
    //Variables
    int sizeint=0;
    int sizechar=0;
    int sizelong=0;
    int sizelonglong=0;
    int sizedouble=0;
    int sizelongdouble=0;

    //Operations
    sizeint = sizeof(int);
    sizechar = sizeof(char);
    sizelong = sizeof(long);
    sizelonglong = sizeof(long long);
    sizedouble = sizeof(double);
    sizelongdouble = sizeof(long double);

    //Output
    printf("Int: %zd\nChar: %zd\nLong: %zd\nLong Long: %zd\nDouble: %zd\nLong Double: %zd", sizeint,sizechar,sizelong,sizelonglong,sizedouble,sizelongdouble);
    
    return 0;
}



