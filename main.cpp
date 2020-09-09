#include "Vertice.h"

using namespace std;

int main(){
    S_Grafo* Valores;
    vector<vector<int>> Grafo;

    Obter_dados(Grafo, Valores);

    Imprimir_grafo(Grafo);
    return 0;
}