

#include "menu.h"

/// @fn  menu
/// @param x puntero para guardar la opcion ingresada
/// @return 1 bien 0 mal
int menu(int* x){

	int opc;
	int rta;

	printf("\n\n\t ********* MENU *********");
	printf("\n 1. Alta ");
	printf("\n 2. Modificar ");
	printf("\n 3. Baja ");
	printf("\n 4. Informar ");
	printf("\n 5. Alta forzada de datos");
	printf("\n 6. Salir");

	rta=utn_getNumero(&opc, "\nIngrese opcion:", "\nOpcion incorrecta! \nIngrese nuevamente:", 1, 6, 2);
	if(rta==0){

		*x=opc;

	}

	return rta;

}

//***FUNCIONES DEL MENU

void menuIngresado(int opcion,Passenger* pasa,int tam){

	switch(opcion){


		case 1:

			break;

		case 2:

			break;

		case 3:


			break;


		case 4:



			break;

		case 5:


			 break;

		case 6: printf("\n\nGracias por usar nuestra app. Hasta luego!") ;break;

		default: printf("\nError al procesar la opcion. Intentelo mas tarde!"); ;break;

		}


}
