/**
Al selecionar un destino, indicar el punto cardinal de nuestro pais en donde se encuentra Norte, Sur, Este u Oeste
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char opcion;

    printf("Seleccionar un destino: b=Bariloche, c=Cataratas, m=Mar del Plata u=Ushuaia ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);

    switch(opcion){
        case 'b':
            printf("Oeste");
            break;
        case 'c':
            printf("Norte");
            break;
        case 'm':
            printf("Este");
            break;
        case 'u':
            printf("Sur");
            break;
        default:
            printf("Dato no valido");
            break;
    }

    return 0;
}
