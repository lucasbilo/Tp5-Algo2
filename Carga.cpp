#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

//Archivos.h

#include "Carga.h"
#include "Grafo.h"
#include "Diccionario.h"
#include "NodoDic.h"
#include "Aeropuertos.h"

using namespace std;

Carga::Carga(string nombre_archivo_aeropuertos, string nombre_archivo_vuelos)
{
	this -> nombre_archivo_aeropuertos  = nombre_archivo_aeropuertos;
	this -> nombre_archivo_vuelos = nombre_archivo_vuelos;
	
	ifstream archivo_aeropuerto(nombre_archivo_aeropuertos);
	ifstream archivo_vuelos(nombre_archivo_vuelos);
	
	diccionario_aeropuerto = NULL;
	grafo_vuelos = NULL;
}

Carga::~Carga()
{
    delete diccionario_aeropuerto;
	delete grafo_vuelos;
}

bool Carga::existe_archivo(ifstream& archivo)
{
    if (!archivo.fail())
    {
        return true;
    }
	return false;
}

void Carga::cerrar_archivo(ifstream& archivo)
{
    archivo.close();
}

bool Carga::cargar_diccionario_aeropuerto()
{
    if (existe_archivo(archivo_aeropuerto))
    {
        Diccionario<Aeropuerto>* diccionario_aeropuerto = new Diccionario<Aeropuerto>;//el puntero al grafo a punta el grafo propiamente dicho
        
        string codigo_IATA, nombre_aeropuerto, ciudad, pais;
        float superficie;
        unsigned int cant_terminales, d_nacionales, d_internacionales;

        
        while (archivo_aeropuerto >> codigo_IATA)
        {
            archivo_aeropuerto >> nombre_aeropuerto;
            archivo_aeropuerto >> ciudad;
            archivo_aeropuerto >> pais;
            archivo_aeropuerto >> superficie;
            archivo_aeropuerto >> cant_terminales;
            archivo_aeropuerto >> d_nacionales;
            archivo_aeropuerto >> d_internacionales;
            Aeropuerto* aeropuerto = new Aeropuerto(codigo_IATA, nombre_aeropuerto, ciudad, pais, superficie, cant_terminales, d_nacionales, d_internacionales);
            (*diccionario_aeropuerto).insertar(codigo_IATA, aeropuerto);
        }
		cerrar_archivo(archivo_aeropuerto);
        return true;
    }
        
    else
    {
        cout << "El archivo " << nombre_archivo_aeropuertos << " no se pudo abrir, por favor comprobar que exista." << endl;
        return false;
    };
}

bool Carga::cargar_grafo_vuelos()
{
	if (existe_archivo(archivo_vuelos))
	{
		grafo_vuelos = new Grafo; //el puntero al grafo a punta el grafo propiamente dicho
		
		string codigo_IATA_partida, codigo_IATA_destino;
		double costo_vuelo, horas_vuelo;
        double* p_costo_vuelo = NULL;
        double* p_horas_vuelo = NULL;
		Lista<double>* aux_pesos = new Lista<double>;
		
		while (archivo_vuelos >> codigo_IATA_partida)
		{
			archivo_vuelos >> codigo_IATA_destino;
			archivo_vuelos >> costo_vuelo;
			archivo_vuelos >> horas_vuelo;
			(*aux_pesos).insertar(p_costo_vuelo);
			(*aux_pesos).insertar(p_horas_vuelo);
			Arista* vuelo = new Arista(codigo_IATA_partida, codigo_IATA_destino, aux_pesos);
			(*grafo_vuelos).agregar_arista(vuelo);
		}
		cerrar_archivo(archivo_vuelos);
		return true;
    }
		
	else
	{
		cout << "El archivo " << nombre_archivo_vuelos << " no se pudo abrir, por favor comprobar que exista." << endl;
        return false;
    }
}
		
Diccionario<Aeropuerto>* Carga::obtener_diccionario_aeropuerto()
{
	return diccionario_aeropuerto;
}

Grafo* Carga::obtener_grafo_vuelos()
{
	return grafo_vuelos;
}

	


