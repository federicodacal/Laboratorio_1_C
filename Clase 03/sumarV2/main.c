#include <stdio.h>
#include <stdlib.h>
// Prototipo (no devuelve, recibe)
void sumarv2(int a, int b); // Parametros entre ()

int main()
{
    int num1;
    int num2;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    // Llamada
    sumarv2(num1,num2);

    return 0;
}

// Desarollo
void sumarv2(int a, int b)
{
    int resultado;
    resultado=a+b;
    printf("El resultado de la suma es %d", resultado);
}
