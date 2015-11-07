#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

inline void fastRead_int(int &x){
	register int c = getchar();
	x = 0;
	int neg = 0;

	for(; ((c < 48 || c > 57) && c != '-'); c = getchar());

	if(c == '-')
	{
		neg = 1;
		c = getchar();
	}

	for(; c > 47 && c < 58 ; c = getchar())
	{
		x = (x << 1) + (x << 3) + c - 48;
	}

	if(neg)
		x = -x;
}

int main(){
	int n, c;
	int i, j;
	int aux;
	vector<int> dados;
	vector<int>::iterator it;

	fastRead_int(n);
	for(i=0; i < n; i++){

		fastRead_int(c);

		dados.resize(c);
		dados.clear();

		for(j=0; j < c; j++){
			fastRead_int(aux);
			dados.push_back(aux);
		}

		sort(dados.begin(), dados.begin() + c);

		for(it = dados.begin(); it != (dados.end()-1); it++){
			printf("%d ", *it);
		}

		printf("%d", *it);

		printf("\n");
	}

	return 0;
}
