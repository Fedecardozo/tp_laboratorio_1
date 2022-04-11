
#ifndef FUNCIONESAGENCIA_H_
#define FUNCIONESAGENCIA_H_

#include "operaciones.h"
#include "inputs.h"

#define BTC 4606954.55

//Variables que uso en los puntos 3 y 4
float latamDebito,latamCredito,latamBtc,latamUnitario;
float aeroDebito,aeroCredito,aeroBtc,aeroUnitario;
float diferenciaPrecio;

//2- guardo 2 variables
int getDobleFloat(float*y,float*z);

//3- Validacion carga de datos
int bandera(int a, int b);

//3- Calculo todos los costos y no muestro nada
int todosLosCostos(int bool1,int bool2,int x, float y, float z);

void calculos(float* a,float* b,float* c,float* d,float y,int x);

//4- Muestro todos los calculos de la opcion 3
void informe(int bool1,int bool2,int bool3);

//5- harcodeo los punto 1 y 2 y llamo a los puntos 3 y 4
void cargaForzada(int* x, float* y, float* z,int*a,int*b,int*c);


#endif /* FUNCIONESAGENCIA_H_ */



