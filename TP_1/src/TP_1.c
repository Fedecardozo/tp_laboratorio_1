#include <stdio.h>
#include <stdlib.h>

/*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:*/

//Variables globales
float aero=0, latam=0;
int km;

// Prototypo

void menu();
void menuIngresado(int x);
void kilometro();
//void precioVuelos();
void todosLosCostos();
void informe();



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

	int opc,cont=0;

	do{

		printf("\n 1. Ingresar km ");
		printf("\n 2. Ingresar precio de vuelos ");
		printf("\n 3. Calcular todos los costos");
		printf("\n 4. Informar Resultados");
		printf("\n 5. Carga forzada de datos");
		printf("\n 6. Salir");

		printf("\n Ingrese opcion: ");
		scanf("%d",&opc);

		while(opc<1 || opc>6){

			cont++;

			printf(" Opcion incorrecta,ingrese del 1 al 6 \n Ingrese nuevamente: ");
			scanf("%d",&opc);

			if(cont==3){

				opc=6;

			}

		}

		menuIngresado(opc);



	}while(opc != 6);


}
void kilometro(){


	printf("\n 1. Ingrese kilometros: ");
	scanf("%d",&km);

	printf("\n KMs Ingresados: %d km",km);
}

/*void precioVuelos(){


	// pido los precios
	printf("\n 2. Ingrese precio ");
	printf("\n - Precio vuelo Aerolíneas: ");
	scanf("%f",&aero);
	printf("\n - Precio vuelo Latam: ");
	scanf("%f",&latam);


}*/


void todosLosCostos(){

	/*3. Calcular todos los costos:
		a) Tarjeta de débito (descuento 10%)
		b) Tarjeta de crédito (interés 25%)
		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
		d) Mostrar precio por km (precio unitario)
		e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)*/

	float total=aero+latam;



	printf("\n a) Tarjeta debito %f",total*0.9);
	printf("\n b) Tarjeta de credito %f",total*1.25);
	printf("\n c) Bitcoin %f",total/4606954.55);
	printf("\n d) Mostrar precio por km %f",total/km);
	printf("\n e) Mostrar diferencia de precio ingresada %f",latam-aero);




}

void informe(){

	/*4. Informar Resultados
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
	La diferencia de precio es : r “*/

	printf("\n 4. Informar Resultados");
	printf("\n Latam:");
	printf("\n a) Precio con tarjeta de débito: %f",latam*0.90);
	printf("\n b) Precio con tarjeta de crédito: %f",latam*1.25);
	printf("\n c) Precio pagando con bitcoin: %f",latam/4606954.55);
	printf("\n d) Precio unitario: %f",latam/km);
	printf("\n Aerolíneas:");
	printf("\n a) Precio con tarjeta de débito: %f",aero*0.90);
	printf("\n b) Precio con tarjeta de crédito: %f",aero*1.25);
	printf("\n c) Precio pagando con bitcoin: %f",aero/4606954.55);
	printf("\n d) Precio unitario: %f",aero/km);
	printf("\n La diferencia de precio es: %f",latam-aero);



}

void menuIngresado(int x){




	switch(x){


		case 1: kilometro();break;
		case 2:
				printf("\n 2. Ingrese precio ");
				printf("\n - Precio vuelo Aerolíneas: ");
				scanf("%f",&aero);
				printf("\n - Precio vuelo Latam: ");
				scanf("%f",&latam);
				break;
		case 3:	todosLosCostos();break;
		case 4: informe();break;
		//case 5: cargaForzada()break;
		case 6: printf(" Gracias por usar nuestra aplicacion\n Hasta luego! ");break;


	}


}

int main(void) {

	setbuf(stdout,NULL);

	menu();
	//menuIngresado(x);

	return EXIT_SUCCESS;
}
