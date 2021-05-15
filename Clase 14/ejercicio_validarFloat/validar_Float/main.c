#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int validarFloat(char* str);

int main()
{
    char numero[6];

    numero[0]='3';
    numero[1]='.';
    numero[2]='1';
    numero[3]='4';
    numero[4]='\0';

    printf("%s\n",numero);

    if(validarFloat(numero)==1){
        printf("Es un nro float %f\n",atof(numero));
    }
    else{
        printf("No es un nro float\n");
    }
}

int validarFloat(char* str)
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
