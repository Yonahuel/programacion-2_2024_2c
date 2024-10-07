#include "tipo_elemento.h"
#include "validaciones.h"
#include "funciones.h"

/*

COMPLEJIDAD ALGORITMICA DE LA SOLUCION:

La funcion " Obtener_Divisores " toma una COMPLEJIDAD ALGORITMICA de O(N^2), mejor dicho, complejidad CUADRATICA.
La funcion depende de su entrada, una COLA que posee N cantidad de elementos, la cual puede variar de 0 - 10.
Dentro de la funcion, se encuentra un bucle while anidado, el cual el EXTERNO se ejecuta N cantidad de veces, dependiendo
del tamaño de la COLA de ingreso. Uno de los bucles internos, que recorre una COPIA de la COLA de ingreso, se ejecuta N cantidad
de veces por cada iteracion del externo. Luego, hace algunas iteraciones para encontrar los DIVISORES TOTALES y PARCIALES
en ese bucle y fuera para agregarlos si es el caso, pero que no cambian la COMPLEJIDAD. Luego, el otro bucle interno, se encarga
de encolar de nuevo los elementos para la proxima iteracion si es el caso, N cantidad de veces tambien.

Conclusion: La funcion depende de la COLA de ingreso, la cual posee N cantidad de elementos y al poseer un bucle anidado,
el cual se ejecuta N veces (externo) y N + N veces (los internos), llegamos a la conclusion que el tiempo de ejecucion depende
de N * N, mejor dicho, N^2 ---> COMPLEJIDAD CUADRATICA.

*/

/*
Para ejecutar este tp en codeblocks hay que ir deshabilitando los ejercicios que no se usan y habilitar solo el que se va a usar.

*/


int main(){

    int bandera;

    Cola Resultado, C;

    do{

        C = c_crear();

        do{

            printf("\t\t\t MENU EJERCICIO 5 'TP COLAS': \n\n");
            printf(" 1.     Agregar elementos a la COLA (MANUALMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 2.     Agregar elementos a la COLA (ALEATORIAMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 3.     Obtener los DIVISORES TOTALES y PARCIALES de los elementos que posee la COLA .\n");
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

                    c_ej5_Carga_Manual(C);

                    c_mostrar(C);

                    break;

                case 2:

                    c_ej5_Carga_Aleatoria(C);

                    c_mostrar(C);

                    break;

                case 3:

                    Resultado = Obtener_Divisores(C);

                    printf(" RESULTADO OBTENIDO:\n\n");
                    c_ej5_Mostrar_Resultado(Resultado);

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
