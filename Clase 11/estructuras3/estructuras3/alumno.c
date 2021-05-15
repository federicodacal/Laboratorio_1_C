#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"

int imprimirAlumnos(sAlumno* alumnos, int alumnosLength)
{
    int retorno=-1;

    if(alumnos!=NULL && alumnosLength>0){
        for(int i=0;i<alumnosLength;i++){
            if(alumnos[i].isEmpty==0){
                printf("Nombre: %s - Legajo: %d - Altura: %.2f\n", alumnos[i].nombre, alumnos[i].legajo, alumnos[i].altura);
            }
        }
        retorno=0;
    }
    return retorno;
}

int inicializarAlumnos(sAlumno* alumnos, int alumnosLength)
{
    int retorno=-1;

    if(alumnos!=NULL && alumnosLength>0){
        for(int i=0;i<alumnosLength;i++){
            alumnos[i].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}
