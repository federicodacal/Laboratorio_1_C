#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

char nombres[10][20]={
    "Donato",
    "Carmen",
    "Chepi",
    "Alex",
    "German",
    "Maria",
    "Damian",
    "Daniel",
    "Andrea",
    "Candela"
};

char sexos[10]={'m','f','f','m','m','f','m','m','f','f'};

int edades[10]={56,71,39,30,52,45,44,58,38,29};

float sueldos[10]={1000,1000,1420,1350,2000,1950,2150,1060,1742,1800};

sFecha fechas[10]={
    {4,3,2011},
    {24,3,2021},
    {28,4,2015},
    {11,6,2018},
    {12,5,2016},
    {16,3,2021},
    {2,9,2012},
    {6,11,2018},
    {17,12,2019},
    {19,1,2020}
};

int idSectores[10]={500,504,501,501,502,503,502,504,502,500};

sFecha fechasAlm[]={
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {1,3,2021},
    {2,3,2021},
    {2,3,2021},
    {2,3,2021},
    {2,3,2021},
    {3,3,2021},
    {3,3,2021},
    {4,3,2021},
    {4,3,2021},
    {5,3,2021},
    {5,3,2021},
    {5,3,2021},
    {5,3,2021},
    {5,3,2021}
};

int legajos[]={20000,20001,20002,20003,20004,20005,20006,20007,20001,20003,20007,20009,20006,20008,20007,20000,20002,20003,20004,20005,20009};

int idComidas[]={1004,1003,1003,1002,1001,1000,1001,1002,1004,1000,1003,1000,1002,1004,1004,1000,1002,1001,1003,1001,1004};

int hcodearEmpleados(sEmpleado lista[], int nominaLength, int cant, int* pLegajo)
{
    int cantidad=0;

    if(lista!=NULL && nominaLength>0 && cant>=0 && cant <=nominaLength && pLegajo!=NULL){
        for(int i=0;i<cant;i++){
            lista[i].legajo=*pLegajo;
            (*pLegajo)++;
            // *pLegajo=*pLegajo+1;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].edad=edades[i];
            lista[i].sexo=sexos[i];
            lista[i].sueldo=sueldos[i];
            lista[i].fIngreso=fechas[i];
            lista[i].idSector=idSectores[i];
            lista[i].isEmpty=0;
            cantidad++;
        }
    }

    return cantidad;
}

int hcodearAlmuerzos(sAlmuerzo almuerzos[], int almuerzosLength, int cant, int* pId)
{
    int cantidad=0;

    if(almuerzos!=NULL && almuerzosLength>0 && cant>=0 && cant <=almuerzosLength && pId!=NULL){
        for(int i=0;i<cant;i++){
            almuerzos[i].id=*pId;
            (*pId)++;
            // *pLegajo=*pLegajo+1;
            almuerzos[i].legajoEmpleado=legajos[i];
            almuerzos[i].idComida=idComidas[i];
            almuerzos[i].fecha=fechasAlm[i];
            almuerzos[i].isEmpty=0;
            cantidad++;
        }
    }

    return cantidad;
}
