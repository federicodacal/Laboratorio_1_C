#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

char sexos[20][20]={
    "masculino",
    "femenino",
    "femenino",
    "masculino",
    "masculino",
    "femenino",
    "masculino",
    "masculino",
    "femenino",
    "femenino",
    "masculino",
    "femenino",
    "femenino",
    "masculino",
    "masculino",
    "femenino",
    "masculino",
    "masculino",
    "femenino",
    "femenino"
};

char names[20][20]={
    "Donato",
    "Carmen",
    "Chepi",
    "Alex",
    "German",
    "Maria",
    "Damian",
    "Daniel",
    "Andrea",
    "Candela",
    "Dario",
    "Camila",
    "Cecilia",
    "Alan",
    "Gaston",
    "Mariana",
    "David",
    "Roberto",
    "Anna",
    "Lucrecia"
};

char lastNames[20][20]={
    "De Sanctis",
    "Miranda",
    "Viaggi",
    "Caniggia",
    "Martin",
    "Rosas",
    "Betular",
    "Araoz",
    "Rincon",
    "Vetrano",
    "Rodriguez",
    "Rossellini",
    "Torres",
    "Carter",
    "Gunther",
    "Martinez",
    "Di Leo",
    "Gomez",
    "Martel",
    "Arendt"
};


char telefonos[20][TELEFONO_LEN]={
    "123412345",
    "156543576",
    "145454666",
    "154156789",
    "295414568",
    "112457789",
    "455634689",
    "113445567",
    "156576787",
    "123454657",
    "135678900",
    "943001234",
    "123434545",
    "151516789",
    "159524714",
    "151767879",
    "167687998",
    "991124355",
    "445457675",
    "498003445"
};

char direcciones[20][91]={
    "Av. San Martin 1234",
    "Scalabrini Ortiz 456",
    "Av. Mitre 4123",
    "Av. Rivadavia 345",
    "Montevideo 5023",
    "Roosevelt 1054",
    "Av. Triunvirato 9842",
    "Av. Rivadavia 9023",
    "Av. Mitre 504",
    "Pellegrini 754",
    "Wilde 5466",
    "Francia 3467",
    "Habana 5642",
    "Segurola 7963",
    "Independencia 153",
    "Bonifacio 345",
    "Uruguay 6434",
    "9 de Julio 1405",
    "Av. Santa Fe 1064",
    "Alvear 8512"
};

char localidades[20][51]={
    "Avellaneda",
    "CABA",
    "CABA",
    "Lanus",
    "La Plata",
    "CABA",
    "Florencio Varela",
    "Quilmes",
    "Pilar",
    "Moreno",
    "Avellaneda",
    "Lomas de Zamora",
    "Escobar",
    "Ezeiza",
    "CABA",
    "Avellaneda",
    "CABA",
    "La Matanza",
    "Lomas de Zamora",
    "Avellaneda"
};

float salaries[20]={1000,1000,1420,1350,2000,1950,2150,1060,1742,1800,1000,1000,1420,1350,2000,1950,2150,1060,1742,1800};

int idSectors[20]={500,504,501,501,502,503,502,504,502,500,500,504,501,501,502,503,502,504,502,500};

int ids[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

/** \brief Carga una lista predeterminada a lista de employees
 *
 * \param list[] Employee
 * \param len int
 * \param qty int
 * \param pId int*
 * \return int Lugares ocupados
 *
 */
int hcodeEmployees(Cliente list[], int len, int qty, int* pId)
{
    int places=0;

    if(list!=NULL && len>0 && qty>=0 && qty<=len && pId!=NULL){
        for(int i=0;i<qty;i++){
            list[i].codigo=*pId;
            (*pId)++;
            strncpy(list[i].nombre, names[i],sizeof(list[i].nombre));
            strncpy(list[i].apellido, lastNames[i],sizeof(list[i].apellido));
            strncpy(list[i].sexo, sexos[i],sizeof(list[i].sexo));
            strncpy(list[i].telefono, telefonos[i],sizeof(list[i].telefono));
            strncpy(list[i].domicilio, direcciones[i],sizeof(list[i].domicilio));
            list[i].isEmpty=0;
            places++;
        }
    }

    return places;
}
