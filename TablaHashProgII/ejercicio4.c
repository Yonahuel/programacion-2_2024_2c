#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

// ACLARACION: por las dudas, volver a modificar el tamaño maximo que poseen las listas a 100. No vaya a ser que no pueda
// ejecutar el programa por quedarse sin memoria...

int main(){

    int bandera, casilleros = 97, legajo_buscado;
    char archivo[] = "alumnos.dat";
    bool puedo = false;

    Lista Legajos;
    TablaHash Tablita;
    Alumno Encontrado;

    do{

        printf("\t\t\t Bienvenido al Menu del Ejercicio 4 'TP HASH'\n\n\n");
        printf(" 1.     Crear el Archivo Binario y la Tabla Hash.\n");
        printf(" 2.     Borrar el Archivo Binario y la Tabla Hash.\n");
        printf(" 3.     Agregar datos (Altas).\n");
        printf(" 4.     Borrar datos (Bajas).\n");
        printf(" 5.     Modificar datos (Modificaciones).\n");
        printf(" 6.     Buscar un legajo en el Hash y retornar los datos que posee el Archivo Binario.\n");
        printf(" 7.     Imprimir el contenido de la Tabla Hash.\n");
        printf(" 8.     Imprimir el contenido del Archivo Binario.\n");
        printf(" 0.     Salir del Menu.\n\n");
        printf(" Ingrese el numero de la accion a realizar: ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 8)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 8]!\n");
            printf(" Ingrese el numero de la accion a realizar: ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        switch(bandera){

            case 0:

                break;
            
            case 1:

                if(!puedo){

                    Crear_Archivo(archivo, "w+b");
                    Tablita = th_crear(casilleros, &funcion_hashej4);
                    Legajos = l_crear();

                    printf(" Se creo el Archivo Binario y la Tabla Hash correctamente!\n");
                    puedo = true;
                }

                else{

                    printf(" Ya creo el Archivo y la Tabla Hash, Borrelas con la accion ' 2 ' del menu antes!\n");
                }

                break;

            case 2:

                if(puedo){
                    
                    Crear_Archivo(archivo, "w+b");
                    free(Legajos);
                    free(Tablita);

                    puedo = false;
                }

                else{

                    printf(" No hay Archivo Binario ni una Tabla Hash para borrar!\n");
                }

                break;

            case 3:

                if(puedo){

                    Altas_Archivo(archivo, "r+b", Legajos, Tablita);
                }

                else{

                    printf(" Aun no creo el Archivo Binario ni la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 4:
                
                if(puedo){

                    Bajas_Archivo(archivo, "r+b", Legajos, Tablita);
                }

                else{

                    printf(" Aun no creo el Archivo Binario ni la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 5:

                if(puedo){

                    Modificaciones_Archivo(archivo, "r+b", Legajos, Tablita);
                }

                else{

                    printf(" Aun no creo el Archivo Binario ni la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 6:

                if(puedo){

                    Encontrado = Buscar_Alumno(archivo, "rb", Legajos, Tablita);
                    
                    if(Encontrado != NULL){

                        Mostrar_Encontrado(Encontrado);
                    }
                    

                    free(Encontrado);
                }

                else{

                    printf(" Aun no creo el Archivo Binario ni la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 7:

                if(puedo){

                    th_mostrar(Tablita);
                }

                else{

                    printf(" Aun no creo la Tabla Hash, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
                }

                break;

            case 8:

                if(puedo){

                    Mostrar_Contenido_Archivo(archivo, "rb");
                }

                else{

                    printf(" Aun no creo el Archivo Binario, vuelva a intentarlo luego de seleccionar la accion ' 1 ' del menu!\n");
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