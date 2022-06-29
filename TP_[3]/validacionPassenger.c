
#include "validacionPassenger.h"

static int queModifcar(Passenger* list);
static int opcionesParaModifcar(int opc, Passenger* list);
static int id;

/// @fn int mode_readArchivo(char*)
/// @param path
/// @return -1 datos nullos, 0 guardado modo binario,1 modo texto
int mode_readArchivo(char* path)
{
	int modo=-1;
	FILE* archivo;

	if(path != NULL)
	{
	    archivo=fopen(path,"r");

	    if(archivo != NULL)
	    {
	    	fscanf(archivo,"%d\n%d",&modo,&modo);
	    	fclose(archivo);

	    }

	}

    return modo;
}

/// @fn int generadorId_readArchivo(char*)
/// @brief lee del archivo el ultimo id y lo carga
/// id statico
/// @param path
/// @return retorna id
int generadorId_readArchivo(char* path)
{
	int nuevoId=-1;
	FILE* archivo;

	if(path != NULL)
	{
	    archivo=fopen(path,"r");

	    if(archivo != NULL)
	    {
	    	fscanf(archivo,"%d",&nuevoId);
	    	fclose(archivo);
	    	if(nuevoId>0)
	    	{
	    		id=nuevoId;
	    	}
	    }

	}


    return nuevoId;
}

/// @fn int generadorId_saveArchivo(char*)
/// @brief guarda el ultimo id en el archivo
/// @param path
/// @return -1 path null, 0 ok
int generadorId_saveArchivo(char* path){

	int retorno=-1;
	FILE* archivo;

	if(path != NULL && id > 0)
	{
	    archivo=fopen(path,"w+");

	    if(archivo != NULL)
	    {
	    	fprintf(archivo,"%d",id);
	    	fclose(archivo);
	    	retorno=0;

	    }

	}


    return retorno;

}

/// @fn int generadorId()
/// @brief Genera un id automatico
/// @return -1datos nullos 0 hubo error al obtener nuevo id
/// Sino Devuelve un id entero mayor a 0
int generadorId()
{
	if(id>0)
	{
		return id++;

	}else
	{
		return 0;
	}
}

//FUNCIONES CON LA CONSOLA
/// @fn imprime un solo pasajero en filas
/// @param imprimi un pasajero solo
void imprimirUnPassenger(Passenger* aux){

	char tipo[LEN_TYPE];
	int id;
	char nombre[LEN_NAME];
	char apellido[LEN_APELLIDO];
	float precio;
	char codigoVuelo[LEN_FLYCODE];
	char statusFlight[LEN_STATUSFLIGHT];

	Passenger_getId(aux, &id);
	Passenger_getNombre(aux, nombre);
	Passenger_getApellido(aux, apellido);
	Passenger_getPrecio(aux, &precio);
	Passenger_getCodigoVuelo(aux, codigoVuelo);
	Passenger_getTipoPasajeroTxt(aux, tipo);
	Passenger_getStatusFlight(aux, statusFlight);

	if(id<0)
	{
		id = id*-1;
	}
	printf("|%-10d|%-15s|%-15s|%-15f|%-15s|%-20s|%-20s|\n"
		,id,nombre,apellido,precio,codigoVuelo,tipo,statusFlight);


}

/// @fn pide Un Solo Dato al usuario
/// @pre pide datos para llenar un pasajero y los valida
/// @post y luego los copia en passanger pasado por parametro
/// @param recibi un tipo passenger
/// @return un 0 si esta tod bien o -1 si esta mal
int pedirDatoPassenger(Passenger* p){

	srand(time(NULL));
	int num = rand()%3;
	Passenger p1;
	int retorno=-1;
	char status [3][LEN_STATUSFLIGHT]={{"En Horario"},{"Demorado"},{"Aterrizado"}};

	if(p!=NULL){

		if(utn_getStringMayusculayMinuscula(p1.nombre, "\nIngrese nombre:","\nError esta mal escrito" , LEN_NAME, 2)==0
		   && utn_getStringMayusculayMinuscula(p1.apellido, "\nIngrese apellido:","\nError esta mal escrito" , LEN_APELLIDO, 2)==0
		   && utn_getNumeroFlotante(&p1.precio, "\nIngrese precio: ", "\nError ingrese nuevamente: ", 0, 99999, 2)==0
		   && utn_getStringLetrasYnumerosLimite(p1.codigoVuelo, "\nIngrese codigo de 7 a 10 digitos: ", "\nError, 10 digitos numeros y letras", 7,10, 2)==0
		   && utn_getNumero(&p1.tipoPasajero, "\n**Tipos de pasajeros** \n1-FirstClass \n2-ExecutiveClass \n3-EconomyClass  \nIngrese tipo:",
				   "\nError ingrese nuevamente:", 1, 3, 2)==0)
		{

			strncpy(p1.statusFlight,status[num],LEN_STATUSFLIGHT);
			retorno=0;
			*p=p1;

		}

	}

	return retorno;

}

/// @fn int findPassengerById(LinkedList*, int)
/// @param LinkedList* pArrayListPassenger
/// @param int id
/// @return -1 datos nullos, indice del id
int findPassengerById(LinkedList* pArrayListPassenger,int id)
{
	int retorno=-1;
	Passenger* aux;
	int idAux;

	if(pArrayListPassenger != NULL && id >0)
	{
		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			aux = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(aux, &idAux);

			if(idAux == id)
			{
				retorno=i;
				break;
			}

		}
	}

	return retorno;

}

/// @fn int findPassengerByIdFile(char*, int)
/// @param char* path, nombre del archivo
/// @param int id, a buscar
/// @return -1 datos nullos, indice del id
int setear_NuevoId_Passenger(LinkedList* list,int nuevoID)
{
	int retorno=-1;
	Passenger* aux;
	int idAux;

	if(list != NULL && nuevoID > 0)
	{
		retorno =0;

		for (int i = 0; i < ll_len(list); i++)
		{
			aux = (Passenger*) ll_get(list, i);
			Passenger_getId(aux, &idAux);

			if(idAux<0)
			{

				retorno=Passenger_setId(aux, nuevoID);

			}

		}

	}

	return retorno;

}

///FUNCIONES PARA ORDENAR

/// @fn int opcionesSort()
/// @return 0 ok o la opcion ingresada o -1 error
int opcionesSort(int* criterio)
{
	int retorno = -1;
	int opc;

	if(criterio != NULL)
	{
		retorno = utn_getNumero(&opc, "\n*ORDENAMIENTO*"
				"\n1-Ordenar por nombre"
				"\n2-Ordenar por apellido"
				"\n3-Ordenar por id"
				"\n4-Ordenar por precio"
				"\n5-Salir"
				"\nIngrese opcion: ", "\nError!, ingrese nuevamente:", 1, 5, 2);
		if(!retorno && opc != 5 &&
		  !utn_getNumero(criterio, "\n*Forma* \n0-Descendente \n1-Ascendente \nIngrese opcion: "
				, "Error!,Ingrese nuevamente: ", 0, 1, 1))
		{
			retorno=opc;
		}
	}


	return retorno;

}

/// @fn int sortId(void*, void*)
/// @param void* pasajero1
/// @param void* pasajero2
/// @return 1,-1 no son iguales
/// 0 son iguales
int sortId(void* pasajero1 ,void* pasajero2){

	int retorno = 0;
	Passenger* aux1;
	Passenger* aux2;
	int id1;
	int id2;

	if(pasajero1 != NULL && pasajero2 != NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;
		if(!Passenger_getId(aux1, &id1) && !Passenger_getId(aux2, &id2))
		{
			if(id1 > id2)
			{
				retorno=1;
			}
			if(id1 < id2)
			{
				retorno=-1;
			}
			if(id1 == id2)
			{
				retorno=0;
			}

		}
	}

	return retorno;
}


/// @fn int sortName(void*, void*)
/// @param void* pasajero1
/// @param void* pasajero2
/// @return 1,-1 no son iguales
/// 0 son iguales
int sortName(void* pasajero1 ,void* pasajero2){

	int retorno = 0;
	Passenger* aux1;
	Passenger* aux2;
	char name1[LEN_NAME];
	char name2[LEN_NAME];

	if(pasajero1 != NULL && pasajero2 != NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;
		if(!Passenger_getNombre(aux1, name1) && !Passenger_getNombre(aux2, name2))
		{
			if(name1 != NULL && name2 != NULL)
			{
				retorno = strcmpi(name1,name2);
			}

		}
	}

	return retorno;
}


/// @fn int sortApellido(void*, void*)
/// @param void* pasajero1
/// @param void* pasajero2
/// @return 1,-1 no son iguales
/// 0 son iguales
int sortApellido(void* pasajero1 ,void* pasajero2){

	int retorno = 0;
	Passenger* aux1;
	Passenger* aux2;
	char lastName1[LEN_APELLIDO];
	char lastName2[LEN_APELLIDO];

	if(pasajero1 != NULL && pasajero2 != NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;
		if(!Passenger_getApellido(aux1, lastName1) && !Passenger_getApellido(aux2, lastName2))
		{
			if(lastName1 != NULL && lastName2 != NULL)
			{
				retorno = strcmpi(lastName1,lastName2);
			}

		}
	}

	return retorno;
}


/// @fn int sortPrecio(void*, void*)
/// @param void* pasajero1
/// @param void* pasajero2
/// @return 1,-1 no son iguales
/// 0 son iguales
int sortPrecio(void* pasajero1 ,void* pasajero2){

	int retorno = 0;
	Passenger* aux1;
	Passenger* aux2;
	float precio1;
	float precio2;

	if(pasajero1 != NULL && pasajero2 != NULL)
	{
		aux1 = (Passenger*) pasajero1;
		aux2 = (Passenger*) pasajero2;
		if(!Passenger_getPrecio(aux1, &precio1) && !Passenger_getPrecio(aux2, &precio2))
		{
			if(precio1 > precio2)
			{
				retorno=1;
			}
			if(precio1 < precio2)
			{
				retorno=-1;
			}
			if(precio1 == precio2)
			{
				retorno=0;
			}

		}
	}

	return retorno;
}


///FUNCIONES PARA LA MODIFICACION

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
 static int queModifcar(Passenger* list){

	int retorno=-1;
	Passenger aux=*list;
	int respuesta;
	int opc;

	if(list != NULL){

		puts("\nPASAJERO A MODIFICAR!");
		imprimirUnPassenger(list);

		do{
			retorno= utn_getNumero(&opc, "\nOpciones de lo que desea modificar"
					"\n1-Nombre"
					"\n2-Apellido"
					"\n3-Precio"
					"\n4-Tipo de pasajero"
					"\n5-Codigo de vuelo"
					"\n6-No modificar"
					"\nIngrese opcion: ",
					"\nError Ingrese nuevamente: ", 1, 6, 2);

			if(!retorno && opc != 6)
			{
				retorno= opcionesParaModifcar(opc, &aux);

				if(!retorno)
				{
					respuesta=preguntarSoN("\nEstas seguro? Si-No: ", 2, "\nIngrese [si] o [no]: ");
					if(respuesta)
					{
						*list=aux;
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
				else if(retorno < 0)
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
			else if (opc == 6)
			{
				retorno = 0;
				break;
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

/// @fn opcionesParaModifcar
/// @brief Modifica los datos segun la opcion
/// @return -1 mal 0 bien
static int opcionesParaModifcar(int opc, Passenger* list){

	int retorno=-1;
	Passenger aux = *list;

	if(list != NULL)
	{

		switch (opc)
		{

			case 1:

				retorno = utn_getStringMayusculayMinuscula(aux.nombre, "\nIngrese nombre:","\nError esta mal escrito" , LEN_NAME, 2);

				break;

			case 2:

				retorno = utn_getStringMayusculayMinuscula(aux.apellido, "\nIngrese apellido: ","\nError! de nuevo", LEN_APELLIDO, 2);

				break;

			case 3:

				retorno = utn_getNumeroFlotante(&aux.precio, "\nIngrese precio: ","\nError! de nuevo",0, 9999, 2);

				break;

			case 4:

				retorno = utn_getNumero(&aux.tipoPasajero, "\n**Tipos de pasajeros** \n1-FirstClass \n2-ExecutiveClass \n3-EconomyClass  \nIngrese tipo:",
									   "\nError ingrese nuevamente:", 1, 3, 2);

				break;

			case 5:

				retorno = utn_getStringLetrasYnumerosLimite(aux.codigoVuelo, "\nIngrese codigo de vuelo de 7 a 10 digitos: ", "\nError, ingrese digitos numeros y letras", 7,10, 2);

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

/// @fn modifica Passenger
/// @brief modica un dato de pasajero
/// @param recibe un tipo passenger list
/// @param recibe el tamanio del arraylen
/// @param recibe el id que va a buscar
/// @return 1 un exito 0 ok(-1)Datos nullos (-2) No se encontro ID
/// (-3)Ingreso mal las opciones
/// (-4)Ingreso mal los datos a modificar
/// (-5)mal respuesta de si esta seguro
/// (-6)mal respuesta si desea continuar
int editPassenger(LinkedList* pArrayListPassenger, int id){

	int retorno=-1;
	int indice;
	Passenger* aux;

		if(pArrayListPassenger!=NULL && id>0){

			retorno=0;
			indice=findPassengerById(pArrayListPassenger, id);

			if(indice<0)
			{

				//ERROR NO ENCONTRO EL ID
				retorno=-2;

			}else if(indice>=0){

				//-1 mal los datos -3 mal las opciones
				//-4 mal datos a modificar
				//-5 mal respuesta de si esta seguro
				//-6 mal respuesta si desea continuar
				aux = (Passenger*) ll_get(pArrayListPassenger, indice);
				retorno= queModifcar(aux);
				if(!retorno && !ll_set(pArrayListPassenger, indice, aux))
				{
					retorno=1;
				}

			}


		}

		return retorno;

}


///FUNCIONES PARA LA BAJA

/// \brief Eliminar un Pasajero por Id
///\linkedList* pArrayListPassenger
///\id de parámetro int
///\return int Retorna (-1) si Error [longitud inválida o NULL
/// puntero o si no puede
///encontrar un pasajero] - (0) si está bien (-2) No lo quiere borrar
///
int removePassenger(LinkedList* pArrayListPassenger, int id)
{
	int retorno=-1;
	int indice;

	if(pArrayListPassenger!=NULL &&id>0){

		indice=findPassengerById(pArrayListPassenger, id);

		if(indice<0)
		{

			//NO existe id
			retorno=-1;

		}
		else if(indice>=0)
		{

			imprimirUnPassenger((Passenger*)ll_get(pArrayListPassenger, indice));

			//Preguntar si esta seguro
			if(preguntarSoN("\nEsta seguro que desea eliminar este pasajero? Si o No: ", 2, "\nRespuesta invalida")>0)
			{
				Passenger_delete((Passenger*)ll_pop(pArrayListPassenger, indice));
				retorno=0;
			}
			else
			{
				//No lo quiere borrar
				retorno=-2;
			}

		}


	}

	return retorno;
}
