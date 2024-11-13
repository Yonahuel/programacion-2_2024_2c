#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
 
/*Cantidad maxima de elementos que tendra la lista*/
static const int TAMANIO_MAXIMO = 2000;

/*Este sera nuestro apuntador, el cual simula el NULL a traves del '-1' ya que es un casillero no valido para un array*/
static const int NULO = -1;


/*Estructura Nodo, que funciona como enlazador de casilleros del array/lista de nodos que vamos a manejar, el cual contiene dentro a la 
estructura 'Tipoelemento' (clave y valor); y a 'siguiente' que contendra un int, que hace referencia al casillero siguiente en termino
de posiicion*/
struct Nodo {
    
    /*Puntero a la estructura 'TipoElementoRep', que contiene un 'int clave' y un 'void* valor'*/
    TipoElemento datos;
    
    /*A diferencia de 'lista_punteros', aca se usa un int para enlazar casilleros, ya que no se usan punteros*/
    int siguiente;
};


/*Estructura de la lista, la cual contendra el arreglo de nodos que utilizaremos a forma de casilleros de elementos*/
struct ListaRep {
    
    /*Cursor es un puntero a la estructura Nodo, que va a simular a la memoria de la lista. Basicamente, Cursor es el arreglo de nodos*/
    struct Nodo *cursor;
    
    /*Inicio es el apuntador al inicio de la lista. Contiene la posicion del primer elemento de la lista de nodos*/
    int inicio;
    
    /*Libre es nuestra variable que indica a partir de que posicion no hay mas elementos en la lista, osea, si el elemento 5 de la
    lista no contiene un elemento, libre sera 5, ya que es el primer elemento que esta libre de la lista*/
    int libre;
    
    /*Cantidad actual de Nodos que posee la lista actualmente*/
    int cantidad;
};


/*Estructura del IteradorRep, que va a contener una copia de la lista de nodos, para ir pasando de nodo en nodo*/
struct IteradorRep {
    
    /*Copia de la lista de nodos*/
    Lista lista;
    
    /*Contiene la posicion del nodo actual en el que estamos*/
    int posicionActual;
};


/*Funcion que se encarga de crear la lista de Nodos de TipoElemento*/
Lista l_crear() {
    
    /*Defino el iterador del bucle for para cargar cada casillero de la lista manualmente*/
    int i = 0;

    /*Creo la lista de nodos con memoria dinamica, con el tamaño suficiente para albergar la estructura ListaRep*/
    Lista nueva_lista = (Lista) malloc(sizeof(struct ListaRep));

    /*Inicializo todos los elementos Nodos con memoria dinamica y en 0 del cursor; A su vez, coloco en 0 la cantidad de elementos que
    posee la lista, y inicio se le corresponde la variable NULO, ya que no hay elementos en la lista actualmente. Una vez que se agregue
    un elemento, el NULO sera el siguiente elemento y inicio contendra la posicion del casillero correspondiente*/
    nueva_lista->cursor = calloc(TAMANIO_MAXIMO, sizeof(struct Nodo));
    nueva_lista->cantidad = 0;
    nueva_lista->inicio = NULO;

    /*Bucle que coloca en la variable de cursor(osea, el apuntador a los Nodos), en siguiente, la posicion ordinal del siguiente 
    casillero, encadenando los nodos libres, osea todos.*/
    for (i=0; i<=(TAMANIO_MAXIMO-2); i++) {
        
        nueva_lista->cursor[i].siguiente = i+1;
    }

    /*Declaro el apuntador al primer casillero de nodos libre, */
    nueva_lista->libre = 0;
    
    /*Declaro al ultimo nodo con NULO, indicando que ya no hay mas casilleros luego de él*/
    nueva_lista->cursor[TAMANIO_MAXIMO-1].siguiente = NULO;

    /*retorno la lista recien creada e inicializada para poder trabajar luego en ella*/
    return nueva_lista;
}


/*Funcion que verifica si la lista esta vacia. En caso de que lo este, Retorna True, caso contrario, Retorna False*/
bool l_es_vacia(Lista lista) {
    
    return lista->cantidad == 0;
}


/*Funcion que verifica si la lista esta llena. En caso de que lo este, Retorna True, caso contrario, Retorna False*/
bool l_es_llena(Lista lista) {
    
    return (lista->cantidad == TAMANIO_MAXIMO);
}


/*Funcion que Retorna el tamaño actual de la lista*/
int l_longitud(Lista lista) {
  
    return lista->cantidad;
}


/*Funcion que se encarga de agregar un nuevo Nodo en la posicion que indica libre*/
bool l_agregar(Lista lista, TipoElemento elemento) {
    
    /*Variables con las que iterare dentro de la lista*/
    int p;
    int q;
    int anteq;

    /*Verifico si la lista no esta llena para poedr agregar un elemento. En caso que lo este, Retorno false, indicando que no se puede
    agregar otro elemento*/
    if (l_es_llena(lista)) {
      
        return false;
    }

    /*P sera la posicion del primer casillero libre*/
    p = lista->libre;
    
    /*Asigno a libre, el casillero siguiente a p*/
    lista->libre = lista->cursor[p].siguiente;

    /*Coloco en el casillero dado por p, los datos a ingresar, y como no hay siguiente elementos actualmente, en siguiente coloco NULO*/
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    /*Verifico si la lista estaba vacia, en caso de que lo sea el inicio de la lista, quedara ocupado por la posicion de la variable p 
    recien creada*/
    if (l_es_vacia(lista)) {
        
        lista->inicio = p;
    } 
    
    /*Si no lo era*/
    else {
        
        /*Inicializo a q en el inicio de la lista que hay, osea, el correspondiente primer casillero de la lista*/
        q = lista->inicio;
        
        /*Me encargo de llegar al ultimo casillero de la lista que esta ocupado, para poder enlazarlos*/
        while (q != NULO) {
            
            anteq = q;  
            q = lista->cursor[q].siguiente;
        }

        /*Como llegue al ultimo casillero ocupado de la lista, coloco a siguiente apuntando a la posicion p, ya que es el nuevo elemento*/
        lista->cursor[anteq].siguiente = p;
    }

    /*Incremento la cantidad de elementos que hay en la lista actualmente y retorno true ya que se pudo añadir el elemento*/
    lista->cantidad++;
    return true;
}


/*Funcion que se encarga de borrar todos los casilleros que tengan la misma clave, que la clave proporcionada por parametro en la funcion*/
bool l_borrar(Lista lista, int clave) {
    
    /*Corroboro que la lista no este vacia, en caso de que lo este, retorno falso  ya que no se pueden borrar elementos que no hay*/
    if (l_es_vacia(lista)) {
        
        return false;
    }

    /*Inicializo las variables que usare: indicado de borrado en falso; un q; y un p que sera la posicion del casillero inicial 
    de la lista */
    bool borre = false;
    int q;
    int p = lista->inicio;

    /*Mientras p no llegue a NULO, y el actual casillero(el inicial) sea igual a la clave*/
    while ((p != NULO) && (lista->cursor[p].datos->clave == clave)) {
        
        /*q sera una copia de la ubicacion del casillero actual*/
        q = p;
        
        /*cambio la ubicacion del inicio de la lista con el siguiente*/
        lista->inicio = lista->cursor[p].siguiente;
        
        /*Cambio el apuntador del casillero a libre*/
        lista->cursor[q].siguiente = lista->libre;
        lista->libre = q;

        /*Disminuyo en uno la cantidad de elementos de la lista y coloco en p el nuevo inicio de la lista. Ademas coloco en borre true*/
        lista->cantidad--;
        p = lista->inicio;
        borre = true;
    }

    /*defino una nueva variable, y en p coloco el inicio actual de la lista*/
    int qant;
    p = lista->inicio;
    
    /*con este bucle recorro todos los casilleros ocupados en busca de aquel a borrar*/
    while (p != NULO) {
        
        /*Si las claves son iguales*/
        if (lista->cursor[p].datos->clave == clave) {
            
            /*q guarda la posicion de p, y piso la variable siguiente del casillero qant, con el siguiente de la posicion p, 
            para pisar el casillero a borrar*/
            q = p;
            lista->cursor[qant].siguiente = lista->cursor[p].siguiente;
            
            /*coloco en el siguiente de la posicion q, el nuevo libre*/
            lista->cursor[q].siguiente = lista->libre;
            lista->libre = q;
            
            /*resto 1 a la lista*/
            lista->cantidad--;
            
            /*y sera igual a qant y borre se pone en true*/
            p = qant;  
            borre = true;
        } 
        
        /*Si no son iguales, simplemente pongo en qant el valor de p y p pasa a tener la posicion del siguiente elemento*/
        else {
            qant = p;  
            p = lista->cursor[p].siguiente;
        }
    }

    /*retorno la variable borre*/
    return borre;
}


/*Funcion que se encarga de devolver la primer coincidencia que se encuentre en la lista de Nodos, con respecto a 
la clave proporcionada*/
TipoElemento l_buscar(Lista lista, int clave) {
    
    /*Coloco en p el inicio de la lista*/
    int p = lista->inicio;
    
    /*Recorro todos los casilleros hasta llegar al NULO, osea, el que no contiene nada*/
    while (p != NULO) {
        
        /*Si las claves son iguales, Devuelvo la primer coincidencia, mejor dicho, el nodo actual*/
        if (lista->cursor[p].datos->clave == clave) {
            
            return lista->cursor[p].datos;
        }

        /*Sino coincidieron, sigo con el siguiente*/
        p = lista->cursor[p].siguiente;
    }

    /*Si no hubo coincidencias, retorno null a forma de informar que no las hubo*/
    return NULL;
}


/*Funcion que se encarga de Insertar un nuevo Nodo en el casillero que esta en la pos dada, en la lista de Nodos*/
bool l_insertar(Lista lista, TipoElemento elemento, int pos) {
    
    /*Verifico que la posicion entregada no sea mayor a la cantidad de elementos actuales que hay en la lista. Si es mayor, lo agrego en
    la ultima posicion y retorno false, dando a entender que no se pudo agregar en la posicion querida*/
    if (pos > l_longitud(lista)) {
        
        l_agregar(lista, elemento);
        return false;
    }

    /*Agarro el casillero libre que hay en la lista y le asigno los valores que quiero insertar en la misma*/
    int p = lista->libre;
    lista->libre = lista->cursor[p].siguiente;
    lista->cursor[p].datos = elemento;
    lista->cursor[p].siguiente = NULO;

    /*Si pos es el inicio, al casillero lo transformo en el primer elemento de la lista*/
    if (pos == 1) {
        
        lista->cursor[p].siguiente = lista->inicio;
        lista->inicio = p;
    } 
    
    /*sino es el primer elemento*/
    else {

        /*iterador que usare para llegar a la posicion requerida dentro de la lista*/
        int temp2 = lista->inicio;
        
        /*Recorro los casilleros hasta llegar al anterior querido*/
        for (int i = 0; i < pos - 2; i++) {
            
            temp2 = lista->cursor[temp2].siguiente;
        }

        /*una vez llegado a la posicion anterior a la querida, enlazo en p(casillero nuevo) el siguiente(el elemento que estaba en 
        la posicion querida), y en temp2, en su siguiente, enlazo a p, asi queda todo bien colocado*/
        lista->cursor[p].siguiente = lista->cursor[temp2].siguiente;
        lista->cursor[temp2].siguiente = p;
    }
    
    /*Sumo uno a la cantidad de elementos que posee la lista actual y retorno true, mostrando que se pudo añadir el elemento*/
    lista->cantidad++;
    return true;
}


/*Funcion que elimina el casillero que se encuentre en la posicion 'pos' de la lista de Nodos*/
bool l_eliminar(Lista lista, int pos) {
    
    /*declaro las variables que se usaran*/
    int p;
    bool borre = false;
    int actual = lista->inicio;

    /*Mientras que la posicion sea una posicion valida en la lista actual*/
    if (1 <= pos && pos <= l_longitud(lista)) {
        
        /*Si pos es igual al inicio de la lista, simplemente borro el inicio de la lista, pasando el lista->inicio al 
        siguiente casillero*/
        if (pos == 1) {
            
            p = actual;
            lista->inicio = lista->cursor[actual].siguiente;
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p;
	        
            borre = true;
        } 
        
        /*Si no es el primer elemento*/
        else {
            
            /*Hace el mismo trabajo que en la linea numero 286*/
            for (int i = 0; i < pos - 2; i++) {
            
                actual = lista->cursor[actual].siguiente;
            }
            
            
            p = lista->cursor[actual].siguiente;

            
            lista->cursor[actual].siguiente = lista->cursor[p].siguiente;

            
            lista->cursor[p].siguiente = lista->libre;
            lista->libre = p;
            borre = true;
        }

        /*Resto 1 a la cantidad de elementos que hay en la lista*/
        lista->cantidad--;
    }

    /*retorno borre*/
    return borre;
}


/*Funcion que 'Recupera' el contenido del casillero que esta en la posicion 'pos' de la lista de nodos*/
TipoElemento l_recuperar(Lista lista, int pos) {
    
    int temp2 = lista->inicio;

    for (int i = 0; i < pos - 1; i++) {
      
        temp2 = lista->cursor[temp2].siguiente;
    }

    return lista->cursor[temp2].datos;
}


/*Funcion que muestra las claves de la lista de Nodos*/
void l_mostrar(Lista lista) {
    
    int temp2 = lista->inicio;
    
    printf("Contenido de la lista: ");
    
    /**/
    while (temp2 != NULO) {
    
        printf("%d ", lista->cursor[temp2].datos->clave);
        temp2 = lista->cursor[temp2].siguiente;
    }
    
    printf("\n");
}


/*Funcion que crea un iterador que es un puntero a IteradorRep para poder recorrer la lista*/
Iterador iterador(Lista lista) {
    
    /*Creo el iterador con memoria dinamica*/
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    
    /*creo la copia de la lista*/
    iter->lista = lista;
    
    /*Le asigno el puntero al inicio de la lista*/
    iter->posicionActual = lista->inicio;
    
    /*Retorno el iterador*/
    return iter;
}


/*Funcion que verifica si hay un siguiente en la lista*/
bool hay_siguiente(Iterador iterador) {
    
    return (iterador->posicionActual != NULO);
}


/*Funcion que retorna el siguiente casillero*/
TipoElemento siguiente(Iterador iterador) {
    
    /*Creo un tipoelemento para guardar valores*/
    TipoElemento actual = iterador->lista->cursor[iterador->posicionActual].datos;
    
    /*coloco el iterador en el siguiente Nodo*/
    iterador->posicionActual = iterador->lista->cursor[iterador->posicionActual].siguiente;
    
    /*Retorno el tipoelemento*/
    return actual;
}

