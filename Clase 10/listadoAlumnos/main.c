#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define ALUMNOS_LENGTH 3
#define ASC 1
#define DESC 0


int calcularPromedioRef(int a, int b, float* pPromedio);
void mostrarNotas(int n1[], int n2[], int legajos[], float proms[], int notasLength);
void ordenarPromedios(float vector[], int notas1[], int notas2[], int notasLength, int criterio);
void ordenarLegajos(int vector[],float proms[], int notas1[], int notas2[], int notasLength, int criterio);
void ordenarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam);
void mostrarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam);
void mostrarAlumno(int legajo, char nombre[], char sexo, int nota1, int nota2, float promedio);

int main()
{
    char nombres[ALUMNOS_LENGTH][20];
    int legajos[ALUMNOS_LENGTH];
    char sexos[ALUMNOS_LENGTH];
    int notas1[ALUMNOS_LENGTH];
    int notas2[ALUMNOS_LENGTH];
    float promedios[ALUMNOS_LENGTH];

    for(int i=0;i<ALUMNOS_LENGTH;i++){

        printf("Ingrese el legajo del alumno #%d: ",i+1);
        scanf("%d", &legajos[i]);

        printf("Ingrese nombre del alumno: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese el sexo del alumno #%d: ",i+1);
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese la nota del primer parcial del alumno #%d: ",i+1);
        scanf("%d", &notas1[i]);

        printf("Ingrese la nota del segundo parcial del alumno #%d: ",i+1);
        scanf("%d", &notas2[i]);
        printf("\n");

        calcularPromedioRef(notas1[i], notas2[i], &promedios[i]);

    }

//    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);
//    printf("\n");
//    ordenarPromedios(promedios, notas1, notas2, ALUMNOS_LENGTH, DESC);
//    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);
//    printf("\n");
//    ordenarPromedios(promedios, notas1, notas2, ALUMNOS_LENGTH, ASC);
//    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);
//    printf("\n");
//    ordenarLegajos(legajos, promedios, notas1, notas2, ALUMNOS_LENGTH, ASC);
//    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);

    mostrarAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, ALUMNOS_LENGTH);
    ordenarAlumnos(legajos, nombres,  sexos,  notas1,  notas2,  promedios,  ALUMNOS_LENGTH);
    mostrarAlumnos(legajos, nombres, sexos, notas1, notas2, promedios, ALUMNOS_LENGTH);


    return 0;
}

//void mostrarNotas(int n1[], int n2[], int legajos[], float proms[], int notasLength)
//{
//    printf("***LISTADO DE NOTAS***\n");
//    printf("\tNotas Parcial 1\t\tNotas Parcial 2\t\tPromedio\tLegajos\n");
//    for(int i=0;i<notasLength;i++){
//        printf("\t\t%2d\t\t\t%2d\t\t%.2f\t\t%d\n", n1[i],n2[i],proms[i],legajos[i]);
//    }
//}

void mostrarAlumnos(int lega[], char names[][20], char sexs[], int n1[], int n2[], float proms[], int tam)
{
    printf("***LISTADO DE NOTAS***\n");
    printf("Legajo   Nombre   Sexo   Nota 1   Nota 2   Promedio\n");
//    for(int i=0;i<tam;i++){
//        printf("  %d     %-10s    %c   %2d   %2d   %.2f    \n",lega[i],names[i],sexs[i],n1[i],n2[i],proms[i]);
//    }
    for(int i=0;i<tam;i++){
        mostrarAlumno(lega[i],names[i],sexs[i],n1[i],n2[i],proms[i]);
    }

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

void ordenarPromedios(float vector[], int notas1[], int notas2[], int notasLength, int criterio)
{
    float aux;
    int auxInt;

    for(int i=0;i<notasLength-1;i++){

        for(int j=i+1;j<notasLength;j++){
            if(criterio && vector[i]>vector[j]){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;

                auxInt=notas1[i];
                notas1[i]=notas1[j];
                notas1[j]=auxInt;

                auxInt=notas2[i];
                notas2[i]=notas2[j];
                notas2[j]=auxInt;
            }
            else if(vector[i]<vector[j] && !criterio){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;

                auxInt=notas1[i];
                notas1[i]=notas1[j];
                notas1[j]=auxInt;

                auxInt=notas2[i];
                notas2[i]=notas2[j];
                notas2[j]=auxInt;
            }
        }
    }
}

//void ordenarLegajos(int vector[],float proms[], int notas1[], int notas2[], int notasLength, int criterio)
//{
//    float aux;
//    int auxInt;
//
//    for(int i=0;i<notasLength-1;i++){
//
//        for(int j=i+1;j<notasLength;j++){
//            if(criterio && vector[i]>vector[j]){
//                auxInt=vector[i];
//                vector[i]=vector[j];
//                vector[j]=vector;
//
//                aux=proms[i];
//                proms[i]=proms[j];
//                proms[j]=aux;
//
//                auxInt=notas1[i];
//                notas1[i]=notas1[j];
//                notas1[j]=auxInt;
//
//                auxInt=notas2[i];
//                notas2[i]=notas2[j];
//                notas2[j]=auxInt;
//
//            }
//            else if(vector[i]<vector[j] && !criterio){
//                auxInt=vector[i];
//                vector[i]=vector[j];
//                vector[j]=vector;
//
//                aux=proms[i];
//                proms[i]=proms[j];
//                proms[j]=aux;
//
//                auxInt=notas1[i];
//                notas1[i]=notas1[j];
//                notas1[j]=auxInt;
//
//                auxInt=notas2[i];
//                notas2[i]=notas2[j];
//                notas2[j]=auxInt;
//
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
            if(proms[i]<proms[j]){

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
