#ifndef TP5_ALGO2_ABB_H
#define TP5_ALGO2_ABB_H

#include "ABBNodo.h"
#include<iostream>

template <class T>

class ABB{

    private:
        // attributes
        ABBNodo<T>* raiz;

        // methods
        ABBNodo<T>* insertar(ABBNodo<T>* nodo, T dato);

        void imprimir_en_orden(ABBNodo<T> * nodo);

        ABBNodo<T>* buscar(ABBNodo<T>* nodo, T dato);

        T encontrar_min(ABBNodo<T>* nodo);

        T encontrar_max(ABBNodo<T>* nodo);

        T sucesor(ABBNodo<T>* nodo);

        T predecesor(ABBNodo<T>* nodo);

        ABBNodo<T>* borrar(ABBNodo<T>* nodo, T dato);

        void borrar_todo(ABBNodo<T>* nodo);

    public:

        //CONSTRUCTOR
        // POST: Inicializa un ABB vacio
        ABB();

        // POST: Agrega un nuevo nodo al ABB. Si es el árbol está vacío el nodo insertado será la raíz
        void insertar(T dato);

        // Prints all the dato stored in the BST, sorted from the
        // smallest value to the greatest value.
        void imprimir_en_orden();

        // POST: Busca al dato pasado por parametro en el ABB. Si el dato esta en el ABB devuelve TRUE, en caso contrario FALSE.
        bool buscar(T dato);

        // Devuelve el valor minimo que existe en el ABB
        T encontrar_min();

        // POST: Devuelve el valor maximo que existe en el ABB
        T encontrar_max();

        // POST: Devuelve el sucesor del dato pasado por parametro
        T sucesor(T dato);

        // POST: Devuelve el predecesor del dato pasado por parametro
        T predecesor(T dato);

        // POST: Borra el dato recibido por parametro del ABB
        void borrar(T dato);

        ABBNodo<T>* obtener_raiz();

        bool vacio();

        // POST: Borra todos los nodos del ABB
        void borrar_todo();

        ~ABB<T>();

    };

template <class T>
ABB<T>::ABB(){
    this->raiz = NULL;
}

template <class T>
ABBNodo<T>* ABB<T>::insertar(ABBNodo<T>* nodo, T dato) {
    if (nodo == NULL) {
        nodo = new ABBNodo<T>(dato);
    }
    else if (dato > nodo->obtener_dato()) {
        nodo->modificar_derecho(insertar(nodo->obtener_derecho(), dato), nodo);
    }
    else {
        nodo->modificar_derecho(insertar(nodo->obtener_izquierdo(), dato), nodo);
    }
    return nodo;
}

template <class T>
void ABB<T>::insertar(T dato){
    this->raiz = insertar(this->raiz, dato);
}

template <class T>
void ABB<T>::imprimir_en_orden(ABBNodo<T>* nodo){
    if (nodo != NULL){
        imprimir_en_orden(nodo->obtener_izquierdo());
        std::cout<<nodo->get_data()<<' ';
        imprimir_en_orden(nodo->obtener_izquierdo());
    }
}

template <class T>
void ABB<T>::imprimir_en_orden(){
    this->imprimir_in_order(this->raiz);
}

template <class T>
ABBNodo<T>* ABB<T>::buscar(ABBNodo<T>* nodo, T dato){
    if (nodo == NULL || nodo->obtener_dato() == dato)
        return nodo;

    if (dato > nodo->obtener_dato())
        return buscar(nodo->obtener_derecho(), dato);

    return buscar(nodo->obtener_izquierdo(), dato);
}

template <class T>
bool ABB<T>::buscar(T dato){
    ABBNodo<T>* resultado = buscar(this->raiz, dato);

    return resultado != NULL;
}

template <class T>
T ABB<T>::encontrar_min(ABBNodo<T>* nodo){
    if(nodo == NULL)
        return -1;
    else if(nodo->obtener_izquierdo() == NULL)
        return nodo->obtener_dato();
    else
        return encontrar_min(nodo->obtener_izquierdo());
}

template <class T>
T ABB<T>::encontrar_min(){
    return encontrar_min(this->raiz);
}

template <class T>
T ABB<T>::encontrar_max(ABBNodo<T>* nodo){
    if(nodo == NULL)
        return -1;
    else if(nodo->obtener_derecho() == NULL)
        return nodo->obtener_dato();
    else
        return encontrar_max(nodo->obtener_derecho());
}

template <class T>
T ABB<T>::encontrar_max(){
    return encontrar_max(this->raiz);
}

template <class T>
T ABB<T>::sucesor(ABBNodo<T>* nodo){
    if (nodo->obtener_derecho() != NULL){
        return encontrar_min(nodo->obtener_derecho());
    }
    ABBNodo<T>* sucesor = NULL;
    ABBNodo<T>* ancestro = this->raiz;
    while(ancestro != nodo) {
        if(nodo->obtener_dato() < ancestro->obtener_dato()) {
            sucesor = ancestro;
            ancestro = ancestro->obtener_izquierdo();
        }
        else
            ancestro = ancestro->obtener_derecho();
    }
    return sucesor->obtener_dato();
}

template <class T>
T ABB<T>::sucesor(T dato)
{
    ABBNodo<T>* dato_nodo = this->buscar(this->raiz, dato);
    // Return the key. If the key is not found or successor is not found, return -1
    if(dato_nodo == NULL)
        return -1;
    else
        return sucesor(dato_nodo);
}

template <class T>
T ABB<T>::predecesor(ABBNodo<T> * nodo){
    if (nodo->obtener_izquierdo() != NULL){
        return encontrar_max(nodo->obtener_izquierdo());
    }

    ABBNodo<T>* sucesor = NULL;
    ABBNodo<T>* ancestro = this->raiz;
    while(ancestro != nodo) {
        if(nodo->obtener_dato() > ancestro->obtener_dato()) {
            sucesor = ancestro; // so far this is the deepest nodo for which current nodo is in left
            ancestro = ancestro->obtener_derecho();
        }
        else
            ancestro = ancestro->obtener_izquierdo();
    }
    return sucesor->obtener_dato();
}

template <class T>
T ABB<T>::predecesor(T dato){
    ABBNodo<T> * dato_nodo = this->buscar(this->raiz, dato);
    if(dato_nodo == NULL)
        return -1;
    else
        return predecesor(dato_nodo);
}

template <class T>
ABBNodo<T> * ABB<T>::borrar(ABBNodo<T>* nodo, T dato){
    // The given nodo is not found in ABB
    if (nodo == NULL)
        return NULL;

    if (nodo->obtener_dato() == dato){
        if (nodo->es_hoja())
            delete nodo;
        else if (nodo->solo_hijo_derecho()){
            // The only child will be connected to the parent's of nodo directly
            nodo->obtener_derecho()->modificar_padre(nodo->obtener_padre());
            // Bypass nodo
            ABBNodo<T>* aux = nodo;
            nodo = nodo->obtener_derecho();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierdo()){
            // The only child will be connected to the parent's of nodo directly
            nodo->obtener_izquierdo()->modificar_padre(nodo->obtener_padre());
            // Bypass nodo
            ABBNodo<T>* aux = nodo;
            nodo = nodo->obtener_izquierdo();
            delete aux;
        }

            // The nodo has two children (left and right)
        else{
            // Find successor or predecessor to avoid quarrel
            T sucesor_dato = this->sucesor(dato);

            // Replace nodo's key with successor's key
            nodo->modificar_dato(sucesor_dato);

            // Delete the old successor's key
            nodo->modificar_derecho(borrar(nodo->obtener_derecho(), sucesor_dato));
        }
    }

    else if (nodo->get_data() < dato)
        nodo->modificar_derecho(borrar(nodo->obtener_derecho(), dato));
    else
        nodo->modificar_izquierdo(borrar(nodo->obtener_izquierdo(), dato));

    return nodo;
}

template <class T>
void ABB<T>::borrar(T dato){
    this->raiz = borrar(this->raiz, dato);
}

template <class T>
ABBNodo<T>* ABB<T>::obtener_raiz(){
    return this->raiz;
}

template <class T>
bool ABB<T>::vacio(){
    return this->raiz == NULL;
}


template <class T>
void ABB<T>::borrar_todo(ABBNodo<T>* nodo){
    if(nodo == NULL)
        return;
    this->borrar_todo(nodo->obtener_izquierdo());
    this->borrar_todo(nodo->obtener_derecho());
    delete nodo;
}

template <class T>
void ABB<T>::borrar_todo(){
    this->borrar_todo(this->raiz);
}

template <class T>
ABB<T>::~ABB<T>(){
    this->borrar_todo();
}

#endif //TP5_ALGO2_ABB_H
