#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn_validaciones.h"

#define EMPLOYEE_LEN 1000

int menu();

int main()
{
    int option;
    char exit='n';
    int nextId=1;
    int sector;

    Employee list[EMPLOYEE_LEN];

    do{
        option=menu();
        if(option!=-1){
            switch(option){
                case 1:
                    system("cls");
                    printf("*****Alta Empleado*****");
                    addEmployee(list, EMPLOYEE_LEN, list->id, list->name, list->lastName, list->salary, sector);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("Modificar");
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    printf("Baja");
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    printf("Informar");
                    system("pause");
                    break;
                case 5:
                    printf("Confirmar salida: s/n ");
                    fflush(stdin);
                    exit=getchar();
                    break;
                }
        }

    }while(exit!='s');

    return 0;
}

int menu()
{
    int optionAux;
    int response=-1;;

    system("cls");
    printf("***ABM EMPLEADOS***\n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,5,10)==0){
        response=optionAux;
    }

    return response;
}
