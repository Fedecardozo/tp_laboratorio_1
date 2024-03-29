
#include "arrayPassenger.h"

//globales
static char TIPOPASAJERO[3][20]={{"CLASE TURISTA"},{"CLASE EJECUTIVA"},{"PRIMERA CLASE"}};
static char ESTADOVUELO[2][20]={{"INACTIVO"},{"ACTIVO"}};

//Prototypo
static int generadorId(void);
static int ObtenerIndexLibre(Passenger* p1, int tam);
static int passengersVacio(Passenger *list, int len);
static int queModifcar(int indice,Passenger*p );
static int opcionesParaModifcar(int opc, Passenger* list);
static int ordenAlfabeticoYtipo(Passenger* list, int len, int order,int tipo);
static int ordenFlycode(Passenger* list, int len, int order, int status);

/// @fn harcodeo los datos
/// @param p1 array de Passenger
/// @param len longitud de Passenger
/// @return 0 bien -1 mal[puntero null o len negativo]
int harcodeo(Passenger* p1,int len){

	int retorno =-1;

		if(p1!=NULL && len>0){


			addPassenger(p1, len, generadorId(), "Dario", "Diaz",1500, 1, "hk8vPrmpuJ");
			addPassenger(p1, len, generadorId(), "Esteban", "Estevanez", 5700, 1, "boSlxsM4Rp");
			addPassenger(p1, len, generadorId(), "Abel", "Alvarez", 30000, 2, "cm2FgAXJ8B");
			addPassenger(p1, len, generadorId(), "Bart", "Briasco", 2550.90, 2, "fs5uRqrZRA");
			addPassenger(p1, len, generadorId(), "Carlos", "Cardozo", 1890, 3, "g4m2OCY1Mh");

			addPassenger(p1, len, generadorId(), "Fernando", "Fernandez",1500, 3, "dDqViLjRJc");
			addPassenger(p1, len, generadorId(), "Gonzalo", "Gullit", 5700, 3, "iTkX5txObh");
			addPassenger(p1, len, generadorId(), "Rodrigo", "Rodriguez", 30000, 1, "fbLJgXBmpi");
			addPassenger(p1, len, generadorId(), "Hugo", "Hernandez", 2550.90, 2, "a1KpTUsVjq");
			addPassenger(p1, len, generadorId(), "Ignacio", "Insaurralde", 1890, 1, "ehBpk4leKU");

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

/// \brief Para indicar que todas las posiciones en el array est�n vac�as,
/// esta funci�n pone la bandera (isEmpty) en VERDADERO en todos
/// posici�nes del array
/// \param list Passenger* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
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

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un pasajero y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo passenger
/// @return un 0 si esta todo bien o -1 si esta mal
int pedirDatoPassenger(Passenger* p){

	Passenger p1;
	int retorno=-1;

	if(p!=NULL){

		if(utn_getStringMayusculayMinuscula(p1.name, "\nIngrese nombre:","\nError esta mal escrito" , MAX_CARACTER, 2)==0
		   && utn_getStringMayusculayMinuscula(p1.lastName, "\nIngrese apellido:","\nError esta mal escrito" , MAX_CARACTER, 2)==0
		   && utn_getNumeroFlotante(&p1.price, "\nIngrese precio: ", "\nError ingrese nuevamente: ", PRICE_MIN, PRICE_MAX, 2)==0
		   && utn_getStringLetrasYnumerosLimite(p1.flycode, "\nIngrese codigo 10 digitos: ", "\nError, 10 digitos numeros y letras", MAX_CHARFLYCODE, 2)==0
		   && utn_getNumero(&p1.typePassanger, "\n**Tipos de pasajeros** \n1-Clase turistica \n2-Clase ejecutiva \n3-Primera Clase  \nIngrese tipo:",
				   "\nError ingrese nuevamente:", 1, 3, 2)==0)
		{
			//Esto se tiene que dar de alta en la funcion de dar de alta
			//p1.id = generadorId();
			//p1.isEmpty=OCUPADO;
			retorno=0;
			*p=p1;

		}

	}

	return retorno;

}

//FUNCIONES QUE MUESTRAN POR PANTALLA

/// @fn imprime un solo pasajero en filas
/// @param imprimi un pasajero solo
void imprimirUnPassenger(Passenger p1){

	printf("\n\nNombre: %s \nApellido:%s \nPrecio: %f ",p1.name,p1.lastName,p1.price);
	printf("\nCodigo: %s \nTipo: %d \nEstado: %d",p1.flycode,p1.typePassanger,p1.statusFlight);

}

/// @fn imprime un array de pasajero que esten cargados
/// @param recibi un puntero tipo passenger
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
int printPassengers(Passenger* p1,int tam){

	int retorno = -1;
	int i;

	if(p1 != NULL && tam >=0){

		retorno=0;
		printf("+-----------------------------------------------------------"
				"----------------------------------------------+\n");
		printf("|%-15s|%-15s|%-15s|%-15s|%-20s|%-20s|\n",
				" Nombres"," Apellidos"," Precio"," Codigo"," Tipo de pasajero"," Estado Vuelo");
		  printf("+-------------------------------------------------------------------"
				  "--------------------------------------+\n");
		for (i = 0; i < tam ; i++) {

			if(p1[i].isEmpty==OCUPADO){

				imprimirUnPassengerColumna(p1[i]);
				printf("+-----------------------------------------------------------"
								"----------------------------------------------+\n");

			}

		}

	}


	return retorno;

}

/// @fn int imprimirPasajero(Passanger)
/// @param imprimi un pasajero solo
void imprimirUnPassengerColumna(Passenger p1){

	printf("|%-15s|%-15s|%-15f|%-15s|%-20s|%-20s|\n"
			,p1.name,p1.lastName,p1.price,p1.flycode,TIPOPASAJERO[p1.typePassanger-1],ESTADOVUELO[p1.statusFlight]);

}

/// @fn imprime un array de pasajero que esten cargados
/// Y por tipo de pasajero
/// @param recibi un puntero tipo passenger
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
int printPassengerTipo(Passenger* list, int len,int tipo){

	int retorno=-1;
	int i;

	if(list!=NULL && len >=0 && tipo>0 && tipo<=3)
	{

		printf("\n+-------------------------------------------------------------------"
						  "--------------------------------------+\n");
		printf("|%70s %-34s|\n","ORDENAMIENTO POR APELLIDO. TIPO DE PASAJERO: ",TIPOPASAJERO[tipo-1]);
		printf("+-------------------------------------------------------------------"
						  "--------------------------------------+\n");

		printf("|%-15s|%-15s|%-15s|%-15s|%-20s|%-20s|\n",
				" Nombres"," Apellidos"," Precio"," Codigo"," Tipo de pasajero"," Estado Vuelo");

		printf("+-------------------------------------------------------------------"
						  "--------------------------------------+\n");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==OCUPADO && list[i].typePassanger==tipo)
			{

				imprimirUnPassengerColumna(list[i]);
				printf("+-------------------------------------------------------------------"
								  "--------------------------------------+\n");

				retorno=0;
			}

		}

	}

	return retorno;

}

/// @fn imprime un array de pasajero que esten cargados
/// Y por estado de vuelo
/// @param recibi un puntero tipo passenger
/// @param la longitud para recorrer el array
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
int printPassengerStatus(Passenger* list, int len,int status){

	int retorno=-1;
	int i;

	if(list!=NULL && len >=0 && status>=0 && status<=1)
	{

		printf("\n+-------------------------------------------------------------------"
								  "--------------------------------------+\n");
		printf("|%67s %-37s|\n","ORDENAMIENTO POR CODIGO Y ESTADO DE VUELO ",ESTADOVUELO[status]);
		printf("+-------------------------------------------------------------------"
								  "--------------------------------------+\n");

		printf("|%-15s|%-15s|%-15s|%-15s|%-20s|%-20s|\n",
						" Nombres"," Apellidos"," Precio"," Codigo"," Tipo de pasajero"," Estado Vuelo");

		printf("+-------------------------------------------------------------------"
								  "--------------------------------------+\n");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==OCUPADO && list[i].statusFlight==status)
			{

				imprimirUnPassengerColumna(list[i]);
				printf("+-------------------------------------------------------------------"
										  "--------------------------------------+\n");

				retorno=0;
			}

		}

	}

	return retorno;

}

///\brief agrega en una lista existente de pasajeros los valores recibidos como par�metros
/// en la primera posici�n vac�a
///\param lista de pasajeros*
///\param len int
///\param id int
///\param nombre[] car�cter
///\param apellido[] car�cter
///\param precio flotante
///\param tipoPasajero int
///\param flycode[] car�cter
///\return int Devuelve (-1) si Error [Longitud no v�lida o puntero NULL o sin
///espacio libre] - (0) si est� bien
int addPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[])
{

	int retorno =-1;
	int i;

	if(list != NULL && len>0 && id>0 && name != NULL
			&& lastName != NULL && price > PRICE_MIN
			&& typePassenger > 0 && flycode != NULL)
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
			//ESTO HAY QUE CAMBIARLO DE LUGAR
			list[i].statusFlight = 1;
			//PARA EL HARCODEO LO DEJO ASI
			list[i].isEmpty=OCUPADO;

			retorno=0;

		}


	}

	return retorno;
}

/// \brief Pregunta si las posiciones en el array est�n vac�as,
/// \param list Passenger* Puntero del array de pasajeros
/// \param len int Longitud del arreglo
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0)vacio
/// (1) Cargado
static int passengersVacio(Passenger *list, int len) {

	int retorno=-1;
	int i;

	if(list != NULL && len >0){
		retorno=0;
		for (i = 0; i < len; i++)
		{

			if(list[i].isEmpty==OCUPADO)
			{
				retorno=1;
				break;
			}

		}

	}

	return retorno;


}

//FUNCIONES QUE DEVUELVEN INDICE

/// @fn ObtenerIndexLibre
/// @param p1 recibe un array tipo Paseenger
/// @param tam es el tamanio del del array
/// \return int Devuelve (-1) si Error [Longitud no v�lida o puntero NULL]
/// o -2 sin espacio libre - (0) si est� bien
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

/// \brief find a Passenger by Id en devuelve la posici�n del �ndice en el arreglo.
/// \param list Pasajero*
/// \param len int
/// \param id int
///\return Posici�n del �ndice de pasajero de retorno o (-1) si [Longitud o
///Puntero NULL recibido o pasajero no encontrado]
int findPassengerById(Passenger *list, int len, int id) {

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

//FUNCIONES QUE USA EL ABM

///FUNCION PARA LA BAJA
/// \brief Eliminar un Pasajero por Id (poner el indicador isEmpty en 1)
///\lista de par�metros Pasajero*
///\parametro len int
///\id de par�metro int
///\return int Retorna (-1) si Error [longitud inv�lida o NULL
/// puntero o si no puede
///encontrar un pasajero] - (0) si est� bien (-3) No estaba seguro
int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			indice=findPassengerById(list, len, id);

			if(indice<0){

				retorno=-1;

			}else if(indice>=0){

				//Preguntar si esta seguro
				if(preguntarSoN("\nEsta seguro? Si o No: ", 2, "\nRespuesta invalida"))
				{
					list[indice].isEmpty=LIBRE;
					retorno=0;

				}
				else
				{

					retorno=-2;
				}

			}


		}

	return retorno;
}

///FUNCION PARA LA MODIFICACION
/// @fn modifica Passenger
/// @brief modica un dato de pasajero
/// @param recibe un tipo passenger list
/// @param recibe el tamanio del arraylen
/// @param recibe el id que va a buscar
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
int editPassenger(Passenger* list, int len, int id){

	int retorno=-1;
	int indice;

		if(list!=NULL && len>0 && id>0){

			retorno=0;
			indice=findPassengerById(list, len, id);

			if(indice<0){

				//ERROR NO ENCONTRO EL ID
				retorno=-2;

			}else if(indice>=0 && list[indice].isEmpty==OCUPADO){

				//-1 mal los datos -3 mal las opciones
				//-4 mal datos a modificar
				//-5 mal respuesta de si esta seguro
				//-6 mal respuesta si desea continuar
				retorno= queModifcar(indice,list);

			}


		}

		return retorno;

}

///FUNCION PARA LA MODIFICACION
/// @fn opcionesParaModifcar
/// @brief Modifica los datos segun la opcion
/// @return -1 mal 0 bien
static int opcionesParaModifcar(int opc, Passenger* list){

	int retorno=-1;
	Passenger aux=*list;

	if(list != NULL)
	{

		switch (opc)
		{

			case 1:
				//char c[MAX_CARACTER];
				retorno = utn_getStringMayusculayMinuscula(aux.name, "\nIngrese nombre: ","\nError! de nuevo", MAX_CARACTER, 2);

				break;

			case 2:

				retorno = utn_getStringMayusculayMinuscula(aux.lastName, "\nIngrese apellido: ","\nError! de nuevo", MAX_CARACTER, 2);

				break;

			case 3:
				//float x;
				retorno = utn_getNumeroFlotante(&aux.price, "\nIngrese precio: ","\nError! de nuevo",PRICE_MIN, PRICE_MAX, 2);

				break;

			case 4:
				//int r;
				retorno = utn_getNumero(&aux.typePassanger, "\n**Tipos de pasajeros** \n1-Clase turistica \n2-Clase ejecutiva \n3-Primera Clase  \nIngrese tipo:",
						   "\nError ingrese nuevamente:", 1, 3, 2);

				break;

			case 5:
				//char codigo[MAX_CHARFLYCODE];
				retorno = utn_getStringLetrasYnumerosLimite(aux.flycode, "\nIngrese codigo: ", "\nError",MAX_CHARFLYCODE, 2);

				break;

			default:
				retorno = -1;
			break;

		}

		if(retorno==0)
		{
			*list=aux;
		}

	}

	return retorno;


}

///FUNCION PARA LA MODIFICACION
/// @fn queModifcar
/// @pre Segun la opcion ingresada por el usuario
/// @post va a mostrar un msj y guardarlo en auxiliar
/// De tipo Passenger
/// @param opc la opcion para el switch
/// @param indice para saber cual hay que modificar
/// @param p el puntero passenger para sobreecribir con
/// el auxiliar
/// @return 0 bien o -1 mal -3 mal las opciones
/// -4 mal datos a modificar -5 mal respuesta si esta seguro
/// -6 Mal la respuesta de si desea continuar
static int queModifcar(int indice,Passenger*p ){

	int retorno=-1;
	Passenger aux;
	aux=p[indice];
	int respuesta;
	int opc;

	if(p != NULL && opc>0 && indice >=0 ){

		do{
			retorno= utn_getNumero(&opc, "\nOpciones de lo que desea modificar"
					"\n1-Nombre"
					"\n2-Apellido"
					"\n3-Precio"
					"\n4-Tipo de pasajero"
					"\n5-Codigo de vuelo"
					"\nIngrese opcion: ",
					"\nError Ingrese nuevamente: ", 1, 5, 2);

			if(retorno==0)
			{
				retorno= opcionesParaModifcar(opc, &aux);

				if(retorno==0)
				{
					respuesta=preguntarSoN("\nEstas seguro? Si-No: ", 2, "\nIngrese [si] o [no]: ");

					if(respuesta)
					{
						p[indice]=aux;
						printf("\nSE MODIFICO CON EXITO !");
					}
					if(respuesta==0)
					{
						printf("\nNO SE MODIFICARION LOS DATOS !");
					}
					else if(respuesta<0)
					{
						//Mal la respuesta de si esta seguro
						retorno=-5;
						break;
					}


				}
				else
				{
					//Mal los datos a modificar
					retorno=-4;
					break;
				}


				respuesta = preguntarSoN("\nDesea continuar modificando? Si-No: ", 2, "\nIngrese [si] o [no]: ");
				if(respuesta<0)
				{
					//Mal la respuesta de si desea continuar
					retorno=-6;
					break;
				}
			}
			else
			{
				//mal las opciones
				retorno =-3;
				break;
			}

		}while(respuesta);

	}

	return retorno;
}



//ABM

/// @fn Da de alta un Passenger
/// @param lista de pasajeros
/// @param len longitud del array passenger
/// @return 0 bien -1 mal -2 Esta lleno
int altaPassenger(Passenger* list,int tam){

	Passenger aux;
	int retorno=-1;
	int indice;

	//Busco primero lugar vacio para que el usuario, para avisarle que no hay lugar
	//antes de que complete los datos
	indice = ObtenerIndexLibre(list, tam);

	if(indice>=0 && pedirDatoPassenger(&aux)==0){

		retorno=0;
		//Ya se da de alta
		if(addPassenger(list, tam, generadorId(), aux.name, aux.lastName, aux.price, aux.typePassanger, aux.flycode)==0){

			//Ya lo hace el addPassenger
			//p1[indice].isEmpty=OCUPADO;
			retorno=0;

		}


	}else if(indice==-2){

		//Esta lleno
		retorno =-2;

	}

	return retorno;

}

/// @fn Baja para passenger
/// @param p1 arreglo passenger
/// @param tam longitud del arreglo
/// @return 0 bien -1 error parametros -2 no existe id -3 No hay pasajeros cargados
/// -4 no estaba seguro
int bajaPassenger(Passenger* p1,int tam){

	int retorno=-1;
	int id;
	int rta;

	if(p1 != NULL && tam >0)
	{
		if(passengersVacio(p1, tam))
		{
			if(utn_getNumero(&id, "\nIngrese numero ID:", "\nError Ingrese nuevamente: ", 0, 3000, 2)==0)
			{
				rta=removePassenger(p1, tam, id);
				if(rta==0)
				{

					//ESTA OK
					retorno = 0;

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
			retorno = -3;
		}

	}


	return retorno;

}

/// @fn Modificacion para passenger
/// @param p1 arreglo passenger
/// @param tam longitud del arreglo
/// @return 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
/// (-7)EL ARREGLO ESTA VACIO
int modificionPassenger(Passenger* p1,int tam){

	int retorno =-1;
	int id;

	if(p1 != NULL)
	{
		if(passengersVacio(p1, tam))
		{

			//HASTA EL RETORNO ES -1
			if(utn_getNumero(&id, "\nIngrese id:", "\nDato invalido. Ingrese nuevamente: ", 0, 1200, 2)==0){

				//RETORNO PUEDE 0 BIEN <0 QUE ALGO SALIO MAL
				retorno=editPassenger(p1,tam,id);

			}

		}
		else
		{
			//EL ARREGLO ESTA VACIO
			retorno =-7;
		}

	}




	return retorno;

}


//FUNCIONES ORDENAMIENTO APELLIDO Y TIPO

/// \brief Ordenar los elementos en el arreglo de pasajeros(apellido y TypePaseenger),
///  el orden de los argumentos. Indicar orden ARRIBA o ABAJO
///\param listaPasajero*
///\param len int
///\param order int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
/// (-2)Error al ordenar alfabeticamente (-3)Error al ordenarlo por tipo de pasajero
/// (-4)Esta vacio
int sortPassengers(Passenger* list, int len, int order){

	int retorno = -1;

		if(list != NULL && len >= 0 &&  order>=0 && order<=1 )
		{
			if(passengersVacio(list, len))
			{

				if(ordenAlfabeticoYtipo(list,len,order,1)>=0
						&& ordenAlfabeticoYtipo(list,len,order,2)>=0
						&& ordenAlfabeticoYtipo(list,len,order,3)>=0)
				{

					retorno=0;


				}
				else
				{
					//Error al ordenar alfabeticamente
					retorno=-2;

				}

			}
			else
			{
				//ARREGLO VACIO
				retorno=-4;
			}

		}

		//Retorno =-1 error en los parametros
	return retorno;
}

/// @fn ordena alfabeticamente una lista de pasajeros
/// por apellido
/// @param lista de pasajeros
/// @param len longitud del array
/// @param order [1]Orden ascendente [0] desendente
/// @return 1 bien 0 parametro bien pasa -1 mal
static int ordenAlfabeticoYtipo(Passenger* list, int len, int order,int tipo){

	int retorno = -1;
	int flagSwap;
	int i;
	int renovacionLimite;
	Passenger auxCambio;


	if(list != NULL && len >= 0 &&  order>=0 && order<=1 && tipo>0 && tipo<=3)
	{
		retorno=0;
		renovacionLimite = len-1;
		do{

			flagSwap=0;

			for (i = 0; i <renovacionLimite ; i++)
			{
				if(list[i].isEmpty==OCUPADO && list[i].typePassanger== tipo)
				{

					if(swapCadenas(list[i].lastName ,list[i+1].lastName,MAX_CARACTER,order)>0)
					{

						flagSwap=1;
						auxCambio=list[i];
						list[i]=list[i+1];
						list[i+1]=auxCambio;
						retorno=1;

					}

				}
			}

			renovacionLimite--;

		}while(flagSwap);

	}

	return retorno;


}


/// @fn imprime ordenado por apellido y tipo de pasajero
/// \param list*  lista de Pasajero
/// \param len longitud
/// \param estado [1]vuelo Activado [0]vuelo desactivado
/// \param orden int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
/// (-2)Error al ordenar alfabeticamente (-3)Error al ordenarlo por tipo de pasajero
/// (-4)Esta vacio (-5)No se pudo imprimir los datos
int printSortPassengers(Passenger* list, int len, int order){

	int retorno=-1;

	if(list!=NULL && len >=0 && order>=0 && order<=1)
	{
		retorno=sortPassengers(list, len, order);

		if(retorno==0)
		{

			if(printPassengerTipo(list, len, 1)==0
					&& printPassengerTipo(list, len, 2)==0
					&& printPassengerTipo(list, len, 3)==0)
			{
				retorno=0;
			}
			else
			{
				retorno=-5;
			}

		}

	}

	return retorno;

}


//FUNCIONES CALCULOS

/// @fn promedio Passenger
/// @param lista de pasajeros
/// @param len longitud del array passenger
/// @param promedio puntero para devolver el promedio
/// @return 0 bien -1 mal[paramtros mal] o contador -2 lista vacia
int promedioPassenger(Passenger* list, int len, float* promedio,float* totalPrice){

	int retorno=-1;
	float acumulador=0;
	float contador=0;
	int i;

	if(list!=NULL && len >0 && promedio != NULL){

		retorno =0;
		if(passengersVacio(list, len))
		{

			for (i = 0; i < len; i++) {

				if(list[i].isEmpty == OCUPADO){

					acumulador = acumulador + list[i].price;
					contador++;


				}

			}
			if(contador>0 && acumulador >0)
			{
				*totalPrice=acumulador;
				*promedio = acumulador/contador;
				retorno=contador;

			}

		}
		else
		{
			retorno=-2;
		}
	}


	return retorno;
}

/// @fn superan promedio Passenger
/// @param lista de pasajeros
/// @param len longitud del array passenger
/// @param promedio para comparar cuantos lo superan
/// @return 1 bien -1 mal o contador
int superanPricePromedio(Passenger* list, int len, float promedio){

	int retorno=-1;
	int cont=0;
	int i;

	if (list != NULL && len > 0 && promedio > 0) {

		retorno=0;

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == OCUPADO && list[i].price > promedio) {

				cont++;

			}

		}
		if(cont >=0){

			retorno = cont;

		}

	}


		return retorno;

}

/// @fn print Passenger promedio y los que los superan
/// @param lista de pasajeros
/// @param len longitud del array passenger
/// @param promedio puntero para devolver el promedio
/// @return 0 bien -1 mal[paramtros mal] o contador -2 lista vacia
int printPromedioPassenger(Passenger* list, int len){

	int retorno=-1;
	float promedio;
	float total;

		if (list != NULL && len > 0)
		{
			retorno=promedioPassenger(list, len, &promedio,&total);
			if(retorno>0)
			{
				retorno=superanPricePromedio(list, len, promedio);
				if(retorno>=0)
				{
					printf("\n\nTotal precios de los pasajeros: %f",total);
					printf("\nTotal precios promedio de los pasajeros: %f",promedio);
					printf("\nTotal que superan el precio promedio: %d\n",retorno);
				}

			}


		}


		return retorno;

}


//FUNCIONES ORDENAMIENTO POR CODIGO Y ESTADO VUELO

/// \brief Ordena los elementos del array de pasajeros(codigo vuelo y estado vuelo), el
///  orden de los argumentos indicar orden ARRIBA o ABAJO
/// \param list*  lista de Pasajero
/// \param len longitud
/// \param orden int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
/// (-2)Error al ordenar alfabeticamente (-3)Arreglo vacio
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno = -1;

		if(list != NULL && len >= 0 &&  order>=0 && order<=1 )
		{
			if(passengersVacio(list, len))
			{

				if(ordenFlycode(list,len,order,1) >=0)
				{
					//Salio bien
					retorno=0;

				}
				else
				{
					//Error al ordenar alfabeticamente
					retorno=-2;

				}

			}
			else
			{
				//Arreglo vacio
				retorno=-3;
			}


		}

			//Retorno =-1 error en los parametros
		return retorno;


	return 0;

}

/// @fn ordenFlycode ordena alfabeticamente una lista de pasajeros
/// por el codigo de vuelo
/// @param lista de pasajeros
/// @param len longitud del array
/// @param order [1]Orden ascendente [0] desendente
/// @return 1 bien -1 mal 0 No hay para ordenar
static int ordenFlycode(Passenger* list, int len, int order, int status){

	int retorno = -1;
	int flagSwap;
	int i;
	int renovacionLimite;
	Passenger auxCambio;

	if(list != NULL && len > 0 &&  order>=0 && order<=1 && status >=0 && status <=1)
	{

		retorno=0;
		renovacionLimite = len-1;
		do{

			flagSwap=0;

			for (i = 0; i <renovacionLimite ; i++)
			{
				//if(list[i].isEmpty == OCUPADO)
				//{

					if(swapCadenas(list[i].flycode ,list[i+1].flycode,MAX_CHARFLYCODE,order)>0)
					{
						flagSwap=1;
						auxCambio=list[i];
						list[i]=list[i+1];
						list[i+1]=auxCambio;
						retorno=1;

					}

				//}

			}

			renovacionLimite--;

		}while(flagSwap);


	}

	return retorno;

}

/// @fn imprime ordenado por codigo y estado de vuelo
/// \param list*  lista de Pasajero
/// \param len longitud
/// \param estado [1]vuelo Activado [0]vuelo desactivado
/// \param orden int [1] indica ARRIBA - [0] indica ABAJO
///\return int Devuelve (-1) si hay error [longitud no v�lida o puntero NULL] - (0) si est� bien
/// (-2)Error al ordenarlo por codigo de pasajero
/// (-3)Esta vacio (-4)No se pudo imprimir los datos
int printSortPassengersByCode(Passenger* list, int len, int order,int status){

	int retorno=-1;

	if(list!=NULL && len >=0 && order>=0 && order<=1)
	{
		retorno=sortPassengersByCode(list, len, order);

		if(retorno==0)
		{

			if(printPassengerStatus(list, len, status)==0)
			{
				//SALIO OK
				retorno=0;
			}
			else
			{
				//ERROR AL IMPRIMIR
				retorno=-4;
			}

		}

	}

	return retorno;

}
