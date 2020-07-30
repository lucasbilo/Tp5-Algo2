#include <iostream>
#include "lista.h"
#include "Diccionario.h"
#include "Menu.h"
#include "Validacion.h"
#include "Carga.h"

using namespace std;

const string NOMBRE_ARCHIVO_VUELOS = "vuelos3.txt";
const string NOMBRE_ARCHIVO_AEROPUERTOS = "aeropuertos.txt";

//ESTO ES UNA PRUEBA

int main() {
    
    Carga carga(NOMBRE_ARCHIVO_AEROPUERTOS, NOMBRE_ARCHIVO_VUELOS);
    Grafo* vuelos = new Grafo();
    if(carga.cargar_grafo_vuelos(vuelos))
    {
        cout << "Se cargo el grafo" << endl;
        vuelos->imprimir_camino_minimo("A", "B", 1);
       // vuelos->obtener_vertices()->imprimir_en_orden();
    }
    delete vuelos;
}
