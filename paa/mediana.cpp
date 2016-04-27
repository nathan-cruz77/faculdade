#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

	vector<int> data;

	int meio = 0;
	int aux;
	while(cin >> aux){
		data.push_back(aux);
	}

	sort(data.begin(), data.end());

	if(data.size() % 2 == 0){
		meio = data.size() / 2;
		cout << (data[meio] + data[meio - 1]) / 2. << endl;
	}
	else{
		meio = data.size() / 2;
		cout << data[meio] << endl;
	}

	return 0;
}
