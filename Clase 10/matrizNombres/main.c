#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>#include <strings.h>

#define TAM 5

void mostrarNombres(char m[][20], int tam);
void ordenarNombres(char m[][20], int tam);

int main()
{
    char nombres[TAM][20]={"Donato","German","Carmen","Loco","Pablo"};

//    for(int i=0;i<5;i++){
//        printf("%s\n", nombres[i]);
//    }
//    printf("\n");

    mostrarNombres(nombres, TAM);
    ordenarNombres(nombres, TAM);
    mostrarNombres(nombres, TAM);
    return 0;
}

void mostrarNombres(char m[][20], int tam)
{
    for(int i=0;i<tam;i++){
        printf("%s\n", m[i]);
    }
    printf("\n");
}

void ordenarNombres(char m[][20], int tam)
{
    char aux[20];

    for(int i=0;i<tam-1;i++){
        for(int j=i+1;j<tam;j++){
            if(stricmp(m[i],m[j])>0){
                strcpy(aux,m[i]);
                strcpy(m[i],m[j]);
                strcpy(m[j],aux);
            }
        }
    }
}
