
#include "arrayPassenger.h"

//Prototypo
static int generadorId(void);
static int ObtenerIndexLibre(Passenger* p1, int tam);

/// @fn harcodeo los datos
/// @param p1 array de Passenger
/// @param len longitud de Passenger
/// @return 0 bien -1 mal[puntero null o len negativo]
int harcodeo(Passenger* p1,int len){

	int retorno =-1;

		if(p1!=NULL && len>0){


			addPassenger(p1, len, generadorId(), "Dario", "Diaz",1500, 1, "hk8vPrmpuJ",1);
			addPassenger(p1, len, generadorId(), "Esteban", "Estevanez", 5700, 1, "boSlxsM4Rp",1);
			addPassenger(p1, len, generadorId(), "Abel", "Alvarez", 30000, 2, "cm2FgAXJ8B",1);
			addPassenger(p1, len, generadorId(), "Bart", "Briasco", 2550.90, 2, "fs5uRqrZRA",1);
			addPassenger(p1, len, generadorId(), "Carlos", "Cardozo", 1890, 3, "g4m2OCY1Mh",1);

			addPassenger(p1, len, generadorId(), "Fernando", "Fernandez",1500, 3, "dDqViLjRJc",1);
			addPassenger(p1, len, generadorId(), "Gonzalo", "Gullit", 5700, 3, "iTkX5txObh",1);
			addPassenger(p1, len, generadorId(), "Rodrigo", "Rodriguez", 30000, 1, "fbLJgXBmpi",1);
			addPassenger(p1, len, generadorId(), "Hugo", "Hernandez", 2550.90, 2, "a1KpTUsVjq",1);
			addPassenger(p1, len, generadorId(), "Ignacio", "Insaurralde", 1890, 1, "ehBpk4leKU",1);

			retorno=0;

		}


	return retorno;


}

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return Devuelve un id entero
static int generadorId(){

	static int id=1000;
	return id++;

}

/// \brief Para indicar que todas las posiciones en el array están vacías,
/// esta función pone la bandera (isEmpty) en VERDADERO en todos
/// posiciónes del array
/// \param list Passenger* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int initPassengers(Passenger *list, int len) {

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

/// @fn imprime un solo pasajero en filas
/// @param imprimi un pasajero solo
void imprimirUnPassenger(Passenger p1){

	printf("\n\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
	printf("\nCodigo: %s \nTipo: %d \nEstado: %d",p1.flycode,p1.typePassanger,p1.statusFlight);

}

/// @fn imprime un array de pasajero que esten cargados
/// @param recibi un puntero tipo passenger
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
int printPassengers(Passenger* p1,int tam){

	int retorno = -1;
	int i;

	if(p1 != NULL && tam >=0){

		retorno=0;

		for (i = 0; i < tam ; i++) {

			if(p1[i].isEmpty==OCUPADO){

				imprimirUnPassenger(p1[i]);

			}



		}

	}


	return retorno;

}

///\brief agrega en una lista existente de pasajeros los valores recibidos como parámetros
/// en la primera posición vacía
///\param lista de pasajeros*
///\param len int
///\param id int
///\param nombre[] carácter
///\param apellido[] carácter
///\param precio flotante
///\param tipoPasajero int
///\param flycode[] carácter
///\return int Devuelve (-1) si Error [Longitud no válida o puntero NULL o sin
///espacio libre] - (0) si está bien
int addPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[],int statusFlight)
{

	int retorno =-1;
	int i;

	if(list != NULL && len>0 && id>0 && name != NULL
			&& lastName != NULL && price > PRICE_MIN
			&& typePassenger > 0 && flycode != NULL
			&& statusFlight>=0)
	{

		i=ObtenerIndexLibre(list, len);

		if(i>=0)
		{

			list[i].id = id;
			strncpy(list[i].name,name,sizeof(list[i].name));
			strncpy(list[i].lastName,lastName,sizeof(list[i].lastName));
			list[i].price = price;
			strncpy(list[i].flycode,flycode,sizeof(list[i].flycode));
			list[i].typePassanger = typePassenger;
			list[i].statusFlight = statusFlight;
			list[i].isEmpty=OCUPADO;

			retorno=0;

		}


	}

	return retorno;
}

/// @fn ObtenerIndexLibre
/// @param p1 recibe un array tipo Paseenger
/// @param tam es el tamanio del del array
/// \return int Devuelve (-1) si Error [Longitud no válida o puntero NULL]
/// o -2 sin espacio libre - (0) si está bien
static int ObtenerIndexLibre(Passenger* p1, int tam){

	int retorno=-1;
	int i;


		if (p1 != NULL && tam > 0)
		{

		for (i = 0; i < tam; i++)
		{

			if (p1[i].isEmpty == LIBRE)
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
