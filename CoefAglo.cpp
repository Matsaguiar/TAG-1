#include <iostream>
#include <stdio.h>
#include <vector>
//#include "CoefAglo.h"

using namespace std;


void Obtem_coef_vertice(vector<vector<int>> Grafo, int tamCoef){
    
    vector<double> coefAglomeracao(tamCoef);

    double possivelTriang;
    double coefVertice;
    double triangulos;

    for(int i = 0; i < 7; i++){
        cout << "i = " << i << endl;
        if(Grafo[i].size() > 1){ //Verifica se ha vizinhos para formar possiveis triangulos;            
            triangulos = 0;
            possivelTriang = (Grafo[i].size()*(Grafo[i].size()-1))/2;

            for(int j = 0; j < Grafo[i].size()-1; j++){
                cout << "ENTROU2" << endl;
                
                if(Grafo[i].size() > 1 && Grafo[i+1].size() > 1){
                    int inf = Grafo[i][j+1] - 1;

                    for(int k = 0; k < Grafo[inf].size(); k++){
                        cout << " Grafo[i][j]= " << Grafo[i][j] << " Grafo[i][j+1] = " << Grafo[i][j+1] << endl;
                        printf("Inf: %d  - Grafo[%d][%d] =  %d = Grafo[%d][%d] = %d\n", inf, i, j, Grafo[i][j], inf, k, Grafo[inf][k]);    
                        if(Grafo[i][j] == Grafo[inf][k]){
                            cout << "ENTROU5" << endl;
                            //triangulos = (triangulos + 1)/2; 
                            triangulos++;
                        }                
                    }
                }else
                    cout << "Nao entrou" << endl;
            }
            //triangulos = triangulos/3;
            cout << triangulos << endl << "PosTri " << possivelTriang << endl;;
            coefVertice = triangulos/possivelTriang;
            cout << coefVertice << endl;
            coefAglomeracao[i] = coefVertice;
            //cout << coefAglomeracao[i] << endl;
        }
        /* else{
            coefAglomeracao[i] = 0;
            cout << "Coef = " << coefAglomeracao[i] << endl;
        } */
    }
    
    cout << "Coeficientes: " << endl;
    /* for(int i = 0; i < 7; i++){
        cout << i+1 << " - ";     //Imprime os vertices;                
        cout << "Coef: " << coefAglomeracao[i]; 
        cout << endl;
    } */
}

int main(){
    vector<vector<int>> Grafo(7);

    FILE* fd;                           //Cria o ponteiro do arquivo;

    char file[] = "soc.txt";   //Abre o arquivo soc-dolphins.mtx;
    fd = fopen(file, "r");

    if(fd == NULL){                     //Verifica se o arquivo abriu com sucesso;
        cout << "Erro abrir arquivo" << endl;
        return 0;
    }

    for(int i = 0; i < 7; i++){    //Faz a leitura dos vertices e seus respectivos elos;
        int a, b;
        fscanf(fd, "%d %d", &a, &b);
        Grafo[a-1].push_back(b);
        Grafo[b-1].push_back(a);
    }   
    /* cout << "Vertices: " << endl;
    for(int i = 0; i < 7; i++){
        cout << i+1 << " - ";     //Imprime os vertices;
        for(int j = 0; j < Grafo[i].size(); j++){
            printf("%d ", Grafo[i][j]);
        }                   
        cout << "Grau: " << Grafo[i].size(); //Imprime o grau de cada vertice;
        cout << endl;
    } */
    Obtem_coef_vertice(Grafo, 7);
    
    return 0;
}
