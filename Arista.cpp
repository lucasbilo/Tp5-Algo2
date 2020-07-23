#include "Arista.h"
using namespace std;

Arista::Arista(std::string cod_partida, std::string cod_destino, Lista<double>* pesos){
    this->cod_partida = cod_partida;
    this->cod_destino = cod_destino;
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
