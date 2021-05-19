#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Juego.h"
#include "Categoria.h"
#include "Cliente.h"
#include "Alquileres.h"
#include "fecha.h"
#include "utn_validaciones.h"
#include "datawarehouse.h"

#define CLIENTE_LEN 5000

int menu();

int main()
{
    int nextCodigoCliente=100;
 //   int nextCodigoAlquiler=500;


    char exit='n';
    int option;

    Cliente list[CLIENTE_LEN];

    initClientes(list, CLIENTE_LEN);

    hcodeEmployees(list, CLIENTE_LEN, 20, &nextCodigoCliente);

    do{
        option=menu();
        if(option!=-1){
            switch(option){
                case 1:
                    system("cls");
                    printf("\n*****GESTIONAR ALTA*****\n");
                    printf("-------------------------------------\n");
                    if(!addCliente(list, CLIENTE_LEN, &nextCodigoCliente)){
                        printf("ALTA EXITOSA\n\n");
                    }
                    else{
                        printf("\nNo se realizo la alta\n\n");
                    }
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("\n*****GESTIONAR MODIFICACION*****\n");
                    printf("-------------------------------------\n");
                    if(!updateCliente(list, CLIENTE_LEN)){
                        printf("Modificacion exitosa\n\n");
                    }
                    else{
                        printf("\nOcurrio un problema\n\n");
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    printf("\n\t\t*****GESTIONAR BAJA*****\n");
                    printf("\t------------------------------------------------------------\n");
                    if(!removeCliente(list, CLIENTE_LEN)){
                        printf("BAJA EXITOSA\n\n");
                    }
                    else{
                        printf("\nNo se realizo baja\n\n");
                    }
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    sortClientesByLastName(list, CLIENTE_LEN);
                    printClientes(list,CLIENTE_LEN);
                    system("pause");
                    break;
                case 5:
                    printf("Confirmar salida: s/n");
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
    int response=-1;;
    int optionAux;

    system("cls");
    printf("\n*****ADMINISTRACION DE JUEGOS INFANTILES*****\n");
    printf("------------------------------------------\n");
    printf("[1] ALTA CLIENTE\n");
    printf("[2] MODIFICAR CLIENTE\n");
    printf("[3] BAJA CLIENTE\n");
    printf("[4] INFOMRES\n");
    printf("------------------------------------------\n");
    printf("[5] Salir\n");

    if(utn_getNumero(&optionAux,"\nIngrese opcion:\n","\nDato ingresado no valido.",1,5,10)==0){
        response=optionAux;
    }

    return response;
}

