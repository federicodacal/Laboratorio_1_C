#include <stdio.h>
#include <stdlib.h>
#define EMPLEADOS 9

int printArrayInt(int* pArray, int edadesLength);
int ordenarArrayInt(int* pArray, int edadesLength);

int main()
{
    int edades[EMPLEADOS]={54,26,93,17,77,31,44,55,27};
    int respuesta;

    printf("Array Inicial: \n");
    printArrayInt(edades, EMPLEADOS);

    printf("\nArray Ordenado: \n");
    respuesta=ordenarArrayInt(edades, EMPLEADOS);
    if(respuesta>0){
        printf("Iteraciones: %d \n", respuesta);
    }

    printArrayInt(edades, EMPLEADOS);

    respuesta=ordenarArrayInt(edades, EMPLEADOS);
    if(respuesta>0){
        printf("\nIteraciones: %d \n(al estar ordenado muestra la cantidad de iteraciones que le lleva hacer todas las pasadas\n", respuesta);
    }


    return 0;
}

/**
 * \brief Imprime los elementos de un vector
 * \param pArray int* Puntero al array a ser ordenado
 * \param edadesLength int Tamaño del array
 * \return int 0 si Ok, -1 para Error
 */
int printArrayInt(int* pArray, int edadesLength)
{
    int function_success=-1;
    if(pArray!=NULL && edadesLength>=0){
        for(int i=0;i<edadesLength;i++){
            printf("[Debug] Indice: %d, Valor: %d\n", i,pArray[i]);
        }
    }
    return function_success;

}

/**
 * \brief Ordena los elementos de un vector ASC
 * \param pArray int* Puntero al array a ser ordenado
 * \param edadesLength int Tamaño del array
 * \return int Cantidad de iteraciones necesarias para ordenar el vector; 0 si Ok, -1 para Error
 */
int ordenarArrayInt(int* pArray, int edadesLength)
{
    int flagSwap;
    int contador;
    int aux;

    if(pArray!=NULL && edadesLength>=0){
        do{
            flagSwap=0;
            for(int i=0;i<edadesLength-1;i++){
                if(pArray[i]>pArray[i+1]){
                    flagSwap=1;
                    aux=pArray[i];
                    pArray[i]=pArray[i+1];
                    pArray[i+1]=aux;
                }
                contador++;
            }

        }while(flagSwap);
    }
    return contador;
}
