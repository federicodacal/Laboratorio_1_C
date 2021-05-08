#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Empleado.h"
#include "datawarehouse.h"

void mostrarEmpleado(sEmpleado unEmpleado, sSector sectores[], int sectorLength)
{
    char descripcion[20];
    if(cargarDescripcionSector(unEmpleado.idSector, sectores, sectorLength, descripcion)){
    printf("%d     %10s      %d      %c      %9.2f      %02d/%02d/%02d  %s\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fIngreso.dia,
           unEmpleado.fIngreso.mes,
           unEmpleado.fIngreso.anio,
           descripcion
           );
    }
}

void mostrarEmpleados(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int flag=1;
    printf("\n\t\t*****LISTADO DE EMPLEADOS******\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Legajo      Nombre      Edad   Sexo      Sueldo      Fecha Ingreso  Sector\n");
    for(int i=0;i<nominaLength;i++){
        if(!lista[i].isEmpty){
            mostrarEmpleado(lista[i], sectores, sectorLength);
            flag=0;
        }
    }
    if(flag){
        printf("\n\tNo hay empleados que mostrar\n");
    }
    printf("\n\n");

}

void ordenarEmpleados(sEmpleado lista[], int nominaLength)
{
    sEmpleado auxEmpleado;
    for(int i=0; i<nominaLength-1;i++){
        for(int j=i+1;j<nominaLength;j++){
            if(lista[i].sexo>lista[j].sexo || (lista[i].sexo==lista[j].sexo && strcmpi(lista[i].nombre,lista[j].nombre)>0)){

                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}

void inicializarEmpleados(sEmpleado lista[], int nominaLength)
{
    for(int i=0;i<nominaLength;i++){
        lista[i].isEmpty=1;
    }
}

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

int altaEmpleado(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLenght, int* pLegajo)
{
    int function_success=0;
    sEmpleado nuevoEmpleado; // auxiliar
    int indice;
    int idSector;

    system("cls");
    printf("\t Alta Empleado\n");
    printf("Legajo: %d\n", *pLegajo);

    if(lista!=NULL && nominaLength>0 && pLegajo!=NULL){
        indice=buscarLibre(lista, nominaLength);
        if(indice==-1){
            printf("No hay lugar en el sistema\n");
        }
        else{
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese edad: ");
            scanf("%d", &nuevoEmpleado.edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
            scanf("%d/%d/%d",
                &nuevoEmpleado.fIngreso.dia,
                &nuevoEmpleado.fIngreso.mes,
                &nuevoEmpleado.fIngreso.anio);

            mostrarSectores(sectores,sectorLenght);
            printf("Ingrese el ID del sector: \n");
            // VALIDAR ID SECTOR (SI EL ID ES VALIDO O NO)
            scanf("%d",&idSector);

            nuevoEmpleado.idSector=idSector;
            nuevoEmpleado.legajo=*pLegajo;
            (*pLegajo)++;    // *pLegajo=*pLegajo+1;
            nuevoEmpleado.isEmpty=0;
            lista[indice]=nuevoEmpleado;
            function_success=1;
        }
    }
    return function_success;
}


int buscarLibre(sEmpleado lista[], int nominaLength)
{
    int indice=-1;
    for (int i=0; i<nominaLength;i++){
        if(lista[i].isEmpty){
            indice=i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(sEmpleado lista[], int nominaLength, int legajo)
{
    int indice=-1;
    for (int i=0; i<nominaLength;i++){
        if(lista[i].legajo==legajo && lista[i].isEmpty==0){
            indice=i;
            break;
        }
    }
    return indice;
}

int bajaEmpleado(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int function_success=0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("        Baja Empleado\n");
    mostrarEmpleados(lista, nominaLength, sectores, sectorLength);
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice=buscarEmpleado(lista,nominaLength,legajo);

    if(indice==-1){
        printf("No hay ningun empleado registrado con el legajo %d\n", legajo);
    }
    else{
       mostrarEmpleado(lista[indice], sectores, sectorLength);
       printf("Confirma baja? s/n ");
       fflush(stdin);
       scanf("%c", &confirma);
       if(confirma=='s'){
        lista[indice].isEmpty=1;
        function_success=1;
       }
       else{
        printf("Baja cancelada\n");
       }
    }
    return function_success;
}
