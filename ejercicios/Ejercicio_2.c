#include <stdio.h>
#include "Ejercicio_2_Header.h"

int producto(int a, int b) {
    return productoRecursivo(a, b, 0);
}

int productoRecursivo(int a, int b, int result) {
     if (b == 0) {
         return result;
     }
     return productoRecursivo(a, b - 1, result + a);
}