#include "Vertice.h"

vector<vector<int>> Obter_dados(vector<vector<int>>Grafo, S_Grafo* Valores){
    FILE* fd;

    char file[] = "soc-dolphins.mtx";
    fd = fopen(file, "rt");

    if(fd == NULL){
        printf("Erro abrir arquivo\n");
        return Grafo;
    }

    rewind(fd); // Move para o começo do arquivo;

    while(fgetc(fd) == '%'){
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
        int Va, Vb;
        fscanf(fd, "%d %d", &Va, &Vb);
        Grafo[Va].push_back(Vb);
        Grafo[Vb].push_back(Va);
    }
    
    fclose(fd);
    return 0;
}

void Imprimir_grafo(vector<vector<int>> Grafo, S_Vertice Valores){
    for(int i = 0; i < Valores.origem; i++){
        for(int j = 0; j < Valores.destino; j++){
            cout << Grafo[i][j];
        } 
        cout << endl;
    }
}