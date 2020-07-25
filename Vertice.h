#ifndef TP5_ALGO2_VERTICE_H
#define TP5_ALGO2_VERTICE_H

#include "Arista.h"
#include <string>
#include "ABB.h"

class Vertice {

    private:
        std::string clave;
        ABB<Arista, std::string>* aristas_adyacentes;
    public:
        Vertice(std::string clave);
        ~Vertice();

        //PRE: No hay otra arista con el mismo destino. La partida de la arista es igual a la clave.
        // POST: Se agrega la arista al diccionario de aristas_adyacentes. Su clave es el destino, y el dato, la arista.
        void agregar_arista(Arista* arista);
        Arista* consultar_arista(std::string destino);
};


#endif //TP5_ALGO2_VERTICE_H
