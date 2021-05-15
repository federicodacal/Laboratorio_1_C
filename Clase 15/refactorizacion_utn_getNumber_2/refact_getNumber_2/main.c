#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_validaciones.h"

int main()
{
    int num;

    if(getNumber(&num,"\nNumero: ","Error\n",-10,10,2)==0){
        printf("%d",num);
    }
    return 0;
}

