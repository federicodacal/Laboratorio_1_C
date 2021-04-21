/**
Al ingresar una edad debemos informar si la persona es mayor de edad (mas de 18 años) o adolescente (entre 13 y 17 años) o niño (menor a 13 años).**/
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

    if(edad<13){
        printf("Es menor de edad");
    }
    else {
        if(edad<18){
            printf("Es adolescente");
            }
                else{
                    printf("Es mayor de edad");
            }
        }


    return 0;
}
