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
    char seguir;

    do{

        printf("Ingrese numero #%d: ", contador+1);
        scanf("%d", &numero);

        if(contador==0){
            maximo=numero;
            minimo=numero;
        }
        else{
            if(numero>maximo){
                maximo=numero;
            }
            if(numero<minimo){
                minimo=numero;
            }
        }

        printf("Desea continuar ingresando numeros? s/n ");
        fflush(stdin);
        scanf("%c", &seguir);
        contador++;

    }
    while(seguir=='s');

    printf("El valor minimo es %d y el valor maximo es %d\n", minimo, maximo);

    return 0;
}
