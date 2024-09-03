#include <stdio.h>
#include <stdlib.h>
#include "Ejercicios.h"
#include "validaciones.h"

int main(){

    int bandera;
    do{

        printf("\t\t\t Menu General!\n\n\n");

        printf(" Ingrese '1' para realizar el ejercicio 1 del practico!\n");
        printf(" Ingrese '2' para realizar el ejercicio 2 del practico!\n");
        printf(" Ingrese '3' para realizar el ejercicio 3 del practico!\n");
        printf(" Ingrese '4' para realizar el ejercicio 4 del practico!\n");
        printf(" Ingrese '5' para realizar el ejercicio 5 del practico!\n");
        printf(" Ingrese '6' para realizar el ejercicio 6 del practico!\n");
        printf(" Ingrese '7' para realizar el ejercicio 7 del practico!\n");
        printf(" Ingrese '8' para realizar el ejercicio 8 del practico!\n");
        printf(" Ingrese '9' para realizar el ejercicio 9 del practico!\n");
        printf(" Ingrese '10' para realizar el ejercicio 10 del practico!\n");
        printf(" Ingrese '0' para realizar el ejercicio 1 del practico!\n\n");
        printf(" Ingrese la opcion: ");

        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 10)){

            printf(" Ingreso Invalido! debe ingresar una opcion entre[0; 10]!!\n");
            printf(" Ingrese la opcion: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }


        switch(bandera){

            case 0:
                break;
            case 1:
                ejercicio1();
                break;
            case 2:
                ejercicio2();
                break;
            case 3:
                ejercicio3();
                break;
            case 4:
                ejercicio4();
                break;
            case 5:
                ejercicio5();
                break;
            case 6:
                ejercicio6();
                break;
            case 7:
                ejercicio7();
                break;
            case 8:
                ejercicio8();
                break;
            case 9:
                ejercicio9();
                break;
            case 10:
                ejercicio10();
                break;
        }

    }
    while(bandera != 0);

    printf(" Hasta la proxima!!!\n");
    system("Pause");
    return 0;
}
