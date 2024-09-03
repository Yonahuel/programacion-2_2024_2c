#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void ejercicio5(){


    int bandera;
    char numero_string[TAMANIO_STRING];


    do{

        numero_string[0] = '\0';
        char *numero_miles;

        printf("\t\t\t Bienvenido al programa 'AGREGANDO EL SEPARADOR DE MILES'!!\n\n");

        printf(" Ingrese el NUMERO ENTERO al que le pondremos los separadores de miles (maximo 10 digitos): ");

        Ingresar_Cadena_Caracteres_Numeros_Signos(numero_string, TAMANIO_STRING);

        numero_miles = agregarSeparadorMiles(numero_string);

        Mostrar_resultado_ejercicio5(numero_miles, numero_string);

        printf("\n Desea volver a realizar el ejercicio? (*Ingrese '0' para salir del sistema; *Ingrese '1' para volver a realizarlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(numero_miles);
    }
    while(bandera != 0);

}
