#ifndef TP5_ALGO2_VALIDACION_H
#define TP5_ALGO2_VALIDACION_H

#include <string>

class Validacion{
    public:
        //CONSTRUCTOR SIN PARAMETROS
        Validacion();

        //DESTRUCTOR
        ~Validacion();

        int opcion_entre_rangos(int min, int max);

        int pedir_entero(std::string mensaje);

        std::string pedir_string(std::string mensaje);
};

#endif //TP5_ALGO2_VALIDACION_H
