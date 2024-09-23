
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "funciones.h"
#include "tipo_elemento.h"
#include "validaciones.h"

int main(){

    float promedio_L1, promedio_L2;
    Lista L1, L2;
    Lista Diferencia_L1, Diferencia_L2;
    Lista Elementos_Comunes;
    struct valores *Minimo_1;
    struct valores *Minimo_2;
    struct valores *Maximo_1;
    struct valores *Maximo_2;
    Lista Multiplo_1;
    Lista Multiplo_2;
    bool multiplo;
    bool escalar;
    bool mismo_tamanio;
    int resultado;
    int Grado_del_Polinomio;
    int Inicio_Rango_Valores = 0, Final_Rango_Valores = 0;
    float Cada_Cuanto = 0.0;
    float X = 0.0;
    float Y = 0.0;
    bool sublista;
    Lista Resultado_FX;
    Lista Intervalo_Completo;
    Lista Polinomio;
    int bandera;


    do{

        printf("\t\t\t  MENU DEL SISTEMA!\n\n");
        printf(" 1.      Realizar el ejercicio ' 2 ' TP LISTAS\n");
        printf(" 2.      Realizar el ejercicio ' 3 ' TP LISTAS\n");
        printf(" 3.      Realizar el ejercicio ' 4 ' TP LISTAS\n");
        printf(" 4.      Realizar el ejercicio ' 5 ' TP LISTAS\n");
        printf(" 5.      Realizar el ejercicio ' 6 ' TP LISTAS\n");
        printf(" 0.      Salir del MENU DEL SISTEMA\n\n");
        printf(" Ingrese el numero de la accion a realizar: ");

        bandera = Ingresar_Entero_Positivo();
        while(!Validar_Intervalo_Enteros(bandera, 0, 5)){

            printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '5'!\n");
            printf(" Ingrese el numero de la accion a realizar: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }


        switch(bandera){

            case 0:

                break;

            case 1:

                L1 = l_crear();
                L2 = l_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 2: \n\n");
                    printf(" 1. Agregar elementos a una LISTA (MANUALMENTE).\n");
                    printf(" 2. Eliminar elementos de una LISTA dada una posicion de la misma.\n");
                    printf(" 3. Retornar una LISTA con los valores de L1 que NO ESTEN en L2.\n");
                    printf(" 4. Retornar una LISTA con los valores de L2 que NO ESTEN en L1.\n");
                    printf(" 5. Retornar una LISTA con los ELEMENTOS EN COMUN que tengan ambas LISTAS.\n");
                    printf(" 6. Retornar el promedio de ambas LISTAS.\n");
                    printf(" 7. Retornar el VALOR MAXIMO que posee cada LISTA junto a su POSICION ORDINAL.\n");
                    printf(" 8. Retornar el VALOR MINIMO que posee cada LISTA junto a su POSICION ORDINAL.\n");
                    printf(" 9. Retornar las LISTAS multiplicadas por un NUMERO N que usted desee.\n");
                    printf(" 10. Cargar una LISTA con numeros ALEATORIOS y sin repetirse.\n");
                    printf(" 11. Mostrar ambas LISTAS.\n");
                    printf(" 0. Salir del ejercicio 2.\n\n");
                    printf(" Ingrese el numero de la accion que desea realizar: ");

                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 0, 11)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 11]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            break;

                        case 1:

                            printf(" A que LISTA desea cargarle elementos? (*Ingrese '0' para cargarle a L1; *Ingrese '1' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 1]!\n");
                                printf(" Ingrese el numero de la LISTA a agregar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 0){

                                Cargar_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                                bandera = -1;
                            }

                            else{

                                Cargar_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 2:

                            printf(" A que LISTA desea eliminarle elementos? (*Ingrese '0' para eliminarle a L1; *Ingrese '1' para eliminarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 1]!\n");
                                printf(" Ingrese el numero de la LISTA eliminar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 0){

                                Eliminar_Elementos_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                                bandera = -1;
                            }

                            else{

                                Eliminar_Elementos_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 3:

                            Diferencia_L1 = Valores_Diferentes(L1, L2);

                            if(Diferencia_L1 == NULL){

                                printf(" No hay datos!\n");
                            }

                            else{

                                printf(" Resultado: "); l_mostrar(Diferencia_L1);
                            }

                            system("pause");
                            system("cls");

                            free(Diferencia_L1);

                            break;

                        case 4:

                            Diferencia_L2 = Valores_Diferentes(L2, L1);

                            if(Diferencia_L2 == NULL){

                                printf(" No hay datos!\n");
                            }

                            else{

                                printf(" Resultado: "); l_mostrar(Diferencia_L2);
                            }

                            system("pause");
                            system("cls");

                            free(Diferencia_L2);

                            break;

                        case 5:

                            Elementos_Comunes = Valores_Comunes(L1, L2);

                            if(Elementos_Comunes == NULL){

                                printf(" No hay datos!\n");
                            }

                            else{

                                printf(" Resultado: "); l_mostrar(Elementos_Comunes);
                            }

                            system("pause");
                            system("cls");

                            free(Elementos_Comunes);

                            break;

                        case 6:

                            promedio_L1 = Promedio_Listas(L1);
                            promedio_L2 = Promedio_Listas(L2);

                            printf(" El promedio de la LISTA 1 es: %f\n", promedio_L1);
                            printf(" El promedio de la LISTA 2 es: %f\n", promedio_L2);

                            system("pause");
                            system("cls");

                            break;

                        case 7:

                            Maximo_1 = Valor_Maximo(L1);
                            Maximo_2 = Valor_Maximo(L2);

                            if(Maximo_1 == NULL){

                                printf(" No hay datos de la LISTA 1!\n");
                            }

                            else{

                                printf(" El valor Maximo de la LISTA 1 es %d que se encuentra en la posicion %d!.\n", Maximo_1->Elemento, Maximo_1->posicion_Ordinal);
                            }

                            if(Maximo_2 == NULL){

                                printf(" No hay datos de la LISTA 2!\n");
                            }

                            else{

                                printf(" El valor Maximo de la LISTA 2 es %d que se encuentra en la posicion %d!.\n", Maximo_2->Elemento, Maximo_2->posicion_Ordinal);
                            }

                            system("pause");
                            system("cls");

                            free(Maximo_1);
                            free(Maximo_2);

                            break;

                        case 8:

                            Minimo_1 = Valor_Minimo(L1);
                            Minimo_2 = Valor_Minimo(L2);

                            if(Minimo_1 == NULL){

                                printf(" No hay datos de la LISTA 1!\n");
                            }

                            else{

                                printf(" El valor Minimo de la LISTA 1 es %d que se encuentra en la posicion %d!.\n", Minimo_1->Elemento, Minimo_1->posicion_Ordinal);
                            }

                            if(Minimo_2 == NULL){

                                printf(" No hay datos de la LISTA 2!\n");
                            }

                            else{

                                printf(" El valor Minimo de la LISTA 2 es %d que se encuentra en la posicion %d!.\n", Minimo_2->Elemento, Minimo_2->posicion_Ordinal);
                            }

                            system("pause");
                            system("cls");

                            free(Minimo_1);
                            free(Minimo_2);

                            break;

                        case 9:

                            Multiplo_1 = Lista_Multiplo(L1);
                            Multiplo_2 = Lista_Multiplo(L2);

                            printf(" Lista 1 Multiplo: "); l_mostrar(Multiplo_1);
                            printf(" Lista 2 Multiplo: "); l_mostrar(Multiplo_2);

                            system("pause");
                            system("cls");

                            free(Multiplo_1);
                            free(Multiplo_2);

                            break;

                        case 10:

                            printf(" Que LISTA desea cargar Aleatoriamente con numeros unicos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a cargar Aleatoriamente: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Aleatorio(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                                bandera = -1;
                            }

                            else{

                                Cargar_Aleatorio(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 11:

                            printf(" Lista 1: "); l_mostrar(L1);
                            printf(" Lista 2: "); l_mostrar(L2);

                            system("pause");
                            system("cls");

                            break;
                    }
                }
                while(bandera != 0);

                free(L1);
                free(L2);

                break;

            case 2:

                L1 = l_crear();
                L2 = l_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 3 'TP LISTAS': \n\n");
                    printf(" 1. Agregar elementos a una LISTA (MANUALMENTE).\n");
                    printf(" 2. Cargar una LISTA con numeros ALEATORIOS y sin repetirse.\n");
                    printf(" 3. Eliminar elementos de una LISTA, dada una posicion de la misma.\n");
                    printf(" 4. Verificar si L2 es multiplo de L1.\n");
                    printf(" 5. Mostrar ambas LISTAS.\n");
                    printf(" 0. Salir del ejercicio 3.\n\n");
                    printf(" Ingrese el numero de la accion que desea realizar: ");

                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 0, 5)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 5]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            break;

                        case 1:

                            printf(" A que LISTA desea cargarle elementos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a agregar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Cargar_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 2:

                            printf(" Que LISTA desea cargar Aleatoriamente con numeros unicos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a cargar: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Aleatorio(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Cargar_Aleatorio(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 3:

                            printf(" A que LISTA desea eliminarle elementos? (*Ingrese '1' para eliminarle a L1; *Ingrese '2' para eliminarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA para eliminar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Eliminar_Elementos_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Eliminar_Elementos_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 4:

                            if(l_es_vacia(L1) || l_es_vacia(L2)){

                                printf(" No se puede realizar esta accion, ya que una o ambas Lista no tiene elementos!\n");
                                multiplo = false;
                                escalar = false;
                            }

                            else{

                                mismo_tamanio = Verificar_Igualdad_Tamanio_Listas(L1, L2);

                                if(!mismo_tamanio){

                                    printf(" No se puede realizar esta accion, las listas no tienen el mismo tamanio!\n");
                                    multiplo = false;
                                    escalar = false;
                                }

                                else{

                                    multiplo = Verificar_Multiplo(L1, L2);

                                    if(multiplo){

                                        escalar = Verificar_Escalar(L1, L2);
                                    }

                                    else{

                                        escalar = false;
                                    }

                                    printf(" Es mutiplo?: %s\n", multiplo ? "true" : "false");
                                    printf(" Es escalar?: %s\n", escalar ? "true" : "false");
                                }
                            }

                            system("pause");
                            system("cls");

                            break;

                        case 5:

                            printf(" Lista 1: "); l_mostrar(L1);
                            printf(" Lista 2: "); l_mostrar(L2);

                            system("pause");
                            system("cls");

                            break;
                    }
                }
                while(bandera != 0);

                free(L1);
                free(L2);

                break;

            case 3:

                L1 = l_crear();
                L2 = l_crear();

                do{
                    printf("\t\t\t MENU EJERCICIO 4 'TP LISTAS': \n\n");
                    printf(" 1. Agregar elementos a una LISTA (MANUALMENTE).\n");
                    printf(" 2. Cargar una LISTA con numeros ALEATORIOS y sin repetirse.\n");
                    printf(" 3. Eliminar elementos de una LISTA, dada una posicion de la misma.\n");
                    printf(" 4. Verificar si L1 es mayor, igual o menor a L2.\n");
                    printf(" 5. Mostrar ambas LISTAS.\n");
                    printf(" 0. Salir del ejercicio 4..\n\n");
                    printf(" Ingrese el numero de la accion que desea realizar: ");

                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 0, 5)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 5]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            break;

                        case 1:

                            printf(" A que LISTA desea cargarle elementos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a agregar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Cargar_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 2:

                            printf(" Que LISTA desea cargar Aleatoriamente con numeros unicos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a cargar: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Aleatorio(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Cargar_Aleatorio(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 3:

                            printf(" A que LISTA desea eliminarle elementos? (*Ingrese '1' para eliminarle a L1; *Ingrese '2' para eliminarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA para eliminar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Eliminar_Elementos_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Eliminar_Elementos_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 4:

                            if(l_es_vacia(L1) || l_es_vacia(L2)){

                                printf(" No se puede realizar esta accion, ya que una o ambas Lista no tiene elementos!\n");
                            }

                            else{

                                mismo_tamanio = Verificar_Igualdad_Tamanio_Listas(L1, L2);

                                if(!mismo_tamanio){

                                    printf(" No se puede realizar esta accion, las listas no tienen el mismo tamanio!\n");
                                }

                                else{

                                    resultado = Comparar_Listas(L1, L2);
                                }
                            }

                            system("pause");
                            system("cls");

                            break;

                        case 5:

                            printf(" Lista 1: "); l_mostrar(L1);
                            printf(" Lista 2: "); l_mostrar(L2);

                            system("pause");
                            system("cls");

                            break;
                    }
                }
                while(bandera != 0);

                free(L1);
                free(L2);

                break;

            case 4:

                Resultado_FX = l_crear();
                Intervalo_Completo = l_crear();

                printf("\t\t\t\t ATENCION!!!!!\n\n");
                printf(" A continuacion debera ingresar el 'GRADO DEL POLINOMIO'. Si ingresa '0', se vera asi: f(x) = C --> (C es un numero cualquiera);");
                printf(" Si ingresa un '1', se vera asi: f(x) = C.X + C ; Si ingresa un '2', se vera asi: f(x) = C.X^2 + C.X + C;... Y asi sucesivamente!\n\n");
                printf(" Cual es el 'GRADO DEL POLINOMIO'? (Numero entero positivo entre [0; 10]): ");

                Grado_del_Polinomio = Ingresar_Entero_Positivo();

                while(!Validar_Intervalo_Enteros(Grado_del_Polinomio, 0, 10)){

                    printf(" Ingreso Invalido! debe ingresar un GRADO entre [0; 10]!\n");
                    printf(" Cual es el 'GRADO DEL POLINOMIO'? (Numero entero positivo entre [0; 10]): ");

                    Grado_del_Polinomio = Ingresar_Entero_Positivo();
                    fflush(stdin);
                }

                printf(" Procederemos a cargar los COEFICIENTES DEL POLINOMIO!\n");

                Polinomio = Cargar_Polinomio(Grado_del_Polinomio);

                printf(" Calcularemos el valor de F(X) para el polinomio en un punto dado! Ingrese el valor que tendra 'X' (Valor entre [-10.0; 10.0] ): ");
                X = Ingreso_Decimal_Positivo_Negativo();

                while(!Validar_Intervalo_Decimal(X, -10.0, 10.0)){

                    printf(" Ingreso Invalido! debe ingresar un 'X' entre [-10.0; 10.0] !\n");
                    printf(" Cual es el 'X'? (Numero entero entre [-10.0; 10.0] ): ");

                    X = Ingreso_Decimal_Positivo_Negativo();
                    fflush(stdin);
                }

                Y = Resultado_calcular_fx(Polinomio, Grado_del_Polinomio, X);

                printf(" El Resultado de F(x) cuando X es %.2f es: %.2f\n", X, Y);
                system("pause");
                system("cls");

                printf(" Procederemos a cargar un intervalo para calcular el valor de F(x) para cada punto de X en el!\n");
                printf(" Ingrese el inicio del intervalo (valor entero de 'X' mas a la izquierda en el plano): ");
                Inicio_Rango_Valores = Ingreso_Entero_Positivo_Negativo();

                printf(" Ingrese el final del intervalo (valor entero de 'X' mas a la derecha en el plano): ");
                Final_Rango_Valores = Ingreso_Entero_Positivo_Negativo();

                while(Inicio_Rango_Valores > Final_Rango_Valores){

                    printf("\n Ingreso Invalido! el valor del FINAL DEL INTERVALO no puede ser menor a %d!\n", Inicio_Rango_Valores);
                    printf(" Ingrese el final del intervalo (valor entero de 'X' mas a la derecha en el plano): ");
                    Final_Rango_Valores = Ingreso_Entero_Positivo_Negativo();
                    fflush(stdin);
                }

                printf(" Ingrese un valor de intervalo (de a cuanto vamos a calcular la X dentro del intervalo ya dado. Numero decimal positivo entre [0.1; 1.0]): ");
                Cada_Cuanto = Ingresar_Decimal_Positivo();

                while(!Validar_Intervalo_Decimal(Cada_Cuanto, 0.1, 1.0)){

                    printf("\n Ingreso Invalido! el valor del INTERVALO es coprrecto!\n");
                    printf(" Ingrese un valor de intervalo (De a cuanto vamos a calcular la X dentro del intervalo ya dado. Numero decimal positivo entre [0.1; 1.0]): ");
                    Cada_Cuanto = Ingresar_Decimal_Positivo();
                    fflush(stdin);
                }

                Cargar_Intervalo_Completo(Intervalo_Completo, Inicio_Rango_Valores, Final_Rango_Valores, Cada_Cuanto);

                Calcular_Intervalo_fx(Polinomio, Intervalo_Completo, Resultado_FX, Grado_del_Polinomio);
                mostrar_ejercicio5(Polinomio, Intervalo_Completo, Resultado_FX, Grado_del_Polinomio);

                free(Resultado_FX);
                free(Polinomio);
                free(Intervalo_Completo);

                printf(" Saldremos del ejercicio 5!\n");
                system("pause");
                system("cls");

                break;

            case 5:

                L1 = l_crear();
                L2 = l_crear();

                do{

                    printf("\t\t\t MENU EJERCICIO 6 'TP LISTAS': \n\n");
                    printf(" 1. Agregar elementos a una LISTA (MANUALMENTE).\n");
                    printf(" 2. Cargar una LISTA con numeros ALEATORIOS y sin repetirse.\n");
                    printf(" 3. Eliminar elementos de una LISTA dada una posicion de la misma.\n");
                    printf(" 4. Verificar si L2 es SUBLISTA de L1.\n");
                    printf(" 0. Salir del ejercicio 6.\n\n");
                    printf(" Ingrese el numero de la accion a realizar: ");

                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 0, 4)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 4]!\n");
                        printf(" Ingrese el numero de la accion a realizar: ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    switch(bandera){

                        case 0:

                            break;

                        case 1:

                            printf(" A que LISTA desea cargarle elementos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a agregar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Cargar_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 2:

                            printf(" Que LISTA desea cargar Aleatoriamente con numeros unicos? (*Ingrese '1' para cargarle a L1; *Ingrese '2' para cargarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA a cargar: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Cargar_Aleatorio(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Cargar_Aleatorio(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 3:

                            printf(" A que LISTA desea eliminarle elementos? (*Ingrese '1' para eliminarle a L1; *Ingrese '2' para eliminarle a L2): ");
                            bandera = Ingresar_Entero_Positivo();

                            while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                                printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 2]!\n");
                                printf(" Ingrese el numero de la LISTA para eliminar elementos: ");
                                bandera = Ingresar_Entero_Positivo();
                                fflush(stdin);
                            }

                            if(bandera == 1){

                                Eliminar_Elementos_Lista(L1);
                                l_mostrar(L1);
                                system("pause");
                                system("cls");
                            }

                            else{

                                Eliminar_Elementos_Lista(L2);
                                l_mostrar(L2);
                                system("pause");
                                system("cls");
                            }

                            break;

                        case 4:

                            if(l_es_vacia(L1)){

                                printf(" No se pude realizar esta operacion! L1 esta vacia!\n");
                                continue;
                            }

                            if(l_es_vacia(L2)){

                                printf(" No se puede realizar esta operacion! L2 esta vacia!\n");
                                continue;
                            }

                            sublista = Verificar_Sublista(L1, L2);

                            printf(" L1 es sublista de L2? %s\n", sublista ? "true" : "false");

                            system("pause");
                            system("cls");

                            break;
                    }
                }
                while(bandera != 0);

                free(L1);
                free(L2);

                break;
        }

        printf(" Quiere volver al MENU DEL SISTEMA o salir de la aplicacion? (*Ingrese '1' para volver; *Ingrese '0' salir de la aplicacion): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entre [0; 1]!\n");
            printf(" Quiere volver al MENU DEL SISTEMA o salir de la aplicacion? (*Ingrese '1' para volver; *Ingrese '0' salir de la aplicacion): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

    }
    while(bandera!=0);

    printf("\t Hasta la Proxima!\n");
    system("pause");

    return 0;
}









/*
.         COMPLEJIDAD ALGORITMICA EJERCICIO 4:
.
.   La complejidad algoritmica de la solucion (la funcion "COMPARAR LISTAS") es de O(N), mejor conocido como Complejidad
.   Lineal, ya que la unica entrada de la funcion son las 2 listas, las cuales poseen la misma cantidad de elementos, y
.   se recorren 1 sola vez y al mismo tiempo dentro de un while, que corta su iteracion cuando en las listas ya no hay
.   elementos sin recorrer. Por lo que concluyo que, el tiempo de ejecucion solo depende del tamaño de las listas
.   y como estos tamaños pueden ser variables, es COMPLEJIDAD LINEAL y no CONSTANTE.
.
*/



/*
.
.       COMPLEJIDAD ALGORITMICA EJERCICIO 6:
.
.   La complejidad algoritmica de la solucion (de la funcion "VERIFICAR SUBLISTAS") es de O(N^2), mejor conocido como
.   Complejidad Cuadratica. Esto se debe a que la funcion recibe 2 listas, las cuales tienen tamaño variables y estos
.   pueden ser diferentes, osea tenemos L1 con tamaño N y L2 con tamaño M. Sumandole a esto, que el recorrido de sus
.   contenidos se hacen por separado. El while externo maneja el contenido de L2 y el interno maneja el contenido de L1,
.   recorriendo todo su contenido cada vez que halla una iteracion en el while externo. Por lo que puedo concluir que,
.   el tiempo de ejecucion depende de M y N de la siguiente manera: M*N (M cantidad de veces que se ejecuta el bucle interno
.   de N iteraciones); obteniendo de esta forma la Complejidad Cuadratica.
.
.
*/
