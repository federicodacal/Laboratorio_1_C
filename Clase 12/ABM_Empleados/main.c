/*
ABM Empleados:
1 Alta Empleado
2 Baja Empleado
3 Modificacion Empleado
4 Mostrar Empleados
5 Ordenar Empleados
6 Informes
7 Salir
*/

#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#define NOMINA_LENGTH 10

int menu ();

int main()
{
    sEmpleado nomina[NOMINA_LENGTH];

    char salir='n';

    do{

        switch(menu()){
        case 1:
            printf("\nAlta Empleado\n");
            system("pause");
            break;
        case 2:
            printf("\nBaja Empleado\n");
            system("pause");
            break;
        case 3:
            printf("\nModificar Empleado\n");
            system("pause");
            break;
        case 4:
            printf("\nListar Empleados\n");
            system("pause");
            break;
        case 5:
            printf("\nOrdenar Empleados\n");
            system("pause");
            break;
        case 6:
            printf("\nInformes\n");
            system("pause");
            break;
        case 7:
            printf("Confirmar salida: s/n ");
            fflush(stdin);
            salir=getchar();
            break;
        }

    }while(salir!='s');

    return 0;
}

int menu ()
{
    int opcion;

    system("cls");
    printf("***ABM Empleados***\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Baja Empleado\n");
    printf("3. Modificar Empleado\n");
    printf("4. Listar Empleados\n");
    printf("5. Ordenar Empleados\n");
    printf("6. Informes\n");
    printf("7. Salir\n");
    printf("\nIngrese opcion: \n");
    scanf("%d", &opcion);
    return opcion;
}
