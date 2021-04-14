#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 5
#define ASC 1
#define DESC 0

void ordenarCriterio(int vector[], int numerosLength, int criterio);
void mostrarNumeros(int vector[], int numerosLength);


int main()
{
    int numeros[NUMEROS_LENGTH]={2,9,7,5,1};

    mostrarNumeros(numeros, NUMEROS_LENGTH);
    ordenarCriterio(numeros,NUMEROS_LENGTH, DESC);
    mostrarNumeros(numeros, NUMEROS_LENGTH);
    ordenarCriterio(numeros,NUMEROS_LENGTH, ASC);
    mostrarNumeros(numeros, NUMEROS_LENGTH);
    return 0;
}

void ordenarCriterio(int vector[], int numerosLength, int criterio)
{
    int aux;

    for(int i=0;i<numerosLength-1;i++){

        for(int j=i+1;j<numerosLength;j++){
            if(criterio && vector[i]>vector[j]){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
            else if(vector[i]<vector[j] && !criterio){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}

void mostrarNumeros(int vector[], int numerosLength)
{
    for(int i=0;i<numerosLength;i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}
