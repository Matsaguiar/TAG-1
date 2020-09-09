#include "Vertice.h"

using namespace std;

vector<vector<int>> Obter_dados(vector<vector<int>>Grafo, S_Grafo Valores){
    FILE* fd;

    char file[] = "soc-dolphins.mtx";
    fd = fopen(file, "rt");

    if(fd == NULL){
        printf("Erro abrir arquivo\n");
        return Grafo;
    }

    rewind(fd); // Move para o começo do arquivo;

    while(fgetc(fd) == '%'){ //Pula os comentarios;
        fscanf(fd, "%*[^\n]\n");
        cout << '1';
    }
    
    fseek(fd, -1, SEEK_CUR);

    int a, b, N;
    fscanf(fd, "%d %d %d", &a, &b, &N);
    Valores.origem = a;
    Valores.destino = b;
    Valores.quantidade = N;

    for(int i = 0; i < N; i++){
        int Vori, Vdes;
        fscanf(fd, "%d %d", &Vori, &Vdes);
        Grafo[Vori].push_back(Vdes);
        Grafo[Vdes].push_back(Vori);
    }
    
    fclose(fd);
    return Grafo;
}

void Imprimir_grafo(vector<vector<int>>Grafo){
    for(int i = 0; i < Grafo.size(); i++){
        for(int j = 0; j < Grafo[i].size(); j++){
            cout << Grafo[i][j];
        } 
        cout << endl;
    }
}
