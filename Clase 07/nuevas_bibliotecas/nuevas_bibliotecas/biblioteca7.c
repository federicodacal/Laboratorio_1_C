
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getInt(int* pResultado);
static int esNumerica(char* cadena);
static int myGets(char* cadena, int longitud);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno=-1; // Valor de retorno (cargada con 'error' -1, en este caso significa que no obtuvo el numero)
	int buffer;	// Area de intercambio con usuario

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

		do{
			printf("%s", mensaje);
			getInt(&buffer);
			if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo){
				*pResultado=buffer;
				retorno=0; // Perfecto!
				break; // Si logre conseguir el numero
			}
			else{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos>0);

	}

	return retorno;
}

int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{
		char buffer;	// Area de intercambio con usuario
		int retorno=-1; // Valor de retorno (cargada con 'error' -1, en este caso significa que no obtuvo el numero)

		if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){

			do{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%c", &buffer);
				if(buffer>=minimo && buffer<=maximo){
					*pResultado=buffer;
					retorno=0; // Perfecto!
					break; // Si logre conseguir el numero
				}
				else{
					printf("%s", mensajeError);
					reintentos--;
				}

			}while(reintentos>0);

		}
		return retorno;
}

static int getInt(int* pResultado)
{
    int retorno=-1;
    char buffer[4096];

    if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)){

        if(esNumerica(buffer)){
            retorno=0;
            *pResultado=atoi(buffer);
        }
    }
    return retorno;
}

static int esNumerica(char* cadena)
{
    int retorno=1;
    int i=0;

    if(cadena[0]=='-'){
        i=1;
    }
    for( ;cadena[i]!='\0';i++){
        if(cadena[i]>'9' || cadena[i]<'0'){
            retorno=0;
            break;
        }
    }
    return retorno;
}

static int myGets(char* cadena, int longitud)
{
    fflush(stdin);
    fgets(cadena,longitud,stdin);
    cadena[strlen(cadena)-1]='\0';
    fflush(stdin);

    return 0;
}
