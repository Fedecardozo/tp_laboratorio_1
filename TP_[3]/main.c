#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

#define NAME_ARCHIVO "data.csv"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();

int main()
{
	setbuf(stdout,NULL);

    int option=0;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	option = menu();
        switch(option)
        {
        	case 1://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).

				if(!controller_loadFromText(NAME_ARCHIVO,listaPasajeros))
				{
					puts("\nCARGA EXITOSA!!");

				}
				else
				{
					puts("\nHUBO UN ERROR AL CARGAR LA INFORMACION. INTENTELO MAS TARDE...");
				}
				break;
            case 3://Alta pasajero

            	if(!controller_addPassenger(listaPasajeros))
            	{
            		puts("\nSE DIO DE ALTA CON EXITO! ");
            	}
            	else
            	{
            		puts("\nHUBO UN PROBLEMA INTENTELO MAS TARDE ");
            	}

            	break;
            case 6:

            	if(controller_ListPassenger(listaPasajeros) <= 0)
            	{
            		puts("\nNO HAY PASAJEROS CARGADOS!!!");
            	}
            	break;
        }
    }while(option != 10);
    return 0;
}

int menu()
{
	int num=11;

	utn_getNumero(&num,"\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
			"\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
			"\n3. Alta de pasajero"
			"\n4. Modificar datos de pasajero"
			"\n5. Baja de pasajero"
			"\n6. Listar pasajeros"
			"\n7. Ordenar pasajeros"
			"\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
			"\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
			"\n10. Salir"
			"\nINGRESE OPCION: "
			,"\nOPCION INVALIDA.\nIngrese nuevamente: ", 1, 10, 2);

	return num;
}
