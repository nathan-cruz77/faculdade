#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(string a, string b){
    int i, j, maior = 0;

    vector<vector<int> > cache;

    cache.resize(a.size() + 1);
    for(i = 0; i < a.size() + 1; i++){
        cache[i].resize(b.size() + 1);
        fill(cache[i].begin(), cache[i].end(), 0);
    }

    for(i = 1; i < a.size() + 1; i++){
        for(j = 1; j < b.size() + 1; j++){
            if(a[i - 1] == b[j - 1]){
                cache[i][j] = cache[i - 1][j - 1] + 1;
            }
            else{
                cache[i][j] = 0;
            }

            if(cache[i][j] > maior){
                maior = cache[i][j];
            }
        }
    }

    return maior;
}

int main(){

    string a, b;
    int result;

    while(getline(cin, a), getline(cin, b)){
        //cout << a << " " << b << endl;

        result = lcs(a, b);

        cout << result << endl;
    }

    return 0;
}
