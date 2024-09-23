#ifndef EJERCICIOS_H_INCLUDED
#define EJERCICIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
//Ejercicio 1.
#define TAMANIO_STRING 20

bool palindromo(char cadena_caracteres[]);

bool palindromo_recursivo(char cadena_caracteres[], int principio, int finall);

void Mostrar_Resultado_ejercicio1(bool resultado, char cadena_caracteres[]);

void ejercicio1();
void ejercicio22();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
void ejercicio8();
void ejercicio9();
void ejercicio10();


//Ejercicio 2.

int producto(int m, int n);

void producto_recursivo(int *resultado, int m, int n);

void Mostrar_resultado_ejercicio2(int resultado, int m, int n);



//Ejercicio 3.

int terminoSeridFibonacci(int numero);

void Mostrar_resultado_ejercicio3(int resultado, int numero);



//Ejercicio 4.

double division(int m, int n);

double division_recursiva(int m, int n, int decimales);

void Mostrar_resultado_ejercicio4(double resultado, int m, int n);



//Ejercicio 5.

char *agregarSeparadorMiles(char Numero_string[]);

void CargarlosPuntos(char *Numero_miles, char numero_string[], int inicio, int final, char temporal);

void Cambiar_Orientacion_string(char *Numero_miles, int inicio, int final, char temporal);

void Mostrar_resultado_ejercicio5(char numero_miles[], char numero[]);



//Ejercicio 6.

int Calcular_tamanio_mafia(int nivel_reunion);

char *SitiodelaReunion(int nivel_reunion);

void Cargar_Reunion(char *Cadena_Mafia, int nivel_reunion);

void Mostrar_resultado_ejercicio6(char Cadena_mafia[], int nivel_reunion);




//Ejercicio 7.

#define TAMANIO_ONDA_DIGITAL 51

void Validar_Cadena_String_ejercicio7(char *Cadena_string);

char *ondaDigital(char Cadena_string[]);

void ondaDigital_Recursiva(char *Cadena_Digital, char Cadena_string[], int pos_Digital, int inicio);

void Mostrar_resultado_ejercicio7(char Cadena_Digital[], char Cadena_string[]);




//Ejercicio 8.

#define TAMANIO_CONJUNTOS 20

struct SubConj{

    int subconjunto[TAMANIO_CONJUNTOS];
    int tam;
};

struct ListaSubConj{

    struct SubConj Formados[TAMANIO_CONJUNTOS];
    int cantidad_formados;
};

int *Cargar_ConjuntoA(int tam);

struct ListaSubConj *subconjuntosQueSumanN(int ConjuntoA[], int tam_conjA, int n);

void subconjuntosQueSumanN_Recursiva(struct ListaSubConj *Resultado, int ConjuntoA[], int tam_conjA, int indice_ConjA, int n, int suma, int *indice_resultado, int *almacen, int tam_almacen);

void Mostrar_resultado_ejercicio8(struct ListaSubConj Resultado, int ConjuntoA[], int tamconjA, int n);



//Ejercicio 9.

bool divisiblePor7(int Numero);

void Mostrar_resultado_ejercicio9(bool Resultado, int numero);



//Ejercicio 10.

int *explosion(int N, int B, int *Cantidad_Fragmentos);

void explosion_recursiva(int **Fragmentos, int *inicio, int N, int B);

void Mostrar_resultado_ejercicio10(int Fragmentos[], int Cantidad_Fragmentos, int N, int B);







#endif // EJERCICIOS_H_INCLUDED
