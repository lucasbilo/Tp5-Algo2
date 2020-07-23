#ifndef TP5_ALGO2_VUELO_H
#define TP5_ALGO2_VUELO_H

#include <string>

class Vuelo{

    private:
        std::string cod_partida;
        std::string cod_destino;
        int costo_vuelo;
        float horas_vuelo;

    public:
        //CONSTRUCTOR
        // POST: Inicializa a Vuelo, se asigna cada parametro al atributo correspondiente.
        Vuelo(std::string cod_partida, std::string cod_destino, int costo, float horas);

        //DESTRUCTOR
        ~Vuelo();

        //void mostrar();

        // POST: Devuelve un string que es el atributo cod_partida
        std::string obtener_cod_partida();

        // POST: Devuelve un string que es el atributo cod_destino
        std::string obtener_cod_destino();

        // POST: Devuelve un entero que es el atributo costo_vuelo
        int obtener_costo();

        // POST: Devuelve un flotante que es el atributo horas_vuelo
        float obtener_horas();

};

#endif //TP5_ALGO2_VUELO_H
