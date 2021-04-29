#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Empleado.h"

void mostrarEmpleado(sEmpleado unEmpleado)
{
    printf("%d     %10s      %d      %c      %9.2f      %02d/%02d/%02d\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fIngreso.dia,
           unEmpleado.fIngreso.mes,
           unEmpleado.fIngreso.anio
           );
}

void mostrarEmpleados(sEmpleado lista[], int nominaLength)
{
    int flag=1;
    printf("\t*****LISTADO DE EMPLEADOS******\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Legajo      Nombre      Edad   Sexo      Sueldo      Fecha Ingreso\n");
    for(int i=0;i<nominaLength;i++){
        if(!lista[i].isEmpty){
            mostrarEmpleado(lista[i]);
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
