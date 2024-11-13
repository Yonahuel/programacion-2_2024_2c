#ifndef TIPO_ELEMENTO_H
#define TIPO_ELEMENTO_H

/*Registro definido para trabajar con memoria dinamica a traves de punteros. contiene una clave entera y un puntero generico que 
puede apuntar a cualquier tipo de dato*/
struct TipoElementoRep {
    int clave;  //valor entero
    void* valor;  //puntero generico
};

/*Crea un alias/nuevo tipo de dato, que puede referirse mas adelante a un puntero de 'TIPOELEMENTOREP' con 
solamente 'TIPOELEMENTO'*/
typedef struct TipoElementoRep *TipoElemento;

TipoElemento te_crear(int clave);
TipoElemento te_crear_con_valor(int clave, void* valor);

#endif // TIPO_ELEMENTO_H

