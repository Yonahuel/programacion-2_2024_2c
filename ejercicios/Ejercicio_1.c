#include <string.h>

#include "headers/Ejercicio_1_Header.h"

bool palindromo(char cadena[]) {
    return comparacionRecursiva(cadena, 0, strlen(cadena) - 1);
}

bool comparacionRecursiva(char cadena[], const int inicio, const int fin) {
    if(inicio >= fin) {
        return true;
    }
    if(cadena[inicio] != cadena[fin]) {
        return false;
    }
    return comparacionRecursiva(cadena, inicio + 1, fin - 1);
}