#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;


#define INF UINT_MAX


struct Peao{

    unsigned int linha;
    unsigned int coluna;
    bool esta_vivo;

    Peao(pair<unsigned int, unsigned int> coordenadas){
        this->linha = coordenadas.first;
        this->coluna = coordenadas.second;

        this->esta_vivo = true;
    }

};


unsigned int coordenadas_para_posicao(unsigned int linha, unsigned int coluna){

    unsigned int posicao = 0;

    coluna += 1;
    posicao = (linha * 8) + coluna;

    return posicao;

}


pair<unsigned int, unsigned int> posicao_para_coordenadas(unsigned int posicao){

    unsigned int linha;
    unsigned int coluna;

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

    for(unsigned int i = 0; i < peoes.size(); i++){
        if(peoes[i].esta_vivo)
            return false;
    }

    return true;

}


bool eh_falha(vector<Peao>& peoes){

    for(unsigned int i = 0; i < peoes.size(); i++){
        if(peoes[i].linha >= 9)
            return true;
    }

    return false;

}


bool movimento_eh_valido(unsigned int linha, unsigned int coluna){

    return (linha < 10 && linha >= 0) && (coluna < 8 && coluna >= 0);

}


vector<pair<unsigned int, unsigned int> > movimentos_possiveis(unsigned int linha_cavalo, unsigned int coluna_cavalo){

    vector<pair<unsigned int, unsigned int> > movimentos;

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


vector<Peao> fazer_movimento(pair<unsigned int, unsigned int> destino, vector<Peao> peoes){

    /* Mata peoes vivos na posicao destino do cavalo */
    for(unsigned int i = 0; i < peoes.size(); i++){
        if(destino.first == peoes[i].linha &&
           destino.second == peoes[i].coluna &&
           peoes[i].esta_vivo){
            peoes[i].esta_vivo = false;
        }
    }

    /* Movimenta os peoes vivos */
    for(unsigned int i = 0; i < peoes.size(); i++){
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


unsigned int back_track(vector<Peao> peoes, pair<unsigned int, unsigned int> cavalo, unsigned int movimentos_feitos, unsigned int& melhor_solucao){

    vector<unsigned int>::iterator menor_subsolucao;

    if(eh_solucao(peoes)){
        if(movimentos_feitos < melhor_solucao)
            melhor_solucao = movimentos_feitos;
        return melhor_solucao;
    }

    if(eh_falha(peoes)){
        return INF;
    }

    if(movimentos_feitos >= melhor_solucao){
        return INF;
    }

    vector<pair<unsigned int, unsigned int> > movimentos = movimentos_possiveis(cavalo.first, cavalo.second);
    vector<Peao> temporario;
    vector<unsigned int> solucoes;

    for(unsigned int i = 0; i < movimentos.size(); i++){
        temporario = fazer_movimento(movimentos[i], peoes);
        solucoes.push_back(back_track(temporario, movimentos[i], movimentos_feitos + 1, melhor_solucao));
    }

    menor_subsolucao = min_element(solucoes.begin(), solucoes.end());

    /* Estado atual não é solução e não existe subestado a ser visitado */
    if(menor_subsolucao == solucoes.end()){
        return INF;
    }

    return min(movimentos_feitos + *menor_subsolucao, melhor_solucao);

}


int main(){

    unsigned int quantidade_peoes = 0;
    unsigned int pos = 0;

    pair<unsigned int, unsigned int> cavalo;

    unsigned int movimentos = 0;
    unsigned int melhor_solucao = INF;
    unsigned int melhor = INF;

    vector<Peao> peoes;

    cin >> quantidade_peoes;
    for(unsigned int i = 0; i < quantidade_peoes; i++){
        cin >> pos;
        peoes.push_back(Peao(posicao_para_coordenadas(pos)));
    }

    cin >> pos;
    cavalo = posicao_para_coordenadas(pos);
    melhor = back_track(peoes, cavalo, 0, melhor_solucao);

    melhor = max(melhor, melhor_solucao);

    if(melhor < INF){
        cout << melhor << endl;
    }
    else{
        cout << "impossible" << endl;
    }

    return 0;
}
