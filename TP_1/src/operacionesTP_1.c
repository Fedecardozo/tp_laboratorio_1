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

int bandera(int a, int b){

	if(a==1 && b==1){

			return 2;

	}else{

		if(a==0){

			printf("\n Faltan cargar los kilometro. Opcion 1\n");

		}
		if(b==0){

			printf("\n Faltan cargar los precios de los vuelos. Opcion 2\n");

		}

		return 0;

	}




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
	porcentaje(y,-10,"\n a) Precio con tarjeta de d�bito: $");
	porcentaje(y,25,"\n b) Precio con tarjeta de credito: $");
	printf("\n c) Precio pagando con bitcoin: $%f",y/4606954.55);
	printf("\n d) Precio unitario: $%f",y/x);

	printf("\n Aerol�neas:");
	porcentaje(z,-10,"\n a) Precio con tarjeta de d�bito: $");
	porcentaje(z,25,"\n b) Precio con tarjeta de credito: $");
	printf("\n c) Precio pagando con bitcoin: $%f",z/4606954.55);
	printf("\n d) Precio unitario: $%f",z/x);

	printf("\n La diferencia de precio es: $%f \n",z-y);


}
int menu(){

	int opc;//,cont=0;


	printf("\n 1. Ingresar km ");
	printf("\n 2. Ingresar precio de vuelos ");
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar Resultados");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir");

	//Pido la opcion con un mensaje y la guardo en opc
	opc=getInt("\n\n Ingrese opcion: ");

	//Valido que la opcion sea correcta segun los parametros asigandos
	opc=validador(opc,1,6,3," \nOpcion incorrecta,ingrese opcion del 1 al 6: ");

	return opc;

}

void menuIngresado(){

	int opcion,km;
	float aero,latam;
	int flag1=FALSE, flag2=FALSE;

	do{

		opcion = menu();

		switch(opcion){


			case 1:

				km=getInt("\n Ingrese kilometros: ");
				flag1=TRUE;
				break;

			case 2:
					printf("\nIngresar vuelos: ");
					latam = getFloat("\n -Precio vuelo Latam: ");
					aero = getFloat("\n -Precio vuelo Aerolineas: ");
					flag2=TRUE;
					break;

			case 3:

				if(bandera(flag1,flag2)==2){

					todosLosCostos(km,aero,latam);

				}

				break;

			case 4:

				if(bandera(flag1,flag2)==2){

					informe(km,aero,latam);

				}

				break;

			//case 5: cargaForzada()break;*/

			case 6: printf("\n Gracias por usar nuestra aplicacion\n Hasta luego! ");break;


		}


	}while(opcion != 6);


}


