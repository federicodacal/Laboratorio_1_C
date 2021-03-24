/**
Construcción:
A. mostrar la cantidad de alambre a comprar si se ingresara el largo y el ancho de un terreno rectangular y se debe alambrar con tres hilos de alambre.
B. mostrar la cantidad de alambre a comprar si se ingresara el radio de un terreno circular y se debe alambra con tres hilos de alambre.
C. Para hacer un contrapiso de 1m x 1m se necesitan 2 bolsas de cemento y 3 de cal, debemos mostrar cuantas bolsas se necesitan de cada uno para las medidas del terreno rectangular.
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float calcularRectangulo();
float calcularCircunferencia();

int main()
{
    char opcion;
    float areaRectangulo;
    float areaCircunferencia;

    printf("Que area desea calcular? r=Rectangulo, c=Circunferencia ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);
    while(opcion!='r' && opcion!='c'){
        printf("Que area desea calcular? r=Rectangulo, c=Circunferencia ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);
    }

    if(opcion=='r'){
        areaRectangulo=calcularRectangulo();
        printf("El area del circulo es: %.2f", areaRectangulo);
    }
    else{
        areaCircunferencia=calcularCircunferencia();
        printf("El area del circulo es: %.2f", areaCircunferencia);
    }

    return 0;
}

float calcularRectangulo()
{
    float ancho;
    float largo;
    float area;
    printf("Ingrese el ancho: ");
    scanf("%f", &ancho);
    printf("Ingrese el largo: ");
    scanf("%f", &largo);
    area=ancho*largo;
    return area;
}

float calcularCircunferencia()
{
    float radio;
    float area;
    printf("Ingrese el radio: ");
    scanf("%f", &radio);
    area=3.14*radio*radio;
    return area;
}
