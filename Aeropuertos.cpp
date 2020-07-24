#include "Aeropuertos.h"

using namespace std;

Aeropuertos::Aeropuertos(string iata, string aeropuerto, string ciudad, string pais, float superficie, unsigned int cant_terminales, unsigned int d_nacionales, unsigned int d_internacionales){
    this->iata = iata;
    this->aeropuerto = aeropuerto;
    this->ciudad = ciudad;
    this->pais = pais;
    this->superficie = superficie;
    this->cant_terminales = cant_terminales;
    this->d_nacionales = d_nacionales;
    this->d_internacionales = d_internacionales;
}

string Aeropuertos::obtener_iata(){
    return iata;
}

string Aeropuertos::obtener_aeropuerto(){
    return aeropuerto;
}

string Aeropuertos::obtener_ciudad(){
    return ciudad;
}

string Aeropuertos::obtener_pais(){
    return pais;
}

float Aeropuertos::obtener_superficie(){
    return superficie;
}

unsigned int Aeropuertos::obtener_cant_terminales(){
    return cant_terminales;
}

unsigned int Aeropuertos::obtener_d_nacionales(){
    return d_nacionales;
}

unsigned int Aeropuertos::obtener_d_internacionales(){
    return d_internacionales;
}

void mostrar_datos(){
    cout << "Codigo iata: " << iata << endl;
    cout << "Nombre del aeropuerto: " << aeropuerto << endl;
    cout << "Nombre de la ciudad: "  << ciudad << endl;
    cout << "Nombre del pais: " << pais << endl;
    cout << "Superficie del aeropuerto: " << superficie << endl;
    cout << "Cantidad de terminales: " << cant_terminales << endl;
    cout << "Cantidad de destinos NACIONALES: " << d_nacionales << endl;
    cout << "Cantidad de destinos INTERNACIONALES: " << d_internacinales << endl;
    cout << "------------------------------------------------------" << endl;
}
