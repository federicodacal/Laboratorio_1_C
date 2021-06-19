#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=45;
    int numeros[]={34,21,12,56,88};

    FILE* f=fopen("archivo.bin","wb");
    FILE* f2=fopen("datos.bin","wb");

    int x;
    int vector[5];

    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    if(fwrite(&num,sizeof(int),1,f)==1){
        printf("Los datos se guardaron con exito\n");
    }
    else{
       printf("Hubo un problema al guardar los datos\n");
    }

    fclose(f);

    f=fopen("archivo.bin","rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }


    if(fread(&x,sizeof(int),1,f)==1){
        printf("Los datos se leyeron con exito\n");
    }
    else{
       printf("Hubo un problema al guardar los datos\n");
    }

    printf("x: %d\n",x);

    fclose(f);

    if(fwrite(numeros,sizeof(int),5,f2)==5){
        printf("Los datos se guardaron con exito\n");
    }
    else{
       printf("Hubo un problema al guardar los datos\n");
    }

    fclose(f2);

    f=fopen("archivo.bin","rb");
    if(f==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    if(fread(vector,sizeof(int),5,f2)==5){
        printf("Los datos se leyeron con exito\n");
    }
    else{
       printf("Hubo un problema al guardar los datos\n");
    }
    for(int i=0;i<5;i++){
        printf("%d \n",numeros[i]);
    }
    printf("\n");

    fclose(f2);

    int cont=0;
    while(!feof(f)){
        if(fread(&vector[cont],sizeof(int),1,f)<1){
            break;
        }
        cont++;
    }

    printf("Cont: %d\n",cont);


    return 0;
}
