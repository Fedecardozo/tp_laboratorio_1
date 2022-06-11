
#include "funcionesController.h"

/// @fn int verificacionEliminados(LinkedList*)
/// @brief borra los que estan eliminados de la lista
/// @param pArrayListPassenger
/// @return -1 parametro null o len <=0, 0 ok
int verificacionEliminados(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* aux;
	char nombre[LEN_NAME];
	char nameBorrado[LEN_NAME] = "borrado";

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>0)
	{
		retorno =0;
		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			aux=(Passenger*)ll_get(pArrayListPassenger, i);
			if(!Passenger_getNombre(aux, nombre) && strcmp(nombre,nameBorrado)==0)
			{
				aux = (Passenger*)ll_pop(pArrayListPassenger, i);;
				i--;

			}
		}
	}

	return retorno;
}

/// @fn LinkedList controller_verificarArchivo*(char*, LinkedList*, int(*)(char*, LinkedList*))
/// @brief Genera la lista que se va a guardar
/// @param path
/// @param pArrayListPassenger
/// @param pFuncLoad
/// @return nueva LinkedList
LinkedList* perfeccionaLista(char* path,LinkedList* pArrayListPassenger,int (*pFuncLoad)(char*,LinkedList*))
{
	LinkedList* auxLinked = ll_newLinkedList();

	if(path != NULL && pArrayListPassenger != NULL && pFuncLoad != NULL)
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			auxLinked = ll_clone(pArrayListPassenger);

		}

		//Esta funcion ya verifica que no se repitan  //verificar eliminados
		//Si sale tod mal borra la lista auxiliar
		if(pFuncLoad(path,auxLinked)<0 || verificacionEliminados(auxLinked)<0)
		{
			controller_ListPassenger(auxLinked);
			ll_clear(auxLinked);
			ll_deleteLinkedList(auxLinked);
			auxLinked = ll_clone(pArrayListPassenger);
		}

	}

	return auxLinked;

}

/// @fn int controller_saveId(char*)
/// @brief guarda el id en el archivo
/// @param path
/// @return
int controller_saveId(char* path)
{
	int retorno=-1;

	if(path != NULL)
	{
		retorno = generadorId_saveArchivo(path);
	}


	return retorno;
}

/// @fn int controller_saveModeAndId(char*,int mode)
/// @param path
/// @return -1 datos nullos, 0 ok
int controller_saveModeAndId(char* path,int mode)
{

	int retorno=-1;
	FILE* archivo;

	if(path != NULL && mode>=0 && mode<=2)
	{
		//guardo el id primero
		if(!generadorId_saveArchivo(path))
		{
			archivo=fopen(path,"r+");

			if(archivo != NULL)
			{
				fseek(archivo , 0 , SEEK_END);
				fprintf(archivo,"\n%d",mode);
				fclose(archivo);
				retorno=0;

			}
		}


	}

	return retorno;

}

/// @fn int controller_saveModeAndId(char*,int mode)
/// @param path
/// @return -1 datos nullos, 0 ok
int controller_saveBorrados(char* path,int mode,LinkedList* listaBorrados)
{

	int retorno=-1;
	FILE* archivo;
	int borradoId=0;

	if(path != NULL && listaBorrados!=NULL && mode>=0 && mode<=2)
	{
		retorno=0;
		archivo=fopen(path,"r+");

		//guardo el id Y el modo primero
		if(!controller_saveModeAndId(path, mode) && ll_len(listaBorrados)>0 && mode <2)
		{
			if(archivo != NULL)
			{
				for (int i = 0; i < ll_len(listaBorrados); i++)
				{
					if(!Passenger_getId((Passenger*)ll_get(listaBorrados, i), &borradoId))
					{
						fseek(archivo , 0 , SEEK_END);
						fprintf(archivo,"\n%d",borradoId);
					}
				}

				fprintf(archivo,"\n%d",0);
			}
		}
		else if(archivo != NULL)
		{
			fseek(archivo , 0 , SEEK_END);
			fprintf(archivo,"\n%d",borradoId);
			if(mode == 2 && verificacionEliminados(listaBorrados))
			{

				retorno = 0;
			}
		}

		fclose(archivo);
	}

	return retorno;

}

/// @fn int controller_saveModeAndId(char*,int mode)
/// @param path
/// @return -1 datos nullos, 0 ok
int controller_readBorrados(char* path,LinkedList* listaBorrados)
{
	int retorno=-1;
	FILE* archivo;
	int i=0;
	int borrado;

	if(path != NULL && listaBorrados!=NULL)
	{
		retorno=0;
		archivo=fopen(path,"r");

		if(archivo != NULL)
		{
			do
			{
				i++;

				if(fscanf(archivo,"%d\n",&borrado)==1 && i>=3 && borrado != 0)
				{
					retorno=controller_cargarBorrado(listaBorrados, borrado);
				}

			}while(!feof(archivo));

		}

		fclose(archivo);
	}

	return retorno;

}

/// @fn int controller_actualizacion(int, char*, char*, LinkedList*)
/// @brief segun el ultimo modo guardado, actualiza
/// @param modo
/// @param pathBin
/// @param pathText
/// @param pArrayListPassenger
/// @return -1 parametros nullos, 0 ok
int controller_actualizacion(int modo,char* pathBin, char* pathText,LinkedList* pArrayListPassenger){

	int retorno=-1;
	LinkedList* auxLinked = ll_newLinkedList();

	if(modo>=0 && modo<=2 && pathBin != NULL && pathText != NULL && pArrayListPassenger != NULL)
	{

		if(modo == 2)
		{
			//ya esta actualizado
			retorno=0;
		}
		else if(modo==0)
		{
			//modo 0, entonces se guardo en binario por ultima vez
			//actualizo, leo del binario y guardo en modo texto
			//auxLinked = perfeccionaLista(pathBin, pArrayListPassenger, controller_loadFromBinary);
			if(!controller_saveAsTextInvertido(pathText,pathBin, pArrayListPassenger))
			{

				retorno=0;
			}

		}
		else if(modo==1)
		{

			//modo 1, entonces se guardo en texto por ultima vez
			//actualizo, leo del texto y guardo en modo binario
			//auxLinked = perfeccionaLista(pathText, pArrayListPassenger, controller_loadFromText);
			if(!controller_saveAsBinaryInvertido(pathText,pathBin, pArrayListPassenger))
			{

				retorno=0;
			}
		}

	}
	ll_clear(auxLinked);
	ll_deleteLinkedList(auxLinked);

	return retorno;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsTextInvertido(char* pathTxt,char* pathBin , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int i;
	Passenger* aux;
	LinkedList* auxLinked = ll_newLinkedList();
	char pasajero[sizeof(Passenger)];

	if(pathTxt != NULL && pathBin != NULL && pArrayListPassenger != NULL)
	{
		//Clono la lista tal cual viene por parametro y cargo con el archivo
		auxLinked = perfeccionaLista(pathBin, pArrayListPassenger,controller_loadFromBinary);
		//Elimino los borrados de la lista original
		verificacionEliminados(pArrayListPassenger);

		if(auxLinked != NULL && !File_openModeReadWriteTxt(pathTxt, "w+"))
		{
			for(i=0; i<ll_len(auxLinked);i++)
			{
				aux = (Passenger*)ll_get(auxLinked, i);
				if(!Passenger_getTxt(aux, pasajero))
				{
					retorno = File_openWriteTxtSave(pathTxt, pasajero,"r+",SEEK_END);

				}
			}

		}
		else
		{
			retorno = -2;
		}

		ll_clear(auxLinked);
		ll_deleteLinkedList(auxLinked);

	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinaryInvertido(char* pathTxt,char* pathBin  , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int i=1;
	Passenger* aux;
	LinkedList* auxLinked = ll_newLinkedList();
	//char pasajero[sizeof(Passenger)];

	if(pathTxt != NULL && pathBin != NULL && pArrayListPassenger != NULL)
	{

		//Clono la lista tal cual viene por parametro y cargo con el archivo
		auxLinked = perfeccionaLista(pathTxt, pArrayListPassenger,controller_loadFromText);

		//Elimino los borrados de la lista original
		verificacionEliminados(pArrayListPassenger);

		if(auxLinked != NULL && !File_openModeReadWriteTxt(pathBin, "wb"))
		{
			for(i=0; i<ll_len(auxLinked);i++)
			{
				aux = (Passenger*)ll_get(auxLinked, i);
				if(aux != NULL)
				{

					retorno=File_openWriteBinarioSave(pathBin, aux, sizeof(Passenger), "r+b",SEEK_END);

				}
			}

		}
		else
		{
			//La lista son iguales no realizo ningun cambio
			//por ende no se pudo guardar
			retorno = -2;
		}

		ll_clear(auxLinked);
		ll_deleteLinkedList(auxLinked);

	}

    return retorno;
}

/// @fn int controller_AgregarBorrados(LinkedList*, LinkedList*)
/// @brief agrega de una lista a la otra
/// @param pArrayListPassenger
/// @param pArrayListPassengerBorrados
/// @return -1 datos nullos, 0 ok
int controller_AgregarBorrados(LinkedList* pArrayListPassenger,LinkedList* pArrayListPassengerBorrados)
{
	int retorno=-1;

	if(pArrayListPassenger != NULL && pArrayListPassengerBorrados != NULL)
	{
		retorno =0;

		if(ll_len(pArrayListPassengerBorrados) > 0)
		{

			for(int i=0; i<ll_len(pArrayListPassengerBorrados);i++)
			{
				if(!ll_add(pArrayListPassenger,(Passenger*)ll_get(pArrayListPassengerBorrados, i)))
				{

					retorno =0;
				}

			}
		}
	}

	return retorno;
}

/// @fn int controller_cargarBorrado(LinkedList*, int)
/// @brief carga los borrados con el id a la lista
/// pasada por parametro
/// @param pArrayListPassengerBorrados
/// @param idBorrado
/// @return -1 parametro nulls o id <=0, 0 ok
int controller_cargarBorrado(LinkedList* pArrayListPassengerBorrados,int idBorrado)
{
	int retorno=-1;
	Passenger* auxBorrados;

	if(pArrayListPassengerBorrados != NULL && idBorrado>0)
	{
		retorno =0;

		auxBorrados = Passenger_new();

		if(!Passenger_setId(auxBorrados, idBorrado) && !Passenger_setNombre(auxBorrados, "borrado")
				&& !ll_add(pArrayListPassengerBorrados,auxBorrados))

		{
			retorno =0;
		}

	}

	return retorno;
}
