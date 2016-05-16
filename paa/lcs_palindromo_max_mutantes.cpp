#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct SequenciaMutacao{

    int quantidade_mutacao;
    int tamanho;

    SequenciaMutacao(){
        this->quantidade_mutacao = 0;
        this->tamanho = 0;
    }

    bool operator >(const SequenciaMutacao& outro){
        if(this->quantidade_mutacao > outro.quantidade_mutacao)
            return true;

        else if(this->quantidade_mutacao == outro.quantidade_mutacao){
            if(this->tamanho > outro.tamanho)
                return true;
            else
                return false;
        }

        else
            return false;
    }

    bool operator < (const SequenciaMutacao& outro){
        if(outro.quantidade_mutacao > this->quantidade_mutacao)
            return true;

        else if(outro.quantidade_mutacao == this->quantidade_mutacao){
            if(outro.tamanho > this->tamanho)
                return true;
            else
                return false;
        }

        else
            return false;
    }

    bool operator ==(const SequenciaMutacao& outro){
        if(this->tamanho == outro.tamanho &&
            this->quantidade_mutacao == outro.tamanho)
            return true;
        else
            return false;
    }

    SequenciaMutacao& operator =(const SequenciaMutacao& outro){
        this->tamanho = outro.tamanho;
        this->quantidade_mutacao = outro.quantidade_mutacao;

        return *this;
    }
};

void inline le_entrada(string& a, vector<bool>& mut){
    int n, x;

    cin >> a;

    cin >> n;
    mut.resize(a.size());
    fill(mut.begin(), mut.end(), false);

    for(int i = 0; i < n; i++){
        cin >> x;
        mut[x - 1] = true;
    }
}

void verifica(SequenciaMutacao& atual, SequenciaMutacao outro, SequenciaMutacao mais_outro){
    if(outro > atual || mais_outro > atual){
        if(outro > mais_outro)
            atual = outro;
        else
            atual = mais_outro;
    }
}

int lps_especial(string sequencia, vector<bool> mutacoes){
    int i, j, aux, tamanho;

    tamanho = sequencia.size();

    vector<vector<SequenciaMutacao> > cache;

    cache.resize(tamanho);
    for(i = 0; i < tamanho; i++){
        cache[i].resize(tamanho);
        fill(cache[i].begin(), cache[i].end(), SequenciaMutacao());

        cache[i][i].tamanho = 1;

        if(mutacoes[i])
            cache[i][i].quantidade_mutacao++;
    }

    for(aux = 1; aux < tamanho; aux++){
        for(i = 0, j = aux; j < tamanho; i++, j++){
            if(sequencia[i] == sequencia[j]){
                if(aux == 1){
                    cache[i][j].tamanho = 2;
                }
                else{
                    cache[i][j].tamanho = cache[i + 1][j - 1].tamanho + 2;
                    cache[i][j].quantidade_mutacao = cache[i + 1][j - 1].quantidade_mutacao;
                }
                cache[i][j].quantidade_mutacao += mutacoes[i];
                cache[i][j].quantidade_mutacao += mutacoes[j];
            }
            verifica(cache[i][j], cache[i][j - 1], cache[i + 1][j]);
        }
    }

    return cache[0][tamanho - 1].tamanho;
}

int main(){
    string sequencia;
    vector<bool> mutacoes;

    le_entrada(sequencia, mutacoes);

    cout << lps_especial(sequencia, mutacoes) << endl;

    return 0;
}
