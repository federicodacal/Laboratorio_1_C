// Lograr tomar un dato y luego mostrarlo

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[15];

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Su nombre es: %s", nombre);
    return 0;
}
