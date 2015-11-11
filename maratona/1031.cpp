#include <iostream>
#include <vector>

using namespace std;

int josephus(int n, int k){
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}

int main(){
    int n, c, k;
    int i, j;

    for(cin >> n; n != 0; cin >> n){

        c = -1;
        for(k=1; c != 13; k++){
            c = josephus(n, k);
            cout << "c = " << c << endl;
            cout << "josephus(" << n << ", " << k << ") = " << josephus(n, k) << endl;
        }

        cout << "k = " << k << endl;
        cout << "josephus(" << n << ", " << k << ") = " << josephus(n, k) << endl;
    }

    return 0;
}
