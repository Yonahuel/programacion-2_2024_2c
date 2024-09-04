
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Ejercicios.h"
#include "validaciones.h"


void ejercicio10(){

    int bandera, N, B, Cantidad_Fragmentos;

    do{
        int *Fragmentos;
        Cantidad_Fragmentos = 0;

        printf("\t\t\t Bienvenido al programa 'BOMBAA'!!\n\n");

        printf(" Ingrese el Numero Explosivo 'N' (Numero entero > 2): ");
        N = Ingresar_Entero_Positivo();

        while(N < 2){

            printf(" Igreso Invalido! Debe ingresar un numero entero positivo >= 2!\n");
            printf(" Ingrese el Numero Explosivo 'N' (Numero Entero >= 2): ");
            N = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        printf(" Ingrese el Numero Bomba 'B' (Numero Entero >= 1): ");
        B = Ingresar_Entero_Positivo();

        while(B < 1){

            printf(" Igreso Invalido! Debe ingresar un numero entero positivo >= 1!\n");
            printf(" Ingrese el Numero Bomba 'B' (Numero Entero >= 1): ");
            N = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        Fragmentos = explosion(N, B, &Cantidad_Fragmentos);

        Mostrar_resultado_ejercicio10(Fragmentos, Cantidad_Fragmentos, N, B);

        printf("\n Desea volver a realizar el ejercicio? (*Ingrese '0' para salir del sistema; *Ingrese '1' para volver a realizarlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(Fragmentos);

    }
    while(bandera != 0);

    printf("\t\t Hasta la proxima!\n");
    system("pause");

}
