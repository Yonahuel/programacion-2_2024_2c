#include "pilas.h"
#include "funciones.h"
#include "tipo_elemento.h"
#include "validaciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){

    int bandera, clave, posicion1, posicion2, longuitud, base, numero;
    char *resultado;
    bool esta, repetido, iguales;
    Pila Original, Copia, Pila1, Pila2, Invertida, Resultado, P1, P2;

    do{

        printf("\t\t\t MENU DEL SISTEMA 'TP PILAS': \n\n");
        printf(" 1.     Realizar el ejercicio 2.\n");
        printf(" 2.     Realizar el ejercicio 3.\n");
        printf(" 3.     Realizar el ejercicio 4.\n");
        printf(" 4.     Realizar el ejercicio 5.\n");
        printf(" 5.     Realizar el ejercicio 6.\n");
        printf(" 6.     Realizar el ejercicio 7.\n");
        printf(" 7.     Realizar el ejercicio 8.\n");
        printf(" 0.     Salir del SISTEMA.\n\n");
        printf(" Ingrese el numero de la accion a realizar: ");

        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 7)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '7'!\n");
            printf(" Ingrese el numero de la accion a realizar: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }


        switch(bandera){

            case 0:

                printf("Saldremos del sistema! ");
                break;

            case 1:

                Original = p_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 2 'TP PILAS': \n\n");
                    printf(" 1.     Agregar elementos a la PILA (MANUALMENTE).\n");
                    printf(" 2.     Agregar elementos a la PILA (ALEATORIAMENTE).\n");
                    printf(" 3.     Buscar un elemento en la PILA.\n");
                    printf(" 4.     Colocar un nuevo elemento en la PILA dada una posicion.\n");
                    printf(" 5.     Eliminar de la PILA un elemento (Su primer ocurrencia en la PILA).\n");
                    printf(" 6.     Intercambiar de la PILA 2 elementos dadas sus POSICIONES en la PILA.\n");
                    printf(" 7.     Copiar el contenido de la PILA en otra.\n");
                    printf(" 8.     Longuitud de la PILA actualmente.\n");
                    printf(" 9.     Mostrar la PILA actual.\n");
                    printf(" 0.     VOLVER AL MENU DEL SISTEMA.\n\n");
                    printf(" Ingrese el numero de la accion a realizar: ");

                    bandera = Ingresar_Entero_Positivo();
                    while(!Validar_Intervalo_Enteros(bandera, 0, 9)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [0; 9]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            printf(" Volveremos al menu del sistema!\n");

                            break;

                        case 1:

                            Cargar_Pilas_Manualmente(Original);

                            p_mostrar(Original);

                            break;

                        case 2:

                            Cargar_Pilas_Aleatoriamente(Original);

                            p_mostrar(Original);

                            break;

                        case 3:

                            p_mostrar(Original);
                            printf("\n\n");

                            printf(" Ingrese la clave del elemento a buscar (Numero entero): ");
                            clave = Ingreso_Entero_Positivo_Negativo();

                            esta = p_ej2_existeclave(Original, clave);

                            printf(" Esta el elemento?: %s\n", esta ? "True" : "False");

                            break;

                        case 4:

                            p_mostrar(Original);
                            printf("\n\n");

                            printf(" Ingrese la posicion ordinal de la PILA en la que desea colocar el elemento (Numero entero [1; 10]): ");
                            posicion1 = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(posicion1, 1, 10)){

                                printf(" Ingreso Invalido! Debe ingresar una posicion ordinal entre [1; 10]!\n");
                                printf(" Ingrese la posicion ordinal de la PILA en la que desea colocar el elemento (Numero entero [1; 10]): ");
                                posicion1 = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            Original = p_ej2_colocarelemento(Original, posicion1);

                            p_mostrar(Original);

                            break;

                        case 5:

                            p_mostrar(Original);
                            printf("\n\n");

                            printf(" Ingrese el elemento del cual eliminaremos su primer ocurrencia de la PILA: ");
                            clave = Ingreso_Entero_Positivo_Negativo();

                            Original = p_ej2_eliminarclave(Original, clave);

                            p_mostrar(Original);

                            break;

                        case 6:

                            p_mostrar(Original);
                            printf("\n\n");

                            printf(" Ingrese la posicion ordinal del elemento 1 de la PILA que intercambiaremos (Numero entero [1; 10]): ");
                            posicion1 = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(posicion1, 1, 10)){

                                printf(" Ingreso Invalido! Debe ingresar una posicion ordinal entre [1; 10]!\n");
                                printf(" Ingrese la posicion ordinal de la PILA en la que desea colocar el elemento (Numero entero [1; 10]): ");
                                posicion1 = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            do{

                                repetido = false;

                                p_mostrar(Original);
                                printf("\n\n");

                                printf(" Ingrese la posicion ordinal del elemento 2 de la PILA que intercambiaremos (Numero entero [1; 10]): ");
                                posicion2 = Ingresar_Entero_Positivo();

                                while(!Validar_Intervalo_Enteros(posicion2, 1, 10)){

                                    printf(" Ingreso Invalido! Debe ingresar una posicion ordinal entre [1; 10]!\n");
                                    printf(" Ingrese la posicion ordinal de la PILA en la que desea colocar el elemento (Numero entero [1; 10]): ");
                                    posicion1 = Ingresar_Entero_Positivo();
                                    fflush(stdin);
                                }

                                if(posicion1 == posicion2){

                                    printf(" Ingreso Invalido! no puede ingresar la misma posicion ordinal del elemento 1!\n");

                                    repetido = true;
                                }
                            }
                            while(repetido);

                            Original = p_ej2_intercambiarposiciones(Original, posicion1, posicion2);

                            p_mostrar(Original);

                            break;

                        case 7:

                            Copia = p_ej2_duplicar(Original);

                            printf(" PILA Original: "); p_mostrar(Original);
                            printf(" PILA Copia: "); p_mostrar(Copia);

                            free(Copia);

                            break;

                        case 8:

                            longuitud = p_ej2_cantidadelementos(Original);

                            printf(" La PILA posee %d elementos!\n", longuitud);

                            break;

                        case 9:

                            p_mostrar(Original);
                            break;
                    }

                    system("pause");
                    system("cls");

                }
                while(bandera != 0);

                free(Original);
                break;

            case 2:

                Pila1 = p_crear();
                Pila2 = p_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 3 'TP PILAS': \n\n");
                    printf(" 1.     Agregar elementos a una PILA (MANUALMENTE).\n");
                    printf(" 2.     Agregar elementos a una PILA (ALEATORIAMENTE).\n");
                    printf(" 3.     Verificar si las 2 PILAS son iguales tanto en posicion como en contenido.\n");
                    printf(" 4.     Mostrar la PILA actual.\n");
                    printf(" 0.     VOLVER AL MENU PRINCIPAL.\n\n");
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

                            printf(" Volveremos al menu del sistema!\n");

                            break;

                        case 1:

                            printf(" A que PILA desea cargarle elementos? (*Ingrese '1' para cargarle a PILA1; *Ingrese '2' para cargarle a PILA2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la PILA a agregar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Pilas_Manualmente(Pila1);
                                printf(" PILA 1: ");
                                p_mostrar(Pila1);
                            }

                            else{

                                Cargar_Pilas_Manualmente(Pila2);
                                printf(" PILA 2: ");
                                p_mostrar(Pila2);
                            }

                            break;

                        case 2:

                            printf(" A que PILA desea cargarle elementos ALEATORIAMENTE? (*Ingrese '1' para cargarle a PILA1; *Ingrese '2' para cargarle a PILA2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la PILA a agregar elementos ALEATORIAMENTE: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Pilas_Aleatoriamente(Pila1);
                                printf(" PILA 1: ");
                                p_mostrar(Pila1);
                            }

                            else{

                                Cargar_Pilas_Aleatoriamente(Pila2);
                                printf(" PILA 2: ");
                                p_mostrar(Pila2);
                            }

                            break;

                        case 3:

                            iguales = p_ej3_iguales(Pila1, Pila2);

                            printf(" Son iguales las PILAS tanto en contenido como en posicion?: %s\n", iguales ? "True" : "False");

                            break;

                        case 4:

                            printf(" PILA 1: "); p_mostrar(Pila1);
                            printf(" PILA 2: "); p_mostrar(Pila2);
                            break;
                    }

                    system("pause");
                    system("cls");

                }
                while(bandera != 0);

                free(Pila1);
                free(Pila2);

                break;

            case 3:

                do{

                    printf("\t\t\t MENU EJERCICIO 4 'TP PILAS': \n\n");
                    printf(" 1.     Pasar un numero de base 10 a cualquier otra base entre [2 ; 16]!\n");
                    printf(" 0.     Salir del Menu!\n\n");
                    printf(" Ingrese el numero de la accion a realizar: ");

                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                        printf(" Ingreso Invalido! debe ingresar un numero entre [0 ; 1]!\n");
                        printf(" Ingrese el numero de la accion a realizar [0 'salir' ; 1 'pasar un numero de base 10 a otra base']: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        printf(" Ingrese el numero de base 10 (numero entero entre[-1023; 1023]): ");
                        numero = Ingreso_Entero_Positivo_Negativo();

                        while(!Validar_Intervalo_Enteros(numero, -1023, 1023)){

                            printf(" Intervalo Invalido! Debe ingresar un numero de base 10 entre [-1023; 1023]!\n");
                            printf(" Ingrese el numero de base 10 (numero entero entre[-1023; 1023]): ");
                            numero = Ingreso_Entero_Positivo_Negativo();
                            fflush(stdin);
                        }

                        printf(" A que base pasaremos al numero %d? (numero entre [2; 16]): ", numero);
                        base = Ingresar_Entero_Positivo();

                        while(!Validar_Intervalo_Enteros(base, 2, 16)){

                            printf(" Ingreso Invalido! debe ingresar una base entre [2 ; 16]!\n");
                            printf(" A que base pasaremos al numero %d? (numero entre [2; 16]): ", numero);
                            base = Ingresar_Entero_Positivo();
                            fflush(stdin);
                        }

                        resultado = p_ej4_cambiarbase(numero, base);

                        printf(" El resultado de pasar al numero '%d' a la base '%d' es: '%s'!\n", numero, base, resultado);

                        system("pause");
                        system("cls");

                        free(resultado);
                    }

                    else{

                        printf(" VOLVEREMOS AL MENU PRINCIPAL\n");
                    }

                    system("pause");
                    system("cls");
                }
                while(bandera != 0);

                break;

            case 4:

                Original = p_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 5 'TP PILAS': \n\n");
                    printf(" 1.     Agregar elementos a la PILA (MANUALMENTE).\n");
                    printf(" 2.     Agregar elementos a la PILA (ALEATORIAMENTE).\n");
                    printf(" 3.     Copiar la PILA pero INVERTIDA.\n");
                    printf(" 4.     Mostrar la PILA actual.\n");
                    printf(" 0.     VOLVER AL MENU DEL SISTEMA.\n\n");
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

                            printf(" VOLVEREMOS AL MENU DEL SISTEMA!\n");

                            break;

                        case 1:

                            Cargar_Pilas_Manualmente(Original);
                            printf(" PILA: ");
                            p_mostrar(Original);

                            break;

                        case 2:

                            Cargar_Pilas_Aleatoriamente(Original);
                            printf(" PILA: ");
                            p_mostrar(Original);

                            break;

                        case 3:

                            Invertida = p_ej5_invertir(Original);

                            printf(" PILA INVERTIDA: "); p_mostrar(Invertida);
                            printf(" PILA ORIGINAL: "); p_mostrar(Original);

                            free(Original);

                            Original = Invertida;

                            break;

                        case 4:

                            printf(" PILA: "); p_mostrar(Original);

                            break;
                    }

                    system("pause");
                    system("cls");

                }
                while(bandera != 0);

                free(Original);

                break;

            case 5:

                Original = p_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 6 'TP PILAS': \n\n");
                    printf(" 1.     Agregar elementos a la PILA (MANUALMENTE).\n");
                    printf(" 2.     Agregar elementos a la PILA (ALEATORIAMENTE).\n");
                    printf(" 3.     Obtener la PILA sin X elemento (ITERATIVO).\n");
                    printf(" 4.     Obtener la PILA sin X elemento (RECURSIVO).\n");
                    printf(" 5.     Mostrar la PILA actual.\n");
                    printf(" 0.     VOLVER AL MENU DEL SISTEMA.\n\n");
                    printf(" Ingrese el numero de la accion a realizar: ");

                    bandera = Ingresar_Entero_Positivo();
                    while(!Validar_Intervalo_Enteros(bandera, 0, 5)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [0; 5]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            printf(" VOLVEREMOS AL MENU DEL SISTEMA!\n");

                            break;

                        case 1:

                            Cargar_Pilas_Manualmente(Original);
                            printf(" PILA: ");
                            p_mostrar(Original);

                            break;

                        case 2:

                            Cargar_Pilas_Aleatoriamente(Original);
                            printf(" PILA: ");
                            p_mostrar(Original);

                            break;

                        case 3:

                            p_mostrar(Original);

                            printf(" Que elemento desea eliminar de la PILA?: ");
                            clave = Ingreso_Entero_Positivo_Negativo();

                            Resultado = p_ej6_eliminarclave_iterativo(Original, clave);

                            printf(" PILA RESULTADO: "); p_mostrar(Resultado);
                            printf(" PILA ORIGINAL: "); p_mostrar(Original);

                            free(Original);

                            Original = Resultado;

                            break;

                        case 4:

                            p_mostrar(Original);

                            printf(" Que elemento desea eliminar de la PILA?: ");
                            clave = Ingreso_Entero_Positivo_Negativo();

                            Resultado = p_ej6_eliminarclave(Original, clave);

                            printf(" PILA RESULTADO: "); p_mostrar(Resultado);
                            printf(" PILA ORIGINAL: "); p_mostrar(Original);

                            free(Original);

                            Original = Resultado;

                            break;


                        case 5:

                            printf(" PILA: "); p_mostrar(Original);

                            break;
                    }

                    system("pause");
                    system("cls");

                }
                while(bandera != 0);

                free(Original);

                break;

            case 6:

                P1 = p_crear();
                P2 = p_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 7 'TP PILAS': \n\n");
                    printf(" 1.     Agregar elementos a una PILA (MANUALMENTE).\n");
                    printf(" 2.     Agregar elementos a una PILA (ALEATORIAMENTE).\n");
                    printf(" 3.     Obtener una nueva PILA con los elementos en comun de P1 y P2.\n");
                    printf(" 4.     Mostrar las PILAS actuales.\n");
                    printf(" 0.     VOLVER AL MENU DEL SISTEMA.\n\n");
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

                            printf(" VOLVEREMOS AL MENU DEL SISTEMA\n");

                            break;

                        case 1:

                            printf(" A que PILA desea cargarle elementos? (*Ingrese '1' para cargarle a PILA1; *Ingrese '2' para cargarle a PILA2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la PILA a agregar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Pilas_Manualmente(P1);
                                printf(" PILA 1: ");
                                p_mostrar(P1);
                            }

                            else{

                                Cargar_Pilas_Manualmente(P2);
                                printf(" PILA 2: ");
                                p_mostrar(P2);
                            }

                            break;

                        case 2:

                            printf(" A que PILA desea cargarle elementos ALEATORIAMENTE? (*Ingrese '1' para cargarle a PILA1; *Ingrese '2' para cargarle a PILA2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la PILA a agregar elementos ALEATORIAMENTE: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Pilas_Aleatoriamente(P1);
                                printf(" PILA 1: ");
                                p_mostrar(P1);
                            }

                            else{

                                Cargar_Pilas_Aleatoriamente(P2);
                                printf(" PILA 2: ");
                                p_mostrar(P2);
                            }

                            break;

                        case 3:

                            Resultado = p_ej7_eliminarclave(P1, P2);

                            printf(" PILA 1: "); p_mostrar(P1);
                            printf(" PILA 2: "); p_mostrar(P2);
                            printf(" Elementos en comun: "); p_mostrar(Resultado);

                            break;

                        case 4:

                            printf(" PILA 1: "); p_mostrar(P1);
                            printf(" PILA 2: "); p_mostrar(P2);

                            break;
                    }

                    system("pause");
                    system("cls");

                    free(Resultado);

                }
                while(bandera != 0);

                free(P1);
                free(P2);

                break;

            case 7:

                Original = p_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 8 'TP PILAS': \n\n");
                    printf(" 1.     Agregar elementos a la PILA (MANUALMENTE).\n");
                    printf(" 2.     Obtener una PILA con todos los elementos junto a la cantidad de veces que aparecen.\n");
                    printf(" 3.     Mostrar la PILA actual.\n");
                    printf(" 0.     VOLVEREMOS AL MENU DEL SISTEMA.\n\n");
                    printf(" Ingrese el numero de la accion a realizar: ");

                    bandera = Ingresar_Entero_Positivo();
                    while(!Validar_Intervalo_Enteros(bandera, 0, 3)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [0; 3]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            printf(" VOLVEREMOS AL MENU PRINCIPAL!\n");

                            break;

                        case 1:

                            Cargar_Pilas_Manualmente(Original);
                            printf(" PILA: ");
                            p_mostrar(Original);

                            break;

                        case 2:

                            Resultado = p_ej8_sacarrepetidos(Original);

                            printf(" PILA ORIGINAL: "); p_mostrar(Original);
                            printf(" PILA REPETICIONES: "); p_mostrar_con_Valor(Resultado);

                            break;


                        case 3:

                            printf(" PILA: "); p_mostrar(Original);

                            break;
                    }

                    system("pause");
                    system("cls");

                    free(Resultado);

                }
                while(bandera != 0);

                free(Original);

                break;
        }

    }
    while(bandera != 0);


    printf(" Hasta la proxima!\n");
    system("pause");

    return 0;
}
