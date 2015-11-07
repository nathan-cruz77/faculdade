#include <iostream>

using namespace std;

int main(){
	int x = 0;
	int i;
	string expressao;

	while(cin >> expressao){
		//cout << expressao;

		for(i=0; i<expressao.size(); i++){
			if(expressao[i] == '('){
				x++;
			}
			else if(expressao[i] == ')'){
				x--;
			}

			if(x < 0){
				i = expressao.size();
			}
		}

		if(x != 0){
			cout << "incorrect\n";
		}
		else{
			cout << "correct\n";
		}

		x = 0;
	}

	return 0;
}
