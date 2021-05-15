#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_validaciones.h"

static int isNum(char* str, int limit);
static int getInt(int* pResultado);
static int isFloat(char* str);
static int getFloat(float* pResultado);

/** \brief Lee el stdin hasta que enncuentra un '\n' o hasta que haya copiado una cadena de un maximo de 'length-1' caracteres.
 *
 * \param str char* pointer al espacio de memoria donde se copia la cadena obtenida
 * \param length int define el tamano de la cadena
 * \return int 0 (Exito) si se obtuvo una cadena y -1 (Error) si no pudo
 *
 */
int myGets(char* str, int length)
{
    int function_success=-1;
    char bufferStr[4096];

    if(str!=NULL && length>0){
        fflush(stdin);
        if(fgets(bufferStr,sizeof(bufferStr),stdin)!=NULL){
            if(bufferStr[strnlen(bufferStr,sizeof(bufferStr))-1]=='\n'){
                bufferStr[strnlen(bufferStr,sizeof(bufferStr))-1]='\0';
            }
            if(strnlen(bufferStr,sizeof(bufferStr))<=length){
                strncpy(str,bufferStr,length);
                function_success=0;
            }
        }
    }

    return function_success;
}

/** \brief Obtiene un numero entero
 *
 * \param pResultado int* pointer a espacio de memoria donde se va a dejar el resultado de la funcion
 * \return int 0 (Exito) si se obtiene un numero entero y -1 (Error) si no pudo
 *
 */
static int getInt(int* pResultado)
{
    int function_success=-1;
    char bufferStr[50];

    if(pResultado!=NULL &&
       myGets(bufferStr,sizeof(bufferStr))==0 &&
       isNum(bufferStr,sizeof(bufferStr))){
            *pResultado=atoi(bufferStr);
            function_success=0;
    }


    return function_success;
}

/** \brief Verifica si la cadena ingresada es numerica
 *
 * \param str char* cadena de caracteres a ser analizada
 * \param limit int limite
 * \return int 1 (True) si la cadena es numerica, 0 (False) si no lo es o -1 (Error)
 *
 */
static int isNum(char* str, int limit)
{
    int function_success=-1; // ERROR

    if(str!=NULL && limit>0){
        function_success=1; // Verdadero
        for(int i=0;i<limit && str[i]!='\0';i++){
            if(i==0 && (str[i]=='+' || str[i]=='-')){
                continue;
            }
            if(str[i]>'9' || str[i]<'0'){
                function_success=0; // Falso
                break;
            }
            // Continue
        }
        // Break
    }

    return function_success;
}

int getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int function_success=-1;
    int bufferInt;

    do{
        printf("%s",mensaje);

        if(getInt(&bufferInt)==0 &&
           bufferInt>=minimo &&
           bufferInt<=maximo){
            *pResultado=bufferInt;
            function_success=0;
            break;
        }

        printf("%s",mensajeError);

        reintentos--;
    }while(reintentos>=0);

    return function_success;
}
