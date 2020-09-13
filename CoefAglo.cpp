#include "CoefAglo.h"

using namespace std;

pair<int,double> coefAglomeracao(vector<vector<int>> Grafo, int vert){
    int possiveisTriang = (Grafo[vert-1].size() * (Grafo[vert-1].size() - 1)) / 2;
    double coefVertice = 0;
    double triangulos = 0;

    if(possiveisTriang > 0 && Grafo[vert-1].size() > 1){
        int a = vert;
    
        for(int i = 0; i < Grafo[a-1].size(); i++){   
            int b = Grafo[a-1][i];

            for(int j = 0; j < Grafo[b-1].size(); j++){
                int c = Grafo[b-1][j];

                if(c != a){
                    for(int k = 0; k < Grafo[c-1].size(); k++){                
                        if(Grafo[c-1][k] == a){
                            triangulos++;
                            break;
                        }
                    }
                }
            }
        }
        coefVertice = triangulos/(Grafo[vert-1].size() * (Grafo[vert-1].size() - 1));
    }

    pair<int, double> n = make_pair(vert, coefVertice);

    return n;
}

void Obtem_coef_vertice(vector<vector<int>> Grafo){

    cout << endl << "\tCoeficiente de Aglomeracao dos vertices" << endl << endl;
    for(int i = 1; i <= Grafo.size(); i++){

        pair <int, double> n = coefAglomeracao(Grafo, i);
        printf("Vertice: %d - %.2f\n", n.first, n.second);
    }
}

void Obtem_coef_medio(vector<vector<int>> Grafo){
    double soma = 0.0;

    for(int i = 0; i < Grafo.size(); i++){
        pair<int, double> p = coefAglomeracao(Grafo, i+1);
        soma = soma + p.second;
    }

    printf("Coeficiente Medio de Aglomeracao: %.2f\n", soma/(Grafo.size()));

}
