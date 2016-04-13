#include <iostream>
#include <map>

using namespace std;

int main(){
    int i;
    string linha;
    map<char, char> teclado;

    /* Primeira linha */
    teclado['1'] = '`';
    teclado['2'] = '1';
    teclado['3'] = '2';
    teclado['4'] = '3';
    teclado['5'] = '4';
    teclado['6'] = '5';
    teclado['7'] = '6';
    teclado['8'] = '7';
    teclado['9'] = '8';
    teclado['0'] = '9';
    teclado['-'] = '0';
    teclado['='] = '-';

    /* Segunda linha */
    teclado['W'] = 'Q';
    teclado['E'] = 'W';
    teclado['R'] = 'E';
    teclado['T'] = 'R';
    teclado['Y'] = 'T';
    teclado['U'] = 'Y';
    teclado['I'] = 'U';
    teclado['O'] = 'I';
    teclado['P'] = 'O';
    teclado['['] = 'P';
    teclado[']'] = '[';
    teclado['\\'] = ']';

    /* Terceira linha */
    teclado['S'] = 'A';
    teclado['D'] = 'S';
    teclado['F'] = 'D';
    teclado['G'] = 'F';
    teclado['H'] = 'G';
    teclado['J'] = 'H';
    teclado['K'] = 'J';
    teclado['L'] = 'K';
    teclado[';'] = 'L';
    teclado['\''] = ';';

    /* Quarta linha */
    teclado['X'] = 'Z';
    teclado['C'] = 'X';
    teclado['V'] = 'C';
    teclado['B'] = 'V';
    teclado['N'] = 'B';
    teclado['M'] = 'N';
    teclado[','] = 'M';
    teclado['.'] = ',';
    teclado['/'] = '.';
    teclado[' '] = ' ';

    while(getline(cin, linha)){
        for(i=0; i<linha.size(); i++){
            cout << teclado[linha[i]];
        }
        cout << endl;
    }
}
