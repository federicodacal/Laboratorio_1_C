#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED

int getNumber(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif // VALIDACION_H_INCLUDED
