
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

float porcentaje(float x, int y){

	float resultado;

	resultado = x*(1+(y*0.01)) ;

	return resultado;

}


