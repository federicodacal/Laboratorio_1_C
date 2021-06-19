#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
}Estructura;

int main()
{
    int estatica;
    int* pDinamica=(int*)malloc(sizeof(int));
    int* pDinamica2=(int*)malloc(sizeof(int));
    int* pDinamica3=(int*)malloc(sizeof(int));
    float* pPi=(float*)malloc(sizeof(float));

    estatica=10;
    *pDinamica=15;
    *pPi=3.1416;
    *pDinamica3=33;

    printf("Estatica: %d\tDinamica: %d\n\n",estatica,*pDinamica);

    printf("Ingrese un numero para memoria estatica: \n");
    scanf("%d",&estatica);
    printf("Ingrese un numero para memoria dinamica: \n");
    scanf("%d",pDinamica2);

    printf("\nEstatica: %d\tDinamica: %d\n",estatica,*pDinamica2);
    printf("Pi: %.4f\n\n",*pPi);

    printf("Puntero a entero: %d\n",sizeof(int*));    // 8
    printf("Int: %d\n",sizeof(int));
    printf("Puntero a float: %d\n",sizeof(float*));  // 8
    printf("Float: %d\n",sizeof(float));
    printf("Puntero a char: %d\n",sizeof(char*));   // 8
    printf("Char: %d\n",sizeof(char));
    printf("Puntero a estructura: %d\n",sizeof(Estructura*));   // 8
    printf("Estructura: %d\n",sizeof(Estructura));

    if(pDinamica3==NULL){
        printf("No fue posible conseguir memoria.\n");
        system("pause");
        exit(1);
    }

    free(pDinamica);
    free(pDinamica2);
    free(pDinamica3);
    free(pPi);
    return 0;
}
