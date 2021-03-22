#include <stdio.h>
#include <stdlib.h>
// Prototipo de la funcion (void, no retorna nada)
// No recibe, no devuelve
void sumarv1(void);     // tambien se pueden dejar los parentesis vacios para indiciar que no recibe nada

int main()
{
    // Llamada
    sumarv1();
    return 0;
}

// Desarrollo
void sumarv1()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado=num1+num2;
    printf("El resultado de la suma es: %d", resultado);
}
