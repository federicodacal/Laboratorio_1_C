/**
Debemos lograr tomar el importe,
mostrar el importe con un aumento del 10 %
**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float importeIngresado;
    int porcentajeAumento;
    float aumento;
    float importeFinal;

    porcentajeAumento=10;

    printf("Ingrese el importe: $");
    scanf("%f", &importeIngresado);
    while(importeIngresado<1){
        printf("Error. Ingrese el importe: $");
        scanf("%f", &importeIngresado);
    }

    aumento= (float) porcentajeAumento/100*importeIngresado;
    printf("%f", aumento);
    importeFinal= (float) importeIngresado+aumento;

    printf("El importe final es: $%.2f", importeFinal);
    return 0;
}
