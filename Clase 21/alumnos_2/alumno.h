#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct{
    char nombre[20];
    float altura;
    int id;
}Alumno;

Alumno* alumno_new(void);
Alumno* alumno_newParams(char* nombre, float altura, int id);
int alumno_initArray(Alumno* arrayPtr[], int len);
void alumno_delete(Alumno* this);
int alumno_deleteIndexArray(Alumno* arrayPtr[], int index, int len);
int alumno_buscarLibre(Alumno* arrayPtr[], int len);
int alumno_buscarPorId(Alumno* arrayPtr[], int len, int id);
int alumno_imprimirArray(Alumno* arrayPtr[], int len);
int alumno_agregarAlumno(Alumno* arrayPtr[], int len, char* nombre, float altura, int id);
int alumno_removeById(Alumno* arrayPtr[], int len, int id);
int alumno_setNombre(Alumno* this, char* nombre);
int alumno_getNombre(Alumno* this, char* nombre);
int alumno_setAltura(Alumno* this, float altura);
int alumno_setAlturaTxt(Alumno* this, char* altura);
int alumno_getAltura(Alumno* this, float* altura);
int alumno_setId(Alumno* this,int id);
int alumno_setIdTxt(Alumno* this, char* id);
int alumno_getIdTxt(Alumno* this, char* id);
int alumno_getId(Alumno* this, int* id);
int alumno_ordenarArray(Alumno* arrayPtr[], int len);
int alumno_promedioAltura(Alumno* arrayPtr[], int len, float* promedio);
int alumno_calcularMayorAltura(Alumno* arrayPtr[], int len, int* index);
int alumno_salvarArray(Alumno* arrayPtr[], int len, char* path);
int alumno_agregarAlumnoTxt(Alumno* arrayPtr[], int len, char* nombre, char* altura, char* id);
int alumno_leerArrayEnArchivo(Alumno* arrayPunteros[],int len, char* path, int* nextId);
#endif // ALUMNO_H_INCLUDED
