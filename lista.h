#ifndef TP4_ALGO2_LISTA_H
#define TP4_ALGO2_LISTA_H

# include <iostream>
# include "nodo.h"

template < typename Dato >
class Lista{

private:
    Nodo<Dato>* primero; // Primer elemento de la lista
    unsigned tam; // Tamaño de la lista

public:
    // Constructor
    // PRE: Ninguna
    // POST: construye una lista vacía
    // primero apunta a nulo y tam = 0
    Lista();

    // Destructor
    // PRE: Lista creada
    // POST: Libera todos los recursos de la lista
    ~Lista();

    // PRE: lista creada y d puntero que apunta a memoria dinamica.
    // POST: agrega un dato dentro de un nodo al principio
    // - modifica el primero
    // - tam se incrementa en 1
    void insertar(Dato* d);

    // PRE: Lista creada
    // POST: devuelve el tamaño de la lista (cantidad de nodos)
    unsigned obtener_tam();

    // PRE: - lista creada y no vacía
    // - 0 < pos <= tam
    // POST: devuelve un puntero al dato que está en la posición pos (se toma 1 como el primero)
    Dato* obtener_dato(unsigned pos);

    // PRE: Lista creada
    // POST: TRUE si es vacia (tam == 0), False en caso contrario
    bool lista_vacia();

    // PRE: - lista creada y no vacía
    // - 0 < pos <= tam
    // POST: libera el nodo que está en la posición pos (se toma 1 como el primero)
    void eliminar_dato(unsigned pos);

    //POST: Copia los datos del puntero recibido en la lista.

    void copiar(Lista<Dato>*);

};

//Constructor
template < typename Dato >
Lista<Dato>::Lista(){
    primero = 0;
    tam = 0;
}

//Destructor
template < typename Dato >
Lista<Dato>::~Lista(){
    while (!this->lista_vacia()){
        this->eliminar_dato(1);
    }
}


template < typename Dato >
bool Lista<Dato>::lista_vacia(){
    return (tam == 0);
}

template < typename Dato >
void Lista<Dato>::insertar(Dato* d){
    Nodo<Dato>* nuevo = new Nodo<Dato>(d);
    if (!(this->lista_vacia())){
        nuevo->modificar_sig(primero);
    }
    primero = nuevo;
    tam++;
}

template < typename Dato >
Dato* Lista<Dato>::obtener_dato(unsigned pos){
    Nodo<Dato>* paux = primero;
    unsigned i = 1;
    while (i < pos && paux->obtener_sig()){
        paux = paux->obtener_sig();
        i++;
    }
    return paux->obtener_dato();
}

template < typename Dato >
unsigned Lista<Dato>::obtener_tam(){
    return tam;
}

template < typename Dato >
void Lista<Dato>::eliminar_dato(unsigned pos){
    Nodo<Dato>* aux = primero;
    if (!lista_vacia()){
        if (pos == 1){
            primero = primero->obtener_sig();
        }
        else{
            for (unsigned cont = 0; (cont < pos-1 && aux->obtener_sig()); cont++)
                aux = aux->obtener_sig();
            aux->modificar_sig(aux->obtener_sig());
        }
        Nodo<Dato>* borrar = aux;
        delete borrar;
        tam--;
    }
}

template < typename Dato >
void Lista<Dato>::copiar(Lista<Dato>* lista){
    for(unsigned i = 1; i <= lista->obtener_tam(); i++){
        Dato* d = new Dato;
        *d = *(lista->obtener_dato(i));
        insertar(d);
    }
}



#endif //TP4_ALGO2_LISTA_H