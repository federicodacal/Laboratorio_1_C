#include "fecha.h"
#include "Empleado.h"
#include "almuerzo.h"
#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

int hcodearEmpleados(sEmpleado lista[], int nominaLength, int cant, int* pLegajo);
int hcodearAlmuerzos(sAlmuerzo almuerzos[], int almuerzosLength, int cant, int* pId);

#endif // DATAWAREHOUSE_H_INCLUDED
