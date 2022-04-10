
#include "inputs.h"


// guardar entero sin validacion
void getInt(char*msj,int*x){

	int num;

	printf(msj);
	scanf("%d",&num);

	*x = num;

}

// guardo numero entero con validacion
int getIntPlus(char*msj,int*x,int min,int max,char *msjError,int intentos){

	int aux;
	int retorno=0;
	int cont=0;

	if(msj != NULL && x != NULL && min<max && msjError != NULL && intentos>0 ){

		printf(msj);
		scanf("%d",&aux);

		do{

			if(aux<min || aux>max){

				printf(msjError);
				scanf("%d",&aux);
				cont++;

			}
			if(aux>=min && aux<=max){

				*x = aux;
				retorno = 1;
				cont = intentos;

			}



		}while(cont != intentos);


	}else{


		retorno = 0;


	}



	return retorno;

}

// guardo flotante sin validacion
int getFloat(char*m,float*x){

	float num;

	printf(m);
	scanf("%f",&num);

	*x =num;

	return 1;

}

// guardo flotante con validacion
int getFloatPlus(char*msj,float*x,float min,float max,char *msjError,int intentos){

	float aux;
	int retorno=0;
	int cont=0;

	if(msj != NULL && x != NULL && min<max && msjError != NULL && intentos>0 ){

		printf(msj);
		scanf("%f",&aux);

		do{

			if(aux<min || aux>max){

				printf(msjError);
				scanf("%f",&aux);
				cont++;

			}
			if(aux>=min && aux<=max){

				*x = aux;
				retorno = 1;
				cont = intentos;

			}



		}while(cont != intentos);


	}else{


		retorno = 0;


	}



	return retorno;

}
