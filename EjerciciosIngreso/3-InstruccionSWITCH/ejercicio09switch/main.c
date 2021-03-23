/**
Una agencia de viajes debe sacar las tarifas de los viajes, se cobra $15.000 por cada estadia como base, se pide el ingreso de una estacion del año y localidad para vacacionar para poder calcular el precio final

en Invierno: bariloche tiene un aumento del 20% cataratas y ushuaia tiene un descuento del 10% Mar del plata tiene un descuento del 20%

en Verano: bariloche tiene un descuento del 20% cataratas y ushuaia tiene un aumento del 10% Mar del plata tiene un aumento del 20%

en Otoño y Primavera: bariloche tiene un aumento del 10% cataratas tiene un aumento del 10% Mar del plata tiene un aumento del 10% y ushuaia tiene el precio sin descuento
**/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char destino;
    char estacion;
    const float costoBruto=15000;
    float costoFinal;
    int porcentaje;
    float descuento;

    printf("Ingrese destino: b=Bariloche, c=Cataratas, m=Mar del Plata, u=Ushuaia ");
    fflush(stdin);
    scanf("%c", &destino);
    destino=tolower(destino);
    while(destino != 'b' && destino != 'c' && destino != 'm' && destino != 'u'){
        printf("Error. Ingrese destino: b=Bariloche, c=Cataratas, m=Mar del Plata, u=Ushuaia ");
        fflush(stdin);
        scanf("%c", &destino);
    }

    printf("Ingrese estacion: i=Invierno, v=Verano, p=Primavera, o=Otonio ");
    fflush(stdin);
    scanf("%c", &estacion);
    estacion=tolower(estacion);
        while(estacion != 'i' && estacion != 'v' && estacion != 'p' && estacion != 'o'){
        printf("Error. Ingrese estacion: i=Invierno, v=Verano, p=Primavera, o=Otonio ");
        fflush(stdin);
        scanf("%c", &estacion);
        estacion=tolower(estacion);
    }

    switch(destino){
        case 'b': // Bariloche
            if(estacion=='i'){
                porcentaje=20;
            }
            else if(estacion=='v'){
                porcentaje=-20;
            }
            else{
                porcentaje=-10;
            }
            break;
        case 'c': // Cataratas
            if(estacion=='i'){
                porcentaje=-10;
            }
            else{
                porcentaje=10;
            }
            break;
        case 'm': // Mar del Plata
            if(estacion=='i'){
                porcentaje=-20;
            }
            else if(estacion=='v'){
                porcentaje=20;
            }
            else{
                porcentaje=10;
            }
            break;
        case 'u': // Ushuaia
            if(estacion=='i'){
                porcentaje=-10;
            }
            else{
                porcentaje=10;
            }
            break;
    }

    descuento=(float) porcentaje/100*costoBruto;
    costoFinal=(float) costoBruto+descuento;

    printf("El costo final es %.2f", costoFinal);

    return 0;
}
