#include <iostream>
#include <deque>
#include <list>

using namespace std;

void print_deck(deque<int> deck){
    deque<int>::iterator it;

    for(it=deck.begin(); it != deck.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    int n, k;
    int i, j;
    deque<int> deck;
    list<int> descarte;
    list<int>::iterator descarte_iterator;

    for(cin >> n; n != 0; cin >> n){

        /* Limpa as estruturas de dados da iteracao anterior */
        deck.clear();
        descarte.clear();

        /* Preenche a pilha de cartas */
        for(i=1; i<=n; i++){
            deck.push_back(i);
        }

        //print_deck(deck);
        while(deck.size() > 1){
            descarte.push_back(deck.front());
            deck.pop_front();

            deck.push_back(deck.front());
            deck.pop_front();

            //print_deck(deck);
        }

        cout << "Discarded cards:";

        for(descarte_iterator = descarte.begin();
            *descarte_iterator != descarte.back();
            descarte_iterator++){
            cout << " " << *descarte_iterator << ",";
        }

        cout << " " << descarte.back() << endl;

        cout << "Remaining card: " << deck.front() << endl;
    }

    return 0;
}
