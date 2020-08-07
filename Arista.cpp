#include "Arista.h"

using namespace std;

//CONSTRUCTOR
Arista::Arista(Vertice* origen, Vertice* destino, Lista<double>* pesos){
    this->origen = origen;
    this->destino = destino;
    this->pesos = pesos;
}

//DESTRUCTOR
Arista::~Arista() {
    delete pesos;
}

string Arista::obtener_cod_partida(){
    return origen->obtener_clave();
}

string Arista::obtener_cod_destino(){
    return destino->obtener_clave();
}

double Arista::obtener_peso(int posicion){
    return *(pesos->obtener_dato(posicion));
}

Vertice* Arista::obtener_destino(){
    return destino;
}

Vertice* Arista::obtener_origen(){
    return origen;
}

