/*
 ============================================================================
 Name        : ejercicio_array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 hola
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define EDAD_SIZE 5

void imprimirArray(int arrayEdades[], int arrayLength);
int getPromedioEdades(float *pPromedio, int arrayEdades[], int arrayLength);

int main(void)
{
	setbuf(stdout, NULL);

	int edad;
	int edades[EDAD_SIZE];
	float promedioEdades;

	for(int i=0;i<EDAD_SIZE;i++){
		if(utn_getNumero(&edad, "Ingrese Edad: ", "Error.", 1, 120, 3)==0){
			edades[i]=edad;
		}
		else{
			printf("No valido");
		}
	}

	/* LISTAR EDADES:
	for(int i=0;i<EDAD_SIZE;i++){
		printf("%d\n", edades[i]);
	}
	*/

	imprimirArray(edades, EDAD_SIZE); // Pasa la direccion de Memoria del comienzo del Array

	if(getPromedioEdades(&promedioEdades, edades, EDAD_SIZE)==0){
		printf("El promedio de edad es: %.2f\n", promedioEdades);
	}

	return EXIT_SUCCESS;
}

// El nombre del Array es la direccion de memoria donde comienza el array

// Por referencia
void imprimirArray(int arrayEdades[], int arrayLength)	// Sintaxis con corchetes porque el array refiere a una direccion em memoria
{
	for(int i=0;i<EDAD_SIZE;i++){
		printf("%d\n", arrayEdades[i]);
	}
}

int getPromedioEdades(float *pPromedio,int arrayEdades[], int arrayLength)
{
	int acumuladorEdad;
	int retorno=-1;

	if(arrayLength>0 && pPromedio!=NULL && arrayEdades!=NULL){

	for (int i=0;i<arrayLength;i++){

		acumuladorEdad+=arrayEdades[i];
		*pPromedio=(float) acumuladorEdad/arrayLength;

		}
		retorno=0;
	}
	return retorno;
}
