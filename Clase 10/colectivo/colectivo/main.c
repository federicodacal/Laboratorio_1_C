#include <stdio.h>
#include <stdlib.h>
#define FILAS 4
#define COLUMNAS 13

void mostrarRecaudaciones(int matrix[][13], int filas);
void totalizarFila(int vec[], int tam);

int main()
{
    int mat[FILAS][COLUMNAS]={0};
    int linea;
    int interno;
    int recaudacion;
    char seguir;

    do{
        printf("Ingrese linea: ");
        scanf("%d", &linea);

        printf("Ingrese interno: ");
        scanf("%d", &interno);
        printf("Ingrese recaudacion: ");
        scanf("%d", &recaudacion);

        mat[linea-1][interno-1]+=recaudacion;

        printf("Quiere agregar otra recuadacion?: s/n");
        fflush(stdin);
        scanf("%c", &seguir);
    }while(seguir!='n');

    mostrarRecaudaciones(mat,FILAS);
    return 0;
}

void mostrarRecaudaciones(int matrix[][13], int filas)
{
    printf("\t---***Recaudaciones***---\n");
    printf("Internos\n");
    printf("\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\tTotales");

    for(int i=0;i<filas;i++){
        if(i!=filas-1){
            printf("Linea %d", i+1);
        }
        else{
            printf("Totales");
        }
        totalizarFila(matrix[i],13);
        for(int j=0;j<13;j++){
            printf("%4d ", matrix[i][j]);
            if(i<filas){
                matrix[filas-1][j]+=matrix[i][j];
            }
        }
        printf("\n");
    }
    printf("\n");
}

void totalizarFila(int vec[], int tam)
{
    for(int i=0;i<tam-1;i++){
        vec[tam-1]+=vec[i];
    }
}
