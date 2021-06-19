#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "utn_validaciones.h"

#define ALUMNOS_LEN 30

int main()
{
    Alumno* arrayPunterosAlumno[ALUMNOS_LEN];

    int opcion;
    int nextId=1;

    float bufferAltura;
    char bufferNombre[20];
    int bufferId;
    int bufferIndex;
    float auxPromedio;

    if(!alumno_initArray(arrayPunterosAlumno,ALUMNOS_LEN)){

        printf("INIT OK\n\n");

        alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,"Pepe",1.65,nextId++);
        alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,"Juan",1.76,nextId++);
        alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,"Pedro",1.91,nextId++);
        alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,"Ana",1.71,nextId++);
        alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,"Analia",1.61,nextId++);

        do{
            utn_getNumero(&opcion,"\n1-ALTA\n2-BAJA\n3-MODIFICAR\n4-ORDENAR\n5-IMPRIMIR\n6-Promedio Altura\n7-Alumno Mas Alto\n8-Guardar Archivo\n9-Leer desde Archivo\n\n10-Salir\n","\nOpcion Invalida\n",1,10,2);

            switch(opcion){
                case 1:
                    if(!utn_getNombre(bufferNombre,20,"\nNombre: ","Dato incorrecto\n",4) &&
                       !utn_getNumeroFlotante(&bufferAltura,"\nAltura: ","Dato incorrecto\n",0.1,4,5) &&
                       alumno_agregarAlumno(arrayPunterosAlumno,ALUMNOS_LEN,bufferNombre,bufferAltura,nextId)>=0){
                        printf("ALTA OK\n");
                        nextId++;
                    }
                    break;
                case 2:
                    alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);
                    if(!utn_getNumero(&bufferId,"\nID: ","Error\n",1,100,2) &&
                       !alumno_removeById(arrayPunterosAlumno,ALUMNOS_LEN,bufferId)){
                        printf("BAJA OK\n");
                       }
                       else{
                        printf("Error en al baja\n");
                       }
                    break;
                case 3:
                    alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);
                    if(!utn_getNumero(&bufferId,"\nID: ","Error\n",1,100,2)){
                       bufferIndex=alumno_buscarPorId(arrayPunterosAlumno,ALUMNOS_LEN,bufferId);
                           if(bufferId>=0){
                                if(!utn_getNombre(bufferNombre,20,"\nNombre: ","Dato incorrecto\n",4) &&
                                    !utn_getNumeroFlotante(&bufferAltura,"\nAltura: ","Dato incorrecto\n",0.1,4,5)){
                                    alumno_setNombre(arrayPunterosAlumno[bufferIndex],bufferNombre);
                                    alumno_setAltura(arrayPunterosAlumno[bufferIndex],bufferAltura);;
                                }
                           }
                       }
                       else{
                        printf("Error\n");
                       }

                    break;
                case 4:
                    alumno_ordenarArray(arrayPunterosAlumno,ALUMNOS_LEN);
                    alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);
                    break;
                case 5:
                    alumno_imprimirArray(arrayPunterosAlumno,ALUMNOS_LEN);
                    break;
                case 6:
                    alumno_promedioAltura(arrayPunterosAlumno,ALUMNOS_LEN,&auxPromedio);
                    printf("La altura promedio es: %.2f\n",auxPromedio);
                    break;
                case 7:
                    alumno_calcularMayorAltura(arrayPunterosAlumno,ALUMNOS_LEN,&bufferIndex);
//                    alumno_getNombre(arrayPunterosAlumno[bufferIndex],bufferNombre);
//                    alumno_getAltura(arrayPunterosAlumno[bufferIndex],&bufferAltura);

                    break;
                case 8:
                    if(!alumno_salvarArray(arrayPunterosAlumno,ALUMNOS_LEN,"data.csv")){
                        printf("Archivo generado\n");
                    }
                    break;
                case 9:

                    break;
            }

        }while(opcion!=10);
    }

    return 0;
}
