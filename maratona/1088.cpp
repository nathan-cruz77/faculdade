#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;


int intercala_count(vector<int>& A, int inicio, int meio, int fim){

    vector<int> B(A.size(), 0);

    for(int i = inicio; i <= meio; i++){
        B[i] = A[i];
    }
    for(int j = meio + 1; j <= fim; j++){
        B[fim + meio + 1 - j] = A[j];
    }

    int i = inicio;
    int j = fim;
    int c = 0;

    for(int k = inicio; k <= fim; k++){
        if(B[i] <= B[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = B[j];
            j--;

            c++;
        }
    }

    return c;
}


int merge_count(vector<int>& A, int inicio, int fim){
    int meio;
    int trocas = 0;

    if(inicio < fim){

        meio = (inicio + fim) / 2;

        trocas += merge_count(A, inicio, meio);
        trocas += merge_count(A, meio+1, fim);
        trocas += intercala_count(A, inicio, meio, fim);

    }

    return trocas;

}


int trocas(vector<int>& data){

    int quantidade = 0;

    for(int i = 0; i < data.size(); i++){
        if(data[i] != i){
            quantidade += 2 * (data[i] - i) -1;
            swap(data[i], data[data[i]]);
            i--;
        }
    }

    return quantidade;

}


void pprint(vector<int>& numeros){

    for(int i = 0; i < numeros.size(); i++){
        cout << numeros[i] << " ";
    }

    cout << endl;

}


inline void fastRead_int(int &x)
{
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


int main(){

    vector<int> numeros;
    int n;
    int x;
    int inversoes = 0;

    while(true){
        fastRead_int(n);

        if(n == 0)
            break;

        numeros.clear();

        for(int i = 0; i < n; i++){
            fastRead_int(x);
            x--;
            numeros.push_back(x);
        }

        inversoes = trocas(numeros);

        if( (inversoes % 2) == 0){
            cout << "Carlos" << endl;
        }
        else{
            cout << "Marcelo" << endl;
        }

    }

    return 0;
}
