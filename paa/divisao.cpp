#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool eh_valido(unsigned int x){
	vector<int> digitos(5);

	digitos[0] = x / 10000;
	digitos[1] = (x / 1000) % 10;
	digitos[2] = ((x / 100) % 100) % 10;
	digitos[3] = (((x / 10) % 1000) % 100) % 10;
	digitos[4] = (((x % 10000) % 1000) % 100) % 10;

	return (digitos[0] != digitos[1] !=
			digitos[2] != digitos[3] !=
			digitos[4]);
}


bool resultado_valido(unsigned int x, unsigned int y, unsigned int n){
	vector<int> digitos(10, 0);
	string numerao(to_string(x) + to_string(y));
	bool result = true;

	for(int i = 0; i < numerao.size(); i++){
		digitos[numerao[i] - 48]++;
	}

	for(int i = 0; i < numerao.size(); i++){
		if(digitos[numerao[i] - 48] > 1){
			result = false;
			i = numerao.size();
		}
	}

	return (result && (x / y) == n);
}


void gera_numeros(unsigned int n){
	vector<unsigned int> validos;
	vector<unsigned int> numeradores;

	unsigned int numerador = 0;
	unsigned int denominador = 0;

	bool achou = false;

	for(unsigned int i = 1234; i <= 98765; i++){
		if(eh_valido(i))
			validos.push_back(i);
	}

	for(unsigned int i  = 0; i < validos.size(); i++){
		if((validos[i] % n) == 0)
			numeradores.push_back(validos[i]);
	}

	for(int i = numeradores.size() - 1; i >= 0; i--){
		numerador = validos[i];

		for(int j = 0; j < validos.size(); j++){
			//cout << "denominador: " << denominador << " " << "j: " << j << endl;
			denominador = validos[j];

			if(resultado_valido(numerador, denominador, n)){
				achou = true;
				cout << numerador << " " << denominador << endl;
			}
		}
	}

	if(!achou){
		cout << "No solution." << endl;
	}
}


int main(){
	unsigned int n;

	cin >> n;

	gera_numeros(n);

	return 0;
}
