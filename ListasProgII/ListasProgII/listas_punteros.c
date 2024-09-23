#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

/*Cantidad maxima de elementos que va a poder tener la lista*/
static const int TAMANIO_MAXIMO = 100;


/*Estructura de Nodo, la cual funciona a forma de enlazador, en la que en su interior tiene el puntero a 'TipoElementoRep', en el que
tiene una clave y un valor; y luego otra estructura de tipo Nodo, la cual apunta al siguiente nodo de la lista, de esta forma, no
pierdo el contenido de los siguientes elementos*/
struct Nodo {

    /*Puntero al tipo de dato TipoElementoRep, con sus datos*/
    TipoElemento datos;

    /*Puntero a la direccion de memoria del siguiente elemento de la lista. Seria como un iterador. Permite la definicion recursiva
    de elementos de una lista*/
    struct Nodo *siguiente;
};

/*Estructura de ListaRep, que toma el puntero a la direccion de memoria del primer nodo de la lista*/
struct ListaRep {

    /*Puntero que apunta al primer nodo de la lista, y es el unico que debemos saber su ubicacion*/
    struct Nodo *inicio;

    /*Cantidad de nodos que posee la lista actualmente*/
    int cantidad;
};


/*Estructura del IteradorRep, que va a permitir encontrar todos los elementos de la lista de nodos*/
struct IteradorRep {

    /*Puntero al nodo actual en el que estamos parado, (Generalmente siempre se tiene el primer nodo de la lista, ya que con sus datos
    obtenemos los siguientes)*/
    struct Nodo *posicionActual;
};


/*Funcion que se encarga de crear la lista de Nodos de TipoElemento*/
Lista l_crear() {

    /*Crea la estructura Nueva_Lista con memoria dinamica con el tamaño de ListaRep, para trabajar a forma de lista con Nodos*/
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));

    /*Crea e inicializa la lista con el primer elemento apuntando a NULL, haciendo referencia a que no existe ningun elemento en la
    lista todavia, y se inicializa la cantidad en 0*/
    nueva_lista->inicio = NULL;
    nueva_lista->cantidad = 0;

    /*Retorna la Estructura Nueva_Lista*/
    return nueva_lista;
}


/*Funcion que verifica si la lista esta vacia. En caso de que lo este, Retorna True, caso contrario, Retorna False*/
bool l_es_vacia(Lista lista) {

    return (lista->cantidad == 0);
}


/*Funcion que verifica si la lista esta llena. En caso de que lo este, Retorna True, caso contrario, Retorna False*/
bool l_es_llena(Lista lista) {

    return (lista->cantidad == TAMANIO_MAXIMO);
}


/*Funcion que Retorna el tamaño actual de la lista*/
int l_longitud(Lista lista) {

    return lista->cantidad;
}

/*Funcion que se encarga de agregar un nuevo Nodo al final de la lista*/
bool l_agregar(Lista lista, TipoElemento elemento) {

    /*Si la lista esta llena, Retorna False, ya que no se puede agregar mas Nodos con elementos a la lista*/
    if (l_es_llena(lista)) {

        return false;
    }

    /*Creo el nuevo Nodo con memoria dinamica*/
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));

    /*Inicializo las variables que tendra el nuevo Nodo. Datos contendra el elemento de TipoElementoRep que paso; y siguiente apuntara a
    NULL ya que de momento no hay otro Nodo despues de este nuevo Nodo*/
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;

    /*En caso de que la lista este vacia, coloca el nuevo Nodo en la primer posicion*/
    if (lista->inicio == NULL) {

        lista->inicio = nuevo_nodo;
    }

    /*Como no es el primer elemento de la lista, tendremos que ir recorriendo la lista de Nodos hasta llegar a aquell Nodo que apunte a
    NULL, el cual sera el ultimo Nodo existente hasta ahora*/
    else {

        /*Creo una estructura temporal que trabajara a forma de iterador para poder ir recorriendo el array de Nodos en busca
        del que apunta a NULL*/
        struct Nodo *temp2 = lista->inicio;

        /*Bucle que se encarga de llegar hasta el final de la lista de Nodos, y para poder encontrar el que apunta a NULL*/
        while (temp2->siguiente != NULL) {

            temp2 = temp2->siguiente;
        }

        /*Una vez encontrado el Nodo que apunta a NULL, le asignamos a su variable 'siguiente', el Nuevo Nodo que acabo de crear, para
        poder de esta forma, conectarlo al final de la lista y que se quede como nuevo ultimo elemento de la misma*/
        temp2->siguiente = nuevo_nodo;
    }

    /*Aumento en 1 la cantidad de elementos que posee actualmente la lista y devuelvo True, ya que se pudo agregar un Nuevo Nodo*/
    lista->cantidad++;
    return true;
}


/*Funcion que se encarga de borrar todos los Nodos que tengan la misma clave, que la clave proporcionada por parametro en la funcion*/
bool l_borrar(Lista lista, int clave) {

    /*Verifico si la lista esta vacia. Si es vacia, Retorno False, indicando que no se pueden borrar elementos de una lista vacia*/
    if (l_es_vacia(lista)) {

        return false;
    }

    /*Creo esta variable para indicar si se pudieron borrar Nodos*/
    bool borre = false;

    /*Creo un Nodo que sera el puntero al nodo lista->inicio, para no perder los Nodos siguientes*/
    struct Nodo *actual = lista->inicio;

    /*Este bucle se encarga de ver si el primer Nodo de la lista, tiene la misma clave que la que se quiere borrar*/
    while (actual != NULL && actual->datos->clave == clave) {

        /*La lista->inicio pasara a apuntar al Nodo siguiente del primer Nodo (al segundo en este caso), y procede a borrar el que era
        el primer Nodo*/
        lista->inicio = actual->siguiente;
        free(actual);

        /*descuento 1 a la cantidad de Nodos que habia en la lista*/
        lista->cantidad--;

        /*Coloco en actual, el lista->inicio, para volver a corroborar si el inicio de la lista es igual a la clave. Ademas, coloco en
        'borre' True, ya que se logro eliminar aunque sea 1 elemento*/
        actual = lista->inicio;
        borre = true;
    }

    /*Este bucle se encarga de borrar los elementos que no sean el inicio de la lista, si es que tienen igualdad con
    respecto a la clave*/
    while (actual != NULL && actual->siguiente != NULL) {

        /*Si el Nodo siguiente del actual Nodo, tiene como clave, la misma que se desea borrar, procede a hacerlo*/
        if (actual->siguiente->datos->clave == clave) {

            /*Creo un Nodo temporal que contendra el puntero de la direccion de memoria de actual->siguiente*/
            struct Nodo *temp = actual->siguiente;

            /*ahora le asigno a actual->siguiente, el Nodo siguiente, de aquell que quiero borrar, para asi no perder todos los Nodos
            que estan despues del que quiero borrar*/
            actual->siguiente = temp->siguiente;

            /*borro el nodo*/
            free(temp);


            /*Decremento la cantidad de Nodos que posee la lista en 1 y coloco en True la variable borre, declarando que puede borrar un
            Nodo*/
            lista->cantidad--;
            borre = true;
        }

        /*Si no coincidieron las claves, paso al siguiente Nodo de la lista para corroborar*/
        else {

            actual = actual->siguiente;
        }
    }

    /*Retorno la variable borre indicando si pude o no borrar Nodos*/
    return borre;
}


/*Funcion que se encarga de devolver la primer coincidencia que se encuentre en la lista de Nodos, con respecto a
la clave proporcionada*/
TipoElemento l_buscar(Lista lista, int clave) {

    /*Se crea un Interador para poder recorrer la lista de Nodos, a forma de puntero*/
    struct Nodo *actual = lista->inicio;

    /*Bucle que recorre todos los Nodos hasta llegar al que apunta a NULL*/
    while (actual != NULL) {

        /*Si se encuentra una coincidencia, se retorna el TipoElemento con los datos*/
        if (actual->datos->clave == clave) {

            return actual->datos;
        }

        /*Como no hubo coincidencia, pasa al siguiente Nodo*/
        actual = actual->siguiente;
    }

    /*Si no se encontraron coincidencias, se Retorna NULL como forma de informar que no hay coincidencias*/
    return NULL;
}


/*Funcion que se encarga de Insertar un nuevo Nodo en la pos dada, en la lista de Nodos*/
bool l_insertar(Lista lista, TipoElemento elemento, int pos) {

    /*Si la lista de Nodos esta llena, se Retorna False, ya que no se pueden agregar mas Nodos a la misma*/
    if (l_es_llena(lista)) {

        return false;
    }

    /*Si la pos dada, es mas grande que la cantidad de Nodos que hay en la lista, se llama a la funcion l_agregar para que agregue
    el nuevo Nodo en la ultima poscion de la lista de Nodos, y se Retorna False, ya que no existe la posicion 'pos' actualmente en la
    lista*/
    if (pos > l_longitud(lista)) {

        l_agregar(lista, elemento);
        return false;
    }

    /*Creo el Nuevo Nodo con memoria dinamica*/
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));

    /*Asigno en el nuevo Nodo los valores correspondientes que llevara, que actualmente, el siguiente, Apuntara a NULL*/
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = NULL;


    /*Si se quiere agregar el Nuevo Nodo en la primer posicion de la lista, se cambia el contenido de Siguiente por el contenido
    apuntado de lista->inicio, para conectar toda la lista existente como siguiente del actual Nodo, y luego, se cambia el contenido
    de lista->inicio por el Nuevo Nodo, para ya tener la lista correctamente estructurada*/
    if (pos == 1) {

        nuevo_nodo->siguiente = lista->inicio;
        lista->inicio = nuevo_nodo;
    }

    /*Si no se quiere poner en la primer posicion*/
    else {

        /*Se crea un Nodo Temporal con el valor de la lista->inicio, para funcionar a forma de iterador y de esta forma, encontrar
        la posicion en la cual se desea colocar el Nuevo Nodo y tener los datos de ese Nodo en particular para no perder el
        contenido ni los siguientes Nodos*/
        struct Nodo *temp2 = lista->inicio;

        /*Bucle que se encarga de llegar al Nodo Anterior del que se requiere, para poder luego, anexar el Nuevo Nodo en el
        apuntador 'siguiente' de este, de esta forma, logrando colocar el Nuevo Nodo en la posicion deseada y en el apuntador
        'siguiente' del Nuevo Nodo, colocar el que estaba en la posicion 'pos'*/
        for (int i = 0; i < pos - 2; i++) {

            temp2 = temp2->siguiente;
        }

        /*Anexo todos los Nodos que estan despues del Nodo que se encuentra en la 'pos' Anterior a la deseada, para no perderlos*/
        nuevo_nodo->siguiente = temp2->siguiente;

        /*Anexo en la variable 'siguiente' del Nodo que se encuentra en la 'pos' Anterior, todos los Nodos de la lista, y con el Nuevo
        Nodo en la posicion correcta y deseada*/
        temp2->siguiente = nuevo_nodo;
    }

    /*Incremento en 1 la cantidad de Nodos existentes en la lista y Retorno True, ya que se logro insertar el Nuevo Nodo*/
    lista->cantidad++;
    return true;
}


/*Funcion que elimina el Nodo que se encuentre en la posicion 'pos' de la lista de Nodos*/
bool l_eliminar(Lista lista, int pos) {

    /*Verifico que la lista no este vacia, Si lo esta, Retorno False*/
    if (l_es_vacia(lista)) {

        return false;
    }

    /*Creo la variable que informara si se borro o no el Nodo*/
    bool borre = false;

    /*Creo un iterador para poder ir recorriendo la lista de Nodos, a forma de puntero*/
    struct Nodo *actual = lista->inicio;

    /*Como la lista no es vacia, corroboro que pos este dentro de los parametros correctos*/
    if (1 <= pos && pos <= l_longitud(lista)) {

        /*Si pos es el inicio de la lista, anexo el lista->inicio con el Nodo siguiente, para luego borrar el ex
        primer Nodo de la misma*/
        if (pos == 1) {

            lista->inicio = actual->siguiente;
            free(actual);
            borre = true;
        }

        /*Si no es el primer Nodo el que marca pos, se recorren los Nodos, hasta llegar al Nodo anterior al deseado*/
        else {

            for (int i = 0; i < pos - 2; i++) {

                actual = actual->siguiente;
            }

            /*Creo un Nodo temporal, para alvergar la informacion del Nodo querido*/
            struct Nodo *temp = actual->siguiente;

            /*Anexo el Nodo anterior al querido, con el Nodo siguiente al querido, para no perder los Nodos siguientes al que
            quiero borrar, y borro el Nodo que esta en la posicion Pos*/
            actual->siguiente = temp->siguiente;
            free(temp);

            /*coloco en True borre, indicando que pude realizar la operacion*/
            borre = true;
        }

        /*Descuento 1 a la cantidad de Nodos que posee la lista actualmente*/
        lista->cantidad--;
    }

    /*Retorno Borre para indicar lo que paso*/
    return borre;
}


/*Funcion que 'Recupera' el contenido del nodo que esta en la posicion 'pos' de la lista de nodos*/
TipoElemento l_recuperar(Lista lista, int pos) {

    /*Verificamos que la pos dada no es mayor a la cantidad de elementos de la lista. Si es asi, Retorna NULL, ya que no existe ese
    elemento buscado*/
    if (pos > l_longitud(lista)) {

        return NULL;
    }

    /*Como pos no es mayor a la cantidad de elementos, creo una variable temporal, la cual apuntara al inicio de la lista*/
    struct Nodo *temp2 = lista->inicio;

    /*En este bucle, se encarga de recorrer la lista desde el inicio, hasta la posicion deseada, a traves de los punteros 'siguiente'
    de cada uno de los nodos que hay en la lista*/
    for (int i = 0; i < pos - 1; i++) {

        /*voy asignando el nodo siguiente con cada iteracion hasta llegar al deseado*/
        temp2 = temp2->siguiente;
    }

    /*Devuelve el contenido TipoElemento del Nodo que estaba en la posicion 'pos'*/
    return temp2->datos;
}


/*Funcion que muestra las claves de la lista de Nodos*/
void l_mostrar(Lista lista) {

    struct Nodo *temp2 = lista->inicio;

    printf("Contenido de la lista: ");

    while (temp2 != NULL) {

        printf("%d ", temp2->datos->clave);
        temp2 = temp2->siguiente;
    }

    printf("\n");
}


/*Funcion que crea un iterador que es un puntero a IteradorRep para poder recorrer la lista*/
Iterador iterador(Lista lista) {

    /*Creo el iterador con memoria dinamica*/
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));

    /*Le asigno el puntero al inicio de la lista*/
    iter->posicionActual = lista->inicio;

    /*Retorno el iterador*/
    return iter;
}


/*Funcion que verifica si hay un siguiente en la lista*/
bool hay_siguiente(Iterador iterador) {

    return (iterador->posicionActual != NULL);
}


/*Funcion que retorna el siguiente Nodo*/
TipoElemento siguiente(Iterador iterador) {

    /*Creo un tipoelemento para guardar valores*/
    TipoElemento actual = iterador->posicionActual->datos;

    /*coloco el iterador en el siguiente Nodo*/
    iterador->posicionActual = iterador->posicionActual->siguiente;

    /*Retorno el tipoelemento*/
    return actual;
}
