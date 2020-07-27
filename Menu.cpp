#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

Menu::Menu(Diccionario<Aeropuerto> * ABB){
    this -> ABB = ABB;
};

void Menu::menu_completo() {
    int opcion, eleccion1, eleccion2;
    do {
        cout << "1. Menu aeropuertos." << endl;
        cout << "2. Menu vuelos." << endl;
        opcion = validaciones.opcion_entre_rangos(1, 3);
        if (opcion == 1) {
            do {
                menu_abb();
                int eleccion1 = validaciones.opcion_entre_rangos(1, 6);
                opcion_abb(eleccion1);
            } while (eleccion1 != 6);
        }
        else
            //ACA FALTA EL CODIGO DEL MENU_GRAFO.

    }while (opcion != 3);
}


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
            consultar_aeropuerto();
        };
        case 2: {
            alta_aeropuerto();
        }
        case 3:{
            baja_aeropuerto();
        }
        case 4:{
            ABB->imprimir_en_orden();
        }
    }
};

void Menu::alta_aeropuerto() {
    string iata = validaciones.pedir_string("Ingrese el codigo IATA: ");
    while (ABB -> buscar(iata)){
        cout << "El código IATA ingresado ya pertenece a un aeropuerto." << endl;
        iata = validaciones.pedir_string("Ingrese el codigo IATA: ");
    }
    string n_aeropuerto = validaciones.pedir_string("Ingrese el nombre del aeropuerto: ");
    string ciudad = validaciones.pedir_string("Ingrese el nombre de la ciudad: ");
    string pais = validaciones.pedir_string("Ingrese el nombre del país: ");
    int superficie = validaciones.pedir_entero("Ingrese la superficie: ");
    int cant_terminales = validaciones.pedir_entero("Ingrese la cantidad de terminales: ");
    int d_nacionales = validaciones.pedir_entero("Ingrese la cantidad de destinos nacionales: ");
    int d_internacionales = validaciones.pedir_entero("Ingrese la cantidad de destinos internacionales: ");
    Aeropuerto *aeropuerto = new Aeropuerto(iata, n_aeropuerto, ciudad, pais, superficie, cant_terminales,
                                                d_nacionales, d_internacionales);
    ABB->insertar(iata, aeropuerto);
}

void Menu::baja_aeropuerto() {
    string iata = validaciones.pedir_string("Ingrese el codigo IATA: ");
    if(ABB->buscar(iata))
    {
        ABB->borrar(iata);
        cout << "El aeropuerto fue borrado exitosamente" << endl;
    }
    else
        cout << "El codigo IATA ingresado no es correcto." << endl;
}

void Menu::consultar_aeropuerto() {
    string iata = validaciones.pedir_string("Ingrese el codigo IATA: ");
    if(ABB->buscar(iata))
        ABB -> consultar(iata) -> mostrar_datos();
    else
        cout << "El código IATA ingresado no es correcto." << endl;
}



