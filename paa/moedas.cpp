#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int back_track(vector<int>& moedas, int i, int troco){

	if(i == moedas.size() - 1){
		return troco;
	}

	int minimo_usando_moeda_atual = 0;
	int minimo_nao_usando_moeda_atual = 0;
	int moedas_usadas = 0;

	/* Usa a moeda atual */
	moedas_usadas = troco / moedas[i];
	troco = troco % moedas[i];
	minimo_usando_moeda_atual = back_track(moedas, i+1, troco) + moedas_usadas;

	/* Não usa moeda atual */
	troco += moedas[i] * moedas_usadas;
	minimo_nao_usando_moeda_atual = back_track(moedas, i+1, troco);

	/* Retorna o melhor caso */
	return min(minimo_usando_moeda_atual, minimo_nao_usando_moeda_atual);

}


int main(){

	int troco = 0;
	int moeda = 0;
	int quantidade_minima = 0;

	vector<int> moedas;

	cin >> troco;

	while(cin >> moeda){
		moedas.push_back(moeda);
	}

	if(find(moedas.begin(), moedas.end(), 1) == moedas.end()){
		moedas.push_back(1);
	}

	sort(moedas.begin(), moedas.end());
	reverse(moedas.begin(), moedas.end());

	quantidade_minima = back_track(moedas, 0, troco);

	cout << quantidade_minima << endl;

	return 0;

}
