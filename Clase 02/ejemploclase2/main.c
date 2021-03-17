// Pedir dos numeros enteros y calcular el promedio

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // casting -> conversion de un tipo numerico a otro tipo numerico
    // parsing -> convertir algo que NO es de tipo numerico a un tipo numerico (en js parseInt, parseFloat)

    int num1;
    int num2;
    int suma;
    float promedio;

    printf("Ingrese el primer numero: \n");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &num2);

    suma=num1+num2;
    promedio=(float) suma/2;

    //fflush(stdin); limpiar buffer en Windows -> Usar en la linea anterior de pedir caracter o cadena de caracteres
    //__fpurge(stdin); limpiar buffer en Linux

    printf("El promedio es: %.2f", promedio);
    return 0;
}
