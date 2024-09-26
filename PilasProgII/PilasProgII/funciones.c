#include "pilas.h"
#include "funciones.h"
#include "tipo_elemento.h"
#include "validaciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//ejercicio 2.

void Cargar_Pilas_Manualmente(Pila P){

    int bandera;
    bool pudo;

    do{

        pudo = true;

        if(!p_es_llena(P)){

            printf(" Ingrese la clave del elemento a agregar en la PILA (Numero Entero): ");
            TipoElemento elem = te_crear(Ingreso_Entero_Positivo_Negativo());

            pudo = p_apilar(P, elem);

            if(!p_es_llena(P)){

                printf(" Desea agregar otro elemento a la PILA? (*Ingrese ' 0 ' para salir; *Ingrese ' 1 ' para agregarlo): ");
                bandera = Ingresar_Entero_Positivo();

                while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                    printf(" Ingreso invalido! debe ingresar una opcion entre [0; 1] !\n");
                    printf(" Desea agregar otro elemento a la PILA? (*Ingrese ' 0 ' para salir; *Ingrese ' 1 ' para agregarlo): ");
                    bandera = Ingresar_Entero_Positivo();
                    fflush(stdin);
                }
            }

            else{

                printf(" La PILA se lleno! no puede agregar mas elementos!\n");
                system("pause");
                system("cls");
                pudo = false;
                bandera = 0;
            }

        }

        else{

            pudo = false;
            bandera = 0;
            printf(" La PILA se encuentra llena!, no puede agregar mas elementos!\n");
            system("pause");
            system("cls");
        }

    }
    while(bandera != 0 && pudo);
}

void Cargar_Pilas_Aleatoriamente(Pila P){

    srand(time(NULL));

    Pila P_Auxiliar;
    TipoElemento ya_cargado;

    bool repetido;
    int clave, cantidad;

    if(!p_es_llena(P)){

        printf(" Cuantos elementos Cargaremos? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

            printf(" Ingreso invalido! debe ingresar una cantidad entre [1; 10] !\n");
            printf(" Cuantos elementos Cargaremos? (Numero Entero entre [1; 10]): ");
            cantidad = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        do{

            clave = (rand() % (20 - (-20) + 1)) + (-20);

            do{

                repetido = false;
                P_Auxiliar = p_crear();

                while(!p_es_vacia(P)){

                    ya_cargado = p_desapilar(P);

                    if(ya_cargado->clave == clave){

                        repetido = true;
                        p_apilar(P, ya_cargado);
                        break;
                    }

                    else{

                        p_apilar(P_Auxiliar, ya_cargado);
                    }
                }

                while(!p_es_vacia(P_Auxiliar)){

                    ya_cargado = p_desapilar(P_Auxiliar);

                    p_apilar(P, ya_cargado);
                }

                if(repetido){

                    clave = (rand() % (20 - (-20) + 1)) + (-20);
                }

                free(P_Auxiliar);
            }
            while(repetido);

            TipoElemento elemento = te_crear(clave);
            p_apilar(P, elemento);
            cantidad--;

        }
        while(cantidad > 0 && !p_es_llena(P));

        if(cantidad > 0 && p_es_llena(P)){

            printf(" No se puede cargar mas elementos a la PILA ya que esta llena!\n");
            system("pause");
            system("cls");
        }
    }

    else{

        printf(" La PILA se encuentra llena!, no puede agregar mas elementos!\n");
        system("pause");
        system("cls");
    }
}





//ejercicio 2 "A" .

bool p_ej2_existeclave(Pila p, int clave){

    bool existe = false;
    TipoElemento ya_cargado;
    Pila P_Auxiliar = p_crear();

    while(!p_es_vacia(p)){

        ya_cargado = p_desapilar(p);

        if(ya_cargado->clave == clave){

            existe = true;
            p_apilar(p, ya_cargado);
            break;
        }

        else{

            p_apilar(P_Auxiliar, ya_cargado);
        }
    }

    while(!p_es_vacia(P_Auxiliar)){

        ya_cargado = p_desapilar(P_Auxiliar);

        p_apilar(p, ya_cargado);
    }

    free(P_Auxiliar);

    return existe;
}





//ejercicio 2 "B" .

Pila p_ej2_colocarelemento(Pila p, int posicionordinal){

    int contador = 0;
    bool cargado = false;
    Pila P_Auxiliar = p_crear();
    TipoElemento ya_cargado;



    if(p_es_llena(p)){

        while(!p_es_vacia(p)){

            contador++;

            if(contador == posicionordinal){

                printf(" Ingrese la clave del elemento a agregar en la posicion %d de la PILA: ", posicionordinal);
                TipoElemento elem = te_crear(Ingreso_Entero_Positivo_Negativo());

                p_apilar(P_Auxiliar, elem);
                cargado = true;

                ya_cargado = p_desapilar(p);
                free(ya_cargado);
            }

            else{

                ya_cargado = p_desapilar(p);
                p_apilar(P_Auxiliar, ya_cargado);
            }
        }

        while(!p_es_vacia(P_Auxiliar)){

            ya_cargado = p_desapilar(P_Auxiliar);
            p_apilar(p, ya_cargado);
        }
    }

    else{

        while(!p_es_vacia(p)){

            contador++;

            if(contador == posicionordinal){

                printf(" Ingrese la clave del elemento a agregar en la posicion %d de la PILA: ", posicionordinal);
                TipoElemento elem = te_crear(Ingreso_Entero_Positivo_Negativo());
                cargado = true;

                p_apilar(P_Auxiliar, elem);
            }

            else{

                ya_cargado = p_desapilar(p);
                p_apilar(P_Auxiliar, ya_cargado);
            }
        }

        if((contador == posicionordinal - 1) && p_es_vacia(p)){

            printf(" Ingrese la clave del elemento a agregar en la posicion %d de la PILA: ", posicionordinal);
            TipoElemento elem = te_crear(Ingreso_Entero_Positivo_Negativo());
            p_apilar(P_Auxiliar, elem);
        }

        if(!cargado){

            printf(" La posicion ordinal ingresada es mayor a la permitida! Si desea ingresar un elemento, ingrese una posicion entre [1;%d]! \n", contador + 1);
        }

        while(!p_es_vacia(P_Auxiliar)){

            ya_cargado = p_desapilar(P_Auxiliar);
            p_apilar(p, ya_cargado);
        }
    }

    free(P_Auxiliar);

    return p;
}





//ejercicio 2 "C" .

Pila p_ej2_eliminarclave(Pila p, int clave){

    TipoElemento ya_cargado;
    Pila P_Auxiliar = p_crear();

    while(!p_es_vacia(p)){

        ya_cargado = p_desapilar(p);

        if(ya_cargado->clave == clave){

            free(ya_cargado);
            break;
        }

        else{

            p_apilar(P_Auxiliar, ya_cargado);
        }
    }

    while(!p_es_vacia(P_Auxiliar)){

        ya_cargado = p_desapilar(P_Auxiliar);
        p_apilar(p, ya_cargado);
    }

    free(P_Auxiliar);

    return p;
}





//ejercicio 2 "D" .

Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){

    int contador = 0;
    int intercambio = 0;
    TipoElemento ya_cargado;
    TipoElemento elem_1 = te_crear(0);
    TipoElemento elem_2 = te_crear(0);
    Pila P_Auxiliar = p_crear();

    if(p_es_vacia(p)){

        printf(" No se pueden intercambiar elementos porque la PILA esta vacia!\n");
        free(P_Auxiliar);
        return p;
    }

    while(!p_es_vacia(p)){

        contador ++;
        ya_cargado = p_desapilar(p);

        if(contador == pos1){

            elem_1->clave = ya_cargado->clave;
            intercambio++;
        }

        if(contador == pos2){

            elem_2->clave = ya_cargado->clave;
            intercambio++;
        }

        p_apilar(P_Auxiliar, ya_cargado);
    }

    if(intercambio != 2){

        if(contador != 1){

            printf(" No se puede realizar el intercambio ya que debe ingresar 2 posiciones entre [1; %d] !\n", contador);
        }

        else{

            printf(" No se puede realizar el intercambio ya que la PILA solo posee 1 elemento y se requiere minimamente 2!\n");
        }
    }

    while(!p_es_vacia(P_Auxiliar)){

        ya_cargado = p_desapilar(P_Auxiliar);

        if(intercambio == 2){

            if(contador == pos1){

                free(ya_cargado);
                p_apilar(p, elem_2);
            }

            else if(contador == pos2){

                free(ya_cargado);
                p_apilar(p, elem_1);
            }

            else{

                p_apilar(p, ya_cargado);
            }
        }

        else{

            p_apilar(p, ya_cargado);
        }

        contador --;
    }

    return p;
}





//ejercicio 2 "E" .

Pila p_ej2_duplicar(Pila p){

    Pila Copia = p_crear();
    Pila P_Auxiliar = p_crear();
    TipoElemento ya_cargado;

    if(p_es_vacia(p)){

        free(P_Auxiliar);
        return Copia;
    }

    else{

        while(!p_es_vacia(p)){

            ya_cargado = p_desapilar(p);

            TipoElemento elem = te_crear(ya_cargado->clave);

            p_apilar(Copia, elem);
            p_apilar(P_Auxiliar, ya_cargado);
        }

        while(!p_es_vacia(P_Auxiliar)){

            ya_cargado = p_desapilar(P_Auxiliar);
            p_apilar(p, ya_cargado);
        }

        while(!p_es_vacia(Copia)){

            ya_cargado = p_desapilar(Copia);
            p_apilar(P_Auxiliar, ya_cargado);
        }

        free(Copia);

        return P_Auxiliar;
    }
}





//ejercicio 2 "F" .

int p_ej2_cantidadelementos(Pila p){

    Pila P_Auxiliar = p_crear();
    TipoElemento ya_cargado;
    int contador = 0;

    if(p_es_vacia(p)){

        return contador;
    }

    else{

        while(!p_es_vacia(p)){

            ya_cargado = p_desapilar(p);

            contador++;

            p_apilar(P_Auxiliar, ya_cargado);
        }

        while(!p_es_vacia(P_Auxiliar)){

            ya_cargado = p_desapilar(P_Auxiliar);

            p_apilar(p, ya_cargado);
        }
    }

    free(P_Auxiliar);

    return contador;
}
























//ejercicio 3 .

bool p_ej3_iguales(Pila p1, Pila p2){

    Pila P_Auxiliar = p_crear();

    TipoElemento elem_p1;
    TipoElemento elem_p2;
    TipoElemento elem;

    bool iguales = true;

    if(p_ej2_cantidadelementos(p1) != p_ej2_cantidadelementos(p2)){

        printf(" Las PILAS no poseen la misma cantidad de elementos, por lo que nunca seran iguales!\n");
        free(P_Auxiliar);
        return false;
    }

    else if((p_ej2_cantidadelementos(p1) == 0) && (p_ej2_cantidadelementos(p2) == 0)){

        printf(" Las PILAS no poseen elementos!\n");

        free(P_Auxiliar);

        return false;
    }

    else{

        while(!p_es_vacia(p1) && !p_es_vacia(p2)){

            elem_p1 = p_desapilar(p1);
            elem_p2 = p_desapilar(p2);

            if(elem_p1->clave != elem_p2->clave){

                iguales = false;

                p_apilar(p1, elem_p1);
                p_apilar(p2, elem_p2);
                break;
            }

            else{

                elem = te_crear_con_valor(elem_p1->clave, elem_p2);
                p_apilar(P_Auxiliar, elem);
            }
        }

        while(!p_es_vacia(P_Auxiliar)){

            elem = p_desapilar(P_Auxiliar);

            elem_p1 = te_crear(elem->clave);

            elem_p2 = (TipoElemento) elem->valor;

            p_apilar(p1, elem_p1);
            p_apilar(p2, elem_p2);
        }

        free(P_Auxiliar);

        return iguales;
    }
}



















//ejercicio 4 .

char *p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){

    int indice = 0, i = 0;
    int numero = nrobasedecimal;
    Pila Conversion = p_crear(), binario = p_crear();
    TipoElemento Elemento = te_crear(0);
    char Digitos[] = "0123456789ABCDEF\0";
    char *Resultado = (char *) calloc(12, sizeof(char));
    bool negativo = false;

    if(nrootrabase == 10){

        sprintf(Resultado, "%d", numero);
        return Resultado;
    }

    if(numero == 0){

        Resultado[0] = '0';
        return Resultado;
    }

    if(numero < 0 ){

        negativo = true;
        numero *= -1;
        Resultado[0] = '-';
        indice++;
    }

    do{

        TipoElemento Elemento2 = te_crear(numero % nrootrabase);
        p_apilar(Conversion, Elemento2);
        numero /= nrootrabase;
    }
    while(numero > 0);

    Invertir_Pila(Conversion);

    while(!p_es_vacia(Conversion)){

        Elemento = p_desapilar(Conversion);
        Resultado[indice] = Digitos[Elemento->clave];
        indice ++;
    }

    return Resultado;
}


void Invertir_Pila(Pila p){

    Pila Auxiliar = p_crear();

    while(!p_es_vacia(p)){

        TipoElemento te = p_desapilar(p);
        p_apilar(Auxiliar, te);
    }

    while(!p_es_vacia(Auxiliar)){

        TipoElemento te = p_desapilar(Auxiliar);
        p_apilar(p, te);
    }

    free(Auxiliar);
}
























//ejercicio 5 .

Pila  p_ej5_invertir(Pila p){

    Pila Invertida = p_crear();
    Pila P_auxiliar = p_crear();
    TipoElemento ya_cargado;

    while(!p_es_vacia(p)){

        ya_cargado = p_desapilar(p);

        TipoElemento elem = te_crear(ya_cargado->clave);

        p_apilar(P_auxiliar, ya_cargado);
        p_apilar(Invertida, elem);
    }

    while(!p_es_vacia(P_auxiliar)){

        ya_cargado = p_desapilar(P_auxiliar);
        p_apilar(p, ya_cargado);
    }

    free(P_auxiliar);

    return Invertida;
}























//ejercicio 6 .

Pila p_ej6_eliminarclave_iterativo(Pila p, int clave){

    Pila Resultado = p_crear();
    Pila P_auxiliar = p_crear();
    TipoElemento ya_cargado;

    if(p_es_vacia(p)){

        printf(" La PILA esta vacia!, no se pueden borrar elementos!\n");
        return Resultado;
    }

    while(!p_es_vacia(p)){

        ya_cargado = p_desapilar(p);
        p_apilar(P_auxiliar, ya_cargado);
    }

    while(!p_es_vacia(P_auxiliar)){

        ya_cargado = p_desapilar(P_auxiliar);

        if(ya_cargado->clave == clave){

            p_apilar(p, ya_cargado);
        }

        else{

            TipoElemento elem = te_crear(ya_cargado->clave);

            p_apilar(Resultado, elem);
            p_apilar(p, ya_cargado);
        }
    }

    free(P_auxiliar);

    return Resultado;
}


Pila p_ej6_eliminarclave(Pila p, int clave){

    Pila Resultado = p_crear();

    p_ej6_eliminarclave_recursivo(p, Resultado, clave);

    return Resultado;
}


void p_ej6_eliminarclave_recursivo(Pila p, Pila Resultado, int clave){

    if(p_es_vacia(p)){

        return;
    }

    TipoElemento ya_cargado = p_desapilar(p);

    p_ej6_eliminarclave_recursivo(p, Resultado, clave);

    if(ya_cargado->clave != clave){

        TipoElemento elem = te_crear(ya_cargado->clave);
        p_apilar(Resultado, elem);
    }

    p_apilar(p, ya_cargado);

}























//ejercicio 7 .

Pila p_ej7_eliminarclave(Pila p1, Pila p2){

    Pila Resultado = p_crear();
    Pila P_auxiliar1 = p_crear();
    Pila P_auxiliar2 = p_crear();
    TipoElemento elem_p1;
    bool esta_p2, esta_resultado;

    if(p_es_vacia(p1) && p_es_vacia(p2)){

        printf(" Las PILAS estan vacias, por lo que no tienen elementos en comun!\n");
        free(P_auxiliar1);
        free(P_auxiliar2);

        return Resultado;
    }

    else if(p_es_vacia(p1) || p_es_vacia(p2)){

        printf(" Una de las PILAS esta vacia, por lo que no tienen elementos en comun!\n");
        free(P_auxiliar1);
        free(P_auxiliar2);

        return Resultado;
    }

    else{

        while(!p_es_vacia(p1)){

            elem_p1 = p_desapilar(p1);

            esta_p2 = p_ej2_existeclave(p2, elem_p1->clave);

            if(esta_p2){

                esta_resultado = p_ej2_existeclave(Resultado, elem_p1->clave);

                if(!esta_resultado){

                    TipoElemento elem = te_crear(elem_p1->clave);

                    p_apilar(P_auxiliar2, elem);
                }
            }

            p_apilar(P_auxiliar1, elem_p1);
        }

        while(!p_es_vacia(P_auxiliar1)){

            elem_p1 = p_desapilar(P_auxiliar1);
            p_apilar(p1, elem_p1);
        }

        free(P_auxiliar1);

        while(!p_es_vacia(P_auxiliar2)){

            elem_p1 = p_desapilar(P_auxiliar2);
            p_apilar(Resultado, elem_p1);
        }

        free(P_auxiliar2);
    }

    return Resultado;
}























//ejercicio 8 .

Pila p_ej8_sacarrepetidos(Pila p){

    Pila Resultado = p_crear();
    Pila p_auxiliar = p_crear();
    Pila p_auxiliar2 = p_crear();

    TipoElemento elem_p;
    int clave_actual, contador, cantidad_elementos = p_ej2_cantidadelementos(p);
    bool empezar;

    if(p_es_vacia(p)){

        printf(" La PILA esta vacia, por lo que no se puede realizar el ejercicio!\n");
        free(p_auxiliar2);
        free(p_auxiliar);

        return Resultado;
    }

    do{

        contador = 0;
        empezar = false;

        while(!p_es_vacia(p)){

            elem_p = p_desapilar(p);

            if(!p_ej2_existeclave(p_auxiliar2, elem_p->clave) && !empezar){

                empezar = true;
                clave_actual = elem_p->clave;
            }

            if(empezar && (clave_actual == elem_p->clave)){

                contador ++;
            }

            p_apilar(p_auxiliar, elem_p);
        }

        while(!p_es_vacia(p_auxiliar)){

            elem_p = p_desapilar(p_auxiliar);
            p_apilar(p, elem_p);
        }

        if(empezar){

            int *veces = (int*)calloc(1, sizeof(int));
            *veces = contador;

            TipoElemento elem_r = te_crear_con_valor(clave_actual, veces);
            p_apilar(p_auxiliar2, elem_r);
        }

        cantidad_elementos--;
    }
    while(cantidad_elementos > 0);

    while(!p_es_vacia(p_auxiliar2)){

        elem_p = p_desapilar(p_auxiliar2);
        p_apilar(Resultado, elem_p);
    }

    free(p_auxiliar2);
    free(p_auxiliar);

    return Resultado;
}


void p_mostrar_con_Valor(Pila Resultado){

    Pila p_auxiliar = p_crear();
    TipoElemento elem_resultado;

    printf(" Contenido de la PILA REPETIDOS: ");
    while(!p_es_vacia(Resultado)){

        elem_resultado = p_desapilar(Resultado);
        int valor = *(int*)elem_resultado->valor;

        printf("[%d; %d] ", elem_resultado->clave, valor);
        p_apilar(p_auxiliar, elem_resultado);
    }

    while(!p_es_vacia(p_auxiliar)){

        elem_resultado = p_desapilar(p_auxiliar);
        p_apilar(Resultado, elem_resultado);
    }

    free(p_auxiliar);

    printf("\n");
}
