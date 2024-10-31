#include "nodo.h"
#include "arbol-avl.h"

/*Cantidad maxima de Nodos que podra tener el Arbol AVL*/
static const int TAMANIO_MAXIMO = 1000;

/*Prototipo de funciones que solo estan acalaradas en este Archivo.c*/
NodoArbol avl_rotar_derecha(NodoArbol nodo);
NodoArbol avl_rotar_izquierda(NodoArbol nodo);
int avl_altura_izq(NodoArbol nodo);
int avl_altura_der(NodoArbol nodo);
int avl_max(int a, int b);

/*Estructura de Enumeracion que nos ayuda a corroborar los diferentes estados en los que puede estar un Nodo del Arbol AVL*/
enum Balanceo {

    /*Indica que esta desbalanceado a la derecha, esto quiere decir que el Nodo tiene +2, osea 2 HD mas que la cantidad de HI
    (en altura de subarbol)*/
    DESBALANCEADO_DERECHA,
    
    /*Indica que esta apenas desbalanceado a la derecha, esto quiere decir que el Nodo tiene +1, osea 1 HD mas que la cantidad de HI
    (en altura de subarbol)*/
    APENAS_DESBALANCEADO_DERECHA,
    
    /*Indica que el Nodo esta completamente balanceado, la misma cantidad de HI que de HD*/
    BALANCEADO,
    
    /*Indica que esta apenas desbalanceado a la Izquierda, esto quiere decir que el Nodo tiene -1, osea 1 HI mas que la cantidad de HD
    (en altura de subarbol)*/
    APENAS_DESBALANCEADO_IZQUIERDA,
    
    /*Indica que esta desbalanceado a la Izquierda, esto quiere decir que el Nodo tiene -2, osea 2 HI mas que la cantidad de HD 
    (en altura de subarbol)*/
    DESBALANCEADO_IZQUIERDA
};

/*Funcion que se encarga de crear un Arbol AVL vacio y lo retorna para trabajar con él*/
ArbolAVL avl_crear(){

    /*Creo un Puntero a la estructura ArbolVLRep con memoria dinamica y el suficiente tamaño para poder almacenar sus variables*/
    ArbolAVL nuevo_arbol = (ArbolAVL) malloc(sizeof(struct ArbolAVLRep));

    /*Coloco la Raiz del Arbol en NULL ya que lo creo vacio*/
    nuevo_arbol->raiz = NULL;

    /*Coloco en 0 la cantidad de elementos que posee el Arbol ya que esta vacio*/
    nuevo_arbol->cantidad_elementos = 0;

    /*Retorno el Puntero recien creado*/
    return nuevo_arbol;
}


/*Funcion que informa si el Arbol pasado esta vacio retornando True, o con elementos retornando False*/
bool avl_es_vacio(ArbolAVL a){

    return a->raiz == NULL;
}


/*Funcion que informa si el Arbol esta lleno, retornando True si lo esta y False en caso contrario*/
bool avl_es_lleno(ArbolAVL a){

    return (a->cantidad_elementos == TAMANIO_MAXIMO);
}


/*Funcion que se encarga de verificar si el Nodo tiene informacion o apunta a NULL, retornando False en caso de que no apunte a NULL*/
bool avl_es_rama_nula(NodoArbol pa){

    return pa == NULL;
}


/*Funcion que informa la cantidad de Nodos que posee el Arbol AVL actualmente*/
int avl_cantidad_elementos(ArbolAVL a){

    return a->cantidad_elementos;
}


/*Funcion que devuelve el Nodo Raiz/Padre del Arbol AVL*/
NodoArbol avl_raiz(ArbolAVL a){

    return a->raiz;
}


/*
NodoArbol avl_crear_nodo(TipoElemento te) {
    NodoArbol na = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    na->datos = te;
    na->hi = NULL;
    na->hd = NULL;
    na->FE = 0;
    return na;
}
*/


/*Funcion que calcula el balanceo que tiene cierto Nodo, recorriendo su HI y HD en busca de las alturas de los mismos para compararlas*/
enum Balanceo avl_calcular_balanceo(NodoArbol nodo){

    /*Calculo la diferencia de alturas del HI y HD*/
    int diferenciaAltura = avl_altura_izq(nodo) - avl_altura_der(nodo);

    switch (diferenciaAltura){
        
        /*Si la diferencia dio -2, retorno desbalanceo por derecha, ya que el HI tiene 2 alturas más*/
        case -2:
        
            return DESBALANCEADO_DERECHA;
        
        /*Si la diferencia dio -1, retorno apenas desbalanceo por derecha, ya que el HI tiene 1 altura más*/
        case -1:
        
            return APENAS_DESBALANCEADO_DERECHA;
        
        /*Si la diferencia dio 1, retorno apenas desbalanceo por Izquierda, ya que el HD tiene 1 altura más*/
        case 1:
        
            return APENAS_DESBALANCEADO_IZQUIERDA;
        
        /*Si la diferencia dio 2, retorno desbalanceo por Izquierda, ya que el HD tiene 2 alturas más*/
        case 2:
        
            return DESBALANCEADO_IZQUIERDA;
        
        /*Retorno balanceado, ya que no hay diferencias en la altura de ambos Hijos*/
        default:
            
            return BALANCEADO;
    }
}


/*Funcion que se encarga de insertar un Nodo en la posicion correcta, segundo si es mayor o menor a otros Nodos*/
NodoArbol avl_insertar_recursivo(ArbolAVL a, TipoElemento te, NodoArbol pa, bool *inserto){
    
    /*Si el Nodo Padre apunta a NULL significa que llegamos a la Hoja del Arbol y lo insertamos ahi al Nodo*/
    if(pa == NULL){
        
        /*Coloco en true inserto*/
        *inserto = true;

        /*Creo y retorno el Nodo que quiero insertar para poder enlazarlo al Arbol AVL*/
        return n_crear(te);
    }

    /*Si el elemento que se quiere ingresar en el Arbol AVL es mas chico que el Nodo Actual donde estamos parados*/
    if(te->clave < pa->datos->clave){

        /*Continuamos bajando por el HI de este mismo Nodo para insertarlo cuando llegue a uno que apunta a NULL*/
        pa->hi = avl_insertar_recursivo(a, te, pa->hi, inserto);
    } 
    
    /*Si el elemento que se quiere ingresar en el Arbol AVL es mas grande que el Nodo Actual donde estamos parados*/
    else if(te->clave > pa->datos->clave){

        /*Continuamos bajando por el HD de este mismo Nodo para insertarlo cuando llegue a uno que apunta a NULL*/
        pa->hd = avl_insertar_recursivo(a, te, pa->hd, inserto);
    } 
    
    else {
        // Es una inserción de un elemento duplicado
        // decrementamos para compensar el incremento
        // hecho anteriormente
        a->cantidad_elementos--;
        return pa;
    }

    /*Calculo el nuevo balance que tendra el Actual Nodo en el que estamos*/
    pa->FE = avl_max(avl_altura_izq(pa), avl_altura_der(pa)) + 1;

    /*Recupero el resultado del balance anterior para poder corroborar si hay que hacer una rotacion*/
    enum Balanceo balanceState = avl_calcular_balanceo(pa);

    /**/
    if (balanceState == DESBALANCEADO_IZQUIERDA) {
        if (te->clave < pa->hi->datos->clave) {
            // Caso rotación derecha
            pa = avl_rotar_derecha(pa);
        } else {
            // Caso rotación izquierda-derecha
            pa->hi = avl_rotar_izquierda(pa->hi);
            return avl_rotar_derecha(pa);
        }
    }

    if (balanceState == DESBALANCEADO_DERECHA) {
        if (te->clave > pa->hd->datos->clave) {
            // Caso rotación izquierda
            pa = avl_rotar_izquierda(pa);
        } else {
            // Caso rotación derecha-izquierda
            pa->hd = avl_rotar_derecha(pa->hd);
            return avl_rotar_izquierda(pa);
        }
    }

    return pa;
}

bool avl_insertar(ArbolAVL a, TipoElemento te) {
    bool inserto = false;
    a->raiz = avl_insertar_recursivo(a, te, avl_raiz(a), &inserto);
    a->cantidad_elementos++;
    return inserto;
}


NodoArbol avl_buscar_minimo(NodoArbol nodoArbol) {
    NodoArbol actual = nodoArbol;

    while (actual && actual->hi != NULL)
        actual = actual->hi;

    return actual;
}


NodoArbol avl_eliminar_recursivo(ArbolAVL arbol, NodoArbol nodoArbol, int claveABorrar, bool *borre) {
    if (nodoArbol == NULL) {
        arbol->cantidad_elementos++; // No lo encontramos, sumamos para compensar
        return nodoArbol;
    }

    if (claveABorrar < nodoArbol->datos->clave)
        nodoArbol->hi = avl_eliminar_recursivo(arbol, nodoArbol->hi, claveABorrar, borre);
    else if (claveABorrar > nodoArbol->datos->clave)
        nodoArbol->hd = avl_eliminar_recursivo(arbol, nodoArbol->hd, claveABorrar, borre);
    else {
        // encontre la clave
        *borre = true;
	// es una hoja
        if (nodoArbol->hi == NULL && nodoArbol->hd == NULL) {
//          free(nodoArbol);
            nodoArbol = NULL;
        } else if (nodoArbol->hi == NULL && nodoArbol->hd != NULL) {
	      // Un solo hijo x derecha
              nodoArbol = nodoArbol->hd;
//            NodoArbol temp = nodoArbol->hd;
//            free(nodoArbol);
//            return temp;
        } else if (nodoArbol->hi != NULL && nodoArbol->hd == NULL) {
              // Un solo hijo x izquierda
	      nodoArbol = nodoArbol->hi;
//            NodoArbol temp = nodoArbol->hi;
//            free(nodoArbol);
//            return temp;
        } else {
            // El nodo tiene 2 hijos, buscamos el sucesor en in-orden (o sea el menor del subárbol de la derecha)
            NodoArbol temp = avl_buscar_minimo(nodoArbol->hd);
            nodoArbol->datos->clave = temp->datos->clave;
            nodoArbol->datos->valor = temp->datos->valor;
            nodoArbol->hd = avl_eliminar_recursivo(arbol, nodoArbol->hd, temp->datos->clave, borre);
        }
    }

    if (nodoArbol == NULL) {
        return nodoArbol;
    }

    // Actualizar altura y re-balancear el árbol de ser necesario
    nodoArbol->FE = avl_max(avl_altura_izq(nodoArbol), avl_altura_der(nodoArbol)) + 1;
    enum Balanceo balanceState = avl_calcular_balanceo(nodoArbol);

    if (balanceState == DESBALANCEADO_IZQUIERDA) {
        if (avl_calcular_balanceo(nodoArbol->hi) == BALANCEADO ||
                avl_calcular_balanceo(nodoArbol->hi) == APENAS_DESBALANCEADO_IZQUIERDA) {
            return avl_rotar_derecha(nodoArbol);
        }

        // avl_calcular_balanceo(nodoArbol->hi) === Balanceo.APENAS_DESBALANCEADO_DERECHA
        nodoArbol->hi = avl_rotar_izquierda(nodoArbol->hi);
        return avl_rotar_derecha(nodoArbol);
    }

    if (balanceState == DESBALANCEADO_DERECHA) {
        if (avl_calcular_balanceo(nodoArbol->hd) == BALANCEADO ||
                avl_calcular_balanceo(nodoArbol->hd) == APENAS_DESBALANCEADO_DERECHA) {
            return avl_rotar_izquierda(nodoArbol);
        }
        // avl_calcular_balanceo(nodoArbol->hd) === Balanceo.APENAS_DESBALANCEADO_DERECHA
        nodoArbol->hd = avl_rotar_derecha(nodoArbol->hd);
        return avl_rotar_izquierda(nodoArbol);
    }

    return nodoArbol;
}

bool avl_eliminar(ArbolAVL a, int claveABorrar) {
    bool borre = false;
    a->raiz = avl_eliminar_recursivo(a, avl_raiz(a), claveABorrar, &borre);
    a->cantidad_elementos--;
    return borre;
}


TipoElemento avl_buscar_recursivo(NodoArbol nodoArbol, int clave) {
    if (nodoArbol == NULL)
        return NULL;
    else if (clave < nodoArbol->datos->clave)
        return avl_buscar_recursivo(nodoArbol->hi, clave);
    else if (clave > nodoArbol->datos->clave)
        return avl_buscar_recursivo(nodoArbol->hd, clave);
    else
        return nodoArbol->datos;
}

TipoElemento avl_buscar(ArbolAVL a, int clave) {
    return avl_buscar_recursivo(avl_raiz(a), clave);
}


////////////////////////////////////
///  Funciones para el balanceo  ///
////////////////////////////////////

int avl_altura_izq(NodoArbol nodo) {
    if (nodo->hi == NULL) {
        return -1;
    }
    return nodo->hi->FE;
}

int avl_altura_der(NodoArbol nodo) {
    if (nodo->hd == NULL) {
        return -1;
    }
    return nodo->hd->FE;
}

int avl_max(int a, int b) {
    return a > b ? a : b;
}

/**
 *  * Rotación izquierda
 *   a                                     b
 *  / \                                   / \
 * c   b  -> a.avl_rotar_izquierda() ->  a   e
 *    / \                               / \
 *   d   e                             c   d
 */
NodoArbol avl_rotar_izquierda(NodoArbol nodo) {
    NodoArbol otro = nodo->hd;
    nodo->hd = otro->hi;
    otro->hi = nodo;
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->FE = avl_max(avl_altura_der(otro), nodo->FE) + 1;

    return otro;
}

/**
 * Rotación derecha
 *     b                                 a
 *    / \                               / \
 *   a   e -> b.avl_rotar_derecha() -> c   b
 *  / \                                   / \
 * c   d                                 d   e
 */
NodoArbol avl_rotar_derecha(NodoArbol nodo) {
    NodoArbol otro = nodo->hi;
    nodo->hi = otro->hd;
    otro->hd = nodo;
    nodo->FE = avl_max(avl_altura_izq(nodo), avl_altura_der(nodo)) + 1;
    otro->FE = avl_max(avl_altura_izq(otro), nodo->FE) + 1;

    return otro;
}
