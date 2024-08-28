#ifndef HEADERS_H
#define HEADERS_H
#include <stddef.h>

// Ejercicio 8
#define TAMANO_SUMA 20
typedef struct {
    int suma[TAMANO_SUMA];
    int cantElementos;
} Subconjunto;

typedef struct ArraySubconjuntos {
    Subconjunto listaSubconjunto[TAMANO_SUMA];
    int cantidadSubConjuntos;
} ArraySubconjuntos;

ArraySubconjuntos *subconjuntosQueSumanN(int array[], int n, int tamanoArray);
void sumaRecursiva(
    ArraySubconjuntos *array,
    int conjunto[],
    int corte,
    int indiceArray,
    int ciclo,
    int suma,
    int almacen[],
    int tamanoAlmacen
);

#endif