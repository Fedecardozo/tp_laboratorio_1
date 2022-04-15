
#include "funcionesAgencia.h"


//Punto 2
int getDobleFloat(float*y,float*z){

	int uno;
	int dos;
	int retorno=0;
	float num1,num2;
	printf("\nIngresar vuelos: \n");

	uno = getFloatPlus("\n -Precio vuelo Aerolineas: ", &num1, 1.00, 3000000.00, "\nPrecio incorrecto \n -Ingrese precio:", 2);

	if(uno == FALSE){

		retorno= FALSE;

	}else if(uno == TRUE){

		dos = getFloatPlus("\n -Precio vuelo Latam: ", &num2, 1.00, 3000000.00, "\nPrecio incorrecto \n -Ingrese precio:", 2);

	}

	if(dos == FALSE){

		retorno= FALSE;

	}else if(uno == TRUE && dos == TRUE){

		*y = num1;
		*z = num2;
		retorno = TRUE;

	}

	return retorno;
}


//Valido que los datos esten cargados punto 3
int bandera(int a, int b){

	if(a==TRUE && b==TRUE){

			return 2;

	}else{

		if(a==0){

			printf("\n Faltan cargar los kilometro. Opcion 1\n");

		}
		if(b==0){

			printf("\n Faltan cargar los precios de los vuelos. Opcion 2\n");

		}

		return FALSE;

	}


}

//Calculos
void calculos(float* a,float* b,float* c,float* d,float y,int x){


	*a= porcentaje(y,-10);
	*b= porcentaje(y,25);
	*c= dividir(y,BTC);
	*d= dividir(y,x);

}

//3- Calculo todos los costos y no muestro nada
int todosLosCostos(int bool1,int bool2,int x, float y, float z){

	if(bandera(bool1,bool2)==2){

		//Aerolineas
		calculos(&aeroDebito,&aeroCredito,&aeroBtc,&aeroUnitario,y,x);

		//Latam
		calculos(&latamDebito,&latamCredito,&latamBtc,&latamUnitario,z,x);

		//Precio unitario
		if(z > y){

			diferenciaPrecio = z - y;

		}else{

			diferenciaPrecio = y - z;

		}

		printf("\n Calculos realizados!..\n");
		return TRUE;

	}else{

		return FALSE;

	}




}


//4- Muestro todos los calculos de la opcion 3
void informe(int bool1,int bool2,int bool3){

	int ban=2;



	if(bool3 == FALSE){

		printf("\n Te falto calcular los datos! En la opcion 3!\n");
		ban = bandera(bool1,bool2);

	}else if(ban == 2){

		printf("\n 4. Informar Resultados");

			printf("\n\n Aerolineas: ");
			printf("\n a) Precio con tarjeta de debito: $ %f",aeroDebito);
			printf("\n b) Precio con tarjeta de credito: $ %f",aeroCredito);
			printf("\n c) Precio pagando con bitcoin: $ %f",aeroBtc);
			printf("\n d) Precio unitario: $ %f",aeroUnitario);


			printf("\n\n Latam:");
			printf("\n a) Precio con tarjeta de debito: $ %f",latamDebito);
			printf("\n b) Precio con tarjeta de credito: $ %f",latamCredito);
			printf("\n c) Precio pagando con bitcoin: $ %f",latamBtc);
			printf("\n d) Precio unitario: $ %f",latamUnitario);

			printf("\n\n La diferencia de precio es: $ %f \n",diferenciaPrecio);


	}


}

//5- harcodeo los punto 1 y 2 y llamo a los puntos 3 y 4

void cargaForzada(int* x, float* y, float* z,int*a,int*b,int*c){

	//km: 7090
	//Aerolineas Argentinas: $162965
	//Latam: $ 159339

	//Punto 1
	*x = 7090;
	*a=1;

	//Punto 2
	*y = 162965;
	*z = 159339;
	*b=1;

	//Punto 3
	*c=todosLosCostos(*a,*b,*x, *y, *z);

	//Punto 4;
	informe(*a,*b,*c);


}
