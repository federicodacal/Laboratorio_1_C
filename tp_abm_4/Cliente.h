#define NAME_LEN 51
#define APELLIDO_LEN 51
#define TELEFONO_LEN 21
#define DOMICILIO_LEN 91

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[NAME_LEN];
    char apellido[APELLIDO_LEN];
    char sexo[20];
    char telefono[TELEFONO_LEN];
    char domicilio[DOMICILIO_LEN];
    int isEmpty;
}Cliente;

int initClientes(Cliente list[], int len);
int addCliente(Cliente list[], int len, int* pCodigo);
int findEmptyIndex(Cliente list[], int len);
void printCliente(Cliente cliente);
int printClientes(Cliente list[], int len);
int removeCliente(Cliente list[], int len);
int findClientById(Cliente list[], int len, int id);
int updateCliente(Cliente list[], int len);
int modifyCliente(Cliente list[], int len, int index);
int sortClientesByLastName(Cliente list[], int len);

#endif // CLIENTE_H_INCLUDED
