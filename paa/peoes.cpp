#include <iostream>
#include <vector>
#include <utility>

#include <cstdio>

using namespace std;


struct Peao{

	int linha;
	int coluna;
	bool esta_vivo;

	Peao(pair<int, int> coordenadas){
		this->linha = coordenadas.first;
		this->coluna = coordenadas.second;

		this->esta_vivo = true;

		cout << "linha: " << this->linha << " coluna: " << this->coluna << endl;
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

	return (linha < 8 && coluna < 8);

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
		}
	}

	return peoes;

}


void back_track(vector<Peao> peoes, pair<int, int> cavalo, int& movimentos_feitos, int& movimentos_melhor_solucao){

	if(eh_solucao(peoes)){

		if(movimentos_feitos < movimentos_melhor_solucao)
			movimentos_melhor_solucao = movimentos_feitos;

		return;
	}

	if(eh_falha(peoes)){
		movimentos_melhor_solucao = -1;
		return;
	}

	movimentos_feitos++;

	//cout << "k = " << movimentos_feitos << endl;

	vector<pair<int, int> > movimentos = movimentos_possiveis(cavalo.first, cavalo.second);
	vector<Peao> temporario;

	for(int i = 0; i < movimentos.size(); i++){
		temporario = fazer_movimento(movimentos[i], peoes);
		back_track(temporario, movimentos[i], movimentos_feitos, movimentos_melhor_solucao);
	}

}


int main(){

	int quantidade_peoes = 0;
	int pos = 0;

	pair<int, int> cavalo;

	int movimentos = 0;
	int melhor_solucao = 0;

	vector<Peao> peoes;

	cin >> quantidade_peoes;
	for(int i = 0; i < quantidade_peoes; i++){
		cin >> pos;
		peoes.push_back(Peao(posicao_para_coordenadas(pos)));
	}

	cin >> pos;
	cavalo = posicao_para_coordenadas(pos);
	cout << "Iniciando backtracking..." << endl;
	cout << "cavalo_linha: " << cavalo.first << " cavalo_coluna: " << cavalo.second << endl;
	back_track(peoes, cavalo, movimentos, melhor_solucao);

	if(melhor_solucao <= 0){
		cout << melhor_solucao << endl;
	}
	else{
		cout << "impossible" << endl;
	}

	return 0;
}
