#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

bool comp(list<string> i, list<string> j){
    return i.size() < j.size();
}

int main(){
    int n, i;
    bool inserido = false;
    string linha;

    list< list<string> > lista;
    list<string> maior;

    list< list<string> >::iterator iterador_um;
    list<string>::iterator iterador_dois;

    for(cin >> n; n != 0; cin >> n){

        lista.clear();

        for(i=0; i < n; i++){
            cin >> linha;

            for(iterador_um = lista.begin();
                iterador_um != lista.end();
                iterador_um++){

                for(iterador_dois = (*iterador_um).begin();
                    iterador_dois != (*iterador_um).end() && !inserido;
                    iterador_dois++){

                    if(linha.find(*iterador_dois) != -1 ||
                       linha.find(*iterador_dois) != -1){
                        (*iterador_um).push_back(linha);
                        inserido = true;
                    }

                }

            }

            if(!inserido){
                lista.push_back(list<string>());
                lista.back().push_back(linha);
            }
        }

        cout << (*max_element(lista.begin(), lista.end(), comp)).size();
        cout << endl;

    }

    cout << endl;

    return 0;
}
