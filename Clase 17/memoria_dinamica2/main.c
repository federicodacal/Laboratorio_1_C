#include <stdio.h>
#include <stdlib.h>

int mostrarEnteros(int* vec, int len);

int main()
{
    int numeros[5];

    int* aux=NULL; // Inicializar variable de puntero

    int* vector=(int*)malloc(5*sizeof(int));

    for(int i=0;i<5;i++){
        printf("#%d Ingrese un nro: ",i+1);
        scanf("%d", &numeros[i]);
    }

    for(int i=0;i<5;i++){
        printf("\n%d ",numeros[i]);
    }
    printf("\n");
    ///////////////////////////////////////////////////////////////////////////////

    for(int i=0;i<5;i++){
        printf("#%d Ingrese un nro: ",i+1);
        scanf("%d", &vector[i]);
    }
    for(int i=0;i<5;i++){
        printf("\n%d ",vector[i]);
    }
    printf("\n");
    ///////////////////////////////////////////////////////////////////////////////

    // Nomenclatura de 'corchetes' o vectorial
    for(int i=0;i<5;i++){
        printf("#%d Ingrese un nro: ",i+1);
        scanf("%d", &vector[i]);
    }
    for(int i=0;i<5;i++){
        printf("\n%d ",vector[i]);
    }
    printf("\n");
    ///////////////////////////////////////////////////////////////////////////////

    // Nomenclatura de punteros
    for(int i=0;i<5;i++){
        printf("#%d Ingrese un nro: ",i+1);
        scanf("%d",vector+i);
    }
    for(int i=0;i<5;i++){
        printf("\n%d ",*(vector+i));
    }
    printf("\n");


    mostrarEnteros(vector,5);

    // Agrandar vector
    aux(int*)realloc(vector,sizeof(int)*10);
    if(aux==NULL){
        printf("No se pudo conseguir memoria \n");
        system("pause");
        exit(1);
    }

    vector+aux;
    aux=NULL;
    printf("Vector agrandado");

    free(vector);
    return 0;
}

int mostrarEnteros(int* vec, int len)
{
    int response=-1;
    if(vec!=NULL && len>0){
        for(int i=0;i<len;i++){
            printf("%d", *(vec+i));
        }
        printf("\n");
        response=0;
    }
    return response;
}
