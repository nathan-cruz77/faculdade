#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	float salario;
	float aumento;
	int p;

	cin >> salario;

	if(salario > 0 && salario <= 400){
		aumento = salario * 0.15;
		p = 15;
	}
	else if(salario > 400 && salario <= 800){
		aumento = salario * 0.12;
		p = 12;
	}
	else if(salario > 800 && salario <= 1200){
		aumento = salario * 0.10;
		p = 10;
	}
	else if(salario > 1200 && salario <= 2000){
		aumento = salario * 0.07;
		p = 7;
	}
	else{
		aumento = salario * 0.04;
		p = 4;
	}

	cout << fixed << setprecision(2);

	cout << "Novo salario: " << salario + aumento << endl;
	cout << "Reajuste ganho: " << aumento << endl;
	cout << "Em percentual: " << p << " %" << endl;

	return 0;
}
