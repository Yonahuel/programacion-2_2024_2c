#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ejercicio7(){


    int bandera;
    char Cadena_string[TAMANIO_ONDA_DIGITAL];


    do{
        Cadena_string[0] = '\0';
        char *Cadena_Digital;

        printf("\t\t\t Bienvenido al programa 'ESBOZO DE UNA ONDA DIGITAL'!!\n\n");

        printf(" Ingrese la ONDA DIGITAL a representar con altos y bajos (maximo 50 caracteres): ");
        Validar_Cadena_String_ejercicio7(Cadena_string);

        Cadena_Digital = ondaDigital(Cadena_string);

        Mostrar_resultado_ejercicio7(Cadena_Digital, Cadena_string);

        printf("\n Desea volver a realizar el ejercicio? (*Ingrese '0' para salir del sistema; *Ingrese '1' para volver a realizarlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        //free(Cadena_Digital); por alguna extraña razon no anda con el free(Cadena_Digital).
    }
    while(bandera != 0);

    printf("\t\t Hasta la proxima!\n");
    system("pause");
}
