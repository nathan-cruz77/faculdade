#include <iostream>
#include <string>

using namespace std;

char cesar(char c, int n){
    c = toupper(c);
    c = (c + n) <= 90 ? (c + n) : (c + n) - 26;

    return c;
}

int main(){

    string chave;
    string entrada;
    string saida;
    int deslocamento = 0;

    cin >> chave;
    cin >> entrada;

    for(int i = 0; i < entrada.size(); i++){

        if(entrada[i] == ' '){
            saida += ' ';
        }
        else{
            deslocamento = (int) toupper(chave[i % chave.size()]) - 65;
            saida += cesar(entrada[i], deslocamento);
        }
    }

    cout << saida << endl;

    return 0;
}
