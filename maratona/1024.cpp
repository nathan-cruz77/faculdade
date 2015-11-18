#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool is_char(char a){
	if((a >= 65 && a <= 90) || (a >= 97 && a <= 122)){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int n, metade;
	string linha;

	while(cin >> n){

		/* Pega lixo */
		getline(cin, linha);
		linha.clear();

		for(int i=0; i<n; i++){
			getline(cin, linha);
			//cout << "linha: \"" << linha << "\"" << endl;

			/* Primeira passada */
			for(int j=0; j<linha.size(); j++){
				if(is_char(linha[j])){
					linha[j] = linha[j] + 3;
				}
			}

			/* Segunda passada */
			reverse(linha.begin(), linha.end());

			/* Terceira passada */
			for(metade = linha.size() / 2; metade < linha.size(); metade++){
				linha[metade] = linha[metade] - 1;
			}

			/* Impressao do resultado */
			cout << linha << endl;

			linha.clear();
		}
	}

	return 0;
}
