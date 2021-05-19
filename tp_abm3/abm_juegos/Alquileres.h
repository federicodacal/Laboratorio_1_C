#include "fecha.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int alquilerId;
    int juegoId;
    int clienteId;
    sFecha fechaAlquiler;
}Alquileres;

#endif // ALQUILERES_H_INCLUDED
