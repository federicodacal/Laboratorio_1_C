#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"



void listarEmpleadosSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int idSector;
    int indice;
    int flag=0;

    system("cls");
    printf("    Informe de Empleados por Sector\n");
    mostrarSectores(sectores, sectorLength);
    printf("Ingrese ID sector: ");
    scanf("%d", &idSector);

    indice=buscarSector(idSector,sectores,sectorLength);

    while(indice==-1){
        printf("ID no es valido. Ingrese ID sector: ");
        scanf("%d", &idSector);
        indice=buscarSector(idSector,sectores,sectorLength);
    }

    printf("\n\t\t*****LISTADO DE EMPLEADOS por SECTOR %s******\n", sectores[indice].descripcion);
    printf("-------------------------------------------------------------------------\n");
    printf("Legajo      Nombre      Edad   Sexo      Sueldo      Fecha Ingreso  Sector\n");
    for(int i=0;i<nominaLength;i++){
        if(lista[i].isEmpty==0 && lista[i].idSector==idSector){
            mostrarEmpleado(lista[i],sectores, sectorLength);
            flag=1;
        }
    }
    if(flag==0){
        printf("No hay empleados en el sector de %s\n", sectores[indice].descripcion);
    }
}


void listarEmpleadosCadaSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int flag;

    system("cls");
    printf("    *****LISTADO DE EMPLEADOS POR SECTOR*****\n\n");
    for(int i=0;i<sectorLength;i++){
        printf("\nSector: %s\n", sectores[i].descripcion);
        flag=1;
        for(int j=0; j<nominaLength;j++){
            if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id){
                mostrarEmpleado(lista[j],sectores,sectorLength);
                flag=0;
            }
        }
        if(flag==1){
            printf("No hay empleados \n");
        }
    }
    printf("\n");
}

void totalSueldoSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int idSector;
    int indice;
    int flag=0;
    float totalSueldos=0;

    system("cls");
    printf("    *****Total Sueldos de Sector\n");
    mostrarSectores(sectores, sectorLength);
    printf("Ingrese ID sector: ");
    scanf("%d", &idSector);

    indice=buscarSector(idSector,sectores,sectorLength);

    while(indice==-1){
        printf("ID no es valido. Ingrese ID sector: ");
        scanf("%d", &idSector);
        indice=buscarSector(idSector,sectores,sectorLength);
    }

    for(int i=0;i<nominaLength;i++){
        if(lista[i].isEmpty==0 && lista[i].idSector==idSector){
            totalSueldos+=lista[i].sueldo;
            flag=1;
        }
    }

    printf("Total Sueldos: $%.2f\n", totalSueldos);
    if(flag==0){
        printf("No hay empleados en el sector de %s\n", sectores[indice].descripcion);
    }
}

void totalADepositar(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    float totalSueldos;
    float acumuladorSueldosTotal=0;

    system("cls");
    printf("    *****Total Sueldos*****\n\n");
    for(int i=0;i<sectorLength;i++){
        printf("\nSector: %s\n", sectores[i].descripcion);
        totalSueldos=0;
        for(int j=0; j<nominaLength;j++){
            if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id){
                totalSueldos+=lista[j].sueldo;
            }
        }
        printf("Total Sueldos: $%.2f\n", totalSueldos);
        acumuladorSueldosTotal+=totalSueldos;

    }
    printf("\n");
    printf("Total a Depositar: $ %.2f\n\n", acumuladorSueldosTotal);
}

void sectorMayorSueldo(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    float totalSueldos;
    float sueldosTotales[sectorLength];
    float mayorSueldo;
    int flag=0;

    system("cls");
    printf("    *****Sectores de Mayor Sueldo*****\n\n");
    for(int i=0;i<sectorLength;i++){
        totalSueldos=0;
        for(int j=0; j<nominaLength;j++){
            if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id){
                totalSueldos+=lista[j].sueldo;
            }
        }
    sueldosTotales[i]=totalSueldos;
    }
    for(int i=0;i<sectorLength;i++){
        if(flag==0 || sueldosTotales[i]>mayorSueldo){
            mayorSueldo=sueldosTotales[i];
            flag=1;
        }
    }
    for(int i=0;i<sectorLength;i++){
        if(mayorSueldo==sueldosTotales[i]){
            printf("%s: $ %.2f\n", sectores[i].descripcion, mayorSueldo);
        }
    }
    printf("\n");
}
