
#include "funcionesPropias.h"

/// @fn Preguntar por si o por no
/// @param msj
/// @param intentos
/// @param msjError
/// @return 1 si 0 no -1 mal los datos
int preguntarSoN(char*msj,int intentos, char*msjError){

	int retorno=-1;
	char respuesta[2];

	if(msj != NULL && msjError != NULL && intentos >=0)
	{

		do{

			printf(msj);

			if(myGets(respuesta,sizeof(respuesta))==0)
			{
				strupr(respuesta);
				if(respuesta[0] =='S' || strcmp(respuesta,"SI")==0)
				{
					retorno=1;
					break;

				}
				if( respuesta[0] =='N'|| strcmp(respuesta,"NO")==0)
				{
					retorno=0;
					break;

				}
				if(intentos>0)
				{

					printf(msjError);

				}

				intentos--;

			}

		}while(intentos>=0);


	}

	return retorno;


}

