/**
Las lámparas están al mismo precio de $35 pesos final.
A. Si compra 6 o más lamparitas bajo consumo tiene un descuento del 50%.
B. Si compra 5 lamparitas bajo consumo marca "ArgentinaLuz" se hace un descuento del 40 % y si es de otra marca el descuento es del 30%.
C. Si compra 4 lamparitas bajo consumo marca "ArgentinaLuz" o “FelipeLamparas” se hace un descuento del 25 % y si es de otra marca el descuento es del 20%.
D. Si compra 3 lamparitas bajo consumo marca "ArgentinaLuz" el descuento es del 15%, si es “FelipeLamparas” se hace un descuento del 10 % y si es de otra marca un 5%.
E. Si el importe final con descuento suma más de $120 se debe sumar un 10% de ingresos brutos en informar del impuesto con el siguiente mensaje: ”IIBB Usted pago X”, siendo X el impuesto que se pagó.
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int pedirCantidad();
char pedirMarca();
float calcularPrecio(int a, char b);
float calcularImpuesto(float a);

int main()
{
    int cantidad;
    char marca;
    float precio;
    float precioIIBB;

    cantidad=pedirCantidad();
    marca=pedirMarca();
    printf("La marca es %c (desde main)", marca);
    precio=calcularPrecio(cantidad, marca);
    printf("El precio final es %.2f", precio);

    if(precio>120){
        precioIIBB=calcularImpuesto(precio);
        printf("El precio con impuesto IIBB es %.2f", precioIIBB);
    }

    return 0;
}

int pedirCantidad()
{
    int cantidad;
    printf("Ingrese la cantidad de unidades: ");
    scanf("%d", &cantidad);
    while(cantidad<1){
        printf("Error. Ingrese la cantidad de unidades: ");
        scanf("%d", &cantidad);
    }
    return cantidad;
}

char pedirMarca()
{
    char* punteroMarca=NULL;
    char marca;

    printf("Ingrese la marca: a=ArgentinaLuz, f=FelipeLamparas, j=Jeluz, h=HazIluminacion, o=Osram ");
    fflush(stdin);
    scanf("%c", &marca);
    marca=tolower(marca);
    while(marca!='a' && marca!='f' && marca!='j' && marca!='h' && marca!='o'){
        printf("Error. Ingrese la marca: a=ArgentinaLuz, f=FelipeLamparas, j=Jeluz, h=HazIluminacion, o=Osram ");
        fflush(stdin);
        scanf("%c", &marca);
        marca=tolower(marca);
    }
    punteroMarca=&marca;
    printf("La marca es %c (desde funcion pedirMarca)", *punteroMarca);
    return *punteroMarca;
}

float calcularPrecio(int a, char b)
{
    // a = unidades
    // b = marca
    int precioUnidad = 35;
    float precioInicial;
    int porcentaje;
    float descuento;
    float precioFinal;

    switch(a){
        case 1:
        case 2:
            porcentaje=0;
            break;
        case 3:
            if(b=='a'){
                porcentaje=15;
            }
            else if(b=='f'){
                porcentaje=10;
            }
            else{
                porcentaje=5;
            }
            break;
        case 4:
            if(b=='a' || b=='f'){
                porcentaje=25;
            }
            else{
                porcentaje=20;
            }
            break;
        case 5:
            if(b=='a'){
                porcentaje=40;
            }
            else{
                porcentaje=30;
            }
            break;
        default: // 6 o más
            porcentaje=50;
            break;
    }

    precioInicial=precioUnidad*a;

    if(porcentaje!=0){
        descuento=(float) porcentaje/100*precioInicial;
        precioFinal=(float) precioInicial-descuento;
    }
    else{
        precioFinal=precioInicial;
    }

    return precioFinal;
}

float calcularImpuesto(float a)
{
    float precioIIBB;
    float porcentajeImpuesto=10;
    float valorImpuesto;

    valorImpuesto=porcentajeImpuesto/100*a;
    precioIIBB=a+valorImpuesto;

    return precioIIBB;
}
