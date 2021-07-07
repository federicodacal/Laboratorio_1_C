#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn_validaciones.h"
#include "parser.h"
#include "Pais.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayList)
{
    int response=-1;
    char pathIngresado[128];
    FILE* f=NULL;

    if(pArrayList!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .csv que desea cargar: \nSi no recuerda el path puede ingresar el archivo predeterminado data.csv\n","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"r");
            if(f==NULL){
                printf("No se encontro el archivo %s\n\n",pathIngresado);
            }
            else{
                if(!parser_FromText(f,pArrayList)){
                    response=0;
                }
            }
        }
    }

    fclose(f);
    return response;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(LinkedList* pArrayList)
{
	int response=-1;
	char pathIngresado[128];
	FILE* f=NULL;

	if(pArrayList!=NULL){
        if(!utn_getDescripcion(pathIngresado, 128,"Ingrese el path del archivo .bin que desea cargar: \nSi no recuerda el path puede ingresar el archivo predeterminado data.bin\n","\nError. Dato ingresado no valido. Reingrese dato \n",5)){
            f=fopen(pathIngresado,"rb");
            if(f==NULL){
                printf("No se encontro el archivo %s\n",pathIngresado);
            }
            else{
                if(!parser_FromBinary(f, pArrayList)){
                    response=0;
                }
                else{
                    printf("No se pudo abrir el archivo\n");
                }
            }
        }
	}
	fclose(f);
    return response;
}

int controller_List(LinkedList* pArrayList)
{
    int response=-1;

    ePais* auxPais=NULL;
    int flag=0;
    int len;

    if(pArrayList!=NULL){
    	printf("ID - Pais - Recuperados - Infectados - Muertos\n---------------------------------------------------------\n");
    	len=ll_len(pArrayList);
    	for(int i=0;i<len;i++){
    		auxPais=(ePais*)ll_get(pArrayList,i);
    		if(auxPais!=NULL){
    			pais_printPais(auxPais);
    			flag=1;
    		}
    	}
        printf("\n");
    	if(flag==0){
    		printf("No hay empleados para mostrar\n");
    	}
    	response=0;
    }

    return response;
}
