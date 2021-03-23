/**
1. Para el departamento de facturación:
A. Ingresar tres precios de productos y mostrar la suma de los mismos.
B. Ingresar tres precios de productos y mostrar el promedio de los mismos.
C. ingresar tres precios de productos sumarlos y mostrar precio final (más IVA 21%).
**/

#include <stdio.h>
#include <stdlib.h>
float sumar(float a, float b, float c);
float calcularPromedio(float a, float b, float c);
float calcularImpuesto(float a, float b, float c);

int main()
{
    float precio1;
    float precio2;
    float precio3;
    float suma;
    float promedio;
    float precioFinal;

    printf("Ingrese el primer precio: ");
    scanf("%f", &precio1);
    printf("Ingrese el primer precio: ");
    scanf("%f", &precio2);
    printf("Ingrese el tercer precio: ");
    scanf("%f", &precio3);

    suma=sumar(precio1,precio2,precio3);
    printf("El resultado de la suma es: %.2f\n", suma);
    promedio=calcularPromedio(precio1,precio2,precio3);
    printf("El promedio es: %.2f\n", promedio);
    precioFinal=calcularImpuesto(precio1,precio2,precio3);
    printf("El precio con IVA incluido es: $%.2f", precioFinal);
}

float sumar(float a, float b, float c){
    float suma;
    suma=a+b+c;
    return suma;
}

float calcularPromedio(float a, float b, float c){
    float suma;
    float promedio;
    suma=a+b+c;
    promedio=suma/3;
    return promedio;
}

float calcularImpuesto(float a, float b, float c){
    float suma;
    float precioIVA;
    float porcentajeIVA=21;
    float precioFinal;
    suma=a+b+c;
    precioIVA=porcentajeIVA/100*suma;
    precioFinal=suma+precioIVA;
    return precioFinal;
}
