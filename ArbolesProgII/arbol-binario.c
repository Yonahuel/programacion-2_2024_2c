#include <stdlib.h>
#include <string.h>
#include "arbol-binario.h"
#include "nodo.h"

/*Defino la cantidad de Nodos/Elementos que podra tener el Arbol Binario*/
static const int TAMANIO_MAXIMO = 100;


/*Estructura ArbolBinarioRep que contendra la raiz/padre de todos los Nodos que podra tener el Arbol Binario y la 
cantidad de Nodos/Elementos que tiene actualmente el mismo*/
struct ArbolBinarioRep{

    NodoArbol raiz; //Nodo padre de absolutamente todos los elementos del Arbol Binario.

    int cantidad_elementos; //variable que contendra un seguimiento de la cantidad de elementos que tendra el Arbol Binario
};


/*Funcion que crea el Nodo padre/Arbol Binario vacio*/
ArbolBinario a_crear(){

    /*Creo el puntero de tipo Nodo con memoria dinamica suficiente para almacenar una estructura de ArbolBinarioRep*/
    ArbolBinario nuevo_arbol = (ArbolBinario) malloc(sizeof(struct ArbolBinarioRep));

    /*Coloco la variable raiz en NULL, ya que se hace vacio y todavia no tiene elementos, y coloco en 0 la cantidad 
    de elementos por el mismo motivo*/
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;

    /*Retorno el Nodo recien creado*/
    return nuevo_arbol;
}


/*Funcion que se encarga de informar si el Arbol actual esta vacio, retonando True en caso de que lo sea, y False en caso contrario*/
bool a_es_vacio(ArbolBinario a){
    
    return a->raiz == NULL;
}


/*Funcion que se encarga de informar si el Arbol actual esta lleno, retornando True en caso de que lo sea, y False en caso contrario*/
bool a_es_lleno(ArbolBinario a){
  
    return (a->cantidad_elementos == TAMANIO_MAXIMO);
}


/*Funcion que se encarga de informar la cantidad de elementos que posee actualmente el Arbol Binario*/
int a_cantidad_elementos(ArbolBinario a){
 
    return a->cantidad_elementos;
}


/*Funcion que se encarga de informar si la rama/Nodo pasado por parametro es NULL, retornando True en caso de que lo sea y 
False en caso contrario*/
bool a_es_rama_nula(NodoArbol pa){
    
    return pa == NULL;
}


/*Funcion que se encarga de retornar el Nodo Padre, el cual conecta a todo el Arbol Binario*/
NodoArbol a_raiz(ArbolBinario a){

    return a->raiz;
}


/*Funcion que se encarga de establecer el Nodo Padre/raiz del Arbol Binario si es que este no tiene uno aun*/
NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te){
    
    /*En caso de que el Arbol Binario ya tenga un Nodo Padre/raiz, retorno ese mismo Nodo*/
    if(a->raiz != NULL){
        
        return a->raiz;
    }

    /*Como no tenia un Nodo Padre/raiz, creo un nuevo Nodo con el TipoElemento pasado como parametro para luego 
    establecerlo como Padre*/
    NodoArbol na = n_crear(te);
    a->raiz = na;
    
    /*Aumento en 1 la cantidad de elementos del Arbol Binario*/
    a->cantidad_elementos++;

    /*Retorno el Nodo recien creado para poder trabajar con el luego*/
    return na;
}


/*Funcion que se encarga de conectar a un Nodo pasado por parametro un Nuevo Hijo Izquierdo, en caso de que este no posea ya uno*/
NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te){

    /*Verifico que el Nodo que se paso por parametro tenga datos, sino se retorna NULL haciendo referencia a que ese Nodo no tiene 
    contenido ni esta en el Arbol Binario*/
    if(pa == NULL){

        return NULL;
    }

    /*En caso de que el Nodo ya tenga un Hijo Izquierdo se retorna ese Hijo Izquierdo, ya que no se deben sobreescribir los Nodos 
    ya existentes, si se quiere poner en un Hijo Izquierdo, debera ser en el siguiente*/
    if(pa->hi != NULL){
        
        return pa->hi;
    }

    /*Creo el Nuevo Nodo con los datos del TipoElemento que es pasado como parametro para ser el Hijo Izquierdo*/
    NodoArbol na = n_crear(te);

    /*Sumo 1 a la cantidad de elementos que posee el Arbol Binario*/
    a->cantidad_elementos++;

    /*Coloco en el Nodo ya existente, el Nuevo Hijo Izquierdo*/
    pa->hi = na;

    /*Retorno el Hijo Izquierdo, para no perder la seguidilla*/
    return na;
}


/*Funcion que se encarga de conectar a un Nodo pasado por parametro un Nuevo Hijo Derecho, en caso de que este no posea ya uno*/
NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te){

    /*Verifico que el Nodo que se paso por parametro tenga datos, sino se retorna NULL haciendo referencia a que ese Nodo no tiene 
    contenido ni esta en el Arbol Binario*/
    if(pa == NULL){

        return NULL;
    }

    /*En caso de que el Nodo ya tenga un Hijo Derecho se retorna ese Hijo Derecho, ya que no se deben sobreescribir los Nodos 
    ya existentes, si se quiere poner en un Hijo Derecho, debera ser en el siguiente*/
    if (pa->hd != NULL) {

        return pa->hd;
    }

    /*Creo el Nuevo Nodo con los datos del TipoElemento que es pasado como parametro para ser el Hijo Derecho*/
    NodoArbol na = n_crear(te);

    /*Sumo 1 a la cantidad de elementos que posee el Arbol Binario*/
    a->cantidad_elementos++;

    /*Coloco en el Nodo ya existente, el Nuevo Hijo Derecho*/
    pa->hd = na;

    /*Retorno el Hijo Derecho, para no perder la seguidilla*/
    return na;
}