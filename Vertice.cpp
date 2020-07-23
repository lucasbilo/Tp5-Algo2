#include "Vertice.h"

Vertice::Vertice(std::string clave){
    this->clave = clave;
    aristas_adyacentes = new ABB<Arista>;
}

Vertice::~Vertice(){
    delete aristas_adyacentes;
}

void Vertice::agregar_arista(Arista* arista){
    aristas_adyacentes->agregar(arista->obtener_cod_destino(), arista);
}

Arista* Vertice::consultar_arista(std::string destino){
    return aristas_adyacentes->consultar(destino);
}