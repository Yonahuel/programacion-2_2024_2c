#include "funciones.h"
#include "validaciones.h"
#include "listas.h"
#include "tipo_elemento.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//ejercicio 2.

void Cargar_Lista(Lista L){

    int bandera;
    bool pudo;

    do{

        if(!l_es_llena(L)){

            printf(" Que numero desea agregar?: ");
            TipoElemento elemento = te_crear(Ingreso_Entero_Positivo_Negativo());

            pudo = l_agregar(L, elemento);

            printf(" Desea agregar otro numero a la LISTA? (*Ingrese '0' para salir; *Ingrese '1' para agregarlo): ");
            bandera = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
                printf(" Ingrese la opcion: ");
                bandera = Ingresar_Entero_Positivo();
                fflush(stdin);
            }
        }

        else{

            pudo = false;
            printf(" No se pude agregar mas elementos ya que la LISTA esta llena!\n");

            system("pause");
            system("cls");
        }
    }
    while(bandera != 0 && pudo);
}

void Eliminar_Elementos_Lista(Lista L){

    int bandera, pos, caso_particular;
    bool pudo;

    do{

        caso_particular = 0;

        if(!l_es_vacia(L)){

            l_mostrar(L);
            printf(" Ingrese la posicion del elemento a eliminar de la lista: ");
            pos = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(pos, 1, 100)){

                printf(" Ingreso Invalido! Debe ingresar una posicion > 0 o <= 100!\n");
                printf(" Ingrese la posicion a eliminar de la lista: ");
                pos = Ingresar_Entero_Positivo();
                fflush(stdin);
            }

            pudo = l_eliminar(L, pos);

            if(!pudo){

                printf(" Ingreso de posicion INEXISTENTE de la lista actual! Por favor vuelva a intentarlo!\n");
                pudo = true;
                bandera = 1;
                caso_particular = 1;

                system("pause");
                system("cls");
            }

            if(caso_particular != 1){

                printf(" Desea eliminar algun otro elemento de la LISTA? (*Ingrese '0' para salir; *Ingrese '1' para eliminar otro elemento): ");
                bandera = Ingresar_Entero_Positivo();

                while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                    printf(" Ingreso Invalido! Debe ingresar un opcion entre '0' o '1'!\n");
                    printf(" Ingrese la opcion: ");
                    bandera = Ingresar_Entero_Positivo();
                    fflush(stdin);
                }
            }
        }

        else{

            pudo = false;
            printf(" No se pude eliminar mas elementos ya que la LISTA esta vacia!\n");

            system("pause");
            system("cls");
        }
    }
    while(bandera != 0 && pudo);

}

Lista Valores_Diferentes(Lista L_Principal, Lista L_secundaria){

    if(l_es_vacia(L_Principal)){

        return NULL;
    }

    Lista Resultado = l_crear();

    Iterador iter_Principal = iterador(L_Principal);
    TipoElemento elemento_principal;

    TipoElemento elemento_secundario;

    while(hay_siguiente(iter_Principal)){

        bool esta = false;

        elemento_principal = siguiente(iter_Principal);

        Iterador iter_secundario = iterador(L_secundaria);

        while(hay_siguiente(iter_secundario)){

            elemento_secundario = siguiente(iter_secundario);

            if(elemento_principal->clave == elemento_secundario->clave){

                esta = true;
                break;
            }
        }

        free(iter_secundario);

        if(!esta){

            TipoElemento buscado = l_buscar(Resultado, elemento_principal->clave);

            if(buscado == NULL){

                TipoElemento agregable = te_crear(elemento_principal->clave);
                l_agregar(Resultado, agregable);
            }
        }
    }

    free(iter_Principal);

    return Resultado;
}

Lista Valores_Comunes(Lista L1, Lista L2){

    if(l_es_vacia(L1) || l_es_vacia(L2)){

        return NULL;
    }

    Lista Resultado = l_crear();

    Iterador iter_L1 = iterador(L1);

    TipoElemento elemento_L1;
    TipoElemento elemento_L2;

    while(hay_siguiente(iter_L1)){

        bool iguales = false;
        elemento_L1 = siguiente(iter_L1);

        Iterador iter_L2 = iterador(L2);

        while(hay_siguiente(iter_L2)){

            elemento_L2 = siguiente(iter_L2);

            if(elemento_L1->clave == elemento_L2->clave){

                iguales = true;
                break;
            }
        }

        free(iter_L2);

        if(iguales){

            TipoElemento buscado = l_buscar(Resultado, elemento_L1->clave);

            if(buscado == NULL){

                TipoElemento agregado = te_crear(elemento_L1->clave);
                l_agregar(Resultado, agregado);
            }
        }
    }

    free(iter_L1);

    return Resultado;
}


float Promedio_Listas(Lista L){

    if(l_es_vacia(L)){

        return 0.0;
    }

    Iterador iter = iterador(L);
    int contador = 0;
    int acumulador;

    TipoElemento elem;

    while(hay_siguiente(iter)){

        elem = siguiente(iter);
        acumulador += elem->clave;
        contador++;
    }

    free(iter);

    return acumulador / contador;
}

struct valores *Valor_Maximo(Lista L){

    if(l_es_vacia(L)){

        return NULL;
    }

    struct valores *Maximo = (struct valores*) calloc(1, sizeof(struct valores));

    int valor_maximo = -2144783648;
    int pos_Actual = 1;
    int pos_maximo = -1;

    Iterador iter = iterador(L);
    TipoElemento actual;

    while(hay_siguiente(iter)){

        actual = siguiente(iter);

        if(actual->clave > valor_maximo){

            valor_maximo = actual->clave;
            pos_maximo = pos_Actual;
        }

        pos_Actual ++;
    }

    free(iter);

    Maximo->Elemento = valor_maximo;
    Maximo->posicion_Ordinal = pos_maximo;

    return Maximo;
}

struct valores *Valor_Minimo(Lista L){

    if(l_es_vacia(L)){

        return NULL;
    }

    struct valores *Minimo = (struct valores*) calloc(1, sizeof(struct valores));

    int valor_minimo = 2147483646;
    int pos_Actual = 1;
    int pos_minimo = -1;

    Iterador iter = iterador(L);
    TipoElemento actual;

    while(hay_siguiente(iter)){

        actual = siguiente(iter);

        if(actual->clave < valor_minimo){

            valor_minimo = actual->clave;
            pos_minimo = pos_Actual;
        }

        pos_Actual ++;
    }

    free(iter);

    Minimo->Elemento = valor_minimo;
    Minimo->posicion_Ordinal = pos_minimo;

    return Minimo;
}

Lista Lista_Multiplo(Lista L){

    Iterador iter = iterador(L);
    Lista Resultado = l_crear();

    printf(" Ingrese el Numero por el que se multiplicaran los elementos de la LISTA: ");
    int N = Ingreso_Entero_Positivo_Negativo();

    Multiplo_Recursivo(Resultado, iter, N);

    free(iter);

    return Resultado;
}

void Multiplo_Recursivo(Lista Resultado, Iterador iter, int N){

    if(!hay_siguiente(iter)){

        return;
    }

    TipoElemento elem = te_crear(0);
    elem = siguiente(iter);

    elem->clave *= N;

    l_agregar(Resultado, elem);

    Multiplo_Recursivo(Resultado, iter, N);
}

void Cargar_Aleatorio(Lista L){

    srand(time(NULL));

    int Numero;
    int cantidad;
    bool pudo;

    printf(" Cuantos elementos cargaremos? (numero entero positivo[1; 100]): ");
    cantidad = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(cantidad, 1, 100)){

        printf(" Ingreso Invalido! Debe ingresar un numero entre [1; 100]!\n");
        printf(" Cuantos elementos cargaremos? (numero entero positivo[1; 100]): ");
        cantidad = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    do{

        TipoElemento elem = te_crear((rand() % (2000 - (-2000) + 1)) + (-2000));

        TipoElemento buscado = l_buscar(L, elem->clave);

        while(buscado != NULL){

            elem->clave = (rand() % (2000 - (-2000) + 1)) + (-2000);
            buscado = l_buscar(L, elem->clave);
        }

        pudo = l_agregar(L, elem);

        if(!pudo){

            printf(" No se pueden agregar mas elementos, la Lista esta llena!\n");
            system("pause");
            system("cls");
            return;
        }

        cantidad--;
    }
    while(cantidad > 0);
}


















//ejercicio 3.

bool Verificar_Multiplo(Lista L1, Lista L2){

    Iterador iter_L1 = iterador(L1);
    Iterador iter_L2 = iterador(L2);

    TipoElemento elem_L1, elem_L2;

    bool multiplo = true;

    while(hay_siguiente(iter_L1) && hay_siguiente(iter_L2) && multiplo){

        elem_L1 = siguiente(iter_L1);
        elem_L2 = siguiente(iter_L2);

        if(elem_L1->clave == 0 && elem_L2->clave != 0){

            multiplo = false;
        }

        else{

            if(elem_L2->clave % elem_L1->clave != 0){

                multiplo = false;
            }
        }
    }

    free(iter_L1);
    free(iter_L2);

    return multiplo;
}


bool Verificar_Escalar(Lista L1, Lista L2){

    bool escalar = true;

    Iterador iter_L1 = iterador(L1);
    Iterador iter_L2 = iterador(L2);

    TipoElemento elem_L1, elem_L2;

    int contador = 0;
    int n_escalar_actual, n_escalar_anterior;

    while(hay_siguiente(iter_L1) && hay_siguiente(iter_L2) && escalar){

        elem_L1 = siguiente(iter_L1);
        elem_L2 = siguiente(iter_L2);

        if(contador == 0){

            n_escalar_anterior = elem_L2->clave / elem_L1->clave;
        }
        else{

            n_escalar_actual = elem_L2->clave / elem_L1->clave;

            if(n_escalar_anterior != n_escalar_actual){

                escalar = false;
            }
        }
    }

    free(iter_L1);
    free(iter_L2);

    return escalar;
}


bool Verificar_Igualdad_Tamanio_Listas(Lista L1, Lista L2){

    int contador_L1 = 0, contador_L2 = 0;

    Iterador iter_L1 = iterador(L1);
    Iterador iter_L2 = iterador(L2);

    TipoElemento elem;

    while(hay_siguiente(iter_L1)){

        elem = siguiente(iter_L1);
        contador_L1++;
    }

    while(hay_siguiente(iter_L2)){

        elem = siguiente(iter_L2);
        contador_L2++;
    }

    free(iter_L1);
    free(iter_L2);

    if(contador_L1 != contador_L2){

        return false;
    }

    return true;
}


















//ejercicio 4.


int Comparar_Listas(Lista L1, Lista L2){

    int contador_L1 = 0, contador_L2 = 0;

    Iterador iter_L1 = iterador(L1);
    Iterador iter_L2 = iterador(L2);

    TipoElemento elem_L1, elem_L2;

    while(hay_siguiente(iter_L1) && hay_siguiente(iter_L2)){

        elem_L1 = siguiente(iter_L1);
        elem_L2 = siguiente(iter_L2);

        if(elem_L1->clave > elem_L2->clave){

            contador_L1 ++;
        }

        if(elem_L1->clave < elem_L2->clave){

            contador_L2 ++;
        }
    }

    free(iter_L1);
    free(iter_L2);

    if(contador_L1 > contador_L2){

        printf(" L1 > L2\n");
        return 1;
    }

    if(contador_L1 < contador_L2){

        printf(" L1 < L2\n");
        return 2;
    }

    else{

        printf(" L1 = L2\n");
        return 3;
    }
}


















//ejercicio 5.



Lista Cargar_Polinomio(int grado_polinomio){

    int coeficiente = grado_polinomio;
    int n;
    Lista Polinomio = l_crear();

    do{

        printf(" Ingrese el coeficiente de X^%d (numero entero entre [-100; 100]): ", coeficiente);
        n = Ingreso_Entero_Positivo_Negativo();

        while(!Validar_Intervalo_Enteros(n, -100, 100)){

            printf(" Ingreso Invalido! debe ingresar un Numero entre [-100; 100]!\n");
            printf(" Ingrese el coeficiente de X^%d (numero entero entre [-100; 100]): ", coeficiente);
            n = Ingreso_Entero_Positivo_Negativo();
            fflush(stdin);
        }

        coeficiente--;

        TipoElemento elem = te_crear(n);

        l_agregar(Polinomio, elem);
    }
    while(coeficiente > -1);

    return Polinomio;
}

float Resultado_calcular_fx(Lista Polinomio, int Grado_del_Polinomio, float X){

    float Resultado = 0.0;

    int coeficiente = Grado_del_Polinomio;

    float potencia;

    Iterador iter = iterador(Polinomio);
    TipoElemento elem;

    while(hay_siguiente(iter)){

        elem = siguiente(iter);

        potencia = 1.0;

        if(coeficiente != 0){

            for(int i = 1; i <= coeficiente; i++){

                potencia *= X;
            }
        }

        Resultado += elem->clave * potencia;

        coeficiente --;
    }

    free(iter);

    return Resultado;
}

void Cargar_Intervalo_Completo(Lista Intervalo_Completo, int Inicio_Rango_Valores, int Final_Rango_Valores, float Cada_Cuanto){

    float acumulador = 0.0;

    while((Inicio_Rango_Valores + acumulador) < Final_Rango_Valores){

        float* valor = (float*) calloc(1 , sizeof(float));

        *valor = Inicio_Rango_Valores + acumulador;

        TipoElemento elem = te_crear_con_valor(0, valor);

        l_agregar(Intervalo_Completo, elem);

        acumulador += Cada_Cuanto;

        if((Inicio_Rango_Valores + acumulador) >= Final_Rango_Valores){

            float* valor2 = (float*) calloc(1 , sizeof(float));

            *valor2 = Final_Rango_Valores;

            TipoElemento elem2 = te_crear_con_valor(0, valor2);

            l_agregar(Intervalo_Completo, elem2);
        }
    }
}

void Calcular_Intervalo_fx(Lista Polinomio, Lista Intervalo_Completo, Lista Resultado_FX, int Grado_del_Polinomio){

    Iterador iter = iterador(Intervalo_Completo);

    while(hay_siguiente(iter)){

        TipoElemento elemento = siguiente(iter);

        float valor = *(float*)elemento->valor;

        float* Fx = (float*) calloc(1, sizeof(float));

        *Fx = Resultado_calcular_fx(Polinomio, Grado_del_Polinomio, valor);

        TipoElemento Y = te_crear_con_valor(0, Fx);
        l_agregar(Resultado_FX, Y);
    }

    free(iter);
}

void mostrar_ejercicio5(Lista Polinomio, Lista Intervalo_Completo, Lista Resultado_FX, int Grado_del_Polinomio){


    Iterador iter_X = iterador(Intervalo_Completo);
    Iterador iter_Y = iterador(Resultado_FX);
    Iterador iter_poli = iterador(Polinomio);

    TipoElemento elem_x;
    TipoElemento elem_y;
    TipoElemento elem_poli;

    int contador = Grado_del_Polinomio;

    printf(" POLINOMIO: ");

    while(hay_siguiente(iter_poli)){

        elem_poli = siguiente(iter_poli);

        if(contador == 0){

            printf("%d\n\n", elem_poli->clave);
        }

        else{


            if(elem_poli->clave > 0){

                printf("%dX^%d + ", elem_poli->clave, contador);

                contador--;
            }

            else{

                printf("%dX ", elem_poli->clave);
                contador--;
            }
        }
    }

    free(iter_poli);

    printf("  X  |  Y  \n");
    printf("-----|-----\n");

    while(hay_siguiente(iter_X) && hay_siguiente(iter_Y)){

        elem_x = siguiente(iter_X);
        elem_y = siguiente(iter_Y);

        float valor_x = *(float*) elem_x->valor;
        float valor_y = *(float*) elem_y->valor;

        printf("%.1f  |  %.2f\n", valor_x, valor_y);
    }

    free(iter_X);
    free(iter_Y);
}


















//ejercicio 6.

bool Verificar_Sublista(Lista L1, Lista L2){

    bool sublista;
    TipoElemento elem_L1, elem_L2;

    Iterador iter_L2 = iterador(L2);

    while(hay_siguiente(iter_L2)){

        sublista = false;

        elem_L2 = siguiente(iter_L2);

        Iterador iter_L1 = iterador(L1);

        while(hay_siguiente(iter_L1)){

            elem_L1 = siguiente(iter_L1);

            if(elem_L2->clave == elem_L1->clave){

                sublista = true;
                break;
            }
        }

        free(iter_L1);

        if(!sublista){

            free(iter_L2);
            return sublista;
        }
    }

    free(iter_L2);

    return sublista;
}
