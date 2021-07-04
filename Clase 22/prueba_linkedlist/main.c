#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[40];
    char sexo;
    int edad;
}Mascota;

void mostrarMascota(Mascota* m);
void mostrarMascotas(LinkedList* list);
int filterHembras(void* pElement);
int filterCachorros(void* pElement); // menos de dos anios
int filterBunny(void* pElement);

int main()
{
    LinkedList* list=ll_newLinkedList();

    Mascota m1={1234,"Bobby",'m',2};
    Mascota m2={3322,"Pepe",'m',3};
    Mascota m3={6543,"Lola",'h',1};
    Mascota m4={1111,"Bunny",'h',6};
    Mascota m5={9891,"Sussie",'h',9};
    Mascota m6={2310,"Lolo",'m',1};

    ll_add(list,&m1); // Paso mascota por refencia porque es estatica
    ll_add(list,&m2);
    ll_add(list,&m3);
    ll_add(list,&m4);
    ll_add(list,&m5);
    ll_add(list,&m6);

    mostrarMascotas(list);

    LinkedList* hembras=ll_filter(list,filterHembras);
    mostrarMascotas(hembras);

    LinkedList* cachorros=ll_filter(list,filterCachorros);
    mostrarMascotas(cachorros);

    LinkedList* bunny=ll_filter(list,filterBunny);
    mostrarMascotas(bunny);


    return 0;
}

void mostrarMascota(Mascota* m)
{
    if(m!=NULL){
        printf("%d  %s  %c      %d\n",m->id, m->nombre, m->sexo, m->edad);
    }
}

void mostrarMascotas(LinkedList* list)
{
    int len;
    if(list!=NULL){
        len=ll_len(list);
        printf("ID  Nombre  Sexo  Edad\n");
        for(int i=0;i<len;i++){
            mostrarMascota((Mascota*)ll_get(list,i));
        }
        printf("\n");
    }
}

int filterHembras(void* pElement)
{
    return((Mascota*)pElement)->sexo=='h';
}

int filterCachorros(void* pElement) // menos de dos anios
{
    return((Mascota*)pElement)->edad<2;
}

int filterBunny(void* pElement)
{
    int retorno=0;
    if(!strcmp(((Mascota*)pElement)->nombre,"Bunny")){
        retorno=1;
    }
    return retorno;
}

