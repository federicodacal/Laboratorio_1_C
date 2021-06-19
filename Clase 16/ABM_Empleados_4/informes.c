#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

void listarEmpleadosSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int idSector;
    int indice;
    int flag=0;

    system("cls");
    printf("    Informe de Empleados por Sector\n");
    mostrarSectores(sectores, sectorLength);
    printf("Ingrese ID sector: ");
    scanf("%d", &idSector);

    indice=buscarSector(idSector,sectores,sectorLength);

    while(indice==-1){
        printf("ID no es valido. Ingrese ID sector: ");
        scanf("%d", &idSector);
        indice=buscarSector(idSector,sectores,sectorLength);
    }

    printf("\n\t\t*****LISTADO DE EMPLEADOS por SECTOR %s******\n", sectores[indice].descripcion);
    printf("-------------------------------------------------------------------------\n");
    printf("Legajo      Nombre      Edad   Sexo      Sueldo      Fecha Ingreso  Sector\n");
    for(int i=0;i<nominaLength;i++){
        if(lista[i].isEmpty==0 && lista[i].idSector==idSector){
            mostrarEmpleado(lista[i],sectores, sectorLength);
            flag=1;
        }
    }
    if(flag==0){
        printf("No hay empleados en el sector de %s\n", sectores[indice].descripcion);
    }
}


void listarEmpleadosCadaSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int flag;

    system("cls");
    printf("    *****LISTADO DE EMPLEADOS POR SECTOR*****\n\n");
    for(int i=0;i<sectorLength;i++){
        printf("\nSector: %s\n", sectores[i].descripcion);
        flag=1;
        for(int j=0; j<nominaLength;j++){
            if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id){
                mostrarEmpleado(lista[j],sectores,sectorLength);
                flag=0;
            }
        }
        if(flag==1){
            printf("No hay empleados \n");
        }
    }
    printf("\n");
}

void totalSueldoSector(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int idSector;
    int indice;
    int flag=0;
    float totalSueldos=0;

    system("cls");
    printf("    *****Total Sueldos de Sector\n");
    mostrarSectores(sectores, sectorLength);
    printf("Ingrese ID sector: ");
    scanf("%d", &idSector);

    indice=buscarSector(idSector,sectores,sectorLength);

    while(indice==-1){
        printf("ID no es valido. Ingrese ID sector: ");
        scanf("%d", &idSector);
        indice=buscarSector(idSector,sectores,sectorLength);
    }

    for(int i=0;i<nominaLength;i++){
        if(lista[i].isEmpty==0 && lista[i].idSector==idSector){
            totalSueldos+=lista[i].sueldo;
            flag=1;
        }
    }

    printf("Total Sueldos: $%.2f\n", totalSueldos);
    if(flag==0){
        printf("No hay empleados en el sector de %s\n", sectores[indice].descripcion);
    }
}

void totalADepositar(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    float totalSueldos;
    float acumuladorSueldosTotal=0;

    system("cls");
    printf("    *****Total Sueldos*****\n\n");
    for(int i=0;i<sectorLength;i++){
        printf("\nSector: %s\n", sectores[i].descripcion);
        totalSueldos=0;
        for(int j=0; j<nominaLength;j++){
            if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id){
                totalSueldos+=lista[j].sueldo;
            }
        }
        printf("Total Sueldos: $%.2f\n", totalSueldos);
        acumuladorSueldosTotal+=totalSueldos;

    }
    printf("\n");
    printf("Total a Depositar: $ %.2f\n\n", acumuladorSueldosTotal);
}

void sectorMayorSueldo(sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    float totalSueldos;
    float sueldosTotales[sectorLength];
    float mayorSueldo;
    int flag=0;

    system("cls");
    printf("    *****Sectores de Mayor Sueldo*****\n\n");
    for(int i=0;i<sectorLength;i++){
        totalSueldos=0;
        for(int j=0; j<nominaLength;j++){
            if(lista[j].isEmpty==0 && lista[j].idSector==sectores[i].id){
                totalSueldos+=lista[j].sueldo;
            }
        }
    sueldosTotales[i]=totalSueldos;
    }
    for(int i=0;i<sectorLength;i++){
        if(flag==0 || sueldosTotales[i]>mayorSueldo){
            mayorSueldo=sueldosTotales[i];
            flag=1;
        }
    }
    for(int i=0;i<sectorLength;i++){
        if(mayorSueldo==sueldosTotales[i]){
            printf("%s: $ %.2f\n", sectores[i].descripcion, mayorSueldo);
        }
    }
    printf("\n");
}

void almuerzosEmpleado(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int legajo;
    int flag=1;

    printf("    Informe Almuerzos de un Empleado\n");

    mostrarEmpleados(lista,nominaLength,sectores,sectorLength);
    printf("Ingrese legajo empleado: \n");
    scanf("%d",&legajo);
        while(buscarEmpleado(lista,nominaLength,legajo)==-1){
            printf("Error. Reingrese legajo empleado: \n");
            scanf("%d",&legajo);
        }
    for(int i=0;i<almuerzosLength;i++){
        if(almuerzos[i].isEmpty==0 && almuerzos[i].legajoEmpleado==legajo){
            mostrarAlmuerzo(almuerzos[i],comidas,comidasLength,lista,nominaLength);
            flag=0;
        }
    }
    if(flag){
        printf("El empleado de legajo %d no registra almuerzos\n",legajo);
    }
    printf("\n");
}

void totalAlmuerzosEmpleado(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sEmpleado lista[], int nominaLength, sSector sectores[], int sectorLength)
{
    int legajo;
    float pagoTotal=0;
    int flag=1;

    printf("    Informe $ Total Almuerzos de un Empleado\n");

    mostrarEmpleados(lista,nominaLength,sectores,sectorLength);
    printf("Ingrese legajo empleado: \n");
    scanf("%d",&legajo);
        while(buscarEmpleado(lista,nominaLength,legajo)==-1){
            printf("Error. Reingrese legajo empleado: \n");
            scanf("%d",&legajo);
        }
    for(int i=0;i<almuerzosLength;i++){
        if(almuerzos[i].isEmpty==0 && almuerzos[i].legajoEmpleado==legajo){
            for(int j=0;j<comidasLength;j++){
                if(comidas[j].id==almuerzos[i].idComida){
                    pagoTotal+=comidas[j].precio;
                }
            }
            flag=0;
        }
    }
    if(flag){
        printf("El empleado de legajo nro. %d no registra almuerzos\n",legajo);
    }
    else{
        printf("Total Almuerzos empleado legajo nro. %d: $ %.2f\n",legajo,pagoTotal);
    }
    printf("\n");
}

void totalAlmuerzosSector(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sSector sectores[], int sectorLength, sEmpleado lista[], int nominaLength)
{
    float total;
    int idSector;
    int legajo;
    int idComida;

    // Recorrer array de sectores
    for(int s=0;s<sectorLength;s++){
        total=0; // Me posicione en sector e inicializo total
        idSector=sectores[s].id;
        // Recorrer array empleados buscando aquellos que trabajan en este sector
        for(int e=0;e<nominaLength;e++){
            if(lista[e].isEmpty==0 && lista[e].idSector==idSector){
                legajo=lista[e].legajo;
                // Recorro los almuerzos en busca de aquellos que pertenecen al empleado
                for(int a=0;a<almuerzosLength;a++){
                    if(almuerzos[a].isEmpty==0 && almuerzos[a].legajoEmpleado==legajo){
                        // Recorrer array de comidas buscando la que pertenece a este almuerzo
                        idComida=almuerzos[a].idComida;
                        for(int c=0;c<comidasLength;c++){
                            if(comidas[c].id==idComida){
                                total+=comidas[c].precio;
                            }
                        }
                    }
                }
            }
        }
        // Mostrar Total Sector
        printf("Sector %s: $%.2f\n", sectores[s].descripcion,total);
    }
    printf("\n");
}

void milanesasPorSector(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sSector sectores[], int sectorLength, sEmpleado lista[], int nominaLength)
{
    char milanesa[20]="Milanesa";
    int contadorMila;
    int idSector;
    int legajo;
    int indice;

    // Recorrer array de sectores
    for(int s=0;s<sectorLength;s++){
        contadorMila=0;
        idSector=sectores[s].id;
        // Recorrer array empleados buscando aquellos que trabajan en este sector
        for(int e=0;e<nominaLength;e++){
            if(lista[e].isEmpty==0 && lista[e].idSector==idSector){
                legajo=lista[e].legajo;
                // Recorro los almuerzos en busca de aquellos que pertenecen al empleado
                for(int a=0;a<almuerzosLength;a++){
                    if(almuerzos[a].isEmpty==0 && almuerzos[a].legajoEmpleado==legajo){
                        // Recorrer array de comidas buscando la que pertenece a este almuerzo
                        indice=buscarComida(almuerzos[a].idComida,comidas,comidasLength);
                        if(strcmp(comidas[indice].descripcion,milanesa)==0){
                            contadorMila++;
                        }

                    }
                }
            }
        }
        // Mostrar Total Sector
        printf("Sector %s: %d milanesas\n", sectores[s].descripcion,contadorMila);
    }
    printf("\n");
}

void sectorMasMilanesas(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength, sSector sectores[], int sectorLength, sEmpleado lista[], int nominaLength)
{
    int idMilanesa=1000;
    int contadores[sectorLength];
    int mayorMilanesa;
    int idSector;
    int legajo;

    // Recorrer array de sectores
    for(int s=0;s<sectorLength;s++){
        contadores[s]=0;  // Inicializo contador en el indice s
        idSector=sectores[s].id;
        // Recorrer array empleados buscando aquellos que trabajan en este sector
        for(int e=0;e<nominaLength;e++){
            if(lista[e].isEmpty==0 && lista[e].idSector==idSector){
                legajo=lista[e].legajo;
                // Recorro los almuerzos en busca de aquellos que pertenecen al empleado
                for(int a=0;a<almuerzosLength;a++){
                    if(almuerzos[a].isEmpty==0 && almuerzos[a].legajoEmpleado==legajo){
                        if(almuerzos[a].idComida==idMilanesa){
                            contadores[s]++;
                        }
                    }

                }
            }
        }
    }

    // Buscar Mayor
    for(int s=0;s<sectorLength;s++){
        if(s==0 || contadores[s]>mayorMilanesa){
            mayorMilanesa=contadores[s];
        }
    }
    printf("Sector/es de mas milanesas: \n");    for(int s=0;s<sectorLength;s++){
        if(contadores[s]==mayorMilanesa){
            printf("%s \n",sectores[s].descripcion);
        }
    }

    printf("\n");
}

void listarTotalComidasFecha(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength)
{
    sFecha fecha;
    int cant;
    int contadores[comidasLength];

    for(int i=0;i<comidasLength;i++){
        contadores[i]=0; // Inicializar
    }

    printf("Total consumido por Fecha\n");

    printf("Ingrese fecha dd/mm/aaaa: ");
    cant=scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);

    while(cant !=3){
        printf("Fecha Incorrecta. Reingrese fecha\n");
        fflush(stdin);
        cant=scanf("%d/%d/%d", &fecha.dia,&fecha.mes,&fecha.anio);
    }

    for(int a=0;a<almuerzosLength;a++){
        if(almuerzos[a].isEmpty==0 && compararFechas(almuerzos[a].fecha,fecha)){
            contadores[buscarComida(almuerzos[a].idComida,comidas,comidasLength)]++;
        }
    }
    for(int c=0;c<comidasLength;c++){
        printf("%s: %d\n",comidas[c].descripcion,contadores[c]);
    }
    printf("\n");
}

void ingresoPorComidas(sAlmuerzo almuerzos[], int almuerzosLength, sComida comidas[], int comidasLength)
{
    int contador;

    printf("Ingreso por comidas:\n");
    for(int c=0;c<comidasLength;c++){
        contador=0;
        for(int a=0;a<almuerzosLength;a++){
            if(almuerzos[a].isEmpty==0 && comidas[c].id==almuerzos[a].idComida){
                contador++;
            }
        }
        printf("%s: %.2f\n",comidas[c].descripcion,contador*comidas[c].precio);
    }
    printf("\n");
}
