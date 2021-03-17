// Debemos lograr tomar dos numeros, realizar la operaci�n correcta y mostrar el resulto por medio de "alert()"
// ej.: "la Resta es 750"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char operacion[20];
    char suma[] = "suma";
    char resta[] = "resta";
    char division[] = "division";
    char multiplicacion[] = "multiplicacion";
    int respuestaSuma;
    int respuestaResta;
    int respuestaDivision;
    int respuestaMultiplicacion;

    int num1;
    int num2;
    int resultadoSuma;
    int resultadoResta;
    int resultadoDivision;
    int resultadoMultiplicacion;

    printf("Que operacion desea realizar? (suma, resta, division o multiplicacion):\n");
    scanf("%s", operacion);
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    respuestaSuma=(strcmp(operacion, suma));
    respuestaResta=(strcmp(operacion, resta));
    respuestaDivision=(strcmp(operacion, division));
    respuestaMultiplicacion=(strcmp(operacion, multiplicacion));

    do{
        if(respuestaSuma==0){
            resultadoSuma=num1+num2;
            printf("La suma es: %d", resultadoSuma);
        }
        else if(respuestaResta==0){
            resultadoResta=num1-num2;
            printf("La resta es: %d", resultadoResta);
        }
        else if(respuestaDivision==0){
            resultadoDivision=num1/num2;
            printf("La division es: %d", resultadoDivision);
        }
        else if(respuestaMultiplicacion==0){
            resultadoMultiplicacion=num1*num2;
            printf("La multiplicacion es: %d", resultadoMultiplicacion);
        }

        prompt("�Desea continuar ingresando datos?");
    }while()
    return 0;
}
