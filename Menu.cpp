#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

Menu::Menu(Diccionario<Aeropuerto> * ABB){
    this -> ABB = ABB;
};

void Menu::menu_abb() {
    cout << "Opciones disponibles: " << endl;
    cout << "1. Consultar por un aeropuerto en particular." << endl;
    cout << "2. Dar de alta un nuevo aeropuerto." << endl;
    cout << "3. Dar de baja un aeropuerto." << endl;
    cout << "4. Mostrar todos los aeropuertos" <<endl;
    cout << "5. Mostrar todos los codigos IATA" <<endl;
    cout << "6. Salir." << endl;
};

void Menu::opcion_abb(int opcion) {
    switch (opcion) {
        case 1: {
            string iata = solicitar_clave();
            if(ABB->buscar(iata))
                ABB -> consultar(iata) -> mostrar_datos();
            else
                cout << "El código IATA ingresado no es correcto." << endl;
        };
        /*case 2: {
            string iata = solicitar_clave();
            if(ABB->buscar(iata))
                Aeropuerto* aeropuerto = new Aeropuerto(string iata, string aeropuerto, string ciudad, string pais, float superficie, unsigned int cant_terminales, unsigned int d_nacionales, unsigned int d_internacionales);
                ABB ->insertar(iata, );
        };*/
        case 3:{
            string iata = solicitar_clave();
            if(ABB->buscar(iata))
            {
                ABB->borrar(iata);
                cout << "El aeropuerto fue borrado exitosamente" << endl;
            }
            else
                cout << "El codigo IATA ingresoda no es correcto." << endl;
        }
        case 4:{
            ABB->imprimir_en_orden();
        }
    }
};

string Menu::solicitar_clave() {
    string iata;
    cout << "Ingrese el codigo IATA que desea utilizar: ";
    cin >> iata;
    return iata;
}



