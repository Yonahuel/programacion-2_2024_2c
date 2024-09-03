#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ejercicio6(){


    int bandera, nivel_reunion;


    do{

        char *Cadena_mafia;

        printf("\t\t\t Bienvenido al programa 'REFUERZOS DE LA MAFIA CHINA'!!\n\n");
        printf(" Ingrese el 'NIVEL DE LA REUNION' de la mafia china (Numero entero positivo < 51): "); nivel_reunion = Ingresar_Entero_Positivo();

        while(nivel_reunion > 50){

            printf("\n Inrgeso Excesivo! Debe ingresar un numero entre [0; 50]!\n");
            printf(" Ingrese el 'NIVEL DE LA REUNION' de la mafia china (Numero entero positivo < 51): "); nivel_reunion = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        Cadena_mafia = SitiodelaReunion(nivel_reunion);

        Mostrar_resultado_ejercicio6(Cadena_mafia, nivel_reunion);

        printf("\n Desea volver a realizar el ejercicio? (*Ingrese '0' para salir del sistema; *Ingrese '1' para volver a realizarlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(Cadena_mafia);
    }
    while(bandera != 0);

    printf("\t\t Hasta la proxima!\n");
    system("pause");

}
