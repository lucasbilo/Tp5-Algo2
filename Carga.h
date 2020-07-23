#ifndef carga_h
#define carga_h

#include <stdio.h>
#include <fstream>
#include <string>

//Archivos.h

#include "Grafo.h"
#include "ABB.h"

using namespace std;

class Carga
{
private:

	//Atributos
	
	ifstream archivo_aeropuerto;
	ifstream archivo_vuelos;
	ABB* diccionario_aeropuerto;
	Grafo* grafo_vuelos;
	
	//Metodos
	
	//PRE: Variable archivo de lectura por parametro.
    //POST: Devuelve booleana depende de si se pudo abrir el archivo o no.
    bool existe_archivo();


public:

    //Constructor
    //PRE: Nombres de archivo .txt en string.
    //POST: Variables de archivo ifstream creadas.
    Carga(){string nombre_archivo_aeropuerto, string nombre_archivo_vuelos};
	
    //Destructor
    //PRE: Objeto archivo creado.
    //Libera recursos, memoria, etc.
    ~Carga(){};
	
    
    //PRE: -.
    //POST: Arbol diccionario de aeropuertos creado mediante la lectura del aeropuerto.
    bool cargar_diccionario_aeropuerto(){};
	
    //PRE: -.
    //POST: Grafo de vuelos creado mediante la lectura del archivo de vuelos.
    void cargar_grafo_vuelos(){};
	
	//PRE: -.
	//POST: Devuelve un puntero al diccionario.
	ABB* obtener_diccionario_aeropuerto(){};
	
	//PRE: -.
	//POST: Devuelve puntero al grafo de vuelos.
	Grafo* obtener_grafo_vuelos(){};
};

#endif /* carga_h */
