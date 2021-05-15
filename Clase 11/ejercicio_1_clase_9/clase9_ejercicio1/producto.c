#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "utn_validaciones.h"

int setStatus(sProducto productos[], int productosLength, int value)
{
    int function_success=-1;
    if(productos!=NULL && productosLength>0){
        for(int i=0;i<productosLength;i++){
            productos[i].isEmpty=value;
        }
        function_success=0;
    }
    return function_success;
}

int findEmpty(sProducto productos[], int productosLength)
{
    int index=-1;
    if(productos!=NULL && productosLength>0){
        for(int i=0;i<productosLength;i++){
            if(productos[i].isEmpty==0){
                 index=i;
            }
        }
    }
    return index;
}
int findProductById(sProducto productos[], int productosLength, int idProd)
{
    int index=-1;
    if(productos!=NULL && productosLength>0){
        for(int i=0;i<productosLength;i++){
            if(productos[i].id==idProd && productos[i].isEmpty==1){
                 index=i;
            }
        }
    }
    return index;
}

int prod_imprimir(sProducto* aux)
{
    int retorno=-1;
    if(aux!=NULL){
        printf("%s - %s - Precio: %.2f",aux->nombre,aux->descripcion,aux->precio);
        retorno=0;
    }
    return retorno;
}

int prod_printArray(sProducto* productos, int productosLength)
{
    int respuesta=1;

    if(productos!=NULL && productosLength>0){
        for(int i=0;i<productosLength;i++){
            if(productos[i].isEmpty!=1){
                printf("%s - %s - Precio: %.2f",productos[i].nombre,productos[i].descripcion,productos[i].precio);
            }
        }
        respuesta=0;
    }

    return respuesta;
}


int prod_initArray(sProducto* productos, int productosLength)
{
    int respuesta=1;

    if(productos!=NULL && productosLength>0){
        for(int i=0;i<productosLength;i++){
            productos[i].isEmpty=1;
        }
        respuesta=0;
    }

    return respuesta;
}

int prod_updateArray(sProducto* productos, int productosLength, int indice)
{
    int respuesta=1;
    sProducto auxProducto;

    if(productos!=NULL && productosLength>0 && indice<productosLength){
        if (utn_getNombre(auxProducto.nombre,NOMBRE_LENGTH,"\nIngrese Nombre: ","\nError dato no valido",10)==0 &&
        utn_getDescripcion(auxProducto.descripcion,DESCRIPCION_LENGTH,"\nIngrese Descripcion: ","\nError dato no valido",10)==0 &&
        utn_getNumeroFlotante(&auxProducto.precio,"Precio: $","\nError dato no valido",0.1,100000,10)==0)
        {
        //printf("%s - %s - Precio: %.2f",auxProducto.nombre,auxProducto.descripcion,auxProducto.precio);
        //prod_imprimir(&auxProducto);
        }
        respuesta=0;
        productos[indice]=auxProducto;
        productos[indice].isEmpty=0;
    }

    return respuesta;
}

int prod_getEmptyIndex(sProducto* productos, int productosLength)
{
    int respuesta=1;

    if(productos!=NULL && productosLength>0){
        for(int i=0;i<productosLength;i++){
            if(productos[i].isEmpty==1){
                respuesta=i;
                break;
            }
        }
    }
    return respuesta;
}
