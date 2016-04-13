#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int busca(vector<int>& A, int x) {
    int i;

    for(i = 0; i < A.size(); i++){
        if(A[i] == x)
            return i;
    }

    return -1;
}


vector<int> acha_campeoes(vector<int>& pontos){
    int maior = 0;
    vector<int> champs;

    maior = *max_element(pontos.begin(), pontos.end());

    for(int i = 0; i < pontos.size(); i++){
        if(pontos[i] == maior)
            champs.push_back(i+1);
    }

    return champs;
}


int main(){
    int g;
    int p;
    int s;
    int k;
    int pontuacao;

    vector<vector<int> > resultados;
    vector<int> pontos;
    vector<int> campeoes;

    for(cin >> g >> p; g != 0 && p != 0; cin >> g >> p){

        resultados.clear();
        pontos.clear();

        pontos.resize(p);
        fill(pontos.begin(), pontos.end(), 0);

        for(int i = 0; i < p; i++){
            resultados.push_back(vector<int>(p, 0));
        }

        for(int i = 0; i < g; i++){

            /* Save results */
            for(int j = 0; j < p; j++){
                cin >> resultados[i][j];
            }

        }

        cin >> s;

        for(int i = 0; i < s; i++){
            cin >> k;

            for(int j = 0; j < k; j++){
                cin >> pontuacao;

                for(int a = 0; a < resultados.size(); a++){
                    pontos[busca(resultados[a], j)] += pontuacao;
                }
            }

            campeoes = acha_campeoes(pontos);

            for(int j = 0; j < campeoes.size() - 1; j++){
                cout << campeoes[j] << " ";
            }

            cout << campeoes[campeoes.size() - 1] << endl;

            campeoes.clear();
            fill(pontos.begin(), pontos.end(), 0);

        }

    }

    return 0;
}
