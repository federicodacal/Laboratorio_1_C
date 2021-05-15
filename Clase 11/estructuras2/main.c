#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define NOMINA_LENGTH 9

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
}sEmpleado;

void mostrarEmpleado(sEmpleado unEmpleado);
void mostrarEmpleados(sEmpleado lista[], int nominaLength);
void ordenarEmpleados(sEmpleado lista[], int nominaLength);
void ordenarEmpleados2(sEmpleado lista[], int nominaLength);
void ordenarEmpleados3(sEmpleado lista[], int nominaLength);

int main()
{
    sEmpleado nomina[NOMINA_LENGTH]={
    {545,"Miguel",32,'m',50000,{26,4,2021}},
    {323,"Jacinto",33,'m',45000,{25,4,2021}},
    {434,"Paula",28,'f',65000,{23,4,2021}},
    {293,"Luis",31,'m',75000,{22,4,2021}},
    {201,"Lucia",28,'f',83000,{21,4,2021}},
    {515,"Roberto",39,'m',54500,{26,3,2021}},
    {333,"Analia",36,'f',45600,{25,3,2021}},
    {134,"Pamela",24,'f',68000,{11,2,2021}},
    {193,"Lionel",25,'m',72100,{4,4,2020}}
    };

    mostrarEmpleados(nomina, NOMINA_LENGTH);
    ordenarEmpleados(nomina, NOMINA_LENGTH);
    mostrarEmpleados(nomina, NOMINA_LENGTH);
    ordenarEmpleados2(nomina, NOMINA_LENGTH);
    mostrarEmpleados(nomina, NOMINA_LENGTH);
    ordenarEmpleados3(nomina, NOMINA_LENGTH);
    mostrarEmpleados(nomina, NOMINA_LENGTH);

//    for(int i=0;i<NOMINA_LENGTH;i++){
//        printf("\nIngrese legajo: ");
//        scanf("%d", &nomina[i].legajo);
//
//        printf("Ingrese nombre: ");
//        fflush(stdin);
//        gets(nomina[i].nombre);
//
//        printf("Ingrese edad: ");
//        scanf("%d", &nomina[i].edad);
//
//        printf("Ingrese sexo: ");
//        fflush(stdin);
//        scanf("%c", &nomina[i].sexo);
//
//        printf("Ingrese sueldo: ");
//        scanf("%f", &nomina[i].sueldo);
//
//        printf("Ingrese fecha de ingreso dd/mm/aaaa: \n");
//        scanf("%d/%d/%d", &nomina[i].fIngreso.dia,&nomina[i].fIngreso.mes,&nomina[i].fIngreso.anio);
//    }
//
//    mostrarEmpleados(sEmpleado nomina, NOMINA_LENGTH);

    return 0;
}

void mostrarEmpleado(sEmpleado unEmpleado)
{
    printf("%d     %10s      %d      %c      %9.2f      %02d/%02d/%02d\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fIngreso.dia,
           unEmpleado.fIngreso.mes,
           unEmpleado.fIngreso.anio
           );
}

void mostrarEmpleados(sEmpleado lista[], int nominaLength)
{
    printf("\t*****LISTADO DE EMPLEADOS******\n");
    printf("-------------------------------------------------------------------------\n");
    printf("Legajo      Nombre      Edad   Sexo      Sueldo      Fecha Ingreso\n");
    for(int i=0;i<nominaLength;i++){
        mostrarEmpleado(lista[i]);
    }
    printf("\n\n");

}

void ordenarEmpleados(sEmpleado lista[], int nominaLength)
{
    sEmpleado auxEmpleado;
    for(int i=0; i<nominaLength-1;i++){
        for(int j=i+1;j<nominaLength;j++){
            if(lista[i].sexo>lista[j].sexo || (lista[i].sexo==lista[j].sexo && strcmpi(lista[i].nombre,lista[j].nombre)>0)){

                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}

void ordenarEmpleados2(sEmpleado lista[], int nominaLength)
{
    sEmpleado auxEmpleado;
    for(int i=0; i<nominaLength-1;i++){
        for(int j=i+1;j<nominaLength;j++){
            if(lista[i].sueldo<lista[j].sueldo || (lista[i].sueldo==lista[j].sueldo && strcmpi(lista[i].nombre,lista[j].nombre)>0)){

                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}

void ordenarEmpleados3(sEmpleado lista[], int nominaLength)
{
    sEmpleado auxEmpleado;
    for(int i=0; i<nominaLength-1;i++){
        for(int j=i+1;j<nominaLength;j++){
            if((lista[i].fIngreso.anio>lista[j].fIngreso.anio
                || (lista[i].fIngreso.anio==lista[j].fIngreso.anio && lista[i].fIngreso.mes>lista[j].fIngreso.mes))
                || (lista[i].fIngreso.anio==lista[j].fIngreso.anio && lista[i].fIngreso.mes==lista[j].fIngreso.mes && lista[i].fIngreso.                    dia>lista[j].fIngreso.dia))
            {
                auxEmpleado=lista[i];
                lista[i]=lista[j];
                lista[j]=auxEmpleado;
            }
        }
    }
}
