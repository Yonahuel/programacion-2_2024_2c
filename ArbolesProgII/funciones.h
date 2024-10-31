#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdbool.h>
#include "listas.h"
#include "colas.h"
#include "arbol-avl.h"
#include "arbol-binario-busqueda.h"
#include "arbol-binario.h"



void mostrar_AB(NodoArbol Padre, int nivel);

Lista Cargar_Arbol_Binario_PO(ArbolBinario Arbol, NodoArbol Padre);
void proceso_interno_PO(ArbolBinario Arbol, NodoArbol Padre, Lista Contenido, int nivel);

Lista Cargar_Arbol_Binario_POU(ArbolBinario Arbol, NodoArbol Padre);
void proceso_interno_POU(ArbolBinario Arbol, NodoArbol Padre, Lista Contenido, int nivel);

Lista Cargar_Arbol_Nario_POU(ArbolBinario Arbol, NodoArbol Actual);
void proceso_interno_Nario_POU(ArbolBinario Arbol, NodoArbol Actual, Lista Contenido, int nivel, int nhijo, int padre);





// Ejercicio 2 .

Lista Obtener_Hojas_AB(ArbolBinario Arbol);
void B_Hojas(NodoArbol Padre, Lista L);

Lista Obtener_Internos_AB(ArbolBinario Arbol);
void B_Internos(NodoArbol Padre, Lista L, int Nivel);

Lista Obtener_Ocurrencias_AB(ArbolBinario Arbol, int clave);
void B_Ocurrencias(NodoArbol Padre, Lista L, int clave, int Nivel);
void mostrar_Ocurrencias(Lista Ocurrencias, int clave);




// Ejercicio 3 .

int *Obtener_Padre_AB(ArbolBinario Arbol, int clave);
void B_Padre_AB(NodoArbol Padre, int **resultado, bool *encontrado, int clave);

Lista Obtener_Hijos_AB(ArbolBinario Arbol, int clave);
void B_Hijos_AB(NodoArbol Padre, Lista Hijos, bool* encontrado, int clave);

int *Obtener_Hermano_AB(ArbolBinario Arbol, int clave);
void B_Hermano_AB(NodoArbol Padre, int **Hermano, bool *encontrado, int clave);

int Obtener_Nivel_AB(ArbolBinario Arbol, int clave);
void C_Nivel_AB(NodoArbol Padre, int *nivel, bool *encontrado, int actual, int clave);

int Obtener_ALtura_Subrama_AB(ArbolBinario Arbol, int clave);
void C_Altura_Subrama_AB(NodoArbol Padre, int *Altura, bool encontrado, int actual, int clave);

Lista Obtener_MismoNivel_AB(ArbolBinario Arbol, int clave);
void O_Mismo_Nivel_AB(NodoArbol Padre, Lista Mismo_Nivel, int actual, int nivel);






// Ejercicio 4 .

Lista Contenido_Nario_A(ArbolBinario Arbol);
void Contenido_Anchura_Nario(NodoArbol Padre, Lista Recorrido, Cola A_recorrer, int Nivel, bool *ingresar);

int Obtener_Hojas_Nario(ArbolBinario Arbol);
void Hojas_Nario(NodoArbol Padre, int *cantidad);

bool Comparar_Arboles_Narios(ArbolBinario Arbol1, ArbolBinario Arbol2);
void Calculo_Similar_Nario(NodoArbol Padre1, NodoArbol Padre2, bool *similar);

TipoElemento Obtener_Padre_Nario(ArbolBinario Arbol, Lista Contenido);
void O_Padre_Nario(NodoArbol Nodo, TipoElemento Resultado, int p_actual, bool *encontrado, int clave);

Lista Obtener_Hermanos_Nario(ArbolBinario Arbol, Lista Contenido);
void O_Hermanos_Nario(NodoArbol Nodo, Lista Hermanos, bool *encontrado, int *nivel, int actual, int clave);





// Ejercicico 7 .

bool Determinar_Equivalencia_Binario(ArbolBinario Arbol1, ArbolBinario Arbol2);
void D_Equivalencia_B(NodoArbol Nodo1, NodoArbol Nodo2, bool *Equivalente);





// Ejercicio 8 .

int Obtener_Altura_Nario(ArbolBinario Arbol);
void Altura_Nario(NodoArbol Nodo, int *Altura, int actual);

int *Obtener_NivelNodo_Nario(ArbolBinario Arbol, Lista Contenido, int clave);
void O_Nivel_Nodo_Nario(NodoArbol Nodo, int **nivel, int actual, bool *encontrado, int clave);

Lista Obtener_Internos_Nario(ArbolBinario Arbol);
void O_Internos_Nario(NodoArbol Padre, Lista Internos, Cola Proximo, bool *empezar, int nivel);

bool Determinar_NHojas_Nario(ArbolBinario Arbol);
void Verficiar_NHojas_Nario(NodoArbol Padre, bool *mismo_Nivel, int **Nivel, int actual);




// Ejercicio 9 .

ArbolAVL De_Binario_a_Avl(ArbolBinario Arbol_Binario);
void Generar_AVL(NodoArbol Nodo, ArbolAVL Arbol);

int Comparar_Binario_AVL(ArbolBinario Arbol_Binario, ArbolAVL Arbol_Avl);
void Obtener_Altura_AB_ABB_AVL(NodoArbol Padre, int *Altura, int Actual);




// Ejercicio 10 .

void Cargar_AVL_ABB(ArbolAVL AVL, ArbolBinarioBusqueda ABB, int cantidad_elementos);
void Comparar_Altura_ABB_AVL(ArbolAVL AVL, Lista Alturas_AVL, ArbolBinarioBusqueda ABB, Lista Alturas_ABB, Lista Diferencia_Alturas);
void Mostrar_Resultados(Lista AVL, Lista ABB, Lista Diferencia);



#endif // FUNCIONES_H

