#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


int main(){

    int bandera, elementos;
    bool puedo = false, c1, c2, c3;

    Conjunto ConjuntoA, ConjuntoB, ConjuntoC;


    do{

        printf("\t\t\t Bienvenido al menu del Ejercicio 4 'TP CONJUNTOS'!!\n\n\n");
        printf(" 1.     Crear y cargar los 3 Conjuntos.\n");
        printf(" 2.     Borrar los Conjuntos.\n");
        printf(" 3.     Demostrar la propiedad de TRANSITIVIDAD.\n");
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

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1000]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'A'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(ConjuntoA, elementos);

                    printf(" Cuantos elementos tendra el Conjunto 'B'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1000]!\n");
                        printf(" Cuantos elementos tendra el Conjunto 'B'? (numero entero entre [ 0; 1000 ]): ");
                        elementos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    cargar_conjunto_manual(ConjuntoB, elementos);

                    printf(" Cuantos elementos tendra el Conjunto 'C'? (numero entero entre [ 0; 1000 ]): ");
                    elementos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(elementos, 0, 1000)){

                        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1000]!\n");
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

                    printf(" Propiedad de transitividad: Si ' A ' es un subconjunto de ' B ', y ' B ' es un subconjunto de ' C ',\n");
                    printf("\t\t\t se demuestra que ' A ' tambien es un subconjunto de C!\n\n");
                    
                    c1 = subconjunto_de(ConjuntoB, ConjuntoA);
                    c2 = subconjunto_de(ConjuntoC, ConjuntoB);
                    c3 = subconjunto_de(ConjuntoC, ConjuntoA);

                    if(c1 && c2 && c3){

                        printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                        printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                        printf(" Queda demostrado que ' A ' es subconjunto de ' B '\n\n");

                        printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                        printf(" Conjunto C: "); cto_mostrar(ConjuntoC);
                        printf(" Queda demostrado que ' B ' es subconjunto de ' C '\n\n");

                        printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                        printf(" Conjunto C: "); cto_mostrar(ConjuntoC);
                        printf(" Queda demostrado que ' A ' es subconjunto de ' C '\n\n");

                        printf(" Se cumple la propiedad de transitividad!\n");
                    }

                    else{

                        if(!c1 && c2){

                            printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                            printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                            printf(" Queda demostrado que ' A ' no es subconjunto de ' B '\n\n");

                            printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                            printf(" Conjunto C: "); cto_mostrar(ConjuntoC);
                            printf(" Queda demostrado que ' B ' es subconjunto de ' C '\n\n");

                            printf(" Como ' A ' no es subconjunto de ' B ', entonces tampoco es subconjunto de ' C '\n");
                            printf(" No se cumple la propiedad de transitividad!\n");
                        }

                        else if(!c1 && !c2){

                            printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                            printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                            printf(" Queda demostrado que ' A ' no es subconjunto de ' B '\n\n");

                            printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                            printf(" Conjunto C: "); cto_mostrar(ConjuntoC);
                            printf(" Queda demostrado que ' B ' no es subconjunto de ' C '\n\n");

                            printf(" Ni ' A ', ni ' B ' son Subconjuntos de ' C ', no se cumple la propiedad!\n");
                        }

                        else if(c1 && !c2){

                            printf(" Conjunto A: "); cto_mostrar(ConjuntoA);
                            printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                            printf(" Queda demostrado que ' A ' es subconjunto de ' B '\n\n");

                            printf(" Conjunto B: "); cto_mostrar(ConjuntoB);
                            printf(" Conjunto C: "); cto_mostrar(ConjuntoC);
                            printf(" Queda demostrado que ' B ' no es subconjunto de ' C '\n\n");

                            printf(" Como ' B ' no es subconjunto de ' C ', ' A ' tampoco lo es!, no se cumple la propiedad!\n");
                        }
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