#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Empleado.h"

#define NOMINA_LENGTH 10

void inicializarEmpleados(sEmpleado lista[], int nominaLength);

int main()
{
    sEmpleado nomina[NOMINA_LENGTH]={
    {545,"Miguel",32,'m',50000,{26,4,2021},1},
    {323,"Jacinto",33,'m',45000,{25,4,2021},0},
    {434,"Paula",28,'f',65000,{23,4,2021},0},
    {293,"Luis",28,'m',75000,{22,4,2021},1},
    {200,"Lucia",28,'f',82000,{21,4,2021},0},
    {222,"Pablo",31,'m',52500,{21,4,2021},1},
    {223,"Indiana",33,'f',66500,{20,4,2021},0},
    {341,"Marina",23,'f',75000,{19,4,2021},0},
    {721,"Christian",24,'m',35800,{12,4,2021},0},
    {192,"Luciana",38,'f',81650,{1,4,2021},0}
    };


    inicializarEmpleados(nomina, NOMINA_LENGTH);
    mostrarEmpleados(nomina, NOMINA_LENGTH);
//  ordenarEmpleados(nomina, NOMINA_LENGTH);
//  mostrarEmpleados(nomina, NOMINA_LENGTH);

    return 0;
}

void inicializarEmpleados(sEmpleado lista[], int nominaLength)
{
    for(int i=0;i<nominaLength;i++){
        lista[i].isEmpty=1;
    }
}
