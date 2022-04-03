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
float getFloat(char*m){

	float x;

	printf(m);
	scanf("%f",&x);

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
void porcentaje(float x, int y,char *m){

	float resultado;

	resultado = x*(1+(y*0.01)) ;

	printf("%s %f",m,resultado);

}
// punto 3
void todosLosCostos(int x, float y, float z){

	float total=y+z;

	porcentaje(total,-10,"\n a) Tarjeta debito: $");
	porcentaje(total,25,"\n b) Tarjeta de credito: $");
	printf("\n c) Bitcoin $%f",total/4606954.55);
	printf("\n d) Mostrar precio por km $%f",total/x);
	printf("\n e) Mostrar diferencia de precio ingresada $%f \n",y-z);


}
// punto 4
void informe(float y, float z, int x){

	printf("\n 4. Informar Resultados");

	printf("\n Latam:");
	porcentaje(y,-10,"\n a) Precio con tarjeta de débito: $");
	porcentaje(y,25,"\n b) Precio con tarjeta de credito: $");
	printf("\n c) Precio pagando con bitcoin: $%f",y/4606954.55);
	printf("\n d) Precio unitario: $%f",y/x);

	printf("\n Aerolíneas:");
	porcentaje(z,-10,"\n a) Precio con tarjeta de débito: $");
	porcentaje(z,25,"\n b) Precio con tarjeta de credito: $");
	printf("\n c) Precio pagando con bitcoin: $%f",z/4606954.55);
	printf("\n d) Precio unitario: $%f",z/x);

	printf("\n La diferencia de precio es: $%f \n",z-y);


}
int menu(){


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


	printf("\n 1. Ingresar km ");
	printf("\n 2. Ingresar precio de vuelos ");
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar Resultados");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir");

	//Pido la opcion con un mensaje y la guardo en opc
	opc=getInt("\n\n Ingrese opcion: ");

	system("cls");

	//Valido que la opcion sea correcta segun los parametros asigandos
	opc=validador(opc,1,6,3," \nOpcion incorrecta,ingrese opcion del 1 al 6: ");

	return opc;

}

void menuIngresado(){

	int opcion,km;
	float aero,latam;

	do{

		opcion = menu();

		switch(opcion){


			case 1: km=getInt("\n Ingrese kilometros: ");break;

			case 2:
					printf("\nIngresar vuelos: ");
					latam = getFloat("\n -Precio vuelo Latam: ");
					aero = getFloat("\n -Precio vuelo Aerolineas: ");
					break;

			case 3:	todosLosCostos(km,aero,latam);break;

			case 4: informe(km,aero,latam);break;

			//case 5: cargaForzada()break;*/

			case 6: printf("\n Gracias por usar nuestra aplicacion\n Hasta luego! ");break;


		}


	}while(opcion != 6);


}


