/**
Pedir números hasta que el usuario quiera, mostrar el número máximo y el número mínimo ingresado.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char seguir;
    int numero;
    int minimo;
    int maximo;
    int flag;

    flag=0;

    do{
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(flag==0){
            maximo=numero;
            minimo=numero;
            flag=1;
        }
        else{
            if(numero>maximo){
                maximo=numero;
            }
            if(numero<minimo){
                minimo=numero;
            }
        }

        printf("Continuar ingresando? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir=='s');

    printf("El maximo es %d \n", maximo);
    printf("El minimo es %d \n", minimo);
    return 0;
}
