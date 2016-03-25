#include <iostream>
#include <bitset>
#include <utility>
#include <vector>

using namespace std;


bitset<10> bitfy(string chave){
    bitset<10> chave_em_bits;
    int n = chave_em_bits.size();

    if(chave.size() != chave_em_bits.size()){
        cout << "AVISO: A chave deve ter 10 bits" << endl;

        if(chave.size() > chave_em_bits.size()){
            cout << "AVISO: Concatenando a chave." << endl;
        }
        else{
            cout << "AVISO: Completando a chave com 0s." << endl;
            for(int i = 0; i < chave_em_bits.size() - chave.size(); i++){
                chave += "0";
            }
        }
    }

    for(int i = 0; i < chave.size(); i++){
        chave_em_bits[(n - 1) - i] = chave[i];
    }

    return chave_em_bits;
}


void left_shift(bitset<5>& data){
    data = (data << 1) | (data >> (data.size() - 1));
}


pair<bitset<4>, bitset<4> > particionador(bitset<8> data){
    bitset<4> esq, dir;

    for(int j = 3; j >= 0; j--){
        dir[j] = data[j];
    }

    for(int j = 7; j > 3; j--){
        esq[j - 4] = data[j];
    }

    return make_pair(esq, dir);
}


pair<bitset<5>, bitset<5> > p10(bitset<10> chave_inicial){
    bitset<5> saida_1;
    bitset<5> saida_2;

    saida_1[0] = chave_inicial[2];
    saida_1[1] = chave_inicial[4];
    saida_1[2] = chave_inicial[1];
    saida_1[3] = chave_inicial[6];
    saida_1[4] = chave_inicial[3];

    saida_2[0] = chave_inicial[9];
    saida_2[1] = chave_inicial[0];
    saida_2[2] = chave_inicial[8];
    saida_2[3] = chave_inicial[7];
    saida_2[4] = chave_inicial[5];

    return make_pair(saida_1, saida_2);
}


bitset<8> p8(bitset<5> entrada_1, bitset<5> entrada_2){
    bitset<8> saida;
    size_t n = entrada_1.size();

    saida[7] = entrada_2[(n - 1) - 0];
    saida[6] = entrada_1[(n - 1) - 2];
    saida[5] = entrada_2[(n - 1) - 1];
    saida[4] = entrada_1[(n - 1) - 3];
    saida[3] = entrada_2[(n - 1) - 2];
    saida[2] = entrada_1[(n - 1) - 4];
    saida[1] = entrada_2[(n - 1) - 4];
    saida[0] = entrada_2[(n - 1) - 3];

    return saida;
}


bitset<8> k1(bitset<10> chave){
    pair<bitset<5>, bitset<5> > particionada;

    particionada = p10(chave);

    left_shift(particionada.first);
    left_shift(particionada.second);

    return p8(particionada.first, particionada.second);
}


bitset<8> k2(bitset<10> chave){
    pair<bitset<5>, bitset<5> > particionada;

    particionada = p10(chave);

    left_shift(particionada.first);
    left_shift(particionada.second);

    left_shift(particionada.first);
    left_shift(particionada.second);

    return p8(particionada.first, particionada.second);
}


void initial_permutation(bitset<8>& data){
    bitset<8> aux = data;
    size_t n = aux.size();

    data[7] = aux[(n - 1) - 1];
    data[6] = aux[(n - 1) - 5];
    data[5] = aux[(n - 1) - 2];
    data[4] = aux[(n - 1) - 0];
    data[3] = aux[(n - 1) - 3];
    data[2] = aux[(n - 1) - 7];
    data[1] = aux[(n - 1) - 4];
    data[0] = aux[(n - 1) - 6];
}


void reverse_initial_permutation(bitset<8>& data){
    bitset<8> aux = data;
    size_t n = aux.size();

    data[7] = aux[(n - 1) - 3];
    data[6] = aux[(n - 1) - 0];
    data[5] = aux[(n - 1) - 2];
    data[4] = aux[(n - 1) - 4];
    data[3] = aux[(n - 1) - 6];
    data[2] = aux[(n - 1) - 1];
    data[1] = aux[(n - 1) - 7];
    data[0] = aux[(n - 1) - 5];
}


bitset<8> ep(bitset<4> data){
    bitset<8> aux;
    size_t n = data.size();

    aux[7] = data[n - 3];
    aux[6] = data[n - 0];
    aux[5] = data[n - 1];
    aux[4] = data[n - 2];
    aux[3] = data[n - 1];
    aux[2] = data[n - 2];
    aux[1] = data[n - 3];
    aux[0] = data[n - 0];

    return aux;
}


bitset<2> s0(bitset<4> data){

    vector<vector<unsigned int> > matriz = {
        {1, 0, 3, 2},
        {3, 2, 1, 0},
        {0, 2, 1, 3},
        {3, 1, 3, 2}
    };

    bitset<2> linha;
    bitset<2> coluna;
    bitset<2> to_return;

    linha[0] = data[0];
    linha[1] = data[3];

    coluna[0] = data[2];
    coluna[1] = data[1];

    bitset<sizeof(unsigned int)> result(matriz[linha.to_ulong()][coluna.to_ulong()]);

    to_return[0] = result[0];
    to_return[1] = result[1];

    return to_return;

}


bitset<2> s1(bitset<4> data){

    vector<vector<unsigned int> > matriz = {
        {1, 1, 2, 3},
        {2, 0, 1, 3},
        {3, 0, 1, 0},
        {2, 1, 0, 3}
    };

    bitset<2> linha;
    bitset<2> coluna;
    bitset<2> to_return;

    linha[0] = data[0];
    linha[1] = data[3];

    coluna[0] = data[2];
    coluna[1] = data[1];

    bitset<sizeof(unsigned int)> result(matriz[linha.to_ulong()][coluna.to_ulong()]);

    to_return[0] = result[0];
    to_return[1] = result[1];

    return to_return;

}


bitset<4> p4(bitset<2> esq, bitset<2> dir){

    bitset<4> concatenado(esq.to_string() + dir.to_string());
    bitset<4> aux = concatenado;

    concatenado[0] = aux[3];
    concatenado[1] = aux[1];
    concatenado[2] = aux[0];
    concatenado[3] = aux[2];

    return concatenado;

}


bitset<4> complex_function(bitset<8> chave, bitset<4> texto){
    bitset<8> permutado;
    pair<bitset<4>, bitset<4> > entrada_particionada;

    permutado = ep(texto) ^ chave;
    entrada_particionada = particionador(permutado);

    /* Esquerda para s0 e direita para s1 */
    return p4(s0(entrada_particionada.first), s1(entrada_particionada.second));
}


string cifra(string texto, string chave){
    string cifrado;

    bitset<10> chave_em_bits = bitfy(chave);
    bitset<8> texto_plano;

    pair<bitset<4>, bitset<4> > particionado;

    bitset<8> chave1 = k1(chave_em_bits);
    bitset<8> chave2 = k2(chave_em_bits);

    bitset<4> esq, dir;

    for(int i = 0; i < texto.size(); i++){
        texto_plano = texto[i];

        initial_permutation(texto_plano);
        particionado = particionador(texto_plano);

        esq = particionado.first;
        dir = particionado.second;

        esq ^= complex_function(k1, dir);
        swap(esq, dir);
        esq ^= complex_function(k2, dir);

        bitset<8> concatenado(esq.to_string() + dir.to_string());
        reverse_initial_permutation(concatenado);

        cifrado += (char) concatenado.to_ulong();
    }

    return cifrado;
}


int main(){
    string chave;
    string texto;

    cin >> chave;
    cin >> texto;

    cout << cifra(texto, chave) << endl;

    return 0;
}
