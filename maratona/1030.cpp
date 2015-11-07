#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pos_um_vivo(vector<int> vet){
	int i;

	for(i=0; i<vet.size(); i++){
		if(vet[i] == 0){
			return i;
		}
	}

	return -1;
}

int main(){
	int i, j, mortos;
	int n, c, k;
	int aux;
	vector<int> vet;

	cin >> n;
	for(i=0; i<n; i++){
		cin >> c;
		cin >> k;

		vet.clear();
		vet.resize(c);
		fill(vet.begin(), vet.end(), 0);

		mortos = 0;
		for(j=0; mortos != c-1; j+=k){
			aux = j % c;
			if(vet[aux] == 0){
				vet[aux] = 1;
				mortos++;
			}
			cout << "Mortos: " << mortos << "\tj: " << j
					<< "\taux: " << aux << endl;

		}

		cout << "Case " << i+1 << ": " <<  pos_um_vivo(vet) << endl;
	}
	return 0;
}
