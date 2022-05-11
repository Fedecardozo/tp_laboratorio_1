

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "utn.h"
#include "funcionesPropias.h"

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
		lastName[],float price,int typePassenger, char flycode[]);
int removePassenger(Passenger* list, int len, int id);
int findPassengerById(Passenger *list, int len, int id);
int printPassengerTipo(Passenger* list, int len,int tipo);
int printPassengerStatus(Passenger* list, int len,int status);

//FUNCIONES ORDENAMIENTO
int sortPassengers(Passenger* list, int len, int order);
int printSortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);
int printSortPassengersByCode(Passenger* list, int len, int order,int status);

//ABM
int altaPassenger(Passenger* p1,int tam);
int bajaPassenger(Passenger* p1,int tam);
int modificionPassenger(Passenger* p1,int tam);

//FUNCIONES CALCULOS
int promedioPassenger(Passenger* list, int len, float* promedio,float* totalPrice);
int superanPricePromedio(Passenger* list, int len, float promedio);
int printPromedioPassenger(Passenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
