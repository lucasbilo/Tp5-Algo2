#include "Grafo.h"

Grafo::Grafo(){
    cantidad_vertices = 0;
    vertices = new ABB<Vertice>;
}

Grafo::~Grafo(){
    delete vertices;
}

void Grafo::agregar_arista(Arista* arista){
    Vertice* aux = vertices->consultar(arista->cod_destino);
    if(aux == NULL)
        agregar_vertice(arista->cod_destino);
    aux = vertices->consultar(arista->cod_partida);
    if(aux == NULL){
        agregar_vertice(arista->cod_partida);
        aux = vertices->consultar(arista->cod_partida);
    }
    aux->agregar_arista(arista);
}

void Grafo::agregar_vertice(string clave_vertice){
    Vertice* aux = new Vertice(clave_vertice);
    vertices->agregar(clave_vertice, aux);
}

void Grafo::buscar_camino_minimo(Vertice origen, Vertice destino); // hay que ver bien desps que es lo que devolveria
//podria ser una lista de listas de sucesiones de aristas. Porque vieron que puede haber mas de un camino bueno. No se hay que pensarlo
void Grafo::imprimir_camino(Lista<Arista>);