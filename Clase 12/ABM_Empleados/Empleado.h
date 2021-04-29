#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}sFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    sFecha fIngreso;
    int isEmpty;
}sEmpleado;

void mostrarEmpleado(sEmpleado unEmpleado);
void mostrarEmpleados(sEmpleado lista[], int nominaLength);
void ordenarEmpleados(sEmpleado lista[], int nominaLength);

#endif // EMPLEADO_H_INCLUDED

