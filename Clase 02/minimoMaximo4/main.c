/**
Pedir números y dar como resultado maximo y minimo
**/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int maximo;
    int minimo;
    int contador=0;

    do{

        printf("Ingrese numero #%d (el numero 888 finaliza el programa): ", contador+1);
        scanf("%d", &numero);

        if(contador==0){
            maximo=numero;
            minimo=numero;
        }
        else{
            if(numero!=888){
                if(numero>maximo){
                    maximo=numero;
                }
                if(numero<minimo){
                    minimo=numero;
                }
            }
        }
        contador++;
    }
    while(numero!=888);

    printf("El valor minimo es %d y el valor maximo es %d\n", minimo, maximo);

    return 0;
}
