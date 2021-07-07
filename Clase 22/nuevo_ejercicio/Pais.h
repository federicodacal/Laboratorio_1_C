#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
}ePais;

ePais* pais_new();
ePais* pais_newParams(char* idStr, char* nombreStr, char* recuperadosStr, char* infectadosStr, char* muertosStr);
void pais_delete(ePais* this);
int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setRecuperados(ePais* this,int recuperados);
int pais_getRecuperados(ePais* this,int* recuperados);
int pais_setInfectados(ePais* this,int infectados);
int pais_getInfectados(ePais* this,int* infectados);
int pais_setMuertos(ePais* this,int muertos);
int pais_getMuertos(ePais* this,int* muertos);
int pais_printPais(ePais* pPais);


int randomRecuperados(void);
int randomInfectados(void);
int randomMuertos(void);
void loadRandomRecuperados(void* pElement);
void loadRandomInfectados(void* pElement);
void loadRandomMuertos(void* pElement);

#endif // PAIS_H_INCLUDED
