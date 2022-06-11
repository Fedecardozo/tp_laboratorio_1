#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"

#define NAME_ARCHIVO "data.csv"
#define NAME_ARCHIVO_BINARIO "dataBin.csv"
#define NAME_ID "ultimoId.txt"

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
    int error;
    int borrado;
    int flagSave=0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    LinkedList* listaPasajerosBorrados = ll_newLinkedList();

    if(!controller_incioFinPrograma(NAME_ID, NAME_ARCHIVO, NAME_ARCHIVO_BINARIO,"INCIANDO PROGRAMA..."))
    {
    	puts("BIENVENIDO!!");
    }
    else
    {
    	puts("HUBO UN ERROR AL CARGAR EL PROGRAMA!");
    	exit(0);
    }

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
            case 2://Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).

                if(!controller_loadFromBinary(NAME_ARCHIVO_BINARIO,listaPasajeros))
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
            case 4://Modificar datos pasajero
            	error=controller_editPassenger(listaPasajeros);
				if(error<0)
				{
					controller_printErroresEdit(error);
				}

            	break;
            case 5://Baja pasajero

            	borrado = controller_removePassenger(listaPasajeros);

            	if(borrado<0)
            	{
            		controller_printErroresRemove(borrado);
            	}
            	else if(borrado>=0 && !controller_cargarBorrado(listaPasajerosBorrados, borrado))
            	{
            		puts("\nSE ELIMINO CON EXITO!");
            	}

            	break;
            case 6://Listar pasajeros

            	if(controller_ListPassenger(listaPasajeros) <= 0)
            	{
            		puts("\nNO HAY PASAJEROS CARGADOS!!!");
            	}
            	break;
            case 7://Ordenar pasajeros
            	error=controller_sortPassenger(listaPasajeros);
            	if(error<=0)
            	{
            		controller_printErroresSort(error);
            	}
            	break;
            case 8://Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
            	puts("\nESPERE PROCESANDO INFORMACION...");

            	if(!controller_AgregarBorrados(listaPasajeros,listaPasajerosBorrados)
            		&&	!controller_saveAsText(NAME_ARCHIVO, listaPasajeros))
            	{
            		flagSave=1;
            		if(!controller_saveBorrados(NAME_ID, 1, listaPasajerosBorrados))
            		{
						puts("\nSE GUARDO CON EXITO");
            		}
            	}
            	else
            	{
            		puts("\nNO HAY DATOS PARA GUARDAR EN EL ARCHIVO");
            	}

            	break;
            case 9://Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
            	puts("\nESPERE PROCESANDO INFORMACION...");
            	if(!controller_AgregarBorrados(listaPasajeros,listaPasajerosBorrados)
            		&& !controller_saveAsBinary(NAME_ARCHIVO_BINARIO, listaPasajeros))
				{
            		flagSave=1;
            		if(!controller_saveBorrados(NAME_ID, 0, listaPasajerosBorrados))
            		{
						puts("\nSE GUARDO CON EXITO");
            		}
				}
            	else
            	{
            		puts("\nNO HAY DATOS PARA GUARDAR EN EL ARCHIVO");
            	}
            	break;
            case 10:

            	if(!flagSave)
            	{
            		puts("\nLE FALTO GUARDAR EL ARCHIVO!");
            	}
            	else
            	{
            		if(!controller_incioFinPrograma(NAME_ID, NAME_ARCHIVO, NAME_ARCHIVO_BINARIO,"\nCERRANDO PROGRAMA..."))
            		{
            			puts("\nPROGRAMA CERRADO HASTA LUEGO!");
            		}
            	}

            	break;
            default://10. Salir
            	puts("\nHUBO UN ERROR!! INTENTELO MAS TARDE! ");
            	option=10;
            	break;
        }

    }while(option != 10 || !flagSave);
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
