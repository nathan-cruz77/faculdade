#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

#define PI 3.14159265

void linhas_inuteis(){
    std::string linha;

    /* Le as linhas inuteis */
    std::getline(std::cin, linha);
    std::getline(std::cin, linha);
}

double** aloca_matriz(int n){
    double** mat = new double*[n];

    for(int i=0; i<n; i++){
        mat[i] = new double[n];
    }

    return mat;
}

void mat_transformacao(double** T, double** Tt){

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i == 0)
                T[i][j] = 1/sqrt(8);
            else
                T[i][j] = sqrt(2/8.0) * cos(((2*j+1)*i*PI)/16.0);

            Tt[j][i] = T[i][j];
        }
    }
}

void inicializa(double** A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            A[i][j] = 0;
    }
}

int conta_zeros(double** A, int n){
    int aux=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == 0)
                aux++;
        }
    }

    return aux;
}

double** multiplica(double** A, double** B, int ordem){
    double** matrizResultado = aloca_matriz(ordem);
    inicializa(matrizResultado, ordem);

    // multiplica
    for (int i=0; i<ordem; i++) {
        for (int j=0; j<ordem; j++) {
            for (int k=0; k<ordem; k++) {
               matrizResultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return matrizResultado;
}

void dct(int lin, int col, double** T, double** M, double** Tt){
    double** aux = aloca_matriz(8);

    for(int i=lin, a=0; i<lin+8; i++, a++){
        for(int j=col, b=0; j<col+8; j++, b++){
            aux[a][b] = M[i][j];
        }
    }

    aux = multiplica(multiplica(T, aux, 8), Tt, 8);

    for(int i=lin, a=0; i<lin+8; i++, a++){
        for(int j=col, b=0; j<col+8; j++, b++){
            M[i][j] = aux[a][b];
        }
    }
}

int main(){
    int ordem, zeros_iniciais, zeros_finais;
    double **mat, **T, **Tt;
    std::string linha, aux1;

    linhas_inuteis();

    /* Dimensoes da imagem */
    std::getline(std::cin, linha);

    /* pseudo-interpreta a linha */
    for(int i=0; linha[i] != ' '; i++){
        aux1 += linha[i];
    }

    ordem = (int) strtol(linha.c_str(), NULL, 10);

    /* Aloca todas as matrizes necessarias */
    mat = aloca_matriz(ordem);
    T = aloca_matriz(8);
    Tt = aloca_matriz(8);

    double q10[8][8] = {{ 80,  60,  50,  80, 120, 200, 255, 255},
                        { 55,  60,  70,  95, 130, 255, 255, 255},
                        { 70,  65,  80, 120, 200, 255, 255, 255},
                        { 70,  85, 110, 145, 255, 255, 255, 255},
                        { 90, 110, 185, 255, 255, 255, 255, 255},
                        {120, 175, 255, 255, 255, 255, 255, 255},
                        {245, 255, 255, 255, 255, 255, 255, 255},
                        {255, 255, 255, 255, 255, 255, 255, 255} };

    /* Pega o "pixel-depth" da imagem */
    std::getline(std::cin, linha);

    /* Popula a matriz da imagem */
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            std::getline(std::cin, linha);
            mat[i][j] = (double) strtol(linha.c_str(), NULL, 10);

            /* Shift para forcar os dados a cruzarem o zero */
            mat[i][j] -= 128;
        }
    }

    zeros_iniciais = conta_zeros(mat, ordem);

    /* Gera a matriz de transformacao e sua transposta */
    mat_transformacao(T, Tt);

    for(int i=0; i<ordem; i+=8){
        for(int j=0; j<ordem; j+=8){
            dct(i, j, T, mat, Tt);
        }
    }

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            mat[i][j] = round(mat[i][j]/q10[i%8][j%8]);
        }
    }

    zeros_finais = conta_zeros(mat, ordem);

    /* Desfaz a etapa de quantizacao */
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            mat[i][j] = mat[i][j]*q10[i%8][j%8];
        }
    }

    /* Desfaz o DCT */
    for(int i=0; i<ordem; i+=8){
        for(int j=0; j<ordem; j+=8){
            dct(i, j, Tt, mat, T);
        }
    }

    /* Desfaz o shift e o round */
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            mat[i][j] = round(mat[i][j]) + 128;
        }
    }

    std::cout << "P2\n";
    std::cout << "# Imagem produto do DCT\n";
    std::cout << "# Zeros descartados " << zeros_finais - zeros_iniciais;
    std::cout << "/" << ordem*ordem <<  "\n";
    std::cout << ordem << " " << ordem << "\n";
    std::cout << "255\n";

    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            std::cout << (int) mat[i][j] << "\n";
        }
    }

    return 0;
}
