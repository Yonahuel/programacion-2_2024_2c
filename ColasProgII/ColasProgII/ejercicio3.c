#include "tipo_elemento.h"
#include "validaciones.h"
#include "funciones.h"


/*

COMPLEJIDAD ALGORITMICA DE LA SOLUCION:

la funcion " Verificar_Igualdad " toma una complejidad algoritmica de O(N), mejor dicho,
complejidad LINEAL, ya que la funcion solo recibe 2 COLAS las cuales unicamente dependen de su tamaño (cantidad de
elementos que estas poseen), que pueden variar de 0 a 10 elementos, por lo que el tiempo de la ejecucion de la funcion
no es siempre la misma. Luego, en el peor de los casos, aquel en que la cantidad de elementos de las COLAS es la misma,
utiliza un solo bucle while para comparar sus elementos (llamando a una funcion "c_desencolar" la cual es de complejidad
constante, para obtener el elemento del inicio de las COLAS), y almacenarlos en dos COLAS auxiliares. Este bucle while
siempre iterara segun la cantidad de elementos que tengan las COLAS, por ende es LINEAL. Por ultimo, utilizo otro bucle
para devolver a sus respectivas COLAS ORIGINALES los elementos.

Conclusion: la funcion es de complejidad LINEAL, ya que unicamente depende del tamaño 'N' que tengan ambas COLAS, que puede
no ser la misma en todas sus corridas. Con los 2 bucles seria N + N, mejor dicho 2N --> COMPLEJIDAD LINEAL.



*/
/*
Para ejecutar este tp en codeblocks hay que ir deshabilitando los ejercicios que no se usan y habilitar solo el que se va a usar.

*/



int main(){

    int bandera;
    bool iguales;

    Cola C1, C2;

    do{

        C1 = c_crear();
        C2 = c_crear();

        do{

            printf("\t\t\t MENU EJERCICIO 3 'TP COLAS': \n\n");
            printf(" 1.     Agregar elementos a una de las COLAS (MANUALMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 2.     Agregar elementos a una de las COLAS (ALEATORIAMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 3.     Verificar si las 2 COLAS son iguales tanto en posicion como en contenido.\n");
            printf(" 4.     Mostrar las COLAS actuales.\n");
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

                    printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA 1; *Ingrese ' 2 ' para cargarle a la COLA 2): ");
                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [1; 2]!\n");
                        printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA 1; *Ingrese ' 2 ' para cargarle a la COLA 2): ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        Cargar_Manualmente_Repetidos(C1);

                        printf(" COLA 1: \n"); c_mostrar(C1);
                    }

                    else{

                        Cargar_Manualmente_Repetidos(C2);

                        printf(" COLA 2: \n"); c_mostrar(C2);
                    }

                    break;

                case 2:

                    printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA 1; *Ingrese ' 2 ' para cargarle a la COLA 2): ");
                    bandera = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                        printf(" Ingreso Invalido! Debe ingresar una opcion entre [1; 2]!\n");
                        printf(" A que COLA vamos a agregarle elementos? (*Ingrese ' 1 ' para cargarle a la COLA 1; *Ingrese ' 2 ' para cargarle a la COLA 2): ");
                        bandera = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    if(bandera == 1){

                        Cargar_Aleatoriamente_Repetidos(C1);

                        printf(" COLA 1: \n"); c_mostrar(C1);
                    }

                    else{

                        Cargar_Aleatoriamente_Repetidos(C2);

                        printf(" COLA 2: \n"); c_mostrar(C2);
                    }

                    break;

                case 3:

                    iguales = Verificar_Igualdad(C1, C2);

                    printf(" Son iguales las COLAS en posicion y contenido? %s.\n", iguales ? "True" : "False");

                    break;

                case 4:

                    printf(" COLA 1: \n"); c_mostrar(C1);
                    printf(" COLA 2: \n"); c_mostrar(C2);

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

    }
    while(bandera != 0);

    printf(" Hasta la proxima!\n");
    system("pause");

    return 0;
}
