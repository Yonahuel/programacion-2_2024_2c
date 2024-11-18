#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


int main(){

    int bandera, elementos, clave;
    bool puedo = false;

    Lista coleccion;
    Conjunto Union, interseccion;


    do{

        printf("\t\t\t Bienvenido al menu del Ejercicio 3 'TP CONJUNTOS'!!\n\n\n");
        printf(" 1.     Crear y cargar la Coleccion de Conjuntos.\n");
        printf(" 2.     Borrar la Coleccion de Conjuntos.\n");
        printf(" 3.     Obtener la UNION de los Conjuntos que se encuentran en la Coleccion.\n");
        printf(" 4.     Obtener la INTERSECCION de los Conjuntos que se encuentran en la Coleccion.\n");
        printf(" 5.     Mostrar el contenido de la Coleccion de Conjuntos.\n");
        printf(" 0.     Salir del Menu.\n\n");
        printf("    Ingrese el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 5)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 5]!\n");
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

                    coleccion = l_crear();

                    printf(" Cuantos Conjuntos cargaremos? (Numero positivo entero entre [1 y 10]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 1, 10)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 10]!\n");
                        printf(" Cuantos Conjuntos cargaremos? (Numero positivo entero entre [1 y 10]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    Cargar_ej3(coleccion, elementos);
                }

                else{

                    printf(" Ya cargo la coleccion de Conjuntos! realice la accion ' 2 ' para poder cargar otros!\n");
                }

                break;

            case 2:

                if(puedo){

                    puedo = false;
                    
                    free(coleccion);
                    printf(" Se borro correctamente la Coleccion de Conjuntos!\n");
                }

                else{

                    printf(" No hay una Coleccion de Conjuntos para poder borrar!\n");
                }

                break;

            case 3:

                if(puedo){

                    Union = Obtener_Union_Coleccion(coleccion);
                    printf(" Resultado: "); cto_mostrar(Union);
                    
                    free(Union);
                }

                else{

                    printf(" No cargo todavia una coleccion de Conjuntos para poder realizar el ejercicio!\n");
                }

                break;

            case 4:

                if(puedo){

                    interseccion = Obtener_interseccion_Coleccion(coleccion);
                    printf(" Resultado: "); cto_mostrar(interseccion);
                    
                    free(interseccion);
                }

                else{

                    printf(" No cargo todavia una coleccion de Conjuntos para poder realizar el ejercicio!\n");
                }

                break;

            case 5:

                mostrar_coleccion_conjuntos(coleccion);

                break;

        }

        system("pause");
        system("cls");
    }
    while(bandera != 0);

    return 0;
}