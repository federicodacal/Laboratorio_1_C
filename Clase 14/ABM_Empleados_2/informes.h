#include "Empleado.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void listarEmpleadosSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void listarEmpleadosCadaSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void totalSueldoSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void totalADepositar(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);
void sectorMayorSueldo(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength);

#endif // INFORMES_H_INCLUDED
