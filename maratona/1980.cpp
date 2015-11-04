#include <iostream>
#include <map>


using namespace std;

int fatorial(int i){
	if(i <= 1){
		return 1;
	}
	return i * fatorial(i-1);
}

int main(){
	int i, s;
	string a;
	map<char, int> elemento_ocorrencias;
	map<char, int>::iterator it;

	for(cin >> a; a != "0"; cin >> a){

		for(i=0; i<a.size(); i++){
			elemento_ocorrencias[a[i]] = 0;
		}
		for(i=0; i<a.size(); i++){
			elemento_ocorrencias[a[i]] += 1;
		}

		s = 1;

		for(it = elemento_ocorrencias.begin();
			it != elemento_ocorrencias.end();
			it++){
			s *= fatorial(it->second);
		}

		cout << fatorial(a.size()) / s << endl;

		elemento_ocorrencias.clear();
	}

	return 0;
}
