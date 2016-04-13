#include <iostream>
#include <map>
#include <list>

using namespace std;

int main(){
    map<int, list<int> > tabela_hash;
    int n, i, j;
    int m, c;
    int aux;

    map<int, list<int> >::iterator mapa_iterator;
    list<int>::iterator lista_iterator;

    cin >> n;

    for(i=0; i<n; i++){
        cin >> m;
        cin >> c;

        for(j=0; j<c; j++){
            cin >> aux;
            tabela_hash[aux % m].push_back(aux);
        }

        for(j=0; j<m; j++){
            if(tabela_hash.find(j) == tabela_hash.end()){
                tabela_hash[j] = list<int>();
            }
        }

        for(mapa_iterator = tabela_hash.begin(), j=0;
            mapa_iterator != tabela_hash.end();
            mapa_iterator++, j++){

            cout << mapa_iterator->first;

            for(lista_iterator = mapa_iterator->second.begin();
                lista_iterator != mapa_iterator->second.end();
                lista_iterator++){

                cout << " -> " << *lista_iterator;
            }

            cout << " -> \\" << endl;
        }

        if(i != n-1){
            cout << endl;
        }
        tabela_hash.clear();
    }

    return 0;
}
