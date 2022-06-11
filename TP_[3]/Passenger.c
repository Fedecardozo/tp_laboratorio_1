
#include "Passenger.h"

/// @fn Passenger Passenger_new*()
/// Crea un espacio de memoria
/// e inicializa los campos
/// @return direccion Passenger
Passenger* Passenger_new(){

	Passenger* aux=(Passenger*)malloc(sizeof(Passenger));

	if(aux != NULL)
	{
		Passenger_setId(aux, 0);
		Passenger_setNombre(aux, "vacio");
		Passenger_setApellido(aux, "vacio");
		Passenger_setPrecio(aux, 0);
		Passenger_setCodigoVuelo(aux, "a");
		Passenger_setTipoPasajero(aux, 4);
		Passenger_setStatusFlight(aux, "vacio");
	}

	return aux;

}

/// @fn Passenger Passenger_newParametros*(int, char*, int, char*, float, char*, char*)
/// @param id
/// @param nombreStr
/// @param tipoPasajeroStr
/// @param lastname
/// @param price
/// @param flycode
/// @param statusFlight
/// @return direccion Passenger
Passenger* Passenger_newParametros(int id,char* nombreStr,int tipoPasajeroStr,char* lastname,float price,char* flycode,char*statusFlight){

	Passenger* aux=Passenger_new();

	if(aux != NULL)
	{
		//Validar que este tod bien
		Passenger_setId(aux, id);
		Passenger_setNombre(aux, nombreStr);
		Passenger_setApellido(aux, lastname);
		Passenger_setTipoPasajero(aux, tipoPasajeroStr);
		Passenger_setPrecio(aux, price);
		Passenger_setCodigoVuelo(aux, flycode);
		Passenger_setStatusFlight(aux, statusFlight);

	}

	return aux;

}

/// @fn Passenger Passenger_newPassenger*(Passenger)
/// @param Passenger
/// @return direccion Passenger
Passenger* Passenger_newPassenger(Passenger p){

	return Passenger_newParametros(p.id,p.nombre,p.tipoPasajero,p.apellido,p.precio,p.codigoVuelo,p.statusFlight);

}

/// @fn Passenger Passenger_newParametrosTxt*(char*, char*, char*, char*, char*, char*, char*)
/// @param idStr
/// @param nombreStr
/// @param tipoPasajeroStr
/// @param lastname
/// @param price
/// @param flycode
/// @param statusFlight
/// @return direccion Passenger
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* lastname,char* price,char* flycode,char*statusFlight)
{

	Passenger* aux=Passenger_new();

	if(aux != NULL)
	{
		//Validar que este tod bien
		Passenger_setIdTxt(aux, idStr);
		Passenger_setNombre(aux, nombreStr);
		Passenger_setApellido(aux, lastname);
		Passenger_setTipoPasajeroTxt(aux, tipoPasajeroStr);
		Passenger_setPrecioTxt(aux, price);
		Passenger_setCodigoVuelo(aux, flycode);
		Passenger_setStatusFlight(aux, statusFlight);

	}

	return aux;

}

/// @fn void Passenger_delete(Passenger*)
/// @brief Libera direccion de Passenger
/// @param Passenger* this
void Passenger_delete(Passenger* this){

	if(this != NULL)
	{
		puts("Se supone que se borro");
		free(this);
	}
}

/// @fn int Passenger_setIdTxt(Passenger*, char*)
/// @param this
/// @param id
/// @return -1 parametros nullos, 0 ok
int Passenger_setIdTxt(Passenger* this,char* id){

	int retorno =-1;

	if(this != NULL && id != NULL)
	{
		retorno = 0;
		this->id= atoi(id);

	}

	return retorno;

}

/// @fn int Passenger_getIdTxt(Passenger*, char*)
/// @param this
/// @param id
/// @return -1 parametros nullos, 0 ok
int Passenger_getIdTxt(Passenger* this,char* id){

	int retorno =-1;

	if(this != NULL && id != NULL)
	{
		retorno = 0;
		sprintf(id,"%d",this->id);

	}

	return retorno;

}

/// @fn int Passenger_setId(Passenger*, int)
/// @param this
/// @param id
/// @return -1 parametros nullos, 0 ok
int Passenger_setId(Passenger* this,int id){

	int retorno =-1;

	if(this != NULL)
	{
		retorno = 0;
		this->id= id;

	}

	return retorno;

}

/// @fn int Passenger_getId(Passenger*, int*)
/// @param this
/// @param id
/// @return -1 parametros nullos, 0 ok
int Passenger_getId(Passenger* this,int* id){

	int retorno =-1;

	if(this != NULL && id != NULL)
	{
		retorno=0;
		*id=this->id;
	}

	return retorno;

}

/// @fn int Passenger_setNombre(Passenger*, char*)
/// @param this
/// @param nombre
/// @return -1 parametros nullos, 0 ok
int Passenger_setNombre(Passenger* this,char* nombre){

	int retorno =-1;

	if(this != NULL && nombre != NULL)
	{

		retorno = 0;
		//Validar que sea un nombre
		strncpy(this->nombre,nombre,LEN_NAME);

	}

	return retorno;


}

/// @fn int Passenger_getNombre(Passenger*, char*)
/// @param this
/// @param nombre
/// @return -1 parametros nullos, 0 ok
int Passenger_getNombre(Passenger* this,char* nombre){

	int retorno =-1;

	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		//Devuelvo el nombre
		strncpy(nombre,this->nombre,LEN_NAME);

	}

	return retorno;
}

/// @fn int Passenger_setApellido(Passenger*, char*)
/// @param this
/// @param apellido
/// @return -1 parametros nullos, 0 ok
int Passenger_setApellido(Passenger* this,char* apellido){

	int retorno =-1;

	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strncpy(this->apellido,apellido,LEN_APELLIDO);

	}

	return retorno;

}

/// @fn int Passenger_getApellido(Passenger*, char*)
/// @param this
/// @param apellido
/// @return -1 parametros nullos, 0 ok
int Passenger_getApellido(Passenger* this,char* apellido){

	int retorno =-1;

	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		//Devuelve un apellido
		strncpy(apellido,this->apellido,LEN_APELLIDO);

	}

	return retorno;
}

/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @param this
/// @param codigoVuelo
/// @return -1 parametros nullos, 0 ok
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno =-1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		//Validar que sea un codigo de vuelo valido
		strncpy(this->codigoVuelo,codigoVuelo,LEN_FLYCODE);

	}

	return retorno;

}

/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @param this
/// @param codigoVuelo
/// @return -1 parametros nullos, 0 ok
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno =-1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		//Devuelvo codigo de vuelo
		strncpy(codigoVuelo,this->codigoVuelo,LEN_FLYCODE);

	}

	return retorno;

}

/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @param this
/// @param tipoPasajero
/// @return -1 parametros nullos, 0 ok
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){

	int retorno =-1;

	if(this != NULL && tipoPasajero >0)
	{
		retorno = 0;
		this->tipoPasajero=tipoPasajero;

	}

	return retorno;
}

/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @param this
/// @param tipoPasajero
/// @return -1 parametros nullos, 0 ok
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){

	int retorno =-1;

	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		*tipoPasajero=this->tipoPasajero;

	}

	return retorno;

}

/// @fn int Passenger_setTipoPasajeroTxt(Passenger*, char*)
/// @param this
/// @param tipoPasajero
/// @return -1 parametros nullos, 0 ok
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero){

	int retorno =-1;
	int flag =0;
	char tipo [3][LEN_TYPE]={{"FirstClass"},{"ExecutiveClass"},{"EconomyClass"}};

	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		if(strcmp(tipo[0],tipoPasajero)==0)
		{
			this->tipoPasajero=1;
			flag++;

		}
		if(strcmp(tipo[1],tipoPasajero)==0)
		{
			this->tipoPasajero=2;
			flag++;

		}
		if(strcmp(tipo[2],tipoPasajero)==0)
		{
			this->tipoPasajero=3;
			flag++;

		}
		if(!flag)
		{
			this->tipoPasajero=4;
		}

	}

	return retorno;
}

/// @fn int Passenger_getTipoPasajeroTxt(Passenger*, char*)
/// @param this
/// @param tipoPasajero
/// @return -1 parametros nullos, 0 ok
int Passenger_getTipoPasajeroTxt(Passenger* this,char* tipoPasajero){

	int retorno =-1;
	char tipo [4][LEN_TYPE]={{"FirstClass"},{"ExecutiveClass"},{"EconomyClass"},{"NIIDEA"}};

	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		strncpy(tipoPasajero,tipo[this->tipoPasajero-1],LEN_TYPE);


	}

	return retorno;

}

/// @fn int Passenger_setPrecio(Passenger*, float)
/// @param this
/// @param precio
/// @return -1 parametros nullos, 0 ok
int Passenger_setPrecio(Passenger* this,float precio){

	int retorno =-1;

	if(this != NULL && precio >= 0)
	{
		retorno = 0;
		this->precio = precio;

	}

	return retorno;

}

/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @param this
/// @param precio
/// @return -1 parametros nullos, 0 ok
int Passenger_getPrecio(Passenger* this,float* precio){

	int retorno =-1;

	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;

	}

	return retorno;
}

/// @fn int Passenger_setPrecioTxt(Passenger*, char*)
/// @param this
/// @param precio
/// @return -1 parametros nullos, 0 ok
int Passenger_setPrecioTxt(Passenger* this,char* precio){

	int retorno =-1;

	if(this != NULL && precio != NULL)
	{

		retorno = 0;
		this->precio = atof(precio);


	}

	return retorno;

}

/// @fn int Passenger_getPrecioTxt(Passenger*, char*)
/// @param this
/// @param precio
/// @return -1 parametros nullos, 0 ok
int Passenger_getPrecioTxt(Passenger* this,char* precio){

	int retorno =-1;

	if(this != NULL && precio != NULL)
	{

		retorno = 0;
		sprintf(precio,"%f",this->precio);


	}

	return retorno;

}

/// @fn int Passenger_setStatusFlight(Passenger*, char*)
/// @param this
/// @param statusFlight
/// @return -1 parametros nullos, 0 ok
int Passenger_setStatusFlight(Passenger* this,char* statusFlight){

	int retorno =-1;

	if(this != NULL && statusFlight != NULL)
	{
		retorno = 0;
		strncpy(this->statusFlight,statusFlight,LEN_STATUSFLIGHT);

	}

	return retorno;
}

/// @fn int Passenger_getStatusFlight(Passenger*, char*)
/// @param this
/// @param statusFlight
/// @return -1 parametros nullos, 0 ok
int Passenger_getStatusFlight(Passenger* this,char* statusFlight){

	int retorno =-1;

	if(this != NULL && statusFlight != NULL)
	{
		retorno = 0;
		strncpy(statusFlight,this->statusFlight,LEN_STATUSFLIGHT);

	}

	return retorno;

}

/// @fn int Passenger_getTxt(Passenger*, char*)
/// @param this
/// @param pasajero
/// @return -1 parametros nullos, 0 ok

int Passenger_getTxt(Passenger* this,char* pasajero){

	int retorno =-1;
	char tipo[LEN_TYPE];
	int id;
	char nombre[LEN_NAME];
	char apellido[LEN_APELLIDO];
	float precio;
	char codigoVuelo[LEN_FLYCODE];
	char statusFlight[LEN_STATUSFLIGHT];

	//char aux[sizeof(Passenger)];

	if(this != NULL && pasajero != NULL)
	{
		retorno = 0;

		Passenger_getId(this, &id);
		Passenger_getNombre(this, nombre);
		Passenger_getApellido(this, apellido);
		Passenger_getPrecio(this, &precio);
		Passenger_getCodigoVuelo(this, codigoVuelo);
		Passenger_getTipoPasajeroTxt(this, tipo);
		Passenger_getStatusFlight(this, statusFlight);
		sprintf(pasajero,"%d,%s,%s,%.0f,%s,%s,%s",id,nombre,apellido,precio,codigoVuelo,tipo,statusFlight);

	}

	return retorno;

}
