#include "Validacion.h"
#include <iostream>

using namespace std;

int Validacion::opcion_abb(int opcion) {
    int numero;
    cout << "Ingrese un numero entre el 1 y 6: ";
    cin >> numero;
    while (numero < 1 || numero > 6)
    {
        cout << "El numero ingresado esta fuera de rango, vuelva a ingresar un numero: ";
        cin >> numero
    }
    return numero;
}