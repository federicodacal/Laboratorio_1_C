/**
Pedir 5 números y dar como resultado maximo y minimo
**/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int maximo;
    int minimo;
    int flag=1;

    for(int i=0;i<5;i++){

        printf("Ingrese numero #%d: ", i+1);
        scanf("%d", &numero);

        if(flag==1){
            maximo=numero;
            minimo=numero;
            flag=0;
        }
        else{
            if(numero>maximo){
                maximo=numero;
            }
            if(numero<minimo){
                minimo=numero;
            }
        }
    }

    printf("El valor minimo es %d y el valor maximo es %d\n", minimo, maximo);
    return 0;
}
