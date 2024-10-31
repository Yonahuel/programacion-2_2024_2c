#ifndef VALIDACIONES_H
#define VALIDACIONES_H



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//-------------------------------------------     FUNCIONES EXTRA PARA VALIDAR     ------------------------------------------

int Longuitud_String(char String[]);

bool Validar_Intervalo_Enteros(int Numero, int minimo, int maximo);

bool Validar_Intervalo_Decimal(float Numero, float minimo, float maximo);


//-------------------------------------   VALIDACIONES NUMEROS ENTEROS PARA ARBOLES   --------------------------------------

char *Ingresar_Numero_A_P();

char *Ingresar_Numero_A_N();

char *Ingresar_Numero_A_PN();



//--------------------------------------------  VALIDACIONES NUMEROS ENTEROS -----------------------------------------------
int String_A_Entero(char string[]);

int Ingresar_Entero_Positivo();

int Ingresar_Entero_Negativo();

int Ingreso_Entero_Positivo_Negativo();


//--------------------------------------------  VALIDACIONES NUMEROS DECIMALES -----------------------------------------------

float String_A_Decimal(char string[]);

float Ingresar_Decimal_Positivo();

float Ingresar_Decimal_Negativo();

float Ingreso_Decimal_Positivo_Negativo();

//-------------------------------------------------- VALIDACIONES STRINGS ---------------------------------------------------

void Ingresar_Cadena_Caracteres(char *Cadena, int cantidad_caracteres);

void Ingresar_Cadena_Caracteres_Numeros_Signos(char *Cadena, int cantidad_maxima_elementos);


#endif