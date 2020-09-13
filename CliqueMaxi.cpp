#include "CliqueMaxi.h"
using namespace std;

vector<vector<int>> maxclique;                          //Onde vai guardar os cliques maximais

vector<int> Inserir_sem_repetir(vector<int> V, int  N){ // Para inserir o N no vetor
    if (V.empty()){                                     //Se for vazia, nao tem repetidos
        V.push_back(N);
        return V;
    }

    sort(V.begin(), V.end());                           //Ordena para usar o Lower_bound

    if(N > *V.end()){                                   //Se for maior que o final, nao esta contido
        V.push_back(N);
        return V;
    }
    
    auto aux = lower_bound(V.begin(), V.end(), N);      //Verifica se o numero esta presente por busca binaria
    if (*aux != N){                                     //Se nao estiver, inseri o numero no final
        V.push_back(N);
        sort(V.begin(), V.end() );
    }
    return V;
}

vector<int> Subno (vector<int> V, int N){
    if( V.empty() )
        return V;

    sort(V.begin(), V.end());
    auto aux = lower_bound( V.begin(), V.end(), N );
    if (*aux == N){
        V.erase(aux);
    }
    sort(V.begin(), V.end() );
    return V;
}

vector<int> InterN (vector<int> V, int N, vector<vector<int>> Grafo){
    vector<int> vizinhos, aux;
    int pos;

    if( V.empty() ){
        return V;
    }

    for( int i=0; i < Grafo[N-1].size(); i++){
        pos = Grafo[N-1][i];
        vizinhos.push_back(pos);
    }

    for(int i=0; i < V.size(); i++){
        for(int j=0; j < vizinhos.size(); j++){
            if(vizinhos[j] == V[i]){
                aux.push_back(vizinhos[j]);
            }
        }
    }
    sort (aux.begin(), aux.end());
    return aux;
}

void bronKerbosch(vector<int> R, vector<int> P, vector<int> X, vector<vector<int>> Grafo){
    vector<int> Paux, Xaux;
    int cont;
    if((P.empty()) && (X.empty())){ //Se P e X estão vazios, siginifica que R conte, um clique maximal
        sort(R.begin(), R.end());
        cont = 0;
        for(int i=0; i < maxclique.size() ; i++){
            if(maxclique[i] == R){
                cont++;
            }
        }
        if (cont == 0)
            maxclique.push_back(R);
    }
    Paux = P;
    Xaux = X;
    for(int i=0; i < P.size(); i++){ //Para cada nó no vetor P
        bronKerbosch(Inserir_sem_repetir(R,Paux[i]), InterN(P,Paux[i], Grafo), InterN(X,Paux[i], Grafo), Grafo);
        Paux = Subno(P, Paux[i]);
        Xaux = Inserir_sem_repetir(X, Paux[i]);
    }
    P = Paux;
    X = Xaux;
}

void Imprimir_bronKerbosch(){
    cout << "Tamanho Clique Maximo = " << maxclique.size() << endl;
    cout << endl;
    for(int i = 0; i < maxclique.size(); i++){
        cout << "Clique " << i + 1 << " - ";
        for(int j = 0; j < maxclique[i].size(); j++){
            cout << maxclique[i][j] << " ";
        }
        cout << endl;
    }
}