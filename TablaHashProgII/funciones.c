#include "funciones.h"
#include "validaciones.h"
#include "tipo_elemento.h"
#include "nodo.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>


// Ejercicio 4 .

int funcion_hashej4(int clave){

    return clave % moduloej4;
}




void Crear_Archivo(char archivo[], char modo[]){

    FILE *fp = fopen(archivo, modo);

    if(fp == NULL){

        perror(" No se pudo crear el Archivo: 'alumnos.dat'\n");
        fclose(fp);
        return;
    }

    Alumno aux = (Alumno)calloc(1, sizeof(struct AlumnoRep));
    
    if(aux == NULL){

        perror(" Error en la asignacion de memoria dinamica para los registros!\n");
        fclose(fp);
        return;
    }

    aux->Apellido[0] = '\0';
    aux->Nombre[0] = '\0';
    aux->Domicilio[0] = '\0';
    aux->legajo = 0;
    aux->Telefono = 0;
    aux->pos = 0;

    for(int i = 0; i < 99; i++){

        fwrite(aux, sizeof(struct AlumnoRep), 1, fp);
    }

    free(aux);
    fclose(fp);
}




void Altas_Archivo(char archivo[], char modo[], Lista Legajos, TablaHash Tablita){

    FILE *fp = fopen(archivo, modo);
    
    if(fp == NULL){

        perror(" No se pudo abrir el Archivo : 'alumnos.dat'\n");
        fclose(fp);
        return;
    }

    if(l_longitud(Legajos) == 100){

        printf(" El registro de alumnos esta lleno! no se pueden agregar mas alumnos!\n");
        fclose(fp);
        return;
    }

    Alumno nuevo = (Alumno)calloc(1, sizeof(struct AlumnoRep));
    
    if(nuevo == NULL){

        perror(" Error en la asignacion de memoria dinamica para el registro del alumno!\n");
        fclose(fp);
        return;
    }

    int bandera;

    do{

        do{
            printf(" Ingrese el legajo de 6 digitos del alumno a agregar (Numero entero positivo): ");
            nuevo->legajo = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(nuevo->legajo, 100000, 999999)){

                printf(" Ingreso Invalido! Debe ingresar un numero entero entre [100.000; 999.999]!\n");
                printf(" Ingrese el legajo de 6 digitos del alumno a agregar (Numero entero positivo): ");
                nuevo->legajo = Ingresar_Entero_Positivo();
                fflush(stdin);
            }

            if(l_buscar(Legajos, nuevo->legajo)){

                printf(" Ya existe un alumno con ese legajo! ingrese otro diferente!\n");
            }
        }
        while(l_buscar(Legajos, nuevo->legajo));
        
        TipoElemento elem = te_crear(nuevo->legajo);
        l_agregar(Legajos, elem);

        printf(" Ingrese el nombre del alumno (uno solo, sin utilizar la barra espaciadora): ");
        nuevo->Nombre[0] = '\0';
        Ingresar_Cadena_Caracteres(nuevo->Nombre, 50); 

        printf(" Ingrese el apellido del alumno (uno solo, sin utilizar la barra espaciadora): ");
        nuevo->Apellido[0] = '\0';
        Ingresar_Cadena_Caracteres(nuevo->Apellido, 50);

        printf(" Ingrese el domicilio del alumno (Pueblo donde vive, sin usar la barra espaciadora): ");
        nuevo->Domicilio[0] = '\0';
        Ingresar_Cadena_Caracteres(nuevo->Domicilio, 100);

        printf(" Ingrese el telefono del alumno (numero entero): ");
        nuevo->Telefono = Ingresar_Entero_Positivo();

        Alumno temp = (Alumno) calloc(1, sizeof(struct AlumnoRep));
        
        int pos = 0;
        rewind(fp);

        while(feof(fp) == 0){

            fread(temp, sizeof(struct AlumnoRep), 1, fp);

            if(temp->legajo == 0){

                fseek(fp, sizeof(struct AlumnoRep)* -1, SEEK_CUR);
                memset(temp, 0, sizeof(struct AlumnoRep));
                fwrite(nuevo, sizeof(struct AlumnoRep), 1, fp);

                int *ubicacion = (int*) calloc(1, sizeof(int));
                if(ubicacion == NULL){
                    
                    perror(" Error al asignar memoria para ubicacion!\n");
                    fclose(fp);
                    free(temp);
                    free(nuevo);
                    return;
                }

                *ubicacion = pos;
                TipoElemento aux = te_crear_con_valor(nuevo->legajo, ubicacion);
                th_insertar(Tablita, aux);
                break;
            }

            pos++;
        }

        if(l_longitud(Legajos) == 100){

            printf(" El registro de alumnos se lleno! no se pueden agregar mas alumnos!\n");
            fclose(fp);

            free(temp);
            free(nuevo);
            return;
        }

        else{

            printf(" Desea cargar otro Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
                printf(" Desea cargar otro Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
                bandera = Ingresar_Entero_Positivo();
                fflush(stdin);
            }
        }

        free(temp);
    }
    while(bandera != 0);
    
    fclose(fp);
    free(nuevo);
}




void Bajas_Archivo(char archivo[], char modo[], Lista Legajos, TablaHash Tablita){

    FILE *fp = fopen(archivo, modo);
    
    if(fp == NULL){

        perror(" No se pudo abrir el Archivo : 'alumnos.dat'\n");
        fclose(fp);
        return;
    }

    int leg, bandera;
    
    printf(" ACLARACION: Cada alumno que de de baja, desaparecera! Sera completamente eliminado del sistema!\n");
    system("pause");

    do{

        do{

            printf(" Ingrese el legajo de 6 digitos del alumno a borrar (Numero entero positivo): ");
            leg = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(leg, 100000, 999999)){

                printf(" Ingreso Invalido! Debe ingresar un numero entero entre [100.000; 999.999]!\n");
                printf(" Ingrese el legajo de 6 digitos del alumno a agregar (Numero entero positivo): ");
                leg = Ingresar_Entero_Positivo();
                fflush(stdin);
            }

            if(!l_buscar(Legajos, leg)){

                printf(" El legajo ingresado no existe!, Ingrese uno que este cargado!\n");
            }
        }
        while(!l_buscar(Legajos, leg));

        Alumno temp = (Alumno)calloc(1, sizeof(struct AlumnoRep));

        if(temp == NULL){

            perror(" Error en la asignacion de memoria dinamica para el registro que lee los datos del alumno!\n");
            fclose(fp);
            return;
        }
        
        TipoElemento aux = th_recuperar(Tablita, leg);
        int *pos = (int*)aux->valor;

        fseek(fp, sizeof(struct AlumnoRep)* (*pos), SEEK_SET);
        fread(temp, sizeof(struct AlumnoRep), 1, fp);
        fseek(fp, sizeof(struct AlumnoRep)* -1, SEEK_CUR);

        th_eliminar(Tablita, leg);
        
        l_borrar(Legajos, leg);

        free(aux);
        free(pos);

        temp->legajo = 0;
        temp->Apellido[0] = '\0';
        temp->Nombre[0] = '\0';
        temp->Domicilio[0] = '\0';
        temp->Telefono = 0;

        fwrite(temp, sizeof(struct AlumnoRep), 1, fp);
        free(temp);

        printf(" Desea borrar algun otro Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea borrar algun otro Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }
    }
    while(bandera != 0);

    fclose(fp);
}



void Modificaciones_Archivo(char archivo[], char modo[], Lista Legajos, TablaHash Tablita){

    FILE *fp = fopen(archivo, modo);
    
    if(fp == NULL){

        perror(" No se pudo abrir el Archivo : 'alumnos.dat'\n");
        fclose(fp);
        return;
    }

    int leg, bandera;

    do{
        
        do{

            printf(" Ingrese el legajo de 6 digitos del alumno a modificarle los datos (Numero entero positivo): ");
            leg = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(leg, 100000, 999999)){

                printf(" Ingreso Invalido! Debe ingresar un numero entero entre [100.000; 999.999]!\n");
                printf(" Ingrese el legajo de 6 digitos del alumno a agregar (Numero entero positivo): ");
                leg = Ingresar_Entero_Positivo();
                fflush(stdin);
            }

            if(!l_buscar(Legajos, leg)){

                printf(" El legajo ingresado no existe!, Ingrese uno que este cargado!\n");
            }
        }
        while(!l_buscar(Legajos, leg));

        TipoElemento aux = th_recuperar(Tablita, leg);
        int *pos = (int*)aux->valor;

        Alumno temp = (Alumno)calloc(1, sizeof(struct AlumnoRep));

        if(temp == NULL){

            perror(" Error en la asignacion de memoria dinamica para el registro que lee los datos del alumno!\n");
            fclose(fp);
            return;
        }

        fseek(fp, sizeof(struct AlumnoRep)* (*pos), SEEK_SET);
        fread(temp, sizeof(struct AlumnoRep), 1, fp);
        fseek(fp, sizeof(struct AlumnoRep)* -1, SEEK_CUR);

        printf(" Desea cambiar el Nombre del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea cambiar el nombre del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        if(bandera == 1){

            printf(" Ingrese el nuevo nombre del alumno (uno solo, sin utilizar la barra espaciadora): ");
            temp->Nombre[0] = '\0';
            Ingresar_Cadena_Caracteres(temp->Nombre, 50);
        }

        printf(" Desea cambiar el apellido del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea cambiar el apellido del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        if(bandera == 1){

            printf(" Ingrese el nuevo apellido del alumno (uno solo, sin utilizar la barra espaciadora): ");
            temp->Apellido[0] = '\0';
            Ingresar_Cadena_Caracteres(temp->Apellido, 50);
        }

        printf(" Desea cambiar el domicilio del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea cambiar el domicilio del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        if(bandera == 1){

            printf(" Ingrese el nuevo domicilio del alumno (Pueblo donde vive, sin usar la barra espaciadora): ");
            temp->Domicilio[0] = '\0';
            Ingresar_Cadena_Caracteres(temp->Domicilio, 100);
        }

        printf(" Desea cambiar el telefono del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea cambiar el telefono del Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        if(bandera == 1){

            printf(" Ingrese el nuevo telefono del alumno (Numero entero positivo) : ");
            temp->Telefono = Ingresar_Entero_Positivo();
        }

        fwrite(temp, sizeof(struct AlumnoRep), 1, fp);
        
        free(temp);

        printf(" Desea modificar algun otro Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [0; 1]!\n");
            printf(" Desea modificar algun otro Alumno? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }
    }
    while(bandera != 0);
    
    fclose(fp);
}




void Mostrar_Contenido_Archivo(char archivo[], char modo[]){

    FILE *fp = fopen(archivo, modo);
    
    if(fp == NULL){

        perror(" No se pudo abrir el Archivo : 'alumnos.dat'\n");
        fclose(fp);
        return;
    }

    Alumno temp = (Alumno) calloc(1, sizeof(struct AlumnoRep));

    if(temp == NULL){

        perror(" Error en la asignacion de memoria dinamica para el registro del alumno a mostrar!\n");
        fclose(fp);
        return;
    }
        
    int pos = 0;
    rewind(fp);

    printf(" ACLARACION: Se mostrara todo el Archivo! si solo tiene contenido la zona de ' N registro', quiere decir que esta vacio!\n");
    printf(" Mejor dicho, que no fue cargado aun, o si antes habia datos y ahora no, es que fue borrado! Anda igual que la TablaHash\n");
    printf(" en la funcion 'th_mostrar',  mostrando toda la estructura, sin importar que tenga o no datos!\n\n\n");


    printf(" | %-12s | %-8s | %-15s | %-15s | %-30s | %-12s\n\n", "N registro", "Legajo", "Apellido", "Nombre", "Domicilio", "telefono");
    while(feof(fp) == 0){

        fread(temp, sizeof(struct AlumnoRep), 1, fp);
        if(temp->legajo == 0){

            printf("\t%d\n", pos);
        }

        else{
            
            printf("\t%-7d | %-8d | %-15s | %-15s | %-30s | %-12d\n", pos, temp->legajo, temp->Apellido, temp->Nombre, temp->Domicilio, temp->Telefono);
        }
        pos++;
    }

    fclose(fp);
    free(temp);
}




void Mostrar_Encontrado(Alumno Encontrado){

    if(Encontrado->pos != -1){

        printf(" REGISTRO ENCONTRADO: \n\n");
        printf(" Posicion Encontrado: %d ; Legajo: %d ; Nombre: %s ; Apellido: %s ; Domicilio: %s ; Telefono %d \n", Encontrado->pos, Encontrado->legajo, Encontrado->Nombre, Encontrado->Apellido, Encontrado->Domicilio, Encontrado->Telefono);

    }

    else{

        printf(" No existe un alumno con el legajo: %d ! Resultado: NULL !\n", Encontrado->legajo);
    }
}




Alumno Buscar_Alumno(char archivo[], char modo[], Lista Legajos, TablaHash Tablita){

    FILE *fp = fopen(archivo, modo);
    
    if(fp == NULL){

        perror(" No se pudo abrir el Archivo : 'alumnos.dat'\n");
        fclose(fp);
        return NULL;
    }

    Alumno temp = (Alumno) calloc(1, sizeof(struct AlumnoRep));

    if(temp == NULL){

        perror(" Error en la asignacion de memoria dinamica para el registro del alumno a retornar!\n");
        fclose(fp);
        return NULL;
    }

    printf(" Ingrese el legajo de 6 digitos del alumno a buscar sus datos (Numero entero positivo): ");
    int leg = Ingresar_Entero_Positivo();
    TipoElemento casillero = th_recuperar(Tablita, leg);
    
    if(casillero == NULL){

        fclose(fp);
        temp->pos = -1;
        temp->legajo = leg;

        return temp;
    }

    int *pos = (int*)casillero->valor;

    fseek(fp, sizeof(struct AlumnoRep)* (*pos), SEEK_SET);
    fread(temp, sizeof(struct AlumnoRep), 1, fp);
    temp->pos = (*pos);

    fclose(fp);

    return temp;
}























// Ejercicio 5 .

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>

long long obtener_tiempo_en_nanosegundos() {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
    return (start.QuadPart * 1000000000) / frequency.QuadPart;
}

#else
#include <sys/time.h>
#include <unistd.h>

long long obtener_tiempo_en_nanosegundos() {
    struct timespec tiempo;
    clock_gettime(CLOCK_MONOTONIC, &tiempo);
    return (long long) tiempo.tv_sec * 1000000000LL + (long long) tiempo.tv_nsec;
}

#endif



bool es_primo(int num){
    
    if(num <= 1){

        return false;
    }
    
    
    for(int i = 2; i * i <= num; i++){

        if (num % i == 0){
            
            return false;
        }
    }

    return true;
}




int encontrar_primo(int cantidad_elementos){

    for(int i = cantidad_elementos; i > 1; i--){
    
        if(es_primo(i)){

            return i;
        }

        if(i == 1){

            return 1;
        }
    }
}




void Cargar_estructuras_avl_hash(TablaHash tablita, ArbolAVL arbol, int cantidad_elementos, int minimo_rango, int maximo_rango){

    int numero, i;

    for(i = 0; i < cantidad_elementos; i++){

        do{

            numero = minimo_rango + rand() % (maximo_rango - minimo_rango + 1);
        }
        while(avl_buscar(arbol, numero) != NULL);

        TipoElemento elem = te_crear(numero);
        avl_insertar(arbol, elem);
        th_insertar(tablita, elem);
    }
}




void Calcular_tiempos(TablaHash tablita, ArbolAVL arbol, int cantidad_a_buscar, int minimo_rango, int maximo_rango){

    int numero, i = 0;
    double promedio_avl = 0.0, promedio_hash = 0.0;
    
    long long inicio, final, diferencia, totalavl = 0, totalhash = 0;

    TipoElemento avl, hash;

    do{

        numero = minimo_rango + rand() % (maximo_rango - minimo_rango + 1);
        printf(" Numero a buscar : %d .\n", numero);

        // avl .
        inicio = obtener_tiempo_en_nanosegundos();
        hash = th_recuperar(tablita, numero);
        final = obtener_tiempo_en_nanosegundos();


        diferencia = final - inicio;
        totalavl += diferencia;
        

        // avl .
        inicio = obtener_tiempo_en_nanosegundos();
        avl = avl_buscar(arbol, numero);
        final = obtener_tiempo_en_nanosegundos();
   

        diferencia = final - inicio;
        totalhash += diferencia;
        
        i++;
        cantidad_a_buscar --;
    }
    while(cantidad_a_buscar > 0);

    promedio_avl = (double)totalavl / (double)i;
    promedio_hash = (double)totalhash / (double)i;
    double promedio_avl_segundos = promedio_avl / 1000000000.0;
    double promedio_hash_segundos = promedio_hash / 1000000000.0;
    
    printf("\n\n");
    printf(" Tras buscar %d elementos en las estructuras que podrian estar como no estar. El resultado es:\n", i);
    printf("Promedio de tiempo del AVL: %.10lf segs. Promedio de tiempo del HASH: %.10lf segs.\n", promedio_avl_segundos, promedio_hash_segundos);

}

























// Ejercicio 6 .


int funcion_hashej6(int clave){

    return clave % moduloej6;
}




void Altas_Vacunados( TablaHash tablita){

    char dia[3];
    char mes[3];
    char anio [5];
    char fechatotal[10];
    int fecha; 
    bool puedo;
    int bandera;


    do{
        
        fechatotal[0] = '\0';    
        printf(" Ingresaremos la fecha en la que se vacunaron las personas!\n\n");

        do{     
        
            do{
                
                puedo = true;
                printf(" Ingrese el año en que se vacunaron (numero entero entre [ 2020; 2022 ]): ");
                anio[0] = '\0';
                Ingresar_CadenaNumero_Positivo(anio, 5);

                if(anio[0] != '2' || anio[1] != '0' || anio[2] != '2' || (anio[3] != '0' && anio[3] != '1' && anio[3] != '2')){

                    printf(" Año invalido! debe ingresar un anio entre [ 2020; 2022 ]!\n");
                    puedo = false;
                }
            }
            while(!puedo);


            do{
                puedo = true;
                printf(" Ingrese el mes en que se vacunaron (numero entero entre [01; 12]): ");
                mes[0] = '\0';
                Ingresar_CadenaNumero_Positivo(mes, 3);

                if(mes[0] > '1'){

                    printf(" mes invalido! debe ingresar un mes entre [ 01; 12 ]!\n");
                    puedo = false;
                }

                if(mes[0] == '0' && mes[1] == '0'){

                    printf(" mes invalido! debe ingresar un mes entre [ 01; 12 ]!\n");
                    puedo = false;
                }

                if(mes[0] == '1' && mes[1] > '2'){

                    printf(" mes invalido! debe ingresar un mes entre [ 01; 12 ]!\n");
                    puedo = false;
                }
            }
            while(!puedo);
            
            do{
                puedo = true;
                printf(" Ingrese el dia en que se vacunaron (numero entero entre [01 ; 31] segun corresponda el mes de ese anio): ");
                dia[0] = '\0';
                Ingresar_CadenaNumero_Positivo(dia, 3);

                if(dia[0] == '0' && dia[1] == '0'){
                    
                    printf(" dia invalido! debe ingresar un dia entre [ 01; 31 ]!\n");
                    puedo = false;
                }

                if(dia[0] > '3' || (dia[0] == '3' && dia[1] > '1')){

                    printf(" dia invalido! debe ingresar un dia entre [ 01; 31 ]!\n");
                    puedo = false;
                }
            }
            while(!puedo);

        }
        while(!esfecha_valida(dia, mes, anio));
        
        strcat(fechatotal, anio);
        strcat(fechatotal, mes);
        strcat(fechatotal, dia);

        fecha = String_A_Entero(fechatotal);

        int i = 1;
        Lista l = l_crear();

        do{
            
            if(l_es_llena(l)){

                printf(" La lista de vacunados se lleno! No se pueden agregar mas personas!\n");
                break;
            }

            vacunado nuevo = (vacunado)calloc(1, sizeof(struct RegistroRep));

            printf(" Ingresaremos al vacunado Nº%d\n\n", i);

            printf(" Ingrese el nombre del vacunado Nº%d (uno solo, sin utilizar la barra espaciadora): ", i);
            nuevo->nombre[0] = '\0';
            Ingresar_Cadena_Caracteres(nuevo->nombre, 50); 

            printf(" Ingrese el apellido del vacunado Nº%d (uno solo, sin utilizar la barra espaciadora): ", i);
            nuevo->apellido[0] = '\0';
            Ingresar_Cadena_Caracteres(nuevo->apellido, 50);
            
            printf(" Ingrese el dni del vacunado Nº%d (Numero entero entre [ 1.000.000; 99.999.999]): ",i);
            nuevo->dni = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(nuevo->dni, 1000000, 99999999)){

                printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 1.000.000; 99.999.999 ]!\n");
                printf(" Ingrese el dni del vacunado (Numero entero entre [ 1.000.000; 99.999.999]): ");
                nuevo->dni = Ingresar_Entero_Positivo();
                fflush(stdin);
            }

            TipoElemento elem = te_crear_con_valor(i, nuevo);
            l_agregar(l, elem);

            printf(" Desea cargar a otro vacunado? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();

            while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

                printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1 ]!\n");
                printf(" Desea cargar a otro vacunado? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
                bandera = Ingresar_Entero_Positivo();
                fflush(stdin);
            }

            i++;
        }
        while(bandera != 0);

        TipoElemento fecha_vacunatorio = te_crear_con_valor(fecha, l);
        th_insertar(tablita, fecha_vacunatorio);

        printf(" Desea cargar otra fecha de vacunacion? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
        bandera = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(bandera, 0, 1)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [ 0; 1 ]!\n");
            printf(" Desea cargar otra fecha de vacunacion? (+ Ingrese ' 1 ' si desea hacerlo; + Ingrese ' 0 ' si no desea hacerlo): ");
            bandera = Ingresar_Entero_Positivo();
            fflush(stdin);
        }
    }
    while(bandera != 0);
}

TipoElemento Buscar_Vacunados(TablaHash tablita){

    char dia[3];
    char mes[3];
    char anio [5];
    char fechatotal[10];
    int fecha; 
    bool puedo;
        
    fechatotal[0] = '\0';    
    printf(" Ingresaremos la fecha en la que se vacunaron las personas!\n\n");

    do{     
    
        do{
            
            puedo = true;
            printf(" Ingrese el año en que se vacunaron (numero entero entre [ 2020; 2022 ]): ");
            anio[0] = '\0';
            Ingresar_CadenaNumero_Positivo(anio, 5);

            if(anio[0] != '2' || anio[1] != '0' || anio[2] != '2' || (anio[3] != '0' && anio[3] != '1' && anio[3] != '2')){

                printf(" Año invalido! debe ingresar un anio entre [ 2020; 2022 ]!\n");
                puedo = false;
            }
        }
        while(!puedo);


        do{
            puedo = true;
            printf(" Ingrese el mes en que se vacunaron (numero entero entre [01; 12]): ");
            mes[0] = '\0';
            Ingresar_CadenaNumero_Positivo(mes, 3);

            if(mes[0] > '1'){

                printf(" mes invalido! debe ingresar un mes entre [ 01; 12 ]!\n");
                puedo = false;
            }

            if(mes[0] == '0' && mes[1] == '0'){

                printf(" mes invalido! debe ingresar un mes entre [ 01; 12 ]!\n");
                puedo = false;
            }

            if(mes[0] == '1' && mes[1] > '2'){

                printf(" mes invalido! debe ingresar un mes entre [ 01; 12 ]!\n");
                puedo = false;
            }
        }
        while(!puedo);
        
        do{
            puedo = true;
            printf(" Ingrese el dia en que se vacunaron (numero entero entre [01 ; 31] segun corresponda el mes de ese anio): ");
            dia[0] = '\0';
            Ingresar_CadenaNumero_Positivo(dia, 3);

            if(dia[0] == '0' && dia[1] == '0'){
                
                printf(" dia invalido! debe ingresar un dia entre [ 01; 31 ]!\n");
                puedo = false;
            }

            if(dia[0] > '3' || (dia[0] == '3' && dia[1] > '1')){

                printf(" dia invalido! debe ingresar un dia entre [ 01; 31 ]!\n");
                puedo = false;
            }
        }
        while(!puedo);

    }
    while(!esfecha_valida(dia, mes, anio));
    
    strcat(fechatotal, anio);
    strcat(fechatotal, mes);
    strcat(fechatotal, dia);

    fecha = String_A_Entero(fechatotal);

    return th_recuperar(tablita, fecha);
}





void mostrar_vacunados(Lista vacunados){

    Iterador iter = iterador(vacunados);
    
    while(hay_siguiente(iter)){

        TipoElemento elem = siguiente(iter);

        vacunado persona = (vacunado)elem->valor;

        printf("%s      %s      %d \n", persona->nombre, persona->apellido, persona->dni);
    }

    free(iter);
}





bool esfecha_valida(char dia[], char mes[], char anio[]){

    bool biciesto;
    
    if(anio[3] == '0'){

        biciesto = true;
    }

    if(biciesto){

        if(mes[0] == '0' && mes[1] == '2'){

            if(dia[0] > '2'){

                printf(" Dia invalido! El mes de febrero del anio 2020 solo puede tener 29 dias, ya que es año biciesto!\n");
                return false;
            }
        }

        else{

            if((mes[0] == '0' && mes[1] == '4') || (mes[0] == '0' && mes[1] == '6') || (mes[0] == '0' && mes[1] == '9') || (mes[0] == '1' && mes[1] == '1')){

                if(dia[0] == '3' && dia[1] > 0){

                    printf(" Dia Invalido! El mes %s no puede tener mas de 30 dias!\n", mes);
                    return false;
                }
            }
        }
    }

    else{

       if(mes[0] == '0' && mes[1] == '2'){

            if(dia[0] > '2' || (dia[0] == '2' && dia[1] > '8')){

                printf(" Dia invalido! El mes de febrero del anio %s solo puede tener 28 dias, ya que no es biciesto!\n", anio);
                return false;
            }
        }

        else{

            if((mes[0] == '0' && mes[1] == '4') || (mes[0] == '0' && mes[1] == '6') || (mes[0] == '0' && mes[1] == '9') || (mes[0] == '1' && mes[1] == '1')){

                if(dia[0] == '3' && dia[1] > 0){

                    printf(" Dia Invalido! El mes %s no puede tener mas de 30 dias!\n", mes);
                    return false;
                }
            }
        } 
    }
    
    return true;
}