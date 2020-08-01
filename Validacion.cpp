#include "Validacion.h"
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int Validacion::string_a_int(string palabra)
{
    int numero = atoi(palabra.c_str());
    return numero;
}

bool Validacion::es_digito(string palabra)
{
    bool es_digito = true;
    for (int i = 0; i < palabra.length(); i++)
    {
        if (!(isdigit(palabra[i])))
        {
            es_digito = false;
        }
    }
    return es_digito;
}

int Validacion::opcion_entre_rangos(int min, int max) {
    string numero;
    cout << "Ingrese la opcion que desee realizar: ";
    cin >> numero;
    
    bool digito = es_digito(numero);
    
    int numero_int = string_a_int(numero);
    
    while (numero_int < min || numero_int > max || (!digito))
    {
        cout << "El numero ingresado esta fuera de rango o es invalido, vuelva a ingresar un numero: ";
        cin >> numero;
        digito = es_digito(numero);
        numero_int = string_a_int(numero);
    }
    return numero_int;
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
    for (unsigned int i = 0; i <= palabra.length(); i++)
    {
        if (palabra[i] == ' ')
        {
            palabra[i] = '-';
        }
    }
    return palabra;
}
