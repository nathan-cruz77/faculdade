#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 1
#define tmax 10
#define dt 0.01

//Constantes
#define lambda 0.005555556
#define beta 0.071428571
#define zeta 0.166666667
#define alfa 0.1
#define mu 0.084
#define sigma 0.0084
#define omega_1 0.00654
#define omega_2 0.1


void le_entrada(char** args, double* gamaT, double* delta, double* I){
	*gamaT =  (double) strtod(args[1], (char**) NULL);
	*delta =  (double) strtod(args[2], (char**) NULL);
	*I =  (double) strtod(args[3], (char**) NULL);
	
}

void Doenca(double delta, double gamaT, double psiT, double S, double I){
	double dS, dE, dI, dR, dV, gama=0, psi=0;
	double E=0, R=0, V=0;
	double t;
	
	//Arquivo para o grafico
    char impr_doenca[] = "doenca.txt";
    FILE *arq;
    //Abertura do arquivo
    arq = fopen(impr_doenca, "w");

    if(arq == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
        return ;
    }
	
	for(t=0; t<tmax; t+=dt){

	    //Verifica o quanto de populacao que ira nascer
	    gama = (omega_1*(S+E+R+V) + omega_2*I)*gamaT;
	    psi = (omega_1*(S+E+R+V) + omega_2*I)*psiT;

	    //Taxa de variacao da populacao sucetivel
	    dS = (lambda*R + gama - mu*I*S - omega_1*S - delta*S - sigma*E*S)*t;
	    
	    //Taxa de variacao da populacao exposta
	    dE = (mu*I*S + alfa*I + sigma*E*S - omega_1*E - beta*E - zeta*E)*t;
	    
	    //Taxa de variacao da populacao infectada
	    dI = (zeta*E - omega_2*I - alfa*I)*t;
	    
	    //Taxa variacao da populacao recuperada
	    dR = (beta*E - lambda*R - omega_1*R)*t;
	    
	    //Taxa de variacao da populacao vacinada
	    dV = (delta*S + psi - omega_1*V)*t;
	    
	    //Acrescenta a taxa na populacao correspondente
	    S += dS;
	    E += dE;
	    I += dI;
	    R += dR;
	    V += dV;

	    /*printf("S = %f\n",S);
	    printf("E = %f\n",E);
	    printf("I = %f\n",I);
	    printf("R = %f\n",R);
	    printf("V = %f\n",V);
	    printf("S+E+I+R+V = %f\n",S+E+I+R+V);*/

	    fprintf(arq,"%f\t%f\t%.2f\n",S,I, t);
	}
}

void main(int a, char** args){
	double gamaT; //Porcentagem de pessoas que nascem e nao sao vacinadas
	double delta; //Porcentagem de pessoas que sao vacinas adultas
	double psiT;
	double S; //Porcentagem de pessoas sucetiveis
	double I; //Porcentagem de pessoas infectadas

	le_entrada(args, &gamaT, &delta, &I);
    psiT = 1 - gamaT;
    S = 1 - I;
	
	Doenca(delta,gamaT,psiT,S,I);
}
