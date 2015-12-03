#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SequenciaMutacao{
    int tamanho;
    int quantidade_mutacoes;

    SequenciaMutacao(){
        this->tamanho = 0;
        this->quantidade_mutacoes = 0;
    }
};

int longest_common_subsequence(string a, string b, vector<bool> mutacoes){
    int i, j;
    SequenciaMutacao maior;
    vector<bool> mutacoes_reversa = mutacoes;

    reverse(mutacoes_reversa.begin(), mutacoes_reversa.end());

    vector<vector<SequenciaMutacao> > cache;

    cache.resize(a.size() + 1);
    for(i = 0; i < a.size() + 1; i++){
        cache[i].resize(b.size() + 1);
        fill(cache[i].begin(), cache[i].end(), SequenciaMutacao());
    }

    for(i = 1; i < a.size() + 1; i++){
        for(j = 1; j < b.size() + 1; j++){

            if(a[i - 1] == b[j - 1]){
                cache[i][j].tamanho = cache[i - 1][j - 1].tamanho + 1;
                cache[i][j].quantidade_mutacoes = cache[i - 1][j - 1].quantidade_mutacoes;

                if(mutacoes[i] || mutacoes_reversa[j]){
                    cache[i][j].quantidade_mutacoes++;
                }

            }
            else{

                if(cache[i][j - 1].quantidade_mutacoes > cache[i - 1][j].quantidade_mutacoes){
                    cache[i][j].tamanho = cache[i][j - 1].tamanho;
                    cache[i][j].quantidade_mutacoes = cache[i][j - 1].quantidade_mutacoes;
                }

                else if(cache[i][j - 1].quantidade_mutacoes == cache[i - 1][j].quantidade_mutacoes){

                    if(cache[i][j - 1].tamanho > cache[i - 1][j].tamanho){
                        cache[i][j].tamanho = cache[i][j - 1].tamanho;
                        cache[i][j].quantidade_mutacoes = cache[i][j - 1].quantidade_mutacoes;

                    }
                    else{
                        cache[i][j].tamanho = cache[i - 1][j].tamanho;
                        cache[i][j].quantidade_mutacoes = cache[i - 1][j].quantidade_mutacoes;
                    }

                }
            }

            if(cache[i][j].quantidade_mutacoes > maior.quantidade_mutacoes){
                maior.tamanho = cache[i][j].tamanho;
                maior.quantidade_mutacoes = cache[i][j].quantidade_mutacoes;
            }
            else if(cache[i][j].quantidade_mutacoes == maior.quantidade_mutacoes){
                if(cache[i][j].tamanho > maior.tamanho){
                    maior.tamanho = cache[i][j].tamanho;
                }
            }

        }
    }

    return maior.tamanho;
}

void read_input(string& sequencia, string& invertida, vector<bool>& mutacoes){
    int quantidade_mutacoes, aux;

    cin >> sequencia;

    invertida = sequencia;
    reverse(invertida.begin(), invertida.end());

    cin >> quantidade_mutacoes;

    mutacoes.resize(sequencia.size());
    fill(mutacoes.begin(), mutacoes.end(), false);

    for(int i = 0; i < quantidade_mutacoes; i++){
        cin >> aux;
        mutacoes[aux - 1] = true;
    }

}

int main(){

    vector<bool> mutacoes;
    string sequencia, sequencia_invertida;

    read_input(sequencia, sequencia_invertida, mutacoes);

    cout << longest_common_subsequence(sequencia, sequencia_invertida, mutacoes) << endl;

    return 0;
}
