/**
DACAL FEDERICO
DIVISION "A"
IDE: CodeBlocks

Ejercicio 1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int contadorPositivos;
    int contadorNegativos;
    int acumuladorPositivos;
    int acumuladorNegativos;
    float promedioPositivos;
    float promedioNegativos;
    char seguir;

    contadorPositivos=0;
    contadorNegativos=0;
    acumuladorPositivos=0;
    acumuladorNegativos=0;

    do{
        printf("Ingrese numero: ");
        scanf("%d", &numeroIngresado);

        if(numeroIngresado!=0){
            if(numeroIngresado<0){
                contadorNegativos++;
                acumuladorNegativos+=numeroIngresado;
            }
            else{
                contadorPositivos++;
                acumuladorPositivos+=numeroIngresado;
            }
        }

        printf("¿Desea continuar ingresando numeros? (s/n): ");
        fflush(stdin);
        scanf("%c", &seguir);


    }while(seguir=='s');

    promedioNegativos=(float) acumuladorNegativos/contadorNegativos;
    promedioPositivos=(float) acumuladorPositivos/contadorPositivos;

    if(contadorNegativos==0){
        printf("No se ingresaron numeros negativos\n");
    }
    else{
        printf("Promedio Negativos: %.2f \n", promedioNegativos);
    }

    if(contadorPositivos==0){
        printf("No se ingresaron numeros positivos\n");
    }
    else{
        printf("Promedio Positivos: %.2f \n", promedioPositivos);
    }

    return 0;
}
