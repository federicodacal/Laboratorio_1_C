/**
Pedir números hasta que el usuario quiera, sumar los que son positivos y multiplicar los negativos.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int sumaPositivos;
    int productoNegativos;
    int flag;
    char seguir;

    flag=0;
    sumaPositivos=0;
    productoNegativos=1;

    do{
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        printf("Continuar ingresado numeros? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(numero<0){
            productoNegativos*=numero;
            flag=1;
        }
        else{
            sumaPositivos+=numero;
        }

    }while(seguir=='s');

    if(flag==0){
    productoNegativos=0;
    }
    printf("La suma de los positivos es %d\n", sumaPositivos);
    printf("El producto de los negativos es %d\n", productoNegativos);
    return 0;
}
