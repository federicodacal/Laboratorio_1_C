#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    float precio;
}sComida;

void mostrarComidas(sComida comidas[], int comidasLength);
void mostrarComida(sComida unaComida);
int cargarDescripcionComida(int id, sComida comidas[], int comidasLength, char descrip[]);
int validarIdComida(int id, sComida comidas[], int comidasLength);
#endif // COMIDA_H_INCLUDED


