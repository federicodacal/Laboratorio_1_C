#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero;
	int contadorDivisores;

	contadorDivisores=0;

	printf("Ingrese el número: ");
	scanf("%d", &numero);

	for(int i=1;i<=numero;i++){
        if(numero % i == 0){
        contadorDivisores++;
		}
	}

    if (contadorDivisores==1){
		printf("no es considerado primo o compuesto");
	}
	else if (contadorDivisores==2){
		printf("es primo");
	}
	else if (contadorDivisores==0){
		printf("no puede dividir")13;
	}
	else{
		printf("no es primo");
	}
}
