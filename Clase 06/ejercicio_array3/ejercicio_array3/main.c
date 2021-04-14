// Declarar un array de cinco enteros, pedir al usuario los numeros, informar cual fue el mayor y en que posicion se ingreso (si hubo empate mostrar las posiciones)

#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 5

int getNumeros(int vector[], int numerosLength);
int mostrarMayor(int vector[], int numerosLength);

int main()
{
    int numeros[NUMEROS_LENGTH];

    getNumeros(numeros, NUMEROS_LENGTH);
    mostrarMayor(numeros, NUMEROS_LENGTH);

    return 0;
}

int getNumeros(int vector[], int numerosLength)
{
    int function_success=-1;

    if(vector!=NULL && numerosLength>0){
        for(int i=0;i<numerosLength;i++){
            printf("Ingrese el numero #%d: ", i+1);
            scanf("%d", &vector[i]);
        }
        function_success=0;
    }
    return function_success;
}

int mostrarMayor(int vector[], int numerosLength)
{
    int function_success=-1;
    int mayorNumero;

    if(vector!=NULL && numerosLength>0){
        for(int i=0;i<numerosLength;i++){
            if(i==0 || vector[i]>mayorNumero){
                mayorNumero=vector[i];
            }
        }

        printf("El mayor numero ingresado es: %d y se ingreso en la/s posicion/es: ", mayorNumero);

        for(int i=0;i<numerosLength;i++){
            if(vector[i]==mayorNumero){
            printf("%d ", i+1);
            }
        }
        function_success=0;
    }
    return function_success;
}
