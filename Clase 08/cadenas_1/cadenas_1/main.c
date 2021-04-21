#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copiarCadena(char cadenaDestino[], char cadenaOrigen[]);

int main()
{
    int edad=20;

    char sexos[5]={'f','f','m','f','m'};
    // i=0 f
    // i=1 f
    // i=2 m
    // i=3 f
    // i=4 m

    char nombre[5]={"Juan"}; // Inicializacion explicita
    // i=0 J
    // i=1 u
    // i=2 a
    // i=3 n
    // i=4 \0

    char cadena1[20]={"Jose"};
    char cadena2[20]={"Pablo"};
    char cadena3[20]={"Luis"};

    printf("El nombre es %s y la edad es %d\n",nombre,edad);

    printf("%s, %s\n", cadena1, cadena2);
    strcpy(cadena2,cadena1);
    printf("%s, %s\n", cadena1, cadena2);

    printf("%s, %s\n", cadena2, cadena3);
    copiarCadena(cadena2,cadena3);
    printf("%s, %s\n", cadena2, cadena3);

    return 0;
}

void copiarCadena(char cadenaDestino[], char cadenaOrigen[])
{
    for(int i=0; ;i++){
        cadenaDestino[i]=cadenaOrigen[i];
        if(cadenaOrigen[i]=='\0'){
            break;
        }
    }
}
