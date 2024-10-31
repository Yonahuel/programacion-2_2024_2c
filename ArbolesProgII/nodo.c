#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"


/*Funcion que retorna el contenido del del Hijo izquierdo del Nodo pasado por parametro*/
NodoArbol n_hijoizquierdo(NodoArbol N){

    /*Si el Nodo no posee ningun dato, osea, apunta a NULL, retorno NULL ya que no posee datos*/
    if(N == NULL){
        
        return NULL;
    }

    /*Como no es NULL el Nodo pasado, procedo a retornar los datos que posee el hijo izquierdo del Nodo Actual, 
    seran datos o NULL dependiendo de lo que posea el Hijo*/
    else{
        
        return N->hi;
    }
};


/*Funcion que retorna el contenido del del Hijo derecho del Nodo pasado por parametro*/
NodoArbol n_hijoderecho(NodoArbol N){
    
    /*Si el Nodo no posee ningun dato, osea, apunta a NULL, retorno NULL ya que no posee datos*/
    if(N == NULL){

        return NULL;
    }

    /*Como no es NULL el Nodo pasado, procedo a retornar los datos que posee el hijo derecho del Nodo Actual, 
    seran datos o NULL dependiendo de lo que posea el Hijo*/
    else{

        return N->hd;
    }
};


/*Funcion que crea un nuevo Nodo con los datos pasados por parametro de un TipoElemento*/
NodoArbol n_crear(TipoElemento te){

    /*Creo un puntero de tipo Nodo con memoria dinamica con suficiente tamaño para alvergar la estructura de NodoArbolRep*/
    NodoArbol na = (NodoArbol) malloc(sizeof(struct NodoArbolRep));

    /*Le asigno los datos del TipoElemento pasado por parametro y coloco a sus Hijos en NULL ya que de momento no tendra Hijos*/
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;

    /*Coloco en 0 su equilibrio ya que no tiene hijos por lo que, esta equilibrado*/
    na->FE = 0;

    /*Retorno el Nodo recien creado*/
    return na;
};


/*Funcion que se encarga de retornar los datos que se encuentran en X Nodo pasado por parametro*/
TipoElemento n_recuperar(NodoArbol N){

    /*Creo un TipoElemento para poder hacer una copia de los datos del Nodo pasado por parametro*/
    TipoElemento x = te_crear(0);

    /*Si no posee datos, osea, apunta a NULL, retorno NULL*/
    if (N == NULL){

        return NULL;
    }

    /*Caso contrario, hago la copia de los datos del Nodo, y procedo a retornarlos*/
    else{

        x = N->datos;
        return x;
    }
};