#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
}Empleado;

int mostrarEmpleado(Empleado* pEmp); // Por Referencia

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

int main()
{
    Empleado* emp1=(Empleado*)malloc(sizeof(Empleado));
    Empleado* emp2= newEmpleado();

    if(emp1==NULL){
        printf("No se pudo conseguir memoria\n");
        system("pause");
        exit(1);
    }
    else{
        printf("\nIngrese id: ");
        scanf("%d", &emp1->id);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(emp1->nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &emp1->sexo);
        printf("Ingrese sueldo: $");
        scanf("%f", &emp1->sueldo);
    }

    Empleado* emp3=newEmpleadoParam(1111,"Jose",'m',4500);

    mostrarEmpleado(emp1);
    mostrarEmpleado(emp2);
    mostrarEmpleado(emp3);

    free(emp1);
    destroyEmpleado(emp2);
    return 0;
}

int mostrarEmpleado(Empleado* pEmp) // Por Referencia
{
    int response=-1;
    if(pEmp!=NULL){
        printf("\nID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",
               pEmp->id,
               pEmp->nombre,
               pEmp->sexo,
               pEmp->sueldo);
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
        gets(pNombre);
        strcpy(emp->nombre,pNombre);
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

