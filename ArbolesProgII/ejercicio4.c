#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

int main(){

    int bandera, Cantidad_Hojas;
    bool Similar, puedo = false;

    TipoElemento Nodo_Padre;
    Lista Cargado_n1, Cargado_n2, Recorrido_Anchura, Hermanos;

    TipoElemento Raiz_Nario1, Raiz_Nario2;
    NodoArbol Principal_Nario1, Principal_Nario2;
    ArbolBinario Arbol_Nario1, Arbol_Nario2;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 4 'TP ARBOLES'!\n\n\n");
        printf(" 1.     Crear el Arbol N-ario y cargarle elementos (Solo puede usarla si no esta cargado aun).\n");
        printf(" 2.     Borrar el Arbol N-ario Actual.\n");
        printf(" 3.     Obtener el Listado de Claves del recorrido en Anchura del Arbol N-ario.\n");
        printf(" 4.     Obtener la Cantidad de Hojas que posee el Arbol N-ario.\n");
        printf(" 5.     Determinar si el Arbol N-ario actual es Similar a otro Arbol N-ario.\n");
        printf(" 6.     Dado un Nodo del Arbol N-ario, obtener el Tipoelemento del Padre.\n");
        printf(" 7.     Dado un Nodo del Arbol N-ario, obtener a todos sus Hermanos.\n");
        printf(" 0.     Salir del Sistema\n\n");
        printf(" Ingresa el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 7)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 7]!\n");
            printf(" Ingrese el numero de la accion a realizar: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        switch(bandera){

            case 0:

                break;

            case 1:

                if(!puedo){

                    puedo = true;

                    Arbol_Nario1 = a_crear();

                    printf("\n Ingresa la Clave de la Raiz del Arbol N-ario: ");
                    Raiz_Nario1 = te_crear(Ingreso_Entero_Positivo_Negativo());

                    Principal_Nario1 = a_establecer_raiz(Arbol_Nario1, Raiz_Nario1);

                    Cargado_n1 = Cargar_Arbol_Nario_POU(Arbol_Nario1, Principal_Nario1);

                    if(a_es_lleno(Arbol_Nario1)){

                        printf(" El Arbol N-ario se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }
                }

                else{

                    printf("\n Ya existe un Arbol N-ario! Si desea realizar esta accion, borrelo primero\n");
                }

                break;

            case 2:

                if(puedo){
                    
                    puedo = false;

                    free(Arbol_Nario1);
                    free(Principal_Nario1);
                    free(Raiz_Nario1);
                    free(Cargado_n1);

                    printf("\n Se ah borrado el Arbol N-ario!\n");
                }

                else{

                    printf("\n No se cargo todavia un Arbol N-ario, por lo que no se puede realizar esta accion!\n");
                }

                break;
            
            case 3:

                if(!puedo){

                    printf("\n Todavia no creo ni cargo el Arbol N-ario! Hagalo para poder realizar el ejercicio!\n");
                }

                else{

                    Recorrido_Anchura = Contenido_Nario_A(Arbol_Nario1);

                    printf("\n El contenido del Arbol N-ario con el Recorrido en Anchura es: \n\n");
                    l_mostrar(Recorrido_Anchura);

                    free(Recorrido_Anchura);
                }

                break;

            case 4:

                if(!puedo){

                    printf("\n Todavia no creo ni cargo el Arbol N-ario! Hagalo para poder realizar el ejercicio!\n");
                }

                else{

                    Cantidad_Hojas = Obtener_Hojas_Nario(Arbol_Nario1);

                    printf("\n El Arbol N-ario tiene %d Hojas!\n\n", Cantidad_Hojas);
                }

                break;

            case 5:

                if(!puedo){

                    printf("\n Todavia no cargo el Arbol N-ario 1! hagalo primero para poder realizar este ejercicio!\n");
                }

                else{

                    Arbol_Nario2 = a_crear();

                    printf("\n Ingresa la Clave de la Raiz del nuevo Arbol N-ario a comparar con el ya cargado: ");
                    Raiz_Nario2 = te_crear(Ingreso_Entero_Positivo_Negativo());

                    Principal_Nario2 = a_establecer_raiz(Arbol_Nario2, Raiz_Nario2);

                    Cargado_n2 = Cargar_Arbol_Nario_POU(Arbol_Nario2, Principal_Nario2);

                    if(a_es_lleno(Arbol_Nario2)){

                        printf(" El Arbol Binario se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }

                    Similar = Comparar_Arboles_Narios(Arbol_Nario1, Arbol_Nario2);

                    printf("\n Son Similares los Arboles N-arios?: %s.\n", Similar ? "True" : "False");
                }

                free(Arbol_Nario2);
                free(Principal_Nario2);
                free(Raiz_Nario2);
                free(Cargado_n2);

                break;

            case 6:
                
                if(!puedo){
                    
                    printf("\n Todavia no creo ni cargo el Arbol N-ario! Hagalo para poder realizar el ejercicio!\n");
                }

                else{

                    Nodo_Padre = Obtener_Padre_Nario(Arbol_Nario1, Cargado_n1);

                    if(Nodo_Padre != NULL){

                        printf("\n El Padre es: %d\n", Nodo_Padre->clave);
                    }
                }

                free(Nodo_Padre);

                break;

            case 7:

                if(!puedo){

                    printf("\n Todavia no creo ni cargo el Arbol N-ario! Hagalo para poder realizar el ejercicio!\n");
                }

                else{

                    Hermanos = Obtener_Hermanos_Nario(Arbol_Nario1, Cargado_n1);

                    printf("\n Hermanos Obtenidos: \n\n");
                    l_mostrar(Hermanos);
                }

                free(Hermanos);

                break;
        }

        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}