#include <stdio.h>
#include <stdlib.h>

void swap (int* x, int* y);

int main()
{
    int a=9;
    int b=5;
    //int aux;

    printf("Antes del swap a = %d b = %d\n", a, b);

    //aux=a;
    //a=b;
    //b=aux;
    swap(&a, &b); // Direccion de memoria de a y de b

    printf("Antes del swap a = %d b = %d\n", a, b);
    return 0;
}

void swap (int* x, int* y)
{
    // x -> direccion en memoria de variable a
    // y -> direccion en memoria de variable b
    int aux;
    aux = *x; // *x -> * direccion en memoria de a (guardada en x)
    *x = *y;  // *y -> * direccion en memoria de b (guardada en y)
    *y = aux;
}
