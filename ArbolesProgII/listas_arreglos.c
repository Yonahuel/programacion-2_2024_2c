#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*Variable que se encarga de definir el tamaño de la lista*/
static const int TAMANIO_MAXIMO = 100;


/*Estructura que representa una lista*/
struct ListaRep {
    
    /*Esta es la lista, que consta de un array de punteros a un tipo de estructura 'TipoElementoRep', ya que 'TIPOELEMENTO' es un 
    puntero a esa estructura ya mencionada*/
    TipoElemento *valores;
    
    /*Esta es la variable que define la cantidad de elementos actuales que hay en la lista*/
    int cantidad;
};


/*Estructura que representa un iterador de la lista*/
struct IteradorRep {
    
    /*Este es un puntero a la estructura 'ListaRep', que basicamente va a apuntar al contenido de la lista creada en la posicion de
    memoria de ListaRep. Funcionara a modo de copia para poder iterar en su contenido*/
    Lista lista;
    
    /*Esta es una variable que se encarga guardar la posicion en la que estamos actualmente en la lista. Es un iterador*/
    int posicionActual;
};


/*Funcion que se encarga de crear una lista de punteros a la estructura de 'TipoElementoRep', de forma vacia*/
Lista l_crear() {
    
    /*Crea un puntero a 'ListaRep' con memoria dinamica con el tamaño suficiente para trabajar en el a forma de lista*/
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));
    
    /*Aqui creo e inicializo el contenido del puntero, con el valor NULL, y coloco la cantidad de elementos en 0, ya que se inicializa
    vacia la lista*/
    nueva_lista->valores = calloc(TAMANIO_MAXIMO, sizeof(TipoElemento));
    nueva_lista->cantidad = 0;
    
    /*Retorno este puntero a la estructura ya mencionada*/
    return nueva_lista;
}


/*Funcion que se encarga de Informar si la lista entregada esta vacia o tiene algun contenido. Lo hace devolviendo True en caso de 
que sea vacia o False en caso de que tenga contenido*/
bool l_es_vacia(Lista lista) {
    
    return (lista->cantidad == 0);
}


/*Funcion que se encarga de Informar si la lista entregada esta llena o no. Lo hace devolviendo True en caso de 
que este llena o False en caso de que no lo este*/
bool l_es_llena(Lista lista) {
    
    return (lista->cantidad == TAMANIO_MAXIMO);
}


/*Funcion que Informa la cantidad de elementos actuales que tiene la Lista entregada*/
int l_longitud(Lista lista) {
    
    return lista->cantidad;
}


/*Funcion que agrega en la ultima posicion de la lista entregada, si es que no esta llena, el elemento dado*/
bool l_agregar(Lista lista, TipoElemento elemento) {
    
    /*Corrobora de que la lista no sea llena, en caso de lo este, retornara falso, ya que no se pudo agregar el elemento en la lista*/
    if (l_es_llena(lista)) {
        return false;
    }

    /*Como la lista no estaba llena, agrega en la ultima posicion conocida de la lista, la cual esta vacia, el elemento entregado y
    suma 1 a la cantidad de elementos de la lista*/
    lista->valores[lista->cantidad] = elemento;
    lista->cantidad++;
    
    /*Retorna True, ya que si se pudo agregar el elemento en la lista*/
    return true;
}


/*Funcion que se encarga de borrar todos los elementos de la lista que coincidan con el valor 'clave' proporcionado*/
bool l_borrar(Lista lista, int clave) {
    
    /*Corrobora que la lista no este vacia, ya que si lo esta, no se puede borrar un elemento que no puede existir ya que no hay 
    elementos, retornando False*/
    if (l_es_vacia(lista)) {
        return false;
    }

    /*Como hay elementos en la lista, Pos se inicializa en 0 para que funcione a modo de iterador de las posiciones de la lista, y 
    creo la variable 'Borre' que va a indicar si se borro un numero o no*/
    int pos = 0;
    bool borre = false;

    /*Bucle que itera hasta que se llega al ultimo elemento de la lista*/
    while (pos < lista->cantidad) {
        
        /*Si coinciden los valores de la clave proporcionada con el de la clave del elemento, procedo a borrar el elemento*/
        if (lista->valores[pos]->clave == clave) {
            
            /*Coloco 'borre' en true, para indicar que si se borro aunque sea un elemento*/
            borre = true;
            
            /*Procedo a traves de este bucle a sobreescribir el elemento de encontrado, lo hago corriendo todos los elementos
            despues de el una posicion a la izquierda*/
            for (int i = pos; i < lista->cantidad - 1; i++) {
                
                lista->valores[i] = lista->valores[i + 1];
            }

            /*Resto 1 a la cantidad de elementos actuales de la lista*/
            lista->cantidad--;
        } 
        
        /*Si no coincidieron los valores, sigo con el siguiente*/
        else {
            pos++;
        }
    }

    /*Retorno la variable Borre para indicar si se borraron o no elementos en la lista*/
    return borre;
}


/*Funcion que se encarga de buscar un elemento de la lista, el cual coincida su clave con la clave proporcionada. Devuelve la primer
coincidencia*/
TipoElemento l_buscar(Lista lista, int clave) {
    
    /*Inicializo un iterador para recorrer la lista*/
    int pos = 0;
    
    /*Bucle que itera hasta que los valores de lista y cantidad sean iguales*/
    while (pos < lista->cantidad) {
        
        /*Si las claves coincidieron, devuelve el elementos de la lista*/
        if (lista->valores[pos]->clave == clave) {
            
            return lista->valores[pos];
        }

        /*Si no coincidieron, sigo con el siguiente elemento de la lista*/
        pos++;
    }

    /*Si no se encontro ningun elemento con esa clave, Retorno NULL para indicar que no existe tal elemento*/
    return NULL;
}


/*Funcion que inserta un elemento proporcionado, en la posicion 'pos' de la lista dada*/
bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    
    /*Compruebo que la lista dada no esta llena, si lo esta Retorna false, ya que no se puede agregar mas elementos a la lista*/
    if (l_es_llena(lista)) {
        return false;
    }

    /*Como la lista no esta llena, corroboro que la posicion 'pos' dada, no sea mayor a la cantidad de elementos que hay en la lista,
    en caso de que lo sea, simplemente agrego el elemento ern la ultima posicion*/
    if (pos > l_longitud(lista)) {
        
        /*Llamo a la funcion 'l_agregar' para que se encargue de agregar en la ultima posicion el elemento dado, en la lista*/
        l_agregar(lista, elemento);
        return false;
    }

    /*Como 'pos' no es mayor a la cantidad de elementos de la lista, este bucle se encarga de correr todos los elementos de la lista
    desde pos hasta el final de la misma, una posicion a la derecha, para habilitar el espacio en 'pos' para agregar el elemento*/
    for (int i = lista->cantidad; i >= pos && i > 0; i--) {
        
        lista->valores[i] = lista->valores[i - 1];
    }

    /*Agrego el elemento en la ubicacion querida de la lista. (es pos - 1, ya que el indice de la lista arranca en 0 y no en 1). Como
    ultimo paso, sumo 1 a la cantidad de elementos que posee la lista*/
    lista->valores[pos - 1] = elemento;
    lista->cantidad++;

    /*Retorna True ya que se pudo agregar el elemento*/
    return true;
}


/*Funcion que borra el elemento que se encuentra en la posicion 'pos' dada*/
bool l_eliminar(Lista lista, int pos) {
    
    /*Corroboro que la posicion no sea mayor a la cantidad de elementos actuales de la funcion, ya que si es mayor, no se puede eliminar
    un elemento que no hay en la lista. Retorno False*/
    if (pos > l_longitud(lista)) {
        
        return false;
    }
    
    /*Verifico que la 'pos' dada sea una posicion valida de la lista*/
    if (1 <= pos && pos <= l_longitud(lista)) {
        
        /*Este bucle se encarga de sobreescribir el dato de la posicion 'pos' para asi, moviendo todos los elementos que estan despues
        de pos, una posicion a la izquierda, de esta forma, elmino el elemento*/
        for (int i = pos - 1; i < lista->cantidad; i++) {
            
            lista->valores[i] = lista->valores[i + 1];
        }

        /*Resto 1 a la cantidad de elementos de la lista y retorno True, ya que se pudo eliminar el dato*/
        lista->cantidad--;
        return true;
    }

    /*Retorno False, ya que el dato no se pudo eliminar*/
    else {
	
        return false;
    }
}


/*Funcion que "recupera" el contenido del elemento de la posicion 'pos' de la lista*/
TipoElemento l_recuperar(Lista lista, int pos) {
    
    /*Si pos es mayor a la cantidad de elementos de la lista, retorna NULL, ya que no hay nada en esa posicion*/
    if (pos > l_longitud(lista)) {
        
        return NULL;
    }

    /*Si no es mayor, Retorna el contenido del elemento que esta en la pos pedida*/
    return lista->valores[pos - 1];
}


/*Funcion que se encarga de imprimir el contenido de la clave de la lista por pantalla*/
void l_mostrar(Lista lista) {
    
    printf("Contenido de la lista: ");
    
    for (int i = 0; i < lista->cantidad; i++) {
        
        printf("%d ", lista->valores[i]->clave);
    }

    printf("\n");
}


/*Funcion que crea un iterador que es un puntero a 'IteradorRep' para poder hacer el recorrido de las listas*/
Iterador iterador(Lista lista) {
    
    /*Crea el iterador con memoria dinamica, permitiendo asi, poder iterar en una lista*/
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    
    /*Crea y carga las variables del iterador de la lista, donde la primer variable es la lista y el segundo su posicion actual*/
    iter->lista = lista;
    iter->posicionActual = 0;
    
    /*Retorna el iterador recien creado*/
    return iter;
}


/*Funcion que verifica si para el elemento actual de la lista, se encuentra otro elemento despues de él. Devuelve True si es asi y 
False si no lo es*/
bool hay_siguiente(Iterador iterador) {
    
    return iterador->posicionActual < iterador->lista->cantidad;
}


/*Funcion que retorna el proximo elemento que hay en la lista*/
TipoElemento siguiente(Iterador iterador) {
    
    return iterador->lista->valores[iterador->posicionActual++];
}
