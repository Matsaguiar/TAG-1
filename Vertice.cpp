#include "Vertice.h"

vector<vector<int>> Obter_dados(vector<vector<int>>Grafo, S_Grafo* Valores){
    FILE* fd;

    char file[] = "soc-dolphins.mtx";
    fd = fopen(file, "r");

    if(fd == NULL){
        printf("Erro abrir arquivo\n");
        return Grafo;
    }
    
    rewind(fd); // Move para o começo do arquivo;
    
    while(fgetc(fd) == '%'){ //Pula os comentarios;
        fscanf(fd, "%*[^\n]\n");
        cout << '1';
    }
    cout << endl;

    fseek(fd, -1, SEEK_CUR);
    
    int a, b, N;
    
    fscanf(fd, "%d %d %d", &a, &b, &N);
    cout << a << endl;
    cout << b << endl;
    cout << N << endl;

    Valores->origem = a;
    Valores->destino = b;
    Valores->quantidade = N;

    cout << Valores->origem << endl;
    cout << Valores->destino << endl;
    cout << Valores->quantidade << endl;

    for(int i = 0; i < N; i++){
        int Vori, Vdes;
        fscanf(fd, "%d %d", &Vori, &Vdes);
        cout << Vori << endl; cout << Vdes << endl;
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