#include <stdio.h>
#include <stdlib.h>

int swap(char* p, char* q);

int main()
{
    int x=10;
    int y=12;
    int auxInt=sizeof(int);

    char unChar='a';
    int auxChar=sizeof(char);

    char arrayString[5]="Hola";
    int auxString=sizeof(arrayString);

    printf("Sizeof de int: %d\n",auxInt);
    printf("Dir x: %p\n",&x);
    printf("Dir y: %p\n\n",&y);

    printf("Sizeof de char: %d\n",auxChar);
    printf("Dir a: %p\n\n",&unChar);

    printf("Sizeof de array string: %d\n",auxString);
    printf("Dir arrayString: %p\n\n",arrayString);

    // SWAP
    char a='1';
    char b='2';
    char c;

    c=a;
    a=b;
    b=c;

    swap(&a,&b);

    return 0;
}

int swap(char* p, char* q)
{
    char r;

    r=*p;   // Operador de indireccion, el contenido apuntado por p lo guardamos en r
    *p=*q;
    *q=r;

    return 0;
}
