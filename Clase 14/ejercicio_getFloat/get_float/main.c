#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int getFloat(float* pResultado);
int isFloat(char* str);

int main()
{
    float precio;

    printf("Ingrese un precio: ");

    if(getFloat(&precio)==1){
        printf("El precio es valido $%.2f\n",precio);
    }
    else{
        printf("Dato incorrecto\n");
    }

    return 0;
}

int getFloat(float* pResultado)
{
    char buffer[128];
    int retorno=0;

    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(pResultado!=NULL){
        if(isFloat(buffer)==1){
            *pResultado=atof(buffer);
            retorno=1;
        }
    }

    return retorno;
}

int isFloat(char* str)
{
    int retorno=1;
    int i=0;
    int flag=0;

    printf("%s\n",str);

    if(str[0]=='-'){
        i=1;
    }
    for(;str[i]!='\0';i++){
        if(str[i]<'0' || str[i]>'9'){
            if(str[i]=='.'){
                flag++;
                if(flag>1){
                    retorno=0;
                    break;
                }
            }
            else{
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
