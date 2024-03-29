

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

/// @fn Informa los errores al dar de baja
/// @param error para el switch
static void erroresBaja(int error){


	switch(error){

	 case 0: printf("\nSE DIO DE BAJA CON EXITO !"); break;
	 case -1: printf("\nERROR DATOS INVALIDOS !"); break;
	 case -2: printf("\nNO EXISTE EL TAL ID !"); break;
	 case -3: printf("\nNO HAY PASAJEROS CARGADOS !"); break;
	 case -4: printf("\nNO SE DIO DE BAJA!"); break;
	 default: printf("\nALGO SALIO MAL !"); break;



	}


}

/// @fn Informa los errores al modificar
/// @param error para el switch
static void erroresModificacion(int error){

	switch(error){

	 case 0: printf("\nPROCESO TERMINADO !"); break;
	 case -1: printf("\nERROR DATOS INVALIDOS !"); break;
	 case -2: printf("\nNO EXISTE EL TAL ID !"); break;
	 case -3: printf("\nINGRESO MAL LAS OPCIONES !"); break;
	 case -4: printf("\nINGRESO MAL LOS DATOS A MODIFICAR!"); break;
	 case -5: printf("\nRESPUESTA INCORRECTA !"); break;
	 case -6: printf("\nRESPUESTA INCORRECTA !"); break;
	 case -7: printf("\nNO HAY PASAJEROS CARGADOS !"); break;
	 default: printf("\nALGO SALIO MAL !"); break;



	}


}

static void informar(Passenger* pasa,int tam){


	//1.Listado de los pasajeros ordenados alfab�ticamente por Apellido y Tipo de pasajero.
	switch(printSortPassengers(pasa, tam,1))
	{

	 case 0: printf("\nSE ORDENO CON EXITO !"); break;
	 case -1: printf("\nERROR EN LOS DATOS !"); break;
	 case -2: printf("\nERROR AL ORDENAR ALFABETICAMENTE !"); break;
	 case -3: printf("\nERROR AL ORDENAR TIPO PASAJERO !"); break;
	 case -4: printf("\nNO HAY DATOS CARGADOS!"); break;
	 case -5: printf("\nERROR AL IMPRIMIR TODOS LOS DATOS!"); break;
	 default: printf("\nALGO SALIO MAL !"); break;

	}


	//2.Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio
	//promedio.
	switch(printPromedioPassenger(pasa, tam))
		{

		 //case 0: printf("\nSE ESTA CALCULANDO..."); break;
		 case -1: printf("\nERROR EN LOS DATOS !"); break;
		 case -2: printf("\nNO HAY DATOS CARGADOS!"); break;
		 default: printf("\nSE CALCULO CON EXITO !"); break;

		}

	//3. Listado de los pasajeros por C�digo de vuelo y estados de vuelos �ACTIVO�
	switch(printSortPassengersByCode(pasa, tam, 1, 1))
		{

		 case 0: printf("\nSE ORDENO CON EXITO !"); break;
		 case -1: printf("\nERROR EN LOS DATOS !"); break;
		 case -2: printf("\nERROR AL ORDENAR POR CODIGO !"); break;
		 case -3: printf("\nNO HAY DATOS CARGADOS!"); break;
		 case -4: printf("\nERROR AL IMPRIMIR TODOS LOS DATOS!"); break;
		 default: printf("\nALGO SALIO MAL !"); break;

		}


}

void menuIngresado(int opcion,Passenger* pasa,int tam){

	switch(opcion){


		case 1:

			erroresAlta(altaPassenger(pasa, tam));

			break;

		case 2:

			erroresModificacion(modificionPassenger(pasa, tam));

			break;

		case 3:

			erroresBaja(bajaPassenger(pasa, tam));

			break;


		case 4:

			informar(pasa,tam);

			break;

		case 5:

				harcodeo(pasa,tam);
				printPassengers(pasa, tam);

			 break;

		case 6: printf("\n\nGracias por usar nuestra app. Hasta luego!") ;break;

		default: printf("\nError al procesar la opcion. Intentelo mas tarde!"); ;break;

		}


}
