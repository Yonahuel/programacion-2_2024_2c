#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//calculo tamaño del numero ingresado.
int Longuitud_String(char String[]){

    return strlen(String);
}

//Funcion para Validar un numero dado un intervalo de valores.
bool Validar_Intervalo_Enteros(int Numero, int minimo, int maximo){

    if(Numero < minimo || Numero > maximo){

        return false;
    }

    return true;
}


bool Validar_Intervalo_Decimal(float Numero, float minimo, float maximo){

    if(Numero < minimo || Numero > maximo){

        return false;
    }

    return true;
}

/*----------------------------------------------------------------------------------------------------------------------------------
.                                                                                                                                   .
.                                                                                                                                   .
.                              V A L I D A C I O N E S   D E   N U M E R O S   E N T E R O S                                        .
.                                                                                                                                   .
.                                                                                                                                   .
------------------------------------------------------------------------------------------------------------------------------------*/


//Paso el numero a int.
int String_A_Entero(char string[]){

    return atoi(string);
}


int Ingresar_Entero_Positivo(){

    //variables.
    bool bandera, valido;
    int longuitud, contador = 0;
    char Numero[12];
    char maximo[] = "2144783647";

    do{

        Numero[0] = '\0';
        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero: ");
        }


        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.

        //pido el numero.
        fgets(Numero, 12, stdin);
        fflush(stdin);


        longuitud = Longuitud_String(Numero); //calculo su longuitud

        //si esta vacio imprimo el cartel.
        if(longuitud == 1 && Numero[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO POSITIVO!\n");
            bandera = false;
        }

        //si el ingreso es excesivo imprimo el cartel.
        if(longuitud == 11 && Numero[longuitud - 1] != '\n'){

            printf("\n Ingreso Excesivo! Debe ingresar un Numero con un maximo de 10 DIGITOS!\n");
            bandera = false;
        }

        //si el ingreso sigue valido.
        if(bandera){

            Numero[longuitud - 1] = '\0'; //cambio el salto de linea.
            longuitud --; //resto 1 al tamaño

            //Me fijo que no empiece con 0 un numero >= a 2 digitos.
            if(Numero[0] == '0' && longuitud >= 2){

                printf("\n Ingreso Invalido!, Lo ingresado NO corresponde a un NUMERO POSITIVO. El Numero NO PUEDE empezar con 0!\n");
                bandera = false;
            }

            //verifico que no hallan letras o caracteres especiales.
            for(int i = 0; i < longuitud; i++){

                if(!isdigit(Numero[i])){

                    printf("\n Ingreso Invalido! NO se permite nada diferente a un DIGITO!\n");
                    bandera = false;
                    break;
                }
            }

            //si sigue valido.
            if(bandera){

                valido = true;

                //si su tamaño es el maximo permitido.
                if(longuitud == 10){

                    for(int i = 0; i < longuitud; i++){

                        if(maximo[i] > Numero[i]){

                            break;
                        }

                        if(maximo[i] < Numero[i]){

                            valido = false;
                            break;
                        }
                    }

                    //si no se pudo imprimo cartel.
                    if(!valido){

                        printf("\n Ingreso Invalido! El Numero ingresado es mayor al Numero maximo que puede almacenar un 'INT'!\n");
                        bandera = false;
                    }
                }
            }
        }

        contador ++;
    }
    while(!bandera);

    printf("\n");
    system("cls");
    //convierto y retorno el Numero.
    return String_A_Entero(Numero);
}


int Ingresar_Entero_Negativo(){

    //variables.
    bool bandera, valido;
    int longuitud, contador = 0;
    char Numero[13];
    char minimo[] = "-2144783648";


    do{

        Numero[0] = '\0';
        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero: ");
        }


        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.

        //pido el numero.
        fgets(Numero, 13, stdin);
        fflush(stdin);


        longuitud = Longuitud_String(Numero); //calculo su longuitud

        //si esta vacio imprimo el cartel.
        if(longuitud == 1 && Numero[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO NEGATIVO!\n");
            bandera = false;
        }

        if(longuitud == 2 && Numero[0] == '-' && Numero[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido! Debe ingresar un NUMERO NEGATIVO!\n");
            bandera = false;
        }

        //si el ingreso es excesivo imprimo el cartel.
        if(longuitud == 12 && Numero[longuitud - 1] != '\n'){

            printf("\n Ingreso Excesivo! Debe ingresar un Numero con un maximo de 11 DIGITOS (Contando el signo ' - ')!\n");
            bandera = false;
        }

        //si el ingreso sigue valido.
        if(bandera){

            Numero[longuitud - 1] = '\0'; //cambio el salto de linea.
            longuitud --; //resto 1 al tamaño

            //verifico que no hallan letras o caracteres especiales.
            for(int i = 0; i < longuitud; i++){

                if(!isdigit(Numero[i])){

                    if(Numero[i] == '-' && i != 0){

                        printf("\n Ingreso Invalido! El signo ' - ' SOLO puede estar en el inicio del numero!\n");
                        bandera = false;
                        break;
                    }

                    else{

                        printf("\n Ingreso Invalido! El Numero NO PUEDE tener otra cosa que no sean DIGITOS o el signo ' - '!\n");
                        bandera = false;
                        break;
                    }
                }

                if(i == 0 && Numero[i] != '-'){

                    printf("\n Ingreso Invalido! Lo ingresado no es un NUMERO NEGATIVO!\n");
                    bandera = false;
                    break;
                }

                //Si arranca con 0 imprimo el cartel.
                if(i == 1 && Numero[i] == '0'){

                    printf("\n Ingreso Invalido! El Numero NO PUEDE arrancar con '0'!\n");
                    bandera = false;
                    break;
                }
            }


            //si sigue valido.
            if(bandera){

                valido = true;

                //si su tamaño es el maximo permitido.
                if(longuitud == 11){

                    for(int i = 1; i < longuitud; i++){

                        if(minimo[i] > Numero[i]){

                            break;
                        }

                        if(minimo[i] < Numero[i]){

                            valido = false;
                            break;
                        }
                    }

                    //si no se pudo imprimo cartel.
                    if(!valido){

                        printf("\n Ingreso Invalido! El Numero ingresado es menor al Numero minimo que puede almacenar un 'INT'!\n");
                        bandera = false;
                    }
                }
            }
        }

        contador ++;
    }
    while(!bandera);

    printf("\n");
    system("cls");
    //convierto y retorno el Numero.
    return String_A_Entero(Numero);
}



int Ingreso_Entero_Positivo_Negativo(){


    //variables.
    bool bandera, valido, N;
    int longuitud, contador = 0;
    char Numero[13];

    char maximo[] = "2144783647";
    char minimo[] = "-2144783648";


    do{

        Numero[0] = '\0';
        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero: ");
        }


        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.
        N = false; //variable para saber si es negativo.

        //pido el numero.
        fgets(Numero, 13, stdin);
        fflush(stdin);


        longuitud = Longuitud_String(Numero); //calculo su longuitud.

        //si esta vacio imprimo el cartel.
        if((longuitud == 1 && Numero[longuitud - 1] == '\n') || (longuitud == 2 && Numero[0] == '-' && Numero[longuitud - 1] == '\n')){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO NEGATIVO o POSITIVO!\n");
            bandera = false;
        }

        if(bandera){

            //Recorro el array para ver si esta todo dentro de lo permitido.
            for(int i = 0; i < longuitud; i++){

                //si no es un digito y diferente al salto de linea.
                if(!isdigit(Numero[i]) && Numero[i] != '\n'){

                    //si es el menos en un lugar incorrecto, imprimo el cartel.
                    if(Numero[i] == '-' && i != 0){

                        printf("\n Ingreso Invalido! Si quiere ingresar un NUMERO NEGATIVO, el signo ' - ' solo puede estar al comienzo del Numero!\n");
                        bandera = false;
                    }

                    //si tiene un signo menos, coloco que es negativo.
                    if(Numero[i] == '-' && i == 0){

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
                if(Numero[longuitud - 1] == '\n'){

                    Numero[longuitud - 1] = '\0';
                    longuitud = Longuitud_String(Numero);
                }

                //si tiene un mayor tamaño al permitido, imprimo el cartel.
                if(longuitud == 12){

                    printf("\n Ingreso Excesivo! Si desea ingresar un NUMERO NEGATIVO, debe tener como maximo 11 DIGITOS (Contando el signo ' - ')!\n");
                    bandera = false;
                }

                //si tiene un tamaño correcto.
                else{

                    //veriico que el primer digito no sea un '0', caso contrario imprimo el cartel.
                    if(Numero[1] == '0'){

                        printf("\n Ingreso Invalido! Si desea ingresar un NUMERO NEGATIVO, el mismo no puede iniciar con 0!\n");
                        bandera = false;
                    }

                    //si sigue valido el numero negativo
                    if(bandera){

                        //verifico si su tamaño es menor al maximo permitido.
                        if(longuitud == 11){

                            for(int i = 1; i < longuitud; i++){

                                if(minimo[i] > Numero[i]){

                                    break;
                                }

                                if(minimo[i] < Numero[i]){

                                    valido = false;
                                    break;
                                }

                                valido = true;
                            }

                            //si no lo es imprimo cartel.
                            if(!valido){

                                printf("\n Ingreso Invalido! El Numero ingresado es menor al Numero minimo que puede almacenar un 'INT'!\n");
                                bandera = false;
                            }
                        }
                    }
                }
            }

            //caso para el positivo.
            else{

                //Cambio el salto de linea en caso de que lo tenga.
                if(Numero[longuitud - 1] == '\n'){

                    Numero[longuitud - 1] = '\0';
                    longuitud = Longuitud_String(Numero);
                }

                //si se excede en cantidad de digitos imprimo el cartel.
                if(longuitud > 10){

                    printf("\n Ingreso Excesivo! Si desea ingresar un NUMERO POSITIVO, puede ingresar hasta un maximo de 10 DIGITOS!\n");
                    bandera = false;
                }

                //si no es 0 pero empieza el numero con 0, imprimo el cartel(numero mayor 1 digito)
                if(longuitud >= 2 && Numero[0] == '0'){

                    printf("\n Ingreso Invalido! Si desea ingresar un NUMERO POSITIVO MAYOR A 2 DIGITOS, el mismo NO PUEDE empezar con 0!\n");
                    bandera = false;
                }

                //si sigue valido.
                if(bandera){

                    valido = true;

                    //verifico si su tamaño es menor al maximo permitido.
                    if(longuitud == 10){

                        for(int i = 0; i < longuitud; i++){

                            if(maximo[i] > Numero[i]){

                                break;
                            }

                            if(maximo[i] < Numero[i]){

                                valido = false;
                                break;
                            }
                        }

                        //si no es imprimo cartel.
                        if(!valido){

                            printf("\n Ingreso Invalido! El Numero ingresado es mayor al Numero maximo que puede almacenar un 'INT'!\n");
                            bandera = false;
                        }
                    }
                }
            }
        }

        contador ++;
    }
    while(!bandera);

    printf("\n");
    system("cls");
    return String_A_Entero(Numero);
}







/*----------------------------------------------------------------------------------------------------------------------------------
.                                                                                                                                   .
.                                                                                                                                   .
.                              V A L I D A C I O N E S   D E   N U M E R O S   D E C I M A L E S                                    .
.                                                                                                                                   .
.                                                                                                                                   .
------------------------------------------------------------------------------------------------------------------------------------*/


//Paso el numero a int.
float String_A_Decimal(char string[]){

    return atof(string);
}




float Ingresar_Decimal_Positivo(){

    //variables.
    bool bandera, valido;
    int longuitud, contador = 0, punto;
    char Numero[9];
    char maximo[] = "9999.9";
    char minimo[] = "0.0000";

    do{

        punto = 0;
        Numero[0] = '\0';
        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero Decimal: ");
        }


        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.

        //pido el numero.
        fgets(Numero, 9, stdin);
        fflush(stdin);


        longuitud = Longuitud_String(Numero); //calculo su longuitud

        //si esta vacio imprimo el cartel.
        if(longuitud == 1 && Numero[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO DECIMAL POSITIVO!\n");
            bandera = false;
        }

        if((longuitud == 7 && Numero[longuitud - 1] != '\n') || longuitud > 7){

            printf("\n Ingreso Excesivo! Debe ingresar un NUMERO DECIMAL POSITIVO de hasta 5 digitos en total, contando los decimales!\n");
            bandera = false;
        }

        //Me fijo que no empiece con 0 un numero >= a 2 digitos.
        if(Numero[0] == '0' && Numero[1] != '.'){

            printf("\n Ingreso Invalido!, Lo ingresado NO corresponde a un NUMERO DECIMAL POSITIVO! Si el numero empieza con '0', no puede tener mas parte entera, por lo que debe ser seguido del caracter ' . ' !\n");
            bandera = false;
        }

        if(bandera){

            Numero[longuitud - 1] = '\0'; //cambio el salto de linea.
            longuitud --; //resto 1 al tamaño

            //verifico que no hallan letras o caracteres especiales.
            for(int i = 0; i < longuitud; i++){

                if(!isdigit(Numero[i])){

                    if(Numero[i] != '.'){

                        printf("\n Ingreso Invalido! NO se permite nada diferente a un DIGITO o el signo ' . ' !\n");
                        bandera = false;
                        break;
                    }

                    else{

                        if(i == 0){

                            printf("\n Ingreso Invalido! El NUMERO DECIMAL no puede empezar con el signo ' . ' !\n");
                            bandera = false;
                            break;
                        }

                        if(i == longuitud - 1){

                            printf("\n Ingreso Invalido! El NUMERO DECIMAL no puede terminar con el signo ' . ' !\n");
                            bandera = false;
                            break;
                        }

                        if(punto > 1){

                            printf("\n Ingreso Invalido! El NUMERO DECIMAL no puede tener mas de un signo ' . ' !\n");
                            bandera = false;
                            break;
                        }

                        punto++;
                    }
                }
            }

            if(punto == 0){

                printf("\n Lo ingresado no es un NUMERO DECIMAL!, por favor, ingrese un numero que contenga el signo ' . ' !\n");
                bandera = false;
            }

            //si sigue valido.
            if(bandera){

                valido = true;

                //si su tamaño es el maximo permitido.
                if(longuitud == 6){

                    for(int i = 0; i < longuitud; i++){

                        if(Numero[i] == '.' && maximo[i] != '.'){

                            break;
                        }

                        if(maximo[i] > Numero[i]){

                            break;
                        }

                        if(maximo[i] < Numero[i]){

                            valido = false;
                            break;
                        }
                    }

                    if(valido){

                        for(int i = 0; i < longuitud; i++){

                            if(minimo[i] == '.' && Numero[i] != '.'){

                                break;
                            }

                            if(minimo[i] > Numero[i]){

                                valido = false;
                                break;
                            }
                        }
                    }

                    //si no se pudo imprimo cartel.
                    if(!valido){

                        printf("\n Ingreso Invalido! El NUMERO DECIMAL ingresado es mayor a [9999.9] o menor a [0.0000], que permitimos para un 'FLOAT'!\n");
                        bandera = false;
                    }
                }
            }

        }

        contador ++;
    }
    while(!bandera);

    printf("\n");
    system("cls");

    return String_A_Decimal(Numero);
}


float Ingresar_Decimal_Negativo(){

    //variables.
    bool bandera, valido;
    int longuitud, contador = 0, punto;
    char Numero[10];
    char maximo[] = "-0.0001";
    char minimo[] = "-9999.9";

    do{

        punto = 0;
        Numero[0] = '\0';

        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero Decimal: ");
        }


        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.

        //pido el numero.
        fgets(Numero, 10, stdin);
        fflush(stdin);


        longuitud = Longuitud_String(Numero); //calculo su longuitud

        //si esta vacio imprimo el cartel.
        if(longuitud == 1 && Numero[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido! No ha ingresado nada. Por Favor, Ingrese un NUMERO DECIMAL NEGATIVO!\n");
            bandera = false;
        }

        if((longuitud == 8 && Numero[longuitud - 1] != '\n') || longuitud > 8){

            printf("\n Ingreso Excesivo! Debe ingresar un NUMERO DECIMAL NEGATIVO de hasta 5 digitos en total, contando los decimales!\n");
            bandera = false;
        }

        //Me fijo que no empiece con 0 un numero >= a 2 digitos.
        if(Numero[1] == '0' && Numero[2] != '.'){

            printf("\n Ingreso Invalido!, Lo ingresado NO corresponde a un NUMERO DECIMAL NEGATIVO! Si el numero empieza con '0', no puede tener mas parte entera, por lo que debe ser seguido del caracter ' . ' !\n");
            bandera = false;
        }

        if(bandera){

            Numero[longuitud - 1] = '\0'; //cambio el salto de linea.
            longuitud --; //resto 1 al tamaño

            //verifico que no hallan letras o caracteres especiales.
            for(int i = 0; i < longuitud; i++){

                if(!isdigit(Numero[i])){

                    if(Numero[i] != '.' && Numero[i] != '-'){

                        printf("\n Ingreso Invalido! NO se permite nada diferente a un DIGITO o al signo ' . ' y al signo ' - ' !\n");
                        bandera = false;
                        break;
                    }

                    else{

                        if(Numero[i] == '.'){

                            if(i == 0){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL no puede empezar con el signo ' . ' !\n");
                                bandera = false;
                                break;
                            }

                            if(i == longuitud - 1){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL no puede terminar con el signo ' . ' !\n");
                                bandera = false;
                                break;
                            }

                            if(punto > 1){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL no puede tener mas de un signo ' . ' !\n");
                                bandera = false;
                                break;
                            }

                            punto++;
                        }

                        else{

                            if(i != 0){

                                printf("\n Ingreso Invalido! El signo ' - ' SOLO puede estar en el inicio del NUMERO DECIMAL NEGATIVO!\n");
                                bandera = false;
                                break;
                            }
                        }
                    }
                }

                if(i == 0 && Numero[i] != '-'){

                    printf("\n Ingreso Invalido! Lo ingresado no es un NUMERO DECIMAL NEGATIVO!\n");
                    bandera = false;
                    break;
                }
            }

            if(punto == 0){

                printf("\n Lo ingresado no es un NUMERO DECIMAL!, por favor, ingrese un numero que contenga el signo ' . ' !\n");
                bandera = false;
            }

            //si sigue valido.
            if(bandera){

                valido = true;

                //si su tamaño es el maximo permitido.
                if(longuitud == 7){

                    for(int i = 0; i < longuitud; i++){

                        if(maximo[i] == '.' && Numero[i] != '.'){

                            break;
                        }

                        if(maximo[i] < Numero[i]){

                            break;
                        }

                        if(maximo[i] > Numero[i]){

                            valido = false;
                            break;
                        }
                    }

                    if(valido){

                        for(int i = 0; i < longuitud; i++){

                            if(Numero[i] == '.' && minimo[i] != '.'){

                                break;
                            }

                            if(minimo[i] > Numero[i]){

                                break;
                            }

                            if(minimo[i] < Numero[i]){

                                valido = false;
                                break;
                            }
                        }
                    }

                    //si no se pudo imprimo cartel.
                    if(!valido){

                        printf("\n Ingreso Invalido! El NUMERO DECIMAL ingresado es mayor a [-0.0001] o menor a [-9999.9], que permitimos para un 'FLOAT'!\n");
                        bandera = false;
                    }
                }
            }
        }

        contador ++;
    }
    while(!bandera);


    printf("\n");
    system("cls");

    return String_A_Decimal(Numero);
}

float Ingreso_Decimal_Positivo_Negativo(){

    //variables.
    bool bandera, valido, N;
    int longuitud, contador = 0, punto;
    char Numero[10];

    char maximo_positivo[] = "9999.9";
    char minimo_positivo[] = "0.0000";
    char maximo_negativo[] = "-0.0001";
    char minimo_negativo[] = "-9999.9";

    do{

        punto = 0;
        Numero[0] = '\0';

        //Por si hay mas de un ciclo, pido el numero de nuevo.
        if(contador > 0){

            system("pause"); system("cls");
            printf(" Ingrese el Numero Decimal: ");
        }


        bandera = true; //coloco en true la bandera para poder ver si es correcto el ingreso.

        //pido el numero.
        fgets(Numero, 10, stdin);
        fflush(stdin);


        longuitud = Longuitud_String(Numero); //calculo su longuitud

        if(longuitud == 1 && Numero[longuitud - 1] == '\n'){

            printf("\n Ingreso Invalido, No hay ingresado nada! por favor, Ingrese un NUMERO DECIMAL POSITIVO o NEGATIVO!\n");
            bandera = false;
        }

        if((longuitud == 8 && Numero[longuitud - 1] != '\n') || longuitud > 8){

            printf("\n Ingreso Excesivo! El NUMERO DECIMAL solo puede tener hasta 5 digitos (contando los decimales)!\n");
            bandera = false;
        }

        if(Numero[0] == '0' && Numero[1] != '.'){

            printf("\n Ingreso Invalido! El NUMERO DECIMAL POSITIVO que arranca con '0' debe ser inmediatamente seguido del ' . ' !\n");
            bandera = false;
        }

        if(Numero[1] == '0' && Numero[2] != '.'){

            printf("\n Ingreso Invalido! El NUMERO DECIMAL NEGATIVO que arranca con '0' debe ser inmediatamente seguido del ' . ' !\n");
            bandera = false;
        }

        if(bandera){

            Numero[longuitud - 1] = '\0'; //cambio el salto de linea.
            longuitud --; //resto 1 al tamaño

            //verifico que no hallan letras o caracteres especiales.
            for(int i = 0; i < longuitud; i++){

                if(!isdigit(Numero[i])){

                    if(Numero[i] != '-' && Numero[i] != '.'){

                        printf("\n Ingreso Invalido! El NUMERO DECIMAL solo puede contener DIGITOS o los signos ' . ' e ' - ' !\n");
                        bandera = false;
                        break;
                    }

                    else{

                        if(Numero[i] == '.'){

                            if(i == 0){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL NO puede arrancar con el signo ' . ' !\n");
                                bandera = false;
                                break;
                            }

                            if(i == longuitud - 1){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL NO puede terminar con el signo ' . ' !\n");
                                bandera = false;
                                break;
                            }

                            if(punto > 1){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL NO puede tener mas de un signo ' . ' !\n");
                                bandera = false;
                                break;
                            }

                            punto++;
                        }

                        else{

                            if(i != 0){

                                printf("\n Ingreso Invalido! El NUMERO DECIMAL NEGATIVO SOLO puede contener el signo ' - ' adelante de todos los digitos!\n");
                            }

                            N = true;
                        }
                    }
                }
            }

            if(punto == 0){

                printf("\n Lo ingresado no es un NUMERO DECIMAL!, por favor, ingrese un numero que contenga el signo ' . ' !\n");
                bandera = false;
            }

            if(bandera){

                valido = true;

                if(N){

                    if(longuitud == 7){

                        for(int i = 0; i < longuitud; i++){

                            if(maximo_negativo[i] == '.' && Numero[i] != '.'){

                                break;
                            }

                            if(maximo_negativo[i] < Numero[i]){

                                break;
                            }

                            if(maximo_negativo[i] > Numero[i]){

                                valido = false;
                                break;
                            }
                        }

                        if(valido){

                            for(int i = 0; i < longuitud; i++){

                                if(Numero[i] == '.' && minimo_negativo[i] != '.'){

                                    break;
                                }

                                if(minimo_negativo[i] > Numero[i]){

                                    break;
                                }

                                if(minimo_negativo[i] < Numero[i]){

                                    valido = false;
                                    break;
                                }
                            }
                        }
                    }

                    if(!valido){

                        printf("\n Ingreso Invalido! El NUMERO DECIMAL NEGATIVO ingresado es mayor a [-0.0001] o menor a [-9999.9], que permitimos para un 'FLOAT'!\n");
                        bandera = false;
                    }

                }

                else{

                    if(longuitud > 6){

                        printf("\n Ingreso Excesivo! El NUMERO DECIMAL POSITIVO SOLO puede tener hasta 5 digitos, contando la parte decimal!\n");
                        bandera = false;
                        continue;
                    }

                    if(longuitud == 6){

                        for(int i = 0; i < longuitud; i++){

                            if(Numero[i] == '.' && maximo_positivo[i] != '.'){

                                break;
                            }

                            if(maximo_positivo[i] > Numero[i]){

                                break;
                            }

                            if(maximo_positivo[i] < Numero[i]){

                                valido = false;
                                break;
                            }
                        }

                        if(valido){

                            for(int i = 0; i < longuitud; i++){

                                if(minimo_positivo[i] == '.' && Numero[i] != '.'){

                                    break;
                                }

                                if(minimo_positivo[i] < Numero[i]){

                                    break;
                                }

                                if(minimo_positivo[i] < Numero[i]){

                                    valido = false;
                                    break;
                                }
                            }
                        }

                        //si no se pudo imprimo cartel.
                        if(!valido){

                            printf("\n Ingreso Invalido! El NUMERO DECIMAL POSITIVO ingresado es mayor a [9999.9] o menor a [0.0000], que permitimos para un 'FLOAT'!\n");
                            bandera = false;
                        }
                    }
                }
            }
        }

        contador++;
    }
    while(!bandera);


    printf("\n");
    system("cls");

    return String_A_Decimal(Numero);
}

