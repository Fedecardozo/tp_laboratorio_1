/*
 * operacionesTP_1.h
 *
 * prototypos de las funciones y los includes
 *
 */

#ifndef OPERACIONESTP_1_H_
#define OPERACIONESTP_1_H_
#include <stdio.h>
#include <stdlib.h>
// Prototypo
int menu();
int getInt(char*m);
float getFloat(char*m);
int validador(int rta,int menor,int mayor,int cantidad,char*m);
void porcentaje(float x, int y,char *m);
void menuIngresado();
void todosLosCostos(int x, float y, float z);

#endif /* OPERACIONESTP_1_H_ */
