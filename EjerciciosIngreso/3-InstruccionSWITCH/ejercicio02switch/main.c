/**
Al seleccionar un mes informar:
si estamos en Invierno: "Abrigate que hace frio."
si aún no llego el Invierno: "Falta para el invierno."
si ya paso el Invierno: "Ya pasamos el frio, ahora calor!!!."
ACLARAcIÓN: tomamos a Julio y Agosto como los meses de Invierno.
**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    printf("Seleccionar un mes del anio del 1 al 12: ");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            printf("Aun no llegamos al invierno.");
            break;
        case 7:
        case 8:
            printf("Abrigate que hace frio!");
            break;
        case 9:
        case 10:
        case 11:
        case 12:
            printf("Ya pasamos el frio, ahora calor!");
            break;
        default:
            printf("No es una opcion valida");
            break;
    }

    return 0;
}
