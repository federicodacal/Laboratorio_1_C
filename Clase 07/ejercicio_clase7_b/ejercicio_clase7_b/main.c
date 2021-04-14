/**
Funcion mostrarNumeros(int vector[], int TAM, int inicio, int fin)
Debe mostrar los numeros del indice del 1 al 3 y del 4 al 2.
**/

#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 5

/** \brief funcion que muestra los numeros de un vector desde el indice 1 a 3 y 4 al 2.
 *
 * \param vector[] int array que se va a mostrar
 * \param NUMEROS_LENGHT int length del array
 * \param inicio int indice del primer elemento a mostrar
 * \param fin int indice del ultimo elemento a mostrar
 * \return int function_success=-1 fallo la ejecución, function_success=0 si fue exitoso.
 *
 */
int mostrarNumeros(int vector[], int numerosLength, int inicio, int fin);

int main()
{
    int numeros[NUMEROS_LENGTH]={2,4,6,8, 10};

    mostrarNumeros(numeros, NUMEROS_LENGTH, 1, 3);
    mostrarNumeros(numeros, NUMEROS_LENGTH, 4, 2);
    return 0;
}

int mostrarNumeros(int vector[], int numerosLength, int inicio, int fin)
{
    int function_success=-1;

    if(vector!=NULL && numerosLength>0 && inicio>=0 && inicio<numerosLength && fin>=0 && fin<numerosLength){
        if(inicio<fin){

            for(int i=inicio;i<=fin;i++){
                printf("%d ", vector[i]);
            }
        }
        else{

             for(int i=inicio;i>=fin;i--){
                printf("%d ", vector[i]);
            }
        }
        printf("\n");
        function_success=0;
    }
    return function_success=0;
}
