#include <stdio.h>
#include <stdlib.h>

void sumar(int a, int b, int* pResultado)
{
    *pResultado=a+b;
}

void restar(int a, int b, int* pResultado)
{
   *pResultado=a-b;
}

int calcular(int a, int b, void(*pFuncion)(int, int, int*))
{
    int auxResultado;
    pFuncion(a,b,&auxResultado);
    return auxResultado;
}

int main()
{
    int aux;

    aux=calcular(10,5,restar);
    printf("El resultado de la resta es %d\n",aux);

    aux=calcular(10,5,sumar);
    printf("El resultado de la suma es %d\n",aux);

    return 0;
}
