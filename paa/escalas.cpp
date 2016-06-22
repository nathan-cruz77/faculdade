#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n;
    int aux;
    vector<int> dists;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> aux;
        dists.push_back(aux);
    }

    int total = 0;
    for(int salvo = -1, corrente = 0; corrente != n - 1; corrente++){
        if(salvo > 0){
            if(dists[corrente] - dists[salvo] > 200){
                salvo = corrente - 1;
                total += 1;
            }
        }
        else{
            if(dists[corrente] > 200){
                salvo = corrente - 1;
                total += 1;
            }
        }
    }

    cout << total + 1 << endl;

    return 0;

}
