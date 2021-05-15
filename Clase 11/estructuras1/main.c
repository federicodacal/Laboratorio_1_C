#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//struct alumno{
//    int legajo;
//    char nombre[20];
//    char sexo;
//    int nota1;
//    int nota2;
//    float promedio;
//};

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

int main()
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;

    sEmpleado emp1;
    sEmpleado emp2;
    sFecha fIngreso;

    legajo=111;
    strcpy(nombre,"Juan");
    edad=34;
    sexo='m';
    sueldo=6500;

    emp1.legajo=340;
    strcpy(emp1.nombre,"Lucia");
    emp1.edad=29;
    emp1.sexo='f';
    emp1.sueldo=7000;

    printf("%d %s %d %c %.2f\n", legajo,nombre,edad,sexo,sueldo);
    printf("%d %s %d %c %.2f\n", emp1.legajo,emp1.nombre,emp1.edad,emp1.sexo,emp1.sueldo);

    mostrarEmpleado(emp1);

    printf("\n%d \n\n",sizeof(sEmpleado));

    printf("Ingrese legajo: ");
    scanf("%d", &emp2.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(emp2.nombre);

    printf("Ingrese edad: ");
    scanf("%d", &emp2.edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &emp2.sexo);

    printf("Ingrese sueldo: ");
    scanf("%f", &emp2.sueldo);

//    printf("Ingrese dia de ingreso: ");
//    scanf("%d", &emp2.fIngreso.dia);
//
//    printf("Ingrese mes de ingreso: ");
//    scanf("%d", &emp2.fIngreso.mes);
//
//    printf("Ingrese anio de ingreso: ");
//    scanf("%d", &emp2.fIngreso.anio);

    printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
    scanf("%d/%d/%d", &emp2.fIngreso.dia,&emp2.fIngreso.mes,&emp2.fIngreso.anio);

//    printf("%d %s %d %c %.2f\n", emp2.legajo,emp2.nombre,emp2.edad,emp2.sexo,emp2.sueldo);

    mostrarEmpleado(emp2);

    return 0;
}

void mostrarEmpleado(sEmpleado unEmpleado)
{
    printf("%d %s %d %c %.2f %02d/%02d/%02d\n",
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
