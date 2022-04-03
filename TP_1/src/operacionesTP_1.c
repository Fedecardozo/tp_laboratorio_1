/*
 * operacionesTP_1.c
 *
 * Desarrollo de las funciones
 *
 */

#include "operacionesTP_1.h"

int getInt(char*m){

	int x;

	printf(m);
	scanf("%d",&x);

	return x;


}

int validador(int rta,int menor,int mayor,int cantidad,char*m){

	int cont=0;

	while(rta<menor || rta>mayor){

		cont++;
		rta = getInt(m);

		if(cont==cantidad){

			rta=6;

		}

	}

	return rta;
}

void menu(){


	/*1. Ingresar Kilómetros: ( km=x)
	2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
	- Precio vuelo Aerolíneas:
	- Precio vuelo Latam:
	3. Calcular todos los costos:
	a) Tarjeta de débito (descuento 10%)
	b) Tarjeta de crédito (interés 25%)
	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	d) Mostrar precio por km (precio unitario)
	e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
	4. Informar Resultados
	“Latam:
	a) Precio con tarjeta de débito: r
	b) Precio con tarjeta de crédito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	Aerolíneas:
	a) Precio con tarjeta de débito: r
	b) Precio con tarjeta de crédito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	La diferencia de precio es : r “
	5. Carga forzada de datos
	6. Salir*/

	int opc;//,cont=0;

	do{

		printf("\n 1. Ingresar km ");
		printf("\n 2. Ingresar precio de vuelos ");
		printf("\n 3. Calcular todos los costos");
		printf("\n 4. Informar Resultados");
		printf("\n 5. Carga forzada de datos");
		printf("\n 6. Salir");

		/*printf("\n Ingrese opcion: ");
		scanf("%d",&opc);*/
		opc=getInt("\n Ingrese opcion: ");

		opc=validador(opc,1,6,3," Opcion incorrecta,ingrese opcion del 1 al 6: ");

		/*while(opc<1 || opc>6){

			cont++;

			//printf(" Opcion incorrecta,ingrese del 1 al 6 \n Ingrese nuevamente: ");
			//scanf("%d",&opc);
			opc=getInt("Opcion incorrecta,ingrese del 1 al 6 \n Ingrese nuevamente:");

			if(cont==3){

				opc=6;

			}

		}*/

		//menuIngresado(opc);



	}while(opc != 6);


}


