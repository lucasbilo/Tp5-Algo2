#include "Carga.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Carga::Carga(string nombre_archivo_aeropuertos, string nombre_archivo_vuelos)
{
	this -> nombre_archivo_aeropuertos  = nombre_archivo_aeropertos;
	this -> nombre_archivo_vuelos = nombre_archivo_vuelos;
	
	ifstream archivo_aeropuerto(nombre_archivo_aeropuertos);
	ifstream archivo_vuelos(nombre_archivo_vuelos);
	diccionario_aeropuerto = NULL;
	grafo_vuelos = NULL;
}

bool Carga::existe_archivo(ifstream& archivo)
{
    if (!archivo.fail())
    {
        return true;
    }
	return false;
}

ABB* Carga::obtener_diccionario_aeropuerto()
{
	return diccionario_aeropuerto;
}

Grafo* Carga::obtener_grafo_vuelos()
{
	return grafo_vuelos;
}


//FALTA

void Carga::cargar_diccionario_aeropuerto();


bool Carga::cargar_grafo_vuelos()
{
	if (existe_archivo(archivo_grafo))
	{
		Grafo vuelos; //Objeto vuelos de clase Grafo creado
		grafo_vuelos -> vuelos; //el puntero al grafo a punta el grafo propiamente dicho
		
		string codigo_IATA_partida, codigo_IATA_destino;
		double costo_vuelo, horas_vuelo;
		Lista<double>* aux_pesos = new Lista<double>;
		
		while (archivo_grafo >> codigo_IATA_partida)
		{
			archivo_grafo >> codigo_IATA_destino;
			archivo_grafo >> costo_vuelo;
			archivo_grafo >> horas_vuelo;
			(*aux_pesos).insertar(costo_vuelo);
			(*aux_pesos).insertar(horas_vuelo);
			Arista* vuelo = new Arista(codigo_IATA_partida, codigo_IATA_destino, aux_pesos);
			vuelos.agregar_arista(vuelo);
		}
		return true;
		
	else
	{
		cout << "El archivo " << nombre_archivo_vuelos << " no se pudo abrir, por favor comprobar que exista." << endl;
		return false
}
	


