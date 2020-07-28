#ifndef carga_h
#define carga_h

#include <stdio.h>
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
	std::ifstream archivo_aeropuerto;
	std::ifstream archivo_vuelos;
	Diccionario<Aeropuerto>* diccionario_aeropuerto;
	Grafo* grafo_vuelos;
	
	//Metodos
	
	//PRE: Variable archivo de lectura por parametro (ifstream).
    //POST: Devuelve booleana depende de si se pudo abrir el archivo o no.
    bool existe_archivo(ifstream& archivo);
	
	//PRE: Variable archivo de lectura por parametro (ifstream).
	//POST: Cierra el archivo ifstream.
	void cerrar_archivo(ifstream& archivo);


public:

    //Constructor
    //PRE: Nombres de archivo .txt en string.
    //POST: Variables de archivo ifstream creadas.
    Carga(std::string nombre_archivo_aeropuerto, std::string nombre_archivo_vuelos);
	
    //Destructor
    //PRE: Objeto archivo creado.
    //POST: Elimina punteros a diccionario y grafo.
    ~Carga();
	
    
    //PRE: -.
    //POST: Arbol diccionario de aeropuertos creado mediante la lectura del aeropuerto. Devuelve bool determinando si se pudo cargar o no.
    bool cargar_diccionario_aeropuerto();
	
    //PRE: -.
    //POST: Grafo de vuelos creado mediante la lectura del archivo de vuelos. Devuelve bool determinando si se pudo cargar o no.
    bool cargar_grafo_vuelos();
	
	//PRE: -.
	//POST: Devuelve un puntero al diccionario.
	Diccionario<Aeropuerto>* obtener_diccionario_aeropuerto();
	
	//PRE: -.
	//POST: Devuelve puntero al grafo de vuelos.
	Grafo* obtener_grafo_vuelos();
};

#endif /* carga_h */
