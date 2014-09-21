#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

void linhas_inuteis(){
    std::string linha;

    /* Le as linhas inuteis */
    std::getline(std::cin, linha);
    std::getline(std::cin, linha);
}

//int[][] dct()

int main(){
    int lado;
    int** mat;
    int** T;
    int** Tt;
    std::string linha;
    std::string aux1, aux2;

    linhas_inuteis();

    /* Dimensoes da imagem */
    std::getline(std::cin, linha);

    /* pseudo-interpreta a linha */
    for(int i=0; linha[i] != ' '; i++){
        aux1 += linha[i];
    }

    lado = (int) strtol(linha.c_str(), NULL, 10);

    /* Aloca a matriz para abrigar os dados da imagem */
    mat = new int*[lado];
    for(int i=0; i<lado; i++){
        mat[i] = new int[lado];
    }
    std::cout <<"Alocada matriz da imagem [" << lado << "][" << lado << "]\n";

    /* Aloca as matrizes auxiliares 8x8 */
    T = new int*[8];
    Tt = new int*[8];
    for(int i=0; i<8; i++){
        T[i] = new int[8];
        Tt[i] = new int[8];
    }
    std::cout << "Alocadas matrizes auxiliares [8][8]\n";


    /* Mais uma linha inutil */
    std::getline(std::cin, linha);

    /* Popula a matriz da imagem */
    for(int i=0; i<160; i++){
        for(int j=0; j<160; j++){
            std::getline(std::cin, linha);
            mat[i][j] = (int) strtol(linha.c_str(), NULL, 10);
        }
    }

    std::cout << "Populada a matriz com os dados da imagem\n";
    return 0;
}
