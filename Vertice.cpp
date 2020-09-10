#include "Vertice.h"

// vector<vector<int>> Faz_grafo(int v){
//     vector<vector<int>> graph(v); 
//     return Grafo;
// }

 void Obter_tamanho(int *Va, int *Vb, int *Vc){
    FILE* fd;

    char file[] = "soc-dolphins.mtx";
    fd = fopen(file, "r");

    if(fd == NULL){
        printf("Erro abrir arquivo\n");
    }
    
    rewind(fd); // Move para o começo do arquivo;
    
    while(fgetc(fd) == '%'){ //Pula os comentarios;
        fscanf(fd, "%*[^\n]\n");
    }

    fseek(fd, -1, SEEK_CUR);
        
    fscanf(fd, "%d %d %d", Va, Vb, Vc);

    fclose(fd);
}

vector<vector<int>> Obter_dados(int Va, int Vb, int N){
    FILE* fd;

    vector<vector<int>> Grafo(Va);

    char file[] = "soc-dolphins.mtx";
    fd = fopen(file, "r");

    if(fd == NULL){
        printf("Erro abrir arquivo\n");
        return Grafo;
    }
    
    rewind(fd); // Move para o começo do arquivo;
    
    while(fgetc(fd) == '%'){ //Pula os comentarios;
        fscanf(fd, "%*[^\n]\n");
    }

    fseek(fd, -1, SEEK_CUR);
    int x, y, z;
    fscanf(fd, "%d %d %d", &x, &y, &z);

    for(int i = 0; i < N; i++){
        int a, b;
        fscanf(fd, "%d %d", &a, &b);
        Grafo[a-1].push_back(b);
        Grafo[b-1].push_back(a);
    }
    
    fclose(fd);
    return Grafo;
}

void Imprimir_grafo(vector<vector<int>> Grafo){
    for(int i = 0; i < 62; i++){
        printf("%d - ", i+1);
        for(int j = 0; j < Grafo[i].size(); j++){
            printf("%d ", Grafo[i][j]);
        } 
        cout << "Grau: " << Grafo[i].size();
        cout << endl;
    }
}