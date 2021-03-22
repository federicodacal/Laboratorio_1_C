#include <stdio.h>
#include <stdlib.h>
// Prototipo (devuelve, recibe)
int sumarv4(int a, int b);

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado=sumarv4(num1, num2);
    printf("El resultado es: %d", resultado);
    return 0;
}

// Desarrollo
int sumarv4(int a, int b)
{
    int resultado;
    resultado=a+b;
    return resultado;

    // return a+b;
}
