#ifndef VERTICE_H
#define VERTICE_H
 
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void Obter_tamanho(int *Va, int *Vb, int *Vc);
vector<vector<int>> Obter_dados(int Va, int Vb, int N);

void Imprimir_grafo(vector<vector<int>> Grafo);

#endif  //  VERTICE_H