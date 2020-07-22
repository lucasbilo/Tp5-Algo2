#include "vuelo.h"
using namespace std;

Vuelo::Vuelo(string cod_partida, string cod_destino, int costo, float horas){
    this->cod_partida = cod_partida;
    this->cod_destino = cod_destino;
    costo_vuelo = costo;
    horas_vuelo = horas;
}

Vuelo::~Vuelo() {}

string Vuelo::obtener_cod_partida(){
    return cod_partida;
}

string Vuelo::obtener_cod_destino(){
    return cod_destino;
}

int Vuelo::obtener_costo(){
    return costo_vuelo;
}

float Vuelo::obtener_horas(){
    return horas_vuelo;
}