/**
Pedir números hasta que el USUARIO QUIERA e informar la suma acumulada y el promedio.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char seguir;
    int numero;
    int contador;
    int acumulador;
    float promedio;

    contador=0;
    acumulador=0;


    do{
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        contador++;
        acumulador+=numero;

        printf("Desea ingresar otro numero? s/n ");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir=='s');

    promedio=(float) acumulador/contador;
    printf("La suma de los numeros es %d\n", acumulador);
    printf("El promedio es %.2f\n", promedio);

    return 0;
}
