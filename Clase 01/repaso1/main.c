/**
Ingresar 10 numeros enteros, distintos de cero. Mostrar:
a) Cantidad de pares e impares
b) El menor numero ingresado
c) Suma de los positivos
d) Producto de los negativos
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int menorNumero;
    int productoNegativos;
    int contadorPares;
    int contadorImpares;
    int sumaPositivos;
    int flagPrimerNegativo;

    contadorPares=0;
    contadorImpares=0;
    productoNegativos=1;
    sumaPositivos=0;
    flagPrimerNegativo=0;


    for(int i=0;i<10;i++){

        printf("Ingreso #%d\nIngrese un numero: ", i+1);
        scanf("%d", &numeroIngresado);
        while(numeroIngresado==0){
            printf("Error. Ingrese un numero distinto de 0: ");
            scanf("%d", &numeroIngresado);
        }

        // Producto Negativos
        if(numeroIngresado<0){
            productoNegativos*=numeroIngresado;
            flagPrimerNegativo=1;
            }

        // Suma Positivos
        else{
            sumaPositivos+=numeroIngresado;
        }

        // Contador Pares, Contador Impares
        if(numeroIngresado%2==0){
            contadorPares++;
        }
        else{
            contadorImpares++;
        }

        // Menor Numero
        if(i==0 || numeroIngresado<menorNumero){
            menorNumero=numeroIngresado;
        }
    }

    printf("Numeros Pares: %d\nNumeros Impares: %d\nMenor Numero: %d\nSuma de los positivos: %d\n", contadorPares, contadorImpares, menorNumero, sumaPositivos);

        if(flagPrimerNegativo!=0){
            printf("Producto de los negativos: %d", productoNegativos);
        }
        else{
            printf("No se ingresaron numeros negativos");
        }

    return 0;
}
