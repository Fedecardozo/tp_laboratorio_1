
#include "operaciones.h"


float dividir(float x, float y){

	float resultado=0;

	if(y==0){

		return 0;

	}else{

		resultado = x/y;
		return resultado;

	}



}

// Hace un aumento porcentual o descuento segun si el numero(y) es positivo o negativo
float porcentaje(float x, int y){

	float resultado;

	resultado = x*(1+(y*0.01)) ;

	return resultado;

}


