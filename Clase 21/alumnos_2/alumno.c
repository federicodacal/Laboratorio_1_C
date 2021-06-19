#include <ctype.h>
#include "alumno.h"
#include "utn_validaciones.h"

Alumno* alumno_new(void)
{
    Alumno* auxP=NULL;
    auxP=(Alumno*)malloc(sizeof(Alumno)*1);

    return auxP;

    // return (Alumno*)malloc(sizeof(Alumno));
}

//Alumno* alumno_newParams(char* nombre, float altura, int id)
//{
//    Alumno* ptrAlumno=NULL;
//    ptrAlumno=alumno_new();
//    if(ptrAlumno!=NULL){
//        strcpy(ptrAlumno->nombre,nombre);
//        ptrAlumno->altura=altura;
//        ptrAlumno->id=id;
//    }
//    return ptrAlumno;
//}

Alumno* alumno_newParams(char* nombre, float altura, int id)
{
    Alumno* this=NULL;
    this=alumno_new();
    if(this!=NULL && nombre!=NULL){
        if(alumno_setNombre(this,nombre)==-1 &&
           alumno_setId(this,id)==-1 &&
           alumno_setAltura(this,altura)==-1){
                alumno_delete(this);
                this=NULL;
           }
    }
    return this;
}

Alumno* alumno_newParamsTxt(char* nombre, char* altura, char* id)
{
    Alumno* this=NULL;
    this=alumno_new();
    if(this!=NULL && altura!=NULL && id!=NULL){
        if(alumno_setNombre(this,nombre)==-1 &&
           alumno_setIdTxt(this,id)==-1 &&
           alumno_setAlturaTxt(this,altura)==-1){
                alumno_delete(this);
                this=NULL;
           }
    }
    return this;
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
    Alumno* pAuxAlumno;

    if(arrayPtr!=NULL && len>0 && nombre!=NULL && id>=0){
        freeIndex=alumno_buscarLibre(arrayPtr,len);
        if(freeIndex>=0){
            pAuxAlumno=alumno_newParams(nombre,altura,id);
            if(pAuxAlumno!=NULL){
                arrayPtr[freeIndex]=pAuxAlumno;
                response=freeIndex;
            }
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
        if(esNombre(nombre,20)){
            strncpy(this->nombre,nombre,20);
            response=0;
        }
    }

    return response;
}

int alumno_setAltura(Alumno* this, float altura)
{
    int response=-1;

    if(this!=NULL && altura>0){
        this->altura=altura;
        response=0;
    }

    return response;
}

int alumno_setAlturaTxt(Alumno* this, char* altura)
{
    int response=-1;
    float auxAltura;

    if(this!=NULL && altura!=NULL){
        if(esFlotante(altura)){
            auxAltura=atof(altura);
            if(auxAltura>=0){
                this->altura=auxAltura;
                response=0;
            }
        }
    }

    return response;
}

int alumno_getAltura(Alumno* this, float* altura)
{
    int response=-1;

    if(this!=NULL && altura!=NULL){
        *altura=this->altura;
        response=0;
    }

    return response;
}

int alumno_getNombre(Alumno* this, char* nombre)
{
    int response=-1;

    if(this!=NULL && nombre!=NULL){
        strncpy(nombre,this->nombre,20);
        response=0;
    }

    return response;
}

int alumno_ordenarArray(Alumno* arrayPtr[], int len)
{
    int response=-1;
    int flagSwap;
    Alumno* auxAlumno;

    if(arrayPtr!=NULL && len>0){
        do{
            flagSwap=0;
            for(int i=0;i<len-1;i++){
                if(arrayPtr[i]!=NULL &&
                   arrayPtr[i+1]!=NULL &&
                   strcmp(arrayPtr[i]->nombre,arrayPtr[i+1]->nombre)>0){
                    auxAlumno=arrayPtr[i];
                    arrayPtr[i]=arrayPtr[i+1];
                    arrayPtr[i+1]=auxAlumno;
                    flagSwap=1;
                }
            }
        }while(flagSwap);

        response=0;
    }
    return response;
}

int alumno_promedioAltura(Alumno* arrayPtr[], int len, float* promedio)
{
    int response=-1;
    int cantidadAlumnos=0;
    float acumuladorAltura=0;

    if(arrayPtr!=NULL && len>0 && promedio!=NULL){
        for(int i=0;i<len;i++){
            if(arrayPtr[i]!=NULL){
                cantidadAlumnos++;
                acumuladorAltura+=arrayPtr[i]->altura;
            }
        }
        *promedio=acumuladorAltura/cantidadAlumnos;
    }
    return response;
}

int alumno_calcularMayorAltura(Alumno* arrayPtr[], int len, int* index)
{
    int response=-1;
    int indexMaximo;
    float alturaMaxima;
    int flag=0;

    if(arrayPtr!=NULL && len>0 && index!=NULL){
        response=0;
        for(int i=0;i<len;i++){
            if(arrayPtr[i]!=NULL){
                if(flag==0){
                    indexMaximo=i;
                    alturaMaxima=arrayPtr[i]->altura;
                    flag=1;
                }
            }
            else if(arrayPtr[i]->altura > alturaMaxima){
                indexMaximo=i;
                alturaMaxima=arrayPtr[i]->altura;
            }
        }
        *index=indexMaximo;
    }
    return response;
}

int alumno_salvarArray(Alumno* arrayPtr[], int len, char* path)
{
    int response=-1;
    int auxId;
    char auxNombre[20];
    float auxAltura;

    FILE* fpArchivo;

    if(arrayPtr!=NULL && len>0 && path!=NULL){
        fpArchivo=fopen(path,"w");
        if(fpArchivo!=NULL){
            response=0;
            for(int i=0;i<len;i++){
                if(arrayPtr[i]!=NULL){
                    if(!alumno_getId(arrayPtr[i],&auxId) &&
                       !alumno_getNombre(arrayPtr[i],auxNombre) &&
                       !alumno_getAltura(arrayPtr[i],&auxAltura)){

                            fprintf(fpArchivo,"%d,%s,%f\n",auxId,auxNombre,auxAltura);

                       }
                }
            }
            fclose(fpArchivo);
        }
    }
    return response;
}

int alumno_setIdTxt(Alumno* this, char* id)
{
    int response=-1;
    if(this!=NULL && id!=NULL){
        if(esNumerica(id,10)){
            this->id=atoi(id);
            response=0;
        }
    }
    return response;
}

int alumno_setId(Alumno* this,int id)
{
    int response=-1;
    if(this!=NULL && id>=0){
        this->id=id;
        response=0;
    }
    return response;
}

int alumno_getIdTxt(Alumno* this, char* id)
{
    int response=-1;

    if(this!=NULL && id!=NULL){
        sprintf(id,"%d",this->id);
        response=0;
    }
    return response;
}

int alumno_getId(Alumno* this, int* id)
{
    int response=-1;

    if(this!=NULL && id!=NULL){
        *id=this->id;
        response=0;
    }
    return response;
}

int alumno_leerArrayEnArchivo(Alumno* arrayPunteros[],int len, char* path, int* nextId)
{
    int response=-1;

    FILE* fpArchivo;
    char auxId[4096];
    char auxNombre[4096];
    char auxAltura[4096];

    if(arrayPunteros!=NULL && len>0 && path!=NULL){
        fpArchivo=fopen(path,"r");
        if(fpArchivo!=NULL){
            do{
                if(fscanf(fpArchivo,"%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxAltura)==3){
                    printf("%s-%s-%s",auxId,auxNombre,auxAltura);
                    if(alumno_agregarAlumnoTxt(arrayPunteros,len,auxNombre,auxAltura,auxId)>=0){
                        printf("ALTA OK\n");
                        if(atoi(auxId)>=*nextId){
                            *nextId=atoi(auxId)+1;
                        }
                    }
                }
                response=0;

            }while(!feof(fpArchivo));
            fclose(fpArchivo);
        }
    }
    return response;
}

int alumno_agregarAlumnoTxt(Alumno* arrayPtr[], int len, char* nombre, char* altura, char* id)
{
    int response=-1;
    int freeIndex;
    Alumno* pAuxAlumno;

    if(arrayPtr!=NULL && len>0 && nombre!=NULL && id!=NULL && altura!=NULL){
        freeIndex=alumno_buscarLibre(arrayPtr,len);
        if(freeIndex>=0){
            pAuxAlumno=alumno_newParamsTxt(nombre,altura,id);
            if(pAuxAlumno!=NULL){
                arrayPtr[freeIndex]=pAuxAlumno;
                response=freeIndex;
            }
        }
    }
    return response;
}
