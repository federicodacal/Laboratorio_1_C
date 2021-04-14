/**
Realizar un programa que permita el ingreso de 10 números enteros.
Determinar:
a) el PROMEDIO de los POSITIVOS
b) la Cantidad de ceros
c) y del menor de los negativos la SUMA de los ANTECESORES.
Nota:
Utilizar la función del punto anterior y desarrollar funciones para resolver los
procesos que están resaltados.
**/

#include <stdio.h>
#include <stdlib.h>

int pedirNumero();
int verificarNumero(int);
float calcularPromedio(int, int);
int calcularSumaAntecesores(int);

int main()
{
    int num;
    int respuesta;

    int contadorPositivos;
    int acumuladorPositivos;
    float promedio;

    int menorNegativo;
    int flagMenorNegativo;
    int sumaAntecesores;

    int contadorCeros;

    contadorPositivos=0;
    acumuladorPositivos=0;
    flagMenorNegativo=0;

    for(int i=0; i<10; i++){

        num=pedirNumero();
        respuesta=verificarNumero(num);

        switch(respuesta){
            case 1:
                contadorPositivos++;
                acumuladorPositivos+=num;
                break;
            case -1:
                if(flagMenorNegativo==0 || num<menorNegativo){
                    menorNegativo=num;
                    flagMenorNegativo=1;
                }
                break;
            case 0:
                contadorCeros++;
                break;
        }
    }

    if(contadorPositivos!=0){
        promedio=calcularPromedio(contadorPositivos, acumuladorPositivos);
        printf("El promedio de los positivos es: %.2f\n", promedio);
    }
    else{
        printf("No se ingresaron numeros positivos\n");
    }

    printf("La cantidad ingresada de 0 es: %d\n", contadorCeros);

    if (flagMenorNegativo!=0){
        sumaAntecesores=calcularSumaAntecesores(menorNegativo);
        printf("La suma de los antecesores del menor es: %d", sumaAntecesores);
    }
    else{
        printf("No se ingresaron numeros negativos");
    }

    return 0;
}

int pedirNumero()
{
    int num;
    printf("Ingrese numero: ");
    scanf("%d", &num);
    return num;
}

int verificarNumero(int x)
{
    int respuesta;

    if(x==0){
        respuesta=0;
    }
    else if (x<0){
        respuesta=-1;
    }
    else{
        respuesta=1;
    }

    return respuesta;
}

float calcularPromedio(int x, int y)
{
    float promedio;
    promedio=(float) y/x;
    return promedio;
}

int calcularSumaAntecesores(int a)
{
// Es decir entrada: -7
// Operación:
//  -7+(-6)+(-5)+(-4)+(-3)+(-2)+(-1)

    int sumaAntecesores;

    for(int i=0;i>a;a++){
        sumaAntecesores+=a;
    }
    return sumaAntecesores;
}
