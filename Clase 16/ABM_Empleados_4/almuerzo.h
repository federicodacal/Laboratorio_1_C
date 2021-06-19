#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

#include "fecha.h"
#include "comida.h"
#include "Empleado.h"

typedef struct{
    int id;
    int idComida;
    int legajoEmpleado;
    sFecha fecha;
    int isEmpty;
}sAlmuerzo;

int altaAlmuerzo(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength, int* pNextId);
void mostrarAlmuerzos(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength);
void mostrarAlmuerzo(sAlmuerzo unAlmuerzo, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength);
int buscarLibreAlmuerzo(sAlmuerzo almuerzos[], int almuerzosLength);
void inicializarAlmuerzos(sAlmuerzo almuerzos[], int almuerzosLength);
#endif // ALMUERZO_H_INCLUDED
