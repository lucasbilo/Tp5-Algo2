#include "Vertice.h"

using namespace std;

Vertice::Vertice(std::string clave){
    this->clave = clave;
    aristas_adyacentes = new Diccionario<Arista>;
}

Vertice::~Vertice(){
    delete aristas_adyacentes;
}

std::string Vertice::obtener_clave(){
    return clave;
}

void Vertice::agregar_arista(Arista* arista){
    aristas_adyacentes->insertar(arista->obtener_cod_destino(), arista);
}

Arista* Vertice::consultar_arista(std::string destino){
    return aristas_adyacentes->consultar(destino);
}

Arista* Vertice::encontrar_min(string &min){
    min = aristas_adyacentes->encontrar_min();
    return aristas_adyacentes->consultar(min);
}

Arista* Vertice::siguiente_arista(string &codigo){
    codigo = aristas_adyacentes->sucesor(codigo);
    return aristas_adyacentes->consultar(codigo);
}
