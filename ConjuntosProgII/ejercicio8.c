#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


/*

COMPLEJIDAD ALGORITIMICA: 

La solucion propuesta es de complejidad O(n^2), ya que dentro de los bucles llamo a la funcion cto_pertenece, la cual usa otro while
recorriendo todos los elementos del conjunto. (implementacion listas).

La solucion propuesta es de complejidad O(n . log n), ya que dentro de los bucles llamo a la funcion cto_pertenece, la cual recorre
el arbol AVL ordenado, disminuyendo la cantidad de iteraciones. (implementacion AVL).
*/

int main(){

    int bandera, elementos;
    bool puedo = false;

    Conjunto ConjuntoA, ConjuntoB;


    do{

        printf("\t\t\t Bienvenido al menu del Ejercicio 8 'TP CONJUNTOS'!!\n\n\n");
        printf(" 1.     Crear y cargar los Conjuntos.\n");
        printf(" 2.     Borrar los Conjuntos.\n");
        printf(" 3.     Verificar si tienen ambos los mismos elementos.\n");
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

                    if(verificar_mismos_elementos(ConjuntoA, ConjuntoB)){

                        printf(" Los Conjuntos tienen los mismos elementos!\n");
                    }

                    else{

                        printf(" Los Conjuntos no tienen los mismos elementos!\n");
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