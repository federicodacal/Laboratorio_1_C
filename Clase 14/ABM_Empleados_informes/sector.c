#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"
#include "sector.h"

int cargarDescripcionSector(int id, sSector sectores[], int sectorLength, char descrip[])
{
    int function_success=0;

    if(id>=500 && id<=504 && sectores!=NULL && sectorLength>0 && descrip!=NULL){
        for (int i=0;i<sectorLength;i++){
            if(sectores[i].id == id){
                strcpy(descrip,sectores[i].descripcion);
                function_success=1;
                break;
            }
        }

    }
    return function_success;
}

void mostrarSectores(sSector sectores[], int sectorLength)
{
    printf("    *****LISTA DE SECTORES*****\n");
    printf("        id  Descripcion\n");
    for(int i=0;i<sectorLength;i++){
        mostrarSector(sectores[i]);
    }
    printf("\n");
}

void mostrarSector(sSector sector)
{
    printf("        %d  %10s\n", sector.id, sector.descripcion);
}

int buscarSector(int id, sSector sectores[], int sectorLength)
{
    int indice=-1;

    for(int i=0;i<sectorLength;i++){
        if(sectores[i].id==id){
            indice=i;
            break;
        }
    }
    return indice;
}
