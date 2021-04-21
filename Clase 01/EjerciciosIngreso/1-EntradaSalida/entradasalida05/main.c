// Debemos lograr tomar nombre y edad mostrarlos concatenados
// ej.: "Usted se llama José y tiene 66 años"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    char nombre[20];

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    printf("Ud. se llama %s y su edad es %d", nombre, edad);
    return 0;
}
