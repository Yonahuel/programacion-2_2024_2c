#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

int main(){

    int bandera;
    bool Equivalente, puedo1 = false, puedo2 = false;

    Lista Contenido1, Contenido2;

    TipoElemento Raiz1, Raiz2;
    NodoArbol Principal1, Principal2;
    ArbolBinario Arbol1, Arbol2;


    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 7 'TP ARBOLES'!\n\n\n");
        printf(" 1.     Crear y cargar el Arbol Binario 1 (Solo se puede usar cuando no este cargado).\n");
        printf(" 2      Crear y cargar el Arbol Binario 2 (Solo se puede usar cuando no este cargado).\n");
        printf(" 3.     Borrar un Arbol Binario.\n");
        printf(" 4.     Determinar si los Arboles ingresados son Equivalentes o no (Debe cargar ambos Arboles Binarios).\n");
        printf(" 0.     Salir del Sistema.\n\n");
        printf(" Ingresa el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 4)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 4]!\n");
            printf(" Ingrese el numero de la accion a realizar: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }


        switch(bandera){

            case 0:

                break;

            case 1:

                if(!puedo1){
                    
                    puedo1 = true;

                    Arbol1 = a_crear();

                    printf(" Ingrese la Clave de la Raiz del Arbol Binario 1: ");
                    Raiz1 = te_crear(Ingreso_Entero_Positivo_Negativo());

                    Principal1 = a_establecer_raiz(Arbol1, Raiz1);

                    Contenido1 = Cargar_Arbol_Binario_PO(Arbol1, Principal1);

                    if(a_es_lleno(Arbol1)){

                        printf(" El Arbol Binario 1 se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }
                }

                else{

                    printf("\n Ya cargo el Arbol Binario 1! si desea cargar otro, primero ejecute la accion ' 3 ' del Menu para borrarlo!\n");
                }

                break;

            case 2:

                if(!puedo2){
                    
                    puedo2 = true;

                    Arbol2 = a_crear();
                    
                    printf(" Ingrese la Clave de la Raiz del Arbol Binario 2: ");
                    Raiz2 = te_crear(Ingreso_Entero_Positivo_Negativo());

                    Principal2 = a_establecer_raiz(Arbol2, Raiz2);

                    Contenido2 = Cargar_Arbol_Binario_PO(Arbol2, Principal2);

                    if(a_es_lleno(Arbol2)){

                        printf(" El Arbol Binario 2 se ah llenado, por lo que no se le pueden cargar mas Nodos!\n");
                    }
                }

                else{

                    printf("\n Ya cargo el Arbol Binario 2! si desea cargar otro, primero ejecute la accion ' 3 ' del Menu para borrarlo!\n");
                }

                break;
            
            case 3:

                printf(" Que Arbol Binario vamos a borrar? (+ Ingrese ' 1 ' para eliminar el Arbol Binario 1; + Ingrese ' 2 ' para eliminar el Arbol Binario 2) : ");
                bandera = Ingresar_Entero_Positivo();

                while(!Validar_Intervalo_Enteros(bandera, 1, 2)){

                    printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 2]!\n");
                    printf(" Que Arbol Binario vamos a borrar? (+ Ingrese ' 1 ' para eliminar el Arbol Binario 1; + Ingrese ' 2 ' para eliminar el Arbol Binario 2) : ");
                    bandera = Ingresar_Entero_Positivo();
                    fflush(stdin);
                }

                if(bandera == 1){

                    if(puedo1){

                        free(Raiz1);
                        free(Principal1);
                        free(Arbol1);
                        free(Contenido1);

                        puedo1 = false;
                    }

                    else{

                        printf("\n No se puede realizar esta accion ya que no cargo el Arbol Binario 1 todavia!\n");
                    }
                }

                else{

                    if(puedo2){

                        free(Raiz2);
                        free(Principal2);
                        free(Arbol2);
                        free(Contenido2);

                        puedo2 = false;
                    }

                    else{

                        printf("\n No se puede realizar esta accion ya que no cargo el Arbol Binario 2 todavia!\n");
                    }
                }
                
                break;

            case 4:

                if(!puedo1 && !puedo2){

                    printf("\n No se puede realizar el ejercicio ya que no creo ni cargo los Arboles Binarios!\n");
                }

                else if(!puedo1){

                    printf("\n No se puede realizar el ejercicio ya que no cargo el Arbol Binario 1 !\n");
                }

                else if(!puedo2){

                    printf("\n No se puede realizar el ejercicio ya que no cargo el Arbol Binario 2 !\n");
                }

                else{

                    Equivalente = Determinar_Equivalencia_Binario(Arbol1, Arbol2);
                }

                break;

        }

        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}