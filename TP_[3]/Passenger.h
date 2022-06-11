
#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN_NAME 50
#define LEN_APELLIDO 50
#define LEN_FLYCODE 10
#define LEN_STATUSFLIGHT 20
#define LEN_TYPE 20


typedef struct
{
	int id;
	char nombre[LEN_NAME];
	char apellido[LEN_APELLIDO];
	float precio;
	int tipoPasajero;
	char codigoVuelo[LEN_FLYCODE];
	char statusFlight[LEN_STATUSFLIGHT];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newPassenger(Passenger p);
Passenger* Passenger_newParametros(int id,char* nombreStr,int tipoPasajeroStr,char* lastname,float price,char* flycode,char*statusFlight);
Passenger* Passenger_newParametrosTxt(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* lastname,char* price,char* flycode,char*statusFlight);

void Passenger_delete(Passenger* this);

int Passenger_setIdTxt(Passenger* this,char* id);
int Passenger_getIdTxt(Passenger* this,char* id);
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
int Passenger_setTipoPasajeroTxt(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajeroTxt(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_setPrecioTxt(Passenger* this,char* precio);
int Passenger_getPrecioTxt(Passenger* this,char* precio);

int Passenger_setStatusFlight(Passenger* this,char* statusFlight);
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);

int Passenger_getTxt(Passenger* this,char* pasajero);

#endif /* PASSENGER_H_ */
