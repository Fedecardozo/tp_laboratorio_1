
#ifndef FUNCIONESARCHIVOS_H_
#define FUNCIONESARCHIVOS_H_

#include <stdio.h>
#include <stdlib.h>

int File_openModeReadWriteTxt(char* path,char* mode);
int File_openModeReadWriteBin(char* path,char* mode);
int File_openWriteTxtSave_w(char* path,char* texto);
int File_openWriteTxtSave(char* path,char* texto,char* mode, int cursor);
int File_openWriteTxtSaveInicio(char* path,char* texto);
int File_openWriteBinarioSave(char* path,void* direccion,int bytes,char* mode, int cursor);

#endif /* FUNCIONESARCHIVOS_H_ */
