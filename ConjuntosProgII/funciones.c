#include "funciones.h"
#include "validaciones.h"
#include "tipo_elemento.h"
#include "nodo.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>



void cargar_conjunto_manual(Conjunto C, int tam){

    int clave;

    for(int i = 0; i < tam; i++){

        bool puedo = true;

        printf(" Ingrese el numero %d del conjunto: ", i+1);
        clave = Ingreso_Entero_Positivo_Negativo();
        
        if(i > 0){

            if(cto_pertenece(C, clave)){

                printf(" El numero ' %d ' ya se encuentra en el conjunto! Intente con otro\n");
                i --;
                puedo = false;
            }
        }
        
        if(puedo){

            TipoElemento elem = te_crear(clave);
            cto_agregar(C, elem);
        }
    }
}

void cargar_conjunto_Naturales(Conjunto C, int tam){

    int clave;

    for(int i = 0; i < tam; i++){

        bool puedo = true;

        printf(" Ingrese el numero %d del conjunto: ", i+1);
        clave = Ingresar_Entero_Positivo();
        
        if(i > 0){

            if(cto_pertenece(C, clave)){

                printf(" El numero ' %d ' ya se encuentra en el conjunto! Intente con otro\n");
                i --;
                puedo = false;
            }
        }
        
        if(puedo){

            TipoElemento elem = te_crear(clave);
            cto_agregar(C, elem);
        }
    }
}




void Cargar_ej3(Lista Coleccion, int tam){

    int cant_elementos, clave;

    for(int i = 0; i < tam; i++){

        printf(" Cuantos elementos tendra el Conjunto %d? (Numero positivo entre [ 0 ; 100 ]): ", i+1);
        cant_elementos = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cant_elementos, 0, 100)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 100]!\n");
            printf(" Cuantos elementos tendra el Conjunto %d? (Numero positivo entre [ 0 ; 100]): ", i+1);
            cant_elementos = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        Conjunto C = cto_crear();

        for(int j = 0; j < cant_elementos; j++){
            
            bool puedo = true;

            printf(" Ingrese el numero %d del conjunto %d: ", j+1, i+1);
            clave = Ingreso_Entero_Positivo_Negativo();
            
            if(j > 0){

                if(cto_pertenece(C, clave)){

                    printf(" El numero ' %d ' ya se encuentra en el conjunto %d! Intente con otro\n", i+1);
                    j --;
                    puedo = false;
                }
            }
            
            if(puedo){

                TipoElemento elem = te_crear(clave);
                cto_agregar(C, elem);
            }
        }

        TipoElemento Conj = te_crear_con_valor(i+1, C);
        l_agregar(Coleccion, Conj);
    }
}



Conjunto Obtener_Union_Coleccion(Lista coleccion){

    Iterador iter = iterador(coleccion);
    Conjunto Resultado = cto_crear();
    TipoElemento cont, nuevo, elem_lista;

    while(hay_siguiente(iter)){

        elem_lista = siguiente(iter);
        Conjunto actual = (Conjunto)elem_lista->valor;
        
        int i = 1;

        while(i <= cto_cantidad_elementos(actual)){

            cont = cto_recuperar(actual, i);

            nuevo = te_crear(cont->clave);

            cto_agregar(Resultado, nuevo);

            i++;
        }
    }

    return Resultado;
}



Conjunto Obtener_interseccion_Coleccion(Lista coleccion){

    int i;
    bool primer = true;
    Iterador iter = iterador(coleccion);
    TipoElemento elem_lista, contenido, nuevo;
    Conjunto actual, resultado = cto_crear();

    while(hay_siguiente(iter)){

        i = 1;
        elem_lista = siguiente(iter);
        actual = (Conjunto)elem_lista->valor;

        if(primer){
            
            primer = false;

            if(cto_cantidad_elementos(actual) == 0){

                free(iter);

                return resultado;
            }

            while(i <= cto_cantidad_elementos(actual)){

                contenido = cto_recuperar(actual, i);

                nuevo = te_crear(contenido->clave);

                cto_agregar(resultado, nuevo);

                i++;
            }
        }

        else{

            if(cto_cantidad_elementos(actual) == 0){

                free(resultado);
                free(iter);

                return cto_crear();
            }

            while(i <= cto_cantidad_elementos(resultado)){

                contenido = cto_recuperar(resultado, i);

                if(!cto_pertenece(actual, contenido->clave)){

                    cto_borrar(resultado, contenido->clave);
                }

                i++;
            }
        }
    }

    free(iter);

    return resultado;
}



void mostrar_coleccion_conjuntos(Lista coleccion){
    
    int i = 1;
    Iterador iter = iterador(coleccion);
    TipoElemento elem_lista, contenido;
    Conjunto actual;

    while(hay_siguiente(iter)){

        elem_lista = siguiente(iter);
        actual = (Conjunto)elem_lista->valor;

        printf(" Conjunto ' i ': ", i); cto_mostrar(actual);
        printf("\n\n");

        i++;
    }
}




bool subconjunto_de(Conjunto Principal, Conjunto Subconjunto){

    int i = 1;
    TipoElemento cont;
    if(cto_cantidad_elementos(Subconjunto) > cto_cantidad_elementos(Principal)){

        return false;
    }

    else{

        while(i <= cto_cantidad_elementos(Subconjunto)){

            cont = cto_recuperar(Subconjunto, i);

            if(!cto_pertenece(Principal, cont->clave)){

                return false;
            }

            i++;
        }
    }

    return true;
}



Conjunto diferencia_simetrica(Conjunto A, Conjunto B){

    Conjunto diferenciaAB = cto_diferencia(A, B);
    Conjunto diferenciaBA = cto_diferencia(B, A);

    return cto_union(diferenciaAB, diferenciaBA);
}




bool Subconjunto_Propio(Conjunto Principal, Conjunto Subconjunto){

    int i = 1;
    TipoElemento cont;

    while(i <= cto_cantidad_elementos(Subconjunto)){

        cont = cto_recuperar(Subconjunto, i);

        if(!cto_pertenece(Principal, cont->clave)){

            return false;
        }

        i++;
    }

    i = 1;

    while(i <= cto_cantidad_elementos(Principal)){

        cont = cto_recuperar(Principal, i);

        if(!cto_pertenece(Subconjunto, cont->clave)){

            return true;
        }
        i++;
    }

    return false;
}



bool es_subconjunto_total(Conjunto X, Conjunto Y) {
    
    Conjunto resultado = cto_diferencia(X, Y);
    
    return cto_es_vacio(resultado);
}

bool es_subconjunto_parcial(Conjunto X, Conjunto Y){

    int cantidad_elementosX = cto_cantidad_elementos(X);
    
    Conjunto resultado = cto_diferencia(X, Y);
    
    int cantidad_elementosY = cto_cantidad_elementos(resultado);
    
    return cantidad_elementosY <= (cantidad_elementosX / 2);

}

void determinar_subconjuntos(Conjunto A, Conjunto B, Conjunto C){
    
    Conjunto conjuntos[3] = {A, B, C};
    
    char* nombres[3] = {"A", "B", "C"};

    for(int i = 0; i < 3; i++){

        for(int j = 0; j < 3; j++){

            if(i != j){

                if(es_subconjunto_total(conjuntos[i], conjuntos[j])){

                    printf(" '%s' es un subconjunto total de '%s'\n", nombres[i], nombres[j]);
                } 
                
                else if(es_subconjunto_parcial(conjuntos[i], conjuntos[j])){
                    
                    printf(" '%s' es un subconjunto parcial de '%s'\n", nombres[i], nombres[j]);
                }
            }
        }
    }
}




bool verificar_mismos_elementos(Conjunto A, Conjunto B){

    int i = 1;
    TipoElemento cont;

    if(cto_cantidad_elementos(A) == 0 && cto_cantidad_elementos(B) == 0){

        return true;
    }

    if(cto_cantidad_elementos(A) != cto_cantidad_elementos(B)){

        return false;
    }

    else{

        while(i <= cto_cantidad_elementos(A)){

            cont = cto_recuperar(A, i);

            if(!cto_pertenece(B, cont->clave)){

                return false;
            }

            i++;
        }

        i = 1;

        while(i <= cto_cantidad_elementos(B)){

            cont = cto_recuperar(B, i);

            if(!cto_pertenece(A, cont->clave)){

                return false;
            }
            
            i++;
        }
    }

    return true;
}