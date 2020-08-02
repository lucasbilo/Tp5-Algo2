#ifndef TP5_ALGO2_MENU_H
#define TP5_ALGO2_MENU_H

#include <string>
#include "Aeropuertos.h"
#include "Diccionario.h"
#include "Grafo.h"
#include "Validacion.h"

class Menu{
    private:
        Diccionario<Aeropuerto>* ABB;
        Grafo* grafo;
        Validacion validaciones;

    public:
        //CONSTRUCTOR SIN PARAMETROS:
        //POST: Construye un objeto de clase MENU.
        Menu(Diccionario<Aeropuerto> * ABB, Grafo * grafo);

        //DESTRUCTOR
        ~Menu() {};

        //POST: Muestra el menu del Arbol binario.
        void menu_abb();

        //POST: Muestra el menu del Grafo
        void menu_grafo();

        //POST: Muestra el menu del programa.
        void menu_completo();

        //PRE: La opcion debe ser una opcion valida.
        //POST: Ejecuta la accion correspondiente a la opcion elegida del menu abb.
        void opcion_abb(int opcion);

        //PRE: La opcion debe ser una opcion valida.
        //POST: Ejecuta la accion correspondiente a la opcion elegida del menu grafo
        void opcion_grafo(int opcion);

        //POST: Devuelve el camino minimo del grafo del tipo de peso pasado por parametro.
        void grafo_minimo(int tipo_de_peso);

        //POST: Devuelve el codigo IATA que desea buscar.
        std::string solicitar_clave();

        //POST: Devuelve la informacion de un aeropuerto.
        void consultar_aeropuerto();

        //POST: Da de baja un aeropuerto.
        void baja_aeropuerto();

        //PRE: El codigo IATA no debe estar en el arbol.
        //POST: Da de alta un aeropuerto.
        void alta_aeropuerto();

};

#endif //TP5_ALGO2_MENU_H