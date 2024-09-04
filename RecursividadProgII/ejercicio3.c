#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ejercicio3(){

    int bandera;
    int numero, resultado;

    do{

        printf("\t\t\t Bienvenido al programa 'SERIE DE FIBONACCI'!!\n\n");

        do {
            printf(" Ingrese un NUMERO ENTERO POSITIVO (maximo 45) para calcular su SERIE DE FIBONACCI: ");
            numero = Ingresar_Entero_Positivo();

            if (numero > 45) {
                printf(" Ingreso invalido! El numero no debe ser mayor a 45.\n");
            }
        } while (numero > 45);


        resultado = terminoSeridFibonacci(numero);

        Mostrar_resultado_ejercicio3(resultado, numero);

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
