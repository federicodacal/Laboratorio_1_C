#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn_validaciones.h"

int initClientes(Cliente list[], int len)
{
    int response=1;
    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            list[i].isEmpty=1;
        }
        response=0;
    }
    return response;
}

int addCliente(Cliente list[], int len, int* pCodigo)
{
    int response=-1;

    Cliente newCliente;
    int index;

    if(list!=NULL && len>0 && pCodigo!=NULL){
        printf("\nCodigo: %d\n", *pCodigo);
        index=findEmptyIndex(list,len);
        if(index==-1){
            printf("No hay lugar disponible en el sistema");
            response=1;
        }
        else{
            if(!utn_getNombre(newCliente.nombre,NAME_LEN,"\nIngrese nombre: ","Error dato no valido\n",5) &&
               !utn_getNombre(newCliente.apellido,APELLIDO_LEN,"\nIngrese apellido: ","\nError dato no valido\n",5) &&
               !utn_getSexo(newCliente.sexo, 20, "\nIngrese sexo ('masculino' o 'femenino'): ","\nError dato no valido\n",5) &&
               !utn_getDescripcion(newCliente.telefono, TELEFONO_LEN,"\nIngrese telefono: ","\nError dato no valido\n", 5) &&
               !utn_getDescripcion(newCliente.domicilio, DOMICILIO_LEN,"\nIngrese domicilio: (ej: B. Mitre 1111) ","\nError dato no valido\n",5))
               {
                    newCliente.codigo=*pCodigo;
                    (*pCodigo)++;
                    newCliente.isEmpty=0;
                    list[index]=newCliente;
                    response=0;
               }
        }
    }

    return response;
}

int findEmptyIndex(Cliente list[], int len)
{
    int index=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].isEmpty){
                index=i;
                break;
            }
        }
    }
    return index;
}

void printCliente(Cliente cliente)
{
    printf("%d \t%10s \t%10s \t%10s \t%10s \t%10s\n",
               cliente.codigo,
               cliente.nombre,
               cliente.apellido,
               cliente.sexo,
               cliente.telefono,
               cliente.domicilio);
}

int printClientes(Cliente list[], int len)
{
    int response=-1;
    int flag=1;
    if(list!=NULL && len>0){
        printf("\n\t\t*****LISTADO DE CLIENTES******\n");
        printf("-------------------------------------------------------------------------\n");
        printf("ID \tNombre \tApellido \tSexo \tTelefono\n");
        for(int i=0;i<len;i++){
            if(!list[i].isEmpty){
                printCliente(list[i]);
                flag=0;
            }
        }
        if(flag){
            printf("\n\tNo hay empleados que mostrar\n");
        }
    response=0;
    printf("\n\n");
    }
    return response;
}

int removeCliente(Cliente list[], int len)
{
    int response=-1;
    int codigo;
    int index;
    int confirm;

    if(list!=NULL && len>0){
        printClientes(list,len);
        if(!utn_getNumero(&codigo,"\nIngrese codigo del cliente: \n","Dato no valido",100,2000,5)){
            index=findClientById(list,len,codigo);

            if(index==-1){
                printf("No hay cliente registrado con el codigo %d",codigo);
            }
            else{
                printf("\n");
                printCliente(list[index]);
                if(!utn_getNumero(&confirm,"\n[1] Confirmar baja\n[2] Cancelar\n","\nDato no valido",1,2,10) && confirm){
                    list[index].isEmpty=1;
                    response=0;
                }
                else{
                    printf("\nBaja Cancelada\n");
                    response=1;
                }
            }
        }
    }
    return response;
}

int findClientById(Cliente list[], int len, int id)
{
    int index=-1;

    if(list!=NULL && len>0){
        for(int i=0;i<len;i++){
            if(list[i].codigo==id && list[i].isEmpty==0){
                index=i;
            }
        }
    }
    return index;
}

int updateCliente(Cliente list[], int len)
{
    int response=-1;
    int codigo;
    int index;

    if(list!=NULL && len>0){
        printClientes(list,len);
        if(!utn_getNumero(&codigo,"\nIngrese codigo del cliente: \n","Dato no valido",100,2000,5)){
            index=findClientById(list,len,codigo);
            if(index==-1){
                printf("\nNo hay cliente registrado con el codigo %d\n",index);
            }
            else{
                if(!modifyCliente(list,len,index)){
                    printf("\nDatos Actualizados:\n");
                    printCliente(list[index]);
                    printf("---------------------------------------------------------------\n\n");
                    response=0;
                }
            }
        }
    }
    return response;
}

int modifyCliente(Cliente list[], int len, int index)
{
    int response=-1;
    Cliente auxCliente;
    int option;

    if(list!=NULL && len>0){
        do{
            system("cls");
            printf("\nSeleccione el campo que desea modificar o 5 para Terminar:\n");
            if(!utn_getNumero(&option,"\n[1] Nombre - [2] Apellido - [3] Sexo - [4] Telefono - [5] Domicilio - [6] Terminar Modificacion\n","\nDato no valido",1,6,10)){
                switch(option){
                    case 1:
                        if(!utn_getNombre(auxCliente.nombre,NAME_LEN,"\nIngrese Nombre: ","\nError dato no valido",5)){
                            strcpy(list[index].nombre,auxCliente.nombre);
                            printf("Informacion Actualizada. Nuevo nombre: %s\n\n",auxCliente.nombre);
                            system("pause");
                        }
                        break;
                    case 2:
                        if(!utn_getNombre(auxCliente.apellido,APELLIDO_LEN,"\nIngrese Apellido: ","\nError dato no valido",5)){
                            strcpy(list[index].apellido,auxCliente.apellido);
                            printf("Informacion Actualizada. Nuevo apellido: %s\n\n",auxCliente.apellido);
                            system("pause");
                        }
                        break;
                    case 3:
                        if(!utn_getSexo(auxCliente.sexo,20,"\nIngrese Sexo ('masculino' o 'femenino') ","\nError dato no valido",5)){
                            strcpy(list[index].sexo,auxCliente.sexo);
                            printf("Informacion Actualizada. Nuevo sexo: %s\n\n",auxCliente.sexo);
                            system("pause");
                        }
                        break;
                    case 4:
                        if(!utn_getNumero(auxCliente.telefono,"\nIngrese nombre: ","Error dato no valido\n", 8, 90000000000000, 5)){
                            list[index].telefono=auxCliente.telefono;
                            printf("Informacion Actualizada. Nuevo telefono: %d\n\n",auxCliente.telefono);
                            system("pause");
                        }
                        break;
                    case 5:
                        if(!utn_getDescripcion(auxCliente.domicilio,DOMICILIO_LEN,"\nIngrese Domicilio: ","\nError dato no valido",5)){
                            strcpy(list[index].domicilio,auxCliente.domicilio);
                            printf("Informacion Actualizada. Nuevo domicilio: %s\n\n",auxCliente.domicilio);
                            system("pause");
                        }
                        break;
                    }
                }
        }while(option!=6);
        response=0;
    }
    return response;
}

int sortClientesByLastName(Cliente list[], int len)
{
    int response=-1;
    Cliente auxCliente;

    if(list!=NULL && len>0){
        for(int i=0; i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(strcmpi(list[i].apellido,list[j].apellido)>0){
                    auxCliente=list[i];
                    list[i]=list[j];
                    list[j]=auxCliente;
                }
            }
        response=0;
        }
    }
    return response;
}
