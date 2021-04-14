/**
Declarar un array de tamaño 5, cargarlo secuencialmente y:
a) mostrarlo tal cual fue cargado
b) mostrarlo al reves
**/

#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 5

int mostrarNumeros (int vector[], int numerosLength);
int mostrarNumerosReves(int vector[], int numerosLength);

int main()
{
    int numeros[NUMEROS_LENGTH]={2,4,6,8,10};

    mostrarNumeros(numeros, NUMEROS_LENGTH);
    mostrarNumerosReves(numeros, NUMEROS_LENGTH);
    return 0;
}

int mostrarNumeros (int vector[], int numerosLength)
{
    int function_success=-1;

    if(vector!=NULL && numerosLength>0){

        for(int i=0;i<numerosLength;i++){

            printf("%d ", vector[i]);
        }
        printf("\n");
        function_success=0;
    }
    return function_success;
}

int mostrarNumerosReves (int vector[], int numerosLength)
{
    int function_success=-1;

    if(vector!=NULL && numerosLength>0){

        for(int i=numerosLength-1;i>=0;i--){

            printf("%d ", vector[i]);
        }
        printf("\n");
        function_success=0;
    }
    return function_success;
}
