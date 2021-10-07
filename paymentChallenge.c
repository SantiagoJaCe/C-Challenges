/* Reto: Programa que pida al usuario las horas trabajadas en
una semana e imprima el sueldo total, los impuestos, sueldo después de impuestos.
Si son $12/hr, después de 40hrs se pagan $18/hr
Impuestos:
15% los primeros $300
20% los siguientes $150
25% el resto
*/

#include <stdio.h>

int main(void){

    //Variables
    int horas=0;
    double sueldo1=0;
    double sueldo2=0;
    double extra=0;
    double impuesto1=0;
    double impuesto2=0;
    double impuesto3=0;
    double impuestoT=0;

    //Input
    label:
    horas=0;
    sueldo1=0;
    sueldo2=0;
    extra=0;
    impuesto1=0;
    impuesto2=0;
    impuesto3=0;
    impuestoT=0;

    printf("Ingrese la cantidad de horas trabajadas en la semana: ");
    scanf("%d", &horas);

    //Sueldo antes de impuestos

    if (horas>40){
        extra=horas-40;
        horas=horas-extra;
        sueldo1=(horas*12)+(extra*18);
    }

    else
        sueldo1=horas*12;


    //Calcular impuestos
    if (sueldo1<=300){
        impuesto1=sueldo1*0.15;
        impuesto2=0;
        impuesto3=0;
    }

    else if (sueldo1>300 && sueldo1<=450){
        impuesto1=300*0.15;
        impuesto2=(sueldo1-300)*0.20;
        impuesto3=0;
    }

    else if(sueldo1>450){
        impuesto1=300*0.15;
        impuesto2=150*0.2;
        impuesto3=(sueldo1-450)*0.25;
    }

    else
        printf("ERROR");

    //Calcular sueldo después de impuestos

    impuestoT=impuesto1+impuesto2+impuesto3;
    sueldo2=sueldo1-impuestoT;

    //Output
    printf("El sueldo antes de impuestos es: $%.2f\n",sueldo1);
    printf("Los impuestos restados son: $%.2f\n", impuestoT);
    printf("El sueldo después de los impuestos es: $%.2f\n",sueldo2);

    //Salir
    printf("############################################################\n");
    goto label; 


}