
#include "vuelo.h"

static int generadorId();

/// @fn int VueloeradorId()
/// @brief Vueloera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=1000;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array están vacías,
/// esta función pone la bandera (isEmpty) en VERDADERO en todos
/// posiciónes del array
/// \param list Vuelo* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int Vuelo_Inicializar(Vuelo *list, int len){

	int retorno=-1;
	int i;

	if(list != NULL && len >0){

		for (i = 0; i < len; i++) {

			list[i].isEmpty=LIBRE;

		}

		retorno = 0;

	}

	return retorno;


}

/// @fn ObtenerIndexLibre
/// @param list recibe un array tipo Vuelo
/// @param len es el lenaño del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
int ObtenerIndexLibre(Vuelo* list, int len){

	int retorno=-1;
	int i;


		if (list != NULL && len > 0)
		{

		for (i = 0; i < len; i++)
		{

			if (list[i].isEmpty == LIBRE)
			{

				retorno = i;
				break;

			} else
			{

				//Si esta todo lleno
				retorno = -2;

			}

		}

	}

		return retorno;


}

/// \brief Vuelo BuscarPorid by Id en devuelve la posición del índice en el arreglo.
/// \param list Vuelo *
/// \param len int
/// \param id int
///\return Posición del índice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int Vuelo_BuscarPorid(Vuelo *list, int len, int id){

	int retorno=-1;
	int i;

		if(list!= NULL && len >0)
		{

			for (i = 0; i < len; i++)
			{

				if(list[i].id== id)
				{

					retorno=i;
					break;

				}

			}


		}


	return retorno;

}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un Vuelo y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo Vuelo
/// @return un 0 si esta todo bien o -1 si esta mal
int Vuelo_PediUnDato(Vuelo * list){

	Vuelo Vuelo;
	int retorno=-1;

	if(list!=NULL){

		if(1)//utn_getStringMayusculayMinuscula(list.name, "\nIngrese nombre:","\nError esta mal escrito" , MAX_CARACTER, 2)==0)
		{

			Vuelo.id = generadorId();
			Vuelo.isEmpty=OCUPADO;
			retorno=0;
			*list=Vuelo;

		}

	}

	return retorno;

}

/// @fn int imprime Vuelo
/// @param imprimi un Vuelo solo
void Vuelo_MostrarUno(Vuelo list){

	printf("|%-15d|\n",list.statusFlight);

}

/// @fn imprime un array de Vuelo que esten cargados
/// @param recibi un puntero tipo Vuelo
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int Vuelo_MostrarTodos(Vuelo *list, int len){

	int retorno = -1;
	int i;

	if(list != NULL && len >=0){

		retorno=0;
		printf("+-----------------------------------------------------------"
				"----------------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-20s|%-20s|\n",
				" Nombres"," Apellidos"," Precio"," Codigo"," Tipo de pasajero"," Estado Vuelo");
		  printf("+-------------------------------------------------------------------"
				  "--------------------------------------+\n");
		for (i = 0; i < len ; i++) {

			if(list[i].isEmpty==OCUPADO){

				Vuelo_MostrarUno(list[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}
