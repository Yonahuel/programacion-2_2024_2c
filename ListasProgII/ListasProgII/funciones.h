#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "listas.h"
#include "tipo_elemento.h"


//Ejercicio 2.


struct valores{

    int Elemento;
    int posicion_Ordinal;
};

void Cargar_Lista(Lista L);

void Eliminar_Elementos_Lista(Lista L);

Lista Valores_Diferentes(Lista L_Principal, Lista L_secundaria);

Lista Valores_Comunes(Lista L1, Lista L2);

float Promedio_Listas(Lista L);

struct valores *Valor_Maximo(Lista L);

struct valores *Valor_Minimo(Lista L);

Lista Lista_Multiplo(Lista L);

void Multiplo_Recursivo(Lista Resultado, Iterador iter, int N);

void Cargar_Aleatorio(Lista L);



//ejercicio 3.

bool Verificar_Multiplo(Lista L1, Lista L2);

bool Verificar_Escalar(Lista L1, Lista L2);

bool Verificar_Igualdad_Tamanio_Listas(Lista L1, Lista L2);



//ejercicio 4.

int Comparar_Listas(Lista L1, Lista L2);



//ejercicio 5.

Lista Cargar_Polinomio(int grado_polinomio);

float Resultado_calcular_fx(Lista Polinomio, int Grado_del_Polinomio, float X);

void Cargar_Intervalo_Completo(Lista Intervalo_Completo, int Inicio_Rango_Valores, int Final_Rango_Valores, float Cada_Cuanto);

void Calcular_Intervalo_fx(Lista Polinomio, Lista Intervalo_Completo, Lista Resultado_FX, int Grado_del_Polinomio);

void mostrar_ejercicio5(Lista Polinomio, Lista Intervalo_Completo, Lista Resultado_FX, int Grado_del_Polinomio);



//ejercicio 6.

bool Verificar_Sublista(Lista L1, Lista L2);


#endif // FUNCIONES_H_INCLUDED
