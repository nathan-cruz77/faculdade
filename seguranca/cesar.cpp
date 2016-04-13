#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    string entrada;

    cin >> n;
    cin >> entrada;

    for(int i = 0; i < entrada.size(); i++){
        entrada[i] = toupper(entrada[i]);

        entrada[i] = (entrada[i] + n) < 90 ? (entrada[i] + n) : (entrada[i] + n) - 26;
    }

    cout << entrada << endl;

    return 0;
}
