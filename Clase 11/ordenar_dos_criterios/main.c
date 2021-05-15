#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

#define ALUMNOS_LENGTH 10
#define ASC 1
#define DESC 0


int calcularPromedioRef(int a, int b, float* pPromedio);
void mostrarNotas(int n1[], int n2[], int legajos[], float proms[], int notasLength);
//void ordenarPromedios(float vector[], int notas1[], int notas2[], int notasLength, int criterio);
void ordenarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam);
void ordenarAlumnos2(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam);
void mostrarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam);
void mostrarAlumno(int legajo, char nombre[], char sexo, int nota1, int nota2, float promedio);

int main()
{
    char nombres[ALUMNOS_LENGTH][20]={"Maria","Laura","German","Christian","Chepi","Juan","Pepe","Guido","Ana","Analia"};
    int legajos[ALUMNOS_LENGTH]={100,101,102,103,104,105,106,107,108,109};
    char sexos[ALUMNOS_LENGTH]={'f','f','m','m','f','m','m','m','f','f'};
    int notas1[ALUMNOS_LENGTH]={5,7,8,9,7,5,7,4,2,4};
    int notas2[ALUMNOS_LENGTH]={4,7,9,8,4,5,7,6,6,5};
    float promedios[ALUMNOS_LENGTH];


    for(int i=0;i<ALUMNOS_LENGTH;i++){
        calcularPromedioRef(notas1[i], notas2[i], &promedios[i]);
    }

    mostrarAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, ALUMNOS_LENGTH);
    ordenarAlumnos(legajos, nombres, sexos,  notas1,  notas2,  promedios,  ALUMNOS_LENGTH);
    mostrarAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, ALUMNOS_LENGTH);
    ordenarAlumnos2(legajos, nombres, sexos,  notas1,  notas2,  promedios,  ALUMNOS_LENGTH);
    mostrarAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, ALUMNOS_LENGTH);


    return 0;
}

void mostrarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam)
{
    printf("***LISTADO DE NOTAS***\n");
    printf("Legajo   Nombre   Sexo   Nota 1   Nota 2   Promedio\n");

    for(int i=0;i<tam;i++){
        mostrarAlumno(lega[i],names[i],sexs[i],n1[i],n2[i],proms[i]);
    }
    printf("\n");
}

void mostrarAlumno(int legajo, char nombre[], char sexo, int nota1, int nota2, float promedio)
{
    printf("  %d     %-10s    %c   %2d   %2d   %.2f    \n",legajo,nombre,sexo,nota1,nota2,promedio);
}


int calcularPromedioRef(int a, int b, float* pPromedio)
{
    int function_success=-1;
    if(pPromedio!=NULL && a>0 && b>0){
        *pPromedio=(float)(a+b)/2;
        function_success=0;
    }
    return function_success;
}

//void ordenarPromedios(float vector[], int notas1[], int notas2[], int notasLength, int criterio)
//{
//    float aux;
//    int auxInt;
//
//    for(int i=0;i<notasLength-1;i++){
//
//        for(int j=i+1;j<notasLength;j++){
//            if(criterio && vector[i]>vector[j]){
//                aux=vector[i];
//                vector[i]=vector[j];
//                vector[j]=aux;
//
//                auxInt=notas1[i];
//                notas1[i]=notas1[j];
//                notas1[j]=auxInt;
//
//                auxInt=notas2[i];
//                notas2[i]=notas2[j];
//                notas2[j]=auxInt;
//            }
//            else if(vector[i]<vector[j] && !criterio){
//                aux=vector[i];
//                vector[i]=vector[j];
//                vector[j]=aux;
//
//                auxInt=notas1[i];
//                notas1[i]=notas1[j];
//                notas1[j]=auxInt;
//
//                auxInt=notas2[i];
//                notas2[i]=notas2[j];
//                notas2[j]=auxInt;
//            }
//        }
//    }
//}


void ordenarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam)
{
    float auxFloat;
    int auxInt;
    char auxChar;
    char auxStr[20];

    for(int i=0;i<tam;i++){
        for(int j=i+1;j<tam;j++){
            if(sexs[i]<sexs[j] || (sexs[i]==sexs[j]&&strcmpi(names[i],names[j])>0)){

                auxFloat=proms[i];
                proms[i]=proms[j];
                proms[j]=auxFloat;

                auxInt=n1[i];
                n1[i]=n1[j];
                n1[j]=auxInt;

                auxInt=n2[i];
                n2[i]=n2[j];
                n2[j]=auxInt;

                auxInt=lega[i];
                lega[i]=lega[j];
                lega[j]=auxInt;

                auxChar=sexs[i];
                sexs[i]=sexs[j];
                sexs[j]=auxChar;

                strcpy(auxStr,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],auxStr);

            }
        }
    }
}

void ordenarAlumnos2(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam)
{
    float auxFloat;
    int auxInt;
    char auxChar;
    char auxStr[20];

    for(int i=0;i<tam;i++){
        for(int j=i+1;j<tam;j++){
            if(sexs[i]>sexs[j] || (sexs[i]==sexs[j]&&lega[i]>lega[j])){

                auxFloat=proms[i];
                proms[i]=proms[j];
                proms[j]=auxFloat;

                auxInt=n1[i];
                n1[i]=n1[j];
                n1[j]=auxInt;

                auxInt=n2[i];
                n2[i]=n2[j];
                n2[j]=auxInt;

                auxInt=lega[i];
                lega[i]=lega[j];
                lega[j]=auxInt;

                auxChar=sexs[i];
                sexs[i]=sexs[j];
                sexs[j]=auxChar;

                strcpy(auxStr,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],auxStr);

            }
        }
    }
}
