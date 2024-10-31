#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

/*

!!!! A FALTA DE RESPUESTA DE LOS PROFESORES, PROCEDO A RESPONDER LA COMPLEJIDAD DE LAS FUNCIONES SIN TENER EN CUENTA NINGUNA TAD (NI
DE ARBOLES, NI DE ESTRUCTURAS COMO LAS DE LISTAS O COLAS)¡¡¡¡¡¡¡

COMPLEJIDAD ALGORITMICAS DE LAS FUNCIONES:  

A) La solucion propuesta a traves de las funciones "Obtener_Hojas_AB" y "B_Hojas" es de COMPLEJIDAD ALGORITMICA LINEAL, o mejor dicho,
O(N). Estas funciones solo dependen de la entrada de datos, que en este caso es el ARBOL BINARIO, el cual posee N cantidad de elementos
, los cuales son todos recorridos en "B_Hojas" una sola vez, en busca de aquellas que son hojas para poder agregarlos a una lista. Por
conclusion, solo se itera N veces dependiendo de la cantidad de elementos del Arbol Binario. COMPLEJIDAD ALGORIMICA O(N).



B) La solucion propuesta a traves de las funciones "Obtener_Internos_AB" y "B_Internos" es de COMPLEJIDAD ALGORITMICA LINEAL, o mejor 
dicho, O(N). Estas funciones solo dependen de la entrada de datos, que en este caso es el ARBOL BINARIO, el cual posee N cantidad 
de elementos, los cuales son todos recorridos en "B_Internos" una sola vez, en busca de aquellos que son internos para poder 
agregarlos a una lista. Por conclusion, solo se itera N veces dependiendo de la cantidad de elementos del Arbol Binario. 
COMPLEJIDAD ALGORIMICA O(N).



C) La solucion propuesta a traves de las funciones "Obtener_Ocurrencias_AB" y "B_Ocurrencias" es de COMPLEJIDAD ALGORITMICA LINEAL, o 
mejor dicho, O(N). Estas funciones solo dependen de la entrada de datos, que en este caso es el ARBOL BINARIO, el cual posee N cantidad 
de elementos, los cuales son todos recorridos en "B_Ocurrencias" una sola vez, en busca de aquellos que son iguales a una clave 
dada por parametro para poder agregarlos a una lista. Por conclusion, solo se itera N veces dependiendo de la cantidad de elementos 
del Arbol Binario. COMPLEJIDAD ALGORIMICA O(N).

*/






int main(){

    int bandera, clave;
    bool puedo = false;

    Lista Contenido;

    TipoElemento Raiz;
    NodoArbol N_Principal;
    ArbolBinario Arbol;
    Lista Hojas, Internos, Ocurrencias;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 2 'TP ARBOLES'!\n\n\n");
        printf(" 1.     Crear el Arbol Binario y cargarle elementos (Solo puede usarla si no esta cargado aun).\n");
        printf(" 2.     Borrar el Arbol Binario Actual.\n");
        printf(" 3.     Obtener una Lista con los Nodos Terminales del Arbol Binario.\n");
        printf(" 4.     Obtener una Lista con los Nodos Internos del Arbol Binario.\n");
        printf(" 5.     Obtener una Lista con las Posiciones de las Ocurrencias de una Clave en el Arbol Binario.\n");
        printf(" 6.     Mostrar el contenido del Arbol Binario.\n");
        printf(" 0.     Salir del Sistema.\n\n");
        printf(" Ingresa el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 6)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 6]!\n");
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

                    Arbol = a_crear();

                    printf("\n Ingresa la Clave de la Raiz del Arbol Binario: ");
                    Raiz = te_crear(Ingreso_Entero_Positivo_Negativo());

                    N_Principal = a_establecer_raiz(Arbol, Raiz);

                    Contenido = Cargar_Arbol_Binario_PO(Arbol, N_Principal);

                    if(a_es_lleno(Arbol)){
                        
                        printf(" El Arbol Binario se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }

                }

                else{

                    printf("\n Ya cargo el Arbol Binario! si desea cargar otro, primero ejecuta la accion ' 2 ' del Menu!\n");
                }

                break;

            case 2:

                if(puedo){

                    free(N_Principal);
                    free(Arbol);
                    free(Raiz);

                    puedo = false;
                    printf("\n Se ah borrado el Arbol Binario!\n");
                }

                else{

                    printf("\n No hay Arbol Binario que Borrar!\n");
                }

                break;

            case 3:

                if(puedo){
                    
                    Hojas = Obtener_Hojas_AB(Arbol);

                    l_mostrar(Hojas);

                    free(Hojas);
                }

                else{

                    printf("\n Para realizar el ejercicio, debe primero crear y cargar el Arbol Binario!\n");
                }
                break;

            case 4:

                if(puedo){
                    
                    Internos = Obtener_Internos_AB(Arbol);

                    l_mostrar(Internos);

                    free(Internos);
                }

                else{

                    printf("\n Para realizar el ejercicio, debe primero crear y cargar el Arbol Binario!\n");
                }

                break;

            case 5:

                if(puedo){
                    
                    printf(" Ingrese la Clave a la cual buscar en el Arbol Binario: ");
                    clave = Ingreso_Entero_Positivo_Negativo();

                    Ocurrencias = Obtener_Ocurrencias_AB(Arbol, clave);

                    mostrar_Ocurrencias(Ocurrencias, clave);

                    free(Ocurrencias);

                }

                else{

                    printf("\n Para realizar el ejercicio, debe primero crear y cargar el Arbol Binario!\n");
                }

                break;

            case 6:
                
                if(puedo){

                    printf("\n Contenido del Arbol Binario: \n\n");
                    mostrar_AB(a_raiz(Arbol), 0);
                }

                else{

                    printf("\n No hay Arbol Binario! primero creelo y carguelo con la accion ' 1 ' del menu!\n");
                }

                break;
        }

        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}