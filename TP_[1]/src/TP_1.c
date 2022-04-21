#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion,error=TRUE;


	//Inicio del ciclo y termina cuando ingresa la opcion 6 o se comete algun error

		do{

			// Si hay algun error al ingresar datos le da aviso al usuario y cierra la app
			if(error == 0){

				opcion=7;
				error=-1;

			}else{

				//muestro el menu;
				menu();
				//Pido la opcion con un mensaje y la guardo en opcion
				error=getIntPlus("\n\nIngrese una opcion: ",&opcion,1,6," \nOpcion incorrecta,ingrese opcion del 1 al 6: ",3);

			}

			//Se pasa la opcion ingresada y si hay algun error lo devuelve en el puntero.
			menuIngresado(opcion,&error);

		}while(opcion != 6 && error!=-1);




	return EXIT_SUCCESS;
}
