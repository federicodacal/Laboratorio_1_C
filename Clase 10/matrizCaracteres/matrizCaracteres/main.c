#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char z[3][10]={
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'}};


    for(int i=0; i<3;i++){
        for(int j=0;j<10;j++){
            printf("%c",z[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    strcpy(z[1],"Juan");
    strcpy(z[2],"Pepe");

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(z[0]);


    for(int i=0; i<3;i++){
        for(int j=0;j<10;j++){
            printf("%c",z[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<3;i++){
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(z[i]);
    }


    for(int i=0;i<3;i++){
        printf("%s\n",z[i]);
    }

    return 0;
}
