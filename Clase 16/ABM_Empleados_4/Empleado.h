#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "sector.h"
#include "fecha.h"

typedef struct{
    int legajo; // Primary Key
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    sFecha fIngreso;
    int idSector; // Foreign Key
    int isEmpty;
}sEmpleado;

void mostrarEmpleado(sEmpleado unEmpleado, sSector sectores[], int sectorLength);
void mostrarEmpleados(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void ordenarEmpleados(sEmpleado lista[], int nominaLength);
int altaEmpleado(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLenght, int* pLegajo);
int bajaEmpleado(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
int buscarLibre(sEmpleado lista[], int nominaLength);
int buscarEmpleado(sEmpleado lista[], int nominaLength, int legajo);
void inicializarEmpleados(sEmpleado lista[], int nominaLength);
int cargarNombreEmpleado(int legajo, sEmpleado lista[], int nominaLength, char nombre[]);
#endif // EMPLEADO_H_INCLUDED

