#ifndef TP5_ALGO2_NodoDic_H
#define TP5_ALGO2_NodoDic_H

#include <cstddef>
#include <string>

template <class T> // T para el dato
class Nodo_dic{

    private:
        T* dato;
        std::string clave;
        int nivel;
        Nodo_dic<T>* izquierdo; // Hijo izquierdo
        Nodo_dic<T>* derecho; //Hijo derecho
        Nodo_dic<T>* padre;

    public:
        //Constructor
        // POST: Se inicializa un Nodo_dic con el atributo dato igual al dato recibido por parametro.
        // Los demas atributos apuntan a NULL
        Nodo_dic(T* dato, std::string clave);

        //Destructor
        //POST: Elimina la memoria a la que apunta dato.
        ~Nodo_dic();
    
        void setear_nivel(int nivel);
    
        int obtener_nivel();

        //POST: Devuelve un dato de tipo T que es el atributo clave
        std::string obtener_clave();

        //POST: Devuelve un dato de tipo T que es el atributo dato
        T* obtener_dato();

        // POST: Modifica al atributo dato, por el dato que se recibe como parametro
        void modificar_dato(T* dato);

        void modificar_clave(std::string clave);

        // POST: Modifica 2 atributos, derecho y padre.
        // this->derecho = derecho
        // this->padre = padre
        void modificar_derecho(Nodo_dic<T>* derecho, Nodo_dic<T>* padre);

        // POST: Modifica 2 atributos, izquierdo y padre.
        // this->izquierdo = izquierdo
        // this->padre = padre
        void modificar_izquierdo(Nodo_dic<T>* izquierdo, Nodo_dic<T>* padre);

        // POST: Modifica el atributo derecho:
        // this->derecho = derecho
        void modificar_derecho(Nodo_dic<T>* derecho);

        // POST: Modifica el atributo izquierdo:
        // this->izquierdo = izquierdo
        void modificar_izquierdo(Nodo_dic<T>* izquierdo);

        // POST: Modifica el atributo padre:
        // this->padre = padre
        void modificar_padre(Nodo_dic<T>* padre);

        //POST: Devuelve el atributo derecho
        Nodo_dic<T>* obtener_derecho();

        //POST: Devuelve el atributo izquierdo
        Nodo_dic<T>* obtener_izquierdo();

        //POST: Devuelve el atributo padre
        Nodo_dic<T>* obtener_padre();

        // POST: Unicamente devuelve TRUE si se verifica que:
        // izquierdo == NULL y derecho == NULL
        bool es_hoja();

        // POST: Unicamente devuelve TRUE si se verifica que:
        // izquierdo == NULL y derecho != NULL
        bool solo_hijo_derecho();

        // POST: Unicamente devuelve TRUE si se verifica que:
        // izquierdo != NULL y derecho == NULL
        bool solo_hijo_izquierdo();

        // POST: Unicamente devuelve TRUE si se verifica que el nodo solo tiene un hijo (no importa si es derecho o izquierdo)
        bool solo_un_hijo();
};

template <class T>
Nodo_dic<T>::Nodo_dic(T* dato, std::string clave){
    this->clave = clave;
    this -> nivel = 0;
    this->dato = dato;
    this->izquierdo = NULL;
    this->derecho = NULL;
    this->padre = NULL;
}


template <class T>
Nodo_dic<T>::~Nodo_dic(){
    if( dato != NULL)
        delete dato;
}

template <class T>
void Nodo_dic<T>::setear_nivel(int nivel)
{
    this -> nivel = nivel;
}

template <class T>
int Nodo_dic<T>::obtener_nivel()
{
    return this -> nivel;
}


template <class T>
std::string Nodo_dic<T>::obtener_clave(){
    return this->clave;
}

template <class T>
T* Nodo_dic<T>::obtener_dato(){
    return this->dato;
}

template <class T>
void Nodo_dic<T>::modificar_derecho(Nodo_dic<T>* derecho, Nodo_dic<T>* padre){
    this->derecho = derecho;
    this->padre = padre;
}

template <class T>
void Nodo_dic<T>::modificar_derecho(Nodo_dic<T>* derecho){
    this->derecho = derecho;
}

template <class T>
void Nodo_dic<T>::modificar_izquierdo(Nodo_dic<T>* izquierdo, Nodo_dic<T>* padre){
    this->izquierdo = izquierdo;
    this->padre = padre;
}

template <class T>
void Nodo_dic<T>::modificar_padre(Nodo_dic<T> *padre) {
    this->padre = padre;
}

template <class T>
void Nodo_dic<T>::modificar_dato(T* dato) {
    this->dato = dato;
}

template <class T>
void Nodo_dic<T>::modificar_clave(std::string clave) {
    this->clave = clave;
}

template <class T>
void Nodo_dic<T>::modificar_izquierdo(Nodo_dic<T>* izquierdo){
    this->izquierdo = izquierdo;
}

template <class T>
Nodo_dic<T>* Nodo_dic<T>::obtener_derecho(){
    return this->derecho;
}

template <class T>
Nodo_dic<T>* Nodo_dic<T>::obtener_izquierdo(){
    return this->izquierdo;
}

template <class T>
Nodo_dic<T>* Nodo_dic<T>::obtener_padre(){
    return this->padre;
}

template <class T>
bool Nodo_dic<T>::es_hoja(){
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() == NULL);
}

template <class T>
bool Nodo_dic<T>::solo_hijo_derecho(){
    return (this->obtener_izquierdo() == NULL && this->obtener_derecho() != NULL);
}

template <class T>
bool Nodo_dic<T>::solo_hijo_izquierdo(){
    return (this->obtener_izquierdo() != NULL && this->obtener_derecho() == NULL);
}

template <class T>
bool Nodo_dic<T>::solo_un_hijo(){
    return (this->solo_hijo_derecho() || this->solo_hijo_izquierdo());
}

#endif //TP5_ALGO2_NodoDic_H
