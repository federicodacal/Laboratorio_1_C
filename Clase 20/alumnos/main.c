#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALUMNOS_LEN 100

typedef struct{
    char nombre[20];
    float altura;
    int id;
}Alumno;

Alumno* alumno_new(void)
{
    Alumno* auxP=NULL;
    auxP=(Alumno*)malloc(sizeof(Alumno)*1);

    return auxP;

    // return (Alumno*)malloc(sizeof(Alumno));
}

Alumno* alumno_newParams(char* nombre, float altura, int id)
{
    Alumno* ptrAlumno=NULL;
    ptrAlumno=alumno_new();
    if(ptrAlumno!=NULL){
        strcpy(ptrAlumno->nombre,nombre);
        ptrAlumno->altura=altura;
        ptrAlumno->id=id;
    }
    return ptrAlumno;
}

int alumno_initArray(Alumno* arrayPtr[], int len)
{
    int response=-1;

    if(arrayPtr!=NULL && len>0){
        for(int i=0;i<len;i++){
            arrayPtr[i]=NULL;
        }
        response=0;
    }

    return response;
}

void alumno_delete(Alumno* this)
{
    if(this!=NULL){
        free(this);
    }
}

int alumno_deleteIndexArray(Alumno* arrayPtr[], int index, int len)
{
    int response=-1;

    if(arrayPtr!=NULL && index>=0 && arrayPtr[index]!=NULL && index<len){
        alumno_delete(arrayPtr[index]);
        arrayPtr[index]=NULL;
        response=0;
    }

    return response;
}

int alumno_buscarLibre(Alumno* arrayPtr[], int len)
{
    int response=-1;

    if(arrayPtr!=NULL && len>0){
        response=-2;
        for(int i=0;i<len;i++){
            if(arrayPtr[i]==NULL){
                response=i;
                break;
            }
        }
    }
    return response;
}

int alumno_buscarPorId(Alumno* arrayPtr[], int len, int id)
{
    int response=-1;

    if(arrayPtr!=NULL && len>0 && id>=0){
        response=-2;
        for(int i=0;i<len;i++){
            if(arrayPtr[i]!=NULL && arrayPtr[i]->id==id){
                response=i;
                break;
            }
        }
    }
    return response;
}

int alumno_imprimirArray(Alumno* arrayPtr[], int len)
{
    int response=-1;

    if(arrayPtr!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(arrayPtr[i]!=NULL){
                printf("Nombre: %s - ID: %d - Altura %.2f\n",arrayPtr[i]->nombre, arrayPtr[i]->id, arrayPtr[i]->altura);
            }
        }
    }
    return response;
}

int alumno_agregarAlumno(Alumno* arrayPtr[], int len, char* nombre, float altura, int id)
{
    int response=-1;
    int freeIndex;

    if(arrayPtr!=NULL && len>0 && nombre!=NULL && id>=0){
        freeIndex=alumno_buscarLibre(arrayPtr,len);
        if(freeIndex>=0){
            arrayPtr[freeIndex]=alumno_newParams(nombre,altura,id);
            response=0;
        }
    }
    return response;
}

int alumno_removeById(Alumno* arrayPtr[], int len, int id)
{
    int response=-1;
    int indexDelete;

    if(arrayPtr!=NULL && len>0 && id>=0){
        indexDelete=alumno_buscarPorId(arrayPtr,len,id);
        if(indexDelete>=0){
            if(!alumno_deleteIndexArray(arrayPtr,indexDelete,len)){
                response=0;
            }
        }
    }
    return response;
}


int alumno_setNombre(Alumno* this, char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){

    }

    return response;
}

int main()
{
    int index;
    int indexDelete;

    if(!alumno_initArray(arrayPunterosAlumno,ALUMNOS_LEN)){
        printf("INIT OK\n\n");
        index=alumno_buscarLibre(arrayPunterosAlumno,ALUMNOS_LEN);
        if(index>=0){
            arrayPunterosAlumno[index]=alumno_newParams("Juan",1.75,200);
        }

        index=alumno_buscarLibre(arrayPunterosAlumno,ALUMNOS_LEN);
        if(index>=0){
            arrayPunterosAlumno[index]=alumno_newParams("Ana",1.67,201);
        }

        alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);

        indexDelete=alumno_buscarPorId(arrayPunterosAlumno,ALUMNOS_LEN,200);
        if(indexDelete>=0){
            if(!alumno_deleteIndexArray(arrayPunterosAlumno,indexDelete,ALUMNOS_LEN)){
               printf("\nDelete OK\n\n");
               }
        }

        alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);

        if(alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,"Pepe",1.87,300)>=0){
            printf("\nAlta OK\n\n");
        }

        alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);

        if(!alumno_removeById(arrayPunterosAlumno,ALUMNOS_LEN,201)){
            printf("\nDelete OK\n\n");
        }

        alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);
    }


    return 0;
}
