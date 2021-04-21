#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    int nombreLength;

    char cadena1[20]={"Hola"};
    char cadena2[20]={"Mundo"};

    printf("Ingrese nombre: ");
    fflush(stdin);
//  scanf("%s", nombre);
    gets(nombre);

    puts(nombre);
    printf("%s\n",nombre);
    printf("Ud. se llama %s\n",nombre);

    nombreLength=strlen(nombre);
    printf("%d\n", nombreLength);

    strupr(nombre);
    puts(nombre);
    strlwr(nombre);
    puts(nombre);

    strcat(cad2,cad1);


    return 0;
}
