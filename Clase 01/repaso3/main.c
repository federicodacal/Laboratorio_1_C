/**
DACAL FEDERICO
DIVISION "A"
IDE: CodeBlocks

Ejercicio 2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en
qué orden fue ingresado.
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroIngresado;
    int numeroMinimo;
    int numeroMaximo;
    int ingresoMax;
    int ingresoMin;

    for(int i=0;i<5;i++){
        printf("Ingrese numero: ");
        scanf("%d", &numeroIngresado);

        if(i==0){
            numeroMaximo=numeroIngresado;
            numeroMinimo=numeroIngresado;
        }
        else{
            if(numeroIngresado<numeroMinimo){
                numeroMinimo=numeroIngresado;
                ingresoMin=i+1;
            }
            if(numeroIngresado>numeroMaximo){
                numeroMaximo=numeroIngresado;
                ingresoMax=i+1;
            }
        }
    }

    printf("El maximo es: %d y se ingreso en la vuelta nro. %d\nEl minimo es: %d y se inrgeso en la vuelta nro. %d\n", numeroMaximo, ingresoMax, numeroMinimo, ingresoMin);
    return 0;
}
