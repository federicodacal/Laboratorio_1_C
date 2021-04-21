// Debemos lograr tomar un dato por '=prompt()' y luego mostrarlo por 'alert()'.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;

    printf("Ingrese un numero:");
    scanf("%d", &numero);
    printf("El número ingresado es: %d", numero);

    return 0;
}
