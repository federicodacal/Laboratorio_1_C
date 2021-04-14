#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    if(myIsDigit('a')){
        printf("Es un digito\n");
    }
    else{
        printf("No es un digito\n");
    }

    if(myIsDigit('7')){
        printf("Es un digito\n");
    }
    else{
        printf("No es un digito\n");
    }
    return 0;
}
