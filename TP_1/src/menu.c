

#include "menu.h"

void menu(){

	printf("\n 1. Ingresar km ");
	printf("\n 2. Ingresar precio de vuelos ");
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar Resultados");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir");

}

//Variables que uso en el menuIngresado()

int flag1=FALSE,flag2=FALSE;
int tres=FALSE;
int km;
float aero,latam;

void menuIngresado(int opcion,int* error){


	switch(opcion){


		case 1:

			flag1=getIntPlus("\n Ingrese kilometros: ",&km,1,1000000,"\nError km invalido!\n-Ingrese nuevamente:",2);
			*error=flag1;
			break;

		case 2:

			flag2=getDobleFloat(&aero,&latam);
			*error=flag2;
			break;

		case 3:

			tres=todosLosCostos(flag1,flag2,km,aero,latam);

			break;

		case 4: informe(flag1,flag2,tres);break;

		case 5: cargaForzada(&km,&aero,&latam,&flag1,&flag2,&tres); break;

		case 6: printf("\n Gracias por usar nuestra aplicacion\n Hasta luego! ");break;

		default: printf("\n Algo salio mal!, intentelo mas tarde...");break;

		}


}
