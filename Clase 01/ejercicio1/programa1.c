// Primer programa en C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1 = 25;
    int numero2 = 20;
    int numero3 = 10;
    float x = 3.14;
    char nombre[10] = "Juan";
    char sexo = 'm';
    int edad = 23;

    int entero;
    float flotante;
    char caracter;
    char cadena[15];

    printf("Hello World!\n\n");
    printf("La variable numero1 vale: %d\nLa variable numero2 vale: %d\n", numero1, numero2);
    printf("La variable x vale: %.2f\n", x);
    printf("Ud. se llama %s y tiene %d anios\n\n", nombre, edad);

    printf("Ingrese un entero: ");
    scanf("%d", &entero);
    printf("Ud. ingreso el numero %d\n\n", entero);

    printf("Ingrese su altura: ");
    scanf("%f", &flotante);
    printf("Ud. mide %.2f mts\n\n", flotante);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &caracter);
    printf("El sexo seleccionado es: %c\n\n", caracter);

    printf("Ingrese nombre: ");
    scanf("%s", cadena);
    printf("Su nombre es: %s\n", cadena);

    return 0;
}
