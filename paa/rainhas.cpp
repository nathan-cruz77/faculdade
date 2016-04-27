#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


bool esta_disponivel(vector<pair<int, int> >& rainhas, int linha, int coluna){

	/* Disponibilidade horizontal */
	for(int i = 0; i < rainhas.size(); i++){
		if(rainhas[i].first == linha)
			return false;
	}

	/* Disponibilidade diagonal */
	for(int col = 0; col < coluna; coluna++){
		if(abs(rainhas[col].first - linha) == abs(rainhas[col].second - coluna))
			return false;
	}

	return true;

}


vector<int> gera_possibilidades(vector<pair<int, int> >& rainhas, int i){

	vector<int> possibilidades;

	/* Verifica disponibilidade */
	for(int pos = 0; pos < 8; pos++){
		if(esta_disponivel(rainhas, pos, i))
			possibilidades.push_back(pos);
	}

	return possibilidades;

}


bool back_track(vector<pair<int, int> >& rainhas, int i){

	rainhas[i].second = i;

	vector<int> possibilidades = gera_possibilidades(rainhas, i);

	if(i == 7){
		rainhas[i].first = possibilidades[i];
		return true;
	}

	for(int p = 0; p < possibilidades.size(); p++){
		rainhas[i].first = possibilidades[i];
		if(back_track(rainhas, i+1)){
			return true;
		}
	}

	return false;

}


int main(){

	vector<pair<int, int> > rainhas(8, make_pair(-1, -1));

	back_track(rainhas, 0);

	for(int i = 0; i < rainhas.size(); i++){
		cout << rainhas[i].first << rainhas[i].second << " ";
	}

	cout << endl;

	return 0;
}
