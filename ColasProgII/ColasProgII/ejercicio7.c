#include "tipo_elemento.h"
#include "validaciones.h"
#include "funciones.h"

/*
Para ejecutar este tp en codeblocks hay que ir deshabilitando los ejercicios que no se usan y habilitar solo el que se va a usar y antes de ejecutarlo hay que hacer un rebuild.

*/
int main(){

    int bandera;

    Cola C1, C2, C3;

    do{

        C1 = c_crear();
        C2 = c_crear();
        C3 = c_crear();

        do{


            printf("\t\t\t MENU EJERCICIO 7 'TP COLAS': \n\n");
            printf(" 1.     Agregar elementos a una de las COLAS (MANUALMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 2.     Agregar elementos a una de las COLAS (ALEATORIAMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 3.     Modelar la Atencion de los clientes que hay en las 3 COLAS.\n");
            printf(" 4.     Mostrar las COLAS.\n");
            printf(" 0.     Salir del MENU.\n\n");
            printf(" Ingrese el numero de la accion a realizar: ");

            bandera = Ingresar_Entero_Positivo();
            while(!Validar_Intervalo_Enteros(bandera, 0, 4)){

                printf(" Ingreso Invalido! Debe ingresar una opcion entre [0; 4]!\n");
                printf(" Ingrese el numero de la accion a realizar: ");
                bandera = Ingresar_Entero_Positivo();
                fflush(stdin);
            }


            switch(bandera){

                case 0:

                    break;

                case 1:

                    printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para la COLA 1; *Ingrese ' 2 ' para la COLA 2; *Ingrese ' 3 ' para la COLA 3): ");
                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 3)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [1; 3]!\n");
                        printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para la COLA 1; *Ingrese ' 2 ' para la COLA 2; *Ingrese ' 3 ' para la COLA 3): ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        c_ej7_Carga_CM(C1);

                        c_mostrar(C1);
                    }

                    else if(bandera == 2){

                        c_ej7_Carga_CM(C2);

                        c_mostrar(C2);
                    }

                    else{

                        c_ej7_Carga_CM(C3);

                        c_mostrar(C3);
                    }

                    break;

                case 2:

                    printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para la COLA 1; *Ingrese ' 2 ' para la COLA 2; *Ingrese ' 3 ' para la COLA 3): ");
                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 3)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [1; 3]!\n");
                        printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para la COLA 1; *Ingrese ' 2 ' para la COLA 2; *Ingrese ' 3 ' para la COLA 3): ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        c_ej7_Carga_CA(C1);

                        c_mostrar(C1);
                    }

                    else if(bandera == 2){

                        c_ej7_Carga_CA(C2);

                        c_mostrar(C2);
                    }

                    else{

                        c_ej7_Carga_CA(C3);

                        c_mostrar(C3);
                    }

                    break;

                case 3:

                    Simulacion(C1, C2, C3);

                    break;

                case 4:

                    printf(" COLA 1: \n"); c_mostrar(C1); printf("\n");
                    printf(" COLA 2: \n"); c_mostrar(C2); printf("\n");
                    printf(" COLA 3: \n"); c_mostrar(C3); printf("\n");

                    break;
            }

            system("pause");
            system("cls");

        }
        while(bandera != 0);

        printf(" Desea volver a realizar el ejercicio con COLAS DIFERENTES? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea volver a realizar el ejercicio con COLAS DIFERENTES? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(C1);
        free(C2);
        free(C3);

    }
    while(bandera != 0);

    printf(" Hasta la proxima!\n");
    system("pause");

    return 0;
}
