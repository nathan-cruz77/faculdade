#include <iostream>
#include <bitset>
#include <utility>
#include <vector>
#include <string>

using namespace std;


bitset<10> bitfy(string chave){
    bitset<10> chave_em_bits;
    int n = chave_em_bits.size();

    if(chave.size() != 10){
        cerr << "Erro, tamanho da chave incompativel" << endl;
        cerr << "Recebido: " << chave << " de tamanho " << chave.size() << endl;
    }

    if(chave.size() > chave_em_bits.size()){
        cout << "AVISO: Truncando a chave." << endl;
    }
    if(chave.size() < chave_em_bits.size()){
        cout << "AVISO: Completando a chave com 0s." << endl;
        for(int i = 0; i < chave_em_bits.size() - chave.size(); i++){
            chave = "0" + chave;
        }
    }

    for(int i = chave.size() - 1, j = 0; i >= 0; i--, j++){
        if(chave[j] == '1')
            chave_em_bits[i] = 1;
        else
            chave_em_bits[i] = 0;
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

    saida_1[0] = chave_inicial[6];
    saida_1[1] = chave_inicial[3];
    saida_1[2] = chave_inicial[8];
    saida_1[3] = chave_inicial[5];
    saida_1[4] = chave_inicial[7];

    saida_2[0] = chave_inicial[4];
    saida_2[1] = chave_inicial[2];
    saida_2[2] = chave_inicial[1];
    saida_2[3] = chave_inicial[9];
    saida_2[4] = chave_inicial[0];

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
    //cout << "K = " << chave << endl;
    pair<bitset<5>, bitset<5> > particionada;

    particionada = p10(chave);

    //cout << "P10(k) = " << particionada.first << particionada.second << endl;

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

    left_shift(particionada.first);
    left_shift(particionada.second);

    //cout << "P10 Rotacionada 2x: " << particionada.first << " ";
    //cout << particionada.second << endl;

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

    aux[7] = data[0];
    aux[6] = data[3];
    aux[5] = data[2];
    aux[4] = data[1];
    aux[3] = data[2];
    aux[2] = data[1];
    aux[1] = data[0];
    aux[0] = data[3];

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

    permutado = ep(texto);
    /*
    cout << "EP: " << texto << " -> " << permutado << endl;

    cout << "XOR: " << permutado << endl;
    cout << "    ^" << chave << endl;
    cout << "     ------------" << endl;
    cout << "     " << (permutado ^ chave) << endl;
    */
    permutado ^= chave;

    entrada_particionada = particionador(permutado);

    /* Esquerda para s0 e direita para s1 */
    return p4(s0(entrada_particionada.first), s1(entrada_particionada.second));
}


string cifra(string texto, string chave){
    //cout << "Cifrando..." << endl << endl;

    string cifrado;

    bitset<10> chave_em_bits = bitfy(chave);

    pair<bitset<4>, bitset<4> > particionado;

    bitset<8> chave1 = k1(chave_em_bits);
    bitset<8> chave2 = k2(chave_em_bits);

    //cout << "K1 = " << chave1 << endl;
    //cout << "K2 = " << chave2 << endl;

    bitset<4> esq, dir;

    for(int i = 0; i < texto.size(); i++){

        //cout << "============= Iteracao nova ==============" << endl;

        bitset<8> texto_plano((unsigned long int) texto[i]);
        //cout << "Texto: " << texto_plano << endl;

        initial_permutation(texto_plano);
        //cout << "IP: " << texto_plano << endl;

        particionado = particionador(texto_plano);

        esq = particionado.first;
        dir = particionado.second;

        esq ^= complex_function(chave1, dir);
        swap(esq, dir);
        esq ^= complex_function(chave2, dir);

        bitset<8> concatenado(esq.to_string() + dir.to_string());
        reverse_initial_permutation(concatenado);

        //cout << "cifrado: " << concatenado << " = " << concatenado.to_ulong();
        //cout << endl;
        cifrado += (char) concatenado.to_ulong();

        //cout << "================= Fim da Iteracao ============" << endl;
    }

    return cifrado;
}


string decifra(string texto, string chave){
    //cout << "Decifrando..." << endl << endl;
    string decifrado;

    bitset<10> chave_em_bits = bitfy(chave);
    //cout << "Chave secreta em uso: " << chave_em_bits << endl;

    pair<bitset<4>, bitset<4> > particionado;

    bitset<8> chave1 = k1(chave_em_bits);
    bitset<8> chave2 = k2(chave_em_bits);

    //cout << "k1: " << chave1 << endl;
    //cout << "k2: " << chave2 << endl;

    bitset<4> esq, dir;

    for(int i = 0; i < texto.size() - 1; i++){

        //cout << "============= Iteracao nova ==============" << endl;

        bitset<8> texto_plano((unsigned long int) texto[i]);
        //cout << "Texto: " << texto_plano << endl;

        initial_permutation(texto_plano);
        //cout << "IP: " << texto_plano << endl;

        particionado = particionador(texto_plano);

        esq = particionado.first;
        dir = particionado.second;

        //cout << "  <" << esq << "> <"<< dir << ">" << endl;

        esq ^= complex_function(chave2, dir);
        swap(esq, dir);
        esq ^= complex_function(chave1, dir);

        bitset<8> concatenado(esq.to_string() + dir.to_string());
        reverse_initial_permutation(concatenado);

        //cout << "decifrado: " << concatenado << " = " << concatenado.to_ulong();
        //cout << endl;
        decifrado += (char) concatenado.to_ulong();

        //cout << "================= Fim da Iteracao ============" << endl;
    }

    return decifrado;

}

/*
int main(int argc, char** argv){
    if(argc != 2){
        cout << "[usage]: " << argv[0] << " {option}" << endl;
        cout << "options:" << endl;
        cout << "\t-c | --crypt:\tEncrypt incoming text." << endl;
        cout << "\t-d | --decrypt:\tDecrypt incoming text." << endl;
        exit(EXIT_SUCCESS);
    }

    string chave;
    string texto, opcao(argv[1]);

    getline(cin, chave);
    getline(cin, texto, (char) EOF);

    if(opcao == "-c" || opcao == "--crypt")
        cout << cifra(texto, chave);
    else if(opcao == "-d" || opcao == "--decrypt")
        cout << decifra(texto, chave) << endl;
    else{
        cout << "Unrecognized option '" << opcao << "'. Aborting." << endl;
        exit(EXIT_FAILURE);
    }

    return 0;
}
*/
