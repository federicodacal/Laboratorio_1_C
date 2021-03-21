/**
Al ingresar una edad que sea igual a 15, mostrar el mensaje.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;

    printf("Ingrese edad: ");
    scanf("%d", &edad);
    while(edad<1 || edad>110){
        printf("Error. Ingrese edad: ");
        scanf("%d", &edad);
    }

    if(edad!=15){
        printf("La edad no es 15");
    }
    else{
        printf("La edad es 15");
    }
    return 0;
}
