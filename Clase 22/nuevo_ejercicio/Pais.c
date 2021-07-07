#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pais.h"
#include "LinkedList.h"
#include "utn_validaciones.h"

ePais* pais_new()
{
    ePais* newPais=(ePais*)malloc(sizeof(ePais));

    if(newPais!=NULL){
        newPais->id=0;
        strcpy(newPais->nombre," ");
        newPais->recuperados=0;
        newPais->infectados=0;
        newPais->muertos=0;
    }
    return newPais;
}

ePais* pais_newParams(char* idStr, char* nombreStr, char* recuperadosStr, char* infectadosStr, char* muertosStr)
{
    ePais* newPais=(ePais*)malloc(sizeof(ePais));

    if(newPais!=NULL){
        if(!(!pais_setId(newPais,atoi(idStr)) &&
             !pais_setNombre(newPais,nombreStr) &&
             !pais_setRecuperados(newPais,atoi(recuperadosStr)) &&
             !pais_setInfectados(newPais,atoi(infectadosStr)) &&
             !pais_setMuertos(newPais,atoi(muertosStr)))){
                pais_delete(newPais);
                newPais=NULL;
        }
    }
    return newPais;
}

void pais_delete(ePais* this)
{
    if(this!=NULL){
        free(this);
    }
}

int pais_setId(ePais* this,int id)
{
    int response=-1;
    if(this!=NULL && id>=0){
        this->id=id;
        response=0;
    }
    return response;
}

int pais_getId(ePais* this,int* id)
{
    int response=-1;

    if(this!=NULL && id!=NULL){
        *id=this->id;
        response=0;
    }
    return response;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        if(esNombre(nombre,128)){
            strncpy(this->nombre,nombre,128);
            response=0;
        }
    }
    return response;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        strncpy(nombre,this->nombre,128);
        response=0;
    }
    return response;
}

int pais_setRecuperados(ePais* this,int recuperados)
{
    int response=-1;
    if(this!=NULL && recuperados>=0){
        this->recuperados=recuperados;
        response=0;
    }
    return response;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int response=-1;

    if(this!=NULL && recuperados!=NULL){
        *recuperados=this->recuperados;
        response=0;
    }
    return response;
}

int pais_setInfectados(ePais* this,int infectados)
{
    int response=-1;
    if(this!=NULL && infectados>=0){
        this->infectados=infectados;
        response=0;
    }
    return response;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int response=-1;

    if(this!=NULL && infectados!=NULL){
        *infectados=this->infectados;
        response=0;
    }
    return response;
}

int pais_setMuertos(ePais* this,int muertos)
{
    int response=-1;
    if(this!=NULL && muertos>=0){
        this->muertos=muertos;
        response=0;
    }
    return response;
}

int pais_getMuertos(ePais* this,int* muertos)
{
    int response=-1;

    if(this!=NULL && muertos!=NULL){
        *muertos=this->muertos;
        response=0;
    }
    return response;
}

int pais_printPais(ePais* pPais)
{
    int response=-1;

    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;

    if(pPais!=NULL &&
       !pais_getId(pPais, &id) &&
       !pais_getNombre(pPais, nombre) &&
       !pais_getRecuperados(pPais, &recuperados)&&
       !pais_getInfectados(pPais, &infectados) &&
       !pais_getMuertos(pPais, &muertos)){
            printf("%d %10s %d %d %d\n",id,nombre,recuperados,infectados,muertos);
             response=0;
    }
    return response;
}

int randomRecuperados(void)
{
    int random;
    random=rand()%(1000000+50000);
    return random;
}

int randomInfectados(void)
{
    int random;
    random=rand()%(2000000+40000);

    return random;
}
int randomMuertos(void)
{
    int random;
    random=rand()%(50000+1000);
    return random;
}

void loadRandomRecuperados(void* pElement)
{
    int random=randomRecuperados();
    ePais* auxiliar;

    if(pElement!=NULL)
    {
        auxiliar=(ePais*)pElement;
        auxiliar->recuperados=random;
        pElement=auxiliar;
    }
}

void loadRandomInfectados(void* pElement)
{
    int random=randomInfectados();
    ePais* auxiliar;

    if(pElement!=NULL)
    {
        auxiliar=(ePais*)pElement;
        auxiliar->infectados=random;
        pElement=auxiliar;
    }
}

void loadRandomMuertos(void* pElement)
{
    int random=randomMuertos();
    ePais* auxiliar;

    if(pElement!=NULL)
    {
        auxiliar=(ePais*)pElement;
        auxiliar->muertos=random;
        pElement=auxiliar;
    }
}

