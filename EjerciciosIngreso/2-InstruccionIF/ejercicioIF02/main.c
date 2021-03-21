/**
Al ingresar una edad debemos informar si la persona es mayor de edad, sino informar que es un menor de edad.
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

    if(edad>17){
        printf("Es mayor de edad");
    }
    else{
        printf("Es menor de edad");
    }

    printf("");
    return 0;
}
