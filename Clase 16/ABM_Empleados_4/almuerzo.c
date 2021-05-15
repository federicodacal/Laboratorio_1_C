#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"
#include "comida.h"
#include "Empleado.h"
#include "fecha.h"

int altaAlmuerzo(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength, int* pNextId)
{
    int function_success=0;
    int indice;
    int legajo;
    int idComida;

    sAlmuerzo nuevoAlmuerzo;

    if(almuerzos!=NULL && comidas!=NULL && lista!=NULL && sectores!=NULL && pNextId!=NULL && almuerzosLength>0 && nominaLength>0 && sectorLength>0 && comidasLength>0){
        printf("    Alta Almuerzos\n");
        indice=buscarLibreAlmuerzo(almuerzos,almuerzosLength);
        if(indice==-1){
            printf("No hay lugar para cargar mas almuerzos");
        }
        else{
            mostrarEmpleados(lista,nominaLength,sectores,sectorLength);
            printf("Ingrese legajo empleado: \n");
            scanf("%d",&legajo);
            while(buscarEmpleado(lista,nominaLength,legajo)==-1){
                printf("Error. Reingrese legajo empleado: \n");
                scanf("%d",&legajo);
            }

            nuevoAlmuerzo.legajoEmpleado=legajo;

            mostrarComidas(comidas,comidasLength);
            printf("Ingrese ID de Comida: \n");
            scanf("%d",&idComida);
            while(!(validarIdComida(idComida,comidas,comidasLength))){
                printf("Error. Reingrese ID de Comida: \n");
                scanf("%d",&idComida);
            }

            nuevoAlmuerzo.idComida=idComida;

            printf("Ingrese fecha dd/mm/aaaa: \n");
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

            nuevoAlmuerzo.id=*pNextId;
            (*pNextId)++;
            nuevoAlmuerzo.isEmpty=0;
            almuerzos[indice]=nuevoAlmuerzo;

            function_success=1;
        }
    }


    return function_success;
}

void mostrarAlmuerzos(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength)
{
    int flag=1;
    printf("\n\t\t*****LISTADO DE ALMUERZOS******\n");
    printf("-------------------------------------------------------------------------\n");
    printf("    ID      Legajo      Nombre   Comida      Fecha\n");
    for(int i=0;i<almuerzosLength;i++){
        if(!almuerzos[i].isEmpty){
            mostrarAlmuerzo(almuerzos[i], comidas, comidasLength, lista, nominaLength);
            flag=0;
        }
    }
    if(flag){
        printf("\n\tNo hay almuerzos que mostrar\n");
    }
    printf("\n\n");
}

void mostrarAlmuerzo(sAlmuerzo unAlmuerzo, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength)
{
    char nombreEmpleado[20];
    char descripComida[20];

    if(cargarNombreEmpleado(unAlmuerzo.legajoEmpleado, lista, nominaLength, nombreEmpleado)&&(cargarDescripcionComida(unAlmuerzo.idComida,comidas,comidasLength,descripComida))){
        printf("    %d  %d    %10s    %10s    %02d/%02d/%d\n",
               unAlmuerzo.id,
               unAlmuerzo.legajoEmpleado,
               nombreEmpleado,
               descripComida,
               unAlmuerzo.fecha.dia,
               unAlmuerzo.fecha.mes,
               unAlmuerzo.fecha.anio);
    }

}


int buscarLibreAlmuerzo(sAlmuerzo almuerzos[], int almuerzosLength)
{
    int indice=-1;
    for(int i=0;i<almuerzosLength;i++){
        if(almuerzos[i].isEmpty){
            indice=i;
            break;
        }
    }
    return indice;
}

void inicializarAlmuerzos(sAlmuerzo almuerzos[], int almuerzosLength)
{
    for(int i=0;i<almuerzosLength;i++){
        almuerzos[i].isEmpty=1;
    }
}
