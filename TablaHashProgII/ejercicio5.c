#include "tipo_elemento.h"
#include "nodo.h"
#include "validaciones.h"
#include "funciones.h"

#include "stdlib.h"
#include "time.h"


/*

RESULTADO OBTENIDO:

La complejidad de búsqueda en una tabla hash es, en el mejor de los casos, O(1), ya que la función hash apunta directamente al 
casillero correspondiente. Sin embargo, con colisiones y la implementacion de listas, en el peor caso puede llegar a O(n). especialmente 
si hay muchas colisiones y las listas de colisiones son largas.

Un árbol AVL es un árbol balanceado, por lo que la complejidad de búsqueda es O(log n) en el mejor y peor de los casos. Esto asegura 
tiempos de búsqueda predecibles, aunque la constante de tiempo puede ser mayor que en la tabla hash, dependiendo de las colisiones 
en esta última.

Conlcusion de Tabla Hash con listas de colisiones: Si se genera una tabla hash con muchos casilleros y elementos, la cantidad de colisiones
por casillero sera reducida, haciendo que el tiempo de busqueda sea mucho mas rapida que en el del arbol avl. Si la cantidad de colisiones
por casillero es alta, el tiempo de busqueda, sera parecido o mayor al del arbol avl, dependiendo las circunstancias, ya que la busqueda
de la lista es secuencial.


Conlcusion de Tabla Hash con zona overflow: Si se genera una tabla hash con muchos casilleros y elementos, la cantidad de colisiones
por casillero sera reducida pero terminaran secuencialmente en la zona overflow, haciendo que el tiempo de busqueda sea mucho mas grande
dependiendo del orden de llegada de los elementos y las posicion del elemento buscado, haciendo que en este caso, el tiempo sea mucho
mayor al del arbol avl. si se encuentra en el los casilleros del hash (fuera de la zona overflow), el tiempo sera mas rapido al del arbol
avl. 

*/


int nro_primo = 0;



int funcion_hash(int clave){

    return clave % nro_primo;
}



int main(){

    srand(time(NULL));

    int repeticiones_del_ejercicio, cantidad_elementos, cantidad_a_buscar;
    int minimo_rango, maximo_rango, i = 1;

    TablaHash tablita;
    ArbolAVL arbol;

    printf(" Cuantas veces realizaremos el ejercicio de medir los tiempos? (Numero entero entre[ 1; 100 ]): ");
    repeticiones_del_ejercicio = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(repeticiones_del_ejercicio, 1, 100)){

        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 1; 100 ]!\n");
        printf(" Cuantas veces realizaremos el ejercicio de medir los tiempos? (Numero entero entre[ 1; 100 ]): ");
        repeticiones_del_ejercicio = Ingresar_Entero_Positivo();    
        fflush(stdin);
    }

    do{
        
        //-----------------------------------------------------------------------------------------------------------
        printf(" Tirada %d! Cuantos elementos vamos a cargar en las estructuras? (Numero entre [ 1; 2000 ]): ", i);
        cantidad_elementos = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad_elementos, 1, 2000)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 1; 2000 ]!\n");
            printf(" Tirada %d! Cuantos elementos vamos a cargar en las estructuras? (Numero entre [ 1; 2000 ]): ", i);
            cantidad_elementos = Ingresar_Entero_Positivo();    
            fflush(stdin);
        }

        nro_primo = encontrar_primo(cantidad_elementos);




        //-----------------------------------------------------------------------------------------------------------
        tablita = th_crear(cantidad_elementos, &funcion_hash);
        arbol = avl_crear();



        //-----------------------------------------------------------------------------------------------------------
        printf(" Tirada %d! Requiero saber un rango de valores para poder cargar las estructuras con numeros aleatorios!\n\n", i);
        printf(" Ingrese el valor minimo del rango de valores (Numero entero): ");
        minimo_rango = Ingreso_Entero_Positivo_Negativo();

        printf(" ACLARACION: Cargaremos el 'valor maximo' del rango de valores. Este debe ser un numero igual o mayor a %d, ya que\n", minimo_rango + (cantidad_elementos *2));
        printf(" de esta forma, podremos obtener %d elementos sin repetir, y ademas podemos optimizar la carga de elementos, generando\n", cantidad_elementos);
        printf(" la menor cantidad de numeros repetidos, pudiendo luego buscar numeros que no se encuentren en la estructura tambien!\n\n\n");

        printf(" Ingrese el valor maximo del rango de valores (Numero entero entre [ %d; 2.144.783.646 ]): ", minimo_rango + (cantidad_elementos*2));
        maximo_rango = Ingreso_Entero_Positivo_Negativo();

        while(!Validar_Intervalo_Enteros(maximo_rango, minimo_rango + (cantidad_elementos*2), 2144783646)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ %d; 2.144.783.646 ]!\n",  minimo_rango + (cantidad_elementos*2));
            printf(" Ingrese el valor maximo del rango de valores (Numero entero entre [ %d; 2.144.783.646 ]): ", minimo_rango + (cantidad_elementos*2));
            maximo_rango = Ingreso_Decimal_Positivo_Negativo();
            fflush(stdin);
        }

        Cargar_estructuras_avl_hash(tablita, arbol, cantidad_elementos, minimo_rango, maximo_rango);




        //-----------------------------------------------------------------------------------------------------------
        printf(" Ingrese la cantidad de elementos a buscar en las estructuras con numeros aleatorios (numero entero [ 1; 2000 ]): ");
        cantidad_a_buscar = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad_a_buscar, 1, 2000)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 1; 2000 ]!\n");
            printf(" Ingrese la cantidad de elementos a buscar en las estructuras con numeros aleatorios (numero entero [ 1; 2000 ]): ");
            cantidad_a_buscar = Ingresar_Entero_Positivo();
            fflush(stdin);
        }
        
        Calcular_tiempos(tablita, arbol, cantidad_a_buscar, minimo_rango, maximo_rango);

        system("pause");
        system("cls");


        //-----------------------------------------------------------------------------------------------------------


        free(arbol);
        free(tablita);

        repeticiones_del_ejercicio --;
        i ++;
    }
    while(repeticiones_del_ejercicio > 0);

    system("pause");
    system("cls");

    return 0;
}