#include "Vertice.h"
#include "CoefAglo.h"
#include "CliqueMaxi.h"

void menu(vector<vector<int>> Grafo){
    int op = -1;

    while(op != 0){
        system(CLEAR);

        cout << endl << "\t\tMENU" << endl << endl;
        cout << "(1) Lista de grau dos vertices." << endl;
        cout << "(2) Lista dos cliques maximais." << endl;
        cout << "(3) Lista de coeficiente de aglomeracao de cada vertice." << endl;
        cout << "(4) Coeficiente medio de aglomeracao do grafo." << endl;
        cout << "(5) Mostrar os respectivos vizinhos de cada vertice." << endl;
        cout << "(0) Sair." << endl;
        
        cout << "Digite sua opcao: ";
        cin >> op;

        switch(op){

            case 1:
                system(CLEAR);

                Imprimir_grafo(Grafo);

                printf("\nAperte ENTER para continuar\n");
                getchar();
                getchar();
                break;

            case 2:
                system(CLEAR);

                Imprimir_bronKerbosch();

                printf("\nAperte ENTER para continuar\n");
                getchar();
                getchar();
                break;

            case 3:

                system(CLEAR);

                Obtem_coef_vertice(Grafo);

                printf("\nAperte ENTER para continuar\n");
                getchar();
                getchar();
                break;

            case 4:
                system(CLEAR);

                Obtem_coef_medio(Grafo);

                printf("\nAperte ENTER para continuar\n");
                getchar();
                getchar();
                break;

            case 5:
                system(CLEAR);

                Imprimir_vizinhos(Grafo);

                printf("\nAperte ENTER para continuar\n");
                getchar();
                getchar();
                break;

            default:
                break;
        }

    }
}

int main(){
    int Va, Vb, Vc;                         //Armazena os 3 primeiros valores do arquivo para montar o grafo;

    FILE* fd;                               //Cria o ponteiro do arquivo;

    char file[] = "soc-dolphins.mtx";       //Abre o arquivo soc-dolphins.mtx;
    fd = fopen(file, "r");

    if(fd == NULL){                         //Verifica se o arquivo abriu com sucesso;
        cout << "Erro abrir arquivo" << endl;
        return 0;
    }
    
    Obter_tamanho(&Va, &Vb, &Vc, fd);       //Obtem a quantidade de vertices do grafo;

    vector<vector<int>> Grafo(Va+1);        //Cria lista de adjascencia do grafo;

    Grafo = Obter_dados(Va, Vb, Vc, fd);    //Obtem os elos de cada vertice;

    vector<int> R; //Vazio
    vector<int> X; //Vazio
    vector<int> P; //Passa a conter todos os vertices
    for (int i = 0; i < Va; i++){
        P.push_back(i+1);
    }
    bronKerbosch(R, P, X, Grafo);
    
    fclose(fd);

    menu(Grafo);
   
    return 0;
}
