#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string monta_string(vector<vector<char> > grade){
	int n, x, y;
	string movimento, result;

	cin >> n >> x >> y;

	if(n > 0){
		cin >> movimento;
	}

	x--;
	y--;

	if(x < 0)
		x = 0;
	else if(x > grade.size() - 1)
		x = grade.size() - 1;

	if(y < 0)
		y = 0;
	else if(y > grade[0].size() - 1)
		y = grade[0].size() - 1;

	result += grade[x][y];
	for(int i = 0; i < movimento.size(); i++){
		if(movimento[i] == 'N')
			x--;
		else if(movimento[i] == 'S')
			x++;
		else if(movimento[i] == 'E')
			y++;
		else if(movimento[i] == 'W')
			y--;

		if(x < 0)
			x = 0;
		else if(x > grade.size() - 1)
			x = grade.size() - 1;

		if(y < 0)
			y = 0;
		else if(y > grade[0].size() - 1)
			y = grade[0].size() - 1;

		result += grade[x][y];
	}

	return result;
}

void le_entrada(vector<vector<char> >& grade, string& a, string& b){
	int h, w;

	cin >> h >> w;

	grade.resize(h);
	for(int i = 0; i < h; i++){
		grade[i].resize(w);
		for(int j = 0; j < w; j++){
			cin >> grade[i][j];
		}
	}

	a = monta_string(grade);
	b = monta_string(grade);
}

int longest_common_subsequence(string a, string b){
	vector<vector<int> > cache;
	int maior = 0;

	cache.resize(a.size() + 1);
	for(int i = 0; i <= a.size(); i++){
		cache[i].resize(b.size() + 1);
		fill(cache[i].begin(), cache[i].end(), 0);
	}

	for(int i = 1; i <= a.size(); i++){
		for(int j = 1; j <= b.size(); j++){
			if(a[i - 1] == b[j - 1]){
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else{
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}

	return cache[a.size()][b.size()];
}

int main(){
	int t, result_a, result_b, lcs;
	vector<vector<char> > grade;
	string a, b;

	cin >> t;

	for(int i = 0; i < t; i++){
		le_entrada(grade, a, b);

		lcs = longest_common_subsequence(a, b);
		result_a = a.size() - lcs;
		result_b = b.size() - lcs;
		cout << "Case " << i+1 << ": " << result_a << " " << result_b << endl;
	}

	return 0;
}
