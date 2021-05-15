#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_validaciones.h"
#include "producto.h"

#define QTY_PRODUCTS 1

int main()
{
    sProducto arrayProductos[QTY_PRODUCTS];

    int opcion;
    int indiceEmpty;


    if(prod_initArray(arrayProductos,QTY_PRODUCTS)==0){
        printf("Init OK\n");
    }


    do{
        if(!utn_getNumero(&opcion,"1. Alta\n2. Imprimir\n3. Salir\n","\nError",1,3,10)){
            switch(opcion){
                case 1:
                    indiceEmpty=prod_getEmptyIndex(arrayProductos,QTY_PRODUCTS);
                    if(indiceEmpty>=0){
                        if(prod_updateArray(arrayProductos,QTY_PRODUCTS,indiceEmpty)==0){
                                printf("Carga Ok.");
                        }
                    }
                    else{
                        printf("No hay lugar");
                    }
                    break;
                case 2:
                    prod_printArray(arrayProductos,QTY_PRODUCTS);
                    break;
            }
        }
    }while(opcion!=3);



    printf("\nPrimer lugar vacio: %d",prod_getEmptyIndex(arrayProductos,QTY_PRODUCTS));
    if(prod_updateArray(arrayProductos,QTY_PRODUCTS,2)==0){
        prod_imprimir(&arrayProductos[2]);
    }



//    if(utn_getNumero(&respuestaDescuento,"\nPara aplicar el descuente seleccion [1] - Para salir [2]","Error",1,2,3)==0){
//        if(respuestaDescuento){
//            auxProducto.precio=auxProducto.precio*0.75;
//            //printf("%s - %s - Precio: %.2f",auxProducto.nombre,auxProducto.descripcion,auxProducto.precio);
//            prod_imprimir(&auxProducto);
//        }
//    }

    return 0;
}
