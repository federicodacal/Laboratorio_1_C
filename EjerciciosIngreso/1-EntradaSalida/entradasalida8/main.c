/**
Debemos lograr tomar los numeros, realizar la operaci�n correcta y mostrar el resto entre el dividendo y el divisor.
ej.: "El resto es 0 ."
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividendo;
    int divisor;
    int resto;

    printf("Ingrese el dividendo: ");
    scanf("%d", &dividendo);
    while(dividendo==0){
        printf("No es posible dividir al numero 0. Ingrese dividendo: ");
        scanf("%d", &dividendo);
    }

    printf("Ingrese el divisior: ");
    scanf("%d", &divisor);

    resto=dividendo%divisor;
    printf("El resto es %d", resto);

    return 0;
}