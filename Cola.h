#ifndef TP5_ALGO2_COLA_H
#define TP5_ALGO2_COLA_H

# include "nodo.h"

template <typename T> // T sera el dato que guarden los nodos dentro de Cola (en nuestro caso seran los codigos IATA)
class Cola{
private:
    Nodo<T>* primero ; // Primer elemento de la cola
    Nodo<T>* ultimo ; // Ultimo elemento de la cola

public :
    // Constructor
    // PRE: -
    // POST: Inicializa una cola vacía, primero y ultimo apuntan a nulo
    Cola();

    // Destructor
    // PRE: Cola creada
    // POST: Libera todos los recursos de la cola
    ~ Cola();

    // PRE: Cola creada
    // POST: Devuelve TRUE si la cola no es vacia, esto equivale a que primero no este apuntando a null.
    // FALSE en caso contrario
    bool cola_vacia();

    // PRE: Cola creada
    // POST: Agrega un puntero de tipo T (dentro de un nodo) al final de la cola
    void encolar(T d);

    // PRE: Cola creada y no vacía
    // POST: Libera el nodo al que apunta primero
    T desencolar();
};

template <typename T>
Cola<T>::Cola(){
    primero = 0;
    ultimo = 0;
}

template <typename T>
Cola<T>::~Cola(){
    while (!(cola_vacia())){
        desencolar();
    }
}

template <typename T>
bool Cola<T>::cola_vacia(){
    return (primero == 0);
}

template <typename T>
void Cola<T>::encolar(T d){
    T* dato = new T(d);
    Nodo<T>* nodo = new Nodo<T>(dato);
    if(this->cola_vacia())
        primero = nodo;
    else
        ultimo->modificar_sig(nodo);
    ultimo = nodo;
}

template <typename T>
T Cola<T>::desencolar(){
    if(primero == ultimo)
        ultimo = 0;
    Nodo<T>* paux = primero;
    T aux = *(primero->obtener_dato());
    primero = paux->obtener_sig();
    delete paux;
    return aux;

}

#endif //TP5_ALGO2_COLA_H