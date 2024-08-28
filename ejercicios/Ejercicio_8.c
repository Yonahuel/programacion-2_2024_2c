#include <stdio.h>
#include "headers/Ejercicio_8_Header.h"


ArraySubconjuntos *subconjuntosQueSumanN(
    int array[],
    const int n,
    const int tamanoArray
) {
    ArraySubconjuntos result[1];
    int indiceArray = 0;

    for(int i = 0; i < tamanoArray; i++) {
        const int suma = 0;
        int almacen[TAMANO_SUMA];
        sumaRecursiva(result, array, n, indiceArray, i, suma, almacen, 0);
        indiceArray++;
    }
    return result;
}

void sumaRecursiva(
    ArraySubconjuntos *array,
    int conjunto[],
    const int corte,
    const int indiceArray,
    int ciclo,
    int suma,
    int almacen[],
    int tamanoAlmacen
) {
    if(suma == corte) {
        for (int i = 0; i < tamanoAlmacen; i++) {
            array[1].listaSubconjunto[indiceArray].suma[i] = almacen[i];
        }
        return;
    }

    if(suma > corte) {
        return;
    }

    suma += conjunto[ciclo];
    almacen[tamanoAlmacen] = conjunto[ciclo];
    sumaRecursiva(
        array,
        conjunto,
        corte,
        indiceArray,
        ciclo++,
        suma,
        almacen,
        tamanoAlmacen++
    );
}

void test_subconjuntosQueSumanN(
    int array[],
    const int n,
    const int tamanoArray,
    const ArraySubconjuntos *esperado
) {
    const ArraySubconjuntos *result = subconjuntosQueSumanN(array, n, tamanoArray);

    for (int i = 0; i < TAMANO_SUMA; i++) {
        /* code */
    }
    

    if (result == esperado) {
        printf("Test pasado");
    } else {
        printf("Test no pasado");
    }
}