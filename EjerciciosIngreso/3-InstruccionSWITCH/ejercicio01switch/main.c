/**
Al seleccionar un mes informar.
si es Enero: "que comiences bien el año!!!."
si es Marzo: "a clases!!!."
si es Julio: "se vienen las vacaciones!!!."
si es Diciembre: "Felices fiesta!!!."
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char opcion;

    printf("Seleccionar un mes: e=Enero, m=Marzo, j=Julio o d=Diciembre: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);

    switch(opcion){
        case 'e':
            printf("Que comiences bien el anio!!!");
            break;
        case 'm':
            printf("A clases!!!");
            break;
        case 'j':
            printf("Se vienen las vacaciones!");
            break;
        case 'd':
            printf("Felices Fiestas!");
            break;
        default:
            printf("No es una opcion valida");
            break;

    }
    return 0;
}
