#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

/*

COMPLEJIDAD ALGORITMICA:

La complejidad de la solución propuesta, a través de las funciones Comparar_Binario_AVL y Obtener_Altura_AB_ABB_AVL, es lineal, 
o más específicamente, O(N), ya que depende únicamente del tamaño de la entrada, es decir, del número de nodos en los árboles AVL y 
Binario, los cuales tienen la misma cantidad de elementos. 
El árbol Binario, en el peor de los casos, puede estar completamente desbalanceado, degenerándose en una estructura similar a una 
lista enlazada (donde todos los elementos son hijos izquierdos o derechos de su nodo padre). En este caso, su altura es O(N). Por otro 
lado, el árbol AVL, que es balanceado, tendrá una altura de O(log N).

Dado que Comparar_Binario_AVL calcula las alturas de ambos árboles llamando a Obtener_Altura_AB_ABB_AVL dos veces, la complejidad 
total será la suma de ambas complejidades: O(N) + O(log N). Sin embargo, en notación Big-O, el término O(N) domina, ya que es mayor que 
O(log N) en el peor caso. Por lo tanto, la complejidad final de la solución es O(N).


*/




int main(){

    int bandera, Diferencia;
    bool puedo = false;

    ArbolBinario Arbol_Binario;
    ArbolAVL Arbol_Avl;

    TipoElemento Raiz;
    NodoArbol Principal;
    Lista Contenido;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 9 'TP ARBOLES'!\n\n\n");
        printf(" 1.     Crear el Arbol Binario y el Arbol Avl con su contenido (Solo puede usarla si no esta cargado aun).\n");
        printf(" 2.     Borrar el Arbol Binario y el Arbol Avl actuales.\n");
        printf(" 3.     Comparar las alturas de ambos Arboles.\n");
        printf(" 0.     Salir del Sistema\n\n");
        printf(" Ingresa el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 3)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 3]!\n");
            printf(" Ingrese el numero de la accion a realizar: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        switch(bandera){

            case 0:

                break;

            case 1:

                if(!puedo){

                    puedo = true;

                    Arbol_Binario = a_crear();

                    printf("\n Ingresa la Clave de la Raiz del Arbol Binario: ");
                    Raiz = te_crear(Ingreso_Entero_Positivo_Negativo());

                    Principal = a_establecer_raiz(Arbol_Binario, Raiz);

                    Contenido = Cargar_Arbol_Binario_POU(Arbol_Binario, Principal);

                    if(a_es_lleno(Arbol_Binario)){

                        printf(" El Arbol Binario se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }


                    Arbol_Avl = De_Binario_a_Avl(Arbol_Binario);
                }

                break;

            case 2:

                if(puedo){

                    free(Arbol_Avl);
                    free(Arbol_Binario);
                    free(Contenido);
                    free(Principal);
                    free(Raiz);

                    puedo = false;
                    printf("\n Se borraron los Arboles!\n");
                }
                
                else{

                    printf("\n No hay arboles que borrar! Todavia no los creo!\n");
                }

                break;

            case 3:

                if(puedo){

                    Diferencia = Comparar_Binario_AVL(Arbol_Binario, Arbol_Avl);
                }

                else{

                    printf("\n Todavia no cargo los Arboles! hagalo antes para poder realizar el ejercicio!\n");
                }

                break;
        }


        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}