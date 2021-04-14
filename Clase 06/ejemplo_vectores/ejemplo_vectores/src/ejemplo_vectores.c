/*
 ============================================================================
 Name        : ejemplo_vectores.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMEROS_LENGTH 5

void mostrarVectorNumeros(int vec[], int numerosLength); // NOMENCLATURA o NOTACION VECTORIAL
//void mostrarVectorNumeros(int *vec, int numerosLength); // NOMENCLATURA O NOTACION de PUNTEROS

int main(void)
{
	setbuf(stdout, NULL);

	int numeros[NUMEROS_LENGTH] = {3,4,7,10,12};

	mostrarVectorNumeros(numeros, NUMEROS_LENGTH);

	return EXIT_SUCCESS;
}

void mostrarVectorNumeros(int vec[], int numerosLength) // NOMENCLATURA o NOTACION VECTORIAL
{
	for(int i=0; i<numerosLength;i++){
		printf("%d\n",vec[i]);
	}
}
