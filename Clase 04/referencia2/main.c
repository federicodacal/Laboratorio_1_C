#include <stdio.h>
#include <stdlib.h>

void duplicar(int* p);

int main()
{
    int num;
    int* puntero = &num;

    num=23; // num es el nombre de fantasia o identificador

    *(&num)=23; // el valor en la direccion de memoria de num

    printf("Numero: %d\n",num);
    printf("Direccion de memoria: %d\n", &num);
    printf("Numero: %d\n\n", *(&num));

    *puntero=45;

    printf("Numero: %d\n",num);
    printf("Direccion de memoria: %d\n", &num);
    printf("Numero: %d\n\n", *(&num));

    printf("Antes de llamar a duplicar el nro vale: %d\n", num);
    duplicar(&num);
    printf("Despues de llamar a duplicar el nro vale: %d\n", num);

    return 0;
}

void duplicar(int* p) // Pasaje de valor por referencia
{
    *p*=2;
}
