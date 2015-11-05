#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 7
#define tmax 100.
#define dt 0.01

//Constantes
#define lambda 0.005555556
#define beta 0.071428571
#define zeta 0.166666667
#define alfa 0.1
#define mu 1.309
#define sigma 0.1309
#define omega_1 0.00654
#define omega_2 0.0001

typedef struct{

    /* Populacoes do continente */
    long double S;
    long double I;
    long double E;
    long double R;
    long double V;

    /* Coeficientes migratorios */
    long double fluxo;

    /* Coeficientes da forca de infeccao */
    long double aumenta;
    long double diminui;

} Continente;

Continente cont[N];
double mat[N][N];

void le_entrada(char** args, double* gamaT, double* delta, double* I){
    *gamaT =  (double) strtod(args[1], (char**) NULL);
    *delta =  (double) strtod(args[2], (char**) NULL);
    *I =  (double) strtod(args[3], (char**) NULL);
}

void Doenca(double delta, double gamaT, double psiT){
    double dS[N], dE[N], dI[N], dR[N], dV[N], gama=0, psi=0;
    double t, soma;
    int j, y;
    int NP[N];

    //Arquivo para o grafico
    char impr_doenca[] = "doenca.txt";
    FILE *arq;
    //Abertura do arquivo
    arq = fopen(impr_doenca, "w");

    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }

    for(t=dt; t<tmax; t+=dt){

        for(j=0; j<N; j++){
            //Verifica o quanto de populacao que ira nascer
            gama = (omega_1*(cont[j].S+cont[j].E+cont[j].R+cont[j].V) +
                    omega_2*cont[j].I)*gamaT;
            psi = (omega_1*(cont[j].S+cont[j].E+cont[j].R+cont[j].V) +
                    omega_2*cont[j].I)*psiT;

            //Taxa de variacao da populacao sucetivel
            dS[j] = (lambda*cont[j].R + gama - (mu)*cont[j].I*cont[j].S -
                    omega_1*cont[j].S - delta*cont[j].S -
                    sigma*cont[j].E*cont[j].S)*dt;

            //Taxa de variacao da populacao exposta
            dE[j] = ((mu)*cont[j].I*
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
                dS[j] -= (mat[j][y] * cont[j].S * cont[y].I) * dt;
                dE[j] += (mat[j][y] * cont[j].S * cont[y].I) * dt;
            }

            if((fabs(dS[j]) <= 0.00001 && fabs(dE[j]) <= 0.00001) &&
               (fabs(dI[j]) <= 0.00001 && fabs(dR[j]) <= 0.00001) &&
                fabs(dV[j]) <= 0.00001){
                NP[j] = 0;
            }
        }

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
        fprintf(arq, "%lf\n", t);

        if(soma == 0){
            t = tmax;
        }
    }
}

void main(int a, char** args){
    double gamaT; //Porcentagem de pessoas que nascem e nao sao vacinadas
    double delta; //Porcentagem de pessoas que sao vacinas adultas
    double psiT;
    double I;
    int i, j;

	/* Inicializa a matriz de coeficientes de turismo */
	/*
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			mat[i][j] = 0;
		}
	}
	*/

	mat = {
		{0, 0.000367, 0.001088, 0.001168, 0.002275, 0.002522, 0.000537}, // America do norte
		{0.002236, 0, 0.000300, 0.001174, 0.000838, 0.001597, 0.001291}, // America do Sul
		{0.002031, 0.000487, 0, 0.000796, 0.000278, 0.001969, 0.000692}, // America Central
		{0.001472, 0.001291, 0.001916, 0, 0.001353, 0.000386, 0.002559}, // Oceania
		{0.001929, 0.002435, 0.002161, 0.002569, 0, 0.002628, 0.000800}, // Asia
		{0.002540, 0.002263, 0.002507, 0.002733, 0.001814, 0, 0.002232}, // Europa
		{0.001893, 0.000380, 0.000037, 0.002585, 0.001480, 0.001029, 0}  // Africa
	};

    le_entrada(args, &gamaT, &delta, &I);
    psiT = 1 - gamaT;

    for(i=0; i<N; i++){
        cont[i].E = 0;
        cont[i].R = 0;
        cont[i].V = 0;
        cont[i].I = I;
        cont[i].S = 1 - I;
    }

    Doenca(delta,gamaT,psiT);
}
