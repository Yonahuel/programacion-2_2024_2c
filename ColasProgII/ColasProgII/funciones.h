#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "colas.h"
#include "pilas.h"
#include "listas.h"


void Cargar_Manualmente(Cola C);

void Cargar_Manualmente_Repetidos(Cola C);

void Cargar_Aleatoriamente(Cola C);

void Cargar_Aleatoriamente_Repetidos(Cola C);



// Ejercicio 2 .

bool C_EJ_Verificar_Existencia(Cola C, int numero);

int C_EJ_Longuitud_Cola(Cola C);

Cola C_EJ_Insertar_Elemento(Cola C, int pos);

Cola C_EJ_Eliminar_Elemento(Cola C, int clave);

Cola C_EJ_Copiar_Cola(Cola Original);

Cola C_EJ_Invertir_Cola(Cola Original);



// Ejercicio 3 .

bool Verificar_Igualdad(Cola C1, Cola C2);



// Ejercicio 4 .

Cola Obtener_Sin_Repetidos(Cola C);


bool Cola_Ordenada(Cola C);



// Ejercicio 5 .

void c_ej5_Carga_Manual(Cola C);

void c_ej5_Carga_Aleatoria(Cola C);

void c_ej5_Mostrar_Resultado(Cola C);

Cola Obtener_Divisores(Cola C);



// Ejercicio 6 .

struct posicion{

    int posicion_p;
    int posicion_c;
};

void Cargar_Aleatoriamente_Pila(Pila P);

void Cargar_Manualmente_Pila(Pila P);

Lista Valores_Repetidos_Posiciones(Cola C, Pila P);

void c_ej6_Mostrar_Resultado(Lista L);



// Ejercicio 7 .

void c_ej7_Carga_CM(Cola C);

void c_ej7_Carga_CA(Cola C);

void Simulacion(Cola C1, Cola C2, Cola C3);

#endif // FUNCIONES_H_INCLUDED
