#include <stdio.h>

#include "Ejercicio_1_Header.h"

void test_palindromo() {
    char caso1[] = "neuquen";
    bool result1 = palindromo(caso1);
    bool esperado1 = true;

    char caso2[] = "palindromo";
    bool result2 = palindromo(caso2);
    bool esperado2 = false;

    if(result1 == esperado1) {
        printf("Test pasado: %s\n", caso1);
    } else {
        printf("Test no pasado: %s\n", caso1);
    }

    if(result2 == esperado2) {
        printf("Test pasado: %s\n", caso2);
    } else {
        printf("Test no pasado: %s\n", caso2);
    }
}