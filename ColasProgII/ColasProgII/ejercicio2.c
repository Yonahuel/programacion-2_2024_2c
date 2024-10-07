#include "tipo_elemento.h"
#include "validaciones.h"
#include "funciones.h"


/*

EL MENU DE CARGA ESTA HECHO A POSTA ASÍ PARA IR AGREGANDO NUMEROS A LA COLA, EN CASO DE QUE QUIERA UNA NUEVA, ELIJA
LA OPCION ' 0 '... AHI LE PREGUNTARA SI DESEA TERMINAR EL EJERCICIO O INTENTAR CON UNA COLA DIFERENTE(CARGADA DESDE 0,
ELIGIENDO LA OPCION ' 1 ').        EL MENU QUEDABA ASI DE LARGO SIMPLEMENTE POR EL TEMA DE HACERLO EN CODEBLOCKS, AL
NO SABERLO USAR, OPTAMOS POR ESA ALTERNATIVA, YA QUE NOS COMPLICAMOS CON EL TEMA DE HABILITAR O NO LOS ARCHIVOS HEADERS
Y DESHABILITAR EL MAIN PARA CADA PUNTO DEL EJERCICIOO, ENTONCES TERMINAMOS HACIENDO TODO EN UNO SOLO.

*/

/*
Para ejecutar este tp en codeblocks hay que ir deshabilitando los ejercicios que no se usan y habilitar solo el que se va a usar.

*/

int main(){

    int bandera, clave, pos, longuitud;
    bool esta;

    Cola C_Original, Resultado;

    do{

        C_Original = c_crear();

        do{

            printf("\t\t\t MENU EJERCICIO 2 'TP COLAS': \n\n");
            printf(" 1.     Agregar elementos a la COLA (MANUALMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 2.     Agregar elementos a la COLA (ALEATORIAMENTE) (Los existentes en la COLA + los nuevos que ingresara...).\n");
            printf(" 3.     Verificar si el elemento buscado se encuentra en la COLA.\n");
            printf(" 4.     Agregar un elemento nuevo a la COLA en una posicion dada.\n");
            printf(" 5.     Eliminar un elemento de la COLA (Todas las veces que este aparezca).\n");
            printf(" 6.     Longuitud de la COLA actual.\n");
            printf(" 7.     Realizar una copia de la COLA original.\n");
            printf(" 8.     Invertir el contenido de la COLA.\n");
            printf(" 0.     SALIR DEL MENU.\n\n");
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

                    Cargar_Manualmente_Repetidos(C_Original);

                    c_mostrar(C_Original);

                    break;

                case 2:

                    Cargar_Aleatoriamente_Repetidos(C_Original);

                    c_mostrar(C_Original);

                    break;

                case 3:

                    printf(" Ingrese el numero a buscar en la COLA: ");
                    clave = Ingreso_Entero_Positivo_Negativo();

                    esta = C_EJ_Verificar_Existencia(C_Original, clave);

                    printf(" El numero %d se encuentra en la COLA? %s.\n", clave, esta ? "True" : "False");

                    break;

                case 4:

                    printf(" En que posicion colocaremos el numero en la COLA? (Numero entero entre [1; 10]): ");
                    pos = Ingresar_Entero_Positivo();

                    while(!Validar_Intervalo_Enteros(bandera, 1, 10)){

                        printf(" Ingreso Invalido! Debe ingresar una posicion entre [1; 10]!\n");
                        printf(" En que posicion colocaremos el numero en la COLA? (Numero entero entre [1; 10]): ");
                        pos = Ingresar_Entero_Positivo();
                        fflush(stdin);
                    }

                    C_Original = C_EJ_Insertar_Elemento(C_Original, pos);

                    printf(" RESULTADO: \n\n");
                    c_mostrar(C_Original);

                    break;

                case 5:

                    printf(" Que numero eliminaremos de la COLA?: ");
                    clave = Ingreso_Entero_Positivo_Negativo();

                    C_Original = C_EJ_Eliminar_Elemento(C_Original, clave);

                    printf(" RESULTADO:\n\n");
                    c_mostrar(C_Original);

                    break;

                case 6:

                    longuitud = C_EJ_Longuitud_Cola(C_Original);

                    printf(" La LONGUITUD de la COLA es: %d\n", longuitud);

                    break;

                case 7:

                    Resultado = C_EJ_Copiar_Cola(C_Original);

                    printf(" COLA ORIGINAL: \n"); c_mostrar(C_Original);
                    printf(" COLA COPIA: \n"); c_mostrar(Resultado);

                    free(Resultado);

                    break;

                case 8:

                    Resultado = C_EJ_Invertir_Cola(C_Original);

                    printf(" COLA ORIGINAL: \n"); c_mostrar(C_Original);
                    printf(" COLA INVERTIDA: \n"); c_mostrar(Resultado);

                    free(Resultado);

                    break;
            }

            system("pause");
            system("cls");
        }
        while(bandera != 0);

        printf(" Desea volver a realizar el ejercicio con una cola diferente? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea volver a realizar el ejercicio con una cola diferente? (*Ingrese ' 0 ' para salir del sistema; *Ingrese ' 1 ' para volver a realizarlos): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        free(C_Original);

    }
    while(bandera != 0);

    printf(" Hasta la proxima!\n");
    system("pause");

    return 0;
}
