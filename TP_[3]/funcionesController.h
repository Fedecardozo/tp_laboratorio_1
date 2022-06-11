

#ifndef FUNCIONESCONTROLLER_H_
#define FUNCIONESCONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "validacionPassenger.h"
#include "funcionesArchivos.h"

int controller_saveId(char* path);
int controller_saveModeAndId(char* path,int mode);
int controller_actualizacion(int modo,char* pathBin, char* pathText,LinkedList* pArrayListPassenger);
int controller_AgregarBorrados(LinkedList* pArrayListPassenger,LinkedList* pArrayListPassengerBorrados);
int controller_saveBorrados(char* path,int mode,LinkedList* listaBorrados);
int controller_readBorrados(char* path,LinkedList* listaBorrados);
int verificacionEliminados(LinkedList* pArrayListPassenger);
int controller_saveAsTextInvertido(char* pathTxt,char* pathBin , LinkedList* pArrayListPassenger);
int controller_saveAsBinaryInvertido(char* pathTxt,char* pathBin  , LinkedList* pArrayListPassenger);
LinkedList* perfeccionaLista(char* path,LinkedList* pArrayListPassenger,int (*pFuncLoad)(char*,LinkedList*));
int controller_cargarBorrado(LinkedList* pArrayListPassengerBorrados,int idBorrado);

#endif /* FUNCIONESCONTROLLER_H_ */
