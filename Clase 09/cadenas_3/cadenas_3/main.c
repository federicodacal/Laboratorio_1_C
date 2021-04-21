#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char auxCad[100];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=20){
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);
    puts(nombre);


    printf("Ingrese nombre: ");
    fflush(stdin);
    fgets(nombre,19,stdin); // Deja dos lineas de espacio

    puts(nombre);

    return 0;
}
