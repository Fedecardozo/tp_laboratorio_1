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
 * @return 1 un exito 0 ok(-1)Datos nullos (-2) No se encontro ID
 * (-3)Ingreso mal las opciones
 * (-4)Ingreso mal los datos a modificar
 * (-5)mal respuesta de si esta seguro
 * (-6)mal respuesta si desea continuar
 * (-7)Lista vacia
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{

	int retorno =-1;
	int id;

	if(pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger) > 0)
		{
			//HASTA ACA EL RETORNO ES -1
			if(utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 1, 9999, 2)==0)
			{

				//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
				retorno=editPassenger(pArrayListPassenger,id);


			}

		}
		else
		{
			//LISTA VACIA
			retorno =-7;
		}

	}




	return retorno;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return >0 devuelve el id
 * -1 datos nullos
 * -2 no existe el id
 * -3 lista vacia
 * -4 no se borro
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;
	int rta;

	if(pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger) > 0)
		{
			if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 9999, 2)==0)
			{
				rta=removePassenger(pArrayListPassenger, id);
				if(rta>=0)
				{

					//ESTA OK
					retorno = id;

				}
				else if(rta==-1)
				{

					//NO EXISTE ID
					retorno=-2;

				}
				else if(rta==-2)
				{
					//No se borro
					retorno=-4;
				}


			}

		}
		else
		{
			//Lista vacia
			retorno = -3;
		}

	}


	return retorno;
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
 * \return -1 lista nulla,-2 lista vacia
 *   -3 No se ordeno
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int criterio;
	int opc;

	if(pArrayListPassenger != NULL )
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			opc=opcionesSort(&criterio);

			puts("\nESPERE PROCESANDO INFORMACION...");
			switch(opc)
			{
				case 1:retorno=ll_sort(pArrayListPassenger, sortName, criterio); break;
				case 2:retorno=ll_sort(pArrayListPassenger, sortApellido, criterio); break;
				case 3:retorno=ll_sort(pArrayListPassenger, sortId, criterio); break;
				case 4:retorno=ll_sort(pArrayListPassenger, sortPrecio, criterio); break;
				default: retorno=-3; break;
			}

		}
		else
		{
			retorno=-2;
		}

	}

	return retorno;
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

/// @fn int controller_printErroresEdit(int)
/// @param error
/// @return 0ok -1 no habia errores
int controller_printErroresEdit(int error)
{
	int retorno=-1;

	if(error<0)
	{
		retorno=0;
		switch(error)
		{
			case -1: puts("\nHUBO UN PROBLEMA INTENTELO MAS TARDE!"); break;
			case -2: puts("\nNO SE ENCONTRO EL ID!"); break;
			case -3: puts("\nOPCION INCORRECTA!"); break;
			case -4: puts("\nDATOS INVALIDOS!"); break;
			case -5:
			case -6:	puts("\nRESPUESTA INCORRECTA"); break;
			case -7: puts("\nNO HAY PASAJEROS PARA CARGADOS!"); break;
		}
	}

	return retorno;
}

/// @fn int controller_printErroresRemove(int)
/// @param error
/// @return 0 ok -1 no habia errores
int controller_printErroresRemove(int error)
{
	int retorno=-1;

	if(error<=0)
	{
		retorno=0;
		switch(error)
		{
			case -1: puts("\nHUBO UN PROBLEMA INTENTELO MAS TARDE!"); break;
			case -2: puts("\nNO SE ENCONTRO EL ID!"); break;
			case -3: puts("\nNO HAY PASAJEROS PARA CARGADOS!"); break;
			case -4: puts("\nNO SE BORRO EL PASAJERO!"); break;
		}
	}

	return retorno;
}

/// @fn int controller_printErroresSort(int)
/// @param error
/// @return 0 ok -1 no habia errores
int controller_printErroresSort(int error)
{
	int retorno=-1;

	if(error<=0)
	{
		retorno=0;
		switch(error)
		{
			case 0: puts("\nSE ORDENO EXISOTOSAMENTE"); break;
			case -1: puts("\nHUBO UN PROBLEMA INTENTELO MAS TARDE!"); break;
			case -2: puts("\nNO HAY PASAJEROS PARA CARGADOS!"); break;
			case -3: puts("\nNO SE ORDENO!"); break;
		}
	}

	return retorno;
}
