#include "tipo_elemento.h"
#include "validaciones.h"
#include "funciones.h"

/*

COMPLEJIDAD ALGORITMICA DE LA SOLUCION:

La funcion " Valores_Repetidos_Posiciones ", posee una COMPLEJIDAD ALGORITMICA de O(N^3), mejor dicho, COMPLEJIDAD CUBICA o
POLINOMIAL. Recibe como entrada una COLA de "N" cantidad de elementos, los cuales pueden variar de 0 - 10, y una PILA de "M"
cantidad de elementos, los cuales tambien pueden variar entre 0 - 10 elementos. Dentro de la funcion, esta posee 2 bucles
anidados, los cuales, el externo se ejecutara M cantidad de veces, segun la cantidad de elementos que posee la PILA, y el
intermedio se ejecuta por cada iteracion del externo N veces. Luego dependiendo el caso, puede aparecer un bucle interno,
el cual recorrera todos los elementos de la LISTA actual, osea K cantidad de veces, pudiendo ejecutarse K * N veces.
Luego, utilizo otro bucle intermedio para reencolar los elementos de la COLA como corresponde, iterando N veces por cada iteracion
del externo. Y por ultimo itero M veces para reapilar como corresponde la PILA original.

Conclusion: La funcion depende de sus estructuras de entrada, las cuales pueden variar de tamaños. Luego, al recorrer una
tercer estructura segun el caso, la complejidad aumenta, llegando a que la ecuacion es (M + M) * (N * N) * K, mejor dicho,
2M*2N*K --> O(M*N*K) siendo COMPLEJIDAD CUBICA O POLINOMIAL en el peor de los casos.

*/

/*
Para ejecutar este tp en codeblocks hay que ir deshabilitando los ejercicios que no se usan y habilitar solo el que se va a usar y antes de ejecutarlo hay que hacer un rebuild.

*/


int main(){

    int bandera;
    Cola C;
    Pila P;
    Lista L;


    do{

        C = c_crear();
        P = p_crear();

        do{

            printf("\t\t\t MENU EJERCICIO 6 'TP COLAS': \n\n");
            printf(" 1.     Agregar elementos a la COLA o a la PILA (MANUALMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 2.     Agregar elementos a la COLA o a la PILA (ALEATORIAMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 3.     Obtener los valores en comun y sus respectivas posiciones de la COLA y la PILA.\n");
            printf(" 4.     Mostrar la COLA y la PILA actuales.\n");
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

                    printf(" A que estructura vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA; *Ingrese ' 2 ' para cargarle a la PILA): ");
                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [1; 2]!\n");
                        printf(" A que estructura vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA; *Ingrese ' 2 ' para cargarle a la PILA): ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        Cargar_Manualmente_Repetidos(C);

                        c_mostrar(C);
                    }

                    else{

                        Cargar_Manualmente_Pila(P);

                        p_mostrar(P);
                    }

                    break;

                case 2:

                    printf(" A que estructura vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA; *Ingrese ' 2 ' para cargarle a la PILA): ");
                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [1; 2]!\n");
                        printf(" A que estructura vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA; *Ingrese ' 2 ' para cargarle a la PILA): ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        Cargar_Aleatoriamente_Repetidos(C);

                        c_mostrar(C);
                    }

                    else{

                        Cargar_Aleatoriamente_Pila(P);

                        p_mostrar(P);
                    }

                    break;

                case 3:

                    L = Valores_Repetidos_Posiciones(C, P);

                    printf(" RESULTADO OBTENIDO: \n\n");

                    c_ej6_Mostrar_Resultado(L);

                    free(L);

                    break;

                case 4:

                    printf(" COLA: \n"); c_mostrar(C); printf("\n");
                    printf(" PILA: \n"); p_mostrar(P); printf("\n");

                    break;
            }

            system("pause");
            system("cls");

        }
        while(bandera != 0);

        printf(" Desea volver a realizar el ejercicio con una COLA y una PILA DIFERENTE? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea volver a realizar el ejercicio con una COLA y una PILA DIFERENTE? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
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
