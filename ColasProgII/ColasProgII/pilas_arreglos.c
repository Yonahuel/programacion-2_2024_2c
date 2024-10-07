#include "pilas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*Variable que define el tamaño maximo que tendra la pila*/
static const int TAMANIO_MAXIMO = 10;


/*Estructura PilaRep, la cual es un arreglo de punteros de TipoElemento*/
struct PilaRep {

    /*Arreglo de elementos*/
    TipoElemento *valores;

    /*Variable sin signo que apunta al tope de la pila*/
    unsigned int tope;
};


/*Funcion que crea la pila con memoria dinamica*/
Pila p_crear() {

    /*Creo la pila con memoria dinamica con suficiente espacio para almacenar la estructura PilaRep, la cual alverga un array de
    punteros de tipoelemento simulando una pila*/
    Pila nueva_pila = (Pila) malloc(sizeof(struct PilaRep));

    /*Creo y inicializo en 0 todas las posiciones de tipoelemento de valores con memoria dinamica. Coloco en 0 el tamaño de la pila,
    ya que todavia no se cargaro ningun elemento en ella*/
    nueva_pila->valores = calloc((TAMANIO_MAXIMO+1), sizeof(TipoElemento));
    nueva_pila->tope = 0;

    /*Retorno la pila creada*/
    return nueva_pila;
}


/*Funcion que va agregando elementos a la pila, el nuevo elemento agregado siempre sera el tope de la pila*/
bool p_apilar(Pila pila, TipoElemento elemento) {

    /*Verifico si la pila no esta llena. En caso que lo este, retorna False, haciendo referencia a que no se pueden
    apilar mas elementos*/
    if (p_es_llena(pila)) {

        return false;
    }

    /*Como no esta llena, suma 1 al tope, haciendo referencia al valor siguiente y en pila->valores[tope] se ingresa el nuevo elemento*/
    pila->tope++;
    pila->valores[pila->tope] = elemento;

    /*Retorno true, haciendo referencia a que se pudo apilar el nuevo elemento*/
    return true;
}


/*Funcion que desapila/devuelve el valor que estaba en el tope de la pila, para que hagamos lo que querramos con él*/
TipoElemento p_desapilar(Pila pila) {

    /*Verificamos que la pila no estaba vacia, ya que no se puede desapilar elementos que no hay. Retorna NULL, haciendo referencia
    a que no hay elementos para desapilar*/
    if (p_es_vacia(pila)) {

        return NULL;
    }

    /*Le asigna el elemento que habia en el tope de la pila y le resta 1 al tope para apuntar al elemento anterior al recuperado*/
    TipoElemento elemento = pila->valores[pila->tope];
    pila->tope--;

    /*Retorno el elemento, haciendo referencia a que se pudo desapilar el mismo*/
    return elemento;
}


/*Funcion que me devuelve el elemento que se encuentra en el tope de la pila*/
TipoElemento p_tope(Pila pila) {

    /*Si la pila esta vacia, Retorna NULL haciendo referencia a que no hay elementos en la misma*/
    if (p_es_vacia(pila)) {

        return NULL;
    }

    /*Retorno el valor que esta en el tope de la pila*/
    return pila->valores[pila->tope];
}


/*Funcion que informa si no hay elementos en la pila*/
bool p_es_vacia(Pila pila) {

    return (pila->tope <= 0);
}


/*Funcion que informa si la pila esta llena*/
bool p_es_llena(Pila pila) {

    return (pila->tope == TAMANIO_MAXIMO);
}


/*Funcion que muestra el contenido de la pila*/
void p_mostrar(Pila pila) {

    /*Si esta vacia lo informa por pantalla y sale de la funcion*/
    if (p_es_vacia(pila)) {

        printf("PILA VACIA !!! \n");
        return;
    }

    /*Creo una pila auxiliar para almacenar los elementos que voy a desapilar*/
    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);

    printf("Contenido de la pila: ");

    /*Este bucle desapila los elementos que hay en la pila, pasandola a la pila auxiliar, para poder ir imprimiendo su contenido, ya que
    no se puede acceder a cualquier valor de la pila, solo al tope de la misma*/
    while (p_es_vacia(pila) != true) {

        X = p_desapilar(pila);
        printf("%d ", X->clave);
        p_apilar(Paux, X);
    }

    /*vuelvo a apilar los elementos en la pila original para darles el correspondiente orden de nuevo*/
    while (p_es_vacia(Paux) != true) {

        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }

    printf("\n");
}
