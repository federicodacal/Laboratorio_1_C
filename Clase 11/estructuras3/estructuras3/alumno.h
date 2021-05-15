#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct
{
    int legajo;
    char nombre[50];
    float altura;
    int isEmpty;
}sAlumno;

int imprimirAlumnos(sAlumno* alumnos, int alumnosLength);
int inicializarAlumnos(sAlumno* alumnos, int alumnosLength);

#endif // ALUMNO_H_INCLUDED
