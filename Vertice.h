#ifndef TP5_ALGO2_VERTICE_H
#define TP5_ALGO2_VERTICE_H

#include "Arista.h"
#include <string>
#include "Diccionario.h"

class Arista;

class Vertice {

    private:
        std::string clave;
        Diccionario<Arista>* aristas_adyacentes;
    public:

        Vertice(std::string clave);

        ~Vertice();

        std::string obtener_clave();

        //PRE: No hay otra arista con el mismo destino. La partida de la arista es igual a la clave.
        // POST: Se agrega la arista al diccionario de aristas_adyacentes. Su clave es el destino, y el dato, la arista.
        void agregar_arista(Arista* arista);


        Arista* consultar_arista(std::string destino);

        //POST: Copia la clave de la primera arista del Diccionario en min y devuelvo un puntero a la arista que la representa.
        Arista* encontrar_min(std::string &clave_min);

        // POST: Retorna un puntero a la arista que se encuentra inmediatamente despues de clave en el diccionario. Ademas, modifica la clave, por la del sucesor.
        Arista* siguiente_arista(std::string &codigo);
};


#endif //TP5_ALGO2_VERTICE_H
