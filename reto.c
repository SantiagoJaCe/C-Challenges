/*************************************************
Reto: Programa que convierte el número de minutos
ingresados a días y años
**************************************************/

#include <stdio.h>

int main(){
    //Variables
    int min=0;
    double dias=0;
    double años=0;

    //Input
    printf("Inserta la cantidad de minutos que quieres convertir a días y años, solo enteros:");
    scanf("%d", &min);

    //Operaciones
    dias = ((double)min)/1440;
    años = dias/365;

    //Output
    printf("%d minutos son %f días o %f años.\n",min,dias,años);
    printf("################################################");
}

