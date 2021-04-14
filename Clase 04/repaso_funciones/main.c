#include <stdio.h>
#include <stdlib.h>

// Biblioteca de funciones -> formada por dos archivos (uno contiene los desarrollos y otro los prototipos)

int dividir (float* pResultado, int x, int y);

int main()
{
    float resultado;
    int num1;
    int num2;
    int respuesta;

    printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2);

    respuesta=dividir(&resultado,num1,num2);
    if(respuesta==0){ // 0 indica que la funcion se ejecuto bien
        printf("El resultado es: %.2f", resultado);
    }
    else{
        printf("No es posible dividir por 0");
    }
    return 0;
}

int dividir (float* pResultado, int x, int y)
{
    float resultado;
    int retorno=-1;

    if(pResultado!=NULL && y!=0){
        resultado=(float) x/y;
        *pResultado=resultado;
        retorno=0;
    }
    return retorno;
}
