#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}sSector;

int cargarDescripcionSector(int id, sSector sectores[], int sectorLength, char descrip[]);
void mostrarSectores(sSector sectores[], int sectorLength);
void mostrarSector(sSector sector);
int buscarSector(int id, sSector sectores[], int sectorLength);

#endif // SECTOR_H_INCLUDED
