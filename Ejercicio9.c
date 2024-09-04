#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ejercicio9(){


    int bandera, Numero;
    bool Resultado;

    do{

        printf("\t\t\t Bienvenido al programa '¿ES DIVISIBLE POR '7' EL NUMERO?'!!\n\n");

        printf(" Ingresar el numero para ver si es divisible por 7 (Numero Entero): ");
        Numero = Ingreso_Entero_Positivo_Negativo();

        if(Numero >= 0){

            Resultado = divisiblePor7(Numero);
        }

        else{

            Resultado = divisiblePor7(-Numero);
        }


        Mostrar_resultado_ejercicio9(Resultado, Numero);

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
