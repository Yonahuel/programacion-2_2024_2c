#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>

/*Esta funcion recibe una clave entera, para crear un objeto del tipo 'TIPOELEMENTO', que es un puntero a "TipoElementoRep", donde se 
le asigna memoria dinamica y se le asignan los respectivos valores para trabajar*/
TipoElemento te_crear(int clave){

    /*Crea la varibale de TipoElemento con memoria dinamica, donde se devuelve un puntero a la ubicacion en memoria de su inicio*/
    TipoElemento TE = (TipoElemento) malloc(sizeof(struct TipoElementoRep));
    
    /*Carga las variables apuntadas por TE con sus valores correspondientes*/
    TE->clave = clave;
    TE->valor = NULL;

    /*Retorna el puntero generado de TipoElementoRep*/
    return TE;   
}

/*Es la misma funcion que la anterior, solamente que ahora se le permite darle valor a la segunda variable de TE que es de TipoElemento
que a su ves es de TipoElementoRep*/
TipoElemento te_crear_con_valor(int clave, void* valor){

    TipoElemento TE = (TipoElemento) malloc(sizeof(struct TipoElementoRep));


    TE->clave = clave;
    TE->valor = valor;

    /*Retorna el puntero generado*/
    return TE;
}