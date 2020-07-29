#ifndef CARGA_H //CAMBIAR
#define CARGA_H

#include <iostream>
#include <fstream>
#include <string>

//Archivos.h

#include "Grafo.h"
#include "Diccionario.h"
#include "Aeropuertos.h"

class Carga
{
private:

	//Atributos
	
	std::string nombre_archivo_aeropuertos;
    std::string nombre_archivo_vuelos;

public:

    //Constructor
    //PRE: Nombres de archivo .txt en string.
    //POST: Variables de archivo ifstream creadas.
    Carga(std::string nombre_archivo_aeropuerto, std::string nombre_archivo_vuelos);
	
    //Destructor
    //PRE: Objeto archivo creado.
    //POST: -.
    ~Carga(){}
	
    
    //PRE: -.
    //POST: Arbol diccionario de aeropuertos creado mediante la lectura del aeropuerto. Devuelve bool determinando si se pudo cargar o no.
    bool cargar_diccionario_aeropuerto(Diccionario<Aeropuerto>* p_diccionario);
	
    //PRE: -.
    //POST: Grafo de vuelos creado mediante la lectura del archivo de vuelos. Devuelve bool determinando si se pudo cargar o no.
    bool cargar_grafo_vuelos(Grafo* p_grafo);
};

#endif /* CARGA_H */
