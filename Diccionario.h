#ifndef TP5_ALGO2_Diccionario_H
#define TP5_ALGO2_Diccionario_H

#include "NodoDic.h"
#include<iostream>

template <class T> // T para el dato
class Diccionario{

    private:
        // atributos
        Nodo_dic<T>* raiz;

        // metodos
        Nodo_dic<T>* insertar(Nodo_dic<T>* nodo, T* dato, std::string clave);
        void imprimir_en_orden(Nodo_dic<T> * nodo);
        Nodo_dic<T>* buscar(Nodo_dic<T>* nodo, std::string clave);
        std::string encontrar_min(Nodo_dic<T>* nodo, T* &dato);
        std::string encontrar_max(Nodo_dic<T>* nodo, T* &dato);
        std::string sucesor(Nodo_dic<T>* nodo, T* &dato);
        std::string predecesor(Nodo_dic<T>* nodo, T* &dato);
        Nodo_dic<T>* borrar(Nodo_dic<T>* nodo, std::string clave);
        void borrar_todo(Nodo_dic<T>* nodo);

    public:

        //CONSTRUCTOR
        // POST: Inicializa un Diccionario vacio
        Diccionario();

        //DESTRUCTOR
        //POST: Elimina la memoria pedida para cada nodo.
        ~Diccionario<T>();

        // POST: Agrega un nuevo nodo al Diccionario. Si el árbol está vacío el nodo insertado será la raíz
        void insertar(std::string clave, T* dato);

        // Imprime todas las claves del Diccionario, ordenadas desde el menor al mayor
        void imprimir_en_orden();

        // POST: Busca la clave pasado por parametro en el Diccionario. Si la clave esta en el Diccionario devuelve TRUE, en caso contrario FALSE.
        bool buscar(std::string Clave);

        //POST: Si la clave no esta en el Diccionario, devuelve NULL, sino devuelve un puntero al dato almacenado.
        T* consultar(std::string clave);

        // Devuelve la clave minima que existe en el Diccionario y remplaza dato por un puntero al dato de la clave
        std::string encontrar_min(T* &dato);

        // POST: Devuelve la clave maxima que existe en el Diccionario y remplaza dato por un puntero al dato de la clave
        std::string encontrar_max(T* &dato);

        // POST: Devuelve una clave que es el sucesor de la clave pasada por parametro y remplaza dato por un puntero al dato de la clave
        std::string sucesor(std::string clave, T* &dato);

        // POST: Devuelve una clave que es el predecesor de la clave pasada por parametro y remplaza dato por un puntero al dato de la clave
        std::string predecesor(std::string clave, T* &dato);

        // POST: Borra del Diccionario la clave pasada por parametro y su dato correspondiente
        void borrar(std::string clave);

        Nodo_dic<T>* obtener_raiz();

        bool vacio();

        // POST: Borra todos los nodos del Diccionario
        void borrar_todo();

    };

template <class T>
Diccionario<T>::Diccionario(){
    this->raiz = NULL;
}

template <class T>
Nodo_dic<T>* Diccionario<T>::insertar(Nodo_dic<T>* nodo, T* dato, std::string clave){
    if (nodo == NULL){
        nodo = new Nodo_dic<T>(dato, clave);
    }
    else if (clave > nodo->obtener_clave()){
        nodo->modificar_derecho(insertar(nodo->obtener_derecho(), dato, clave), nodo);
    }
    else{
        nodo->modificar_izquierdo(insertar(nodo->obtener_izquierdo(), dato, clave), nodo);
    }
    return nodo;
}

template <class T>
void Diccionario<T>::insertar(std::string clave, T* dato){
    this->raiz = insertar(this->raiz, dato, clave);
}

template <class T>
void Diccionario<T>::imprimir_en_orden(Nodo_dic<T>* nodo){
    if (nodo != NULL){
        imprimir_en_orden(nodo->obtener_izquierdo());
        std::cout << nodo->obtener_clave() <<' ';
        imprimir_en_orden(nodo->obtener_derecho());
    }
}

template <class T>
void Diccionario<T>::imprimir_en_orden(){
    this->imprimir_en_orden(this->raiz);
}

template <class T>
Nodo_dic<T>* Diccionario<T>::buscar(Nodo_dic<T>* nodo, std::string clave){
    if (nodo == NULL || nodo->obtener_clave() == clave)
        return nodo;

    if (clave > nodo->obtener_clave())
        return buscar(nodo->obtener_derecho(), clave);

    return buscar(nodo->obtener_izquierdo(), clave);
}

template <class T>
bool Diccionario<T>::buscar(std::string clave){
    Nodo_dic<T>* resultado = buscar(this->raiz, clave);

    return resultado != NULL;
}

template <class T>
std::string Diccionario<T>::encontrar_min(Nodo_dic<T>* nodo, T* &dato){
    if(nodo == NULL)
        return "\0";
    else if(nodo->obtener_izquierdo() == NULL){
        dato = nodo->obtener_dato();
        return nodo->obtener_clave();
    }
    else
        return encontrar_min(nodo->obtener_izquierdo(), dato);
}

template <class T>
std::string Diccionario<T>::encontrar_min(T* &dato){
    return encontrar_min(this->raiz, dato);
}

template <class T>
std::string Diccionario<T>::encontrar_max(Nodo_dic<T>* nodo, T* &dato){
    if(nodo == NULL)
        return "\0";
    else if(nodo->obtener_derecho() == NULL){
        dato = nodo->obtener_dato();
        return nodo->obtener_clave();
    }
    else
        return encontrar_max(nodo->obtener_derecho(), dato);
}

template <class T>
std::string Diccionario<T>::encontrar_max(T* &dato){
    return encontrar_max(this->raiz, dato);
}

template <class T>
std::string Diccionario<T>::sucesor(Nodo_dic<T>* nodo, T* &dato){
    if (nodo->obtener_derecho() != NULL){
        return encontrar_min(nodo->obtener_derecho(), dato);
    }
    Nodo_dic<T>* sucesor = NULL;
    Nodo_dic<T>* ancestro = this->raiz;
    while(ancestro != nodo){
        if(nodo->obtener_clave() < ancestro->obtener_clave()){
            sucesor = ancestro;
            ancestro = ancestro->obtener_izquierdo();
        }
        else
            ancestro = ancestro->obtener_derecho();
    }
    dato = sucesor->obtener_dato();
    return sucesor->obtener_clave();
}

template <class T>
std::string Diccionario<T>::sucesor(std::string clave, T* &dato){
    Nodo_dic<T>* clave_nodo = this->buscar(this->raiz, clave);
    // Devuelve la clave. Si no se encuentra la clave o no se encuentra el sucesor, devuelva -1
    if(clave_nodo == NULL){
        dato = NULL;
        return "\0";
    }
    else
        return sucesor(clave_nodo, dato);
}

template <class T>
std::string Diccionario<T>::predecesor(Nodo_dic<T> * nodo, T* &dato){
    if (nodo->obtener_izquierdo() != NULL){
        return encontrar_max(nodo->obtener_izquierdo(), dato);
    }
    Nodo_dic<T>* sucesor = NULL;
    Nodo_dic<T>* ancestro = this->raiz;
    while(ancestro != nodo){
        if(nodo->obtener_clave() > ancestro->obtener_clave()){
            sucesor = ancestro;
            ancestro = ancestro->obtener_derecho();
        }
        else
            ancestro = ancestro->obtener_izquierdo();
    }
    dato = sucesor->obtener_dato();
    return sucesor->obtener_clave();
}

template <class T>
std::string Diccionario<T>::predecesor(std::string clave, T* &dato){
    Nodo_dic<T> * clave_nodo = this->buscar(this->raiz, clave);
    if(clave_nodo == NULL){
        dato = NULL;
        return "\0";
    }
    else
        return predecesor(clave_nodo, dato);
}

template <class T>
Nodo_dic<T> * Diccionario<T>::borrar(Nodo_dic<T>* nodo, std::string clave){
    if (nodo == NULL) // El nodo no se encuentra en el Diccionario
        return NULL;

    if (nodo->obtener_clave() == clave){
        if (nodo->es_hoja()) {
            delete nodo;
        }
        else if (nodo->solo_hijo_derecho()){
            nodo->obtener_derecho()->modificar_padre(nodo->obtener_padre());
            Nodo_dic<T>* aux = nodo;
            nodo = nodo->obtener_derecho();
            delete aux;
        }
        else if (nodo->solo_hijo_izquierdo()){
            nodo->obtener_izquierdo()->modificar_padre(nodo->obtener_padre());
            Nodo_dic<T>* aux = nodo;
            nodo = nodo->obtener_izquierdo();
            delete aux;
        }
        //El nodo tiene dos hijos (izquierdo y derecho)
        else{
            // Encuentra sucesora o predecesora para evitar disputas
            std::string sucesor_clave = this->sucesor(clave);

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

template <class T>
void Diccionario<T>::borrar(std::string clave){
    this->raiz = borrar(this->raiz, clave);
}

template <class T>
Nodo_dic<T>* Diccionario<T>::obtener_raiz(){
    return this->raiz;
}

template <class T>
bool Diccionario<T>::vacio(){
    return this->raiz == NULL;
}

template <class T>
T* Diccionario<T>::consultar(std::string clave){
    Nodo_dic<T>* resultado = buscar(this->raiz, clave);
    if(resultado == NULL)
        return NULL;
    return resultado->obtener_dato();
}


template <class T>
void Diccionario<T>::borrar_todo(Nodo_dic<T>* nodo){
    if(nodo == NULL)
        return;
    this->borrar_todo(nodo->obtener_izquierdo());
    this->borrar_todo(nodo->obtener_derecho());
    delete nodo;
}

template <class T>
void Diccionario<T>::borrar_todo(){
    this->borrar_todo(this->raiz);
}

template <class T>
Diccionario<T>::~Diccionario<T>(){
    this->borrar_todo();
}

#endif //TP5_ALGO2_Diccionario_H
