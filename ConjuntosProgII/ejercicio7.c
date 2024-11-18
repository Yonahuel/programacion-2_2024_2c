#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


/*

COMPLEJIDAD ALGORITMICA:

Para listas: Las funciones tienen complejidad O(n^3).

Para AVL: Las funciones tienen complejidad O(n^2 . log n).

*/


int main(){

    int bandera, elementos;
    bool puedo = false;

    Conjunto ConjuntoA, ConjuntoB, ConjuntoC;


    do{

        printf("\t\t\t Bienvenido al menu del Ejercicio 7 'TP CONJUNTOS'!!\n\n\n");
        printf(" 1.     Crear y cargar los 3 Conjuntos.\n");
        printf(" 2.     Borrar los Conjuntos.\n");
        printf(" 3.     Verificar de quien son SUBCONJUNTOS PARCIALES O TOTALES.\n");
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
                    ConjuntoC = cto_crear();

                    printf(" Cuantos elementos tendra el Conjunto 'A'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1000 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'A'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(ConjuntoA, elementos);

                    printf(" Cuantos elementos tendra el Conjunto 'B'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1000 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'B'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(ConjuntoB, elementos);

                    printf(" Cuantos elementos tendra el Conjunto 'C'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1000 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'C'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(ConjuntoC, elementos);

                    printf(" Se cargaron los 3 conjuntos correctamente!\n");
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
                    free(ConjuntoC);

                    printf(" Conjuntos borrados correctamente!\n");
                }

                else{

                    printf(" No hay conjuntos que borrar!\n");
                }

                break;

            case 3:

                if(puedo){

                    determinar_subconjuntos(ConjuntoA, ConjuntoB, ConjuntoC);
                }

                else{

                    printf(" No hay Conjuntos cargados, por lo que no se puede realizar el ejercicio!\n");
                }

                break;

            case 4:

                if(puedo){
                 
                    printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                    printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                    printf(" Conjunto C: "); cto_mostrar(ConjuntoC);
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