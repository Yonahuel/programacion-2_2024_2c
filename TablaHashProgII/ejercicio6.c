#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"


// ACLARACION: por las dudas, volver a modificar el tamaño maximo que poseen las listas a 100. No vaya a ser que no pueda
// ejecutar el programa por quedarse sin memoria...


int main(){

    int bandera, cantidad_de_casilleros = 1095;
    bool puedo = false;

    TablaHash tablita;
    Lista vacunados;
    TipoElemento casillero_hash;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 6 'TP HASH'\n\n\n");
        printf(" 1.     Crear la Tabla Hash.\n");
        printf(" 2.     Borrarla Tabla Hash.\n");
        printf(" 3.     Agregar datos (Altas).\n");
        printf(" 4.     Buscar una fecha en el Hash y retornar la lista con los vacunados en esa fecha.\n");
        printf(" 5.     Imprimir el contenido de la Tabla Hash.\n");
        printf(" 0.     Salir del Menu.\n\n");
        printf(" Ingrese el numero de la accion a realizar: ");
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

                    tablita = th_crear(cantidad_de_casilleros, &funcion_hashej6);

                    printf(" Se creo la Tabla Hash correctamente!\n");
                    puedo = true;
                }

                else{

                    printf(" Ya creo la Tabla Hash, Borrela con la accion ' 2 ' del menu antes!\n");
                }

                break;

            case 2:

                if(puedo){
                    
                    free(tablita);

                    puedo = false;
                }

                else{

                    printf(" No hay una Tabla Hash para borrar!\n");
                }

                break;

            case 3:

                if(puedo){

                    Altas_Vacunados(tablita);
                }

                else{

                    printf(" Aun no creo la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 4:

                if(puedo){

                    casillero_hash = Buscar_Vacunados(tablita);

                    if(casillero_hash != NULL){

                        vacunados = (Lista)casillero_hash->valor;
                        printf(" Fecha de vacunacion: %d\n\n", casillero_hash->clave);
                        mostrar_vacunados(vacunados);
                    }

                    else{

                        printf(" No hay registros de esa fecha! Resultado: NULL!\n");
                    }
                }

                else{

                    printf(" Aun no creo la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 5:

                if(puedo){

                    th_mostrar(tablita);
                }

                else{

                    printf(" Aun no creo la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;
        }

        system("pause");
        system("cls");
    
    }
    while(bandera != 0);

    printf(" Hasta la proxima!\n");

    return 0;
}