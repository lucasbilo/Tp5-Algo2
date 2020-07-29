#include "Grafo.h"

using namespace std;

const double INFINITO = 1e100;
const int POSICION_INVALIDA = -1;

//CONSTRUCTOR
Grafo::Grafo(){
    cantidad_vertices = 0;
    vertices = new Diccionario<Vertice>;
}

//DESTRUCTOR
Grafo::~Grafo(){
    delete vertices;
}

//Agrega la arista al conjunto de aristas del vertice de salida.
void Grafo::agregar_arista(string origen, string destino, Lista<double>* pesos){
    Vertice* salida = vertices->consultar(origen);
    if(salida == NULL)
        salida = agregar_vertice(origen);
    Vertice* llegada = vertices->consultar(destino);
    if(llegada == NULL)
        llegada = agregar_vertice(destino);
    Arista* arista = new Arista(salida, llegada, pesos);
    salida->agregar_arista(arista);
}

//Agrega un vertice vacio al grafo.
Vertice* Grafo::agregar_vertice(string clave_vertice){
    Vertice* aux = new Vertice(clave_vertice);
    vertices->insertar(clave_vertice, aux);
    cantidad_vertices++;
    return vertices->consultar(clave_vertice);
}



void Grafo::imprimir_caminos(Vertice* salida, Vertice* llegada, Lista<Arista*>* ultimo_visitado[], int tope){
    //que se impriman los caminos que guarda ultimo_visitado.
}

void Grafo::liberar_memoria_visitados(Lista<Arista*>* ultimo_visitado[], int tope){
    for(int i = 0; i < tope; i++){
        if(ultimo_visitado[i] != NULL)
            delete ultimo_visitado[i];
    }
}


void Grafo::imprimir_camino_minimo(string origen, string destino, int posicion_peso){
    Vertice* salida = vertices->consultar(origen);
    Vertice* llegada = vertices->consultar(destino);
    if( salida != NULL && llegada != NULL) {
        Lista<Arista*>* ultimo_visitado[cantidad_vertices -1];
        Vertice* vector_vertices[cantidad_vertices - 1];
        int tope = 0;
        buscar_camino_min(salida, llegada, posicion_peso, ultimo_visitado, vector_vertices, tope);
        imprimir_caminos(salida, llegada, ultimo_visitado, tope);
        liberar_memoria_visitados(ultimo_visitado, tope);
    }else{
        cout << "Ocurrio un problema. Los vertices pedidos no se pudieron encontrar" << endl;
    }
}


void Grafo::buscar_camino_min(Vertice* origen, Vertice* destino, int posicion_peso, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int &tope){
    double distancia[cantidad_vertices -1];
    bool vistos[cantidad_vertices -1];
    double camino_min_encontrado = INFINITO;
    Vertice* vertice_actual;
    string destino_actual;
    Arista* arista_actual = origen->encontrar_min(destino_actual);

    while(arista_actual != NULL){
        generar_posicion(arista_actual, vector_vertices, distancia, posicion_peso, ultimo_visitado, vistos, tope);
        arista_actual = origen->siguiente_arista(destino_actual);
    }

    int pos_minima_distancia = buscar_pos_min(distancia, vistos, tope);
    while(!todos_visitados(vistos, tope) && (camino_min_encontrado > distancia[pos_minima_distancia]) ){
        vistos[pos_minima_distancia] = true;
        vertice_actual = vector_vertices[pos_minima_distancia];
        arista_actual = vertice_actual->encontrar_min(destino_actual);
        int posicion_actual = encontrar_posicion(arista_actual->obtener_destino(), vector_vertices, tope);
        if(posicion_actual == POSICION_INVALIDA)
            posicion_actual = generar_posicion(arista_actual, vector_vertices, distancia, posicion_peso, ultimo_visitado, vistos, tope);
        int i = 0;
        while(arista_actual != NULL){
            cout<<i<<" "<<endl;i++; //no me estaria funcando bien
            if(distancia[posicion_actual] > distancia[pos_minima_distancia] + arista_actual->obtener_peso(posicion_peso)){
                distancia[posicion_actual] = distancia[pos_minima_distancia] + arista_actual->obtener_peso(posicion_peso);
                if(ultimo_visitado[posicion_actual] != NULL)
                    ultimo_visitado[posicion_actual]->borrar_todo();
                else
                    ultimo_visitado[posicion_actual] = new Lista<Arista*>;
                Arista** arista_agregar = new Arista*(arista_actual);
                ultimo_visitado[posicion_actual]->insertar(arista_agregar);

            }else if(distancia[posicion_actual] == distancia[pos_minima_distancia] + arista_actual->obtener_peso(posicion_peso)){
                Arista** arista_agregar = new Arista*(arista_actual);
                ultimo_visitado[posicion_actual]->insertar(arista_agregar);
            }
            arista_actual = origen->siguiente_arista(destino_actual);
        }
    }
}

int Grafo::buscar_pos_min(double distancia[], bool vistos[], int tope){
    int pos_minimo;
    double minimo = INFINITO;
    for(int i = 0; i < tope; i++){
        if(!vistos[i])
            if(distancia[i] < minimo) {
                pos_minimo = i;
                minimo = distancia[i];
            }
    }
    return pos_minimo;
}

bool Grafo::todos_visitados(bool vistos[], int tope){
    int i = 0;
    bool todos_visitados = true;
    while(i < tope && todos_visitados){
        if(!vistos[i])
            todos_visitados = false;
        i++;
    }
    return todos_visitados;
}



int Grafo::encontrar_posicion(Vertice* vertice, Vertice* vector_vertices[], int tope){
    int pos = 0;
    bool encontrado = false;
    while(pos < tope && !encontrado){
        if(vector_vertices[pos] == vertice)
            encontrado = true;
        else
            pos++;
    }
    if(!encontrado)
        return POSICION_INVALIDA;
    return pos;
}

int Grafo::generar_posicion(Arista* arista_actual, Vertice* vector_vertices[], double distancia[], int posicion_peso,
        Lista<Arista*>* ultimo_visitado[], bool vistos[], int &tope){

    vector_vertices[tope] = arista_actual->obtener_destino();
    distancia[tope] = arista_actual->obtener_peso(posicion_peso);
    ultimo_visitado[tope] = new Lista<Arista*>;
    Arista** arista_agregar = new Arista*(arista_actual);
    ultimo_visitado[tope]->insertar(arista_agregar);
    vistos[tope] = false;
    tope++;
    return (tope - 1);
}


