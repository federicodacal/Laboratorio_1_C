/**
Debemos lograr tomar el importe,
mostrar el importe con un decuento del 25 %.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float importeIngresado;
    int porcentajeDescuento;
    float descuento;
    float importeFinal;

    porcentajeDescuento=-25;

    printf("Ingresa el importe: $");
    scanf("%f", &importeIngresado);

    descuento=(float) porcentajeDescuento/100*importeIngresado;
    printf("%2.f", descuento);

    importeFinal=importeIngresado+descuento;
    printf("El importe final es: $%.2f", importeFinal);

    return 0;
}
