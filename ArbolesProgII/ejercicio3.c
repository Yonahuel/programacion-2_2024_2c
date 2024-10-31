#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


int main(){

    int bandera, clave;
    bool puedo = false;

    int *Clave_Padre, *Clave_Hermano, Nivel_Encontrado, Altura_Subrama;
    Lista Hijos, Mismo_Nivel, Contenido;

    TipoElemento Raiz;
    NodoArbol N_Principal;
    ArbolBinario Arbol;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 3 'TP ARBOLES'!\n\n\n");
        printf(" 1.     Crear el Arbol Binario y cargarle elementos (Solo puede usarla si no esta cargado aun).\n");
        printf(" 2.     Borrar el Arbol Binario Actual.\n");
        printf(" 3.     Dada una clave, buscar su Nodo y retornar la clave de su Padre.\n");
        printf(" 4.     Dada una clave, buscar su Nodo y retornar una Lista con sus Hijos.\n");
        printf(" 5.     Dada una clave, buscar su Nodo y retornar la clave de su Hermano.\n");
        printf(" 6.     Dada una clave, buscar su Nodo y retornar el Nivel en el que se encuentra.\n");
        printf(" 7.     Dada una clave, buscar su Nodo y retornar la Altura que posee su Subrama.\n");
        printf(" 8.     Dada una clave, buscar su Nodo y retornar una Lista con los Nodos que esten en el mismo Nivel.\n");
        printf(" 9.     Imprimir el contenido del Arbol Binario.\n");
        printf(" 0.     Salir del Sistema\n\n");
        printf(" Ingresa el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 9)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 9]!\n");
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

                    printf("\n Ingresa la Clave de la Raiz del Arbol Binario: ");
                    Raiz = te_crear(Ingreso_Entero_Positivo_Negativo());

                    N_Principal = a_establecer_raiz(Arbol, Raiz);

                    Contenido = Cargar_Arbol_Binario_POU(Arbol, N_Principal);

                    if(a_es_lleno(Arbol)){

                        printf(" El Arbol Binario se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }
                }

                else{

                    printf("\n Ya cargo el Arbol Binario! si desea cargar otro, primero ejecute la accion ' 2 ' del Menu!\n");
                }

                break;

            case 2:

                if(puedo){

                    free(N_Principal);
                    free(Arbol);
                    free(Raiz);
                    free(Contenido);

                    puedo = false;
                    printf("\n Se ah borrado el Arbol Binario!\n");
                }

                else{

                    printf("\n No hay un Arbol Binario para borrar!\n");
                }

                break;

            case 3:

                if(puedo){

                    do{

                        printf(" Se imprimira el Contenido del Arbol Binario:\n");
                        l_mostrar(Contenido);

                        printf(" Ingrese la Clave de uno de los Nodos ya mostrados (Aquel a buscar su Padre): ");
                        clave = Ingreso_Entero_Positivo_Negativo();

                        if(!l_buscar(Contenido, clave)){

                            printf(" Ingreso Invalido! Debe ingresar la clave de uno de los Nodos Mostrados!\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    while(!l_buscar(Contenido, clave));

                    Clave_Padre = Obtener_Padre_AB(Arbol, clave);

                    if(Clave_Padre == NULL){

                        printf("\n El Nodo que posee la clave %d es la Raiz del Arbol Binario! No posee un Padre!\n");
                    }

                    else{

                        printf("\n El Padre del Nodo que tiene la clave %d es: %d !\n", clave, *Clave_Padre);
                    }

                }

                else{

                    printf("\n No se Cargo ningun Arbol Binario! para realizar este ejercicio debe Cargarlo con la accion ' 1 ' del menu!\n");
                }
                
                break;

            case 4:

                if(puedo){

                    do{

                        printf(" Se imprimira el Contenido del Arbol Binario:\n");
                        l_mostrar(Contenido);

                        printf(" Ingrese la Clave de uno de los Nodos ya mostrados (Aquel a buscar sus Hijos): ");
                        clave = Ingreso_Entero_Positivo_Negativo();

                        if(!l_buscar(Contenido, clave)){

                            printf(" Ingreso Invalido! Debe ingresar la clave de uno de los Nodos Mostrados!\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    while(!l_buscar(Contenido, clave));

                    Hijos = Obtener_Hijos_AB(Arbol, clave);

                    if(l_es_vacia(Hijos)){

                        printf("\n El Nodo con la Clave %d no posee ningun Hijo!\n");
                        l_mostrar(Hijos);
                    }

                    else{

                        printf("\n Hijo/s: \n");
                        l_mostrar(Hijos);
                    }

                    free(Hijos);
                }

                else{

                    printf("\n No se Cargo ningun Arbol Binario! para realizar este ejercicio debe Cargarlo con la accion ' 1 ' del menu!\n");
                }

                break;

            case 5:

                if(puedo){

                    do{

                        printf(" Se imprimira el Contenido del Arbol Binario:\n");
                        l_mostrar(Contenido);

                        printf(" Ingrese la Clave de uno de los Nodos ya mostrados (Aquel a buscar su Hermano): ");
                        clave = Ingreso_Entero_Positivo_Negativo();

                        if(!l_buscar(Contenido, clave)){

                            printf(" Ingreso Invalido! Debe ingresar la clave de uno de los Nodos Mostrados!\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    while(!l_buscar(Contenido, clave));

                    Clave_Hermano = Obtener_Hermano_AB(Arbol, clave);

                    if(Clave_Hermano == NULL){

                        printf("\n El nodo con la clave %d no posee ningun hermano!\n", clave);
                    }

                    else{

                        printf("\n El Hermano del Nodo con la clave %d es: %d !\n", clave, *Clave_Hermano);
                    }
                    
                }

                else{

                    printf("\n No se Cargo ningun Arbol Binario! para realizar este ejercicio debe Cargarlo con la accion ' 1 ' del menu!\n");
                }

                break;

            case 6:
                
                if(puedo){

                    do{

                        printf(" Se imprimira el Contenido del Arbol Binario:\n");
                        l_mostrar(Contenido);

                        printf(" Ingrese la Clave de uno de los Nodos ya mostrados (Aquel a saber su Nivel): ");
                        clave = Ingreso_Entero_Positivo_Negativo();

                        if(!l_buscar(Contenido, clave)){

                            printf(" Ingreso Invalido! Debe ingresar la clave de uno de los Nodos Mostrados!\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    while(!l_buscar(Contenido, clave));

                    Nivel_Encontrado = Obtener_Nivel_AB(Arbol, clave);

                    printf("\n El Nivel del Nodo con la clave %d es: %d !\n", clave, Nivel_Encontrado);
                }

                else{

                    printf("\n No se Cargo ningun Arbol Binario! para realizar este ejercicio debe Cargarlo con la accion ' 1 ' del menu!\n");
                }

                break;

            case 7:

                if(puedo){

                    do{

                        printf(" Se imprimira el Contenido del Arbol Binario:\n");
                        l_mostrar(Contenido);

                        printf(" Ingrese la Clave de uno de los Nodos ya mostrados (Aquel a saber la Altura de su subrama): ");
                        clave = Ingreso_Entero_Positivo_Negativo();

                        if(!l_buscar(Contenido, clave)){

                            printf(" Ingreso Invalido! Debe ingresar la clave de uno de los Nodos Mostrados!\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    while(!l_buscar(Contenido, clave));

                    Altura_Subrama = Obtener_ALtura_Subrama_AB(Arbol, clave);

                    printf("\n La altura de la subrama con la raiz %d es: %d\n", clave, Altura_Subrama);
                }

                else{

                    printf("\n No se Cargo ningun Arbol Binario! para realizar este ejercicio debe Cargarlo con la accion ' 1 ' del menu!\n");
                }

                break;

            case 8:

                if(puedo){

                    printf(" Ingrese un Nivel para buscar a aquellos Nodos que esten en el: ");
                    clave = Ingresar_Entero_Positivo();

                    Mismo_Nivel = Obtener_MismoNivel_AB(Arbol, clave);

                    if(l_es_vacia(Mismo_Nivel)){

                        printf("\n No existe ese nivel en el arbol Binario!\n");
                        l_mostrar(Mismo_Nivel);
                    }

                    else{

                        printf("Nodos que se encuentran en el Nivel %d: \n", clave);
                        l_mostrar(Mismo_Nivel);
                    }

                    free(Mismo_Nivel);
                }

                else{

                    printf("\n No se Cargo ningun Arbol Binario! para realizar este ejercicio debe Cargarlo con la accion ' 1 ' del menu!\n");
                }

                break;

            case 9:

                if(puedo){

                    printf(" Contenido del Arbol Binario: \n\n");
                    mostrar_AB(a_raiz(Arbol), 0);
                }

                else{

                    printf(" No se cargo el Arbol Binario! ejecute la accion ' 1 ' del menu primero!\n");
                }

                break;

        }

        system("pause");
        system("cls");

    }
    while(bandera != 0);

    return 0;
}