#include "Carga.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Carga::Carga(string nombre_archivo_aeropuertos, string nombre_archivo_vuelos)
{
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


void Carga::cargar_grafo_vuelos();


