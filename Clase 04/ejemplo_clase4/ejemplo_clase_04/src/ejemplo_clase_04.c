/*
 ============================================================================
 Name        : ejemplo_clase_04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Objetivo:
 A- Desarollar una biblioteca que posea funciones para pedirle al usuario el ingreso de datos
 	 - getInt()
 	 - getFloat()
 	 - getChar()

 B- Diseñar un programa para jugar a adviniar un numero entre 0 y 100. El juego tiene que dar pistas si
 el numero introducido por el jugador esta por encima o por debajo. El juego termina cuando se adivina
 el numoero o se decide terminar de jugar ingresando un numero negativo. Permiter tantas veces como lo
 desse el jugador y al salir mostrar su mejor puntiacion. Utilizar la biblioteca del punto 1.

 Aspectos a destacar:
 	 - Se practica la declaracion de funciones y se muestra como crear una biblioteca propia.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_clase4.h"

int main(void) {

	setbuf(stdout, NULL);
	int numeroOculto;
	int numeroIngresado;
	char teclaIngresada;
	int intentos=0;
	int jugar;

	teclaIngresada='s';
	while(teclaIngresada=='s'){

		numeroOculto=getRandmonNumber(1,100,1);

		jugar=1;
		while(jugar==1){

			intentos++;

			numeroIngresado=getInt("Ingrese un numero (0 a 99)\n");
			if(numeroIngresado<0){
				jugar=0;
			}
			else if(numeroIngresado==numeroOculto){
				printf("Felicitaciones!!!\n GANASTE!\n Numero de intentos: %d\n", intentos);
				jugar=0;
			}
			else if(numeroIngresado>numeroOculto){
				printf("Numero ingresado es mayor\n");
			}
			else if(numeroIngresado<numeroOculto){
				printf("Numero ingresado es menor\n");
			}

		}

		teclaIngresada=getChar("Desea jugar nuevamente? (s/n)\n");
	}
	return EXIT_SUCCESS;
}
