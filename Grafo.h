#ifndef TP5_ALGO2_GRAFO_H
#define TP5_ALGO2_GRAFO_H

#include "lista.h"
#include "Vertice.h"
#include "Arista.h"

class Grafo {
    private:
        int cantidad_vertices;
        Lista<Vertice> vertices;
    public:
        void agregar_arista(Arista* arista);
        void agregar_vertice(Vertice vertice);
        void buscar_camino_minimo(Vertice origen, Vertice destino); // hay que ver bien desps que es lo que devolveria
        //podria ser una lista de listas de sucesiones de aristas. Porque vieron que puede haber mas de un camino bueno



};



#endif //TP5_ALGO2_GRAFO_H
