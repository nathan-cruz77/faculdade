#include <iostream>
#include <map>
#include <list>
#include <deque>
#include <algorithm>
#include <cstdio>

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

void remove_no(map<int, list<int> >& grafo,
               map<int, list<int> >::iterator a_ser_removido){
    list<int>::iterator list_iterador, aux;

    for(list_iterador = a_ser_removido->second.begin();
        list_iterador != a_ser_removido->second.end();
        list_iterador++){

        if(grafo.find(*list_iterador) != grafo.end()){

            aux = find(grafo[*list_iterador].begin(),
                        grafo[*list_iterador].end(), a_ser_removido->first);

            if(aux != grafo[*list_iterador].end()){
                grafo[*list_iterador].erase(aux);
            }
        }
    }

    grafo.erase(a_ser_removido);
}

void subgrafo_maximal(map<int, list<int> >& grafo, int k){
    map<int, list<int> >::iterator grafo_iterador;

    if(grafo.size() < k+1){
        grafo.clear();
        return;
    }

    for(grafo_iterador = grafo.begin();
        grafo_iterador != grafo.end() && grafo_iterador->second.size() >= k;
        grafo_iterador++);

    /* Saiu do laco pq chegou em um elemento com menos conexoes
    * que o minimo */
    if(grafo_iterador != grafo.end()){
        remove_no(grafo, grafo_iterador);
        subgrafo_maximal(grafo, k);
    }

    /* Saiu do laco pq acabou de processar todo mundo; */


}

int main(){
    int a, b;
    int i, j;
    int n, m, k;

    map<int, list<int> > grafo;
    map<int, list<int> >::iterator mapa_iterador;

    while(cin >> n >> m >> k){

        if(m < k){
            printf("0\n");
            continue;
        }

        grafo.clear();

        /* Le as relacoes e registra no grafo */
        for(i=0; i<m; i++){
            fastRead_int(a);
            fastRead_int(b);

            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        /* Processa o grafo recursivamente */
        subgrafo_maximal(grafo, k);

        /* Imprime os elementos remanescentes */
        for(mapa_iterador = grafo.begin(), j=0;
            mapa_iterador != grafo.end();
            mapa_iterador++, j++){

            if(j != grafo.size()-1){
                printf("%d ", mapa_iterador->first);
            }
            else{
                printf("%d\n", mapa_iterador->first);
            }
        }

        if(grafo.size() == 0){
            printf("0\n");
        }
    }

    return 0;
}
