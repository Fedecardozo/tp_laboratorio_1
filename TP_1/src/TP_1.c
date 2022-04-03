#include <stdio.h>
#include <stdlib.h>
#include "operacionesTP_1.h"

/*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:*/

int main(void) {

	setbuf(stdout,NULL);

	menu();
	//menuIngresado(x);

	return EXIT_SUCCESS;
}
