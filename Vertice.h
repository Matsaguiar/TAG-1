#ifndef VERTICE_H
#define VERTICE_H
 
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

#define FALSE 0;
#define TRUE 1;

typedef struct Vertice{
    int origem;
    int destino;
    int quantidade;
}S_Grafo;

vector<vector<int>> Obter_dados(vector<vector<int>>Grafo, S_Grafo* Valores);

void Imprimir_grafo(vector<vector<int>> Grafo);

#endif  //  VERTICE_H