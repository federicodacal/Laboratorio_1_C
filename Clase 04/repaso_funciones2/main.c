#include <stdio.h>
#include <stdlib.h>

/**
sumarNumeros()
    Prototipos:
-1. int sumarNumeros (int a, int b);
-2. int sumarNumeros (void);
-3. void sumarNumeros (int a, int b);
-4. void sumarNumeros (void);
**/

// El usuario ingresa dos numeros y muestro la suma (prototipos 1, 2, 3 ,4)
// Se calculan dos numeros aleatorios, realizar y mostrar la suma (prototipos 1,3)
// El usuario ingresa dos numeros. Sumarlos y determinar si la suma es mayor a 100 (prototipos 1, 2)
// Prototipo 1 el que más adaptable y utilizable en distintas situaciones

void sumarNumeros4(void);
void sumarNumeros3 (int a, int b);
int sumarNumeros2 (void);
int sumarNumeros1 (int a, int b);

int main()
{
    /* Para sumarNumeros4()

    sumarNumeros4();

    return 0;
    */

    /* Para sumarNumeros3()

    int num1;
    int num2;
    int suma;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    sumarNumeros3(num1, num2);

    return 0;
    */

    /* Para sumarNumeros2()

    int suma;
    suma=sumarNumeros2();
    printf("La suma es %d", suma);

    return 0;
    */

    // Para sumarNumeros1()

    int num1;
    int num2;
    int suma;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    suma=sumarNumeros1(num1,num2);

    printf("La suma es %d", suma);

    return 0;

}

void sumarNumeros4(void)
{
    int num1;
    int num2;
    int suma;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    suma=num1+num2;
    printf("La suma es: %d", suma);

}

void sumarNumeros3 (int a, int b) // Parametros formales
{
    int suma;
    suma=a+b;
    printf("La suma es %d", suma);
}

int sumarNumeros2 (void)
{
    int num1;
    int num2;
    int suma;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    suma=num1+num2;
    return suma;
}

int sumarNumeros1 (int a, int b)
{
    int suma;
    suma=a+b;
    return suma;
}
