#ifndef TP5_ALGO2_AEROPUERTO_H
#define TP5_ALGO2_AEROPUERTO_H

#include <string>
#include <iostream>

class Aeropuerto{
    private:
        std::string iata;
        std::string aeropuerto;
        std::string ciudad;
        std::string pais;
        float superficie;
        unsigned int cant_terminales;
        unsigned int d_nacionales;
        unsigned int d_internacionales;

    public:
        //CONSTRUCTOR SIN PARAMETROS
        //PRE:
        //POST: Inicializa a Aeropuerto.
        Aeropuerto();

        //CONSTRUCTOR CON PARAMETROS
        //PRE:
        //POST: Inicializa a Aeropuerto y se asigna cada parametro al atributo correspondiente.
        Aeropuerto(std::string iata, std::string aeropuerto, std::string ciudad, std::string pais, float superficie, unsigned int cant_terminales, unsigned int d_nacionales, unsigned int d_internacionales);

        //DESTRUCTOR
        ~Aeropuerto(){};

        //GETTERS
        //POST: Devuelve el codigo iata
        std::string obtener_iata();

        //POST: Devuelve el nombre del aeropuerto
        std::string obtener_aeropuerto();

        //POST: Devuelve el nombre de la ciudad
        std::string obtener_ciudad();

        //POST: Devuelve el nombre del pais
        std::string obtener_pais();

        //POST: Devuelve la superficie del aeropuerto
        float obtener_superficie();

        //POST: Devuelve la cantidad de terminales en el aeropuerto
        unsigned int obtener_cant_terminales();

        //POST: Devuelve la cantidad de destinos nacionales
        unsigned int obtener_d_nacionales();

        //POST: Devuelve la cantidad de destinos internacionales
        unsigned int obtener_d_internacionales();

        //POST: Imprime los siguientes atributos del Aeropuerto:
        // iata - aeropuerto - ciudad - pais
        void mostrar_datos();
};

#endif //TP5_ALGO2_AEROPUERTOS_H
