#include "Grafo.h"

using namespace std;

const double INFINITO = 1e100;
const int POSICION_INVALIDA = -1;
const int POSICION_SALIDA = 0;

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











void Grafo::imprimir_caminos(Vertice* salida, Vertice* llegada, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int tope, int posicion_peso){
    Lista<bool>* recorridos_visitados[tope];
    inicializar_recorridos(recorridos_visitados, ultimo_visitado, tope);
    int pos, pos_lista = 1, numero_opcion = 1;
    int pos_llegada = encontrar_posicion(llegada, vector_vertices, tope);
    Lista<Arista*>* camino = new Lista<Arista*>;

    Vertice* destino_parcial = llegada;

    while(!todos_caminos_impresos(recorridos_visitados, ultimo_visitado, vector_vertices, tope, llegada)){
        
        pos = encontrar_posicion(destino_parcial, vector_vertices, tope);
        if(pos != POSICION_SALIDA){
            if(!visitado(recorridos_visitados[pos], pos_lista)){ // avanza en el camino
                agregar_arista(camino, ultimo_visitado[pos], pos_lista);
                visitar_arista(recorridos_visitados[pos],pos_lista);
                destino_parcial = (*camino->obtener_dato(1))->obtener_origen();
            }else{ //retrocede en el camino
                desvisitar_aristas(recorridos_visitados[pos]);
                destino_parcial = (*camino->obtener_dato(1))->obtener_destino();
                camino->eliminar_dato(1);
            }
        }else{
            imprimir_camino(camino, posicion_peso, numero_opcion);
            destino_parcial = (*camino->obtener_dato(1))->obtener_destino();
            camino->eliminar_dato(1);
        }
    }
    imprimir_camino(camino, posicion_peso, numero_opcion);
    liberar_memoria_visitados(recorridos_visitados, tope);
    delete camino;
}



bool Grafo::todos_caminos_impresos(Lista<bool>* recorridos_visitados[], Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int tope, Vertice* llegada){
    
    int pos_actual = encontrar_posicion(llegada, vector_vertices, tope);
    int pos_lista = recorridos_visitados[pos_actual]->obtener_tam();
    Arista* arista_actual = *(ultimo_visitado[pos_actual]->obtener_dato(pos_lista));
    
    bool todos_visitados = true;

    while(todos_visitados && pos_actual != POSICION_SALIDA){
        if(*(recorridos_visitados[pos_actual]->obtener_dato(pos_lista))){
            pos_actual = encontrar_posicion(arista_actual->obtener_origen(), vector_vertices, tope);
            if(pos_actual != POSICION_SALIDA){
                pos_lista = recorridos_visitados[pos_actual]->obtener_tam();
                arista_actual = *(ultimo_visitado[pos_actual]->obtener_dato(pos_lista));
            }
        }
        else
            todos_visitados = false;      
    }

    return todos_visitados;
}



void Grafo::imprimir_camino(Lista<Arista*>* camino, int pos_peso, int &numero_opcion){
    Arista* arista_actual;
    cout << "\n\nOpcion de camino numero " << numero_opcion << "\n\n";
    for( int i = 1; i <= camino->obtener_tam(); i++){
        arista_actual = *camino->obtener_dato(i);
        cout << arista_actual->obtener_cod_partida() << " -> " << arista_actual->obtener_cod_destino() <<
        " COSTO: " << arista_actual->obtener_peso(pos_peso) << endl;
    }
    cout << "\n\n";
    numero_opcion++;
}



/*
 * POST: Modifica todos los elementos de la lista a false.
 * */
void Grafo::desvisitar_aristas(Lista<bool>* aristas_visitadas){
    for(int i = 1; i <= aristas_visitadas->obtener_tam() ; i++ )
        *(aristas_visitadas->obtener_dato(i)) = false;
}

/*
 * POST: Modifica el primer elemento de la lista que sea false a true.
 */
void Grafo::visitar_arista(Lista<bool>* aristas_visitadas, int pos_lista){
    *(aristas_visitadas->obtener_dato(pos_lista)) = true;
}



/*
 * PRE: pos_lista pertenece a los limites de la lista de ultimo_visitado.
 * POST: Agrega la arista que se encuentra en la posicion de ultimo_visitado en el camino.
 * */
void Grafo::agregar_arista(Lista<Arista*>* camino, Lista<Arista*>* ultimo_visitado, int pos_lista){
    Arista** arista_agregar = new Arista*(*(ultimo_visitado->obtener_dato(pos_lista)));
    camino->insertar(arista_agregar);
}


/*
 * PRE: La Lista esta bien inicializada y el puntero no apunta a NULL.
 * POST: Si todos los elementos de la lista tienen TRUE, devuelve true. Sino, devuelve FALSE.
 */
bool Grafo::visitado(Lista<bool>* aristas_visitadas, int &pos_lista){
    bool todas_aristas_visitadas = true;
    int i = 1;
    while(todas_aristas_visitadas && i <= aristas_visitadas->obtener_tam()){
        if( ! (*(aristas_visitadas->obtener_dato(i)))){
            todas_aristas_visitadas = false;
            pos_lista = i;
        }
        i++;
    }
    return todas_aristas_visitadas;
}

/*
 * PRE: ----
 * POST: Crea una relacion 1 a 1 entre el vector de listas de recorridos_visitados y ultimo_visitado,
 *       e inicializa cada atributo de las nueva lista de recorridos en false.
 */
void Grafo::inicializar_recorridos(Lista<bool>* recorridos_visitados[], Lista<Arista*>* ultimo_visitado[], int tope){
    for(int i = 0; i < tope; i++){
        if(ultimo_visitado[i] != NULL){
            recorridos_visitados[i] = new Lista<bool>;
            for(int j = 1; j <= ultimo_visitado[i]->obtener_tam() ; j++){
                bool* visitado = new bool(false);
                recorridos_visitados[i]->insertar(visitado);
            }
        }
    }
}

































void Grafo::imprimir_caminos(Vertice* salida, Vertice* llegada, Vertice* destino_parcial, Lista<Arista*>* ultimo_visitado[],
        Vertice* vector_vertices[], int tope, bool &terminado){

    int pos = encontrar_posicion(destino_parcial, vector_vertices, tope);
    if(pos > 0) {
        Arista *actual = (*(ultimo_visitado[pos]->obtener_dato(1)));
        imprimir_caminos(salida, llegada, actual->obtener_origen(), ultimo_visitado, vector_vertices, tope, terminado);
        cout << actual->obtener_cod_partida() << " -> " << actual->obtener_cod_destino() << endl;

        if (!terminado && (llegada != destino_parcial) && ultimo_visitado[pos]->obtener_tam() > 1) {
            terminado = true;
            ultimo_visitado[pos]->eliminar_dato(1);
        }
    }

    if( llegada == destino_parcial){
        if(terminado){
            terminado = false;
            imprimir_caminos(salida, llegada, llegada, ultimo_visitado, vector_vertices, tope, terminado);
        }else{
            if( ultimo_visitado[pos]->obtener_tam() > 1 ){
                ultimo_visitado[pos]->eliminar_dato(1);
                imprimir_caminos(salida, llegada, llegada, ultimo_visitado, vector_vertices, tope, terminado);
            }
        }
    }
}


void Grafo::liberar_memoria_visitados(Lista<bool>* ultimo_visitado[], int tope){
    for(int i = 1; i < tope; i++){
        if(ultimo_visitado[i] != NULL)
            delete ultimo_visitado[i];
    }
}

void Grafo::liberar_memoria_visitados(Lista<Arista*>* ultimo_visitado[], int tope){
    for(int i = 1; i < tope; i++){
        if(ultimo_visitado[i] != NULL)
            delete ultimo_visitado[i];
    }
}


void Grafo::imprimir_camino_minimo(string origen, string destino, int posicion_peso){
    Vertice* salida = vertices->consultar(origen);
    Vertice* llegada = vertices->consultar(destino);
    if( salida != NULL && llegada != NULL) {
        Lista<Arista*>* ultimo_visitado[cantidad_vertices];
        Vertice* vector_vertices[cantidad_vertices];
        int tope = 0;
        buscar_camino_min(salida, llegada, posicion_peso, ultimo_visitado, vector_vertices, tope);
        int pos_llegada = encontrar_posicion(llegada, vector_vertices, tope);
        if(pos_llegada != POSICION_INVALIDA) {
            //bool termino_imprimir;
            //imprimir_caminos(salida, llegada, llegada, ultimo_visitado, vector_vertices, tope, termino_imprimir);
            imprimir_caminos(salida, llegada, ultimo_visitado, vector_vertices, tope, posicion_peso);
        }
        else {
            cout << "No se encontraron caminos que satisfagan los pedido" << endl;
        }

        liberar_memoria_visitados(ultimo_visitado, tope);
    }else{
        cout << "Ocurrio un problema. Los vertices pedidos no se pudieron encontrar" << endl;
    }
}


void Grafo::buscar_camino_min(Vertice* origen, Vertice* destino, int posicion_peso, Lista<Arista*>* ultimo_visitado[], Vertice* vector_vertices[], int &tope){
    double distancia[cantidad_vertices];
    bool vistos[cantidad_vertices];
    Vertice* vertice_actual;
    string destino_actual;
    Arista* arista_actual = origen->encontrar_min(destino_actual);

    distancia[0] = 0;
    vistos[0] = true;
    vector_vertices[0] = origen;
    tope++;

    while(arista_actual != NULL){
        generar_posicion(arista_actual, vector_vertices, distancia, posicion_peso, ultimo_visitado, vistos, tope);
        arista_actual = origen->siguiente_arista(destino_actual);
    }


    int pos_minima_distancia = buscar_pos_min(distancia, vistos, tope);
    while(!todos_visitados(vistos, tope) && (pos_minima_distancia != encontrar_posicion(destino, vector_vertices, tope))){
        vistos[pos_minima_distancia] = true;
        vertice_actual = vector_vertices[pos_minima_distancia];
        arista_actual = vertice_actual->encontrar_min(destino_actual);
        int posicion_dest_actual;

        while(arista_actual != NULL){
            posicion_dest_actual = encontrar_posicion(arista_actual->obtener_destino(), vector_vertices, tope);
            if(posicion_dest_actual == POSICION_INVALIDA) {
                posicion_dest_actual = generar_posicion(arista_actual, vector_vertices, distancia, posicion_peso, ultimo_visitado, vistos, tope);
                distancia[posicion_dest_actual] += distancia[pos_minima_distancia];
            }else {
                if (distancia[posicion_dest_actual] > distancia[pos_minima_distancia] + arista_actual->obtener_peso(posicion_peso)) {
                    distancia[posicion_dest_actual] = distancia[pos_minima_distancia] + arista_actual->obtener_peso(posicion_peso);
                    ultimo_visitado[posicion_dest_actual]->borrar_todo();
                    Arista** arista_agregar = new Arista *(arista_actual);
                    ultimo_visitado[posicion_dest_actual]->insertar(arista_agregar);

                } else if (distancia[posicion_dest_actual] == distancia[pos_minima_distancia] + arista_actual->obtener_peso(posicion_peso)) {
                    Arista **arista_agregar = new Arista *(arista_actual);
                    ultimo_visitado[posicion_dest_actual]->insertar(arista_agregar);
                }
            }
            arista_actual = vertice_actual->siguiente_arista(destino_actual);
        }
        pos_minima_distancia = buscar_pos_min(distancia, vistos, tope);
    }
}

int Grafo::buscar_pos_min(double distancia[], bool vistos[], int tope){
    int pos_minimo;
    double minimo = INFINITO;
    for(int i = 1; i < tope; i++){
        if(!vistos[i])
            if(distancia[i] < minimo) {
                pos_minimo = i;
                minimo = distancia[i];
            }
    }
    return pos_minimo;
}

bool Grafo::todos_visitados(bool vistos[], int tope){
    int i = 1;
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

