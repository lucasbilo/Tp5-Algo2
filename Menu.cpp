#include <iostream>
#include <string>
#include "Menu.h"

const int PESO_HORAS = 1;
const int PESO_PRECIO = 2;

using namespace std;

Menu::Menu(Diccionario<Aeropuerto> * ABB, Grafo* grafo){
    this -> ABB = ABB;
    this -> grafo = grafo;
}

void Menu::menu_completo() {
    int opcion, eleccion1, eleccion2;
    do {
        cout << endl << endl << "\n---------------------MENU COMPLETO------------------------" << endl;
        cout << "\nOpciones disponibles: \n" << endl;
        cout << "1. Menu aeropuertos." << endl;
        cout << "2. Menu vuelos." << endl;
        cout << "3. Salir." << endl;
        opcion = validaciones.opcion_entre_rangos(1, 3);
        if(opcion == 1){
            do{
                menu_abb();
                eleccion1 = validaciones.opcion_entre_rangos(1, 6);
                opcion_abb(eleccion1);
            }while(eleccion1 != 6);
        }
        else if (opcion == 2){
            do{
                menu_grafo();
                eleccion2 = validaciones.opcion_entre_rangos(1,3);
                opcion_grafo(eleccion2);
            }while(eleccion2 != 3);
        }
    }while(opcion != 3);
}

void Menu::menu_grafo() {
    cout << endl << endl << "\n---------------------MENU GRAFO------------------------" << endl;
    cout << "\nOpciones disponibles: \n" << endl;
    cout << "1. Consultar vuelo minimo por tiempo." << endl;
    cout << "2. Consultar vuelo minimo por precio." << endl;
    cout << "3. Salir." << endl;
}


void Menu::menu_abb() {
    cout << endl << endl << "\n----------------------MENU ABB-------------------------" << endl;
    cout << "\nOpciones disponibles: \n" << endl;
    cout << "1. Consultar por un aeropuerto en particular." << endl;
    cout << "2. Dar de alta un nuevo aeropuerto." << endl;
    cout << "3. Dar de baja un aeropuerto." << endl;
    cout << "4. Mostrar todos los aeropuertos (recorrido in orden)" <<endl;
    cout << "5. Mostrar todos los codigos IATA (recorrido por anchura)" <<endl;
    cout << "6. Salir." << endl;
};

void Menu::opcion_grafo(int opcion) {
    switch (opcion){
        case 1: {
            grafo_minimo(PESO_HORAS); break;
        }
        case 2: {
            grafo_minimo(PESO_PRECIO); break;
        }
    }
}

void Menu::grafo_minimo(int tipo_de_peso) {
    string iata_partida = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA de partida: "));
    string iata_destino = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA de destino: "));
    while (iata_partida == iata_destino){
        cout << "Los codigos IATA ingresados son iguales. Por favor, introduzca codigos IATA distintos. " <<endl;
        iata_partida = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA de partida: "));
        iata_destino = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA de destino: "));
    }
    grafo->imprimir_camino_minimo(iata_partida,iata_destino,tipo_de_peso);
}

void Menu::opcion_abb(int opcion) {
    switch (opcion) {
        case 1: {
            cout << "\n---CONSULTAR AEROPUERTO---\n" << endl;
            consultar_aeropuerto(); break;
        }
        case 2: {
            cout << "\n---ALTA DE UN AEROPUERTO---\n" << endl;
            alta_aeropuerto(); break;
        }
        case 3:{
            cout << "\n---BAJA DE UN AEROPUERTO---\n" << endl;
            baja_aeropuerto(); break;
        }
        case 4:{
            cout << "\n---IMPRESION EN ORDEN---\n" << endl;
            ABB->imprimir_en_orden(); break;
        }
        case 5:{
            cout << "\n---IMPRESION EN ANCHURA---\n" << endl;
            ABB->imprimir_en_anchura(); break;
        }
    }
};

void Menu::alta_aeropuerto()
{
    string iata = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA: "));
    while (ABB -> buscar(iata)){
        cout << "El codigo IATA ingresado ya pertenece a un aeropuerto." << endl;
        iata = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA: "));
    }
    string n_aeropuerto = validaciones.pedir_string("\nIngrese el nombre del aeropuerto: ");
    string ciudad = validaciones.pedir_string("\nIngrese el nombre de la ciudad: ");
    string pais = validaciones.pedir_string("\nIngrese el nombre del pais: ");
    int superficie = validaciones.pedir_entero("\nIngrese la superficie: ");
    int cant_terminales = validaciones.pedir_entero("\nIngrese la cantidad de terminales: ");
    int d_nacionales = validaciones.pedir_entero("\nIngrese la cantidad de destinos nacionales: ");
    int d_internacionales = validaciones.pedir_entero("\nIngrese la cantidad de destinos internacionales: ");
    Aeropuerto *aeropuerto = new Aeropuerto(iata, n_aeropuerto, ciudad, pais, superficie, cant_terminales,
                                                d_nacionales, d_internacionales);
    ABB->insertar(iata, aeropuerto);
}

void Menu::baja_aeropuerto()
{
    string iata = validaciones.pasar_a_mayuscula(validaciones.pedir_string("\nIngrese el codigo IATA: "));
    if(ABB->buscar(iata))
    {
        ABB->borrar(iata);
        cout << "\nEl aeropuerto " << iata << " fue borrado exitosamente" << endl;
    }
    else
        cout << "\nEl codigo IATA ingresado no es correcto." << endl;
}

void Menu::consultar_aeropuerto()
{
    string iata = validaciones.pasar_a_mayuscula(validaciones.pedir_string("Ingrese el codigo IATA: "));
    
    if(ABB->buscar(iata))
        ABB -> consultar(iata) -> mostrar_datos();
    else
        cout << "\nEl codigo IATA ingresado no es correcto." << endl;
}



