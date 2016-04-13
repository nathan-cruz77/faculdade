#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

inline void fastRead_int(int &x)
{
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c < 48 || c > 57) && c != '-'); c = getchar());

    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; c > 47 && c < 58 ; c = getchar())
    {
        x = (x << 1) + (x << 3) + c - 48;
    }

    if(neg)
        x = -x;
}

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
    int i, j;

    vector<int> amigos;
    vector< vector<int> > matriz;

    /* Enquanto tiver coisa para ler da entrada padrao */
    while(cin >> n >> m >> k){

        alguem_foi_impresso = false;
        limpa_vectors(amigos, matriz, n);

        /* Le as ligacoes */
        for(i=0; i<m; i++){
            fastRead_int(a);
            fastRead_int(b);

            matriz[a - 1][b - 1] = 1;
            matriz[b - 1][a - 1] = 1;

            amigos[a - 1]++;
            amigos[b - 1]++;
        }

        if(k == 0){
            for(i = 0; i < n-1; i++){
                printf("%d ", i+1);
                alguem_foi_impresso = true;
            }
            printf("%d\n", i+1);
        }
        else{

            /* Remove os elementos com mais de 0 e menos de k amigos */
            for(i=0; i<n; i++){
                if(amigos[i] > 0 && amigos[i] < k){
                    remove_elemento(matriz, amigos, k, i);
                }
            }

            /* Busca o indice do ultimo elemento que sera impresso */
            for(i=1, j=0; i<n; i++){
                if(amigos[i] > 0){
                    j = i;
                }
            }

            /* Imprime todos que tem mais de 0 amigos */
            for(i=0; i<j; i++){
                if(amigos[i] > 0){
                    printf("%d ", i+1);
                    alguem_foi_impresso = true;
                }
            }

            /* Imprime o ultimo elemento, se ele existir */
            if(amigos[i] > 0){
                printf("%d\n", i+1);
                alguem_foi_impresso = true;
            }

        }

        if(!alguem_foi_impresso){
            printf("0\n");
        }
    }

    return 0;
}
