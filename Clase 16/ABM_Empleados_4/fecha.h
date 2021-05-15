#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int anio;
}sFecha;

int compararFechas(sFecha f1, sFecha f2);

#endif // FECHA_H_INCLUDED
