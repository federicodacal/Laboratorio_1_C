#include <stdio.h>
#include <stdlib.h>

float pedirNumero();
float calcularArea(float radio);

int main()
{
    float aux;
    float area;

    aux=pedirNumero();
    area=calcularArea(aux);
    printf("El area del circulo es: %.2f", area);
    return 0;
}

float pedirNumero()
{
    float auxiliar;
    printf("Ingrese un numero ");
    scanf("%f", &auxiliar);
    return auxiliar;
}

float calcularArea(float radio)
{
    float resultado;
    resultado=3.14*radio*radio;
    return resultado;
}
