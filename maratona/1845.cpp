#include <iostream>
#include <map>
#include <list>
#include <sstream>
#include <algorithm>
#include <string>
#include <istream>
#include <cstdio>

using namespace std;

map<char, char> consoantes;

char transformador(char x){
    if(consoantes.find(x) != consoantes.end()){
        return consoantes[x];
    }
    else{
        return x;
    }
}
void replace_all(std::string& str, const std::string& oldStr, const std::string& newStr){
    size_t pos = 0;

    while((pos = str.find(oldStr, pos)) != std::string::npos){
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
}
void traduz(string palavra){
    size_t pos;

    transform(palavra.begin(), palavra.end(), palavra.begin(), transformador);

    replace_all(palavra, "ff", "f");
    replace_all(palavra, "Ff", "F");

    cout << palavra;
}

int main(){
    char atual;
    char last = 'a';

    consoantes['s'] = 'f';
    consoantes['S'] = 'F';

    consoantes['j'] = 'f';
    consoantes['J'] = 'F';

    consoantes['b'] = 'f';
    consoantes['B'] = 'F';

    consoantes['z'] = 'f';
    consoantes['Z'] = 'F';

    consoantes['p'] = 'f';
    consoantes['P'] = 'F';

    consoantes['v'] = 'f';
    consoantes['V'] = 'F';


    consoantes['x'] = 'f';
    consoantes['X'] = 'F';


    while(scanf("%c", &atual) != EOF){
        atual = transformador(atual);

        if( (atual == 'f' || atual == 'F') &&
            (last == 'f' || last == 'F')){
            continue;
        }
        else{
            cout << atual;
        }

        last = atual;
    }
}
