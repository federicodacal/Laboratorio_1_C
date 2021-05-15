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
void totalAlmuerzosSector(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sSector sectores[], int sectorLength, sEmpleado lista[], int nominaLength);
void milanesasPorSector(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sSector sectores[], int sectorLength, sEmpleado lista[], int nominaLength);
void sectorMasMilanesas(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sSector sectores[], int sectorLength, sEmpleado lista[], int nominaLength);
void listarTotalComidasFecha(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength);
void ingresoPorComidas(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength);
#endif // INFORMES_H_INCLUDED
