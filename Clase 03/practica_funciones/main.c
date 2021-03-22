/**
MINI-CALCULADORA:
Un programa que pida al usuario un numero, despues que pida una operacion y despues pida otro numero. Segun la operacion ingresada se llamará a una funcion que ejecute la operacion sumar, restar, multiplicar, dividir. Luego mostrar al usuario el resultado. El mostrar no puede estar dentro de las funciones de cada operacion. En funcion dividir validar no dividir por 0.
**/

#include <stdio.h>
#include <stdlib.h>
// Prototipos
int sumar (int a, int b);
int restar (int a, int b);
int multiplicar (int a, int b);
float dividir (int a, int b);

int main()
{
    int num1;
    int num2;
    float resultado;
    char operacion;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese operacion (s=sumar, r=restar, m=multiplicar, d=dividir): ");
    fflush(stdin);
    scanf("%c", &operacion);
    while(operacion !='s' && operacion !='r' && operacion !='m' && operacion !='d'){
        printf("Error. Ingrese operacion (s=sumar, r=restar, m=multiplicar, d=dividir): ");
        fflush(stdin);
        scanf("%c", &operacion);
    }
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);
    while(operacion=='d' && num2==0){
        printf("Error. El 0 no puede ser divisor. Ingrese otro numero: ");
        scanf("%d", &num2);
    }

    switch(operacion){
        case 's':
            sumar(num1,num2);
            resultado=sumar(num1,num2);
            break;
        case 'r':
            restar(num1,num2);
            resultado=restar(num1,num2);
            break;
        case 'm':
            multiplicar(num1,num2);
            resultado=multiplicar(num1,num2);
            break;
        case 'd':
            dividir(num1,num2);
            resultado=dividir(num1,num2);
            break;
    }

    printf("El resultado de la operacion %c es: %.2f", operacion, resultado);

    return 0;
}

int sumar (int a, int b)
{
    int resultado;
    resultado=a+b;
    return resultado;
}

int restar (int a, int b)
{
    int resultado;
    resultado=a-b;
    return resultado;
}

int multiplicar (int a, int b)
{
    int resultado;
    resultado=a*b;
    return resultado;
}

float dividir (int a, int b)
{
    float resultado;
    resultado=(float) a/b;
    return resultado;
}
