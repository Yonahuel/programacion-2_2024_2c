#include "funciones.h"
#include "validaciones.h"
#include "tipo_elemento.h"
#include "nodo.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



void mostrar_AB(NodoArbol Padre, int nivel){

    TipoElemento cargado = n_recuperar(Padre);

    printf(" %d Nivel[%d]\n", cargado->clave, nivel);
    
    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(!a_es_rama_nula(HI)){

        mostrar_AB(HI, nivel + 1);
    }

    if(!a_es_rama_nula(HD)){

        mostrar_AB(HD, nivel + 1);
    }
}

Lista Cargar_Arbol_Binario_PO(ArbolBinario Arbol, NodoArbol Padre){

    Lista Contenido = l_crear();

    TipoElemento R = n_recuperar(Padre);
    
    TipoElemento Nuevo = te_crear(R->clave);
    l_agregar(Contenido, Nuevo);
    
    int Nivel = 0;

    proceso_interno_PO(Arbol, Padre, Contenido, Nivel);

    return Contenido;
}



void proceso_interno_PO(ArbolBinario Arbol, NodoArbol Padre, Lista Contenido, int nivel){

    if(a_es_lleno(Arbol)){

        return;
    }

    TipoElemento Actual = n_recuperar(Padre);

    printf(" Nos encontramos en el Nodo que posee la Clave %d del Nivel [%d] !\n", Actual->clave, nivel);
    printf(" Ingrese la Clave de su Hijo Izquierdo (Ingrese ' * ' si no tiene Hijo Izquierdo): ");
    char *clave = Ingresar_Numero_A_PN();

    if(clave[0] != '*'){

        int nombre = String_A_Entero(clave);

        TipoElemento Nuevo = te_crear(nombre);
        l_agregar(Contenido, Nuevo);

        TipoElemento HI = te_crear(nombre);
        NodoArbol CaminoI = a_conectar_hi(Arbol, Padre, HI);

        system("cls");
        proceso_interno_PO(Arbol, CaminoI, Contenido, nivel + 1);
    }

    system("cls");

    if(a_es_lleno(Arbol)){

        return;
    }

    else{

        TipoElemento Actual = n_recuperar(Padre);

        printf(" Nos encontramos en el Nodo que posee la Clave %d del Nivel [%d] !\n", Actual->clave, nivel);
        printf(" Ingrese la Clave de su Hijo Derecho (Ingrese ' * ' si no tiene Hijo Derecho): ");
        char *clave = Ingresar_Numero_A_PN();

        if(clave[0] != '*'){

            int nombre = String_A_Entero(clave);

            TipoElemento Nuevo = te_crear(nombre);
            l_agregar(Contenido, Nuevo);

            TipoElemento HD = te_crear(nombre);
            NodoArbol CaminoD = a_conectar_hd(Arbol, Padre, HD);

            system("cls");
            proceso_interno_PO(Arbol, CaminoD, Contenido, nivel + 1);
        }

        system("cls");
    }
}



Lista Cargar_Arbol_Binario_POU(ArbolBinario Arbol, NodoArbol Padre){

    Lista Contenido = l_crear();

    TipoElemento R = n_recuperar(Padre);
    
    TipoElemento Nuevo = te_crear(R->clave);
    l_agregar(Contenido, Nuevo);

    int Nivel = 0;

    proceso_interno_POU(Arbol, Padre, Contenido, Nivel);

    return Contenido;
}



void proceso_interno_POU(ArbolBinario Arbol, NodoArbol Padre, Lista Contenido, int nivel){

    if(a_es_lleno(Arbol)){

        return;
    }

    TipoElemento Actual = n_recuperar(Padre);
    NodoArbol CaminoI;
    int clave;
    bool agregado = false;
    
    do{

        printf(" Nos encontramos en el Nodo que posee la Clave %d del Nivel [%d] !\n", Actual->clave, nivel);
        printf(" Ingrese la Clave de su Hijo Izquierdo (Ingrese ' * ' si no tiene Hijo Izquierdo): ");

        char *n = Ingresar_Numero_A_PN();

        if(n[0] == '*'){

            system("cls");
            break;
        }

        else{

            clave = String_A_Entero(n);

            if(!l_buscar(Contenido, clave)){

                agregado = true;
                TipoElemento nuevo = te_crear(clave);
                l_agregar(Contenido, nuevo);

                TipoElemento HI = te_crear(clave);
                CaminoI = a_conectar_hi(Arbol, Padre, HI);
            }

            else{

                printf(" Ya existe un Nodo con la CLave %d! Ingrese otra diferente!\n", clave);
                system("pause");
            }
        }

        system("cls");
    }
    while(!agregado);

    if(agregado){

        proceso_interno_POU(Arbol, CaminoI, Contenido, nivel + 1);
    }

    if(a_es_lleno(Arbol)){

        return;
    }

    NodoArbol CaminoD;
    agregado = false;
    
    do{

        printf(" Nos encontramos en el Nodo que posee la Clave %d del Nivel [%d] !\n", Actual->clave, nivel);
        printf(" Ingrese la Clave de su Hijo Derecho (Ingrese ' * ' si no tiene Hijo Derecho): ");

        char *n = Ingresar_Numero_A_PN();

        if(n[0] == '*'){

            system("cls");
            break;
        }

        else{

            clave = String_A_Entero(n);

            if(!l_buscar(Contenido, clave)){

                agregado = true;
                TipoElemento nuevo = te_crear(clave);
                l_agregar(Contenido, nuevo);

                TipoElemento HD = te_crear(clave);
                CaminoD = a_conectar_hd(Arbol, Padre, HD);
            }

            else{

                printf(" Ya existe un Nodo con la CLave %d! Ingrese otra diferente!\n", clave);
                system("pause");
            }
        }

        system("cls");
    }
    while(!agregado);

    if(agregado){

        proceso_interno_POU(Arbol, CaminoD, Contenido, nivel + 1);
    }
}

Lista Cargar_Arbol_Nario_POU(ArbolBinario Arbol, NodoArbol Actual){

    Lista Contenido = l_crear();

    TipoElemento A = n_recuperar(Actual);
    
    TipoElemento Nuevo = te_crear(A->clave);
    l_agregar(Contenido, Nuevo);

    int Nivel = 0, nhijo = 1, padre = A->clave; 

    proceso_interno_Nario_POU(Arbol, Actual, Contenido, Nivel, nhijo, padre);

    return Contenido;
}

void proceso_interno_Nario_POU(ArbolBinario Arbol, NodoArbol Actual, Lista Contenido, int nivel, int nhijo, int padre){

    if(a_es_lleno(Arbol)){

        return;
    }

    NodoArbol Hijos;
    int clave;
    bool agregado = false;

    do{
        
        printf(" Nos encontramos en el Nodo que posee la Clave %d del Nivel [%d] (Padre del Nodo a Cargar)!\n", padre, nivel);
        printf(" Ingrese la Clave del Hijo Numero 1 (Ingrese ' * ' si no tiene Hijo): ");

        char *n = Ingresar_Numero_A_PN();

        if(n[0] == '*'){

            system("cls");
            break;
        }

        else{

            clave = String_A_Entero(n);

            if(!l_buscar(Contenido, clave)){

                agregado = true;
                TipoElemento nuevo = te_crear(clave);
                l_agregar(Contenido, nuevo);

                TipoElemento HI = te_crear(clave);
                Hijos = a_conectar_hi(Arbol, Actual, HI);
            }

            else{

                printf(" Ya existe un Nodo con la CLave %d! Ingrese otra diferente!\n", clave);
                system("pause");
            }
        }

        system("cls");
    }
    while(!agregado);

    if(agregado){

        proceso_interno_Nario_POU(Arbol, Hijos, Contenido, nivel + 1, 1, clave);
    }

    if(a_es_lleno(Arbol)){

        return;
    }

    if(nivel != 0){

        
        NodoArbol Hermanos;
        agregado = false;

        do{

            printf(" Nos encontramos en el Nodo que posee la Clave %d del Nivel [%d] (Hermano del Nodo a cargar)!\n", padre, nivel);
            printf(" Ingrese la Clave del Hermano (Ingrese ' * ' si no tiene otro hermano): ", nhijo + 1);

            char *n = Ingresar_Numero_A_PN();

            if(n[0] == '*'){

                system("cls");
                break;
            }

            else{

                clave = String_A_Entero(n);

                if(!l_buscar(Contenido, clave)){

                    agregado = true;
                    TipoElemento nuevo = te_crear(clave);
                    l_agregar(Contenido, nuevo);

                    TipoElemento HD = te_crear(clave);
                    Hermanos = a_conectar_hd(Arbol, Actual, HD);
                }

                else{

                    printf(" Ya existe un Nodo con la CLave %d! Ingrese otra diferente!\n", clave);
                    system("pause");
                }
            }

            system("cls");
        }
        while(!agregado);

        if(agregado){

            proceso_interno_Nario_POU(Arbol, Hermanos, Contenido, nivel, nhijo + 1, clave);
        }
    }
}




















// Ejercicio 2 .


Lista Obtener_Hojas_AB(ArbolBinario Arbol){

    Lista L = l_crear();

    NodoArbol Raiz = a_raiz(Arbol);

    B_Hojas(Raiz, L);

    return L;
}




void B_Hojas(NodoArbol Padre, Lista L){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        TipoElemento cargado = n_recuperar(Padre);
        TipoElemento hoja = te_crear(cargado->clave);

        l_agregar(L, hoja);
        return;
    }

    else{

        if(!a_es_rama_nula(HI)){

            B_Hojas(HI, L);
        }

        if(!a_es_rama_nula(HD)){

            B_Hojas(HD, L);
        }
    }
}




Lista Obtener_Internos_AB(ArbolBinario Arbol){

    Lista L = l_crear();

    NodoArbol Raiz = a_raiz(Arbol);

    B_Internos(Raiz, L, 0);

    return L;
}




void B_Internos(NodoArbol Padre, Lista L, int Nivel){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    else{

        if(Nivel != 0){

            TipoElemento cargado = n_recuperar(Padre);
            TipoElemento interno = te_crear(cargado->clave);

            l_agregar(L, interno);
        }

        if(!a_es_rama_nula(HI)){

            B_Internos(HI, L, Nivel + 1);
        }

        if(!a_es_rama_nula(HD)){

            B_Internos(HD, L, Nivel + 1);
        }
    }
}



Lista Obtener_Ocurrencias_AB(ArbolBinario Arbol, int clave){

    Lista L = l_crear();

    NodoArbol Raiz = a_raiz(Arbol);

    B_Ocurrencias(Raiz, L, clave, 0);

    return L;    
}




void B_Ocurrencias(NodoArbol Padre, Lista L, int clave, int Nivel){

    TipoElemento cargado = n_recuperar(Padre);

    if(cargado->clave == clave){

        TipoElemento ocurrencia = te_crear_con_valor(Nivel, Padre);
        l_agregar(L, ocurrencia);
    }

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(!a_es_rama_nula(HI)){

        B_Ocurrencias(HI, L, clave, Nivel + 1);
    }

    if(!a_es_rama_nula(HD)){

        B_Ocurrencias(HD, L, clave, Nivel + 1);
    }
}




void mostrar_Ocurrencias(Lista Ocurrencias, int clave){

    int veces = 1;
    int longuitud = l_longitud(Ocurrencias);

    if(l_es_vacia(Ocurrencias)){

        printf("\n No se encontraron Ocurrencias de la clave %d !\n", clave);
        return;
    }

    else{

        Iterador iter = iterador(Ocurrencias);
        printf("\n Se encontraron %d ocurrencias de la clave %d en el Arbol Binario!\n", longuitud, clave);

        while(hay_siguiente(iter)){

            TipoElemento elem = siguiente(iter);
            NodoArbol Nodo = (NodoArbol)elem->valor;
            NodoArbol HI = n_hijoizquierdo(Nodo);
            NodoArbol HD = n_hijoderecho(Nodo);

            printf(" Coincidencia %d: se hallo en la Nivel [%d] ! ", veces, elem->clave);

            if(a_es_rama_nula(HI)){

                printf(" HI --- > NULL. ");
            }

            else{

                TipoElemento h = n_recuperar(HI);
                printf(" HI --- > %d. ", h->clave);
            }

            if(a_es_rama_nula(HD)){

                printf(" HD --- > NULL. \n");
            }

            else{

                TipoElemento h = n_recuperar(HD);
                printf(" HD --- > %d. \n", h->clave);
            }

            veces ++;

        }

        free(iter);
    }
}
























// Ejercicio 3 .


int *Obtener_Padre_AB(ArbolBinario Arbol, int clave){

    NodoArbol Raiz = a_raiz(Arbol);
    TipoElemento R = n_recuperar(Raiz);

    if(R->clave == clave){

        return NULL;
    }

    bool encontrado = false;
    int *resultado = NULL;

    B_Padre_AB(Raiz, &resultado, &encontrado, clave);

    return resultado;
}



void B_Padre_AB(NodoArbol Padre, int **resultado, bool *encontrado, int clave){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    if(*encontrado == false){

        if(!a_es_rama_nula(HI)){

            TipoElemento I = n_recuperar(HI);

            if(I->clave == clave){

                *encontrado = true;
                TipoElemento P = n_recuperar(Padre);

                *resultado = malloc(sizeof(int));
                **resultado = P->clave; 
            }

            else{

                B_Padre_AB(HI, resultado, encontrado, clave);
            }
        }

        if(!a_es_rama_nula(HD) && *encontrado == false){

            TipoElemento D = n_recuperar(HD);

            if(D->clave == clave){

                *encontrado = true;
                TipoElemento P = n_recuperar(Padre);

                *resultado = malloc(sizeof(int));
                **resultado = P->clave;
            }

            else{

                B_Padre_AB(HD, resultado, encontrado, clave);
            }
        }
    }
}




Lista Obtener_Hijos_AB(ArbolBinario Arbol, int clave){

    NodoArbol Raiz = a_raiz(Arbol);

    Lista Hijos = l_crear();

    bool encontrado = false;

    B_Hijos_AB(Raiz, Hijos, &encontrado, clave);

    return Hijos;
}



void B_Hijos_AB(NodoArbol Padre, Lista Hijos, bool* encontrado, int clave){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    TipoElemento P = n_recuperar(Padre);

    if(P->clave == clave){

        *encontrado = true;

        if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

            return;
        }

        if(!a_es_rama_nula(HI)){

            TipoElemento aux = n_recuperar(HI);
            TipoElemento H = te_crear(aux->clave);

            l_agregar(Hijos, H);
        }

        if(!a_es_rama_nula(HD)){

            TipoElemento aux = n_recuperar(HD);
            TipoElemento H = te_crear(aux->clave);

            l_agregar(Hijos, H);
        }
        
        return;
    }

    if(*encontrado == false){

        if(!a_es_rama_nula(HI)){

            B_Hijos_AB(HI, Hijos, encontrado, clave);
        }

        if(!a_es_rama_nula(HD) && *encontrado == false){

            B_Hijos_AB(HD, Hijos, encontrado, clave);
        }
    }
}




int *Obtener_Hermano_AB(ArbolBinario Arbol, int clave){

    NodoArbol Raiz = a_raiz(Arbol);
    TipoElemento R = n_recuperar(Raiz);

    if(R->clave == clave){

        return NULL;
    }

    int *Hermano = NULL;
    bool encontrado = false;

    B_Hermano_AB(Raiz, &Hermano, &encontrado, clave);

    return Hermano;
}



void B_Hermano_AB(NodoArbol Padre, int **Hermano, bool *encontrado, int clave){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    if(!a_es_rama_nula(HI)){

        TipoElemento N = n_recuperar(HI);

        if(N->clave == clave){

            *encontrado = true;
            
            if(!a_es_rama_nula(HD)){

                TipoElemento H = n_recuperar(HD);
                
                *Hermano = malloc(sizeof(int));
                **Hermano = H->clave;

                return;
            }

            return;
        }

        else{

            B_Hermano_AB(HI, Hermano, encontrado, clave);
        }
    }

    if(!a_es_rama_nula(HD) && *encontrado == false){

        TipoElemento N = n_recuperar(HD);

        if(N->clave == clave){

            *encontrado = true;
            
            if(!a_es_rama_nula(HI)){

                TipoElemento H = n_recuperar(HI);

                *Hermano = malloc(sizeof(int));
                **Hermano = H->clave;

                return;
            }

            return;
        }

        else{

            B_Hermano_AB(HD, Hermano, encontrado, clave);
        }
    }
}




int Obtener_Nivel_AB(ArbolBinario Arbol, int clave){

    NodoArbol Raiz = a_raiz(Arbol);

    int nivel = 0;
    int actual = 0;
    bool encontrado = false;

    C_Nivel_AB(Raiz, &nivel, &encontrado, actual, clave);

    return nivel;
}



void C_Nivel_AB(NodoArbol Padre, int *nivel, bool *encontrado, int actual, int clave){

    TipoElemento P = n_recuperar(Padre);

    if(P->clave == clave){

        *encontrado = true;
        *nivel = actual;
        return;
    }

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    if(!a_es_rama_nula(HI)){

        C_Nivel_AB(HI, nivel, encontrado, actual + 1, clave);
    }

    if(!a_es_rama_nula(HD) && *encontrado == false){

        C_Nivel_AB(HD, nivel, encontrado, actual + 1, clave);
    }
}





int Obtener_ALtura_Subrama_AB(ArbolBinario Arbol, int clave){

    NodoArbol Raiz = a_raiz(Arbol);

    int altura = 1;
    int actual = 1;
    bool encontrado = false;

    C_Altura_Subrama_AB(Raiz, &altura, encontrado, actual, clave);

    return altura;
}



void C_Altura_Subrama_AB(NodoArbol Padre, int *Altura, bool encontrado, int actual, int clave){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD) && encontrado == true){

        if(actual > *Altura){

            *Altura = actual;
        } 

        return;
    }

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    TipoElemento P = n_recuperar(Padre);

    if(P->clave == clave && encontrado == false){

        encontrado = true;
    }

    if(!a_es_rama_nula(HI)){

        if(encontrado == true){

            C_Altura_Subrama_AB(HI, Altura, encontrado, actual + 1, clave);
        }

        else{

            C_Altura_Subrama_AB(HI, Altura, encontrado, actual, clave);
        }
    }

    if(!a_es_rama_nula(HD)){

        if(encontrado == true){

            C_Altura_Subrama_AB(HD, Altura, encontrado, actual + 1, clave);
        }

        else{

            C_Altura_Subrama_AB(HD, Altura, encontrado, actual, clave);
        }
    }
}





Lista Obtener_MismoNivel_AB(ArbolBinario Arbol, int clave){

    NodoArbol Raiz = a_raiz(Arbol);

    Lista Mismo_Nivel = l_crear();

    int n_Actual = 0;

    O_Mismo_Nivel_AB(Raiz, Mismo_Nivel, n_Actual, clave);

    return Mismo_Nivel;
}



void O_Mismo_Nivel_AB(NodoArbol Padre, Lista Mismo_Nivel, int actual, int nivel){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(actual == nivel){

        TipoElemento P = n_recuperar(Padre);
        TipoElemento N = te_crear(P->clave);
        l_agregar(Mismo_Nivel, N);
        
        return;
    }

    if(!a_es_rama_nula(HI)){

        O_Mismo_Nivel_AB(HI, Mismo_Nivel, actual + 1, nivel);
    }

    if(!a_es_rama_nula(HD)){

        O_Mismo_Nivel_AB(HD, Mismo_Nivel, actual + 1, nivel);
    }
}























// Ejercicio 4 .


Lista Contenido_Nario_A(ArbolBinario Arbol){

    Lista Recorrido = l_crear();
    Cola A_Recorrer = c_crear();

    bool ingresar = true;
        
    NodoArbol Raiz = a_raiz(Arbol);
    TipoElemento cargado = n_recuperar(Raiz);

    TipoElemento nuevo = te_crear(cargado->clave);
    l_agregar(Recorrido, nuevo);

    Contenido_Anchura_Nario(Raiz, Recorrido, A_Recorrer, 0, &ingresar);

    free(A_Recorrer);

    return Recorrido;
}




void Contenido_Anchura_Nario(NodoArbol Padre, Lista Recorrido, Cola A_recorrer, int Nivel, bool *ingresar){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    if(!a_es_rama_nula(HI)){

        TipoElemento Proximo = te_crear_con_valor(0, HI);
        c_encolar(A_recorrer, Proximo);
    }

    if(!a_es_rama_nula(HD)){

        TipoElemento aux = n_recuperar(HD);
        TipoElemento Nuevo = te_crear(aux->clave);

        l_agregar(Recorrido, Nuevo);

        Contenido_Anchura_Nario(HD, Recorrido, A_recorrer, Nivel + 1, ingresar);
    }

    if(Nivel == 0 && (*ingresar)){

        if(!c_es_vacia(A_recorrer)){

            *ingresar = false;

            while(!c_es_vacia(A_recorrer)){

                TipoElemento aux = c_desencolar(A_recorrer);

                NodoArbol Siguiente = (NodoArbol) aux->valor;

                aux = n_recuperar(Siguiente);
                TipoElemento Nuevo = te_crear(aux->clave);
                l_agregar(Recorrido, Nuevo);

                Contenido_Anchura_Nario(Siguiente, Recorrido, A_recorrer, Nivel + 1, ingresar);
            }
        }
    }
}




int Obtener_Hojas_Nario(ArbolBinario Arbol){

    int cantidad = 0;

    NodoArbol Raiz = a_raiz(Arbol);

    Hojas_Nario(Raiz, &cantidad);

    return cantidad;
}




void Hojas_Nario(NodoArbol Padre, int *cantidad){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        (*cantidad)++;
        return;
    }

    if(!a_es_rama_nula(HD)){

        Hojas_Nario(HD, cantidad);
    }

    if(!a_es_rama_nula(HI)){

        Hojas_Nario(HI, cantidad);
    }

    else{

        (*cantidad)++;
    }
}




bool Comparar_Arboles_Narios(ArbolBinario Arbol1, ArbolBinario Arbol2){

    NodoArbol Raiz1 = a_raiz(Arbol1);
    NodoArbol Raiz2 = a_raiz(Arbol2);

    bool Similar = true;

    Calculo_Similar_Nario(Raiz1, Raiz2, &Similar);

    return Similar;
}



void Calculo_Similar_Nario(NodoArbol Padre1, NodoArbol Padre2, bool *similar){

    if(a_es_rama_nula(Padre1) && a_es_rama_nula(Padre2)){

        return;
    }

    if(a_es_rama_nula(Padre1) || a_es_rama_nula(Padre2)){

        *similar = false;
        return;
    }

    NodoArbol HI1 = n_hijoizquierdo(Padre1);
    NodoArbol HD1 = n_hijoderecho(Padre1);

    NodoArbol HI2 = n_hijoizquierdo(Padre2);
    NodoArbol HD2 = n_hijoderecho(Padre2);

    Calculo_Similar_Nario(HI1, HI2, similar);

    if(*similar == false){

        return;
    }

    else{

        Calculo_Similar_Nario(HD1, HD2, similar);
    }
}




TipoElemento Obtener_Padre_Nario(ArbolBinario Arbol, Lista Contenido){

    int clave;
    bool esta;
    bool encontrado = false;

    TipoElemento Resultado = te_crear(0);

    printf(" El contenido del Arbol Nario es: \n\n"); l_mostrar(Contenido);
    printf(" Ingrese el numero de una de las claves ateriormente mostrada para poder buscarle el Padre (Si ingresa otra, retornara NULL): ");
    clave = Ingreso_Entero_Positivo_Negativo();
    
    esta = l_buscar(Contenido, clave);
    
    if(!esta){

        printf("\n Ingreso una clave que no se encuentra en el Arbol N-ario! Resultado = NULL !\n");
        free(Resultado);

        return NULL;
    }

    NodoArbol Raiz = a_raiz(Arbol);
    TipoElemento comprobar = n_recuperar(Raiz);
    
    if(comprobar->clave == clave){

        free(Resultado);
        printf("\n El Nodo que ingreso es la Raid del Arbol N-ario! por lo que no tiene Padre!\n");

        return NULL;
    }

    O_Padre_Nario(Raiz, Resultado, comprobar->clave, &encontrado, clave);

    return Resultado;
}


void O_Padre_Nario(NodoArbol Nodo, TipoElemento Resultado, int p_actual, bool *encontrado, int clave){

    if(a_es_rama_nula(Nodo)){

        return;
    }

    TipoElemento contenido = n_recuperar(Nodo);

    if(contenido->clave == clave){

        *encontrado = true;

        Resultado->clave = p_actual;

        return;
    }

    NodoArbol HI = n_hijoizquierdo(Nodo);
    NodoArbol HD = n_hijoderecho(Nodo);

    O_Padre_Nario(HI, Resultado, contenido->clave, encontrado, clave);

    if(*encontrado == false){

        O_Padre_Nario(HD, Resultado, p_actual, encontrado, clave);
    }
}




Lista Obtener_Hermanos_Nario(ArbolBinario Arbol, Lista Contenido){

    Lista Hermanos = l_crear();
    bool esta, encontrado = false;
    int clave;
    int nivel = -1;

    printf(" El contenido del Arbol Nario es: \n\n"); l_mostrar(Contenido);
    printf(" Ingrese el numero de una de las claves ateriormente mostrada para poder buscarle los Hermanos (Si ingresa una que no se mostro, retornara la lista vacia): ");
    clave = Ingreso_Entero_Positivo_Negativo();
    
    esta = l_buscar(Contenido, clave);
    
    if(!esta){

        printf("\n La clave ingresada no se encuentra en el Arbol N-ario! por lo que no tiene Hermanos!\n");

        return Hermanos;
    }

    NodoArbol Raiz = a_raiz(Arbol);

    O_Hermanos_Nario(Raiz, Hermanos, &encontrado, &nivel, 0, clave);

    return Hermanos;
}




void O_Hermanos_Nario(NodoArbol Nodo, Lista Hermanos, bool *encontrado, int *nivel, int actual, int clave){

    if(a_es_rama_nula(Nodo)){

        return;
    }

    TipoElemento elem = n_recuperar(Nodo);

    if(elem->clave == clave && *encontrado == false){

        *encontrado = true;
        *nivel = actual;
    }

    NodoArbol HI = n_hijoizquierdo(Nodo);
    NodoArbol HD = n_hijoderecho(Nodo);

    O_Hermanos_Nario(HD, Hermanos, encontrado, nivel, actual, clave);

    if((actual == *nivel) && (*encontrado == true)){

        if(elem->clave != clave){

            TipoElemento Nuevo = te_crear(elem->clave);
            l_agregar(Hermanos, Nuevo);
        }
    }

    if(*encontrado == false){

        O_Hermanos_Nario(HI, Hermanos, encontrado, nivel, actual + 1, clave);
    }
}






















// Ejercicio 7 .


bool Determinar_Equivalencia_Binario(ArbolBinario Arbol1, ArbolBinario Arbol2){

    bool Equivalente = true;

    NodoArbol Raiz1 = a_raiz(Arbol1);
    NodoArbol Raiz2 = a_raiz(Arbol2);

    D_Equivalencia_B(Raiz1, Raiz2, &Equivalente);

    printf("\n Resultado: %s.\n", Equivalente ? "True" : "False");

    return Equivalente;
}




void D_Equivalencia_B(NodoArbol Nodo1, NodoArbol Nodo2, bool *Equivalente){

    if(a_es_rama_nula(Nodo1) && a_es_rama_nula(Nodo2)){

        return;
    }

    if(a_es_rama_nula(Nodo1) || a_es_rama_nula(Nodo2)){

        *Equivalente = false;
        return;
    }

    TipoElemento elem1 = n_recuperar(Nodo1);
    TipoElemento elem2 = n_recuperar(Nodo2);

    if(elem1->clave != elem2->clave){

        *Equivalente = false;
        return;
    }

    NodoArbol HI1 = n_hijoizquierdo(Nodo1);
    NodoArbol HD1 = n_hijoderecho(Nodo1);

    NodoArbol HI2 = n_hijoizquierdo(Nodo2);
    NodoArbol HD2 = n_hijoderecho(Nodo2);

    if(*Equivalente == true){

        D_Equivalencia_B(HI1, HI2, Equivalente);

        if(*Equivalente == true){

            D_Equivalencia_B(HD1, HD2, Equivalente);
        }
    }
}






















// Ejercicio 8 .


int Obtener_Altura_Nario(ArbolBinario Arbol){

    int Altura = 1;

    NodoArbol Raiz = a_raiz(Arbol);

    Altura_Nario(Raiz, &Altura, 1);

    return Altura;
}



void Altura_Nario(NodoArbol Nodo, int *Altura, int actual){

    NodoArbol HI = n_hijoizquierdo(Nodo);
    NodoArbol HD = n_hijoderecho(Nodo);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        if(*Altura < actual){

            *Altura = actual;
        }

        return;
    }

    if(!a_es_rama_nula(HI)){

        Altura_Nario(HI, Altura, actual + 1);
    }

    if(!a_es_rama_nula(HD)){

        Altura_Nario(HD, Altura, actual);
    }
}

int *Obtener_NivelNodo_Nario(ArbolBinario Arbol, Lista Contenido, int clave){

    int *Nivel = NULL;
    bool encontrado = false;

    if(!l_buscar(Contenido, clave)){

        printf("\n La clave ingresada no se encuentra en el Arbol N-ario! Resultado : NULL!\n");

        return Nivel;
    }

    NodoArbol Raiz = a_raiz(Arbol);

    O_Nivel_Nodo_Nario(Raiz, &Nivel, 0, &encontrado, clave);

    return Nivel;
}




void O_Nivel_Nodo_Nario(NodoArbol Nodo, int **nivel, int actual, bool *encontrado, int clave){

    TipoElemento N = n_recuperar(Nodo);

    if(N->clave == clave){

        *encontrado = true;
        *nivel = malloc(sizeof(int));
        **nivel = actual;

        return;
    }

    NodoArbol HI = n_hijoizquierdo(Nodo);
    NodoArbol HD = n_hijoderecho(Nodo);

    if(!a_es_rama_nula(HI) && *encontrado == false){

        O_Nivel_Nodo_Nario(HI, nivel, actual + 1, encontrado, clave);
    }

    if(!a_es_rama_nula(HD) && *encontrado == false){

        O_Nivel_Nodo_Nario(HD, nivel, actual, encontrado, clave);
    }
}

Lista Obtener_Internos_Nario(ArbolBinario Arbol){

    NodoArbol Raiz = a_raiz(Arbol);

    Lista Internos = l_crear();
    Cola proximo = c_crear();

    bool empezar = true;

    O_Internos_Nario(Raiz, Internos, proximo, &empezar, 0);

    free(proximo);

    return Internos;
}


void O_Internos_Nario(NodoArbol Padre, Lista Internos, Cola Proximo, bool *empezar, int nivel){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        return;
    }

    if(!a_es_rama_nula(HI)){

        TipoElemento sig = te_crear_con_valor(0, HI);
        c_encolar(Proximo, sig);

        if(nivel != 0){

            TipoElemento P = n_recuperar(Padre);

            TipoElemento inter = te_crear(P->clave);
            l_agregar(Internos, inter);
        }
    }

    if(!a_es_rama_nula(HD)){

        O_Internos_Nario(HD, Internos, Proximo, empezar, nivel);
    }

    if(*empezar == true){

        *empezar = false;

        while(!c_es_vacia(Proximo)){

            TipoElemento aux = c_desencolar(Proximo);
            NodoArbol H = (NodoArbol)aux->valor;

            O_Internos_Nario(H, Internos, Proximo, empezar, nivel + 1);
        }
    }
}

bool Determinar_NHojas_Nario(ArbolBinario Arbol){

    bool mismo_nivel = true;
    int *nivel = NULL;
    
    NodoArbol Raiz = a_raiz(Arbol);

    Verficiar_NHojas_Nario(Raiz, &mismo_nivel, &nivel, 0);

    return mismo_nivel;
}


void Verficiar_NHojas_Nario(NodoArbol Padre, bool *mismo_Nivel, int **Nivel, int actual){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI)){

        if(*Nivel == NULL){

            *Nivel = malloc(sizeof(int));
            **Nivel = actual;
        }

        if(**Nivel != actual){

            *mismo_Nivel = false;
            return;
        }
    }

    if(!a_es_rama_nula(HI) && *mismo_Nivel == true){

        Verficiar_NHojas_Nario(HI, mismo_Nivel, Nivel, actual + 1);
    }

    if(!a_es_rama_nula(HD) && *mismo_Nivel == true){

        Verficiar_NHojas_Nario(HD, mismo_Nivel, Nivel, actual);
    }
}























// Ejercicio 9 .

ArbolAVL De_Binario_a_Avl(ArbolBinario Arbol_Binario){

    ArbolAVL AVL = avl_crear();

    NodoArbol Raiz_B = a_raiz(Arbol_Binario);

    Generar_AVL(Raiz_B, AVL);

    return AVL;
}




void Generar_AVL(NodoArbol Nodo, ArbolAVL Arbol){

    if(a_es_rama_nula(Nodo)){

        return;
    }

    TipoElemento contenido = n_recuperar(Nodo);
    TipoElemento Elem = te_crear(contenido->clave);

    avl_insertar(Arbol, Elem);

    NodoArbol HI = n_hijoizquierdo(Nodo);
    NodoArbol HD = n_hijoderecho(Nodo);

    Generar_AVL(HI, Arbol);
    Generar_AVL(HD, Arbol);
}




int Comparar_Binario_AVL(ArbolBinario Arbol_Binario, ArbolAVL Arbol_Avl){

    int Altura_Binario = 1, Altura_AVL = 1;

    NodoArbol Raiz_B = a_raiz(Arbol_Binario);
    NodoArbol Raiz_AVL = avl_raiz(Arbol_Avl);

    Obtener_Altura_AB_ABB_AVL(Raiz_B, &Altura_Binario, 1);
    Obtener_Altura_AB_ABB_AVL(Raiz_AVL, &Altura_AVL, 1);

    printf("\n Altura del Arbol Binario: %d. \n", Altura_Binario);
    printf("\n Altura del Arbol AVL: %d. \n", Altura_AVL);

    if(Altura_Binario > Altura_AVL){

        printf("\n Resultado de la comparacion: %d.\n", Altura_Binario - Altura_AVL);
        return Altura_Binario - Altura_AVL;
    }

    else{

        printf("\n Resultado de la comparacion: %d.\n", Altura_AVL - Altura_Binario);
        return Altura_AVL - Altura_Binario;
    }
}




void Obtener_Altura_AB_ABB_AVL(NodoArbol Padre, int *Altura, int Actual){

    NodoArbol HI = n_hijoizquierdo(Padre);
    NodoArbol HD = n_hijoderecho(Padre);

    if(a_es_rama_nula(HI) && a_es_rama_nula(HD)){

        if(*Altura < Actual){

            *Altura = Actual;
        }

        return;
    }

    Obtener_Altura_AB_ABB_AVL(HI, Altura, Actual + 1);
    Obtener_Altura_AB_ABB_AVL(HD, Altura, Actual + 1);
}
























// Ejercicio 10 .


void Cargar_AVL_ABB(ArbolAVL AVL, ArbolBinarioBusqueda ABB, int cantidad_elementos){

    int num;

    while(cantidad_elementos > 0){

        do{

            num = rand() % 1000 + 1;
        }
        while((avl_buscar(AVL, num) != NULL) && (abb_buscar(ABB, num) != NULL));

        TipoElemento Contenido = te_crear(num);
        avl_insertar(AVL, Contenido);
        abb_insertar(ABB, Contenido);

        cantidad_elementos--;
    }
}




void Comparar_Altura_ABB_AVL(ArbolAVL AVL, Lista Alturas_AVL, ArbolBinarioBusqueda ABB, Lista Alturas_ABB, Lista Diferencia_Alturas){

    int Altura_avl = 1, Altura_abb = 1;

    NodoArbol Raiz_avl = avl_raiz(AVL);
    NodoArbol Raiz_abb = abb_raiz(ABB);

    Obtener_Altura_AB_ABB_AVL(Raiz_avl, &Altura_avl, 1);
    Obtener_Altura_AB_ABB_AVL(Raiz_abb, &Altura_abb, 1);

    TipoElemento altu1 = te_crear(Altura_avl);
    l_agregar(Alturas_AVL, altu1);

    TipoElemento altu2 = te_crear(Altura_abb);
    l_agregar(Alturas_ABB, altu2);

    if(Altura_avl > Altura_abb){

        TipoElemento altu3 = te_crear(Altura_avl - Altura_abb);
        l_agregar(Diferencia_Alturas, altu3);
        
        return;
    }

    else{

        TipoElemento altu3 = te_crear(Altura_abb - Altura_avl);
        l_agregar(Diferencia_Alturas, altu3);
        
        return;
    }
}




void Mostrar_Resultados(Lista AVL, Lista ABB, Lista Diferencia){

    Iterador iter_AVL = iterador(AVL);
    Iterador iter_ABB = iterador(ABB);
    Iterador iter_Diferencia = iterador(Diferencia);
    int i = 1;

    while(hay_siguiente(iter_AVL) && hay_siguiente(iter_ABB) && hay_siguiente(iter_Diferencia)){

        TipoElemento cont_avl = siguiente(iter_AVL);
        TipoElemento cont_abb = siguiente(iter_ABB);
        TipoElemento cont_diferencia = siguiente(iter_Diferencia);

        printf("\n Altura AVL corrida %d: %d. \n", i, cont_avl->clave);
        printf("\n Altura ABB corrida %d: %d. \n", i, cont_abb->clave);
        printf("\n Diferencia Obtenida en la corrida %d: %d. \n\n\n", i, cont_diferencia->clave);
        i++;
    }

    free(iter_ABB);
    free(iter_AVL);
    free(iter_Diferencia);
}