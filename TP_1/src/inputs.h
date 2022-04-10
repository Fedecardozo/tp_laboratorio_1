
#ifndef INPUTS_H_
#define INPUTS_H_

#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

void getInt(char*m,int*x);
int getFloat(char*m,float*x);
int getIntPlus(char*msj,int*x,int min,int max,char *msjError,int intentos);
int getFloatPlus(char*msj,float*x,float min,float max,char *msjError,int intentos);


#endif
