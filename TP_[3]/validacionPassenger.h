

#ifndef VALIDACIONPASSENGER_H_
#define VALIDACIONPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "funcionesPropias.h"
#include <time.h>

//typedef int (*pFuncLoad)(char*,LinkedList*);
int mode_readArchivo(char* path);
int generadorId_saveArchivo(char* path);
int generadorId();
void imprimirUnPassenger(Passenger* aux);
int pedirDatoPassenger(Passenger* p);
int editPassenger(LinkedList* pArrayListPassenger, int id);
int removePassenger(LinkedList* pArrayListPassenger, int id);
int findPassengerById(LinkedList* pArrayListPassenger,int id);
int setear_NuevoId_Passenger(LinkedList* list,int nuevoID);
int generadorId_readArchivo(char* path);

//Ordenamiento
int opcionesSort(int* criterio);
int sortId(void* pasajero1 ,void* pasajero2);
int sortPrecio(void* pasajero1 ,void* pasajero2);
int sortApellido(void* pasajero1 ,void* pasajero2);
int sortName(void* pasajero1 ,void* pasajero2);

#endif /* VALIDACIONPASSENGER_H_ */
