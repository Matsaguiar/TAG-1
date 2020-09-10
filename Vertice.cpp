#include "Vertice.h"

 void Obter_tamanho(int *Va, int *Vb, int *Vc, FILE* fd){

    rewind(fd);                     // Move o ponteiro para o começo do arquivo;
    
    while(fgetc(fd) == '%'){        //Pula os comentarios;
        fscanf(fd, "%*[^\n]\n");
    }

    fseek(fd, -1, SEEK_CUR);
        
    fscanf(fd, "%d %d %d", Va, Vb, Vc);

}

vector<vector<int>> Obter_dados(int Va, int Vb, int N, FILE* fd){
    
    vector<vector<int>> Grafo(Va);

    for(int i = 0; i < N; i++){    //Faz a leitura dos vertices e seus respectivos elos;
        int a, b;
        fscanf(fd, "%d %d", &a, &b);
        Grafo[a-1].push_back(b);
        Grafo[b-1].push_back(a);
    }
    
    return Grafo;
}

void Imprimir_grafo(vector<vector<int>> Grafo){
    cout << "Vertices: " << endl;
    for(int i = 0; i < 62; i++){
        cout << i+1 << " - ";     //Imprime os vertices;
        /* for(int j = 0; j < Grafo[i].size(); j++){
            printf("%d ", Grafo[i][j]);
        } */ 
                                //Imprime o grau de cada vertice;
        cout << "Grau: " << Grafo[i].size();
        cout << endl;
    }
}
