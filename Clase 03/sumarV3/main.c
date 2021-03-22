#include <stdio.h>
#include <stdlib.h>
// Prototipo (va a devolver, no recibir)
int sumarv3(); // int sumarv3(void)

int main()
{
    int resultado;
    // Llamada
    resultado=sumarv3();
    printf("El resultado es: %d", resultado);
    return 0;
}

// Desarrollo
int sumarv3()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado=num1+num2;
    return resultado;
}
