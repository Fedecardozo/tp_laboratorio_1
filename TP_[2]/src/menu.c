

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

/// @fn Informa los errores al dar de alta
/// @param error para el switch
static void erroresAlta(int error){

	switch(error){

	 case 0: printf("\nSE CARGO CON EXITO !"); break;
	 case -1: printf("\nERROR DATOS INVALIDOS !"); break;
	 case -2: printf("\nNO HAY MAS LUGAR !"); break;
	 default: printf("\nALGO SALIO MAL !"); break;


	}


}

void menuIngresado(int opcion,Passenger* pasa,int tam){

	switch(opcion){


		case 1:

			erroresAlta(altaPassenger(pasa, tam));

			break;

		case 2:

			break;

		case 3:


			break;


		case 4:



			break;

		case 5:

				harcodeo(pasa,tam);
				printPassengers(pasa, tam);

			 break;

		case 6: printf("\n\nGracias por usar nuestra app. Hasta luego!") ;break;

		default: printf("\nError al procesar la opcion. Intentelo mas tarde!"); ;break;

		}


}
