#ifndef TP5_ALGO2_ARISTA_H
#define TP5_ALGO2_ARISTA_H

#include <string>
#include "lista.h"
#include "Vertice.h"

class Arista{

    private:
        std::string cod_partida;
        Vertice* destino;
        Vertice* origen;
        std::string cod_destino;
        Lista<double>* pesos;

    public:
        //CONSTRUCTOR
        // POST: Inicializa a Arista, se asigna cada parametro al atributo correspondiente.
        Arista(std::string cod_partida, std::string cod_destino, Lista<double>* pesos);

        //DESTRUCTOR
        // POST: Elimina la memoria a la que apunta el puntero a la lista.
        ~Arista();

        // POST: Devuelve un string que es el atributo cod_partida
        std::string obtener_cod_partida();

        // POST: Devuelve un string que es el atributo cod_destino
        std::string obtener_cod_destino();

        // PRE: posicion es una posicion valida de la lista.
        // POST: Devuelve el peso que tiene la arista correspondido a la posicion de la lista.
        double obtener_peso(int posicion);

        Vertice* obtener_destino();

        Vertice* obtener_origen();


};

#endif //TP5_ALGO2_ARISTA_H
