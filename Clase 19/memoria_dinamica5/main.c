#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=10;
    int* p=&x;
    int** q=&p;

    int y;
    int* z=(int*)malloc(sizeof(int));
    int** r=(int**)malloc(sizeof(int*));


    printf("Maneras de mostrar valor de x\n");
    printf("x vale: %d\n",x);
    printf("x vale: %d\n",*p);
    printf("x vale: %d\n",**q);

    printf("Maneras de asignar valor a x\n");
    x=20;
    printf("x vale: %d\n",x);
    *p=25;
    printf("x vale: %d\n",x);
    **q=30;
    printf("x vale: %d\n",x);


    return 0;
}
