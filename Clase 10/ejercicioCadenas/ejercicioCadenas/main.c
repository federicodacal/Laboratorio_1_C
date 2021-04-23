#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

int main()
{
    // apellido, nombre
    // Baus, Christian German
    // No modificar variables apellido y nombre, no crear mas variables

    char nombre[20];
    char apellido[20];
    char nombreCompleto[41]; // Para guardar el nombre mas largo (19) y apellido mas largo (19) y ademas el ", " (la coma y espacio) y tambien el '\0' caracter finalizador. 19+19+2+1=41
    char auxCad[100];

    printf("Ingrese nombre: \n");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese apellido: \n");
    fflush(stdin);
    gets(apellido);

    strcpy(nombreCompleto,apellido);
    strcat(nombreCompleto,", ");
    strcat(nombreCompleto,nombre);

    strlwr(nombreCompleto);
    nombreCompleto[0]=toupper(nombreCompleto[0]);

    for(int i=0; nombreCompleto[i]!='\0';i++){

        if(nombreCompleto[i]==' '){
            nombreCompleto[i+1]=toupper(nombreCompleto[i+1]);
        }
    }

    puts(nombreCompleto);

    return 0;
}
