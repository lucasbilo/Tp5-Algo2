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
    cout << "Codigo iata: " << iata << endl;
    cout << "Nombre del aeropuerto: " << aeropuerto << endl;
    cout << "Nombre de la ciudad: "  << ciudad << endl;
    cout << "Nombre del pais: " << pais << endl;
    cout << "Superficie del aeropuerto: " << superficie << endl;
    cout << "Cantidad de terminales: " << cant_terminales << endl;
    cout << "Cantidad de destinos NACIONALES: " << d_nacionales << endl;
    cout << "Cantidad de destinos INTERNACIONALES: " << d_internacionales << endl;
    cout << "------------------------------------------------------" << endl;
}
