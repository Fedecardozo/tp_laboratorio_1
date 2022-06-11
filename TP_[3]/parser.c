#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "validacionPassenger.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return -1 datos nulls 0 ok
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char varId[10];
	char varName[LEN_NAME];
	char varLastname[LEN_APELLIDO];
	char varPrice[10];
	char varFlycode[LEN_FLYCODE];
	char varTypePassenger[LEN_TYPE];
	char varStatusFlight[LEN_STATUSFLIGHT];
	int contDatos;
	int retorno=-1;
	int id;
	Passenger* pasajero;


	if(pFile != NULL && pArrayListPassenger != NULL)
	{

		retorno =0;

		do{

			contDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
							varId,varName,varLastname,varPrice,varFlycode,varTypePassenger,varStatusFlight);
			id = atoi(varId);
			//Verifico que no se guarde un id repetido
			if(contDatos==7 && findPassengerById(pArrayListPassenger, id)<0)
			{
				pasajero = Passenger_newParametrosTxt(varId, varName, varTypePassenger, varLastname, varPrice, varFlycode, varStatusFlight);
				//Guardo direccion de memoria en la linkedlist
				retorno=ll_add(pArrayListPassenger,pasajero);
			}

		}while(!feof(pFile));

	}


    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
