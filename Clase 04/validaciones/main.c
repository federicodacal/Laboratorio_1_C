#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

// DOXYGEN (DOCUMENTACION DE FUNCIONES)
/** \brief (descripcion de la tarea que realiza la funcion)
 *
 * \param (parametro)
 * \return (retorno de la funcion)
 *
 */

int main()
{
    printf("%d\n", myIsDigit('9')); // 1
    printf("%d\n", myIsDigit('0')); // 1
    printf("%d\n", myIsDigit('t')); // 0
    printf("%d\n", myIsDigit('a')); // 0
    printf("%d\n", myIsDigit(':')); // 0
    printf("%d\n", myIsDigit('/')); // 0
    printf("%d\n", myIsDigit('1')); // 1
    return 0;
}
