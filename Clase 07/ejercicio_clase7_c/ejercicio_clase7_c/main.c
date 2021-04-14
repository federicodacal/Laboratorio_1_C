#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 5

/** \brief Pide al usuario numeros y deja la suma de los mismos en la ultima posicion
 *
 * \param vector[] int Array a cargar con numeros ingresados
 * \param numerosLength int Tamañano del array
 * \return void
 *
 */
void cargarVectorAcumulador(int vector[], int numerosLength);

int main()
{
    int numeros[NUMEROS_LENGTH];

    cargarVectorAcumulador(numeros, NUMEROS_LENGTH);
    return 0;
}

void cargarVectorAcumulador(int vector[], int numerosLength)
{
    vector[numerosLength-1]=0;
    for(int i=0;i<numerosLength-1;i++){
        printf("Ingrese un numero: ");
        scanf("%d", &vector[i]);
        vector[numerosLength-1]+=vector[i];
    }
    printf("%d", vector[numerosLength-1]);
}
