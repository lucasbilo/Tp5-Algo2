#ifndef TP4_ALGO2_NODO_H
#define TP4_ALGO2_NODO_H


template < typename Dato >
class Nodo{

private:
    Dato* dato; // Dato a almacenar
    Nodo* psig; // Puntero a otro nodo

public:
    // Constructor con parametro
    // PRE: d es un puntero que apunta a memoria dinamica
    // POST: Crea un nodo con el dato d y el puntero a NULL
    Nodo(Dato* d);

    // Destructor
    // PRE: Nodo creado
    // POST: Elimina la memoria a la que apunta dato.
    ~Nodo();

    // PRE: el nodo tiene que estar creado y d tiene que apuntar a un dato valido
    // POST: Elimina la memoria a la que apuntaba dato y modifica, dato = d
    void modificar_dato(Dato* d);

    // PRE: nodo creado y ps válido
    // POST: psig apuntara a ps
    void modificar_sig(Nodo* ps);

    // PRE: nodo creado
    // POST: devuelve el dato que contiene el nodo(puntero a un dato en en el heap)
    Dato* obtener_dato();

    // PRE: nodo creado
    // POST: Devuelve el puntero al siguiente nodo, si es el último devuelve NULL
    Nodo* obtener_sig();

    // PRE: nodo creado
    // POST: TRUE si psig != NULL. En caso contrario devuelve FALSE
    bool tiene_sig();
};


template < typename Dato >
Nodo<Dato>::Nodo(Dato* d){
    dato = d;
    psig = 0;
}

template < typename Dato >
Nodo<Dato>::~Nodo(){
    delete dato;
}

template < typename Dato >
void Nodo<Dato>::modificar_dato(Dato* d){
    delete dato;
    dato = d;
}

template < typename Dato >
void Nodo<Dato>::modificar_sig(Nodo* ps){
    psig = ps;
}

template < typename Dato >
Dato* Nodo<Dato>::obtener_dato(){
    return dato;
}

template < typename Dato >
Nodo<Dato>* Nodo<Dato>::obtener_sig(){
    return psig;
}

template < typename Dato >
bool Nodo<Dato>::tiene_sig(){
    return (psig != 0);
}

#endif //TP4_ALGO2_NODO_H