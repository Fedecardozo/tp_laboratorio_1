#include <stdio.h>
#include <stdlib.h>

//Tama�o de Passenger
#define TAM 200

#include "Arraypassenger.h"
#include "menu.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	Passenger pasajero[TAM];

		do{

			if(menu(&opcion)==-1){

				printf("\nError al procesar la opcion. Intentelo mas tarde!");
				break;

			}

			menuIngresado(opcion,pasajero,TAM);


		}while(opcion>0 && opcion<6);

		return EXIT_SUCCESS;


	return EXIT_SUCCESS;
}
