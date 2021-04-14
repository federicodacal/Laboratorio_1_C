/**
Federico Dacal
Division "A"

Crear una funci�n que reciba como par�metro un numero entero. La funci�n
retornara 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en
caso de que sea 0. Realizar la prueba l�gica de la funci�n en el main.
**/

#include <stdio.h>
#include <stdlib.h>

int verificarNumero(int x);

int main()
{
    int x;
    int verificar;

    printf("Ingrese un numero: ");
    scanf("%d", &x);
    verificar=verificarNumero(x);

    printf("Respuesta: %d", verificar);
    return 0;
}

int verificarNumero(int x)
{
    int respuesta;

    if(x==0){
        respuesta=0;
    }
    else if (x<0){
        respuesta=-1;
    }
    else{
        respuesta=1;
    }

    return respuesta;
}
