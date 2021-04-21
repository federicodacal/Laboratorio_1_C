// Debemos lograr tomar dos numeros, realizar la operaci�n correcta y mostrar el resulto por medio de "alert()"
// ej.: "la Resta es 750"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num1;
    int num2;
    char operacion;
    int suma;
    int resta;
    int multiplicacion;
    float division;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("Que operacion desea realizar? s=suma, r=resta, m=multiplicacion d=division ");
    fflush(stdin);
    scanf("%c", &operacion);
    while(operacion!='s' && operacion!='r' && operacion!='m' && operacion!='d'){
            printf("Error. Que operacion desea realizar? s=suma, r=resta, m=multiplicacion d=division ");
            fflush(stdin);
            scanf("%c", &operacion);
    }

    switch(operacion){
        case 's':
            suma=num1+num2;
            printf("La suma es: %d", suma);
            break;
        case 'r':
            resta=num1-num2;
            printf("La resta es: %d", resta);
            break;
        case 'm':
            multiplicacion=num1*num2;
            printf("La multiplicacion es: %d", multiplicacion);
            break;
        case 'd':
            division=(float) num1/num2;
            printf("La division es: %.2f", division);
            break;

    }


}
