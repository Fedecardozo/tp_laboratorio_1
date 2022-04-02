#include <stdio.h>
#include <stdlib.h>

/*Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
para ofrecerlos a sus clientes.
Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciar� y contar� con un men� de opciones:*/

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


	/*1. Ingresar Kil�metros: ( km=x)
	2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
	- Precio vuelo Aerol�neas:
	- Precio vuelo Latam:
	3. Calcular todos los costos:
	a) Tarjeta de d�bito (descuento 10%)
	b) Tarjeta de cr�dito (inter�s 25%)
	c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
	d) Mostrar precio por km (precio unitario)
	e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
	4. Informar Resultados
	�Latam:
	a) Precio con tarjeta de d�bito: r
	b) Precio con tarjeta de cr�dito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	Aerol�neas:
	a) Precio con tarjeta de d�bito: r
	b) Precio con tarjeta de cr�dito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	La diferencia de precio es : r �
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
	printf("\n - Precio vuelo Aerol�neas: ");
	scanf("%f",&aero);
	printf("\n - Precio vuelo Latam: ");
	scanf("%f",&latam);


}*/


void todosLosCostos(){

	/*3. Calcular todos los costos:
		a) Tarjeta de d�bito (descuento 10%)
		b) Tarjeta de cr�dito (inter�s 25%)
		c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
		d) Mostrar precio por km (precio unitario)
		e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)*/

	float total=aero+latam;



	printf("\n a) Tarjeta debito %f",total*0.9);
	printf("\n b) Tarjeta de credito %f",total*1.25);
	printf("\n c) Bitcoin %f",total/4606954.55);
	printf("\n d) Mostrar precio por km %f",total/km);
	printf("\n e) Mostrar diferencia de precio ingresada %f",latam-aero);




}

void informe(){

	/*4. Informar Resultados
	�Latam:
	a) Precio con tarjeta de d�bito: r
	b) Precio con tarjeta de cr�dito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	Aerol�neas:
	a) Precio con tarjeta de d�bito: r
	b) Precio con tarjeta de cr�dito: r
	c) Precio pagando con bitcoin : r
	d) Precio unitario: r
	La diferencia de precio es : r �*/

	printf("\n 4. Informar Resultados");
	printf("\n Latam:");
	printf("\n a) Precio con tarjeta de d�bito: %f",latam*0.90);
	printf("\n b) Precio con tarjeta de cr�dito: %f",latam*1.25);
	printf("\n c) Precio pagando con bitcoin: %f",latam/4606954.55);
	printf("\n d) Precio unitario: %f",latam/km);
	printf("\n Aerol�neas:");
	printf("\n a) Precio con tarjeta de d�bito: %f",aero*0.90);
	printf("\n b) Precio con tarjeta de cr�dito: %f",aero*1.25);
	printf("\n c) Precio pagando con bitcoin: %f",aero/4606954.55);
	printf("\n d) Precio unitario: %f",aero/km);
	printf("\n La diferencia de precio es: %f",latam-aero);



}

void menuIngresado(int x){




	switch(x){


		case 1: kilometro();break;
		case 2:
				printf("\n 2. Ingrese precio ");
				printf("\n - Precio vuelo Aerol�neas: ");
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
