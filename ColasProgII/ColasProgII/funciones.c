#include "funciones.h"
#include "validaciones.h"
#include "tipo_elemento.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>



void Cargar_Manualmente_Repetidos(Cola C){

    int cantidad;
    bool pudo;

    printf("Ingrese la cantidad de elementos a agregar a la COLA (numero entero entre [1; 10]): ");
    cantidad = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

        printf(" Ingreso Invalido! Debe ingresar una cantidad entre [1; 10]!\n");
        printf("Ingrese la cantidad de elementos a agregar a la COLA (Numero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    for(int i = 0; i < cantidad; i++){

        pudo = true;

        if(!c_es_llena(C)){

            printf("Ingrese el numero a agregar a la COLA: ");
            TipoElemento nuevo = te_crear(Ingreso_Entero_Positivo_Negativo());

            pudo = c_encolar(C, nuevo);

            if(c_es_llena(C)){

                printf("La COLA se acaba de llenar! No se puede agregar mas elementos! Volveremos al MENU PRINCIPAL!\n");
                system("pause");
                system("cls");

                break;
            }
        }

        else{

            printf("La COLA ya esta llena! No se puede agregar elementos! Volveremos al MENU PRINCIPAL!\n");
            system("pause");
            system("cls");

            break;
        }
    }
}







void Cargar_Manualmente(Cola C) {

    int cantidad, clave;
    bool pudo, repetido;

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();

    printf("Ingrese la cantidad de elementos a agregar a la COLA (Numero entre [1; 10]): ");
    cantidad = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

        printf(" Ingreso Invalido! Debe ingresar una cantidad entre [1; 10]!\n");
        printf("Ingrese la cantidad de elementos a agregar a la COLA (Numero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    for(int i = 0; i < cantidad; i++){

        pudo = true;

        if(!c_es_llena(C)){

            do {

                repetido = false;

                printf("Ingrese el numero a agregar a la COLA: ");
                clave = Ingreso_Entero_Positivo_Negativo();

                while(!c_es_vacia(C)){

                    ya_cargado = c_desencolar(C);

                    if(clave == ya_cargado->clave){

                        repetido = true;
                    }

                    c_encolar(auxiliar, ya_cargado);
                }

                while(!c_es_vacia(auxiliar)){

                    ya_cargado = c_desencolar(auxiliar);
                    c_encolar(C, ya_cargado);
                }

                if(repetido){

                    printf("Ingreso Invalido! El numero ya se encuentra en la COLA, intente con otro numero!\n");
                }
            }
            while(repetido);

            TipoElemento nuevo = te_crear(clave);
            pudo = c_encolar(C, nuevo);

            if(c_es_llena(C)){

                printf("La COLA se acaba de llenar! No se puede agregar mas elementos! Volveremos al MENU PRINCIPAL!\n");
                system("pause");
                system("cls");

                break;
            }
        }

        else{

            printf("La COLA ya esta llena! No se puede agregar elementos! Volveremos al MENU PRINCIPAL!\n");
            system("pause");
            system("cls");

            break;
        }
    }

    free(auxiliar);
}





void Cargar_Aleatoriamente(Cola C){

    srand(time(NULL));

    int cantidad, clave;
    bool repetido;

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();

    if(!c_es_llena(C)){

        printf(" Cuantos numeros cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 10]!\n");
            printf(" Cuantos elementos cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
            cantidad = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        do{

            do{

                clave = (rand() % (20 - (-20) + 1)) + (-20);

                repetido = false;

                while(!c_es_vacia(C)){

                    ya_cargado = c_desencolar(C);

                    if(ya_cargado->clave == clave){

                        repetido = true;
                    }

                    c_encolar(auxiliar, ya_cargado);
                }

                while(!c_es_vacia(auxiliar)){

                    ya_cargado = c_desencolar(auxiliar);
                    c_encolar(C, ya_cargado);
                }

            }
            while(repetido);

            TipoElemento elem = te_crear(clave);
            c_encolar(C, elem);
            cantidad --;

        }
        while(cantidad > 0 && !c_es_llena(C));

        if(cantidad > 0 && c_es_llena(C)){

            printf(" Se lleno la COLA! Faltaron cargar %d elementos!\n", cantidad);
            system("pause");
            system("cls");
        }
    }

    else{

        printf(" La COLA ya esta llena por lo que no se le pueden cargar mas numeros! Volveremos al MENU PRINCIPAL!\n");
        system("pause");
        system("cls");
    }

    free(auxiliar);

}





void Cargar_Aleatoriamente_Repetidos(Cola C){

    srand(time(NULL));

    int cantidad, clave, clave_anterior, i = 0;

    if(!c_es_llena(C)){

        printf(" Cuantos numeros cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 10]!\n");
            printf(" Cuantos elementos cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
            cantidad = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        do{

            clave = (rand() % (20 - (-20) + 1)) + (-20);

            if( i != 0){

                if(clave > clave_anterior){

                    while(clave < clave_anterior){

                        clave = (rand() % (20 - (-20) + 1)) + (-20);
                    }
                }

                if(clave < clave_anterior){

                    while(clave < clave_anterior){

                        clave = (rand() % (20 - (-20) + 1)) + (-20);
                    }
                }
            }

            TipoElemento elem = te_crear(clave);
            c_encolar(C, elem);
            cantidad --;
            clave_anterior = clave;

        }
        while(cantidad > 0 && !c_es_llena(C));

        if(cantidad > 0 && c_es_llena(C)){

            printf(" Se lleno la COLA! Faltaron cargar %d elementos!\n", cantidad);
            system("pause");
            system("cls");
        }
    }

    else{

        printf(" La COLA ya esta llena por lo que no se le pueden cargar mas numeros! Volveremos al MENU PRINCIPAL!\n");
        system("pause");
        system("cls");
    }

}
















// Ejercicio 2 .

bool C_EJ_Verificar_Existencia(Cola C, int numero){

    bool esta = false;

    TipoElemento ya_Cargado;
    Cola auxiliar = c_crear();

    if(c_es_vacia(C)){

        printf(" La COLA esta vacia, por lo que no esta el elemento en ella!\n");
    }

    else{

        while(!c_es_vacia(C)){

            ya_Cargado = c_desencolar(C);

            if(numero == ya_Cargado->clave){

                esta = true;
            }

            c_encolar(auxiliar, ya_Cargado);
        }

        while(!c_es_vacia(auxiliar)){

            ya_Cargado = c_desencolar(auxiliar);
            c_encolar(C, ya_Cargado);
        }
    }

    free(auxiliar);

    return esta;
}





int C_EJ_Longuitud_Cola(Cola C){

    int longuitud = 0;

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();

    while(!c_es_vacia(C)){

        longuitud++;

        ya_cargado = c_desencolar(C);
        c_encolar(auxiliar, ya_cargado);
    }

    while(!c_es_vacia(auxiliar)){

        ya_cargado = c_desencolar(auxiliar);
        c_encolar(C, ya_cargado);
    }

    free(auxiliar);

    return longuitud;
}





Cola C_EJ_Insertar_Elemento(Cola C, int pos){

    int longuitud = 0;
    bool agregado = false;
    TipoElemento ya_cargado;
    TipoElemento nuevo;
    Cola auxiliar = c_crear();

    if(c_es_vacia(C) && pos != 1){

        printf(" Posicion Invalida! La COLA esta vacia, solo puede colocar un numero en la posicion 1 de la misma!, Volveremos al MENU PRINCIPAL!\n");
        free(auxiliar);

        return C;
    }

    if(c_es_llena(C)){

        printf(" La COLA esta llena! no se le puede agregar mas numeros! Volveremos al MENU PRINCIPAL!\n");
        free(auxiliar);

        return C;
    }

    while(!c_es_vacia(C)){

        longuitud++;

        if(longuitud == pos){

            printf(" Ingrese el numero a colocar en la posicion %d de la COLA: ", pos);

            nuevo = te_crear(Ingreso_Entero_Positivo_Negativo());
            agregado = c_encolar(auxiliar, nuevo);
        }

        ya_cargado = c_desencolar(C);
        c_encolar(auxiliar, ya_cargado);
    }

    if(pos == longuitud + 1){

        nuevo = te_crear(Ingreso_Entero_Positivo_Negativo());
        agregado = c_encolar(auxiliar, nuevo);
    }

    while(!c_es_vacia(auxiliar)){

        ya_cargado = c_desencolar(auxiliar);
        c_encolar(C, ya_cargado);
    }

    if(!agregado){

        printf(" Posicion Invalida! Debe ingresar una posicion entre [1; %d] para colocar un numero! Volveremos al MENU PRINCIPAL\n", longuitud + 1);
    }

    free(auxiliar);

    return C;
}





Cola C_EJ_Eliminar_Elemento(Cola C, int clave){

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();

    if(c_es_vacia(C)){

        printf(" La COLA esta vacia! No hay elementos a eliminar! Volveremos al MENU PRINCIPAL!\n");
        free(auxiliar);

        return C;
    }

    while(!c_es_vacia(C)){

        ya_cargado = c_desencolar(C);

        if(ya_cargado->clave != clave){

            c_encolar(auxiliar, ya_cargado);
        }
    }

    while(!c_es_vacia(auxiliar)){

        ya_cargado = c_desencolar(auxiliar);
        c_encolar(C, ya_cargado);
    }

    free(auxiliar);

    return C;
}





Cola C_EJ_Copiar_Cola(Cola Original){

    TipoElemento ya_cargado, elem_copia;
    Cola auxiliar = c_crear();
    Cola copia = c_crear();

    if(c_es_vacia(Original)){

        printf(" La COLA esta vacia! por lo que no hay numeros a copiar! Volveremos al MENU PRINCIPAL!\n");
        free(auxiliar);

        return copia;
    }

    while(!c_es_vacia(Original)){

        ya_cargado = c_desencolar(Original);

        elem_copia = te_crear(ya_cargado->clave);

        c_encolar(auxiliar, ya_cargado);
        c_encolar(copia, elem_copia);
    }

    while(!c_es_vacia(auxiliar)){

        ya_cargado = c_desencolar(auxiliar);
        c_encolar(Original, ya_cargado);
    }

    free(auxiliar);

    return copia;
}





Cola C_EJ_Invertir_Cola(Cola Original){

    TipoElemento ya_cargado, elem_invertido;
    Cola auxiliar = c_crear();
    Cola Resultado = c_crear();
    Pila Invertida = p_crear();

    if(c_es_vacia(Original)){

        printf(" La COLA esta vacia! No hay numeros a invertir! Volveremos al MENU PRINCIPAL!\n");
        free(auxiliar);
        free(Invertida);

        return Resultado;
    }

    while(!c_es_vacia(Original)){

        ya_cargado = c_desencolar(Original);

        elem_invertido = te_crear(ya_cargado->clave);

        c_encolar(auxiliar, ya_cargado);
        p_apilar(Invertida, elem_invertido);
    }

    while(!c_es_vacia(auxiliar) && !p_es_vacia(Invertida)){

        ya_cargado = c_desencolar(auxiliar);
        elem_invertido = p_desapilar(Invertida);

        c_encolar(Original, ya_cargado);
        c_encolar(Resultado, elem_invertido);
    }

    free(Invertida);
    free(auxiliar);

    return Resultado;
}


































// Ejercicio 3 .

bool Verificar_Igualdad(Cola C1, Cola C2){

    bool iguales = true;

    TipoElemento elem_c1, elem_c2;
    Cola auxiliar1 = c_crear();
    Cola auxiliar2 = c_crear();

    if(c_es_vacia(C1) && c_es_vacia(C2)){

        printf(" Ambas COLAS estan vacias! por lo que puedo considerar que son iguales!\n");

        free(auxiliar1);
        free(auxiliar2);

        return iguales;
    }

    else if(c_es_vacia(C1) || c_es_vacia(C2)){

        printf(" Una de las COLAS esta vacia y la otra no! por lo que no son iguales!\n");
        iguales = false;

        free(auxiliar1);
        free(auxiliar2);

        return iguales;
    }

    else if(C_EJ_Longuitud_Cola(C1) != C_EJ_Longuitud_Cola(C2)){

        printf(" Las COLAS no tienen la misma cantidad de numeros! por lo que no son iguales!\n");
        iguales = false;

        free(auxiliar1);
        free(auxiliar2);

        return iguales;
    }

    else{

        while(!c_es_vacia(C1) && !c_es_vacia(C2)){

            elem_c1 = c_desencolar(C1);
            elem_c2 = c_desencolar(C2);

            if(elem_c1->clave != elem_c2->clave && iguales){

                iguales = false;
            }

            c_encolar(auxiliar1, elem_c1);
            c_encolar(auxiliar2, elem_c2);
        }

        while(!c_es_vacia(C1) && !c_es_vacia(C2)){

            elem_c1 = c_desencolar(auxiliar1);
            elem_c2 = c_desencolar(auxiliar2);
            c_encolar(C1, elem_c1);
            c_encolar(C2, elem_c2);
        }

        free(auxiliar1);
        free(auxiliar2);
    }

    return iguales;
}





































// Ejercicio 4 .


Cola Obtener_Sin_Repetidos(Cola C){

    int veces;

    TipoElemento ya_cargado, elem_copia;
    Cola Resultado = c_crear();
    Cola auxiliar = c_crear();
    Cola auxiliar_c = c_crear();

    if(c_es_vacia(C)){

        printf(" La COLA esta vacia! intente agregar elementos a la COLA la proxima vez!\n");

        free(auxiliar);
        free(auxiliar_c);

        return Resultado;
    }

    Cola copia = C_EJ_Copiar_Cola(C);

    while(!c_es_vacia(C)){

        veces = 0;

        ya_cargado = c_desencolar(C);

        while(!c_es_vacia(copia)){

            elem_copia = c_desencolar(copia);

            if(ya_cargado->clave == elem_copia->clave){

                veces++;
            }

            c_encolar(auxiliar_c, elem_copia);
        }

        while(!c_es_vacia(auxiliar_c)){

            elem_copia = c_desencolar(auxiliar_c);
            c_encolar(copia, elem_copia);
        }

        if(veces == 1){

            TipoElemento elem_r = te_crear(ya_cargado->clave);
            c_encolar(Resultado, elem_r);
        }

        c_encolar(auxiliar, ya_cargado);
    }

    while(!c_es_vacia(auxiliar)){

        ya_cargado = c_desencolar(auxiliar);
        c_encolar(C, ya_cargado);
    }

    free(copia);
    free(auxiliar_c);
    free(auxiliar);

    return Resultado;
}





bool Cola_Ordenada(Cola C){

    bool ordenado = false;
    int i = 0, mayor = 0, menor = 0;
    int longuitud = C_EJ_Longuitud_Cola(C);

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();
    Cola basura = c_crear();

    if(longuitud == 1){

        free(auxiliar);
        free(basura);

        return false;
    }

    while(!c_es_vacia(C)){

        TipoElemento nuevo;

        ya_cargado = c_desencolar(C);

        if(i != 0){

            if(nuevo->clave < ya_cargado->clave || nuevo->clave == ya_cargado->clave){

                mayor++;
            }

            c_encolar(basura, nuevo);
        }

        nuevo = te_crear(ya_cargado->clave);
        c_encolar(auxiliar, ya_cargado);
        i++;
    }

    i = 0;

    free(basura);

    basura = c_crear();

    while(!c_es_vacia(auxiliar)){

        TipoElemento nuevo;

        ya_cargado = c_desencolar(auxiliar);

        if(i != 0){

            if((nuevo->clave > ya_cargado->clave) || (nuevo->clave == ya_cargado->clave)){

                menor++;
            }

            c_encolar(basura, nuevo);
        }

        nuevo = te_crear(ya_cargado->clave);
        c_encolar(C, ya_cargado);
        i++;
    }

    if((longuitud - 1 == mayor) || (longuitud - 1 == menor)){

        ordenado = true;
    }

    free(basura);
    free(auxiliar);

    return ordenado;
}



























// Ejercicio 5 .


void c_ej5_Carga_Manual(Cola C){

    int cantidad, clave;
    bool pudo, repetido;

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();

    printf(" Ingrese la cantidad de elementos a agregar a la COLA (Numero entre [1; 10]): ");
    cantidad = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 10]!\n");
        printf(" Cuantos elementos cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    for(int i = 0; i < cantidad; i++){

        pudo = true;

        if(!c_es_llena(C)){

            do{

                repetido = false;

                do{

                    printf("Ingrese el numero a agregar a la COLA (entero >= 2): ");
                    clave = Ingresar_Entero_Positivo();

                    if(clave < 2){

                        printf("Ingreso Invalido! Debe ingresar un numero >= 2!\n");
                    }

                }
                while(clave < 2);

                while(!c_es_vacia(C)){

                    ya_cargado = c_desencolar(C);

                    if(clave == ya_cargado->clave){

                        repetido = true;
                    }

                    c_encolar(auxiliar, ya_cargado);
                }

                while(!c_es_vacia(auxiliar)){

                    ya_cargado = c_desencolar(auxiliar);
                    c_encolar(C, ya_cargado);
                }

                if(repetido){

                    printf("Ingreso Invalido! El numero ya se encuentra en la COLA, intente con otro numero!\n");
                }

            }
            while(repetido);

            TipoElemento nuevo = te_crear(clave);
            pudo = c_encolar(C, nuevo);

            if(c_es_llena(C)){

                printf("La COLA se acaba de llenar! No se puede agregar mas elementos! Volveremos al MENU PRINCIPAL!\n");
                system("pause");
                system("cls");

                break;
            }

        }

        else{

            printf("La COLA ya esta llena! No se puede agregar elementos! Volveremos al MENU PRINCIPAL!\n");
            system("pause");
            system("cls");

            break;
        }
    }

    free(auxiliar);
}






void c_ej5_Carga_Aleatoria(Cola C){

    srand(time(NULL));

    int cantidad, clave;
    bool repetido;

    TipoElemento ya_cargado;
    Cola auxiliar = c_crear();

    if(!c_es_llena(C)){

        printf(" Cuantos numeros cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

            printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 10]!\n");
            printf(" Cuantos elementos cargaremos en la COLA? (Numero Entero entre [1; 10]): ");
            cantidad = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        do{

            do{

                clave = rand() % 20 + 2;

                repetido = false;

                while(!c_es_vacia(C)){

                    ya_cargado = c_desencolar(C);

                    if(ya_cargado->clave == clave){

                        repetido = true;
                    }

                    c_encolar(auxiliar, ya_cargado);
                }

                while(!c_es_vacia(auxiliar)){

                    ya_cargado = c_desencolar(auxiliar);
                    c_encolar(C, ya_cargado);
                }

            }
            while(repetido);

            TipoElemento elem = te_crear(clave);
            c_encolar(C, elem);
            cantidad --;

        }
        while(cantidad > 0 && !c_es_llena(C));

        if(cantidad > 0 && c_es_llena(C)){

            printf(" Se lleno la COLA! Faltaron cargar %d elementos!\n", cantidad);
            system("pause");
            system("cls");
        }
    }

    else{

        printf(" La COLA ya esta llena por lo que no se le pueden cargar mas numeros! Volveremos al MENU PRINCIPAL!\n");
        system("pause");
        system("cls");
    }

    free(auxiliar);

}






void c_ej5_Mostrar_Resultado(Cola C){

    Cola cauxiliar = c_crear();
    TipoElemento ya_cargado;

    while(!c_es_vacia(C)){

        ya_cargado = c_desencolar(C);

        int n = *(int*) ya_cargado->valor;

        if(n == 0){

            printf(" %d ---> 'DIVISOR TOTAL'\n", ya_cargado->clave);
        }

        if(n == 1){

            printf(" %d ---> 'DIVISOR PARCIAL'\n", ya_cargado->clave);
        }

        c_encolar(cauxiliar, ya_cargado);
    }

    while(!c_es_vacia(cauxiliar)){

        ya_cargado = c_desencolar(cauxiliar);
        c_encolar(C, ya_cargado);
    }

    free(cauxiliar);
}





Cola Obtener_Divisores(Cola C){

    Cola Resultado = c_crear();

    TipoElemento ya_cargado, elem_copia, elem_resultado;

    int longuitud = C_EJ_Longuitud_Cola(C);
    float porcentaje_Unidad = 100.0 / longuitud;
    float porcentaje_actual;

    if(c_es_vacia(C)){

        printf(" La COLA esta vacia! No pose ninguna clase de divisor al no tener elementos en la misma!\n");

        return Resultado;
    }

    Cola cauxiliar = c_crear();
    Cola copia = C_EJ_Copiar_Cola(C);
    Cola copia_auxiliar = c_crear();

    while(!c_es_vacia(C)){

        porcentaje_actual = 0.0;

        ya_cargado = c_desencolar(C);

        while(!c_es_vacia(copia)){

            elem_copia = c_desencolar(copia);

            if((elem_copia->clave % ya_cargado->clave) == 0){

                porcentaje_actual += porcentaje_Unidad;
            }

            c_encolar(copia_auxiliar, elem_copia);
        }

        if(porcentaje_actual > 99.9){

            int *n = (int*) calloc(1, sizeof(int));
            *(n) = 0;
            elem_resultado = te_crear_con_valor(ya_cargado->clave, n);

            c_encolar(Resultado, elem_resultado);
        }

        if((porcentaje_actual < 99.9) && (porcentaje_actual > 49.9)){

            int *m = (int*) calloc(1, sizeof(int));
            *(m) = 1;

            elem_resultado = te_crear_con_valor(ya_cargado->clave, m);

            c_encolar(Resultado, elem_resultado);
        }

        while(!c_es_vacia(copia_auxiliar)){

            elem_copia = c_desencolar(copia_auxiliar);
            c_encolar(copia, elem_copia);
        }

        c_encolar(cauxiliar, ya_cargado);
    }

    while(!c_es_vacia(cauxiliar)){

        ya_cargado = c_desencolar(cauxiliar);
        c_encolar(C, ya_cargado);
    }

    free(cauxiliar);
    free(copia);
    free(copia_auxiliar);

    return Resultado;
}






























// Ejercicio 6 .

void Cargar_Aleatoriamente_Pila(Pila P){

    srand(time(NULL));

    Pila P_Auxiliar = p_crear();
    TipoElemento ya_cargado;

    bool repetido;
    int clave, cantidad;

    if(!p_es_llena(P)){

        printf(" Cuantos elementos Cargaremos? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

            printf(" Ingreso invalido! debe ingresar una cantidad entre [1; 10] !\n");
            printf(" Cuantos elementos Cargaremos? (Numero Entero entre [1; 10]): ");
            cantidad = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        do{

            clave = (rand() % (20 - (-20) + 1)) + (-20);

            do{

                repetido = false;

                while(!p_es_vacia(P)){

                    ya_cargado = p_desapilar(P);

                    if(ya_cargado->clave == clave){

                        repetido = true;
                        p_apilar(P, ya_cargado);
                        break;
                    }

                    else{

                        p_apilar(P_Auxiliar, ya_cargado);
                    }
                }

                while(!p_es_vacia(P_Auxiliar)){

                    ya_cargado = p_desapilar(P_Auxiliar);

                    p_apilar(P, ya_cargado);
                }

                if(repetido){

                    clave = (rand() % (20 - (-20) + 1)) + (-20);
                }

            }
            while(repetido);

            TipoElemento elemento = te_crear(clave);
            p_apilar(P, elemento);
            cantidad--;

        }
        while(cantidad > 0 && !p_es_llena(P));

        if(cantidad > 0 && p_es_llena(P)){

            printf(" No se puede cargar mas elementos a la PILA ya que esta llena!\n");
            system("pause");
            system("cls");
        }
    }

    else{

        printf(" La PILA se encuentra llena!, no puede agregar mas elementos!\n");
        system("pause");
        system("cls");
    }

    free(P_Auxiliar);
}






void Cargar_Manualmente_Pila(Pila P){

    int cantidad;
    bool pudo;

    printf("Ingrese la cantidad de elementos a agregar en la PILA (Numero entero entre [1; 10]): ");
    cantidad = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

        printf(" Ingreso Invalido! Debe ingresar un numero entero entre [1; 10]!\n");
        printf(" Cuantos elementos cargaremos en la PILA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    for(int i = 0; i < cantidad; i++){

        pudo = true;

        if(!p_es_llena(P)){

            printf("Ingrese la clave del elemento a agregar en la PILA (Numero Entero): ");
            TipoElemento elem = te_crear(Ingreso_Entero_Positivo_Negativo());

            pudo = p_apilar(P, elem);

            if(p_es_llena(P)){

                printf("La PILA se lleno! No puede agregar mas elementos!\n");
                system("pause");
                system("cls");

                break;
            }
        }

        else{

            printf("La PILA se encuentra llena! No puede agregar mas elementos!\n");
            system("pause");
            system("cls");

            break;
        }
    }
}






Lista Valores_Repetidos_Posiciones(Cola C, Pila P){

    int posicion_pila = 1, posicion_cola;
    bool agregar;

    struct posicion *comprobar;


    Lista L = l_crear();

    if(c_es_vacia(C) && p_es_vacia(P)){

        printf(" Tanto la COLA como la PILA estan vacias! por lo que no hay elementos en comun!, cargue las primero para obtener un resultado!\n");

        return L;
    }

    if(c_es_vacia(C) || p_es_vacia(P)){

        printf(" Una de las estructuras (COLA, PILA) esta vacia! por lo que no hay elementos en comun!, cargue las primero para obtener un resultado!\n");

        return L;
    }

    TipoElemento elem_p, elem_c, comprobador;

    Pila pauxiliar = p_crear();
    Cola cauxiliar = c_crear();

    while(!p_es_vacia(P)){

        elem_p = p_desapilar(P);
        posicion_cola = 1;

        while(!c_es_vacia(C)){

            elem_c = c_desencolar(C);

            if(elem_c->clave == elem_p->clave){

                if(l_es_vacia(L)){

                    struct posicion *actual = (struct posicion *) calloc(1, sizeof(struct posicion));

                    actual->posicion_c = posicion_cola;
                    actual->posicion_p = posicion_pila;

                    TipoElemento elem_L = te_crear_con_valor(elem_p->clave, actual);

                    l_agregar(L, elem_L);
                }

                else{

                    Iterador iter = iterador(L);
                    agregar = true;

                    while(hay_siguiente(iter)){

                        comprobador = siguiente(iter);

                        if(comprobador->clave == elem_p->clave){

                            comprobar = (struct posicion *) comprobador->valor;

                            if((comprobar->posicion_c == posicion_cola) || (comprobar->posicion_p == posicion_pila)){

                                agregar = false;
                                break;
                            }
                        }
                    }

                    free(iter);

                    if(agregar){

                        struct posicion *actual = (struct posicion *) calloc(1, sizeof(struct posicion));

                        actual->posicion_c = posicion_cola;
                        actual->posicion_p = posicion_pila;

                        TipoElemento elem_L = te_crear_con_valor(elem_p->clave, actual);

                        l_agregar(L, elem_L);
                    }
                }
            }

            c_encolar(cauxiliar, elem_c);

            posicion_cola++;
        }


        while(!c_es_vacia(cauxiliar)){

            elem_c = c_desencolar(cauxiliar);
            c_encolar(C, elem_c);
        }

        p_apilar(pauxiliar, elem_p);

        posicion_pila++;
    }

    while(!p_es_vacia(pauxiliar)){

        elem_p = p_desapilar(pauxiliar);
        p_apilar(P, elem_p);
    }

    free(cauxiliar);
    free(pauxiliar);

    return L;
}






void c_ej6_Mostrar_Resultado(Lista L){

    printf(" Contenido de la Lista: \n\n");

    if(l_es_vacia(L)){

        printf(" LISTA VACIA!!!!\n\n");

        return;
    }

    struct posicion *pos;
    TipoElemento elem_L;

    Iterador iter = iterador(L);

    while(hay_siguiente(iter)){

        elem_L = siguiente(iter);

        pos = (struct posicion *) elem_L->valor;

        printf("\t\t %d ----> posicion en la cola: %d    ; posicion en la pila: %d\n", elem_L->clave, pos->posicion_c, pos->posicion_p);
    }

    free(iter);
    printf("\n");
}

























// Ejercicio 7 .

void c_ej7_Carga_CM(Cola C){

    int cantidad, clave, cliente = C_EJ_Longuitud_Cola(C);
    bool pudo;

    printf("Ingrese la cantidad de clientes a agregar a la COLA (numero entre [1; 10]): ");
    cantidad = Ingresar_Entero_Positivo();

    while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

        printf(" Ingreso Invalido! Debe ingresar una cantidad de clientes entre [1; 10]!\n");
        printf(" Cuantos clientes agregaremos a la COLA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();
        fflush(stdin);
    }

    for(int i = 0; i < cantidad; i++){

        pudo = true;

        if(!c_es_llena(C)){

            do{

                printf("Ingrese el tiempo que tarda el tramite del cliente %d de esta COLA (Numero Entero Positivo >= 1): ", cliente + 1);
                clave = Ingresar_Entero_Positivo();

                if(clave < 1){

                    printf("Ingreso Invalido! Debe ingresar un tiempo >= 1 minuto!\n");
                }

            }
            while(clave < 1);

            TipoElemento nuevo = te_crear(clave);
            pudo = c_encolar(C, nuevo);
            cliente++;

            if(c_es_llena(C)){

                printf("La COLA se acaba de llenar! No se puede agregar mas clientes! Volveremos al MENU PRINCIPAL!\n");
                system("pause");
                system("cls");

                break;
            }

        }

        else{

            printf("La COLA ya esta llena! No se puede agregar mas clientes! Volveremos al MENU PRINCIPAL!\n");
            system("pause");
            system("cls");

            break;
        }
    }
}






void c_ej7_Carga_CA(Cola C){

    srand(time(NULL));

    int cantidad, clave;

    if(!c_es_llena(C)){

        printf(" Cuantos clientes agregaremos a la COLA? (Numero Entero entre [1; 10]): ");
        cantidad = Ingresar_Entero_Positivo();

        while(!Validar_Intervalo_Enteros(cantidad, 1, 10)){

            printf(" Ingreso Invalido! Debe ingresar una cantidad de clientes entre [1; 10]!\n");
            printf(" Cuantos clientes agregaremos a la COLA? (Numero Entero entre [1; 10]): ");
            cantidad = Ingresar_Entero_Positivo();
            fflush(stdin);
        }

        do{

            clave = rand() % 100 + 1;

            TipoElemento elem = te_crear(clave);
            c_encolar(C, elem);
            cantidad --;

        }
        while(cantidad > 0 && !c_es_llena(C));

        if(cantidad > 0 && c_es_llena(C)){

            printf(" Se lleno la COLA! Faltaron cargar %d clientes!\n", cantidad);
            system("pause");
            system("cls");
        }
    }

    else{

        printf(" La COLA ya esta llena por lo que no se le pueden cargar mas clientes! Volveremos al MENU PRINCIPAL!\n");
        system("pause");
        system("cls");
    }

}




void Simulacion(Cola C1, Cola C2, Cola C3){

    int cli_c1 = 0, cli_c2 = 0, cli_c3 = 0;
    int tiempo_atencion, invertido1, invertido2, invertido3;

    bool tiene1 = false, tiene2 = false, tiene3 = false;

    Cola copia1, copia2, copia3;

    TipoElemento cliente, sacar;

    if(c_es_vacia(C1) && c_es_vacia(C2) && c_es_vacia(C3)){

        printf(" Las COLAS no tienen clientes! carguelas antes de realizar el ejercicio!\n");

        return;
    }

    if(!c_es_vacia(C1)){

        copia1 = C_EJ_Copiar_Cola(C1);
        tiene1 = true;
    }

    if(!c_es_vacia(C2)){

        copia2 = C_EJ_Copiar_Cola(C2);
        tiene2 = true;
    }

    if(!c_es_vacia(C3)){

        copia3 = C_EJ_Copiar_Cola(C3);
        tiene3 = true;
    }

    printf(" Cuantos minutos invertiremos en la atencion de cada COLA? (numero entero >= 1): ");
    tiempo_atencion = Ingresar_Entero_Positivo();

    while(tiempo_atencion < 1){

        printf(" Ingreso Invalido! debe ingresar una cantidad de minutos >= 1!\n");
        printf(" Cuantos minutos invertiremos en la atencion de cada COLA? (numero entero >= 1): ");
        tiempo_atencion = Ingresar_Entero_Positivo();
        fflush(stdin);
    }


    do{

        invertido1 = tiempo_atencion;
        invertido2 = tiempo_atencion;
        invertido3 = tiempo_atencion;

        if(!c_es_vacia(C1)){

            do{

                cliente = c_recuperar(C1);

                if(invertido1 - cliente->clave > 0){

                    invertido1 -= cliente->clave;

                    sacar = c_desencolar(C1);
                    cli_c1 ++;

                    printf(" CLIENTE %d COLA 1 --> ATENCION COMPLETADA!\n", cli_c1);
                }

                else{

                    cliente->clave -= invertido1;
                    invertido1 = 0;
                }
            }
            while(invertido1 > 0 && !c_es_vacia(C1));
        }

        if(!c_es_vacia(C2)){

            do{

                cliente = c_recuperar(C2);

                if(invertido2 - cliente->clave > 0){

                    invertido2 -= cliente->clave;

                    sacar = c_desencolar(C2);
                    cli_c2 ++;

                    printf(" CLIENTE %d COLA 2 --> ATENCION COMPLETADA!\n", cli_c2);
                }

                else{

                    cliente->clave -= invertido2;
                    invertido2 = 0;
                }
            }
            while(invertido2 > 0 && !c_es_vacia(C2));
        }

        if(!c_es_vacia(C3)){

            do{

                cliente = c_recuperar(C3);

                if(invertido3 - cliente->clave > 0){

                    invertido3 -= cliente->clave;

                    sacar = c_desencolar(C3);
                    cli_c3 ++;

                    printf(" CLIENTE %d COLA 3 --> ATENCION COMPLETADA!\n", cli_c3);
                }

                else{

                    cliente->clave -= invertido3;
                    invertido3 = 0;
                }
            }
            while(invertido3 > 0 && !c_es_vacia(C3));
        }
    }
    while(!c_es_vacia(C1) || !c_es_vacia(C2) || !c_es_vacia(C3));

    if(tiene1){

        while(!c_es_vacia(copia1)){

            sacar = c_desencolar(copia1);
            c_encolar(C1, sacar);
        }
    }

    if(tiene2){

        while(!c_es_vacia(copia2)){

            sacar = c_desencolar(copia2);
            c_encolar(C2, sacar);
        }
    }

    if(tiene3){

        while(!c_es_vacia(copia3)){

            sacar = c_desencolar(copia3);
            c_encolar(C3, sacar);
        }
    }
}
