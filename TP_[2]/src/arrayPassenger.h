

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

int harcodeo(Passenger* p1,int len);



//**** FIN CABECERAS DE FUNCION****

#endif /* ARRAYPASSENGER_H_ */
