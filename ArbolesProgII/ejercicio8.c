#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


int main(){

    int bandera, Altura_Arbol, *Nivel_Nodo, clave;
    bool puedo = false, Hojas_MNivel;

    Lista Contenido, Nodos_Internos;

    TipoElemento Raiz;
    NodoArbol Principal;
    ArbolBinario Arbol;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 8 'TP ARBOLES'!\n\n\n");
        printf(" 1.     Crear el Arbol N-ario y cargarle elementos (Solo puede usarla si no esta cargado aun).\n");
        printf(" 2.     Borrar el Arbol N-ario Actual.\n");
        printf(" 3.     Determinar la Altura del Arbol N-ario.\n");
        printf(" 4.     Obtener el Nivel de un Nodo del Arbol N-ario.\n");
        printf(" 5.     Listar los Nodos internos del Arbol N-ario.\n");
        printf(" 6.     Determinar si las Hojas del Arbol N-ario estan todas en el mismo nivel.\n");
        printf(" 0.     Salir del Sistema\n\n");
        printf(" Ingresa el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 6)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 6]!\n");
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

                    Arbol = a_crear();

                    printf("\n Ingresa la Clave de la Raiz del Arbol N-ario: ");
                    Raiz = te_crear(Ingreso_Entero_Positivo_Negativo());

                    Principal = a_establecer_raiz(Arbol, Raiz);

                    Contenido = Cargar_Arbol_Nario_POU(Arbol, Principal);

                    if(a_es_lleno(Arbol)){

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

                    free(Arbol);
                    free(Principal);
                    free(Raiz);
                    free(Contenido);

                    printf("\n Se ah borrado el Arbol N-ario!\n");
                }

                else{

                    printf("\n No se cargo todavia un Arbol N-ario, por lo que no se puede realizar esta accion!\n");
                }

                break;

            case 3:

                if(puedo){

                    Altura_Arbol = Obtener_Altura_Nario(Arbol);

                    printf("\n El Arbol N-ario es de altura %d !\n", Altura_Arbol);
                }

                else{

                    printf("\n No se cargo todavia un Arbol N-ario, por lo que no se puede realizar esta accion!\n");
                }

                break;

            case 4:

                if(puedo){

                    printf(" Se imprimira el Contenido del Arbol Binario:\n");
                    l_mostrar(Contenido);

                    printf(" Ingrese la Clave de uno de los Nodos ya mostrados (Aquel a buscar su Nivel): ");
                    clave = Ingreso_Entero_Positivo_Negativo();

                    Nivel_Nodo = Obtener_NivelNodo_Nario(Arbol, Contenido, clave);

                    if(Nivel_Nodo != NULL){

                        printf("\n El Nodo con la clave %d se encuentra en el Nivel [%d] !\n", clave, *Nivel_Nodo);
                    }
                }

                else{

                    printf("\n No se cargo todavia un Arbol N-ario, por lo que no se puede realizar esta accion!\n");
                }

                break;

            case 5:

                if(puedo){

                    Nodos_Internos = Obtener_Internos_Nario(Arbol);

                    printf("\n Los Nodos Internos del Arbol N-ario son: \n\n");
                    l_mostrar(Nodos_Internos);
                    
                    free(Nodos_Internos);
                }

                else{

                    printf("\n No se cargo todavia un Arbol N-ario, por lo que no se puede realizar esta accion!\n");
                }

                break;

            case 6:

                if(puedo){

                    Hojas_MNivel = Determinar_NHojas_Nario(Arbol);

                    printf("\n Se encuentran en el mismo nivel las Hojas del Arbol N-ario?: %s !\n", Hojas_MNivel ? "True" : "False");
                }

                else{

                    printf("\n No se cargo todavia un Arbol N-ario, por lo que no se puede realizar esta accion!\n");
                }

                break;

        }
        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}