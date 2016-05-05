#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


string rc4(string chave, string mensagem){
    vector<int> s(256);
    int j, aux;
    int k = 0;

    /* Inicializacao de S */
    for(int i = 0; i < s.size(); i++){
        s[i] = i;
    }

    /* Permutacao inicial de S */
    for(int i = 0, j = 0; i < s.size(); i++){

        aux = (int) chave[i % chave.size()];
        j = (j + s[i] + aux) % 256;

        swap(s[i], s[j]);
    }

    /* Geracao do Stream */
    for(int l = 0, j = 0, i = 0; l < mensagem.size(); l++){
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;

        swap(s[i % s.size()], s[j % s.size()]);

        aux = (s[i] + s[j]) % 256;
        k = s[aux];
        mensagem[l] = k ^ mensagem[l];
    }

    return mensagem;
}

/*
int main(){
    string chave, mensagem, cifrado;

    getline(cin, chave);
    getline(cin, mensagem, (char) EOF);


    cifrado = rc4(chave, mensagem);
    cout << cifrado << endl;
    mensagem = rc4(chave, cifrado);
    cout << mensagem;

    return 0;
}
*/
