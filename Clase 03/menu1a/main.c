#include <stdio.h>
#include <stdlib.h>

int main()
{
    char salir;
    char opcion;
    int flagSaludar;
    int flagBrindis;

    flagSaludar=0;
    flagBrindis=0;
    salir='n';

    do{

        system("cls");
        printf("***Menu de Opciones***\n\na.Saludar\nb.Brinds\nc.Despedir\nd.Salir\n");
        printf("\nIngrese opcion: \n");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion){
        case 'a':
            printf("\nHola!!!\n");
            flagSaludar=1;
            system("pause");
            break;
        case 'b':
            if(flagSaludar==1){
                printf("\nChin, chin!!!\n");
                flagBrindis=1;
                system("pause");
            }
            else{
                printf("\nAntes de brindar es necesario saludarse.\n");
                system("pause");
            }
            break;
        case 'c':
            if(flagSaludar && !flagBrindis){
                printf("\nPrimero brindemos.\n");
                system("pause");
            }
            else if(flagSaludar && flagBrindis){
                printf("\nHasta luego!\n");
                flagSaludar=0;
                flagBrindis=0;
                system("pause");
            }
            else{
                printf("\nAntes de despedirnos deberiamos saludarnos.\n");
                system("pause");
            }
            break;
        case 'd':
            printf("Confirma salida? s/n \n");
            fflush(stdin);
            salir=getchar();
            if(salir=='s'){
                printf("\nSaliste.\n");
            }
            break;
        default:
            printf("\nNo es una opcion valida.\n");
            system("pause");
            break;
        }

    }while(salir!='s');

    return 0;
}
