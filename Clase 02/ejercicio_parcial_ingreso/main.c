/**
Debemos realizar la carga de una compra de 5(cinco) productos de prevención de contagio
De cada uno debo obtener los siguientes datos:
el nombre del producto
el tipo de producto (validar "ALCOHOL" , "IAC" o "QUAT") ,
el precio (validar entre 100 y 300),
la cantidad de unidades (no puede ser 0 o negativo y no debe superar las 1000 unidades),
el tipo de inflamable("ignífugo", "combustible", "explosivo" )
y la Marca.

Se debe informar al usuario lo siguiente:

a) El promedio de cantidad por tipo de producto
b) El tipo de inflamable con más cantidad de unidades en total de la compra
c) Cuántas unidades de IAC con precios menores a 200 (inclusive) se compraron en total
d) La marca y tipo del más caro de los productos
**/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // permite usar funciones de caracteres, ej: tolower() y toupper()
#include <math.h> // permite usar funciones de operaciones matematicas

int main()
{
    // nombre
    // tipo prod
    // precio
    // cantidad
    // tipo inf
    // marca

    // promedio acohol
    // promedio iac
    // promedio quat

    // acumulador alcohol
    // acumulador iac
    // acumulador quat

    // contador alcohol
    // contador iac
    // contador quat

    // acumulador ign
    // acumulador comb
    // acumulador exp

    // contador iac < 200

    // precio producto mayor precio
    // marca producto mayor precio
    // tipo producto mayor precio
    // flag precio

    char nombre;
    char tipoProducto;
    float precio;
    int cantidadUnidades;
    char tipoInflamable;
    char marca;

    float promedioA=0;
    float promedioI=0;
    float promedioQ=0;

    int acumuladorA=0;
    int acumuladorI=0;
    int acumuladorQ=0;
    int contadorA=0;
    int contadorI=0;
    int contadorQ=0;

    int acumuladorIg=0;
    int acumuladorComb=0;
    int acumuladorExp=0;

    int contadorIACBarato=0;

    float precioMayorPrecio;
    char tipoMayorPrecio;
    char marcaMayorPrecio;
    int flag=1;

    for(int i=0;i<5;i++){

        printf("Ingrese el nombre: ");
        fflush(stdin);
        scanf("%c", &nombre);

        printf("Ingrese el tipo de prodcuto (a, i, q): ");
        fflush(stdin);
        scanf("%c", &tipoProducto);
        while(tipoProducto != 'a' && tipoProducto != 'i' && tipoProducto != 'q'){
            printf("Error. Ingrese el tipo de prodcuto (a, i, q): ");
            fflush(stdin);
            scanf("%c", &tipoProducto);
        }

        printf("Ingrese el precio: ");
        scanf("%f", &precio);
        while(precio<100 || precio>300){
            printf("Error. Ingrese el precio: ");
            scanf("%f", &precio);
        }

        printf("Ingrese la cantidad de unidades: ");
        scanf("%d", &cantidadUnidades);
        while(cantidadUnidades<1 || cantidadUnidades>1000){
            printf("Error. la cantidad de unidades: ");
            scanf("%d", &cantidadUnidades);
        }

        printf("Ingrese el tipo de inflamable (i, c, e): ");
        fflush(stdin);
        scanf("%c", &tipoInflamable);
        while(tipoInflamable != 'i' && tipoInflamable != 'c' && tipoInflamable != 'e'){
            printf("Ingrese el tipo de inflamable (i, c, e): ");
            fflush(stdin);
            scanf("%c", &tipoInflamable);
        }

        printf("Ingrese la marca: ");
        fflush(stdin);
        scanf("%c", &marca);

        printf("El nombre es %c, el tipo es %c, el precio es $%.2f, la cantidad es %d, el tipo inflamable es %c y la marca es %c\n\n", nombre, tipoProducto, precio, cantidadUnidades, tipoInflamable, marca);

        switch(tipoProducto){
            case 'a':
                contadorA++;
                acumuladorA+=cantidadUnidades;
                break;
            case 'i':
                contadorI++;
                acumuladorI+=cantidadUnidades;
                if(precio<201){
                    contadorIACBarato++;
                }
                break;
            case 'q':
                contadorQ++;
                acumuladorQ+=cantidadUnidades;
                break;
        }

        switch(tipoInflamable){
            case 'i':
                acumuladorIg+=cantidadUnidades;
                break;
            case 'c':
                acumuladorComb+=cantidadUnidades;
                break;
            case 'e':
                acumuladorExp+=cantidadUnidades;
                break;
        }

        if(flag==1 || precio>precioMayorPrecio){
            precioMayorPrecio=precio;
            tipoMayorPrecio=tipoProducto;
            marcaMayorPrecio=marca;
            flag=0;
        }
    }

    printf("Se ingreso A: %d veces\nSe ingreso I: %d veces\nSe ingreso Q: %d veces\n", contadorA, contadorI, contadorQ);
    printf("Cantidad unidades A: %d\nCantidad unidades I: %d\nCantidad unidades Q: %d\n", acumuladorA, acumuladorI, acumuladorQ);

    // Comprobar si se ingreso A
    if(contadorA==0){
        printf("No se ingresaron unidades de A\n");
    }
    else{
        promedioA=(float)acumuladorA/contadorA;
        printf("El promedio de A es %2.f\n", promedioA);
    }

    // Comprobar si se ingreso I
    if(contadorI==0){
        printf("No se ingresaron unidades de I\n");
    }
    else{
        promedioI=(float)acumuladorI/contadorI;
        printf("El promedio de I es %2.f\n", promedioI);
    }

    // Comprobar si se ingreso Q
    if(contadorQ==0){
        printf("No se ingresaron unidades de Q\n");
    }
    else{
        promedioQ=(float)acumuladorQ/contadorQ;
        printf("El promedio de Q es %2.f\n", promedioQ);
    }

    // Comprobar tipo inflamable con mas unidades
    if(acumuladorIg>acumuladorComb && acumuladorIg>acumuladorExp){
        printf("El tipo inflamable con mas unidades es Ignifugo\n");
    }
    else if(acumuladorComb>acumuladorExp){
        printf("El tipo inflamable con mas unidades es Combustible\n");
    }
    else{ // explosivo
        printf("El tipo inflamable con mas unidades es Explosivo\n");
    }

    // Comprobar si se ingreso IAC con precio 200 o menor
    if(contadorIACBarato==0){
        printf("No se ingresaron unidades de IAC con precio $200 o menor\n");
    }
    else{
        printf("La cantidad de IAC con precio $200 o menor es: %d\n", contadorIACBarato);
    }

    // Mayor precio
    printf("El mayor precio es %2.f, el tipo es %c y la marca es %c\n", precioMayorPrecio, tipoMayorPrecio, marcaMayorPrecio);

  return 0;
}
