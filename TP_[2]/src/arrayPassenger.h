

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn.h"
#define LIBRE 1
#define OCUPADO 0
#define MAX_CARACTER 51
#define MAX_CHARFLYCODE 10
#define PRICE_MAX 1000000.00
#define PRICE_MIN 1000.00

typedef struct{

	int id;
	char name[MAX_CARACTER];
	char lastName[MAX_CARACTER];
	float price;
	char flycode[MAX_CHARFLYCODE];
	int typePassanger;
	int statusFlight;
	int isEmpty;


}Passenger;

//HARCODEO
int harcodeo(Passenger* p1,int len);

//FUNCIONES INDIVIDUALES
void imprimirUnPassenger(Passenger p1);
void imprimirUnPassengerColumna(Passenger p1);
int pedirDatoPassenger(Passenger* p);

//FUNCIONES DE PASSENGER
int initPassengers(Passenger *list, int len);
int printPassengers(Passenger* p1,int tam);
int addPassenger(Passenger* list, int len, int id, char name[],char
		lastName[],float price,int typePassenger, char flycode[],int statusFlight);

//ABM
int altaPassenger(Passenger* p1,int tam);

#endif /* ARRAYPASSENGER_H_ */
