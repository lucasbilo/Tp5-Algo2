#include "Diccionario.h"
#include "Menu.h"
#include "Carga.h"

using namespace std;

const string NOMBRE_ARCHIVO_VUELOS = "vuelos.txt";
const string NOMBRE_ARCHIVO_AEROPUERTOS = "aeropuertos.txt";

int main() {

    Carga carga(NOMBRE_ARCHIVO_AEROPUERTOS, NOMBRE_ARCHIVO_VUELOS);
    Diccionario<Aeropuerto>* aeropuerto = new Diccionario<Aeropuerto>;
    Grafo* vuelos = new Grafo();
    bool archivo_aeropuertos_abierto = carga.cargar_diccionario_aeropuerto(aeropuerto);
    bool archivo_vuelos_abierto = carga.cargar_grafo_vuelos(vuelos);
    if (archivo_aeropuertos_abierto && archivo_vuelos_abierto)
    {
       Menu menu(aeropuerto, vuelos);
       menu.menu_completo(); 
    }
    
    delete vuelos;
    delete aeropuerto;
}
