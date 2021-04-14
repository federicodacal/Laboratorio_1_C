#include <stdio.h>
#include <stdlib.h>

/** \brief Realiza la division de dos enteros
 *
 * \param x int dividendo de la operacion
 * \param y int divisor de la operacion
 * \return float cociente
 *
 */
float dividir(int x, int y);

/** \brief Realiza la division de dos enteros
 *
 * \param a int dividendo de la operacion
 * \param b int divisor de la operacion
 * \param c float* puntero
 * \return int 1 si pudo realizar la division o 0 si no pudo
 *
 */
int dividir2 (int a, int b, float* c);

int main()
{
    float resultado;
    int num1=20;
    int num2=5;
    int divisionOk; // Usada como bandera que la operacion se realizo correctamente

    divisionOk=dividir2(num1,num2,&resultado); // Paso la direccion de memoria de resultado con &resultado
    if(divisionOk){ // Es lo mismo que decir divisionOk == 1
        printf("El resultado de la division es: %.2f", resultado);
    }
    else{
        printf("Error. No se pudo realizar la operacion");
    }


    /*
    if(num2!=0){
        resultado=dividir(num1,num2);
        printf("Resultado: %.2f\n", resultado);
    }
    else{
        printf("La division por 0 no esta definida");
    }
    */
    return 0;
}

float dividir(int x, int y)
{
    float resultado;
    resultado=(float) x/y;

    return resultado;
    // return (float) x/y;
}

int dividir2 (int a, int b, float* c)
{
    int respuesta;
    if(b!=0 && c!=NULL){ // Validar puntero no sea NULL
        *c=(float) a/b; // Operador de indireccion (asigno el valor a direccion de memoria)
        respuesta=1;
    }
    else{
        respuesta=0;
    }
    return respuesta;
}
