#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>
#include "pilas.h"



void Cargar_Pilas_Manualmente(Pila P);

void Cargar_Pilas_Aleatoriamente(Pila P);




// Ejercicio 2 .
bool p_ej2_existeclave(Pila p, int clave);

Pila p_ej2_colocarelemento(Pila p, int posicionordinal);

Pila p_ej2_eliminarclave(Pila p, int clave);

Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2);

Pila p_ej2_duplicar(Pila p);

int p_ej2_cantidadelementos(Pila p);




// Ejercicio 3 .

bool p_ej3_iguales(Pila p1, Pila p2);




// Ejercicio 4 .
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase);

void Invertir_Pila(Pila p);



// Ejercicio 5 .
Pila  p_ej5_invertir(Pila p);




// Ejercicio 6 .
Pila p_ej6_eliminarclave_iterativo(Pila p, int clave);

Pila p_ej6_eliminarclave(Pila p, int clave);

void p_ej6_eliminarclave_recursivo(Pila p, Pila Resultado, int clave);




// Ejercicio 7 .
Pila p_ej7_eliminarclave(Pila p1, Pila p2);



// Ejercicio 8 .
Pila p_ej8_sacarrepetidos(Pila p);

void p_mostrar_con_Valor(Pila Resultado);

#endif // FUNCIONES_H_INCLUDED
