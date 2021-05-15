#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#define NOMBRE_LENGTH 50
#define DESCRIPCION_LENGTH 55

typedef struct{
    int id;
    char nombre[NOMBRE_LENGTH];
    char descripcion[DESCRIPCION_LENGTH];
    int cantidad;
    float precio;
    int isEmpty;
}sProducto;

int setStatus(sProducto productos[], int productosLength, int value);
int findEmpty(sProducto productos[], int productosLength);
int findProductById(sProducto productos[], int productosLength, int idProd);
int prod_imprimir(sProducto* aux);
int prod_initArray(sProducto* productos, int productosLength);
int prod_updateArray(sProducto* productos, int productosLength, int indice);
int prod_getEmptyIndex(sProducto* productos, int productosLength);
int prod_printArray(sProducto* productos, int productosLength);
#endif // PRODUCTO_H_INCLUDED
