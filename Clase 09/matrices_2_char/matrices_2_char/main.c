#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    z[0][8]='c';
    z[1][4]='c';
    z[2][6]='c';

    printf("%c ",x);
    printf("%c ",y[7]);
    printf("%c ",z[2][6]);
    printf("\n");
    printf("%c\n",x);

    for(int i=0;i<10;i++){
        printf("%c",y[i]);
    }
    printf("\n\n");

    for(int i=0; i<3;i++){
        for(int j=0;j<10;j++){
            printf("%c",z[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    strcpy(y,"Juan");
    strcpy(z[1],"Juan");
    strcpy(z[2],"Pepe");

        for(int i=0;i<10;i++){
        printf("%c",y[i]);
    }
    printf("\n\n");

    for(int i=0; i<3;i++){
        for(int j=0;j<10;j++){
            printf("%c",z[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return 0;
}
