#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	int g, p;
	int i, j;

	map<int, int> resultados_velhos;
	map<int, int> resultados_novos;

	map<int, int> velho;
	map<int, int> novo;

	velho[1] = 10;
	velho[2] = 8;
	velho[3] = 6;
	velho[4] = 5;
	velho[5] = 4;
	velho[6] = 3;
	velho[7] = 2;
	velho[8] = 1;

	novo[1] = 25;
	novo[2] = 18;
	novo[3] = 15;
	novo[4] = 12;
	novo[5] = 10;
	novo[6] = 8;
	novo[7] = 6;
	novo[8] = 4;
	novo[9] = 2;
	novo[10] = 1;

	while(cin >> g >> p){

		resultados_novos.clear();
		resultados_velhos.clear();

		resultados_novos.resize(p);
		resultados_velhos.resize(p);

		fill(resultados_velhos.begin(), resultados_velhos.end(), 0);
		fill(resultados_novos.begin(), resultados_novos.end(), 0);

		for(i=0; i<g; i++){
			
		}
	}

	return 0;
}
