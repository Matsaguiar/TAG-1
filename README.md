# TAG-1
Universidade de Brasília
Departamento de Ciência da Computação

Projeto 1

Teoria e Aplicação de Grafos, Turma A, 1/2020
Prof. Díbio

Em 2003, no artigo “David Lusseau et al., The bottelenose dolphin community of Doubful Sound
features a large proportion of long-lasting associations, Journal of Behavioral Ecology and
Sociobiology 54:4, 396--405 (2003).” uma rede social de relações duradouras é identificada em uma
comunidade de 62 golfinhos e apresentada como um grafo (não direcionado) para estudos. Os dados
estão em arquivo anexo (soc-dolphins.zip). O projeto consiste em escrever um programa em C/C++
que lê o arquivo (soc-dolphins.mtx, ou o txt), monta com esses dados um grafo não direcionado, sem
pesos, usando listas de adjacências, e então calcula e imprime como saída (tela) o seguinte:

(1) o vértice, e seu respectivo grau (para todos os vértices);

(2) todos os cliques maximais (indicando o número de vértices e quais);

(3) O Coeficiente de Aglomeração de cada vértice;

(4) O Coeficiente médio de Aglomeração do Grafo.

=============================================================

Alunos:

Lamarzin: 
Matheus Arruda Aguiar: 18/0127659

=============================================================

Para compilar é necessário inserir o comando no terminal:
g++ main.cpp Vertice.cpp CoefAglo.cpp -o main

Em seguida para executar, basta inserir:
./main

=============================================================

O programa processa as informações do arquivo
soc-dolphins.mtx.

Em seguida mostra a tela inicial com um menu com as opções implementadas.
Para escolher a função a ser executada, basta inserir
um inteiro correspondente à opção listada.
