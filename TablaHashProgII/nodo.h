#ifndef NODO_H
#define NODO_H
#include "tipo_elemento.h"

/*Estructura de NodoArbolRep que guardara los datos del nodo padre y sus hijos, que a su vez se podra concectar 
luego con otros Nodos*/
struct NodoArbolRep {

    /*"Datos" guardara la estructura o el valor que tendra el Nodo actual*/
    TipoElemento datos;

    /*En estas variables se guardara el apuntador a los hijos izquierdo y derecho del Nodo actual*/
    struct NodoArbolRep *hi;
    struct NodoArbolRep *hd;

    /*Variable que se encarga de mantener el equilibrio dentro del Arbol*/
    int FE;
};
typedef struct NodoArbolRep *NodoArbol;

// retorna el hijo izquierdo
NodoArbol n_hijoizquierdo(NodoArbol N);

// retorna el hijo derecho
NodoArbol n_hijoderecho(NodoArbol N);

// Crea un Nodo y lo retorna
NodoArbol n_crear(TipoElemento te);

// Crea un Nodo y lo retorna
TipoElemento n_recuperar(NodoArbol N);

#endif // NODO_H
