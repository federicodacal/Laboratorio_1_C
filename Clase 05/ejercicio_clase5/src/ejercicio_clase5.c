/*
 ============================================================================
 Name        : ejercicio_clase5.c
 Author      : Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Solicitar al usuario 5 números, almacenar estos en un array de enteros, permitir listarlos por pantalla
 indicando el máximo, el mínimo y el promedio.
 Permitir Modificar el valor de cualquiera de los números cargados indicando el índice del mismo y su nuevo valor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_clase4.h"

#define CANTIDAD 5

int main(void)
{
	setbuf(stdout, NULL);

	int arrayNumeros[CANTIDAD];
	int numeroIngresado;
	int indiceArray;
	int valorIngresado;
	int opcionMenu=0;

	for(indiceArray=0;indiceArray<CANTIDAD;indiceArray++){
		numeroIngresado=getInt("Ingrese el valor: \n");
		arrayNumeros[indiceArray]=numeroIngresado;
	}

	while(opcionMenu!=3){

		opcionMenu=getInt("\n1. Mostrar\n2. Modificar\n3.Salir\n");
		switch(opcionMenu){
			case 1:
				printf("\nINDICE - VALOR\n");
				for(indiceArray=0;indiceArray<CANTIDAD;indiceArray++){
					printf("\n%d - %d \n", indiceArray, arrayNumeros[indiceArray]);
				}
				break;
			case 2:
				indiceArray=getInt("\nIngrese el indice a modificar\n");
				if(indiceArray>=0 && indiceArray<CANTIDAD){
					valorIngresado=getInt("Ingrese el valor: \n");
					arrayNumeros[indiceArray]=valorIngresado;
				}
				else{
					printf("\nEl indice ingresado esta fuera de rango!");
				}
				break;
		}
	}

	return EXIT_SUCCESS;
}
