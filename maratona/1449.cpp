#include <iostream>
#include <map>
#include <list>

using namespace std;

int main(){
	int t;
	int m, n;
	int i, j, k;
	char val[256];

	string chave, valor, aux;
	map<string, string> dict;


	cin >> t;
	for(i=0; i<t; i++){
		cin >> m;
		cin >> n;

		for(j=0; j<m; j++){
			cin >> chave;

			cin.getline(val, 256);
			valor = val;

			dict[chave] = valor;
			cout << "dict[\"" << chave << "\"]: " << valor << endl;
		}
/*
		for(j=0; j<n; j++){
			for(aux=""; aux != "\n"; cin >> aux){
				if(dict.find(aux) != dict.end()){
					cout << dict[aux] << " ";
				}
			}
			cout << endl;
		}

		dict.clear();
*/
	}
	return 0;
}
