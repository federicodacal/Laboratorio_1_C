#include <stdio.h>
#include <stdlib.h>

int factorialRec (int n);

int main()
{
    printf("%d\n", factorialRec(5));
    return 0;
}

int factorialRec (int n)
{
    int fact;
    if(n==1 || n==0){
        fact=1; //valor de corte
    }
    else{
        fact=n*factorialRec(n-1);
    }
    return fact;
}
