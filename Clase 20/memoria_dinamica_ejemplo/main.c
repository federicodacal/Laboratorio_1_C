#include <stdio.h>
#include <stdlib.h>

int initArray(int* pArray, int len, int valor)
{
    int response=-1;
    if(pArray!=NULL && len>0){
        for(int i=0;i<len;i++){
            *(pArray+i)=valor; // pArray[i]=valor;
        }
        response=0;
    }
    return response;
}

int printArray(int* pArray, int len)
{
    int response=-1;
    if(pArray!=NULL && len>0){
        for(int i=0;i<len;i++){
            printf("%d %d\n",i+1,*(pArray+i));
        }
        response=0;
    }
    return response;
}

int resizeArray(int** pArray, int* len, int newLen)
{
    int response=-1;
    int* pArrayTemp=NULL;

    if(pArray!=NULL && len!=NULL && newLen>=0){
        pArrayTemp=(int*)realloc(*pArray,sizeof(int)*newLen);
        if(pArrayTemp!=NULL){
            *len=newLen;
            *pArray=pArrayTemp;
            pArrayTemp=NULL;
            response=0;
        }
    }
    return response;
}

int main()
{
    int* pArray=NULL;
    int lenArray=10;

    pArray=(int*)malloc(sizeof(int)*lenArray);

    if(pArray!=NULL){
        if(!initArray(pArray,lenArray,0)){
            printf("Init OK\n");
            printArray(pArray,lenArray);
        }
        else{
            printf("Hubo un problema al inicializar\n");
        }

        if(!resizeArray(&pArray,&lenArray,20)){
            printf("Resize OK\n");
            initArray(pArray,lenArray,1);
            printArray(pArray,lenArray);
        }
    }

    return 0;
}
