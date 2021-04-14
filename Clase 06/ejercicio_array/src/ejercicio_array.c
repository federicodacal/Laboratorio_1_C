/*
 ============================================================================
 Name        : ejercicio_array.c
 Author      : Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/* DECLARAR UN ARRAY DE CINCO ENTEROS, CARGARLO SECUENCIALMENTE CON NUMEROS INRGRESADOS POR EL USUARIO Y
	MOSTRAR SOLO LOS NUMEROS PARES
 */


#include <stdio.h>
#include <stdlib.h>

#define NUMEROS_LENGTH 5

void mostrarPares(int vector[], int numerosLength);
void cargarVector(int vector[], int numerosLength);

int main(void) {

	setbuf(stdout, NULL);

	int numeros[NUMEROS_LENGTH];

	cargarVector(numeros, NUMEROS_LENGTH);
	mostrarPares(numeros, NUMEROS_LENGTH);

	return EXIT_SUCCESS;
}

// NOTACION VECTORIAL
void cargarVector(int vector[], int numerosLength)
{

	for(int i=0; i<numerosLength;i++){
		printf("Ingrese el numero #%d\n",i+1);
		scanf("%d", &vector[i]);
	}
}

// NOTACION DE PUNTEROS
/*
void cargarVector(int* vector, int numerosLenght)
{
	for(int i=0;i<NUMEROS_LENGTH;i++){
		printf("Ingrese el numero #%d\n",i+1);
		scanf("%d", vector+i);
	}
}
*/

// NOTACION VECTORIAL
void mostrarPares(int vector[], int numerosLength)
{
	for(int i=0; i<numerosLength;i++){
		if(vector[i]%2==0){
			printf("%d\n", vector[i]);
		}
	}
}

// NOTACION DE PUNTEROS
/*
void mostrarPares(int* vector, int numerosLength)
{
	for(int i=0; i<numerosLength;i++){
		if(*(vector+i)%2==0){
			printf("%d\n", *(vector+i));
		}
	}
}
*/
