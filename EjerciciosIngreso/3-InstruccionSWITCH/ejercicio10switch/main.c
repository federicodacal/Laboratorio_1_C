/**
Una agencia de viajes nos piden informar si hacemos viajes a lugares según la estación del año estemos, informar si "Se viaja" o "No se viaja" a ese lugar

en Invierno: Solo Bariloche informa "se viaja" los demas destinos "No se viaja"

en Verano: Se viaja a Mar del plata y Cataratas solamente

en Otoño: Se viaja a todos los destinos.

primavera: solo no se viaja a Bariloche
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char destino;
    char estacion;

    printf("Ingrese destino: b=Bariloche, c=Cataratas, m=Mar del Plata ");
    fflush(stdin);
    scanf("%c", &destino);
    destino=tolower(destino);
    while(destino != 'b' && destino != 'c' && destino != 'm'){
        printf("Error. Ingrese destino: b=Bariloche, c=Cataratas, m=Mar del Plata ");
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

    switch(estacion){
        case 'i':
            if(destino=='b'){
                printf("Se viaja");
            }
            else{
                printf("No se viaja");
            }
            break;
        case 'v':
        case 'p':
            if(destino=='b'){
                printf("No se viaja");
            }
            else{
                printf("Se viaja");
            }
            break;
        case 'o':
            printf("Se viaja");
            break;
    }
    return 0;
}
