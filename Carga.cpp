#include <iostream>
#include <string>

//Archivos.h
#include "Carga.h"
#include "Excepcion.h"

using namespace std;

Carga::Carga(string nombre_archivo_aeropuertos, string nombre_archivo_vuelos)
{
	this -> nombre_archivo_aeropuertos  = nombre_archivo_aeropuertos;
	this -> nombre_archivo_vuelos = nombre_archivo_vuelos;
}

bool Carga::cargar_diccionario_aeropuerto(Diccionario<Aeropuerto>* diccionario_aeropuertos)
{
	ifstream archivo_aeropuerto(nombre_archivo_aeropuertos);
	string codigo_IATA, nombre_aeropuerto, ciudad, pais;
    float superficie;
   	unsigned int cant_terminales, d_nacionales, d_internacionales;
   
   	try
   	{
       	if (archivo_aeropuerto.fail()) throw Mi_excepcion();
       	while (archivo_aeropuerto >> codigo_IATA)
		{
           		archivo_aeropuerto >> nombre_aeropuerto;
           		archivo_aeropuerto >> ciudad;
           		archivo_aeropuerto >> pais;
           		archivo_aeropuerto >> superficie;
           		archivo_aeropuerto >> cant_terminales;
           		archivo_aeropuerto >> d_nacionales;
           		archivo_aeropuerto >> d_internacionales;
           		Aeropuerto* aeropuerto = new Aeropuerto(codigo_IATA, nombre_aeropuerto, ciudad, pais, superficie, cant_terminales, d_nacionales, d_internacionales);            		diccionario_aeropuertos -> insertar(codigo_IATA, aeropuerto);
        }
                
        archivo_aeropuerto.close();
    }
   	catch (exception& e)
   	{
       	cout << e.what();
       	cout << nombre_archivo_aeropuertos << endl;
		return false;
    }
    
   	return true;
}

bool Carga::cargar_grafo_vuelos(Grafo* grafo_vuelos)
{
	ifstream archivo_vuelos(nombre_archivo_vuelos);
    string codigo_IATA_partida, codigo_IATA_destino;
   	double costo_vuelo, horas_vuelo;
   
   	try
   	{
       	if (archivo_vuelos.fail()) throw Mi_excepcion();
       	while (archivo_vuelos >> codigo_IATA_partida)
		{
           		Lista<double>* aux_pesos = new Lista<double>;
           		archivo_vuelos >> codigo_IATA_destino;
           		archivo_vuelos >> costo_vuelo;
           		archivo_vuelos >> horas_vuelo;
           		double* p_costo_vuelo = new double(costo_vuelo);
           		double* p_horas_vuelo = new double(horas_vuelo);
           		aux_pesos -> insertar(p_costo_vuelo);
           		aux_pesos -> insertar(p_horas_vuelo);
           		grafo_vuelos -> agregar_arista(codigo_IATA_partida, codigo_IATA_destino, aux_pesos);
       	}
       	archivo_vuelos.close();

   	}
	catch (exception& e)
   	{
       	cout << e.what();
       	cout << nombre_archivo_vuelos << endl;
       	return false;
	}
	return true;
}
	


