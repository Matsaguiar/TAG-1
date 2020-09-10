#include "Vertice.h"

int main(){

    int Va, Vb, Vc;                     //Armazena os 3 primeiros valores do arquivo para montar o grafo;

    FILE* fd;                           //Cria o ponteiro do arquivo;

    char file[] = "soc-dolphins.mtx";   //Abre o arquivo soc-dolphins.mtx;
    fd = fopen(file, "r");

    if(fd == NULL){                     //Verifica se o arquivo abriu com sucesso;
        cout << "Erro abrir arquivo" << endl;
        return 0;
    }

    Obter_tamanho(&Va, &Vb, &Vc, fd);   //Obtem a quantidade de vertices do grafo;

    vector<vector<int>> Grafo(Va+1);    //Cria o grafo;

    Grafo = Obter_dados(Va, Vb, Vc, fd);//Obtem os elos de cada vertice;
    
    fclose(fd);

    Imprimir_grafo(Grafo);

    return 0;
}
