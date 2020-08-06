#include "Aeropuertos.h"

using namespace std;

Aeropuerto::Aeropuerto(string iata, string aeropuerto, string ciudad, string pais, float superficie, unsigned int cant_terminales, unsigned int d_nacionales, unsigned int d_internacionales){
    this->iata = iata;
    this->aeropuerto = aeropuerto;
    this->ciudad = ciudad;
    this->pais = pais;
    this->superficie = superficie;
    this->cant_terminales = cant_terminales;
    this->d_nacionales = d_nacionales;
    this->d_internacionales = d_internacionales;
}

string Aeropuerto::obtener_iata(){
    return iata;
}

string Aeropuerto::obtener_aeropuerto(){
    return aeropuerto;
}

string Aeropuerto::obtener_ciudad(){
    return ciudad;
}

string Aeropuerto::obtener_pais(){
    return pais;
}

float Aeropuerto::obtener_superficie(){
    return superficie;
}

unsigned int Aeropuerto::obtener_cant_terminales(){
    return cant_terminales;
}

unsigned int Aeropuerto::obtener_d_nacionales(){
    return d_nacionales;
}

unsigned int Aeropuerto::obtener_d_internacionales(){
    return d_internacionales;
}

void Aeropuerto::mostrar_datos(){
    cout << "Codigo iata: " << iata << " || Nombre: " << aeropuerto << " || Ciudad: " << ciudad << " || Pais: "<< pais << endl;
    cout << "------------------------------------------------------" << endl;
}
