#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void ejercicio1(){

    int bandera;
    bool resultado;
    char cadena_caracteres[TAMANIO_STRING];

    do{

        cadena_caracteres[0] = '\0';

        printf("\t\t\t Bienvenido al programa 'ES UN PALINDROMO'!!\n\n");
        printf(" Ingrese una CADENA DE CARACTERES no especiales (20 caracteres como maximo): ");
        Ingresar_Cadena_Caracteres(cadena_caracteres, TAMANIO_STRING);

        resultado = palindromo(cadena_caracteres);

        Mostrar_Resultado_ejercicio1(resultado, cadena_caracteres);

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
