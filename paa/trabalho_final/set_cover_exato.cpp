#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;


#define MY_MAX 100000


void read_universe(vector<pair<int, int> >& target){

    for(int i = 0, aux = 0; i < target.size(); i++){
        cin >> aux;
        target[i].first = aux;
    }

}


void read_int_vector(vector<int>& target){

    for(int i = 0, aux = 0; i < target.size(); i++){
        cin >> aux;
        target[i] = aux;
    }

}


bool is_covered(vector<pair<int, int> >& universe){

    for(int i = 0; i < universe.size(); i++){
        if(universe[i].second <= 0){
			return false;
		}
    }

    return true;

}


void marcador(vector<pair<int, int> >& universe, vector<int>& marcadores){

	for(int i = 0; i < marcadores.size(); i++){
		for(int j = 0; j < universe.size(); j++){
			if(universe[j].first == marcadores[i])
				universe[j].second++;
		}
	}

}


void desmarcador(vector<pair<int, int> >& universe, vector<int>& marcadores){

	for(int i = 0; i < marcadores.size(); i++){
		for(int j = 0; j < universe.size(); j++){
			if(universe[j].first == marcadores[i] &&
			   universe[j].second >= 0)
				universe[j].second--;
		}
	}

}


int set_cover(vector<pair<int, int> >& universe,
              vector<pair<vector<int>, bool> >& part,
			  int k){

    int first_false = k;
    int res_1 = 0;
    int res_2 = 0;

    if(is_covered(universe))
        return 0;

	if(first_false >= part.size())
		return MY_MAX;

    /* Marca os elementos cobertos em `universe` */
	marcador(universe, part[first_false].first);
    part[first_false].second = true;

    res_1 = 1 + set_cover(universe, part, k + 1);

    /* Desmarca os elementos cobertos em `universe` */
	desmarcador(universe, part[first_false].first);
	part[first_false].second = false;

    res_2 = set_cover(universe, part, k + 1);

    return min(res_1, res_2);

}


int main(){

    vector<pair<int, int> > universo;
    vector<pair<vector<int>, bool> > particao;

    int tamanho_universo = 0;
    int tamanho_particao = 0;
    int tamanho_subconjunto = 0;

    cin >> tamanho_universo;
    universo.resize(tamanho_universo);
    fill(universo.begin(), universo.end(), make_pair(0, 0));

    read_universe(universo);

    cin >> tamanho_particao;
    particao.resize(tamanho_particao);
    fill(particao.begin(), particao.end(), make_pair(vector<int>(), false));

    for(int i = 0; i < particao.size(); i++){
        cin >> tamanho_subconjunto;
        particao[i].first.resize(tamanho_subconjunto);
        read_int_vector(particao[i].first);
    }

    cout << set_cover(universo, particao, 0) << endl;

    return 0;

}
