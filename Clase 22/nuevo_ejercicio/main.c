#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include <time.h>

int main()
{
    LinkedList* list=ll_newLinkedList();
    if(list==NULL){
        printf("No se pudo crear LinkedList\n");
        system("pause");
        exit(1);
    }

    if(!controller_loadFromText(list)){
        printf("El archivo se cargo correctamente\n");
        controller_List(list);
    }

    return 0;
}
