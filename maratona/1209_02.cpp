#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

void limpa_vectors(vector<int>& amigos, vector<vector<int> >& matriz, int n){

    /* Realoca o vetor e coloca 0 em tudo */
    amigos.resize(n);
    fill(amigos.begin(), amigos.end(), 0);

    /* Realoca a matriz de adjacencia e "limpa" todas as entradas */
    matriz.resize(n);
    for(int i=0; i<n; i++){
        matriz[i].resize(n);
        fill(matriz[i].begin(), matriz[i].end(), 0);
    }
}

void remove_elemento(vector<vector<int> >& matriz, vector<int>& amigos, int k, int indice){
    amigos[indice] = 0;

    /* Percorre a lista de amigos de `indice` */
    for(int i=0; i<amigos.size(); i++){

        /* Se `indice` tem `i` como amigo */
        if(matriz[indice][i] != 0){

            /* Remove a ligacao entre os dois */
            matriz[indice][i] = 0;
            matriz[i][indice] = 0;

            /* Decrementa a quantidade de amigos de `i` */
            amigos[i]--;

            /* Se `i` ficou com menos de `k` amigos
             * removemos ele tambem */
            if(amigos[i] > 0 && amigos[i] < k){
                remove_elemento(matriz, amigos, k, i);
            }
        }
    }
}

int main(){

    bool alguem_foi_impresso;

    int n, m, k;
    int a, b;
    int i;

    vector<int> amigos;
    vector< vector<int> > matriz;

    /* Enquanto tiver coisa para ler da entrada padrao */
    //while(cin >> n >> m >> k){

    cin >> n;
    k = 2;

        alguem_foi_impresso = false;
        limpa_vectors(amigos, matriz, n);

        /* Le as ligacoes */
        for(i=0; i<n; i++){
            cin >> a >> b;

            matriz[a - 1][b - 1] = 1;
            matriz[b - 1][a - 1] = 1;

            amigos[a - 1]++;
            amigos[b - 1]++;
        }

        if(k == 0){
            for(i = 0; i < n-1; i++){
                cout << i+1 << " ";
                alguem_foi_impresso = true;
            }
            cout << i+1 << endl;
        }
        else{
            for(i=0; i<n; i++){
                if(amigos[i] > 0 && amigos[i] < k){
                    remove_elemento(matriz, amigos, k, i);
                }
            }

            /* Imprime todos que tem mais de 0 amigos */
            for(i=1; i<n; i++){
                if(amigos[i] > 0){
                    cout << i+1 << " ";
                    alguem_foi_impresso = true;
                }
            }

            cout << "\b\b\b\b\b";
            cout.flush();
            cout << endl;

        }

        if(!alguem_foi_impresso){
            cout << 0 << endl;
        }
    //}

    return 0;
}
