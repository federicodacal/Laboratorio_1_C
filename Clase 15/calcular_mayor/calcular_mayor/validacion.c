#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

static int myGets(char* auxStr, int length)
{
    fflush(stdin);
    fgets(auxStr,length,stdin);
    auxStr[strlen(auxStr)-1]='\0';

    return 0;
}


static int isNum(char* auxStr)
{
    int function_success=1;
    int i=0;

    if(auxStr[0]=='-'){
        i=1;
        }
    for(;auxStr[i]!='\0';i++){

        if(auxStr[i]>'9' || auxStr[i]<'0'){
            function_success=0;
            break;
        }
    }

    return function_success;
}

static int isChar(char* auxStr)
{
    int function_success=1;

    for(int i=0;auxStr[i]!='\0';i++){
        if((auxStr[i]!=' ') && (auxStr[i]<'a'|| auxStr[i]>'z') && (auxStr[i]<'A' || auxStr[i]>'Z') && (auxStr[i]>'9' || auxStr[i]<'0')){
            function_success=0;
            break;
        }
    }

    return function_success;
}

static int isAlphanumeric(char* auxStr)
{
    int function_success=1;

    for(int i=0;auxStr[i]!='\0';i++){
        if((auxStr[i]!=' ') && (auxStr[i]<'a'|| auxStr[i]>'z') && (auxStr[i]<'A' || auxStr[i]>'Z')){
            function_success=0;
            break;
        }
    }

    return function_success;
}



static int getInt(int* pResultado)
{
    int function_success=-1;
    char buffer[4096];

    if(myGets(buffer,sizeof(buffer))==0 && isNum(buffer)){
        *pResultado=atoi(buffer);
        function_success=0;
    }

    return function_success;
}

int getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int function_success=-1;
    int buffer;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0){
        do{
            printf("%s",mensaje);
            if(getInt(&buffer)==0 && buffer>=minimo && buffer<=maximo){
                *pResultado=buffer;
                function_success=0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>0);
    }

    return function_success;
}

