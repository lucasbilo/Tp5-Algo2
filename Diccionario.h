#ifndef TP5_ALGO2_Diccionario_H
#define TP5_ALGO2_Diccionario_H

#include "NodoDic.h"
#include "Cola.h"
#include<iostream>

template <class T> // T para el dato
class Diccionario{

private:
    // ATRIBUTOS:
    Nodo_dic<T>* raiz;

    // METODOS:

    // POST: Agrega un nuevo nodo al Diccionario. Si el árbol está vacío el nodo insertado será la raíz
    Nodo_dic<T>* insertar(Nodo_dic<T>* nodo, T* dato, std::string clave);
    
    void setear_niveles(Nodo_dic<T>* nodo, int nivel);

    // PRE : (MUY IMPORTANTE) El dato que contiene el nodo tiene que tener un metodo llamado mostrar_datos()
    // POST: Imprime todas las claves del Diccionario, ordenadas desde el menor al mayor
    void imprimir_en_orden(Nodo_dic<T> * nodo);

    // POST: Recorre recursivamente el Diccionario por niveles(anchura) y va imprimiendo las claves del mismo.
    void imprimir_en_anchura(Nodo_dic<T> * nodo);

    // POST: Busca la clave recibida por parametro en el Diccionario.
    // Si la clave esta en el Diccionario, devuelve un puntero al Nodo de la clave. En caso de que no este devuelve un nodo a NULL
    Nodo_dic<T>* buscar(Nodo_dic<T>* nodo, std::string clave);

    // POST: Devuelve la clave minima que existe en el Diccionario
    std::string encontrar_min(Nodo_dic<T>* nodo);

    // POST: Devuelve la clave maxima que existe en el Diccionario
    std::string encontrar_max(Nodo_dic<T>* nodo);

    // POST: Devuelve una clave de tipo string que es el sucesor del nodo recibido por parametro
    std::string sucesor(Nodo_dic<T>* nodo);

    // POST: Devuelve una clave de tipo string que es el predecesor del nodo recibido por parametro
    std::string predecesor(Nodo_dic<T>* nodo);

    /* POST: Devuelve un nodo, este puede ser:
    1) Si el nodo recibido por parametro apunta a NULL, se devuelve NULL
    2) Si el nodo recibido por parametro solo tiene hijo derecho, elimina al nodo y  devuelve al hijo derecho
    3) Si el nodo recibido por parametro solo tiene hijo izquierdo, elimina al nodo y devuelve al hijo izquierdo
    4) Si el nodo recibido por parametro tiene 2 hijos (izquierdo y derecho), se elimina al nodo y se devuelve el sucesor */
    Nodo_dic<T>* borrar(Nodo_dic<T>* nodo, std::string clave);

    // POST: Borra todos los nodos del Diccionario
    void borrar_todo(Nodo_dic<T>* nodo);

public:

    //CONSTRUCTOR
    // POST: Inicializa un Diccionario. Raiz apunta a NULL
    Diccionario();

    //DESTRUCTOR
    //POST: Elimina la memoria pedida para cada nodo.
    ~Diccionario<T>();

    //POST: Llama al metodo privado insertar(), le pasa como parametros los parametros que este metodo recibio
    void insertar(std::string clave, T* dato);
    

    // POST: Llama al metodo privado imprimir_en_orden(), le pasa como parametro la raiz
    void imprimir_en_orden();

    // POST: Llama al metodo privado imprimir_en_anchura(), le pasa como parametro la raiz
    void imprimir_en_anchura();

    // POST: Busca la clave pasado por parametro en el Diccionario (llama al metodo privado buscar()).
    // Si la clave esta en el Diccionario devuelve TRUE, en caso contrario FALSE.
    bool buscar(std::string Clave);

    // POST: Devuelve la clave minima que existe en el Diccionario
    std::string encontrar_min();

    // POST: Devuelve la clave maximaque existe en el Diccionario
    std::string encontrar_max();

    // POST: Devuelve la clave del sucesor de la clave pasada por parametro. En caso de que no se encuentre, se devuelve 'F'
    std::string sucesor(std::string clave);

    // POST: Devuelve la clave del predecesor de la clave pasada por parametro. En caso de que no se encuentre, se devuelve 'F'
    std::string predecesor(std::string clave);

    // POST: Borra del Diccionario la clave pasada por parametro y su dato correspondiente
    void borrar(std::string clave);

    //POST: Si la clave no esta en el Diccionario, devuelve NULL, sino devuelve un puntero al dato almacenado.
    T* consultar(std::string clave);

    // POST: Llama al metodo privado borrar_todo() y le pasa como parametro la raiz
    void borrar_todo();

    // POST: Devuelve la raiz del Diccionario
    Nodo_dic<T>* obtener_raiz();

    // POST: Si raiz apunta a NULL se devuelve TRUE, en caso contrario se devuelve FALSE
    bool vacio();

};

template <class T>
Diccionario<T>::Diccionario(){
    this->raiz = NULL;
}

template <class T>
Nodo_dic<T>* Diccionario<T>::insertar(Nodo_dic<T>* nodo, T* dato, std::string clave){
    if (nodo == NULL){ //raiz es nula
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
void Diccionario<T>::setear_niveles(Nodo_dic<T>* nodo, int nivel)
{
    if (nodo != NULL)
    {
        setear_niveles(nodo -> obtener_izquierdo(), nivel + 1);
        nodo -> setear_nivel(nivel);
        setear_niveles(nodo -> obtener_derecho(), nivel + 1);
    }
}

template <class T>
void Diccionario<T>::imprimir_en_orden(Nodo_dic<T>* nodo){
    if(nodo != NULL){
        imprimir_en_orden(nodo->obtener_izquierdo());
        nodo->obtener_dato()->mostrar_datos();
        imprimir_en_orden(nodo->obtener_derecho());
    }
}

template <class T>
void Diccionario<T>::imprimir_en_orden(){
    this->imprimir_en_orden(this->raiz);
}

template <class T>
void Diccionario<T>::imprimir_en_anchura(Nodo_dic<T>* nodo){
    Cola<Nodo_dic<T>*>* cola = new Cola<Nodo_dic<T>*>;
    Nodo_dic<T>*  aux;
    cola->encolar(nodo);
    int nivel_actual;
    int nivel_anterior = 1;
    setear_niveles(nodo, 1); //setea los niveles de cada nodo
    std::cout << "Nivel " << nivel_anterior << ": ";
    while(!cola->cola_vacia()){
        aux = cola->desencolar();
        nivel_actual = aux -> obtener_nivel();
        
        if (nivel_anterior != nivel_actual)
        {
            std::cout << std::endl;
            std::cout << "Nivel " << nivel_actual << ": ";
            nivel_anterior = nivel_actual;
        }
        
        std::cout << aux->obtener_clave() << " ";
        
        if(aux->obtener_izquierdo() != NULL)
        {
            cola->encolar(aux->obtener_izquierdo());
        }
        if(aux->obtener_derecho() != NULL)
        {
            cola->encolar(aux->obtener_derecho());
        }

    }
    delete cola;

}


template <class T>
void Diccionario<T>::imprimir_en_anchura(){
    if(this->raiz)
        this->imprimir_en_anchura(this->raiz);
    else
        std::cout << "No hay datos en el diccionario. " << std::endl;
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
std::string Diccionario<T>::encontrar_min(Nodo_dic<T>* nodo){
    if(nodo == NULL)
        return "\0";
    else if(nodo->obtener_izquierdo() == NULL)
        return nodo->obtener_clave();
    else
        return encontrar_min(nodo->obtener_izquierdo());
}

template <class T>
std::string Diccionario<T>::encontrar_min(){
    return encontrar_min(this->raiz);
}

template <class T>
std::string Diccionario<T>::encontrar_max(Nodo_dic<T>* nodo){
    if(nodo == NULL)
        return "\0";
    else if(nodo->obtener_derecho() == NULL)
        return nodo->obtener_clave();
    else
        return encontrar_max(nodo->obtener_derecho());
}

template <class T>
std::string Diccionario<T>::encontrar_max(){
    return encontrar_max(this->raiz);
}

template <class T>
std::string Diccionario<T>::sucesor(Nodo_dic<T>* nodo){
    if (nodo->obtener_derecho() != NULL)
        return encontrar_min(nodo->obtener_derecho());

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
    if(sucesor != NULL)
        return sucesor->obtener_clave();
    return "\0";
}

template <class T>
std::string Diccionario<T>::sucesor(std::string clave){
    Nodo_dic<T>* nodo_clave = this->buscar(this->raiz, clave);
    if(nodo_clave == NULL)
        return "\0";
    else
        return sucesor(nodo_clave);
}

template <class T>
std::string Diccionario<T>::predecesor(Nodo_dic<T> * nodo){
    if (nodo->obtener_izquierdo() != NULL){
        return encontrar_max(nodo->obtener_izquierdo());
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
    return sucesor->obtener_clave();
}

template <class T>
std::string Diccionario<T>::predecesor(std::string clave){
    Nodo_dic<T> * clave_nodo = this->buscar(this->raiz, clave);
    if(clave_nodo == NULL)
        return "\0";
    else
        return predecesor(clave_nodo);
}

template <class T>
Nodo_dic<T> * Diccionario<T>::borrar(Nodo_dic<T>* nodo, std::string clave){
    if(nodo == NULL) // El nodo no se encuentra en el Diccionario
        return NULL;

    if(nodo->obtener_clave() == clave){
        if(nodo->es_hoja()){
            Nodo_dic<T>* aux = nodo;
            nodo = NULL;
            delete aux;
        }
        else if(nodo->solo_hijo_derecho()){
            nodo->obtener_derecho()->modificar_padre(nodo->obtener_padre());
            Nodo_dic<T>* aux = nodo;
            nodo = nodo->obtener_derecho();
            delete aux;
        }
        else if(nodo->solo_hijo_izquierdo()){
            nodo->obtener_izquierdo()->modificar_padre(nodo->obtener_padre());
            Nodo_dic<T>* aux = nodo;
            nodo = nodo->obtener_izquierdo();
            delete aux;
        }
            //El nodo tiene dos hijos (izquierdo y derecho)
        else{
            // Encuentra sucesora o predecesora para evitar disputas
            std::string sucesor_clave = this->sucesor(nodo);
            Nodo_dic<T>* sucesor = buscar(nodo, sucesor_clave);
            T* aux = nodo->obtener_dato();

	    //Copiar los datos del nodo sucesor a los del nodo actual
            nodo->modificar_clave(sucesor->obtener_clave());
            nodo->modificar_dato(sucesor->obtener_dato());
            sucesor->modificar_dato(aux);
            
            // Borro el nodo viejo del sucesor
            nodo->modificar_derecho(borrar(nodo->obtener_derecho(), sucesor_clave));
        }
    }

    else if(nodo->obtener_clave() < clave)
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
