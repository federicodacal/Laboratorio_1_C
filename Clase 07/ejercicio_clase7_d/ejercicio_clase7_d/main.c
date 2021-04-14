#include <stdio.h>
#include <stdlib.h>
#define LETRAS_LENGTH 6


/** \brief Busca un caracter en un array de caracteres
 *
 * \param vector[] char vector sobre el cual se realiza la busqueda
 * \param letrasLength int tamaño del vector
 * \param caracter char caracter a buscar
 * \return int retorna el indice de la primera ocurrencia
 *
 */
int buscarCaracter(char vector[], int letrasLength, char caracter);

int main()
{
    char letras[LETRAS_LENGTH]={'a','e','x','j','a','h'};
    char letraIngresada;
    int posicionLetra;

    printf("Ingrese una letra ");
    fflush(stdin);
    scanf("%c", &letraIngresada);

    posicionLetra=buscarCaracter(letras, LETRAS_LENGTH, letraIngresada);

    if(posicionLetra==-1){
        printf("No se encuentra el caracter\n");
    }
    else{
        printf("El caracter %c esta en la posicion %d\n ", letraIngresada, posicionLetra);
    }

    return 0;
}

int buscarCaracter(char vector[], int letrasLength, char caracter)
{
    int indice=-1;

    for(int i=0;i<letrasLength;i++){
        if(caracter==vector[i]){
            indice=i;
            break;  // Para encontrar la primera ocurrencia, una vez que la encuentra se hace el break. En caso de no estar el break continua recorriendo el array hasta la ultima posicion (si quiero encontrar la ultima posicion tengo que quitar el break)
        }
    }
    return indice;
}
