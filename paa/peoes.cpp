#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;


#define INF INT_MAX


struct Peao{

    int linha;
    int coluna;
    bool esta_vivo;

    Peao(pair<int, int> coordenadas){
        this->linha = coordenadas.first;
        this->coluna = coordenadas.second;

        this->esta_vivo = true;

        //cout << "linha: " << this->linha << " coluna: " << this->coluna << endl;
    }

};


int coordenadas_para_posicao(int linha, int coluna){

    int posicao = 0;

    coluna += 1;
    posicao = (linha * 8) + coluna;

    return posicao;

}


pair<int, int> posicao_para_coordenadas(int posicao){

    int linha;
    int coluna;

    if(posicao % 8 == 0){

        linha = (posicao / 8) - 1;
        coluna = 7;

        return make_pair(linha, coluna);
    }

    linha = posicao / 8;
    coluna = (posicao % 8) - 1;

    return make_pair(linha, coluna);

}


bool eh_solucao(vector<Peao>& peoes){

    for(int i = 0; i < peoes.size(); i++){
        if(peoes[i].esta_vivo)
            return false;
    }

    return true;

}


bool eh_falha(vector<Peao>& peoes){

    for(int i = 0; i < peoes.size(); i++){
        if(peoes[i].linha >= 9)
            return true;
    }

    return false;

}


bool movimento_eh_valido(int linha, int coluna){

    return (linha < 10 && linha >= 0) && (coluna < 8 && coluna >= 0);

}


vector<pair<int, int> > movimentos_possiveis(int linha_cavalo, int coluna_cavalo){

    vector<pair<int, int> > movimentos;

    /* Para cima */
    if(movimento_eh_valido(linha_cavalo + 2, coluna_cavalo + 1))
        movimentos.push_back(make_pair(linha_cavalo + 2, coluna_cavalo + 1));

    if(movimento_eh_valido(linha_cavalo + 2, coluna_cavalo - 1))
        movimentos.push_back(make_pair(linha_cavalo + 2, coluna_cavalo - 1));

    /* Para baixo */
    if(movimento_eh_valido(linha_cavalo - 2, coluna_cavalo + 1))
        movimentos.push_back(make_pair(linha_cavalo - 2, coluna_cavalo + 1));

    if(movimento_eh_valido(linha_cavalo - 2, coluna_cavalo - 1))
        movimentos.push_back(make_pair(linha_cavalo - 2, coluna_cavalo - 1));

    /* Para esquerda */
    if(movimento_eh_valido(linha_cavalo + 1, coluna_cavalo - 2))
        movimentos.push_back(make_pair(linha_cavalo + 1, coluna_cavalo - 2));

    if(movimento_eh_valido(linha_cavalo - 1, coluna_cavalo - 2))
        movimentos.push_back(make_pair(linha_cavalo - 1, coluna_cavalo - 2));

    /* Para direita */
    if(movimento_eh_valido(linha_cavalo + 1, coluna_cavalo + 2))
        movimentos.push_back(make_pair(linha_cavalo + 1, coluna_cavalo + 2));

    if(movimento_eh_valido(linha_cavalo - 1, coluna_cavalo + 2))
        movimentos.push_back(make_pair(linha_cavalo - 1, coluna_cavalo + 2));

    return movimentos;

}


vector<Peao> fazer_movimento(pair<int, int> destino, vector<Peao> peoes){

    /* Mata peoes na posicao destino do cavalo */
    for(int i = 0; i < peoes.size(); i++){
        if(destino.first == peoes[i].linha && destino.second == peoes[i].coluna){
            peoes[i].esta_vivo = false;
        }
    }

    /* Movimenta os peoes vivos */
    for(int i = 0; i < peoes.size(); i++){
        if(peoes[i].esta_vivo){
            peoes[i].linha++;

            if(peoes[i].linha == destino.first && peoes[i].coluna == destino.second){
                cout << "impossible" << endl;
                exit(EXIT_SUCCESS);
            }
        }
    }

    return peoes;

}


int back_track(vector<Peao> peoes, pair<int, int> cavalo, int& movimentos_feitos, int& melhor_solucao){

    int movs = 0;

    if(eh_solucao(peoes)){
        if(movimentos_feitos < melhor_solucao)
            melhor_solucao = movimentos_feitos;
        return melhor_solucao;
    }

    if(eh_falha(peoes)){
        return INF;
    }

    movimentos_feitos++;

    if(movimentos_feitos >= melhor_solucao){
        return INF;
    }

    vector<pair<int, int> > movimentos = movimentos_possiveis(cavalo.first, cavalo.second);
    vector<Peao> temporario;
    vector<int> solucoes;

    for(int i = 0; i < movimentos.size(); i++){
        temporario = fazer_movimento(movimentos[i], peoes);
        solucoes.push_back(back_track(temporario, movimentos[i], movimentos_feitos, melhor_solucao));
    }

    movs = movimentos_feitos + *min_element(solucoes.begin(), solucoes.end());
    movimentos_feitos--;

    return movs;

}


int main(){

    int quantidade_peoes = 0;
    int pos = 0;

    pair<int, int> cavalo;

    int movimentos = 0;
    int melhor_solucao = INF;
    int melhor;

    vector<Peao> peoes;

    cin >> quantidade_peoes;
    for(int i = 0; i < quantidade_peoes; i++){
        cin >> pos;
        peoes.push_back(Peao(posicao_para_coordenadas(pos)));
    }

    cin >> pos;
    cavalo = posicao_para_coordenadas(pos);
    //cout << "Iniciando backtracking..." << endl;
    melhor = back_track(peoes, cavalo, movimentos, melhor_solucao);

    //cout << INF << endl;

    if(melhor < INF){
        cout << melhor << endl;
    }
    else{
        cout << "impossible" << endl;
    }

    return 0;
}
