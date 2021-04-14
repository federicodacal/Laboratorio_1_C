#include "biblioteca.h"

int myIsDigit(char x)
{
    int esDigito;

    if (x>=48 && x<=57){
    // if(x>='0' && x<='9'){
        esDigito=1;
    }
    else{
        esDigito=0;
    }
    return esDigito;
}
