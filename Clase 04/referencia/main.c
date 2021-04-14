#include <stdio.h>
#include <stdlib.h>

char myToLower(char caracter);

int main()
{
    char x = 'A';

    printf("%c\n", myToLower(x)); // a
    printf("%c\n", x); // A

    x=myToLower(x);
    printf("%c\n", x);    // a
    return 0;
}

char myToLower(char caracter)
{
    if(caracter>='A' && caracter<='Z'){
        caracter+=32;
    }
    return caracter;
}
