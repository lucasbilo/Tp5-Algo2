#ifndef TP5_ALGO2_VALIDACION_H
#define TP5_ALGO2_VALIDACION_H

#include <string>

class Validacion{
    public:
        //CONSTRUCTOR SIN PARAMETROS
        Validacion(){}

        //DESTRUCTOR
        ~Validacion(){}
    
        //POST: Devuelve el string transformado a int. Solo si string es un digito.
        int string_a_int(std::string palabra);
    
        //POST: Evalúa si la opcion ingresada es un digito y devuelve true si lo es. False si no.
        bool es_digito(std::string palabra);
        
        //POST: Evalua si la opcion se encuentra dentro del minimo y maximo pasados por parametros, y si es digito.
        int opcion_entre_rangos(int min, int max);
        
        //POST: Pide el ingreso de un numero al usuario y devuelve la opcion ingresada.
        int pedir_entero(std::string mensaje);

        //POST: Pide el ingreso de una palabra al usuario y devuelve la opcion ingresada.
        std::string pedir_string(std::string mensaje);
    
        //POST: Pasa el string ingresado a mayuscula y devuelve el string.
        std::string pasar_a_mayuscula(std::string iata);
};

#endif //TP5_ALGO2_VALIDACION_H
