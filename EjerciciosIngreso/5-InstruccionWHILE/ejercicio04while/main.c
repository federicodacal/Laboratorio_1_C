/**
Pedir un número entre 0 y 9 inclusive.
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int numero;

    printf("Ingrese un nro. del 0 a 9: \n");
    scanf("%d", &numero);
    while(numero<0 || numero>9){
        printf("Error. Ingrese nro. del 0 a 9: ");
        scanf("%d", &numero);
    }
    printf("El numero ingresado es %d", numero);
    return 0;
}
