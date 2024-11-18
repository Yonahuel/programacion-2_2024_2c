#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void Ingresar_Cadena_Caracteres(char *Cadena, int cantidad_caracteres){

    bool bandera;
    int longuitud, contador = 0;

    do{

        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el STRING: ");
        }

        bandera = true;

        fgets(Cadena, cantidad_caracteres, stdin);
        fflush(stdin); 

        longuitud = Longuitud_String(Cadena);

        if(longuitud == 1 && Cadena[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un STRING VALIDO!\n");
            bandera = false;
        }

        if(longuitud == cantidad_caracteres - 1 && Cadena[longuitud - 1] != '\n'){

            printf("\n Ingreso Excesivo! Debe ingresar un STRING con un tamanio maximo de %d caracteres!\n", cantidad_caracteres);
            bandera = false;
        }

        if(bandera){

            Cadena[longuitud - 1] = '\0';
            longuitud --;

            for(int i = 0; i < longuitud; i++){

                if(!isalpha(Cadena[i])){

                    printf("\n Ingreso Invalido! NO se permite nada diferente a una LETRA DEL ALFABETO !\n");
                    bandera = false;
                    break;
                }
            }
        }

        contador ++;
    }
    while(!bandera);

    system("cls");
}



void Ingresar_Cadena_Numeros_Signos(char *Cadena, int cantidad_maxima_elementos){

    //variables.
    bool bandera, N;
    int longuitud, contador = 0;

    do{

        Cadena[0] = '\0';
        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero: ");
        }

        
        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.
        N = false; //variable para saber si es negativo.
        
        //pido el numero.
        fgets(Cadena, cantidad_maxima_elementos, stdin);
        fflush(stdin);

        
        longuitud = Longuitud_String(Cadena); //calculo su longuitud.

        //si esta vacio imprimo el cartel.
        if((longuitud == 1 && Cadena[longuitud - 1] == '\n') || (longuitud == 2 && Cadena[0] == '-' && Cadena[longuitud - 1] == '\n')){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO NEGATIVO o POSITIVO!\n");
            bandera = false;
        }

        if(Cadena[longuitud - 1] != '\n'){

            printf("\n Ingreso Excesivo! Por Favor, Ingrese un NUMERO STRING con %d elementos!\n", cantidad_maxima_elementos);
            bandera = false;
        }

        if(bandera){

            //Recorro el array para ver si esta todo dentro de lo permitido.
            for(int i = 0; i < longuitud; i++){

                //si no es un digito y diferente al salto de linea.
                if(!isdigit(Cadena[i]) && Cadena[i] != '\n'){

                    //si es el menos en un lugar incorrecto, imprimo el cartel.
                    if(Cadena[i] == '-' && i != 0){

                        printf("\n Ingreso Invalido! Si quiere ingresar un NUMERO NEGATIVO, el signo ' - ' solo puede estar al comienzo del Numero!\n");
                        bandera = false;
                    }

                    //si tiene un signo menos, coloco que es negativo.
                    if(Cadena[i] == '-' && i == 0){

                        N = true;
                    }

                    //si es cualquier otra cosa a lo anterior mencionado, imprimo el cartel.
                    else{

                        printf("\n Ingreso Invalido! El Numero solo puede contener DIGITOS o el signo ' - '!\n");
                        bandera = false;
                    }
                }
            }

            //si fue negativo.
            if(N && bandera){
                
                //verifico que tenga salto de linea y lo cambio por el simbolo vacio.
                if(Cadena[longuitud - 1] == '\n'){

                    Cadena[longuitud - 1] = '\0';
                    longuitud = Longuitud_String(Cadena);
                }

                else{

                    //veriico que el primer digito no sea un '0', caso contrario imprimo el cartel.
                    if(Cadena[1] == '0'){
                        
                        printf("\n Ingreso Invalido! Si desea ingresar un NUMERO NEGATIVO, el mismo no puede iniciar con 0!\n");
                        bandera = false;
                    }
                }
            }

            //caso para el positivo.
            if(bandera){

                //Cambio el salto de linea en caso de que lo tenga.
                if(Cadena[longuitud - 1] == '\n'){

                    Cadena[longuitud - 1] = '\0';
                    longuitud = Longuitud_String(Cadena);
                }

                //si no es 0 pero empieza el numero con 0, imprimo el cartel(numero mayor 1 digito)
                if(longuitud >= 2 && Cadena[0] == '0'){

                    printf("\n Ingreso Invalido! Si desea ingresar un NUMERO POSITIVO MAYOR A 2 DIGITOS, el mismo NO PUEDE empezar con 0!\n");
                    bandera = false;
                }
            }
        }

        contador ++;
    }
    while(!bandera);

    printf("\n");
    system("cls");
}



void Ingresar_CadenaNumero_Positivo(char *cadena, int tamanio){

    //variables.
    //variables.
    bool bandera;
    int longitud, contador = 0;

    do {
        cadena[0] = '\0';  // Limpiar la cadena antes de nuevo ingreso

        // Por si hay más de un ciclo, pido el número de nuevo
        if (contador > 0) {
            system("pause"); system("cls");
            printf(" Ingrese el Numero: ");
        }

        bandera = true;  // Coloco en true la bandera para verificar si el ingreso es correcto
        
        // Pido el número
        fgets(cadena, tamanio, stdin);
        fflush(stdin);

        longitud = Longuitud_String(cadena);  // Calculo su longitud

        // Si está vacío, imprimo el mensaje de error
        if (longitud == 1 && cadena[longitud - 1] == '\n') {
            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO POSITIVO de %d digitos!\n", tamanio - 1);
            bandera = false;
        }

        // Si la longitud es mayor al tamaño permitido, imprimo mensaje de error
        if (longitud > tamanio - 1) {
            printf("\n Ingreso Excesivo! Por Favor, Ingrese un NUMERO POSITIVO con %d digitos como maximo!\n", tamanio - 1);
            bandera = false;
        }

        // Si la longitud es menor a lo esperado, imprimo mensaje de error
        if (longitud < tamanio - 1) {
            printf("\n Ingreso Invalido! Debe ingresar un NUMERO POSITIVO con exactamente %d digitos!\n", tamanio - 1);
            bandera = false;
        }

        // Verifico que todos los caracteres sean dígitos
        if (bandera) {
            for (int i = 0; i < longitud - 1; i++) {  // Verificar todos menos el \n
                if (!isdigit(cadena[i])) {
                    printf("\n Ingreso Invalido! El Numero solo puede contener DIGITOS!\n");
                    bandera = false;
                    break;
                }
            }
        }

        // Si todo está bien, removemos el salto de línea
        if (bandera && cadena[longitud - 1] == '\n') {
            cadena[longitud - 1] = '\0';  // Reemplazo el salto de línea con terminador nulo
        }

        contador++;
    } while (!bandera);

    printf("\n");
    system("cls");  
}