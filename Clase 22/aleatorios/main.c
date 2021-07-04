#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int numero;
    int max=200;
    int min=100;

    numero=rand()%(max-min+1)+min;
    printf("%d\n",numero);
//    numero=rand();
//    printf("%d\n",numero);
//    numero=rand();
//    printf("%d\n",numero);
//    numero=rand();
//    printf("%d\n",numero);
//    numero=rand();
//    printf("%d\n",numero);

    return 0;
}
