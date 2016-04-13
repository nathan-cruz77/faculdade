#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>

using namespace std;

int main(){
    int t;
    int m, n;
    int i, j, k;

    string chave, valor, aux, linha;
    map<string, string> dict;
    bool iniciou_linha;


    cin >> t;
    for(i=0; i<t; i++){
        cin >> m;
        cin >> n;

        for(j=0; j<m; j++){
            cin >> chave;
            getline(cin, valor);
            getline(cin, valor);

            dict[chave] = valor;
            //cout << "dict[\"" << chave << "\"]: " << valor << endl;
        }

        for(j=0; j<n; j++){
            getline(cin, linha);
            stringstream string_stream(linha);

            iniciou_linha = false;
            while(string_stream >> aux){
                if(iniciou_linha){
                    cout << " ";
                }
                if(dict.find(aux) != dict.end()){
                    cout << dict[aux];
                }
                else{
                    cout << aux;
                }
                iniciou_linha = true;
            }

            cout << endl;
        }

        cout << endl;

        dict.clear();

    }
    return 0;
}
