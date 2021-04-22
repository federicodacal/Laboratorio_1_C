#include <stdio.h>
#include <stdlib.h>
#define LENGTH 5
#define FILAS 3
#define COLUMNAS 5

void mostrarMatriz(int matrix[][5], int filas);

int main()
{
    int x;
    int y[5];
    int z[3][5];

    int t=4;
    int s[LENGTH]={3,2,8,6,5};
    int r[FILAS][COLUMNAS]={{2,1,5,2,3},{5,7,8,5,1},{3,2,3,4,6}};

    int w[LENGTH]={3,2,6,5,7};
    int p[FILAS][COLUMNAS]={{1,2,3,4,5},{6,7,8,9,10},{4,5,3,2,9}};

    int q[FILAS][COLUMNAS]={0}; // Inicializada en 0

    int k[FILAS][COLUMNAS]={0};

    x=10;   // Asgirnar 10 a variable escalar 'x'
    y[3]=10; // Asignar 10 en el indice 3 de vector 'y'
    z[2][1]=10; // Asignar 10 en la fila 2 columna 1 de matriz 'z'

    printf("%d\n", x);
    printf("%d\n", y[3]);
    printf("%d\n", z[2][1]);
    printf("\n");
    printf("%d\n", t);
    printf("%d\n", s[3]);
    printf("%d\n", r[2][1]);
    printf("\n");

    for(int i=0;i<LENGTH;i++){
        printf("%d ", w[i]);
    }
    printf("\n\n");

    // Recorrer matriz r
    for(int i=0;i<FILAS;i++){   // 0,1,2
        for(int j=0;j<COLUMNAS;j++){    // 0,1,2,3,4
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Recorrer matriz p
    for(int i=0;i<FILAS;i++){   // 0,1,2
        for(int j=0;j<COLUMNAS;j++){    // 0,1,2,3,4
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    q[0][4]=4;
    q[2][1]=3;

    for(int i=0;i<COLUMNAS;i++){
        q[1][i]=6;
    }
    for(int i=0;i<FILAS;i++){
        q[i][2]=8;
    }

    // Recorrer matriz q
    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            printf("%d ", q[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0;i<FILAS;i++){
        for(int j=0;j<COLUMNAS;j++){
            printf("Ingrese un nro: ");
            scanf("%d", &k[i][j]);
        }
    }

    // Recorrer matriz
    mostrarMatriz(k, FILAS);

    return 0;
}

void mostrarMatriz(int matrix[][5], int filas)
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<5;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
