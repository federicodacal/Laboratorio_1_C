/*
 ============================================================================
 Name        : clase_bibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);

	int edad;
	char letra;
	int respuesta;

	respuesta=utn_getNumero(&edad, "Ingrese edad: \n", "Error. Fuera de rango. \n", 0,125,2);
	if(respuesta==0){
		printf("La edad es: %d\n",edad);
	}
	else{
		printf("Error\n");
	}

	respuesta=utn_getChar(&letra, "Ingrese letra: \n", "Error. Fuera de rango(A-J). \n", 'A','J',3);
	if(respuesta==0){
		printf("La letra es: %c\n",letra);
	}
	else{
		printf("Error\n");
	}



	return EXIT_SUCCESS;
}
