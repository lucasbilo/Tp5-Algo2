#ifndef TP5_ALGO2_MENU_H
#define TP5_ALGO2_MENU_H

#include <string>
#include "Aeropuertos.h"
#include "ABB.h"
#include "Grafo.h"

class Menu{
    private:
        Diccionario<Aeropuerto>* ABB;

    public:
        //CONSTRUCTOR SIN PARAMETROS:
        //POST: Construye un objeto de clase MENU.
        Menu(Diccionario<Aeropuerto> * ABB);

        //DESTRUCTOR
        ~Menu();

        //POST: Muestra el menu del Arbol binario.
        void menu_abb();

        //PRE: La opcion debe ser una opcion valida.
        //POST: Ejecuta la accion correspondiente a la opcion elegida.
        void opcion_abb(int opcion);

        //POST: Devuelve el codigo IATA que desea buscar.
        std::string solicitar_clave();

};

#endif //TP5_ALGO2_MENU_H