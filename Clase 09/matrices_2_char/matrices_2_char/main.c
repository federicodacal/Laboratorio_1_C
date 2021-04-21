#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    char y[10]={'x','x','x','x','x','x','x','x','x','x'};
    char z[3][10]={
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','x','x','x','x','x','x','x','x','x'}};

    x='a';
    y[7]='b';
    z[2][6]='c';

    printf("%c ",x);
    printf("%c ",y[7]);
    printf("%c ",z[2][6]);
    printf("\n");

    printf("%c\n",x);
    for(int i=0;i<10;i++){
        printf("%c",y[i]);
    }
    printf("\n");

    for(int i=0; i<3;i++){
        for(int j=0;j<10;i++){
            printf("%c",z[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return 0;
}
