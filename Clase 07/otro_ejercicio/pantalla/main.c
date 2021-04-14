#include <stdio.h>
#include <stdlib.h>
#define LETRAS_LENGTH 6


int buscarCaracter(char vector[], int letrasLength, char buscar, char reemplazar);

int main()
{
    char letras[LETRAS_LENGTH]={'a','e','x','j','h','h'};

    int cantidadDeReemplazos;

    for(int i= 0; i<LETRAS_LENGTH; i++){
        printf("%c, ", letras[i]);
    }

    cantidadDeReemplazos = buscarCaracter(letras, LETRAS_LENGTH, 'h', 'y');

    printf("\n%d\n", cantidadDeReemplazos);

    for(int i= 0; i<LETRAS_LENGTH; i++){
        printf("%c, ", letras[i]);
    }

    return 0;
}


int buscarCaracter(char vector[], int letrasLength, char buscar, char reemplazar)
{
    int contadorReemplazos=0;

    for(int i = 0; i < letrasLength; i ++){
        if(buscar==vector[i]){
            vector[i]=reemplazar;
            contadorReemplazos++;
        }
    }
    return contadorReemplazos;
}
