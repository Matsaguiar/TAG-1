#ifndef COEFAGLO_H
#define COEFAGLO_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

pair<int,double> coefAglomeracao(vector<vector<int>> Grafo, int vert);

void Obtem_coef_vertice(vector<vector<int>> Grafo);

void Obtem_coef_medio(vector<vector<int>> Grafo);

#endif  //  COEFAGLO_H