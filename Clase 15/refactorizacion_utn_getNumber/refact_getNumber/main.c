#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validacion.h"

int main()
{
    int auxInt;

    while(1){
        if(getNumber(&auxInt,"Ingrese numero: \n","Error\n",-6,2,10)==0){
            printf("El nro. es %d\n",auxInt);
        }
    }
    return 0;
}
