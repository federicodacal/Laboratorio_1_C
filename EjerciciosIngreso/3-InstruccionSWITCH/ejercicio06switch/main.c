/**
Al ingresar una hora, informar:
si est� entre las 7 y las 11 : "Es de ma�ana.".
si est� entre las 12 y las 19 : "Es de tarde.".
si est� entre las 20 y las 24 o entre las 0 y las 6 : "Es de noche.".
si NO est� entre las 0 y las 24 : "la hora no existe.".
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;

    printf("Ingresar una hora del dia: ");
    scanf("%d", &opcion);

    switch(opcion){
    case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
            printf("Es de noche");
            break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            printf("Es de maniana");
            break;
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            printf("Es de tarde");
            break;
        default:
            printf("Dato no valido");
            break;
    }
    return 0;
}
