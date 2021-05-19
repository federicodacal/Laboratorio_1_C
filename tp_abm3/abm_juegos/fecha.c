#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"

int compararFechas(sFecha f1, sFecha f2)
{
    int esIgual=0;

    if(f1.dia==f2.dia && f1.mes==f2.mes && f1.anio==f2.anio){
        esIgual=1;
    }
    return esIgual;
}
