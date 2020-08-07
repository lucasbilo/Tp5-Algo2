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

        //PRE: posicion_peso es una posicion valida, es decir 1<= pos <= tam de lista de pesos.
        //POST: Imprime todos los caminos minimos determinados por la posicion del peso que hay desde el vertice que corresponde a origen hasta el de destino.
        //      Si no hay un camino entre los mismos o alguno de los vertices no pertenecen al conjunto de vertices, se imprime un mensaje por pantalla
        //      indicando lo ocurrido.
        void imprimir_camino_minimo(std::string origen, std::string destino, int posicion_peso);


    private:

        // POST: Agrega un vertice vacio en el ABB de vertices.
        Vertice* agregar_vertice(std::string clave_vertice);

        //PRE: posicion_peso es una posicion valida, es decir 1<= pos <= tam de lista de pesos. Tope = 0, origen y destino apuntan a vertices del grafo.
        //POST: Llena las posiciones del vector de ultimo_visitado con listas que contienen la ultima arista por la que hay que pasar para cada Vertice del grafo
        //      en funcion de generar un camino minimo entre origen y cada vertice. Vale aclarar que solo son llenados los vertices necesarios para luego poder
        //      imprimir los caminos minimos entre origen y destino.
        // DESCRIPCION: Se implementa el algoritmo de Dijkstra para buscar el camino minimo entre origen y destino.
        void buscar_camino_min(Vertice* origen, Vertice* destino, int posicion_peso, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int &tope);

        //PRE: Tope se corresponde al tope de todos los vectores recibidos. arista_actual es una arista_valida, cuyo destino se corresponde al vertice al que se
        //     le quiere generar una posicion en los vectores.
        // POST: Agrega un vertice al vector de vertices y le asigna una posicion. Inicializa los correspondientes vectores que se corresponden a este vertice.
        //       Es decir, el la ultima arista por la que hay que pasar para llegar al camino minimo sera la arista_actual, la distancia parcial sera el peso
        //       de esta arista; el vector de vertices en la posicion de tope corresponde al vertice a agregar. Aumenta el tope en una unidad.
        //       Devuelve la posicion en los vectores que corresponde a este vertice (tope - 1).
        int generar_posicion(Arista* arista_actual, Vertice* vector_vertices[], double distancia[], int posicion_peso,
                Lista<Arista*>* ultimo_visitado[], bool vistos[], int &tope);

        // PRE: distancia y vistos estan correctamente inicializados y se corresponden a los caminos minimos parciales y a los vertices ya visitados.
        //      tope representa al tope de ambos vectores.
        // POST: Devuelve el minimo de distancia tal que esa posicion no haya sido visitada(no haya visitado ya a ese vertice).
        int buscar_pos_min(double distancia[], bool vistos[], int tope);

        // PRE: tope representa al tope del vector de vistos.
        // POST: Devuelve true si todos los elementos de vistos(hasta tope) valen true.
        bool todos_visitados(bool vistos[], int tope);

        // PRE: tope representa al tope del vector de vertices.
        // POST: Si el vertice esta en el vector_vertices, devuelte la posicion del mismo. Sino, devuelve POSICION_INVALIDA.
        int encontrar_posicion(Vertice* vertice, Vertice* vector_vertices[], int tope);


        // PRE: Para cada Vertice necesario del grafo que puede estar en el camino minimo entre el origen y el destino:
        //      Las listas de ultimo_visitado contienen la ultima arista por la que hay que pasa en funcion de generar un camino minimo
        //      entre origen y cada vertice.
        void imprimir_caminos(Vertice* llegada, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int tope, int posicion_peso);

        void liberar_memoria_visitados(Lista<Arista*>* ultimo_visitado[], int tope);

        // agregados recieen a ver si funciona.

        void imprimir_camino(Lista<Arista*>* camino, int pos_peso, int &numero_opcion);
        void desvisitar_aristas(Lista<bool>* aristas_visitadas);
        void visitar_arista(Lista<bool>* aristas_visitadas, int);
        void agregar_arista(Lista<Arista*>* camino, Lista<Arista*>* ultimo_visitado, int pos_lista);
        bool visitado(Lista<bool>* aristas_visitadas, int &pos_lista);
        void inicializar_recorridos(Lista<bool>* recorridos_visitados[], Lista<Arista*>* ultimo_visitado[], int tope);
        void liberar_memoria_visitados(Lista<bool>* ultimo_visitado[], int tope);
        bool todos_caminos_impresos(Lista<bool>* recorridos_visitados[], Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int tope, Vertice* llegada);







    };



#endif //TP5_ALGO2_GRAFO_H
