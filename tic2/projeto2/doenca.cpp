#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

// C stuff
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Constantes
#define N 7
#define tmax 1000.
#define dt 0.01

#define lambda 0.005555556
#define beta 0.071428571
#define zeta 0.166666667
#define alfa 0.1
#define mu 1.309
#define sigma 0.1309
#define omega_1 0.00654
#define omega_2 0.008

using namespace std;

struct Continente{

    /* Populacoes do continente */
    long double S;
    long double I;
    long double E;
    long double R;
    long double V;

    /* Peso da forca de infeccao */
    long double peso;

    /* Construtor */
    Continente(long double I, long double peso){

        this->E = 0;
        this->R = 0;
        this->V = 0;

        this->I = I * peso;
        this->S = 1 - this->I;

        this->peso = peso;
    }

};

vector<Continente> cont;

void le_entrada(char** args, double* gamaT, double* delta, double* I){
    *gamaT =  (double) strtod(args[1], (char**) NULL);
    *delta =  (double) strtod(args[2], (char**) NULL);
    *I =  (double) strtod(args[3], (char**) NULL);
}

void Doenca(double delta, double gamaT, double psiT, vector<vector<double> > mat){
    double dS[N], dE[N], dI[N], dR[N], dV[N], gama=0, psi=0;
    double t, soma;
    int j, y;
    vector<int> NP(N);

    //Arquivo para o grafico
    char impr_doenca[] = "doenca.txt";
    FILE *arq;
    //Abertura do arquivo
    arq = fopen(impr_doenca, "w");

    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    fill(NP.begin(), NP.end(), 1);

    for(t=dt; t<tmax; t+=dt){

        for(j=0; j<N; j++){
            //Verifica o quanto de populacao que ira nascer
            gama = (omega_1*(cont[j].S+cont[j].E+cont[j].R+cont[j].V) +
                    omega_2*cont[j].I)*gamaT;
            psi = (omega_1*(cont[j].S+cont[j].E+cont[j].R+cont[j].V) +
                    omega_2*cont[j].I)*psiT;

            //Taxa de variacao da populacao sucetivel
            dS[j] = (lambda*cont[j].R + gama - (mu * cont[j].peso)*cont[j].I*cont[j].S -
                    omega_1*cont[j].S - delta*cont[j].S -
                    sigma*cont[j].E*cont[j].S)*dt;

            //Taxa de variacao da populacao exposta
            dE[j] = ((mu * cont[j].peso)*cont[j].I*
                    cont[j].S + alfa*cont[j].I + sigma*cont[j].E*cont[j].S -
                    omega_1*cont[j].E - beta*cont[j].E -
                    zeta*cont[j].E)*dt;

            //Taxa de variacao da populacao infectada
            dI[j] = (zeta*cont[j].E - omega_2*cont[j].I - alfa*cont[j].I)*dt;

            //Taxa variacao da populacao recuperada
            dR[j] = (beta*cont[j].E - lambda*cont[j].R - omega_1*cont[j].R)*dt;

            //Taxa de variacao da populacao vacinada
            dV[j] = (delta*cont[j].S + psi - omega_1*cont[j].V)*dt;

            /* Atualiza as derivadas com base na matriz de coeficientes */
            for(y=0; y<N; y++){
                dS[j] -= (mat[j][y] * 10 * cont[j].S * cont[y].I) * dt;
                dE[j] += (mat[j][y] * 10 * cont[j].S * cont[y].I) * dt;
            }

            if((fabs(dS[j]) <= 0.00001 && fabs(dE[j]) <= 0.00001) &&
               (fabs(dI[j]) <= 0.00001 && fabs(dR[j]) <= 0.00001) &&
                fabs(dV[j]) <= 0.00001){
                NP[j] = 0;
            }
        }

        fprintf(arq, "%lf\t", t);

        soma = 0;
        for(j=0; j<N; j++){

            cont[j].S += dS[j];
            cont[j].E += dE[j];
            cont[j].I += dI[j];
            cont[j].R += dR[j];
            cont[j].V += dV[j];

            fprintf(arq,"%llf\t", cont[j].I);
            soma += NP[j];
        }


        fprintf(arq,"\n");


        if(soma == 0 && t >= tmax / 100){
            t = tmax;
        }
    }
}

int main(int a, char** args){
    double gamaT; //Porcentagem de pessoas que nascem e nao sao vacinadas
    double delta; //Porcentagem de pessoas que sao vacinas adultas
    double psiT;
    double I;
    int i, j;

    vector<vector<double> > pesos(N);

    for(int a=0; a<N; a++){
        pesos[a].resize(N);
        fill(pesos[a].begin(), pesos[a].end(), 0);
    }

    /* Preenche a matriz de coeficientes "migratorios" */
    pesos = {
        {0.000000, 0.002236, 0.002031, 0.001472, 0.001929, 0.002540, 0.001893},  // America do Norte
        {0.002236, 0.000000, 0.000487, 0.001291, 0.002435, 0.002263, 0.000380},  // America do Sul
        {0.002031, 0.000487, 0.000000, 0.001916, 0.002161, 0.002507, 0.000370}, // America Central
        {0.001472, 0.001291, 0.001916, 0.000000, 0.002569, 0.002733, 0.002585}, // Oceania
        {0.001929, 0.002435, 0.002161, 0.002569, 0.000000, 0.001814, 0.001480},  // Asia
        {0.002540, 0.002263, 0.002507, 0.002733, 0.001814, 0.000000, 0.001029},  // Europa
        {0.001893, 0.000380, 0.000370, 0.002585, 0.001480, 0.001029, 0.000000}    // Africa
    };

    le_entrada(args, &gamaT, &delta, &I);
    psiT = 1 - gamaT;

    /* America do norte */
    cont.push_back(Continente(0, 1 - ((0.902 + 0.914 + 0.756)/3) ));

    /* America do Sul */
    cont.push_back(Continente(0, 1 - 0.740));

    /* America Central */
    cont.push_back(Continente(0, 1 - 0.740));

    /* Oceania */
    cont.push_back(Continente(0, 1 - ((0.933 + 0.684 + 0.910)/3) ));

    /* Asia */
    cont.push_back(Continente(0, 1 - ((0.738 + 0.703 + 0.588)/3) ));

    /* Europa */
    cont.push_back(Continente(0, 1 - 0.738));

    /* Africa */
    cont.push_back(Continente(I, 1 - 0.502 ));

    Doenca(delta, gamaT, psiT, pesos);

    return 0;
}
