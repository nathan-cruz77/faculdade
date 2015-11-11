#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

string int_to_string(int num){
	string res;
	stringstream gambi;

	gambi << num;
	gambi >> res;

	return res;
}

int string_to_int(string num){
	int res;
	stringstream gambi;

	gambi << num;
	gambi >> res;

	return res;
}

int char_to_int_decimal(char num){
	return (int) (num - 48);

	/*
	if(num == '0'){
		res = 0;
	}
	else if(num == '1'){
		res = 1;
	}
	else if(num == '2'){
		res = 2;
	}
	else if(num == '3'){
		res = 3;
	}
	else if(num == '4'){
		res = 4;
	}
	else if(num == '5'){
		res = 5;
	}
	else if(num == '6'){
		res = 6;
	}
	else if(num == '7'){
		res == 7;
	}
	else if(num == '8'){
		res = 8;
	}
	else if(num == '9'){
		res = 9;
	}

	return res;
	*/
}

int main(){
	int i, j;
	int a, b;
	string num;
	vector<int> vet(10);

	for(cin >> a >> b; a != 0 && b != 0; cin >> a >> b){

		fill(vet.begin(), vet.end(), 0);

		for(i=a; i<=b; i++){
			num = int_to_string(i);

			for(j=0; j<num.size(); j++){
				vet[num[j] - 48]++;
			}
		}

		for(i=0; i<9; i++){
			cout << vet[i] << " ";
		}
		cout << vet[i] << endl;
	}
}
