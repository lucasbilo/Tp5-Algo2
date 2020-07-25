#ifndef TP5_ALGO2_ABBNODO_H
#define TP5_ALGO2_ABBNODO_H

#include <cstddef>

template <class T, class C> // T para el dato, C para la clave
class ABBNodo{

    private:
        T* dato;
        C clave;
        ABBNodo<T,C>* izquierdo; // Hijo izquierdo
        ABBNodo<T,C>* derecho; //Hijo derecho
        ABBNodo<T,C>* padre;

    public:
        //Constructor
        // POST: Se inicializa un ABBNodo con el atributo dato igual al dato recibido por parametro.
        // Los demas atributos apuntan a NULL
        ABBNodo(T* dato, C clave);

        //Destructor
        //POST: Elimina la memoria a la que apunta dato.
        ~ABBNodo();

        //POST: Devuelve un dato de tipo C que es el atributo clave
        C obtener_clave();

        //POST: Devuelve un dato de tipo C que es el atributo dato
        T* obtener_dato();

        // POST: Modifica al atributo dato, por el dato que se recibe como parametro
        void modificar_dato(T* dato);

        // POST: Modifica 2 atributos, derecho y padre.
        // derecho = derecho(parametro)
        // padre = padre(parametro)
        void modificar_derecho(ABBNodo<T,C>* derecho, ABBNodo<T,C>* padre);

        // POST: Modifica 2 atributos, izquierdo y padre.
        // izquierdo = izquierdo(parametro)
        // padre = padre(parametro)
        void modificar_izquierdo(ABBNodo<T,C>* izquierdo, ABBNodo<T,C>* padre);

        // POST: Modifica el atributo derecho:
        // // derecho = derecho(parametro)
        void modificar_derecho(ABBNodo<T,C>* derecho);

        // POST: Modifica el atributo izquierdo:
        // izquierdo = izquierdo(parametro)
        void modificar_izquierdo(ABBNodo<T,C>* izquierdo);

        // POST: Modifica el atributo padre:
        // padre = padre(parametro)
        void modificar_padre(ABBNodo<T,C>* padre);

        //POST: Devuelve el atributo derecho
        ABBNodo<T,C>* obtener_derecho();

        //POST: Devuelve el atributo izquierdo
        ABBNodo<T,C>* obtener_izquierdo();

        //POST: Devuelve el atributo padre
        ABBNodo<T,C>* obtener_padre();

        // POST: Unicamente devuelve true si se verifica:
        // izquierdo == NULL y derecho == NULL
        bool es_hoja();

        // POST: Unicamente devuelve true si se verifica:
        // izquierdo == NULL y derecho != NULL
        bool solo_hijo_derecho();

        // POST: Unicamente devuelve true si se verifica:
        // izquierdo != NULL y derecho == NULL
        bool solo_hijo_izquierdo();
};

template <class T, class C>
ABBNodo<T,C>::ABBNodo(T* dato, C clave){
    this->clave = clave;
    this->dato = dato;
    this->izquierdo = NULL;
    this->derecho = NULL;
    this->padre = NULL;
}


template <class T, class C>
ABBNodo<T, C>::~ABBNodo(){
    if( dato != NULL)
        delete dato;
}

template <class T, class C>
C ABBNodo<T,C>::obtener_clave(){
    return this->clave;
}

template <class T, class C>
T* ABBNodo<T,C>::obtener_dato(){
    return this->dato;
}

template <class T, class C>
void ABBNodo<T,C>::modificar_derecho(ABBNodo<T,C>* derecho, ABBNodo<T,C>* padre){
    this->derecho = derecho;
    this->padre = padre;
}

template <class T, class C>
void ABBNodo<T,C>::modificar_derecho(ABBNodo<T,C>* derecho){
    this->derecho = derecho;
}

template <class T, class C>
void ABBNodo<T,C>::modificar_izquierdo(ABBNodo<T,C>* izquierdo, ABBNodo<T,C>* padre){
    this->izquierdo = izquierdo;
    this->padre = padre;
}

template <class T, class C>
void ABBNodo<T,C>::modificar_padre(ABBNodo<T,C> *padre) {
    this->padre = padre;
}

template <class T, class C>
void ABBNodo<T,C>::modificar_dato(T* dato) {
    if(dato != NULL)
        delete dato;
    this->dato = dato;
}


template <class T, class C>
void ABBNodo<T,C>::modificar_izquierdo(ABBNodo<T,C>* izquierdo){
    this->izquierdo = izquierdo;
}

template <class T, class C>
ABBNodo<T,C>* ABBNodo<T,C>::obtener_derecho(){
    return this->derecho;
}

template <class T, class C>
ABBNodo<T,C>* ABBNodo<T,C>::obtener_izquierdo(){
    return this->izquierdo;
}

template <class T, class C>
ABBNodo<T,C>* ABBNodo<T,C>::obtener_padre(){
    return this->padre;
}

template <class T, class C>
bool ABBNodo<T,C>::es_hoja(){
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() == NULL);
}

template <class T, class C>
bool ABBNodo<T,C>::solo_hijo_derecho(){
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() != NULL);
}

template <class T, class C>
bool ABBNodo<T,C>::solo_hijo_izquierdo(){
    return (this->obtener_izquierdo() != NULL && this->obtener_derecho() == NULL);
}

#endif //TP5_ALGO2_ABBNODO_H
