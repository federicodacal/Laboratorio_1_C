#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
}Empleado;

int mostrarEmpleado(Empleado* pEmp);
int mostrarEmpleados(Empleado** list, int len);

int agrandarLista(Empleado*** list, int* pLen);

int ordenarEmpleados(Empleado** list, int len);

Empleado* newEmpleado();

Empleado* newEmpleadoParam(int id, char* nombre, char sexo, float sueldo);

int empleadoSetId(Empleado* emp, int id);
int empleadoSetNombre(Empleado* emp, char* nombre);
int empleadoSetSexo(Empleado* emp, char sexo);
int empleadoSetSueldo(Empleado* emp, float sueldo);

int empleadoGetId(Empleado* emp, int* pId);
int empleadoGetNombre(Empleado* emp, char* pNombre);
int empleadoGetSexo(Empleado* emp, char* pSexo);
int empleadoGetSueldo(Empleado* emp, float* pSueldo);

void destroyEmpleado(Empleado* pEmp);

int inicializarEmpleados(Empleado** lista, int len);
int buscarLibreEmpleado(Empleado** lista, int len, int* pIndex);

int main()
{
    int len=3;
    int index;
    int id;
    char nombre[20];
    char sexo;
    float sueldo;

    Empleado* auxEmpleado=NULL;
    Empleado** list = (Empleado**)malloc(sizeof(Empleado*)*len);    // Pido espacio para 3 variables Estructuras de tipo Empleado

    if(list==NULL){
        printf("No se consiguio espacio para lista\n");
        system("pause");
        exit(1);
    }
    else{
        if(!inicializarEmpleados(list,len)){
           printf("Inicializacion correcta\n");
           }
    }

    buscarLibreEmpleado(list, len, &index);
    printf("Indice: %d\n", index);

    auxEmpleado=newEmpleado();

    printf("Ingrese id: ");
    scanf("%d", &id);
    while(!(!empleadoSetId(auxEmpleado,id))){
        printf("ID Invalido\nReingrese id: ");
        scanf("%d", &id);
    }

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    while(!(!empleadoSetNombre(auxEmpleado,nombre))){
        printf("Nombre Invalido\nReingrese nombre: ");
        fflush(stdin);
        gets(nombre);
    }

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c",&sexo);
    while(!(!empleadoSetSexo(auxEmpleado,sexo))){
        printf("Sexo Invalido\nReingrese sexo: ");
        fflush(stdin);
        scanf("%c",&sexo);
    }

    printf("Ingrese sueldo: ");
    scanf("%f", &sueldo);
    while(!(!empleadoSetSueldo(auxEmpleado,sueldo))){
        printf("Sueldo Invalido\nReingrese sueldo: ");
        scanf("%f", &sueldo);
    }

    *(list+index)=auxEmpleado;
    mostrarEmpleados(list,len);

    buscarLibreEmpleado(list, len, &index);
    printf("Indice: %d\n", index);
    *(list+index)=newEmpleadoParam(1000,"Juan",'m',450);
    mostrarEmpleados(list,len);

    buscarLibreEmpleado(list, len, &index);
    printf("Indice: %d\n", index);
    *(list+index)=newEmpleadoParam(1020,"Juana",'f',470);
    mostrarEmpleados(list,len);

    buscarLibreEmpleado(list, len, &index);

    if(index==-1){
        printf("No hay mas lugar\n");
    }

    printf("Agrandar array: \n");
    if(!agrandarLista(&list, &len)){
        printf("Lista redimensionada\n");
        buscarLibreEmpleado(list, len, &index);
        printf("Indice: %d\n", index);
        *(list+index)=newEmpleadoParam(1024,"Ana",'f',400);
        mostrarEmpleados(list,len);
    }

    ordenarEmpleados(list,len);
    mostrarEmpleados(list,len);

    free(list); // Libera vector de punteros
    return 0;
}

int inicializarEmpleados(Empleado** lista, int len)
{
    int response=-1;

    if(lista!=NULL && len>0){
        for(int i=0;i<len;i++){
            //lista[i]=NULL;
            *(lista+i)=NULL;
        }
        response=0;
    }

    return response;
}

int buscarLibreEmpleado(Empleado** lista, int len, int* pIndex)
{
    int response=-1;

    if(lista!=NULL && len>0 && pIndex!=NULL){
        *pIndex=-1;
        for(int i=0;i<len;i++){
            if(*(lista+i)==NULL){
                *pIndex=i;
                break;
            }
        }
        response=0;
    }

    return response;
}

int mostrarEmpleado(Empleado* pEmp)
{
    int response=-1;

    int id;
    char nombre[20];
    char sexo;
    float sueldo;

    if(pEmp!=NULL &&
       !empleadoGetId(pEmp, &id) &&
       !empleadoGetNombre(pEmp, nombre) &&
       !empleadoGetSexo(pEmp, &sexo)&&
       !empleadoGetSueldo(pEmp, &sueldo)){
            printf(" %d %10s %c $%.2f\n",
               id,
               nombre,
               sexo,
               sueldo);
             response=0;
    }
    return response;
}

int mostrarEmpleados(Empleado** list, int len)
{
    int response=-1;

    if(list!=NULL && len>0){
        printf("ID NOMBRE SEXO SUELDO\n");
        for(int i=0;i<len;i++){
            mostrarEmpleado(*(list+i));
        }
        printf("\n");
        response=0;
    }
    return response;
}

// Funcion que permite conseguir espacio en memoria para la estructura y devuelve el puntero hacia esa estructura, ademas inicializa los campos de las estructura
Empleado* newEmpleado()
{
    Empleado* auxEmpleado=(Empleado*)malloc(sizeof(Empleado));

    if(auxEmpleado!=NULL){
        auxEmpleado->id=0;
        strcpy(auxEmpleado->nombre,"");
        auxEmpleado->sexo=' ';
        auxEmpleado->sueldo=0;
    }
    return auxEmpleado;
}

void destroyEmpleado(Empleado* pEmp)
{
    free(pEmp);
}

// Funcion que permite conseguir espacio en memoria para la estructura y devuelve el puntero hacia esa estructura, ademas carga la estructura con los parametros
Empleado* newEmpleadoParam(int id, char* nombre, char sexo, float sueldo)
{
    Empleado* nuevoEmpleado=newEmpleado();
    if(nuevoEmpleado!=NULL){
//        nuevoEmpleado->id=id;
//        strcpy(nuevoEmpleado->nombre,nombre);
//        nuevoEmpleado->sexo=sexo;
//        nuevoEmpleado->sueldo=sueldo;
          if(!(!empleadoSetId(nuevoEmpleado, id) &&
             !empleadoSetNombre(nuevoEmpleado, nombre) &&
             !empleadoSetSexo(nuevoEmpleado, sexo) &&
             !empleadoSetSueldo(nuevoEmpleado, sueldo))
             ){
                destroyEmpleado(nuevoEmpleado);
                nuevoEmpleado=NULL;
             }
    }

    return nuevoEmpleado;
}

int empleadoSetId(Empleado* emp, int id)
{
    int response=-1;

    if(emp!=NULL && id>0){
        emp->id=id;
        response=0;
    }
    return response;
}

int empleadoSetNombre(Empleado* emp, char* nombre)
{
    int response=-1;

    if(emp!=NULL && nombre!=NULL && strlen(nombre)<20){
        strcpy(emp->nombre,nombre);
        response=0;
    }
    return response;
}

int empleadoSetSexo(Empleado* emp, char sexo)
{
    int response=-1;

    if(emp!=NULL && (sexo=='f' || sexo=='m')){
        emp->sexo=sexo;
        response=0;
    }
    return response;
}

int empleadoSetSueldo(Empleado* emp, float sueldo)
{
    int response=-1;

    if(emp!=NULL && sueldo>0){
        emp->sueldo=sueldo;
        response=0;
    }
    return response;
}

int empleadoGetId(Empleado* emp, int* pId)
{
    int response=-1;

    if(emp!=NULL && pId!=NULL){
        *pId=emp->id;
        response=0;
    }
    return response;
}

int empleadoGetNombre(Empleado* emp, char* pNombre)
{
    int response=-1;

    if(emp!=NULL && pNombre!=NULL){
        strcpy(pNombre,emp->nombre);
        response=0;
    }
    return response;
}

int empleadoGetSexo(Empleado* emp, char* pSexo)
{
    int response=-1;

    if(emp!=NULL && pSexo!=NULL){
        *pSexo=emp->sexo;
        response=0;
    }
    return response;
}

int empleadoGetSueldo(Empleado* emp, float* pSueldo)
{
    int response=-1;

    if(emp!=NULL && pSueldo!=NULL){
        *pSueldo=emp->sueldo;
        response=0;
    }
    return response;
}

int agrandarLista(Empleado*** list, int* pLen)
{
    int response=-1;
    Empleado** aux;

    if(list!=NULL && pLen!=NULL){
        int len=*pLen+1;
        aux=(Empleado**)realloc(*list,sizeof(Empleado*)*len);
        if(aux!=NULL){
            *list=aux;
            aux=NULL;
            *pLen=len;
            *(*list+len-1)=NULL;
            response=0;
        }
    }

    return response;
}

int ordenarEmpleados(Empleado** list, int len)
{
    int response=-1;
    Empleado* aux=NULL;
    if(list!=NULL && len>0){
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(*(list+i)!=NULL && *(list+j)!=NULL){
                    if(strcmp((*(list+i))->nombre,(*(list+j))->nombre)>0){
                        aux=*(list+i);
                        *(list+i)=*(list+j);
                        *(list+j)=aux;
                    }
                }
            }
        }

        response=0;
    }

    return response;
}
