/**
Pedir dos numeros e informar la suma de los mismos
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado=num1+num2;
    printf("El resultado es: %d", resultado);
    return 0;
}
