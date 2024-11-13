#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_hash.h"
#include "listas.h"

/*Estructura de TipoRegistroTabla que seria cada casillero de la Tabla Hash, en donde se guardara cada elemento que se le sea ingresada
colocandole ocupado o no si este casillero tiene algo, y en caso de que si tenga ya elementos y se le genere una colision, se usara
una lista dinamica para guardar esas colisiones*/
struct TipoRegistroTabla{

    /*TipoElemento que guarda los datos del elemento*/
    TipoElemento tipo_elemento;

    /*Variable que indica si este casillero esta ocupado ya o no lo esta*/
    bool ocupado;

    /*Lista dinamica que guarda aquellos elementos que les toco el mismo casillero*/
    Lista lista_colisiones;
};


/*Estructura de TablaHashRep que contiene un puntero a una funcion que calcula la direccion donde iran cada elemento a guardar, 
la cantidad maxima de casilleros que podra contener la Tabla Hash y la propia Tabla Hash*/
struct TablaHashRep{

    /*Variable que guarda una funcion x que calcula el metodo con el que se eligen los casilleros de la Tabla Hash para guardar cosas*/
    int (*hash_function)(int);

    /*Variable que contiene la cantidad de casilleros que posee la Tabla Hash*/
    int capacidad;

    /*Aca colocamos un puntero a una estructura de TipoRegistroRep que funciona a forma de Tabla Hash*/
    struct TipoRegistroTabla *tabla;
};


/*Funcion que crea de forma dinamica la Tabla Hash para poder guardar contenido en ella*/
TablaHash th_crear(int capacidad, int (*hash_function)(int)){

    /*Creo la estructura Hash con memoria dinamica para poder almacenar todo el contenido dentro de ella*/
    TablaHash nueva_tabla_hash = (TablaHash) malloc(sizeof(struct TablaHashRep));

    /*Coloco la cantidad de casilleros que tendra esta*/
    nueva_tabla_hash->capacidad = capacidad;

    /*Coloco coloco un puntero a la funcion que contiene el metodo que calculara las posiciones*/
    nueva_tabla_hash->hash_function = hash_function;

    /*Creo la Tabla Hash con memoria dinamica para almacenar los datos*/
    nueva_tabla_hash->tabla = (struct TipoRegistroTabla *) malloc(capacidad * sizeof(struct TipoRegistroTabla));

    /*Empiezo a cargar todos los casilleros y dejarlos 'vacios' para poder cargar los datos*/
    for(int i = 0; i < capacidad; ++i){

        nueva_tabla_hash->tabla[i].tipo_elemento = NULL;
        nueva_tabla_hash->tabla[i].ocupado = false;
        nueva_tabla_hash->tabla[i].lista_colisiones = l_crear();
    }

    /*Retorno la Estructura recien creada*/
    return nueva_tabla_hash;
}


/*Funcion que se encarga de Insertar un elemento en la Tabla Hash*/
bool th_insertar(TablaHash th, TipoElemento te){

    /*Obtengo la posicion en donde voy a colocar el TipoElemento dentro de la Tabla Hash*/
    int pos = th->hash_function(te->clave);
    
    /*defino un puntero a la estructura TipoRegistroTabla en donde voy a almacenar el casillero que se encuentra en la posicion 'pos'
    para poder insertar el elemento posteriormente*/
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];

    /*Si el casillero de la Tabla Hash no esta ocupado, lo guardo directamente ahi y retorno*/    
    if(!registroTabla->ocupado){

        registroTabla->tipo_elemento = te;
        registroTabla->ocupado = true;
        return true;  
    } 
    
    else{

        /*Como no estaba libre el casillero se produce una colision, recorro la lista de colisiones para ver si ya se agrego el dato, 
        si no esta, lo cargo en la lista de colisiones en la posicion NULL*/
        if (registroTabla->tipo_elemento->clave != te->clave && l_buscar(registroTabla->lista_colisiones, te->clave) == NULL) {
            
            return l_agregar(registroTabla->lista_colisiones, te);
        }
    }

    /*Si ya estaba en la lista de colisiones o ya estaba cargado, retorno False, haciendo alusion a que el elemento ya esta cargado*/
    return false;
}


/*Funcion nque se encarga de eliminar un elemento que esta guardado dentro de la Tabla Hash*/
bool th_eliminar(TablaHash th, int clave){

    /*Obtengo la posicion donde deberia estar el elemento a borrar dentro de la Tabla Hash*/
    int pos = th->hash_function(clave);

    /*defino un puntero a la estructura TipoRegistroTabla en donde voy a almacenar el casillero que se encuentra en la posicion 'pos'
    para poder borrar el elemento posteriormente*/
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];

    /*Si el casillero esta ocupado*/
    if(registroTabla->ocupado){

        /*Si el dato se encuentra fuera de la lista de colisiones*/
        if(registroTabla->tipo_elemento->clave == clave) {
            
            /*Si la Lista de colisiones no esta vacia*/
            if(!l_es_vacia(registroTabla->lista_colisiones)){

                /*Piso el dato que se encuentra fuera de la lista, con el primer elemento de la lista de colisiones*/
                registroTabla->tipo_elemento = l_recuperar(registroTabla->lista_colisiones, 1);

                /*elimino el primer elemento de la lista de colisiones*/
                return l_eliminar(registroTabla->lista_colisiones, 1);
            } 
            
            /*Como la lista no tenia elementos*/
            else{

                /*simplemente pongo sus valores en NULL y en desocupado*/
                registroTabla->ocupado = false;
                registroTabla->tipo_elemento = NULL;
                return true;
            }
        } 
        
        /*Como no se encontraba fuera de la lista*/
        else{
            
            /*Intento borrar el elemento si se encuentra en la lista, retornando True en caso de que estaba y False en caso de que 
            no lo este*/
            return l_borrar(registroTabla->lista_colisiones, clave);
        }
    }

    /*En caso de que no habia nada en el casillero, simplemente retorno False*/
    return false;
}


/*Funcion que se encarga de recuperar el dato que se encuentra encuentra en x posicion*/
TipoElemento th_recuperar(TablaHash th, int clave){

    /*Obtengo la posicion del casillero buscado*/
    int pos = th->hash_function(clave);

    /*Obtengo el casillero que quiero*/
    struct TipoRegistroTabla *registroTabla = &th->tabla[pos];

    /*Si el casillero tiene contenido*/
    if(registroTabla->ocupado){

        /*Si el dato se encuentra fuera de la Lista de colisiones*/
        if(registroTabla->tipo_elemento->clave == clave){

            /*Retorno el TipoElemento directamente*/
            return registroTabla->tipo_elemento;  
        } 
        
        /*Sino, debo buscarlo en la Lista de colisiones y si esta lo devuelvo*/
        else{
            
            return l_buscar(registroTabla->lista_colisiones, clave);
        }
    }

    /*Si esta desocupado el casillero retorno NULL*/
    return NULL;
}


void th_mostrar_interna(TablaHash th, bool soloOcupados) {
    
    printf("Contenido de la tabla hash:\n");
    
    for(int i = 0; i < th->capacidad; i++){

        struct TipoRegistroTabla registroTabla = th->tabla[i];
        
        if(registroTabla.ocupado){

            printf("  tabla[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            
            Iterador iter = iterador(registroTabla.lista_colisiones);
            while(hay_siguiente(iter)){

                TipoElemento e = siguiente(iter);
                printf(" -> %i ", e->clave);
            }

            free(iter);
            printf("\n"); 
        } 
        
        else if(!soloOcupados){

            printf("  tabla[%i] [ libre ]\n", i);
        }
    }

    printf("\n");
}


/*Funcion que se encarga de mostrar todos los casilleros de la Tabla Hash*/
void th_mostrar(TablaHash th){

    th_mostrar_interna(th, false);
}


/*funcion que se encarga de mostrar los casilleros ocupados de la Tabla Hash junto a su lista de Colisiones*/
void th_mostrar_solo_ocupados(TablaHash th){

    th_mostrar_interna(th, true);
}
