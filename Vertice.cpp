#include "Vertice.h"

using namespace std;

Vertice::Vertice(std::string clave){
    this->clave = clave;
    aristas_adyacentes = new Diccionario<Arista>;
}

Vertice::~Vertice(){
    delete aristas_adyacentes;
}

void Vertice::agregar_arista(Arista* arista){
    aristas_adyacentes->insertar(arista->obtener_cod_destino(), arista);
}

Arista* Vertice::consultar_arista(std::string destino){
    return aristas_adyacentes->consultar(destino);
}