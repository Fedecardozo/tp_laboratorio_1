
#ifndef VUELO_H_
#define VUELO_H_

#include "utn.h"
#include "funcionesPropias.h"

#define LIBRE 1
#define OCUPADO 0


typedef struct{

	int id;
	int statusFlight;
	int isEmpty;

	int Fk_idPassenger;

}Vuelo;

int Vuelo_Inicializar(Vuelo *list, int len);
int Vuelo_ObtenerIndexLibre(Vuelo *list, int len);
int Vuelo_BuscarPorid(Vuelo *list, int len, int id);
int Vuelo_PediUnDato(Vuelo * list);
void Vuelo_MostrarUno(Vuelo list);
int Vuelo_MostrarTodos(Vuelo *list, int len);



#endif /* VUELO_H_ */
