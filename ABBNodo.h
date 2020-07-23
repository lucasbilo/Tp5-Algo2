#ifndef TP5_ALGO2_ABBNODO_H
#define TP5_ALGO2_ABBNODO_H

template <class T>
class ABBNodo{

    private:
        T dato;
        ABBNodo<T>* izquierdo; // Hijo izquierdo
        ABBNodo<T>* derecho; //Hijo derecho
        ABBNodo<T>* padre;

    public:
        //Constructor
        // POST: Se inicializa un ABBNodo con el atributo dato igual al dato recibido por parametro.
        // Los demas atributos apuntan a NULL
        ABBNodo(T dato);

        //POST: Devuelve el atributo dato
        T obtener_dato();

        // POST: Modifica al atributo dato, por el dato que se recibe como parametro
        void modificar_dato(T dato);

        // POST: Modifica 2 atributos, derecho y padre.
        // derecho = derecho(parametro)
        // padre = padre(parametro)
        void modificar_derecho(ABBNodo<T>* derecho, ABBNodo<T>* padre);

        // POST: Modifica 2 atributos, izquierdo y padre.
        // izquierdo = izquierdo(parametro)
        // padre = padre(parametro)
        void modificar_izquierdo(ABBNodo<T>* izquierdo, ABBNodo<T>* padre);

        // POST: Modifica el atributo derecho:
        // // derecho = derecho(parametro)
        void modificar_derecho(ABBNodo<T>* derecho);

        // POST: Modifica el atributo izquierdo:
        // izquierdo = izquierdo(parametro)
        void modificar_izquierdo(ABBNodo<T>* izquierdo);

        // POST: Modifica el atributo padre:
        // padre = padre(parametro)
        void modificar_padre(ABBNodo<T>* padre);

        //POST: Devuelve el atributo derecho
        ABBNodo<T>* obtener_derecho();

        //POST: Devuelve el atributo izquierdo
        ABBNodo<T>* obtener_izquierdo();

        //POST: Devuelve el atributo padre
        ABBNodo<T>* obtener_padre();

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

template <class T>
ABBNodo<T>::ABBNodo(T dato)
{
    this->dato = dato;
    this->izquierdo = NULL;
    this->derecho = NULL;
    this->padre = NULL;
}

template <class T>
T ABBNodo<T>::obtener_dato()
{
    return this->dato;
}

template <class T>
void ABBNodo<T>::modificar_derecho(ABBNodo<T>* derecho, ABBNodo<T>* padre){
    this->derecho = derecho;
    this->padre = padre;
}

template <class T>
void ABBNodo<T>::modificar_derecho(ABBNodo<T>* derecho){
    this->derecho = derecho;
}

template <class T>
void ABBNodo<T>::modificar_izquierdo(ABBNodo<T>* izquierdo, ABBNodo<T>* padre){
    this->izquierdo = izquierdo;
    this->padre = padre;
}

template <class T>
void ABBNodo<T>::modificar_padre(ABBNodo<T> *padre) {
    this->padre = padre;
}

template <class T>
void ABBNodo<T>::modificar_dato(T dato) {
    this->dato = dato;
}


template <class T>
void ABBNodo<T>::modificar_izquierdo(ABBNodo<T>* izquierdo){
    this->izquierdo = izquierdo;
}

template <class T>
ABBNodo<T>* ABBNodo<T>::obtener_derecho()
{
    return this->derecho;
}

template <class T>
ABBNodo<T>* ABBNodo<T>::obtener_izquierdo()
{
    return this->izquierdo;
}

template <class T>
ABBNodo<T>* ABBNodo<T>::obtener_padre()
{
    return this->padre;
}

template <class T>
bool ABBNodo<T>::es_hoja() {
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() == NULL);
}

template <class T>
bool ABBNodo<T>::solo_hijo_derecho() {
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() != NULL);
}

template <class T>
bool ABBNodo<T>::solo_hijo_izquierdo() {
    return (this->obtener_izquierdo() != NULL && this->obtener_derecho() == NULL);
}

#endif //TP5_ALGO2_ABBNODO_H
