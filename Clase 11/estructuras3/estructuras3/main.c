#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#define QTY_ALUMNOS 100

int main()
{
    sAlumno unAlumno;
    sAlumno Alumnos[QTY_ALUMNOS];

    unAlumno.altura=2.02;
    unAlumno.legajo=99;
    strcpy(unAlumno.nombre,"Juan Carlos");
    unAlumno.isEmpty=0;

    printf("Nombre: %s - Legajo: %d - Altura: %.2f\n", unAlumno.nombre, unAlumno.legajo, unAlumno.altura);

    Alumnos[15]=unAlumno;

    printf("Nombre: %s - Legajo: %d - Altura: %.2f\n", Alumnos[15].nombre, Alumnos[15].legajo, Alumnos[15].altura);
    printf("\n");
    inicializarAlumnos(Alumnos,QTY_ALUMNOS);

    Alumnos[20]=unAlumno;
    Alumnos[25]=unAlumno;

    imprimirAlumnos(Alumnos,QTY_ALUMNOS);


    return 0;
}
