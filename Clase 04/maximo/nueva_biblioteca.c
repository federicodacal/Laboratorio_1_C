#include "nueva_biblioteca.h"

int maximun(int a, int b, int c)
{
    int maximo;

    if(a>b && a>c){
        maximo=a;
    }
    else if(b>=a && b>c){
        maximo=b;
    }
    else{
        maximo=c;
    }
    return maximo;
}

int esPar(int num)
{
    int respuesta=0; // No es par
    if(num%2==0){
        respuesta=1; // Par
    }
    return respuesta;
}

/*
int esPar(int num)
{
    return !(num%2);
}
*/
