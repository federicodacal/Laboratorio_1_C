#include "Empleado.h"
#include "almuerzo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void listarEmpleadosSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void listarEmpleadosCadaSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void totalSueldoSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void totalADepositar(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void sectorMayorSueldo(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void almuerzosEmpleado(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void totalAlmuerzosEmpleado(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);

#endif // INFORMES_H_INCLUDED
