#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void pasarCadenaMayus(char cadena[]);
void pasarCadenaMinus(char cadena[]);

int main()
{
    char nombre[20];
    char nombre2[20]={"Christian"};
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

    puts(nombre2);
    pasarCadenaMayus(nombre2);
    puts(nombre2);
    pasarCadenaMinus(nombre2);
    puts(nombre2);

    strcat(cadena1,cadena2);
    puts(cadena1);

    return 0;
}

void pasarCadenaMayus(char cadena[])
{
    for(int i=0; cadena[i]!='\0';i++){
        if(cadena[i]>='a'&&cadena[i]<='z'){ // Me fijo si es un caracter convertible a mayus (entre 'a' y 'z' minus)
            cadena[i]-=32;  // Por codigo ASCII
        }
    }
}

void pasarCadenaMinus(char cadena[])
{
    for(int i=0; cadena[i]!='\0';i++){
        if(cadena[i]>='A'&&cadena[i]<='Z'){ // Me fijo si es un caracter convertible a minus (entre 'A' y 'Z' mayus)
            cadena[i]+=32;  // Por codigo ASCII
        }
    }
}
