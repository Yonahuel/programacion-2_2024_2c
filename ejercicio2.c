#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void ejercicio2(){

    int bandera;
    int m, n, resultado;

    do{

        printf("\t\t\t Bienvenido al programa 'PRODUCTO DE DOS NUMEROS MEDIANTE SUMAS SUCESIVAS'!!\n\n");

        printf(" Ingrese el NUMERO 'MULTIPLICANDO': "); m = Ingreso_Entero_Positivo_Negativo();

        printf(" Ingrese el NUMERO 'MULTIPLICADOR': "); n = Ingreso_Entero_Positivo_Negativo();

        resultado = producto(m, n);

        Mostrar_resultado_ejercicio2(resultado, m, n);

        printf("\n Desea volver a realizar el ejercicio? (*Ingrese '0' para salir del sistema; *Ingrese '1' para volver a realizarlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }
    }
    while(bandera != 0);

    printf("\t\t Hasta la proxima!\n");
    system("pause");

}
