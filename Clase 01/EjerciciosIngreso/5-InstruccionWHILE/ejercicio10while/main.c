/**
Pedir números hasta que el usuario quiera, mostrar:
1-Suma de los negativos.
2-Suma de los positivos.
3-Cantidad de positivos.
4-Cantidad de negativos.
5-Cantidad de ceros.
6-Cantidad de números pares.
7-Promedio de positivos.
8-Promedios de negativos.
9-Diferencia entre positivos y negativos (positvos-negativos).
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    char seguir;
    int sumaNegativos;
    int sumaPositivos;
    int contadorNegativos;
    int contadorPositivos;
    int contadorCeros;
    int contadorPares;
    float promedioPositivos;
    float promedioNegativos;
    int diferenciaPositivosNegativos;

    sumaNegativos=0;
    sumaPositivos=0;
    contadorCeros=0;
    contadorNegativos=0;
    contadorPositivos=0;
    contadorPares=0;

    do{
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(numero==0){
            contadorCeros++;
        }
        else{
            if(numero<0){
                sumaNegativos+=numero;
                contadorNegativos++;
            }
            else{
                sumaPositivos+=numero;
                contadorPositivos++;
            }
        }

        if(numero!=0 && numero%2==0){
            contadorPares++;
        }

        printf("Continuar ingresando? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);


    }while(seguir=='s');

    promedioNegativos=(float) sumaNegativos/contadorNegativos;
    promedioPositivos=(float) sumaPositivos/contadorPositivos;
    diferenciaPositivosNegativos= sumaPositivos-sumaNegativos;

    printf("1-Suma de los negativos: %d\n",sumaNegativos);
    printf("2-Suma de los positivos: %d\n",sumaPositivos);
    printf("3-Cantidad de positivos: %d\n",contadorPositivos);
    printf("4-Cantidad de negativos: %d\n",contadorNegativos);
    printf("5-Cantidad de ceros: %d\n",contadorCeros);
    printf("6-Cantidad de nros. pares: %d\n",contadorPares);
    printf("7-Promedio de los positivos: %.3f\n",promedioPositivos);
    printf("8-Promedio de los negativos: %.3f\n",promedioNegativos);
    printf("9-Diferencia positivos y negativos: %d\n",diferenciaPositivosNegativos);


    return 0;
}
