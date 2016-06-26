#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


void read_universe(vector<pair<int, bool> >& target){

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


int fitness(vector<pair<int, bool> >& universe, vector<int>& current){

    vector<pair<int, bool> >::iterator aux;
    int fit = 0;

    for(int i = 0; i < current.size(); i++){
        aux = find(universe.begin(), universe.end(), make_pair(current[i], false));

        if(aux != universe.end()){
            fit++;
        }
    }

    return fit;

}


bool is_covered(vector<pair<int, bool> >& universe){

    bool res = true;

    for(int i = 0; i < universe.size(); i++){
        res &= universe[i].second;
    }

    return res;

}


int set_cover(vector<pair<int, bool> >& universe,
              vector<pair<vector<int>, bool> >& part){

    int best_fit = 0;
    int fit_aux = 0;

    int best_index = -1;

    if(is_covered(universe)){
        return 0;
    }

    /* Selecao gulosa */
    for(int i = 0; i < part.size(); i++){
        if(!part[i].second){
            fit_aux = fitness(universe, part[i].first);

            if(fit_aux > best_fit){
                best_fit = fit_aux;
                best_index = i;
            }
        }
    }

    part[best_index].second = true;

    /* Marca os elementos cobertos em `universe` */
    vector<pair<int, bool> >::iterator aux_it;
    for(int i = 0; i < part[best_index].first.size(); i++){
        aux_it = find(universe.begin(), universe.end(),
                      make_pair(part[best_index].first[i], false));

        if(aux_it != universe.end()){
            aux_it->second = true;
        }
    }

    return 1 + set_cover(universe, part);

}


int main(){

    vector<pair<int, bool> > universo;
    vector<pair<vector<int>, bool> > particao;

    int tamanho_universo = 0;
    int tamanho_particao = 0;
    int tamanho_subconjunto = 0;

    cin >> tamanho_universo;
    universo.resize(tamanho_universo);
    fill(universo.begin(), universo.end(), make_pair(0, false));

    read_universe(universo);

    cin >> tamanho_particao;
    particao.resize(tamanho_particao);
    fill(particao.begin(), particao.end(), make_pair(vector<int>(), false));

    for(int i = 0; i < particao.size(); i++){
        cin >> tamanho_subconjunto;
        particao[i].first.resize(tamanho_subconjunto);
        read_int_vector(particao[i].first);
    }

    cout << set_cover(universo, particao) << endl;

    return 0;

}
