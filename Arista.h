#ifndef TP5_ALGO2_ARISTA_H
#define TP5_ALGO2_ARISTA_H

#include <string>
#include "lista.h"
#include "Vertice.h"

class Vertice; //agrego la futura declaracion de Vertice, para avisarle al compilador.
class Arista{

    private:
        Vertice* origen;
        Vertice* destino;
        Lista<double>* pesos;

    public:
        //CONSTRUCTOR
        // PRE: pesos apunta a una lista valida.
        // POST: Inicializa a Arista, se asigna cada parametro al atributo correspondiente.
        Arista(Vertice* origen, Vertice* destino, Lista<double>* pesos);

        //DESTRUCTOR
        // POST: Elimina la memoria a la que apunta el puntero a la lista.
        ~Arista();

        // POST: Devuelve un string que es la clave de destino.
        std::string obtener_cod_destino();

        // POST: Devuelve un string que es la clave de partida.
        std::string obtener_cod_partida();

        // PRE: posicion es una posicion valida de la lista.
        // POST: Devuelve el peso que tiene la arista correspondido a la posicion de la lista.
        double obtener_peso(int posicion);

        //POST: Devuelve destino.
        Vertice* obtener_destino();

        //POST: Devuelve origen.
        Vertice* obtener_origen();
};

#endif //TP5_ALGO2_ARISTA_H
