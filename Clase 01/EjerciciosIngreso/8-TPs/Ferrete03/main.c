/**
3. Para el departamento de Pinturas:
A. Al ingresar una temperatura en Fahrenheit debemos mostrar la temperatura en Centígrados con un mensaje concatenado (ej.: " 32 Fahrenheit son 0 centígrados").
B. Al ingresar una temperatura en Centígrados debemos mostrar la temperatura en Fahrenheit (ej.: "0 centígrados son 32 Fahrenheit ").
**/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float convertirEnFarenheit(float a);
float convertirEnCentigrados(float a);

int main()
{
    char opcion;
    float temperatura;
    float temperaturaC;
    float temperaturaF;

    printf("Seleccione escala de la temperatura: f=Farenheit, c=Centigrados ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);
    while(opcion!='f' && opcion!='c'){
        printf("Error. Seleccione escala: f=Farenheit, c=Centigrados ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion=tolower(opcion);
    }

    if(opcion=='c'){
        printf("Ingrese la temperatura en C: ");
        scanf("%f", &temperatura);
        temperaturaF=convertirEnFarenheit(temperatura);
        printf("%.2f F", temperaturaF);

    }
    else{
        printf("Ingrese la temperatura en F: ");
        scanf("%f", &temperatura);
        temperaturaC=convertirEnCentigrados(temperatura);
        printf("%2.f C", temperaturaC);
    }

    return 0;
}

float convertirEnCentigrados(float a){
    float temperaturaC;

    temperaturaC= (float) (a-32)/1.8;
    return temperaturaC;
}

float convertirEnFarenheit(float a){
    float temperaturaF;

     temperaturaF=a*1.8+32;
     return temperaturaF;
}
