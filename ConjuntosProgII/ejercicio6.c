#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

/*
COMPLEJIDAD ALGORITMICA:

La complejidad algoritmica depende del TAD utilizado.

Si se utiliza Conjuntos de listas la complejidad sera de O(n^2), ya que, dentro del bucle while de subconjuntoproriop se utiliza la 
operacion de cto_pertenece(), la cual utiliza otro bucle para poder recorrer de forma lineal la lista.

En cambio al utilizar el TAD de conjuntos con arboles AVL la complejidad pasara a ser O(n . log n) ya que el recorrido de un arbol AVL
es mas eficiente y no hace falta recorrer todo el arbol, por lo que la cantidad de iteraciones se disminuyen, obteniendo una busqueda
de log n, la cual, si esta dentro de un bucle while, la complejidad seria O(n . log n).


*/


int main(){

    int bandera, elementos;
    bool puedo = false, AB, BA;

    Conjunto ConjuntoA, ConjuntoB;


    do{

        printf("\t\t\t Bienvenido al menu del Ejercicio 6 'TP CONJUNTOS'!!\n\n\n");
        printf(" 1.     Crear y cargar los Conjuntos.\n");
        printf(" 2.     Borrar los Conjuntos.\n");
        printf(" 3.     Verificar si alguno es SUBCONJUNTO PROPIO del otro.\n");
        printf(" 4.     Mostrar el contenido de los Conjuntos.\n");
        printf(" 0.     Salir del Menu.\n\n");
        printf("    Ingrese el numero de la accion a realizar: ");
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

                if(!puedo){

                    puedo = true;

                    ConjuntoA = cto_crear();
                    ConjuntoB = cto_crear();

                    printf(" Cuantos elementos tendra el Conjunto 'A'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1000 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'A'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_Naturales(ConjuntoA, elementos);

                    printf(" Cuantos elementos tendra el Conjunto 'B'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1000 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'B'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_Naturales(ConjuntoB, elementos);


                    printf(" Se cargaron los conjuntos correctamente!\n");
                }

                else{

                    printf(" Ya cargo los 3 conjuntos! realice la accion ' 2 ' del menu antes de poder volver a cargarlos!\n");
                }

                break;

            case 2:

                if(puedo){

                    puedo = false;

                    free(ConjuntoA);
                    free(ConjuntoB);    

                    printf(" Conjuntos borrados correctamente!\n");
                }

                else{

                    printf(" No hay conjuntos que borrar!\n");
                }

                break;

            case 3:

                if(puedo){

                    if(Subconjunto_Propio(ConjuntoA, ConjuntoB)){

                        printf(" El Conjunto ' B ' es un subconjunto propio de ' A '!\n");
                    }

                    else if(Subconjunto_Propio(ConjuntoB, ConjuntoA)){

                        printf(" El Conjunto ' A ' es un subconjunto propio de ' B '!\n");
                    }

                    else{

                        printf(" Ninguno es un subconjunto propio del otro!\n");
                    }
                }

                else{

                    printf(" No hay Conjuntos cargados, por lo que no se puede realizar el ejercicio!\n");
                }

                break;

            case 4:

                if(puedo){
                 
                    printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                    printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                    
                }

                else{

                    printf(" No hay conjuntos que mostrar!\n");
                }
                break; 

        }

        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}