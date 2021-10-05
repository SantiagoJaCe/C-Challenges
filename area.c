#include <stdio.h>

int main(){

    double base;
    double altura;
    double area;
    double peri;

    printf("En este programa puedes calcular el área y el perímetro de un rectángulo, por favor usa las mismas unidades para la base y la altura\n");

    printf("Ingresa el valor de la base del rectángulo:");
    scanf("%lf",&base);
    printf("\nIngresa el valor de la altura del rectángulo:");
    scanf("%lf",&altura);

    area=base*altura;
    peri=(2*base)+(2*altura);


    printf("El área del rectángulo es %3f\n",area);
    printf("El perímetro del rectángulo es %3f",peri);
}