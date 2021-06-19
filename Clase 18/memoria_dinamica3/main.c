#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    float sueldo;
}Empleado;

void mostrarEmpleadoPorValor(Empleado emp);
void mostrarEmpleadoPorRef(Empleado* pEmp);

int main()
{
    // emp1 Empleado estatico
    Empleado emp1;
    Empleado emp3;

    printf("%d\n",sizeof(Empleado));    // 32 bytes

    // emp2 Empleado dinamico
    Empleado* emp2=(Empleado*)malloc(sizeof(Empleado));
    Empleado* emp4=(Empleado*)malloc(sizeof(Empleado));

    printf("\nIngrese id: ");
    scanf("%d", &emp3.id);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(emp3.nombre);
    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &emp3.sexo);
    printf("Ingrese sueldo: $");
    scanf("%f", &emp3.sueldo);

    printf("\nIngrese id: ");
    scanf("%d", &emp4->id);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(emp4->nombre);
    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &emp4->sexo);
    printf("Ingrese sueldo: $");
    scanf("%f", &emp4->sueldo);

    mostrarEmpleadoPorRef(emp4); // Lo puedo pasar directamente porque emp4 ya es una direccion de memoria
    mostrarEmpleadoPorValor(*emp4);
    mostrarEmpleadoPorValor(emp3);
    mostrarEmpleadoPorRef(&emp3);

    emp1.id=1000;
    strcpy(emp1.nombre, "Juan");
    emp1.sexo='m';
    emp1.sueldo=56000;

    (*emp2).id=1200;
    strcpy((*emp2).nombre, "Ana");
    (*emp2).sexo='f';
    (*emp2).sueldo=58000;

    emp2->id=1200;
    strcpy(emp2->nombre, "Ana");
    emp2->sexo='f';
    emp2->sueldo=58000;

   // printf("\nID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",emp1.id,emp1.nombre,emp1.sexo,emp1.sueldo);
//    printf("ID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",(*emp2).id,(*emp2).nombre,(*emp2).sexo,(*emp2).sueldo);
//    printf("ID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",emp2->id,emp2->nombre,emp2->sexo,emp2->sueldo);
//    printf("ID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",emp3.id,emp3.nombre,emp3.sexo,emp3.sueldo);
   // printf("ID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",emp4->id,emp4->nombre,emp4->sexo,emp4->sueldo);

    free(emp2);
    free(emp4);

    return 0;
}

void mostrarEmpleadoPorValor(Empleado emp)
{
    printf("\nID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",
           emp.id,
           emp.nombre,
           emp.sexo,
           emp.sueldo);
}



void mostrarEmpleadoPorRef(Empleado* pEmp)
{
    printf("\nID: %d Nombre: %s Sexo: %c Sueldo: $%.2f\n\n",
           pEmp->id,
           pEmp->nombre,
           pEmp->sexo,
           pEmp->sueldo);
}
