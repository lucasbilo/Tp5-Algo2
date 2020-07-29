#ifndef TP5_ALGO2_GRAFO_H
#define TP5_ALGO2_GRAFO_H

#include "Diccionario.h"
#include "lista.h"
#include "Vertice.h"
#include "Arista.h"

class Grafo {
    private:
        int cantidad_vertices;
        Diccionario<Vertice>* vertices;

    public:
        // CONSTRUCTOR
        // POST: cantidad_vertices se inicializa en cero y se pide memoria para el ABB vertices.
        Grafo();

        //DESTRUCTOR
        // POST: Elimina la memoria a la que apunta vertices.
        ~Grafo();

        // PRE: La cantidad de elementos de la lista de pesos debe ser la misma que la de las demas aristas del grafo.
        // POST: Si alguno de los vertices que conectan a la arista no pertenecen al ABB de vertices, se agregan; y se agrega la arista en el
        //       conjunto de aristas adyacentes del vertice de partida.
        void agregar_arista(std::string origen, std::string destino, Lista<double>* pesos);


        void imprimir_camino_minimo(Vertice origen, Vertice destino); // hay que ver bien desps que es lo que devolveria
        //podria ser una lista de listas de sucesiones de aristas. Porque vieron que puede haber mas de un camino bueno. No se hay que pensarlo
        void imprimir_camino(Lista<Arista>);

    private:

        // POST: Agrega un vertice vacio en el ABB de vertices.
        void agregar_vertice(std::string clave_vertice);

        // PRE: Ambas claves estan en el ABB de vertices.
        // POST: devuelve el peso de la arista dirigida: origen -> destino. El peso es evaluado segun la posicion recibida(peso tipo1, tipo2,etc...)
        double obtener_peso(std::string origen, std::string destino, int posicion);

        int buscar_pos_min(double distancia[], bool vistos[], int tope);

        bool todos_visitados(bool vistos[], int tope);

        int encontrar_posicion(Vertice* vertice, Vertice* vector_vertices[], int tope);

        int generar_posicion(Arista* arista_actual, Vertice* vector_vertices[], double distancia[], int posicion_peso,
                                Lista<Arista*>* ultimo_visitado[],bool vistos[], int &tope);


        void buscar_camino_min(Vertice* origen, Vertice* destino, int pos_peso);
};



#endif //TP5_ALGO2_GRAFO_H
