#include <stdio.h>
#include <stdlib.h>
#define ALUMNOS_LENGTH 3
#define ASC 1
#define DESC 0

float calcularPromedio(int a, int b);
int calcularPromedioRef(int a, int b, float* pPromedio);
void mostrarNotas(int n1[], int n2[], int legajos[], float proms[], int notasLength);
void ordenarPromedios(float vector[], int notas1[], int notas2[], int notasLength, int criterio);
void ordenarLegajos(int vector[],float proms[], int notas1[], int notas2[], int notasLength, int criterio);

int main()
{
    int legajos[ALUMNOS_LENGTH];
    char sexos[ALUMNOS_LENGTH];
    int notas1[ALUMNOS_LENGTH];
    int notas2[ALUMNOS_LENGTH];
    float promedios[ALUMNOS_LENGTH];

    for(int i=0;i<ALUMNOS_LENGTH;i++){

        printf("Ingrese el legajo del alumno #%d: ",i+1);
        scanf("%d", &legajos[i]);

        printf("Ingrese el sexo del alumno #%d: ",i+1);
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese la nota del primer parcial del alumno #%d: ",i+1);
        scanf("%d", &notas1[i]);

        printf("Ingrese la nota del segundo parcial del alumno #%d: ",i+1);
        scanf("%d", &notas2[i]);
        printf("\n");

        //promedios[i]=calcularPromedio(notas1[i], notas2[i]);
        calcularPromedioRef(notas1[i], notas2[i], &promedios[i]);
    }

    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);
    printf("\n");
    ordenarPromedios(promedios, notas1, notas2, ALUMNOS_LENGTH, DESC);
    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);
    printf("\n");
    ordenarPromedios(promedios, notas1, notas2, ALUMNOS_LENGTH, ASC);
    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);
    printf("\n");
    ordenarLegajos(legajos, promedios, notas1, notas2, ALUMNOS_LENGTH, ASC);
    mostrarNotas(notas1, notas2, legajos, promedios, ALUMNOS_LENGTH);

    return 0;
}

float calcularPromedio(int a, int b)
{
    return (float) (a+b)/2;
}

void mostrarNotas(int n1[], int n2[], int legajos[], float proms[], int notasLength)
{
    printf("***LISTADO DE NOTAS***\n");
    printf("\tNotas Parcial 1\t\tNotas Parcial 2\t\tPromedio\tLegajos\n");
    for(int i=0;i<notasLength;i++){
        printf("\t\t%2d\t\t\t%2d\t\t%.2f\t\t%d\n", n1[i],n2[i],proms[i],legajos[i]);
    }
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

void ordenarLegajos(int vector[],float proms[], int notas1[], int notas2[], int notasLength, int criterio)
{
    float aux;
    int auxInt;

    for(int i=0;i<notasLength-1;i++){

        for(int j=i+1;j<notasLength;j++){
            if(criterio && vector[i]>vector[j]){
                auxInt=vector[i];
                vector[i]=vector[j];
                vector[j]=vector;

                aux=proms[i];
                proms[i]=proms[j];
                proms[j]=aux;

                auxInt=notas1[i];
                notas1[i]=notas1[j];
                notas1[j]=auxInt;

                auxInt=notas2[i];
                notas2[i]=notas2[j];
                notas2[j]=auxInt;

            }
            else if(vector[i]<vector[j] && !criterio){
                auxInt=vector[i];
                vector[i]=vector[j];
                vector[j]=vector;

                aux=proms[i];
                proms[i]=proms[j];
                proms[j]=aux;

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
