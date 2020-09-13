#ifndef CLIQUEMAX_H
#define CLIQUEMAX_H
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> Inserir_sem_repetir (vector<int> V, int N);
vector<int> Subno (vector<int> V, int N);
vector<int> InterN (vector<int> V, int N, vector<vector<int>> Grafo);
void bronKerbosch (vector<int> R, vector<int> P, vector<int> X, vector<vector<int>> Grafo);
void Imprimir_bronKerbosch();

#endif  //CLIQUEMAX_H