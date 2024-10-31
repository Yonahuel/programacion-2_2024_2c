#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

#include <time.h>
#include <stdlib.h>

/*

¿Que puede concluir al respecto?:


Se concluye que en el Arboles AVL cuando se cargan una x cantidad de nodos, su altura no varia, o varia a lo sumo en 1 unidad, 
en cambio en los arboles ABB su Altura es desigual, no sigue ningun criterio a simple vista.

*/




int main(){

    srand(time(NULL));
    int veces_repetir_proceso, Cantidad_elementos;

    Lista Alturas_ABB = l_crear(), Alturas_AVL = l_crear(), Diferencia_Alturas = l_crear();

    ArbolAVL AVL;
    ArbolBinarioBusqueda ABB;

    printf("\t\t\t Bienvenido al Ejercicio 10 'TP ARBOLES'!\n\n\n");
    printf(" Cuantas comparaciones realizaremos? (Numero entero entre [1, 100]): ");
    veces_repetir_proceso = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(veces_repetir_proceso, 1, 100)){

        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 100]!\n");
        printf(" Ingrese la cantidad de veces que repetiremos el proceso: ");
        veces_repetir_proceso = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    printf("\n Cuantos elementos tendran todos los Arboles? (Numero entero entre [1, 100]): ");
    Cantidad_elementos = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(Cantidad_elementos, 1, 100)){

        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 100]!\n");
        printf(" Ingrese la cantidad de elementos que tendran todos los arboles: ");
        Cantidad_elementos = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    while(veces_repetir_proceso > 0){

        AVL = avl_crear();
        ABB = abb_crear();

        Cargar_AVL_ABB(AVL, ABB, Cantidad_elementos);

        Comparar_Altura_ABB_AVL(AVL, Alturas_AVL, ABB, Alturas_ABB, Diferencia_Alturas);

        free(AVL);
        free(ABB);
        veces_repetir_proceso--;
    }

    Mostrar_Resultados(Alturas_AVL, Alturas_ABB, Diferencia_Alturas);
    
    system("pause");
    system("cls");

    free(Alturas_ABB);
    free(Alturas_AVL);
    free(Diferencia_Alturas);

    return 0;
}