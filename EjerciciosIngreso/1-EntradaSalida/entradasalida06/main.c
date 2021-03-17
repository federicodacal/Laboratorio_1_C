// Debemos lograr tomar dos numeros y sumarlos. Mostrar el resulto por medio de "alert()"
// ej.: "la suma es 750"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int suma;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    suma=num1+num2;
    printf("La suma es: %d", suma);
    return 0;
}
