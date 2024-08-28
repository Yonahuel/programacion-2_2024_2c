#include <stdio.h>
#include "Ejercicio_2_Header.h"

void test_producto() {
    int a1 = 5;
    int b1 = 3;
    int result1 = producto(a1, b1);
    int esperado1 = 15;

    int a2 = 10;
    int b2 = 4;
    int result2 = producto(a2, b2);
    int esperado2 = 40;

    if(result1 == esperado1) {
        printf("Test pasado: %d * %d = %d. Esperado: %d\n", a1, b1, result1, esperado1);
    } else {
        printf("Test no pasado\n");
    }

    if(result2 == esperado2) {
        printf("Test Pasado: %d * %d = %d. Esperado: %d\n", a2, b2, result2, esperado2);
    } else {
        printf("Test no Pasado\n");
    }
}
