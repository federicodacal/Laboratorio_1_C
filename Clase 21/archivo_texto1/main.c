#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x=20;
    int y;
    int cant;
    char auxCad[5];
   // char charact;
   int id;
   char nombre[20];
   char sexo;
   float sueldo;

    FILE* f=fopen("variables.txt", "w");

    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    cant=fprintf(f,"%d",x);

    if(cant!=0){
        printf("Se guardaron los datos correctamente\n");
    }
    else{
        printf("Error al guardar los datos\n");
    }

    fclose(f);

    FILE* f2=fopen("variables.txt", "r");
    if(f2==NULL){
        printf("No se pudo abrir el archivo xD\n");
        exit(1);
    }

    //cant=fscanf(f2,"%d",&y);
    cant=fscanf(f2,"%s",auxCad);


    if(cant==1){
        printf("Se leyeron los datos\n");
    }
    else{
        printf("Problema al leer los datos");
    }

    y=atoi(auxCad);
    printf("y: %d\n",y);

    fclose(f2);

    FILE* f3=fopen("variables.txt", "r");
    if(f3==NULL){
        printf("No se pudo abrir el archivo xD\n");
        exit(1);
    }

    while(!feof(f3)){
        fgets(auxCad,5,f3);
        printf("%s", auxCad);
    }
    printf("\n");

    fclose(f3);

    FILE* f4=fopen("datos.txt", "r");
    if(f4==NULL){
        printf("No se pudo abrir el archivo xD\n");
        exit(1);
    }

    cant=fscanf(f4,"%d,%[^,],%c,%f",&id,nombre,&sexo,&sueldo);
    printf("Cant: %d\n",cant);
    printf("ID: %d - Nombre: %s - Sexo: %c - Sueldo: $%.2f\n",id,nombre,sexo,sueldo);

    fclose(f4);


    return 0;
}
