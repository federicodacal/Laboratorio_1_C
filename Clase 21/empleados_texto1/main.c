#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

Empleado* newEmpleadoParamCadenas(char* strId, char* strNombre, char* strSexo, char* strSueldo);

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
    int len=1;

    int cant;
//    int auxInt;
//    char auxCad[100];
//    char auxChar;
//    float auxFloat;
//    char auxCadena[100];

    char auxBuffer[4][20];

    int index;
    int flag=0;

    Empleado* auxEmpleado=NULL;
    Empleado** list = (Empleado**)malloc(sizeof(Empleado*)*len);

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

    FILE* f=fopen("MOCK_DATA.csv", "r");

    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    // fscanf(f,"%s\n",auxCadena); // Lectura fantasma para saltear encabezado
    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3]);

    // Itero sobre cada fila o renglon de caracteres del archivo
    while(!feof(f)){

        buscarLibreEmpleado(list,len,&index);
        if(index==-1){
            if(agrandarLista(&list,&len)==-1){
                flag=1; // No pudo agrandar lista
                break;
            }
        }
        else{
            // Leo y parseo una fila o renglon del archivo
            //cant=fscanf(f,"%d,%[^,],%c,%f\n",&auxInt,auxCad,&auxChar,&auxFloat);
            cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3]);

            if(cant==4){
                // Creo un empleado con el constructor
                //auxEmpleado=newEmpleadoParam(auxInt,auxCad,tolower(auxChar),auxFloat);
                auxEmpleado=newEmpleadoParamCadenas(auxBuffer[0],auxBuffer[1],auxBuffer[2],auxBuffer[3]);
                if(auxEmpleado!=NULL){
                    *(list+index)=auxEmpleado;
                    auxEmpleado=NULL;
                }
                else{
                    flag=2; // No pudo crear empleado
                    break;
                }
            }
            else{
                flag=3; // No se pudo leer empleado
                break;
            }
        }
    }

    if(flag==0){
        printf("Empleados cargados correctamente\n");
    }
    else if(flag==1){
        printf("Problema para cosneguir lugar\n");
    }
    else if(flag==2){
        printf("No se pudo crear empleado\n");
    }
    else if(flag==3){
        printf("No se pudo leer empleado\n");
    }

    fclose(f);

    mostrarEmpleados(list,len);

    f=fopen("MOCK_DATA2.csv", "w");

    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    fprintf(f,"id,nombre,sexo,sueldo\n");

    for(int i=0;i<len;i++){
        auxEmpleado=*(list+i);
        if(auxEmpleado!=NULL){
            fprintf(f,"%d,%s,%c,%.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->sexo,auxEmpleado->sueldo);
        }
        auxEmpleado=NULL;
    }

    fclose(f);

    free(list);

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

Empleado* newEmpleadoParamCadenas(char* strId, char* strNombre, char* strSexo, char* strSueldo)
{
    Empleado* nuevoEmpleado=newEmpleado();
    if(nuevoEmpleado!=NULL){
          if(!(!empleadoSetId(nuevoEmpleado, atoi(strId)) &&
             !empleadoSetNombre(nuevoEmpleado, strNombre) &&
             !empleadoSetSexo(nuevoEmpleado, strSexo[0]) &&
             !empleadoSetSueldo(nuevoEmpleado, atof(strSueldo)))
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

    if(emp!=NULL && (sexo=='f' || sexo=='m' || sexo=='M' || sexo=='F')){
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
