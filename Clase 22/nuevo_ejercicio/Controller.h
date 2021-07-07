#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(LinkedList* pArrayListEmployee);
int controller_loadFromBinary(LinkedList* pArrayListEmployee);
int controller_saveAsText(LinkedList* pArrayListEmployee);
int controller_saveAsBinary(LinkedList* pArrayListEmployee);
int controller_List(LinkedList* pArrayList);

#endif
