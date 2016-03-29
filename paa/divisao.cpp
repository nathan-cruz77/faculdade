#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <cstdio>

using namespace std;


string to_string(unsigned int x){
	/* Necessario pois o Judge compila com padrao c++98, que nao tem to_string() */
	ostringstream conversor;

	conversor << x;

	return conversor.str();
}


bool eh_valido(unsigned int x){
	vector<int> digitos(10);
	bool result = true;

	digitos[x / 10000]++;
	digitos[(x / 1000) % 10]++;
	digitos[((x / 100) % 100) % 10]++;
	digitos[(((x / 10) % 1000) % 100) % 10]++;
	digitos[(((x % 10000) % 1000) % 100) % 10]++;

	for(int i = 0; i < 10; i++){
		if(digitos[i] > 1){
			result = false;
			i = 10;
		}
	}

	return result;
}


bool resultado_valido(unsigned int x, unsigned int y, unsigned int n){
	vector<int> digitos(10, 0);

	string x_aux;
	string y_aux;

	if(x < 10000)
		x_aux = "0" + to_string(x);
	else
		x_aux = to_string(x);

	if(y < 10000)
		y_aux = "0" + to_string(y);
	else
		y_aux = to_string(y);

	string numerao(x_aux + y_aux);
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
	unsigned int primeiro_divisivel = 0;

	bool achou = false;

	for(primeiro_divisivel = 1234; (primeiro_divisivel % n) != 0; primeiro_divisivel++);

	for(unsigned int i = primeiro_divisivel; i <= 98765; i += n){
		if(eh_valido(i))
			validos.push_back(i);
	}

	for(int i = 0; i < validos.size(); i++){
		numerador = validos[i];
		denominador = numerador / n;

		if(eh_valido(denominador) && resultado_valido(numerador, denominador, n)){
			achou = true;
			printf("%.5d %.5d\n", numerador, denominador);
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
