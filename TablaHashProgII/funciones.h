#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdbool.h>
#include "listas.h"
#include "arbol-avl.h"
#include "tabla_hash.h"


// Ejercicio 4 .

#define moduloej4 97

struct AlumnoRep{

    int legajo;
    char Nombre[50];
    char Apellido[50];
    char Domicilio[100];
    int Telefono;
    int pos;
};

typedef struct AlumnoRep *Alumno;

int funcion_hashej4(int clave);

void Crear_Archivo(char archivo[], char modo[]);

void Altas_Archivo(char archivo[], char modo[], Lista Legajos, TablaHash Tablita);

void Bajas_Archivo(char archivo[], char modo[], Lista Legajos, TablaHash Tablita);

void Modificaciones_Archivo(char archivo[], char modo[], Lista Legajos, TablaHash Tablita);

void Mostrar_Contenido_Archivo(char archivo[], char modo[]);

void Mostrar_Encontrado(Alumno Encontrado);

Alumno Buscar_Alumno(char archivo[], char modo[], Lista Legajos, TablaHash Tablita);



// Ejercicio 5 .

long long obtener_tiempo_en_nanosegundos();

bool es_primo(int num);

int encontrar_primo(int cantidad_elementos);

void Cargar_estructuras_avl_hash(TablaHash tablita, ArbolAVL arbol, int cantidad_elementos, int minimo_rango, int maximo_rango);

void Calcular_tiempos(TablaHash tablita, ArbolAVL arbol, int cantidad_a_buscar, int minimo_rango, int maximo_rango);



// Ejercicio 6 .


struct RegistroRep{

    char nombre[50];
    char apellido[50];
    int dni;
};
typedef struct RegistroRep *vacunado;

#define moduloej6 1093

int funcion_hashej6(int clave);


void Altas_Vacunados( TablaHash tablita);

TipoElemento Buscar_Vacunados(TablaHash tablita);

void mostrar_vacunados(Lista vacunados);

bool esfecha_valida(char dia[], char mes[], char anio[]);


#endif // FUNCIONES_H

