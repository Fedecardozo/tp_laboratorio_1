#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "validacionPassenger.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return -2 Error al abrir el archivo, -1 datos nullos
 *  0 ok
 *
 */
int controller_loadFromText(char* path,LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* archivo;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		archivo=fopen(path,"r");

		if(archivo != NULL)
		{
			retorno=parser_PassengerFromText(archivo, pArrayListPassenger);
			fclose(archivo);
		}
		else
		{
			//Error al abrir el archivo
			retorno = -2;
		}



	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 0 ok pedir datos, -1 datos nullos, -2 erros al pedir datos
 *   -3 error al obtener id, 1 Salio Ok validando id
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int auxID;
	Passenger aux;
	Passenger* dirPassenger;

	if(pArrayListPassenger != NULL)
	{
		if(pedirDatoPassenger(&aux)==0){

			retorno=0;

			//Genero Id
			auxID=generadorId();

			//Valido Id
			if(auxID > 0)
			{
				aux.id=auxID;

				//Ya se da de alta
				dirPassenger=Passenger_newPassenger(aux);

				if(dirPassenger != NULL && !ll_add(pArrayListPassenger, dirPassenger))
				{
					//Se dio de alta
					retorno=0;
				}

			}
			else
			{
				retorno=-3;
			}


		}
		else
		{

			retorno =-2;

		}
	}

	return retorno;

}


/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return -1 datos nullos,0 no hay cargados
 * >0 cantidad de la lista
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int i=0;
	Passenger* aux;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>=0)
	{

		for(i=0; i<ll_len(pArrayListPassenger);i++)
		{
			aux = (Passenger*)ll_get(pArrayListPassenger, i);
			imprimirUnPassenger(aux);

		}

		retorno=i;
	}

	 return retorno;;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}
