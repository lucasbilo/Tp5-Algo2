#include "Grafo.h"

using namespace std;

const double INFINITO = 1e100;

//CONSTRUCTOR
Grafo::Grafo(){
    cantidad_vertices = 0;
    vertices = new ABB<Vertice, string>;
}

//DESTRUCTOR
Grafo::~Grafo(){
    delete vertices;
}

//Agrega la arista al conjunto de aristas del vertice de salida.
void Grafo::agregar_arista(Arista* arista){
    string partida = arista->obtener_cod_partida();
    string destino = arista->obtener_cod_destino();
    Vertice* aux = vertices->consultar(destino);
    if(aux == NULL)
        agregar_vertice(destino);
    aux = vertices->consultar(partida);
    if(aux == NULL){
        agregar_vertice(partida);
        aux = vertices->consultar(partida);
    }
    aux->agregar_arista(arista);
}

//Agrega un vertice vacio al grafo.
void Grafo::agregar_vertice(string clave_vertice){
    Vertice* aux = new Vertice(clave_vertice);
    vertices->insertar(clave_vertice, aux);
    cantidad_vertices++;
}

double Grafo::obtener_peso(string origen, string destino, int posicion){
    Vertice* aux = vertices->consultar(origen);
    Arista* edge = aux->consultar_arista(destino);
    if(edge == NULL)
        return INFINITO;
    return edge->obtener_peso(posicion);
}


/*FALTA IMPLEMENTAR*/
/*
void Grafo::buscar_camino_minimo(Vertice origen, Vertice destino); // hay que ver bien desps que es lo que devolveria
//podria ser una lista de listas de sucesiones de aristas. Porque vieron que puede haber mas de un camino bueno. No se hay que pensarlo
void Grafo::imprimir_camino(Lista<Arista>);
 */