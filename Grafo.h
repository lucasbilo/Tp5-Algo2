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


        void imprimir_camino_minimo(std::string origen, std::string destino, int posicion_peso);



    private:

        // POST: Agrega un vertice vacio en el ABB de vertices.
        Vertice* agregar_vertice(std::string clave_vertice);

        int buscar_pos_min(double distancia[], bool vistos[], int tope);

        bool todos_visitados(bool vistos[], int tope);

        int encontrar_posicion(Vertice* vertice, Vertice* vector_vertices[], int tope);

        int generar_posicion(Arista* arista_actual, Vertice* vector_vertices[], double distancia[], int posicion_peso,
                                Lista<Arista*>* ultimo_visitado[],bool vistos[], int &tope);


        void buscar_camino_min(Vertice* origen, Vertice* destino, int posicion_peso, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int &tope);

        void liberar_memoria_visitados(Lista<Arista*>* ultimo_visitado[], int tope);

        void imprimir_caminos(Vertice* salida, Vertice* llegada, Vertice* destino_parcial, Lista<Arista*>* ultimo_visitado[],
                Vertice* vector_vertices[], int tope, bool &terminado);


        // agregados recieen a ver si funciona.

        void imprimir_caminos(Vertice* salida, Vertice* llegada, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int tope, int posicion_peso);
        void imprimir_camino(Lista<Arista*>* camino, int pos_peso, int &numero_opcion);
        void desvisitar_aristas(Lista<bool>* aristas_visitadas);
        void visitar_arista(Lista<bool>* aristas_visitadas);
        void agregar_arista(Lista<Arista*>* camino, Lista<Arista*>* ultimo_visitado, int pos_lista);
        bool visitado(Lista<bool>* aristas_visitadas, int &pos_lista);
        void inicializar_recorridos(Lista<bool>* recorridos_visitados[], Lista<Arista*>* ultimo_visitado[], int tope);
        void liberar_memoria_visitados(Lista<bool>* ultimo_visitado[], int tope);







    };



#endif //TP5_ALGO2_GRAFO_H
