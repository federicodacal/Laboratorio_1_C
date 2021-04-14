// Declarar un array de sexos (char) y realizar cargar de datos y mostrar

#include <stdio.h>
#include <stdlib.h>
#define NUMEROS_LENGTH 4

int getSexos(char vector[], int sexosLength);
int mostrarSexos(char vector[], int sexosLength);

int main(void) {

	//setbuf(stdout, NULL);
	char sexos[NUMEROS_LENGTH];

    getSexos(sexos, NUMEROS_LENGTH);
	mostrarSexos(sexos, NUMEROS_LENGTH);

	return EXIT_SUCCESS;
}

int getSexos(char vector[], int sexosLength)
{
    int function_success=-1;
	if(vector!=NULL && sexosLength>0){
		for(int i=0;i<sexosLength;i++){
			printf("Ingrese sexo: m/f/o: ");
			fflush(stdin);
			scanf("%c", &vector[i]);
			while(vector[i]!='m' && vector[i]!='f' && vector[i]!='o'){
                printf("Error. Ingrese sexo: m/f/o: ");
                fflush(stdin);
                scanf("%c", &vector[i]);
			}
		}
		function_success=1;
	}
	return function_success;
}

int mostrarSexos(char vector[], int sexosLength)
{
	int function_success=-1;
	if(vector!=NULL && sexosLength>0){
        printf("\nIngreso: ");
		for(int i=0;i<sexosLength;i++){
			printf("%c ", vector[i]);
		}
		function_success=0;
	}
	return function_success;
}
