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
    Diccionario<Aeropuerto>* aeropuerto = new Diccionario<Aeropuerto>;
    carga.cargar_diccionario_aeropuerto(aeropuerto);
    Grafo* vuelos = new Grafo();
    carga.cargar_grafo_vuelos(vuelos);
    Menu menu(aeropuerto, vuelos);
    menu.menu_completo();
    delete vuelos;
    delete aeropuerto;
}
