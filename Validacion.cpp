#include "Validacion.h"
#include <iostream>

using namespace std;

int Validacion::opcion_entre_rangos(int min, int max) {
    int numero;
    cout << "Ingrese un numero entre el" << min << "y " << max << ": ";
    cin >> numero;
    while (numero < min || numero > max)
    {
        cout << "El numero ingresado esta fuera de rango, vuelva a ingresar un numero: ";
        cin >> numero;
    }
    return numero;
}

int Validacion::pedir_entero(std::string mensaje) {
    int numero;
    cout << mensaje;
    cin >> numero;
    return numero;
}

string Validacion::pedir_string(std::string mensaje) {
    string palabra;
    cout << mensaje;
    cin >> palabra;
    return palabra;
}