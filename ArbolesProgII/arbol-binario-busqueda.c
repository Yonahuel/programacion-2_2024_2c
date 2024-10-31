#include "arbol-binario-busqueda.h"
#include "nodo.h"

/*Defino la cantidad maxima de Nodos/elementos que podra tener el Arbol Binario*/
static const int TAMANIO_MAXIMO = 100;


/*Estructura de ArbolBinarioBusquedaRep que contiene el Nodo Padre/raiz y la cantidad de elementos que tiene el Arbol actualmente, los 
cuales los Nodos estan ordenados(a la izquierda mas chicos, a la derecha mas grandes)*/
struct ArbolBinarioBusquedaRep{
    
    NodoArbol raiz; //Nodo Raiz/Padre de todo el Arbol de Busqueda Binaria

    int cantidad_elementos; //Cantidad de elementos que posee el Arbol de Busqueda Binaria
};


/*Funcion que se encarga de crear con memoria dinamica la estructura principal del Arbol de Busqueda Binaria*/
ArbolBinarioBusqueda abb_crear(){

    /*Creo un puntero de tipo Nodo con memoria dinamica con el tamaño para bancar la estructura de ArbolBinarioBusquedaRep*/
    ArbolBinarioBusqueda nuevo_arbol = (ArbolBinarioBusqueda) malloc(sizeof(struct ArbolBinarioBusquedaRep));

    /*Coloco los datos en NULL y en 0, ya que se crea vacio, sin Nodos dentro*/
    nuevo_arbol->raiz = NULL;
    nuevo_arbol->cantidad_elementos = 0;

    /*Retorno esa Nueva estructura para poder empezar a trabajar en ella*/
    return nuevo_arbol;
}


/*Funcion que se encarga de informar si el Arbol de Busqueda Binaria esta vacio o tiene ya una raiz, retornando True en 
caso de que lo sea y False en caso de que ya tenga un Nodo Raiz/Padre*/
bool abb_es_vacio(ArbolBinarioBusqueda a){

    return (a->raiz == NULL);
}


/*Funcion que se encarga de informar si el Arbol de Busqueda Binaria esta lleno, retornando True en caso de que lo este y 
False en caso de que no lo este*/
bool abb_es_lleno(ArbolBinarioBusqueda a){
    
    return (a->cantidad_elementos == TAMANIO_MAXIMO);
};


/*Funcion que se encarga de informar la cantidad de Nodos/Elementos que posee actualmente el Arbol de Busqueda Binaria*/
int abb_cantidad_elementos(ArbolBinarioBusqueda a){

    return a->cantidad_elementos;
}


/*Funcion que se encarga de verificar si el Nodo pasado como parametro es NULL o tiene elementos, retornando True en caso 
de que este vacio y False en caso de que no lo este*/
bool abb_es_rama_nula(NodoArbol pa){
    
    return pa == NULL;
}


/*Funcion que se encarga de retornar el Nodo Padre/raiz del Arbol de Busqueda Binaria*/
NodoArbol abb_raiz(ArbolBinarioBusqueda a){

    return a->raiz;
}


/*Funcion que se encarga de insertar de forma recursiva un Nuevo Nodo en el Arbol de Busqueda Binaria en la correcta 
posicion de la misma, haciendolo recorriendo el Arbol desde la Raiz hasta la posicion donde se debe insertar*/
NodoArbol abb_insertar_recursivo(ArbolBinarioBusqueda a, NodoArbol pa, TipoElemento te, bool *inserto){
    
    /*Caso Base: Si el Nodo actual apunta a NULL osea, que no posee ningun dato, se le procede a ingresar el TipoElemento que 
    posee los datos que se querian ingresar*/
    if(pa == NULL){

        /*Cambio inserto, haciendo alusion a que se pudo meter el Nuevo Nodo en el Arbol de Busqueda Binaria*/
	    *inserto = true;
        
        /*Sumo a 1 la cantidad de Elementos/Nodos que tiene actualmente el Arbol de Busqueda Binaria*/
        a->cantidad_elementos++;
        
        /*Creo el Nuevo Nodo donde ira el TipoElemento pasado por parametro*/
        NodoArbol nuevo_nodo = n_crear(te);
        
        /*En caso de que no halla Nodo Raiz/Padre, se lo coloca al nuevo Nodo como Raiz/Padre*/
        if(a->cantidad_elementos == 1){
           
            a->raiz = nuevo_nodo;
        }

        /*Retorno ese Nodo*/
        return nuevo_nodo;
    } 
    
    /*Caso General 1: Si el TipoElemento es mayor al elemento del Nodo actual, se lo buscara concectar a traves del camino del 
    Hijo Derecho del Nodo Actual*/
    else if(te->clave > pa->datos->clave){

        pa->hd = abb_insertar_recursivo(a, pa->hd, te, inserto);
    } 
    
    /*Caso General 2: Si el TipoElemento es menor al elemento del Nodo actual, se lo buscara concectar a traves del camino del 
    Hijo Izquierdo del Nodo Actual*/
    else if(te->clave < pa->datos->clave){

        pa->hi = abb_insertar_recursivo(a, pa->hi, te, inserto);
    }

    /*Procedo a retornar el Nuevo Nodo*/
    return pa;
}


/*Funcion que se encarga de insertar un elemento en el Arbol de Busqueda Binaria, de forma iterativa, en la posicion correcta 
donde deberia ir el elemento con respecto al valor del TipoElemento*/
bool abb_insertar(ArbolBinarioBusqueda a, TipoElemento te){
   
    /*Creo una variable bool para especificar que se pudo o no insertar el elemento de momento*/
    bool inserto = false;
   
    /*Si el Arbol de Busqueda Binaria de momento no posee un Nodo Padre/Raiz, el TipoElemento pasado como parametro sera 
    el nuevo Nodo Padre/Raiz*/
    if(abb_es_vacio(a)){
        
        /*Creo el nuevo Nodo y lo asigno al Arbol como Nodo Padre/Raiz*/
        a->raiz = n_crear(te);

        /*Sumo 1 a la cantidad de elementos que posee el Arbol y pongo en true la variable Inserto ya que se pudo agrega 
        el TipoElemento*/
        a->cantidad_elementos++;
	    inserto = true;
    } 
    
    
    else{

        /*Creo dos Nodos para poder empezar a recorrer el Arbol de Busqueda Binaria*/
        NodoArbol p, q;

        /*Le asigno a q el Nodo Padre/Raiz del Arbol*/
        q = abb_raiz(a);

        /*Utilizo un bucle para ir recorriendo el camino correcto de Nodos segun el TipoElemento pasado como parametro*/
        while(q != NULL){
            
            /*Copio el Nodo para luego hacer la insercion del elemento*/
            p = q;

            /*Si el dato del TipoElemento es mas chico que el dato del Nodo Actual, tomo el camino del Hijo Izquierdo, 
            asignandole el Hijo Izquierdo a q*/
            if(te->clave < q->datos->clave){
                
                q = q->hi;
            } 
            
            /*Si el dato del TipoElemento es mas grande que el dato del Nodo Actual, tomo el camino del Hijo Derecho, 
            asignandole el Hijo Derecho a q*/
            else if(te->clave > q->datos->clave){

                q = q->hd;
            } 

            /*Si el dato del TipoElemento es igual al dato de algun Nodo, termino el ciclo*/
            else{
             
                break;
            }
        }

        /*Una vez llegado al Nodo correcto donde tenemos que insertar el TipoElemento*/
        if (q == NULL){

            /*Coloco la variable en True ya que se va a insertar el mismo*/
            inserto = true;

            /*Creo el Nodo que ira en la posicion H.I o H.D del Nodo p, con los datos del TipoElemento pasado como parametro*/
            NodoArbol na = n_crear(te);

            /*Sumo 1 a la cantidad de Nodos/Elementos que posee el Arbol actualmente*/
            a->cantidad_elementos++;

            /*Si el Dato del TipoElemento es mayor al dato del Nodo Padre, se lo inserta en el Hijo Derecho*/
            if(p->datos->clave > te->clave){
              
                p->hi = na;
            } 
            
            /*Si el Dato del TipoElemento es menor al dato del Nodo Padre, se lo inserta en el Hijo Izquierdo*/
            else{
                
                p->hd = na;
            }
        } 
        
        /*Como El dato del TipoElemento ya existe en el Nodo, se procede a informar por pantalla*/
        else{
            
            printf("Clave Duplicada: %d \n", te->clave);
        }
    }

    /*Retorno el True si se pudo insertar o False en caso de que no se pudo insertar el TipoElemento*/
    return inserto;
//    abb_insertar_recursivo(a, abb_raiz(a), te, &inserto);
}


/*Funcion que se encarga de informar cual es el Nodo con el Elemento mas chico que esta dentro del Arbol de Busqueda Binaria*/
NodoArbol abb_buscar_minimo(NodoArbol nodoArbol){

    /*Creo una Copia del Nodo pasado por Parametro*/
    NodoArbol actual = nodoArbol;

    /*Voy recorriendo el camino que lleva al dato mas pequeño del Arbol atraves del bucle, haciendo asignaciones 
    del Nodo Hijo Izquierdo*/
    while(actual && actual->hi != NULL){
     
        actual = actual->hi;
    }

    /*Retorno el Nodo con el dato mas pequeño que se encontro en el Arbol de Busqueda Binaria*/
    return actual;
}


/*Funcion que se encarga de eliminar un elemento del Arbol de Busqueda Binaria de forma recursiva, anexando sus hijos si 
es que los tiene*/
NodoArbol abb_eliminar_recursivo(NodoArbol root, int claveABorrar, bool *borre){
    
    /*caso base: Si la raiz pasada no posee datos, osea el Arbol esta vacio, retorno esa misma Raiz/Nodo*/
    if(root == NULL){

        return root;
    }

    /*Caso General 1: Si clave a borrar es menor al dato que se encuentra en el Nodo Actual, procedo a seguir el camino del Hijo 
    Izquierdo en busca del numero*/
    if(claveABorrar < root->datos->clave){
     
        root->hi = abb_eliminar_recursivo(root->hi, claveABorrar, borre);
    }

    /*Caso General 2: Si clave a borrar es mayor al dato que se encuentra en el Nodo Actual, procedo a seguir el camino del Hijo 
    Derecho en busca del numero*/
    else if(claveABorrar > root->datos->clave){

        root->hd = abb_eliminar_recursivo(root->hd, claveABorrar, borre);
    }

    /*Caso General 3: Si la clave a borrar es igual al dato que se encuentra en el Nodo Actual, procedo a realizar el borrado del Nodo*/   
    else{

        /*Coloco en True la variable, ya que esta la clave a borrar*/
        (*borre) = true;

        /*Si el Nodo que tiene la clave a borrar no tiene Hijo Izquierdo*/
        if(root->hi == NULL){

            /*Guardo en un nuevo Nodo el Hijo Derecho del Nodo Actual donde se encontro la clave*/
            NodoArbol temp = root->hd;
            
            /*Libero el Nodo que posee la clave a borrar*/
            free(root);
            
            /*Retorno el nuevo Nodo con el hijo Derecho para no perder todo ese camino*/
            return temp;
        } 
        
        /*Si el Nodo que tiene la clave a borrar no tiene Hijo Derecho*/
        else if(root->hd == NULL){

            /*Guardo en un nuevo Nodo el Hijo Izquierdo del Nodo Actual donde se encontro la clave*/
            NodoArbol temp = root->hi;

            /*Libero el Nodo que posee la clave a borrar*/
            free(root);
            
            /*Retorno el nuevo Nodo con el hijo Izquierdo para no perder todo ese camino*/
            return temp;
        }

        /*Si el Nodo Actual que posee la clave a eliminar, posee tanto Hijo Izquierdo como Hijo Derecho, procedo a buscar el 
        Hijo Derecho mas chico*/
        NodoArbol temp = abb_buscar_minimo(root->hd);
        
        /*Cambio los datos del Nodo Actual que posee la clave a eliminar con el sucesor encontrado*/
        root->datos->clave = temp->datos->clave;
        root->datos->valor = temp->datos->valor;

        /*Procedo a eliminar la ruta del sucesor que fue copiado, para que no hallan 2 iguales*/
        root->hd = abb_eliminar_recursivo(root->hd, temp->datos->clave, borre);
    }

    /*Retorno el Nodo Actual, libre de la clave a eliminar*/
    return root;
}


/*Funcion que se encarga de Eliminar un Nodo/Elemento del Arbol de Busqueda Binaria*/
bool abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar){

    /*Creo una varaible para indicar si se elimino o no un elemento del Arbol*/
    bool borre = false;

    /**/
    TipoElemento te;
    NodoArbol N;
    te = n_recuperar(abb_raiz(a));

    // contemplo que si borra la raiz y no tiene hijos por la derecha el hijo izquierdo se convierte en raiz
    N = n_hijoderecho(abb_raiz(a));
    if ((N == NULL) && (te->clave == claveABorrar)) {
        printf("Hijo Derecho NULO \n");
        N = abb_raiz(a);
        a->raiz = n_hijoizquierdo(abb_raiz(a));
        free(N);
        return true;
    }

    // contemplo que si borra la raiz y no tiene hijos por la izquierda el hijo derecho se convierte en raiz
    N = n_hijoizquierdo(abb_raiz(a));
    if ((N == NULL) && (te->clave == claveABorrar)) {
        printf("Hijo Izquierdo NULO \n");
        N = abb_raiz(a);
        a->raiz = n_hijoderecho(abb_raiz(a));
        free(N);
        return true;
    }

    // Cualquier otro caso
    // Sino llamo al proceso recursivo
    abb_eliminar_recursivo(abb_raiz(a), claveABorrar, &borre);
    return borre;
}


/*Funcion que se encarga de informar si la clave pasada por parametro se encuentra o no en el Arbol de Busqueda Binaria*/
TipoElemento abb_buscar_recursivo(NodoArbol nodoArbol, int clave){
    
    /*Caso Base: Si el Nodo apunta a NULL, es porque en el Arbol no se encontro el elemento*/
    if (nodoArbol == NULL){
     
        return NULL;
    }

    /*Caso General 1: Si el dato del Nodo Actual es mas grande que el dato a buscar, procedo a seguir buscando por el camino del 
    Hijo Izquierdo*/
    else if (clave < nodoArbol->datos->clave){
     
        return abb_buscar_recursivo(nodoArbol->hi, clave);
    }

    /*Caso General 1: Si el dato del Nodo Actual es mas chico que el dato a buscar, procedo a seguir buscando por el camino del 
    Hijo Derecho*/
    else if (clave > nodoArbol->datos->clave){
     
        return abb_buscar_recursivo(nodoArbol->hd, clave);
    }

    /*Caso Base: si se encontro el Nodo que posee el dato a buscar, lo retorno*/
    else{
     
        return nodoArbol->datos;
    }
}

/*Hace lo mismo que la funcion de arriba*/
TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave) {
    
    return abb_buscar_recursivo(abb_raiz(a), clave);
}