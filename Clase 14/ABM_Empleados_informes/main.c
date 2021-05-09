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
#include <string.h>
#include "Empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#define NOMINA_LENGTH 10
#define SECTOR_LENGTH 5
#define COMIDA_LENGTH 5
#define ALMUERZO_LENGTH 30

int menu();
int menuInformes();

int main()
{
    int nextLegajo=20000;
    int nextIdAlmuerzo=50000;
    sSector sectores[SECTOR_LENGTH]={
        {500, "Sistemas"},
        {501, "Legales"},
        {502, "RRHH"},
        {503, "Contable"},
        {504, "Ventas"}
    };

        sComida comidas[COMIDA_LENGTH]={
        {1000, "Milanesa",150},
        {1001, "Ensalada",180},
        {1002, "Fideos",140},
        {1003, "Pizza",200},
        {1004, "Sopa",110}
    };

    sAlmuerzo almuerzos[ALMUERZO_LENGTH];

    sEmpleado nomina[NOMINA_LENGTH];
    inicializarEmpleados(nomina, NOMINA_LENGTH);

    hcodearEmpleados(nomina, NOMINA_LENGTH, 10, &nextLegajo);

    char salir='n';

    do{
        switch(menu()){
        case 1:
            if(altaEmpleado(nomina,NOMINA_LENGTH,sectores,SECTOR_LENGTH,&nextLegajo)){
                printf("Alta exitosa\n");
            }
            else{
                printf("Hubo un problema\n");
            }
            system("pause");
            break;
        case 2:
            if(bajaEmpleado(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH)){
                printf("Baja exitosa\n");
            }
            else{
                printf("Hubo un problema\n");
            }
            system("pause");
            break;
        case 3:
            printf("\nModificar Empleado\n");
            system("pause");
            break;
        case 4:
            system("cls");
            mostrarEmpleados(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH);
            system("pause");
            break;
        case 5:
            printf("\nOrdenar Empleados\n");
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarSectores(sectores, SECTOR_LENGTH);
            system("pause");
            break;
        case 7:
            printf("\nInformes\n");
            switch(menuInformes()){
                case 1:
                    listarEmpleadosSector(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH);
                    system("pause");
                    break;
                case 2:
                    listarEmpleadosCadaSector(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH);
                    system("pause");
                    break;
                case 3:
                    totalSueldoSector(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH);
                    system("pause");
                    break;
                case 4:
                    totalADepositar(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH);
                    system("pause");
                    break;
                case 5:
                    sectorMayorSueldo(nomina, NOMINA_LENGTH, sectores, SECTOR_LENGTH);
                    system("pause");
                    break;
            }
            break;
        case 8:
            printf("Confirmar salida: s/n ");
            fflush(stdin);
            salir=getchar();
            break;
        }

    }while(salir!='s');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("***ABM Empleados***\n\n");
    printf("1. Alta Empleado\n");
    printf("2. Baja Empleado\n");
    printf("3. Modificar Empleado\n");
    printf("4. Listar Empleados\n");
    printf("5. Ordenar Empleados\n");
    printf("6. Listar Sectores\n");
    printf("7. Informes\n");
    printf("8. Salir\n");
    printf("\nIngrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    int opcion;

    system("cls");
    printf("***INFORMES***\n\n");
    printf("1. Filtrar Empleados por Sector\n");
    printf("2. Mostrar Empleados de Cada Sector\n");
    printf("3. Total Sueldos por Sector\n");
    printf("4. Totales Sueldos\n");
    printf("5. Sector de Mayor Sueldo Acumulado\n");
    printf("8. Volver al Menu\n");
    printf("\nIngrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}
