#include "Ejercicios.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//ejercicio 1.

bool palindromo(char cadena_caracteres[]){

    int principio = 0;
    int final = strlen(cadena_caracteres);

    return palindromo_recursivo(cadena_caracteres, principio, final - 1);
}

bool palindromo_recursivo(char cadena_caracteres[], int principio, int final){

    if(principio >= final){

        return true;
    }

    if(cadena_caracteres[principio] != cadena_caracteres[final]){

        return false;
    }

    palindromo_recursivo(cadena_caracteres, principio + 1, final - 1);
}

void Mostrar_Resultado_ejercicio1(bool resultado, char cadena_caracteres[]){

    if(resultado){

        printf(" La cadena '%s' es un PALINDROMO!\n", cadena_caracteres);
    }

    else{

        printf(" La cadena '%s' no es un PALINDROMO!\n", cadena_caracteres);
    }
}












//Ejercicio 2.

int producto(int m, int n){

    int resultado = 0;

    if(m < 0 && n < 0){

        producto_recursivo(&resultado, -m, -n);
    }

    else{

        producto_recursivo(&resultado, m, n);
    }

    return resultado;
}

void producto_recursivo(int *resultado, int m, int n){


    if(n == 0){

        return;
    }

    if(n > 0){

        *resultado += m;

        producto_recursivo(resultado, m, n - 1);
    }

    else{

        *resultado -= m;

        producto_recursivo(resultado, m, n + 1);
    }
}

void Mostrar_resultado_ejercicio2(int resultado, int m, int n){

    printf(" El resultado del PRODUCTO ENTRE %d x %d es: %d\n", m, n, resultado);
}


//Ejercicio 3.

int terminoSeridFibonacci(int numero){

    if(numero <= 1){

        return 1;
    }

    return terminoSeridFibonacci(numero - 1) + terminoSeridFibonacci(numero - 2);
}

void Mostrar_resultado_ejercicio3(int resultado, int numero){

    printf(" El resultado de hacer FIBONACCI de '%d' es: %d\n", numero, resultado);
}












//Ejercicio 4.

double division(int m, int n){

    double resultado = 0.0;

    if(m < 0 && n < 0){

        resultado = division_recursiva(-m, -n, 0);
    }

    if(m < 0 && n > 0){

        resultado = division_recursiva(-m, n, 0);
        resultado *= -1;
    }

    if(m > 0 && n < 0){

        resultado = division_recursiva(m, -n, 0);
        resultado *= -1;
    }

    else{

        resultado = division_recursiva(m, n, 0);
    }


    return resultado;
}

double division_recursiva(int m, int n, int decimales){

    if(m == 0 || decimales > 6){

        return 0.0;
    }

    if(m < n){

        return division_recursiva(m * 10, n, decimales + 1) / 10.0;
    }

    else{

        return 1.0 + division_recursiva((m - n), n, decimales);
    }
}

void Mostrar_resultado_ejercicio4(double resultado, int m, int n){

    printf(" El resultado de la DIVISION A TRAVES DE RESTAS SUCESIVAS entre '%d' y '%d' es de: %lf\n", m, n, resultado);
}












//Ejercicio 5.

char *agregarSeparadorMiles(char Numero_string[]){

    int longuitud = strlen(Numero_string);

    int inicio = 0, final = longuitud - 1;

    char temporal;

    char *Numero_miles = (char *) calloc(longuitud + 10, sizeof(char));

    CargarlosPuntos(Numero_miles, Numero_string, inicio, final, temporal);

    return Numero_miles;
}

void CargarlosPuntos(char *Numero_miles, char numero_string[], int inicio, int final, char temporal){

    if(final < 0){


        Cambiar_Orientacion_string(Numero_miles, 0, strlen(Numero_miles) - 1, temporal);
        return;
    }

    if(inicio % 4 == 3 && inicio != 0 && numero_string[final] != '-'){

        Numero_miles[inicio] = '.';
        CargarlosPuntos(Numero_miles, numero_string, inicio + 1, final, temporal);
    }

    else{

        Numero_miles[inicio] = numero_string[final];
        CargarlosPuntos(Numero_miles, numero_string, inicio + 1, final - 1, temporal);
    }
}

void Cambiar_Orientacion_string(char *Numero_miles, int inicio, int final, char temporal){

    if(inicio >= final){

        return;
    }

    else{

        temporal = Numero_miles[inicio];
        Numero_miles[inicio] = Numero_miles[final];
        Numero_miles[final] = temporal;

        Cambiar_Orientacion_string(Numero_miles, inicio + 1, final - 1, temporal);
    }
}

void Mostrar_resultado_ejercicio5(char numero_miles[], char numero[]){

    printf(" El resultado de agregarle los puntos de miles al numero '%s' queda de la siguiente manera: '%s'\n", numero, numero_miles);
}
















//Ejercicio 6.

int Calcular_tamanio_mafia(int nivel_reunion){

    return (6*nivel_reunion);
}

char *SitiodelaReunion(int nivel_reunion){

    int tamanio_mafia = Calcular_tamanio_mafia(nivel_reunion);
    char *Cadena_Mafia = (char*)calloc(tamanio_mafia, sizeof(char));

    if(nivel_reunion != 0){

        Cargar_Reunion(Cadena_Mafia, nivel_reunion);
    }


    return Cadena_Mafia;
}

void Cargar_Reunion(char *Cadena_Mafia, int nivel_reunion){

    if(nivel_reunion == 1){

        strcat(Cadena_Mafia, "(-.-)");
        return;
    }

    strcat(Cadena_Mafia, "(-.");
    Cargar_Reunion(Cadena_Mafia, nivel_reunion - 1);

    strcat(Cadena_Mafia, ".-)");
}

void Mostrar_resultado_ejercicio6(char Cadena_mafia[], int nivel_reunion){

    printf(" Atencion, el Nivel de la reunion es %d, presentarse en el salon general: \n\n", nivel_reunion);
    printf(" '%s'\n", Cadena_mafia);
}















//Ejercicio 7.

void Validar_Cadena_String_ejercicio7(char *Cadena_string){

    bool bandera = true;
    int lon;
    do{

        if(!bandera){

            Cadena_string[0] = '\0';
            printf("\n Ingreso Invalido! Solo puede ingresar estos caracteres [l, L, H, h]!\n");
            printf(" Ingrese la ONDA DIGITAL a representar con altos y bajos (maximo 50 caracteres): ");
        }

        bandera = true;
        Ingresar_Cadena_Caracteres(Cadena_string, TAMANIO_ONDA_DIGITAL);
        fflush(stdin);

        lon = strlen(Cadena_string);

        for(int i = 0; i < lon - 1; i++){

            if(Cadena_string[i] != 'l' && Cadena_string[i] != 'L' && Cadena_string[i] != 'H' && Cadena_string[i] != 'h'){

                bandera = false;
                break;
            }
        }
    }
    while(!bandera);
}

char *ondaDigital(char Cadena_string[]){

    int longuitud = strlen(Cadena_string);
    int saltos = 0;


    for(int i = 0; i < longuitud - 1; i++){

        if(i != 0){

            if(Cadena_string[i] == 'l' || Cadena_string[i] == 'L'){

                if(Cadena_string[i - 1] == 'h' || Cadena_string[i - 1] == 'H'){

                    saltos ++;
                }
            }

            else{

                if(Cadena_string[i - 1] == 'l' || Cadena_string[i - 1] == 'L'){

                    saltos ++;
                }
            }
        }
    }

    char *Cadena_Digital = (char*) calloc((longuitud + saltos + 1), sizeof(char));
    int longuitud2 = strlen(Cadena_Digital);

    ondaDigital_Recursiva(Cadena_Digital, Cadena_string, 0, 0);

    return Cadena_Digital;
}


void ondaDigital_Recursiva(char *Cadena_Digital, char Cadena_string[], int pos_Digital, int inicio){

    if(Cadena_string[inicio] == '\0'){

        return;
    }

    if(Cadena_string[inicio] == 'l' || Cadena_string[inicio] == 'L'){

        if((Cadena_string[inicio - 1] == 'h' || Cadena_string[inicio - 1] == 'H') && pos_Digital != 0){

            strcat(Cadena_Digital, "|_");
            pos_Digital += 2;
        }

        else{

            strcat(Cadena_Digital, "_");
            pos_Digital ++;
        }
    }

    if(Cadena_string[inicio] == 'h' || Cadena_string[inicio] == 'H'){

        if((Cadena_string[inicio - 1] == 'l' || Cadena_string[inicio - 1] == 'L') && pos_Digital != 0){

            strcat(Cadena_Digital, "|-");
            pos_Digital += 2;
        }

        else{

            strcat(Cadena_Digital, "-");
            pos_Digital++;
        }
    }

    ondaDigital_Recursiva(Cadena_Digital, Cadena_string, pos_Digital, inicio + 1);
}


void Mostrar_resultado_ejercicio7(char Cadena_Digital[], char Cadena_string[]){

    printf(" La Cadena a representar es: '%s'\n\n", Cadena_string);
    printf(" La representacion en altos y bajos es: '%s' \n", Cadena_Digital);
}












//Ejercicio 8.

int *Cargar_ConjuntoA(int tam){

    int *ConjuntoA = (int*) calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){

        printf(" Ingrese el elemento %i del Conjunto A: ", i + 1);
        ConjuntoA[i] = Ingresar_Entero_Positivo();
        fflush(stdin);

        for(int j = 0; j < i; j++){

            if(ConjuntoA[j] == ConjuntoA[i]){

                while(ConjuntoA[j] == ConjuntoA[i]){

                    printf(" Ingreso Invalido! Debe ingresar un Numero que no este ya en el Conjunto A!\n");
                    printf(" Ingrese el elemento %i del Conjunto A: ", i + 1);
                    ConjuntoA[i] = Ingresar_Entero_Positivo();
                    fflush(stdin);
                }

                j = -1;
            }
        }
    }

    return ConjuntoA;
}

struct ListaSubConj *subconjuntosQueSumanN(int ConjuntoA[], int tam_conjA, int n){

    struct ListaSubConj *Resultado = (struct ListaSubConj*)calloc(1, sizeof(struct ListaSubConj));
    int almacen[tam_conjA];
    int indice_resultado = 0;

    subconjuntosQueSumanN_Recursiva(Resultado, ConjuntoA, tam_conjA, 0, n, 0, &indice_resultado, almacen, 0);

    return Resultado;
}

void subconjuntosQueSumanN_Recursiva(struct ListaSubConj *Resultado, int ConjuntoA[], int tam_conjA, int indice_ConjA, int n, int suma, int *indice_resultado, int *almacen, int tam_almacen){

    /*Caso Base*/
    if(suma == n){

        // Verificar si el subconjunto ya está en Formados
        for(int i = 0; i < Resultado->cantidad_formados; i++){

            if(Resultado->Formados[i].tam == tam_almacen){

                int iguales = 1;

                for(int j = 0; j < tam_almacen; j++) {

                    if(Resultado->Formados[i].subconjunto[j] != almacen[j]){
                        iguales = 0;
                        break;
                    }
                }

                if(iguales == 1){

                    return; // El subconjunto ya existe, no lo agregamos de nuevo
                }
            }
        }

        // Si el subconjunto no está en Formados, lo agregamos

        for(int i = 0; i < tam_almacen; i++){

            Resultado->Formados[*indice_resultado].subconjunto[i] = almacen[i];
        }

        Resultado->Formados[*indice_resultado].tam = tam_almacen;
        Resultado->cantidad_formados += 1;
        *indice_resultado += 1;
        return;
    }

    else if(suma >= n || indice_ConjA > tam_conjA){
        // Si se ha alcanzado el final del conjunto o la suma de los elementos supera N, se retorna
        return;
    }

    // Incluir el elemento actual en el Array
    almacen[tam_almacen] = ConjuntoA[indice_ConjA];
    subconjuntosQueSumanN_Recursiva(Resultado, ConjuntoA, tam_conjA, indice_ConjA + 1, n, suma + ConjuntoA[indice_ConjA], indice_resultado, almacen, tam_almacen + 1);

    // No incluir el elemento actual en el Array
    subconjuntosQueSumanN_Recursiva(Resultado, ConjuntoA, tam_conjA, indice_ConjA + 1, n, suma, indice_resultado, almacen, tam_almacen);
}

void Mostrar_resultado_ejercicio8(struct ListaSubConj Resultado, int ConjuntoA[], int tamconjA, int n){

    int i, j;
    printf(" El Conjunto A es: {");
    for(i = 0; i < tamconjA; i++){

        if(i == tamconjA - 1){

            printf("%d}\n", ConjuntoA[i]);
        }
        else{

            printf("%d, ", ConjuntoA[i]);
        }
    }

    printf("Los Subconjuntos que suman %d que se formaron son: ", n);

    for(i = 0; i < Resultado.cantidad_formados; i++){

        if(i == 0){

            printf("{");
        }

        else{

            printf(", {");
        }

        for(j = 0; j < Resultado.Formados[i].tam; j++){

            if(j == Resultado.Formados[i].tam - 1){

                printf("%d", Resultado.Formados[i].subconjunto[j]);
            }

            else{

                printf("%d, ", Resultado.Formados[i].subconjunto[j]);
            }
        }

        printf("}");
    }

    printf("\n");
}




//Ejercicio 9.

bool divisiblePor7(int Numero){

    if(Numero <= 70){

        if(Numero == 0 || Numero % 7 == 0){

            return true;
        }

        else{

            return false;
        }
    }

    return divisiblePor7((Numero / 10) - ((Numero % 10) * 2));
}

void Mostrar_resultado_ejercicio9(bool Resultado, int numero){

    if(Resultado){

        printf(" El numero %d es divisible por '7'!\n", numero);
    }

    else{

        printf(" El numero %d no es divisible por '7'!\n", numero);
    }
}














//Ejercicio 10.

int *explosion(int N, int B, int *Cantidad_Fragmentos){

    int *Fragmentos = (int*)calloc(1, sizeof(int));

    explosion_recursiva(&Fragmentos, Cantidad_Fragmentos, N, B);

    return Fragmentos;
}

void explosion_recursiva(int **Fragmentos, int *inicio, int N, int B){

    if(N <= B){

        (*Fragmentos)[*inicio] = N;
        (*inicio)++;

        *Fragmentos = (int*)realloc(*Fragmentos, (*inicio + 1) * sizeof(int));
        return;
    }

    explosion_recursiva(Fragmentos, inicio, N/B, B);
    explosion_recursiva(Fragmentos, inicio, N - (N/B), B);
}

void Mostrar_resultado_ejercicio10(int Fragmentos[], int Cantidad_Fragmentos, int N, int B){

    printf(" El Numero 'N' con la Bomba 'B' exploto en los siguientes fragmentos: [");

    for(int i = 0; i < Cantidad_Fragmentos; i++){

        if(i != 0){

            if(i == Cantidad_Fragmentos - 1){

            printf(", %d]\n\n", Fragmentos[i]);
        }

            else{

                printf(", %d", Fragmentos[i]);
            }
        }

        else{

            printf("%d", Fragmentos[i]);
        }
    }
}

