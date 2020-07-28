#include <iostream>
#include "lista.h"
#include "Diccionario.h"
#include "Menu.h"
#include "Validacion.h"
#include "Carga.h"

using namespace std;

const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";
const string NOMBRE_ARCHIVO_AEROPUERTOS = "aeropuertos.txt";

//ESTO ES UNA PRUEBA

int main() {
    
    Carga carga(NOMBRE_ARCHIVO_AEROPUERTOS, NOMBRE_ARCHIVO_VUELOS);
    if(carga.cargar_grafo_vuelos())
    {
        cout << "Se cargo el grafo" << endl;
        ((carga.obtener_grafo_vuelos())->obtener_vertices())->imprimir_en_orden();
    }
}
