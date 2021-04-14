#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int retorno;

    printf("x: %d\n", x); // Trae valor 'basura'

    printf("Ingrese un numero: ");
    retorno=scanf("%d", &x);

    printf("Retorno: %d\n", retorno);
    printf("x: %d\n", x);

    int dia;
    int mes;
    int anio;
    int respuesta;
    printf("Ingrese fecha, dd/mm/aaaa: ");
    respuesta=scanf("%d/%d/%d", &dia, &mes, &anio);

    printf("Respuesta: %d\n", respuesta); // Guarda la cantidad de datos ingresados y que pudo cargar de manera correcta. Ej: si el user ingresa '13/05/hola' respuesta muestra 2. Al primer dato no válido no continua cargando más datos. Ej: si el user ingresa 'xx/12/1995' respuestra muestra 0.
    printf("La fecha ingresada es %d/%d/%d\n", dia, mes, anio);

    return 0;
}
