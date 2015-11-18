#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Plano{

	Plano(int a, int b, int c, int d){
		this->quantidade = 0;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	Plano(){
		this->quantidade = 0;
		this->a = 0;
		this->b = 0;
		this->c = 0;
		this->d = 0;
	}

	int quantidade;
	int a, b, c, d;


	int planeta_maior(int x, int y, int z){
		if((a*x + b*y + c*z) > this->d){
			return true;
		}
		return false;
	}
};

int main(){
	int m, n;
	int a, b, c, d;
	int x, y, z;

	int i, j;

	vector<int> aux;
	vector<Plano> regioes;

	map<vector<int>, int> repeticoes;
	map<vector<int>, int>::iterator repeticoes_iterador;

	cin >> m;
	cin >> n;

	for(i=0; i<m; i++){
		cin >> a >> b >> c >> d;
		regioes.push_back(Plano(a, b, c, d));
	}

	aux.resize(m);

	for(i=0; i<n; i++){
		fill(aux.begin(), aux.end(), 0);

		cin >> x >> y >> z;

		for(j=0; j<regioes.size(); j++){
			if(regioes[j].planeta_maior(x, y, z)){
				aux[j] = 1;
			}
			else{
				aux[j] = -1;
			}
		}

		if(repeticoes.find(aux) != repeticoes.end()){
			repeticoes[aux] += 1;
		}
		else{
			repeticoes[aux] = 1;
		}
	}

	j = 0;
	for(repeticoes_iterador = repeticoes.begin();
		repeticoes_iterador != repeticoes.end();
		repeticoes_iterador++){

		if(repeticoes_iterador->second > j){
			j = repeticoes_iterador->second;
		}

	}

	cout << j << endl;

	return 0;
}
