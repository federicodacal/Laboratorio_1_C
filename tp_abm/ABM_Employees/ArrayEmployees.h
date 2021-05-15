#define NAME_LEN 51
#define LASTNAME_LEN 51

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[NAME_LEN];
    char lastName[LASTNAME_LEN];
    float salary;
    int isEmpty;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);

#endif // ARRAYEMPLOYEES_H_INCLUDED
