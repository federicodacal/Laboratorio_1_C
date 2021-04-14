#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5
int main()
{
    int numeros[LENGTH]={3,5,2,9,4};
    int aux;

    for(int i=0;i<3;i++){
        printf("Hola a todo el mundo!\n");
        for(int j=0;j<5;j++){
            printf("Chau...\n");
        }
    }
    // i=0 j=0/1/2/3/4
    // i=1 j=0/1/2/3/4
    // i=2 j=0/1/2/3/4

    printf("\n\n\n");

    for(int i=0;i<LENGTH-1;i++){
        printf("Hola a todo el mundo!\n");
        for(int j=i+1;j<LENGTH;j++){
            printf("Chau...\n");
        }
    }

    printf("\n\n\nIncial: ");
    for(int i=0;i<LENGTH;i++){
        printf("%d ", numeros[i]);
    }

    printf("\n");
    for(int i=0;i<LENGTH-1;i++){

        for(int j=i+1;j<LENGTH;j++){
            if(numeros[i]>numeros[j]){
                aux=numeros[i];
                numeros[i]=numeros[j];
                numeros[j]=aux;
            }
        }
    }

    printf("\nOrdenado: ");
    for(int i=0;i<LENGTH;i++){
        printf("%d ", numeros[i]);
    }

    printf("\n\n");
    return 0;
}


