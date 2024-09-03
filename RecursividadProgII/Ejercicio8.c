#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ejercicio8(){


    int bandera, tamconjA, n;

    do{

        int *ConjuntoA;
        struct ListaSubConj *Resultado;
        printf("\t\t\t Bienvenido al programa 'ENCONTRAR TODOS LOS SUBCONJUNTOS'!!\n\n");

        printf(" Ingrese el tamanio que tendra el CONJUNTO A (Entero positivo >= 2): "); tamconjA = Ingresar_Entero_Positivo();

        while(tamconjA < 2){

            printf(" Ingreso Invalido! Debe ingresar un tamanio >= 2!\n");
            printf(" Ingrese el tamanio que tendra el CONJUNTO A: "); tamconjA = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        ConjuntoA = Cargar_ConjuntoA(tamconjA);

        printf(" Ingrese el Numero 'N' que deben sumar los elementos de cada Subconjunto (Entero positivo): ");
        n = Ingresar_Entero_Positivo();

        Resultado = subconjuntosQueSumanN(ConjuntoA, tamconjA, n);

        Mostrar_resultado_ejercicio8(*Resultado, ConjuntoA, tamconjA, n);

        printf("\n Desea volver a realizar el ejercicio? (*Ingrese '0' para salir del sistema; *Ingrese '1' para volver a realizarlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(Resultado);
        free(ConjuntoA);
    }
    while(bandera != 0);

    printf("\t\t Hasta la proxima!\n");
    system("pause");

}
