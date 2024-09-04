#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//-------------------------------------------     FUNCIONES EXTRA PARA VALIDAR     ------------------------------------------

int Longuitud_String(char String[]);

bool Validar_Intervalo_Enteros(int Numero, int minimo, int maximo);


//--------------------------------------------  VALIDACIONES NUMEROS ENTEROS -----------------------------------------------

int String_A_Entero(char string[]);

int Ingresar_Entero_Positivo();

int Ingresar_Entero_Negativo();

int Ingreso_Entero_Positivo_Negativo();


//-------------------------------------------------- VALIDACIONES STRINGS ---------------------------------------------------

void Ingresar_Cadena_Caracteres(char *Cadena, int cantidad_caracteres);

void Ingresar_Cadena_Caracteres_Numeros_Signos(char *Cadena, int cantidad_maxima_elementos);





#endif // VALIDACIONES_H_INCLUDED
