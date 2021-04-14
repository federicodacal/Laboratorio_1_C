/*
 * utn_clase4.c
 *
 *  Created on: Apr 7, 2021
 *      Author: Federico
 */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

/**
 * @brief Solicita un numero al usuario y devuelve el resultado
 * @param mensaje Es el mensaje a ser mostrado
 * @return aux El numero ingresado por el usuario
 */
float getFloat(char mensaje[])
{
	float aux;

	printf("%s", mensaje);
	scanf("%f", &aux);

	return aux;
}


/**
 * @brief Solicita un numero al usuario y devuelve el resultado
 * @param mensaje Es el mensaje a ser mostrado
 * @return aux El numero ingresado por el usuario
 */
int getInt(char mensaje[])
{
	int aux;

	printf("%s", mensaje);
	scanf("%d", &aux);

	return aux;
}

/**
 * @brief Solicita un caracter al usuario y devuelve el resultado
 * @param mensaje Es el mensaje a ser mostrado
 * @return aux El caracter ingresado por el usuario
 */
char getChar(char mensaje[])
{
	char aux;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &aux);

	return aux;
}

/**
 * @brief Genera un número aleatorio
 * @param desde Numero random minimo
 * @param hasta Numero random maximo
 * @param iniciar Indica si se trata del primer numero solicitado (1 indica que si)
 * @return El numero random generado
 */
char getRandmonNumber(int desde, int hasta, int iniciar)
{
	if(iniciar)
		srand(time(NULL));
	return desde + (rand()%(hasta+1-desde));
}
