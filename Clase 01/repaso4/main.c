/**
DACAL FEDERICO
DIVISION "A"
IDE: CodeBlocks

Ejercicio 3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una
división de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: libre - P: presencial – R: remota)
Cantidad de materias(mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe, en el caso que
corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)
**/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int legajo;
    char cursada;
    int cantidadMaterias;
    char sexo;
    int notaPromedio;
    int edad;
    char seguir;

    int legajoMejorPromedioFemenino;
    int mejorPromedioFemenino;

    int contadorFemenino;

    int legajoMasJovenMasculino;
    int edadMasJovenMasculino;

    int contadorMasculino;

    int contadorNoBinario;

    int acumuladorNotaMasculino;
    int acumuladorNotaFemenino;
    int acumuladorNotaNoBinario;

    float promedioMasculino;
    float promedioFemenino;
    float promedioNoBinario;

    int flagLibre;

    int flagPrimerIngreso;
    int legajoMasMaterias;
    int edadMasMaterias;

    flagPrimerIngreso=0;
    flagLibre=0;

    contadorNoBinario=0;
    contadorFemenino=0;
    contadorMasculino=0;

    acumuladorNotaMasculino=0;
    acumuladorNotaFemenino=0;
    acumuladorNotaNoBinario=0;

    do{

        printf("Ingrese nro de legajo: \n");
        scanf("%d", &legajo);
        while(legajo<0){
            printf("Error. Ingrese nro de legajo: \n");
            scanf("%d", &legajo);
        }

        printf("Ingrese tipo de cursada ('l' para libre, 'p' para presencial, 'r' para remota): \n");
        fflush(stdin);
        scanf("%c", &cursada);
        while(cursada!='l' && cursada!='p' && cursada!='r'){
            printf("Error. Ingrese tipo de cursada ('l' para libre, 'p' para presencial, 'r' para remota): \n");
            fflush(stdin);
            scanf("%c", &cursada);
        }

        printf("Ingrese cantidad de materias: \n");
        scanf("%d", &cantidadMaterias);
        while(cantidadMaterias<1 || cantidadMaterias>8){
            printf("Error. Ingrese cantidad de materias: \n");
            scanf("%d", &cantidadMaterias);
        }

        printf("Ingrese sexo ('m' para masculino, 'f' para femenino, 'o' para no binario): \n");
        fflush(stdin);
        scanf("%c", &sexo);
        while(sexo!='m' && sexo!='f' && sexo!='o'){
            printf("Error. Ingrese sexo: \n");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        printf("Ingrese nota promedio: \n");
        scanf("%d", &notaPromedio);
        while(notaPromedio<1 || notaPromedio>10){
            printf("Error. Ingrese nota promedio: \n");
            scanf("%d", &notaPromedio);
        }

        printf("Ingrese edad: \n");
        scanf("%d", &edad);
        while(edad<17 || edad>105){
            printf("Error. Ingrese edad: \n");
            scanf("%d", &edad);
        }

        switch(sexo){
            case 'm':
                contadorMasculino++;
                acumuladorNotaMasculino+=notaPromedio;
                if(cursada=='l'){
                        if(contadorMasculino==1 || edad<edadMasJovenMasculino){
                            edadMasJovenMasculino=edad;
                            legajoMasJovenMasculino=legajo;
                            flagLibre=1;
                        }
                }
                break;
            case 'f':
                contadorFemenino++;
                acumuladorNotaFemenino+=notaPromedio;
                if(contadorFemenino==1 || notaPromedio>mejorPromedioFemenino){
                    mejorPromedioFemenino=notaPromedio;
                    legajoMejorPromedioFemenino=legajo;
                }
            break;
            case 'o':
                contadorNoBinario++;
                acumuladorNotaNoBinario+=notaPromedio;
                break;
        }

        if(flagPrimerIngreso==0 || cantidadMaterias>legajoMasMaterias){
            legajoMasMaterias=legajo;
            edadMasMaterias=edad;
            flagPrimerIngreso=1;
        }

        printf("Desea continuar ingresando alumnos? s/n\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }while(seguir=='s');

    if(contadorFemenino!=0){
        printf("a) El Legajo del mejor promedio femenino: %d\nNota mejor promedio femenino: %d\n", legajoMejorPromedioFemenino,             mejorPromedioFemenino);
    }
    else{
        printf("a) No se ingresaron Femenino\n");
    }

    if(flagLibre==1){
        printf("b) El legajo del más joven de los alumnos masculinos entre los que dan libre: %d\nEdad: %d\n",  legajoMasJovenMasculino,            edadMasJovenMasculino);
    }
    else{
        printf("b)No se ingresaron Masculino Libre\n");
    }

    // Promedio notas por sexo
    if(contadorMasculino!=0){
        promedioMasculino=(float)acumuladorNotaMasculino/contadorMasculino;
        printf("c)Promedio Nota Masculino: %.2f\n", promedioMasculino);
    }
    else{
        printf("c)No se ingresaron Masculino\n");
    }

    if(contadorFemenino!=0){
        promedioFemenino=(float)acumuladorNotaFemenino/contadorFemenino;
        printf("Promedio Nota Femenino: %.2f\n", promedioFemenino);
    }
    else{
        printf("No se ingresaron Femenino\n");
    }

    if(contadorNoBinario!=0){
        promedioNoBinario=(float)acumuladorNotaNoBinario/contadorNoBinario;
        printf("Promedio Nota No Binario: %.2f\n", promedioNoBinario);
    }
    else{
        printf("No se ingresaron No Binario\n");
    }

    printf("d) La edad y legajo del que cursa mas materias: %d anios, %d\n", edadMasMaterias, legajoMasMaterias);


    return 0;
}
