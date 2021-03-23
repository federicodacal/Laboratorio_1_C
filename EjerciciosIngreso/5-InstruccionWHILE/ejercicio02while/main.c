/**
Mostrar 10 repeticiones con números DESCENDENTES, desde el 10 al 1.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador;
    contador=10;

    while(contador>0){
        printf("%d\n",contador);
        contador--;
    }

    return 0;
}
