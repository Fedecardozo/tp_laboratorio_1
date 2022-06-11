
#include "funcionesArchivos.h"

/// @fn int File_openModeReadWriteTxt(char*, char*)
/// @brief abre un archivo y lo cierra con los modos
/// pasados por parametros. Sirve para borrar contenido
/// del archivo
/// @param path
/// @param mode
/// @return -1 datos nullos, ok
int File_openModeReadWriteTxt(char* path,char* mode){

	int retorno = -1;
	FILE* pFile;

	if(path != NULL && mode != NULL)
	{
		pFile=fopen(path,mode);

		if(pFile != NULL)
		{
			//fwrite(&i,sizeof(int),1,);
			//fprintf(pFile,"%d",1);
			retorno=0;
			fclose(pFile);
		}

	}

	return retorno;
}

/// @fn int File_openWriteTxtSave_w(char*, char*)
/// @param path
/// @param texto
/// @return -1 datos nullos, -2 error al abrir el archivo, 0 OK
int File_openWriteTxtSave_w(char* path,char* texto)
{
	int retorno=-1;
	FILE* archivo;

	if(path != NULL && texto != NULL)
	{
		archivo = fopen(path,"w+");

		if(archivo != NULL)
		{
			retorno=0;
			fprintf(archivo,"\n%s",texto);
			fclose(archivo);

		}
		else
		{
			retorno = -2;
		}
	}



    return retorno;
}

/// @fn File_openWriteTxtSave(char* path,char* texto,char* mode, int cursor)
/// @param char* path
/// @param char* texto
/// @param char* mode
/// @param int cursor
/// @return -1 datos nullos, -2 error al abrir el archivo, 0 OK
int File_openWriteTxtSave(char* path,char* texto,char* mode, int cursor)
{
	int retorno=-1;
	FILE* archivo;

	if(path != NULL && texto != NULL && mode != NULL && cursor>=0 && cursor<=3)
	{
		archivo = fopen(path,mode);

		if(archivo != NULL)
		{
			retorno=0;
			fseek( archivo , 0 , cursor);
			fprintf(archivo,"%s\n",texto);
			fclose(archivo);

		}
		else
		{
			retorno = -2;
		}

	}



    return retorno;
}

/// @fn int File_openWriteBinarioSave(char* path,char* texto,char* mode, int cursor)
/// @param char* path
/// @param char* texto
/// @param char* mode
/// @param int cursor
/// @param void* direccion
/// @return -1 datos nullos, -2 error al abrir el archivo, 0 OK
int File_openWriteBinarioSave(char* path,void* direccion,int bytes,char* mode, int cursor)
{
	int retorno=-1;
	FILE* archivo;

	if(path != NULL && direccion != NULL && bytes>0 && mode != NULL && cursor>=0 && cursor<=3)
	{
		archivo = fopen(path,mode);

		if(archivo != NULL)
		{
			retorno=0;
			fseek( archivo , 0 , cursor);
			fwrite(direccion,bytes,1,archivo);
			fclose(archivo);

		}
		else
		{
			retorno = -2;
		}

	}



    return retorno;
}



