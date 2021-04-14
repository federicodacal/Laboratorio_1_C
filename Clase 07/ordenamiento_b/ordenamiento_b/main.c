#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 5

void mostrarNumeros(int vector[], int numerosLength);
void ordenarAsc(int vector[], int numerosLength);
void ordenarDesc(int vector[], int numerosLength);

int main()
{
    int numeros[NUMEROS_LENGTH]={4,5,1,9,7};

    // Inicial
    mostrarNumeros(numeros, NUMEROS_LENGTH);

    // Ordenar Asc
    ordenarAsc(numeros, NUMEROS_LENGTH);
    mostrarNumeros(numeros, NUMEROS_LENGTH);

    // Ordenar Desc
    ordenarDesc(numeros, NUMEROS_LENGTH);
    mostrarNumeros(numeros, NUMEROS_LENGTH);
    return 0;
}

void mostrarNumeros(int vector[], int numerosLength)
{
    for(int i=0;i<numerosLength;i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void ordenarAsc(int vector[], int numerosLength)
{
    int aux;
    for(int i=0;i<numerosLength-1;i++){

        for(int j=i+1;j<numerosLength;j++){
            if(vector[i]>vector[j]){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}

void ordenarDesc(int vector[], int numerosLength)
{
    int aux;
    for(int i=0;i<numerosLength-1;i++){

        for(int j=i+1;j<numerosLength;j++){
            if(vector[i]<vector[j]){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }
}
