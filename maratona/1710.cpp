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


	bool tem_este_planeta(int x, int y, int z){
		if((a*x + b*y + c*z) == this->d){
			//cout << a << "*" << x << " " << b << "*" << y << " " << c << "*" << z << " == " << d;
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
	map<int, Plano> regioes;
	map<int, Plano>::iterator regioes_iterator;

	cin >> m;
	cin >> n;

	for(i=0; i<m; i++){
		cin >> a >> b >> c >> d;
		regioes[i] = Plano(a, b, c, d);

		cout << "Regioes[" << i << "]:" << endl;

		cout << "\ta = " << regioes[i].a << endl;
		cout << "\tb = " << regioes[i].b << endl;
		cout << "\tc = " << regioes[i].c << endl;
		cout << "\td = " << regioes[i].d << endl;
		cout << "\tquantidade = " << regioes[i].quantidade << endl;

		cout << endl;
	}

	for(i=0; i<n; i++){
		cin >> x >> y >> z;

		for(regioes_iterator = regioes.begin();
			regioes_iterator != regioes.end();
			regioes_iterator++){
			cout << "Elemento: " << regioes_iterator->first << endl;
			if(regioes_iterator->second.tem_este_planeta(x, y, z)){
				cout << "Registrado: (" << x << ", " << y << ", " << z << ")";
				cout << " -> regiao " << regioes_iterator->first << endl;
				regioes_iterator->second.quantidade++;
				break;
			}
		}
	}

	j = 0;
	for(i=1; i<n; i++){
		if(regioes[i].quantidade > regioes[j].quantidade){
			j = i;
		}
	}

	cout << regioes.size() << endl;
	cout << regioes[j].quantidade << endl;

	return 0;
}
