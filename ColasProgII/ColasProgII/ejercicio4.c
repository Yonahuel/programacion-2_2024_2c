#include "tipo_elemento.h"
#include "validaciones.h"
#include "funciones.h"


/*

COMPLEJIDAD ALGORITMICA DE LA SOLUCION:

La funcion " Obtener_Sin_Repetidos " toma una COMPLEJIDAD ALGORITMICA de O(X^2), mejor dicho, complejidad CUADRATICA, ya
que la funcion recibe como entrada una COLA, la cual varia su tamaño de 0 - 10 elementos, haciendo que el tiempo de
ejecucion varie segun el tamaño de esta. Sin embargo, dentro de la funcion se encuentra un bucle while anidado. El externo,
va desencolando los elementos de la COLA ORIGINAL, iterando N veces, mientras que uno de los internos, se encarga de
recorrer toda la COPIA de la COLA ORIGINAL, iterando N veces por cada una del externo, contabilizando cuantas veces aparece
el elemento desencolado, y el otro, vuelve a encolar en la COPIA todos los elementos como corresponde para la siguiente
iteracion del externo. Si el elemento aparece una sola vez se lo encola en una COLA RESULTADO.

CONCLUSION: La funcion depende del tamaño de la entrada la cual es "N" y al poseer un bucle while anidado, el cual se
ejecuta N veces el exterior y N + N veces los interiores, llegamos a la conclusion que el tiempo de ejecucion de esta funcion
depende de N * N, mejor dicho N^2 ---> COMPLEJIDAD CUADRATICA.

*/

/*
Para ejecutar este tp en codeblocks hay que ir deshabilitando los ejercicios que no se usan y habilitar solo el que se va a usar.

*/


int main(){

    int bandera;
    bool ordenado;
    Cola C, Resultado;

    do{

        C = c_crear();

        do{

            printf("\t\t\t MENU EJERCICIO 4 'TP COLAS': \n\n");
            printf(" 1.     Agregar elementos a la COLA (MANUALMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 2.     Agregar elementos a la COLA (ALEATORIAMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 3.     Obtener los elementos sin repetir de la COLA.\n");
            printf(" 4.     Mostrar la COLA actual.\n");
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

                    do{

                        Cargar_Manualmente_Repetidos(C);

                        ordenado = Cola_Ordenada(C);

                        if(ordenado){

                            if(c_es_llena(C)){

                                free(C);
                                C = c_crear();

                                printf(" La COLA que termino de ingresar esta llena y todos sus elementos estan ordenados!\n");
                                printf(" Debera ingresar una nueva cola desde 0!\n");
                            }

                            else{

                                printf(" La COLA actual esta ordenada! por favor, ingrese otro/s elemento/s para desordenarla!\n");
                            }

                            system("pause");
                        }
                    }
                    while(ordenado);

                    c_mostrar(C);

                    break;

                case 2:

                    Cargar_Aleatoriamente_Repetidos(C);

                    c_mostrar(C);

                    break;

                case 3:

                    Resultado = Obtener_Sin_Repetidos(C);

                    printf(" COLA ORIGINAL: \n"); c_mostrar(C);

                    printf(" COLA SIN REPETIDOS: \n"); c_mostrar(Resultado);

                    free(Resultado);

                    break;

                case 4:

                    c_mostrar(C);

                    break;
            }

            system("pause");
            system("cls");

        }
        while(bandera != 0);

        printf(" Desea volver a realizar el ejercicio con una COLA DIFERENTE? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea volver a realizar el ejercicio con una COLA DIFERENTE? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(C);

    }
    while(bandera != 0);

    printf(" Hasta la proxima!\n");
    system("pause");

    return 0;
}
