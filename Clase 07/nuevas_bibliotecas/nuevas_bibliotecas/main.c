#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca7.h"

int main()
{
    int auxInt;

    if(utn_getNumero(&auxInt, "Numero?","Error!",-10,10,2)==0){
        printf("\nEl numero es: %d\n",auxInt);
        }
    return 0;
}

