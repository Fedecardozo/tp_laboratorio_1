#include <stdio.h>
#include <stdlib.h>
#include "Cardozo.h"

int main()
{
    int x=0, y=0 , opcion;

    do{
        system("cls");
        printf("\t\t\t********* MENU DE OPCIONES **********");
        printf("\n\n 1. Ingresar 1er operando (A=%d)", x);
        printf("\n 2. Ingresar 2do operando (B=%d)", y);
        printf("\n 3. Calcular todas las operaciones ");
        printf("\n a) Calcular la suma (A+B)");
        printf("\n b) Calcular la resta (A-B)  ");
        printf("\n c) Calcular la division (A/B)  ");
        printf("\n d) Calcular la multiplicacion (A*B)  ");
        printf("\n e) Calcular el factorial (A!) y (B!) ");
        printf("\n 4. Informar resultados    ");
        printf("\n 5. Salir ");
        printf("Opciones:");
        scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
            system("cls");
            printf("Ingrese primer numero: ");
            scanf("%d", &x);
            break;

        case 2:
            system("cls");
            printf("Ingrese segundo numero: ");
            scanf("%d", &y);
            break;

            while(y==0)
            {
                printf("Error!, no se puede dividir por 0. Ingrese nuevamente segundo numero: ");
                scanf("%d", &y);
            }
            break;

        case 3:
            system("cls");
            printf("Para visualizar resultados. \nSeleccione la opcion numero 4 ");
            system("\n\npause");
            break;

        case 4:
            system("cls");
            printf("\t\t Los resultados son: ");
            printf("\n\na)La suma de %d + %d es igual= %d", x, y, sumar(x,y));
            printf("\nb)La resta de %d - %d es igual = %d", x, y, restar(x,y));
            printf("\nc)La division de %d / %d es igual= %.2f", x, y, dividir(x,y));
            printf("\nd)La multiplicacion de %d * %d es igual= %d",x ,y ,multiplicar(x,y));
            printf("\ne)Factorial de %d es= %d y \nFactorial de %d= %d\n", x, factorial(x), y , factorial(y));
            system("\n\npause");

        case 5:
            break;

        default:
            system("cls");
            printf("Error, la opcion ingresada es invalida\n");
            system("pause");
            break;
    }

        }while(opcion !=5);

        return 0;

}
