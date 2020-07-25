#ifndef TP5_ALGO2_ABB_H
#define TP5_ALGO2_ABB_H

#include "ABBNodo.h"
#include<iostream>

template <class T, class C> // T para el dato, C para la clave
class ABB{

    private:
        // atributos
        ABBNodo<T,C>* raiz;

        // metodos
        ABBNodo<T,C>* insertar(ABBNodo<T,C>* nodo, T dato, C clave);
        void imprimir_en_orden(ABBNodo<T,C> * nodo);
        ABBNodo<T,C>* buscar(ABBNodo<T,C>* nodo, C clave);
        C encontrar_min(ABBNodo<T,C>* nodo);
        C encontrar_max(ABBNodo<T,C>* nodo);
        C sucesor(ABBNodo<T,C>* nodo);
        C predecesor(ABBNodo<T,C>* nodo);
        ABBNodo<T,C>* borrar(ABBNodo<T,C>* nodo, C clave);
        void borrar_todo(ABBNodo<T,C>* nodo);

    public:

        //CONSTRUCTOR
        // POST: Inicializa un ABB vacio
        ABB();

        // POST: Agrega un nuevo nodo al ABB. Si el árbol está vacío el nodo insertado será la raíz
        void insertar(T dato, C clave);

        // Imprime todas las claves del ABB, ordenadas desde el menor al mayor
        void imprimir_en_orden();

        // POST: Busca la clave pasado por parametro en el ABB. Si la clave esta en el ABB devuelve TRUE, en caso contrario FALSE.
        bool buscar(C Clave);

        // Devuelve la clave minima que existe en el ABB
        C encontrar_min();

        // POST: Devuelve la clave maxima que existe en el ABB
        C encontrar_max();

        // POST: Devuelve una clave que es el sucesor de la clave pasada por parametro
        C sucesor(C clave);

        // POST: Devuelve una clave que es el predecesor de la clave pasada por parametro
        C predecesor(C clave);

        // POST: Borra del ABB la clave pasada por parametro y su dato correspondiente
        void borrar(C clave);

        ABBNodo<T,C>* obtener_raiz();

        bool vacio();

        // POST: Borra todos los nodos del ABB
        void borrar_todo();

        ~ABB<T,C>();

    };

template <class T, class C>
ABB<T,C>::ABB(){
    this->raiz = NULL;
}

template <class T, class C>
ABBNodo<T,C>* ABB<T,C>::insertar(ABBNodo<T,C>* nodo, T dato, C clave){
    if (nodo == NULL){
        nodo = new ABBNodo<T,C>(dato, clave);
    }
    else if (dato > nodo->obtener_dato()){
        nodo->modificar_derecho(insertar(nodo->obtener_derecho(), dato, clave), nodo);
    }
    else{
        nodo->modificar_izquierdo(insertar(nodo->obtener_izquierdo(), dato, clave), nodo);
    }
    return nodo;
}

template <class T, class C>
void ABB<T,C>::insertar(T dato, C clave){
    this->raiz = insertar(this->raiz, dato, clave);
}

template <class T, class C>
void ABB<T,C>::imprimir_en_orden(ABBNodo<T,C>* nodo){
    if (nodo != NULL){
        imprimir_en_orden(nodo->obtener_izquierdo());
        std::cout << nodo->obtener_clave() <<' ';
        imprimir_en_orden(nodo->obtener_derecho());
    }
}

template <class T, class C>
void ABB<T,C>::imprimir_en_orden(){
    this->imprimir_in_order(this->raiz);
}

template <class T, class C>
ABBNodo<T,C>* ABB<T,C>::buscar(ABBNodo<T,C>* nodo, C clave){
    if (nodo == NULL || nodo->obtener_clave() == clave)
        return nodo;

    if (clave > nodo->obtener_clave())
        return buscar(nodo->obtener_derecho(), clave);

    return buscar(nodo->obtener_izquierdo(), clave);
}

template <class T, class C>
bool ABB<T,C>::buscar(C clave){
    ABBNodo<T,C>* resultado = buscar(this->raiz, clave);

    return resultado != NULL;
}

template <class T, class C>
C ABB<T,C>::encontrar_min(ABBNodo<T,C>* nodo){
    if(nodo == NULL)
        return -1;
    else if(nodo->obtener_izquierdo() == NULL)
        return nodo->obtener_clave();
    else
        return encontrar_min(nodo->obtener_izquierdo());
}

template <class T, class C>
C ABB<T,C>::encontrar_min(){
    return encontrar_min(this->raiz);
}

template <class T, class C>
C ABB<T,C>::encontrar_max(ABBNodo<T,C>* nodo){
    if(nodo == NULL)
        return -1;
    else if(nodo->obtener_derecho() == NULL)
        return nodo->obtener_clave();
    else
        return encontrar_max(nodo->obtener_derecho());
}

template <class T, class C>
C ABB<T,C>::encontrar_max(){
    return encontrar_max(this->raiz);
}

template <class T, class C>
C ABB<T,C>::sucesor(ABBNodo<T,C>* nodo){
    if (nodo->obtener_derecho() != NULL){
        return encontrar_min(nodo->obtener_derecho());
    }
    ABBNodo<T,C>* sucesor = NULL;
    ABBNodo<T,C>* ancestro = this->raiz;
    while(ancestro != nodo){
        if(nodo->obtener_clave() < ancestro->obtener_clave()){
            sucesor = ancestro;
            ancestro = ancestro->obtener_izquierdo();
        }
        else
            ancestro = ancestro->obtener_derecho();
    }
    return sucesor->obtener_clave();
}

template <class T, class C>
C ABB<T,C>::sucesor(C clave){
    ABBNodo<T,C>* clave_nodo = this->buscar(this->raiz, clave);
    // Devuelve la clave. Si no se encuentra la clave o no se encuentra el sucesor, devuelva -1
    if(clave_nodo == NULL)
        return -1;
    else
        return sucesor(clave_nodo);
}

template <class T, class C>
C ABB<T,C>::predecesor(ABBNodo<T,C> * nodo){
    if (nodo->obtener_izquierdo() != NULL){
        return encontrar_max(nodo->obtener_izquierdo());
    }

    ABBNodo<T,C>* sucesor = NULL;
    ABBNodo<T,C>* ancestro = this->raiz;
    while(ancestro != nodo){
        if(nodo->obtener_clave() > ancestro->obtener_clave()){
            sucesor = ancestro;
            ancestro = ancestro->obtener_derecho();
        }
        else
            ancestro = ancestro->obtener_izquierdo();
    }
    return sucesor->obtener_clave();
}

template <class T, class C>
C ABB<T,C>::predecesor(C clave){
    ABBNodo<T,C> * clave_nodo = this->buscar(this->raiz, clave);
    if(clave_nodo == NULL)
        return -1;
    else
        return predecesor(clave_nodo);
}

template <class T, class C>
ABBNodo<T,C> * ABB<T,C>::borrar(ABBNodo<T,C>* nodo, C clave){
    if (nodo == NULL) // El nodo no se encuentra en el ABB
        return NULL;

    if (nodo->obtener_clave() == clave){
        if (nodo->es_hoja()) {
            delete nodo->obtener_dato();
            delete nodo;
        }
        else if (nodo->solo_hijo_derecho()){
            nodo->obtener_derecho()->modificar_padre(nodo->obtener_padre());
            ABBNodo<T,C>* aux = nodo;
            nodo = nodo->obtener_derecho();
            delete aux->obtener_dato();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierdo()){
            nodo->obtener_izquierdo()->modificar_padre(nodo->obtener_padre());
            ABBNodo<T,C>* aux = nodo;
            nodo = nodo->obtener_izquierdo();
            delete aux->obtener_dato();
            delete aux;
        }
        //El nodo tiene dos hijos (izquierdo y derecho)
        else{
            // Encuentra sucesora o predecesora para evitar disputas
            C sucesor_clave = this->sucesor(clave);

            //Copiar los datos del nodo sucesor a los del nodo actual
            nodo = buscar(nodo, sucesor_clave);

            //Elimina el antiguo nodo del sucesor
            nodo->modificar_derecho(borrar(nodo->obtener_derecho(), sucesor_clave));
        }
    }

    else if (nodo->obtener_clave() < clave)
        nodo->modificar_derecho(borrar(nodo->obtener_derecho(), clave));
    else
        nodo->modificar_izquierdo(borrar(nodo->obtener_izquierdo(), clave));

    return nodo;
}

template <class T, class C>
void ABB<T,C>::borrar(C clave){
    this->raiz = borrar(this->raiz, clave);
}

template <class T, class C>
ABBNodo<T,C>* ABB<T,C>::obtener_raiz(){
    return this->raiz;
}

template <class T, class C>
bool ABB<T,C>::vacio(){
    return this->raiz == NULL;
}


template <class T, class C>
void ABB<T,C>::borrar_todo(ABBNodo<T,C>* nodo){
    if(nodo == NULL)
        return;
    this->borrar_todo(nodo->obtener_izquierdo());
    this->borrar_todo(nodo->obtener_derecho());
    delete nodo->obtener_dato();
    delete nodo;
}

template <class T, class C>
void ABB<T,C>::borrar_todo(){
    this->borrar_todo(this->raiz);
}

template <class T, class C>
ABB<T,C>::~ABB<T,C>(){
    this->borrar_todo();
}

#endif //TP5_ALGO2_ABB_H
