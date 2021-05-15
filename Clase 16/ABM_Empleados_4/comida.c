#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"

void mostrarComidas(sComida comidas[], int comidasLength)
{
    printf("    Lista de Comidas\n");
    printf("    id    Descripcion   Precio\n");
    for(int i=0;i<comidasLength;i++){
        mostrarComida(comidas[i]);
    }
}

void mostrarComida(sComida unaComida)
{
    printf("    %d  %10s    $%.2f\n",unaComida.id, unaComida.descripcion, unaComida.precio);
}

int cargarDescripcionComida(int id, sComida comidas[], int comidasLength, char descrip[])
{
    int function_success=0;

    if(id>=1000 && id<=1004 && comidas!=NULL && comidasLength>0 && descrip!=NULL){
        for (int i=0;i<comidasLength;i++){
            if(comidas[i].id == id){
                strcpy(descrip,comidas[i].descripcion);
                function_success=1;
                break;
            }
        }

    }
    return function_success;
}

int validarIdComida(int id, sComida comidas[], int comidasLength)
{
    int valido=0;

    if(comidas!=NULL && comidasLength>0){
        for(int i=0;i<comidasLength;i++){
            if(comidas[i].id==id){
                valido=1;
                break;
            }
        }
    }

    return valido;
}

int buscarComida(int id, sComida comidas[], int comidasLength)
{
    int indice=-1;
        if(comidas!=NULL && comidasLength>0){
        for(int i=0;i<comidasLength;i++){
            if(comidas[i].id==id){
                indice=i;
                break;
            }
        }
    }
    return indice;
}
