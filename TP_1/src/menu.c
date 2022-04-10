

#include "menu.h"

void menu(){

	printf("\n 1. Ingresar km ");
	printf("\n 2. Ingresar precio de vuelos ");
	printf("\n 3. Calcular todos los costos");
	printf("\n 4. Informar Resultados");
	printf("\n 5. Carga forzada de datos");
	printf("\n 6. Salir");

}

void menuIngresado(){

	int opcion,km,error=TRUE;
	float aero,latam;
	int flag1=FALSE,flag2=FALSE;
	int tres=FALSE;


	do{



		if(error == 0){

			opcion=7;
			error=-1;

		}else{

			//muestro el menu;
			menu();
			//Pido la opcion con un mensaje y la guardo en opcion
			error=getIntPlus("\n\nIngrese una opcion: ",&opcion,1,6," \nOpcion incorrecta,ingrese opcion del 1 al 6: ",3);

		}
		switch(opcion){


			case 1:

				flag1=getIntPlus("\n Ingrese kilometros: ",&km,1,1000000,"\nError km invalido!\n-Ingrese nuevamente:",2);
				error=flag1;
				break;

			case 2:

				flag2=getDobleFloat(&aero,&latam);
				error=flag2;
				break;

			case 3:

				tres=todosLosCostos(flag1,flag2,km,aero,latam);

				break;

			case 4: informe(flag1,flag2,tres);break;

			case 5: cargaForzada(&km,&aero,&latam,&flag1,&flag2,&tres); break;

			case 6: printf("\n Gracias por usar nuestra aplicacion\n Hasta luego! ");break;

			default: printf("\n Algo salio mal!, intentelo mas tarde...");break;

		}



	}while(opcion != 6 && error!=-1);


}
