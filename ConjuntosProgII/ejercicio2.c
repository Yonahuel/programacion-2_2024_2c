#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


int main(){

    int bandera, elementos, clave;
    bool puedo = false;
    
    Conjunto A, B;
    Conjunto Union, interseccion, diferencia, pertenenciaA, pertenenciaB;

    do{

        printf("\t\t\t Bienvenido al menu del Ejercicio 2 'TP CONJUNTOS'!!\n\n\n");
        printf(" 1.     Crear y cargar los Conjuntos.\n");
        printf(" 2.     Borrar los Conjuntos.\n");
        printf(" 3.     Obtener la UNION del Conjuntos A y B.\n");
        printf(" 4.     Obtener la INTERSECCION del Conjuntos A y B.\n");
        printf(" 5.     Obtener la DIFERENCIA del Conjuntos A y B.\n");
        printf(" 6.     Obtener la PERTENENCIA del Conjuntos A y B.\n");
        printf(" 7.     Mostrar el contenido de los Conjuntos A y B.\n");
        printf(" 0.     Salir del Menu.\n\n");
        printf("    Ingrese el numero de la accion a realizar: ");
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
                    A = cto_crear();
                    B = cto_crear();

                    printf(" Cuantos elementos tendra el Conjunto ' A '? (Numero positivo entero entre [ 0; 100 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 100)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 100 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto ' A '? (Numero entero entre [ 0; 100 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(A, elementos);



                    printf(" Cuantos elementos tendra el Conjunto ' B '? (Numero positivo entero entre [ 0; 100 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 100)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 100 ]!\n");
                        printf(" Cuantos elementos tendra el Conjunto ' B '? (Numero entero entre [ 0; 100 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(B, elementos);
                }

                else{

                    printf(" Ya cargo los Conjuntos! Debe seleccionar la opcion ' 2 ' antes!\n");
                }


                break;

            case 2:

                if(puedo){

                    free(A);
                    free(B);
                    puedo = false;

                    printf(" Se borraron los Conjuntos Correctamente!\n");
                }

                else{

                    printf(" No hay Conjuntos a borrar!\n");
                }

                break;
                
            case 3:

                if(puedo){

                    Union = cto_union(A, B);

                    printf(" Resultado A + B: "); cto_mostrar(Union);
                    free(Union);
                }

                else{

                    printf(" No hay conjuntos con los que hacer el ejercicio!, carguelos antes!\n");
                }

                break;
                
            case 4:

                if(puedo){

                    interseccion = cto_interseccion(A, B);

                    printf(" Resultado A = B: "); cto_mostrar(interseccion);
                    free(interseccion);
                }

                else{

                    printf(" No hay conjuntos con los que hacer el ejercicio!, carguelos antes!\n");
                }

                break;
                
            case 5:

                if(puedo){

                    diferencia = cto_diferencia(A, B);

                    printf(" Resultado A - B: "); cto_mostrar(diferencia);
                    free(diferencia);

                    diferencia = cto_diferencia(B, A);

                    printf(" Resultado B - A: "); cto_mostrar(diferencia);
                    free(diferencia);
                }

                else{

                    printf(" No hay conjuntos con los que hacer el ejercicio!, carguelos antes!\n");
                }

                break;
                
            case 6:

                if(puedo){
                    
                    int seguir;
                    
                    pertenenciaA = cto_interseccion(A, B);
                    pertenenciaB = cto_interseccion(B, A); 
                    
                    do{

                        printf(" Ingrese el numero a saber si pertenece a algun o a ambos Conjuntos: ");
                        clave = Ingreso_Entero_Positivo_Negativo();

                        if(cto_cantidad_elementos(A) == 0 && cto_cantidad_elementos(B) == 0){

                            printf(" Los Conjuntos estan vacios, por lo que ' %d ' no pertenece a ninguno!\n", clave);
                        }

                        if(cto_cantidad_elementos(A) > 0){

                            if(cto_pertenece(pertenenciaA, clave)){

                                printf(" El Numero ' %d ' pertenece al Conjunto A!\n", clave);
                            }
                        }

                        if(cto_cantidad_elementos(B) > 0){

                            if(cto_pertenece(pertenenciaB, clave)){

                                printf(" El Numero ' %d ' pertenece al Conjunto B!\n", clave);
                            }
                        }

                        printf(" Desea comprobar la pertenencia de otro numero? (+Ingrese ' 1 ' si desea hacerlo; +Ingrese ' 0 ' caso contrario!): ");
                        seguir = Ingresar_Entero_Positivo();

                        while(!Validar_Intervalo_Enteros(seguir, 0, 1)){

                            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1 ]!\n");
                            printf(" Desea comprobar la pertenencia de otro numero? (+Ingrese ' 1 ' si desea hacerlo; +Ingrese ' 0 ' caso contrario!): ");
                            seguir = Ingresar_Entero_Positivo();
                            fflush(stdin);
                        }

                    }
                    while(seguir != 0);

                    free(pertenenciaA);
                    free(pertenenciaB);
                }

                else{

                    printf(" No hay conjuntos con los que hacer el ejercicio!, carguelos antes!\n");
                }

                break;
                
            case 7:

                if(puedo){

                    printf(" Conjunto A: "); cto_mostrar(A);
                    printf(" Conjunto B: "); cto_mostrar(B);
                }

                else{

                    printf(" No hay Conjuntos a mostrar\n");
                }

                break;
                
        }

        system("pause");
        system("cls");

    }
    while(bandera != 0);


    return 0;
}