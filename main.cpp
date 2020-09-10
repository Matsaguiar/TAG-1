#include "Vertice.h"

int main(){
    // S_Grafo* Valores;
    // cout << &Grafo << endl;
    // cout << &Valores << endl;
    
    int Va, Vb, Vc;
    Obter_tamanho(&Va, &Vb, &Vc);
    vector<vector<int>> Grafo(Va+1);

    Grafo = Obter_dados(Va, Vb, Vc);
    
    Imprimir_grafo(Grafo);
    return 0;
}