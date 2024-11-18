#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdbool.h>
#include "listas.h"
#include "arbol-avl.h"
#include "conjuntos.h"


void cargar_conjunto_manual(Conjunto C, int tam);

void cargar_conjunto_Naturales(Conjunto C, int tam);

void Cargar_ej3(Lista Coleccion, int tam);

Conjunto Obtener_Union_Coleccion(Lista coleccion);

Conjunto Obtener_interseccion_Coleccion(Lista coleccion);

void mostrar_coleccion_conjuntos(Lista coleccion);

bool subconjunto_de(Conjunto Principal, Conjunto Subconjunto);

Conjunto diferencia_simetrica(Conjunto A, Conjunto B);

bool Subconjunto_Propio(Conjunto Principal, Conjunto Subconjunto);

bool es_subconjunto_total(Conjunto X, Conjunto Y);

bool es_subconjunto_parcial(Conjunto X, Conjunto Y);

void determinar_subconjuntos(Conjunto A, Conjunto B, Conjunto C);

bool verificar_mismos_elementos(Conjunto A, Conjunto B);



#endif // FUNCIONES_H