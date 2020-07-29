#include "Arista.h"

using namespace std;

Arista::Arista(Vertice* origen, Vertice* destino, Lista<double>* pesos){
    this->origen = origen;
    this->destino = destino;
    this->pesos = pesos;
}

Arista::~Arista() {
    delete pesos;
}

string Arista::obtener_cod_partida(){
    return cod_partida;
}

string Arista::obtener_cod_destino(){
    return cod_destino;
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

