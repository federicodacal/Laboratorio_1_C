#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    int b;
    int c;
    char o;
    float f;

    printf("El size de 'a' es: %d\n", sizeof(a));
    printf("El size de 'b' es: %d\n", sizeof(b));
    printf("El size de 'o' es: %d\n", sizeof(o));
    printf("El size de 'f' es: %d\n", sizeof(f));

    printf("La direccion de 'a' es: %d\n", &a);
    printf("La direccion de 'b' es: %d\n", &b);
    printf("La direccion de 'o' es: %d\n", &o);

    return 0;
}
