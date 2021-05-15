#include <stdio.h>
#include <stdlib.h>
#include "validacion.h"

int calcularMayor(int* pResultado, int x, int y);

int main()
{
    int num1;
    int num2;
    int respuesta;
    int respuestaNum1;
    int respuestaNum2;
    int resultado;

    respuestaNum1=getNumber(&num1,"Ingese el primer nro: \n","Error\n",-100,100,3);
    respuestaNum2=getNumber(&num2,"Ingese el segundo nro: \n","Error\n",-100,100,3);

    if(respuestaNum1==0&&respuestaNum2==0){
        respuesta=calcularMayor(&resultado,num1,num2);
        if(respuesta==0){
        printf("Los nros. son iguales\n");
        }
        else if(respuesta>0){
        printf("El mayor nro es: %d\n", resultado);
        }
        else{
        printf("Error\n");
        }
    }
    else{
        printf("Error al cargar alguno de los nros\n");
    }


    return 0;
}

int calcularMayor(int* pResultado, int x, int y)
{
    int function_success=-1;

    if(pResultado!=NULL){
        if(x==y){
            function_success=0;
        }
        else{
            if(x>y){
                *pResultado=x;
            }
            else{
                *pResultado=y;
            }
            function_success=1;
        }
    }

    return function_success;
}
