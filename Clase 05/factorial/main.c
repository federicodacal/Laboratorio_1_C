#include <stdio.h>
#include <stdlib.h>

int factorial (int n);

int main()
{
    printf("%d\n", factorial(5));
    return 0;
}

int factorial (int n)
{
    int fac=1;

    for(int i=1;i<=n;i++){
        fac*=i;
    }
    return fac;
}
