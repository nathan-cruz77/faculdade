#include <stdlib.h>
#include <stdio.h>

/* Tipo conta */
typedef struct{
   int numero;
  double saldo;
} Conta;

typedef Conta* Pconta;

Pconta iniciar_conta(int num, double saldo){
    /* Inicia a Conta com numero e saldo determinados
     * retorna uma referencia a conta criada */

    Pconta conta = (Pconta) malloc(sizeof(Conta));

    conta->numero = num;
    conta->saldo = saldo;

    return conta;
}

int depositar(Pconta conta, double valor){
    /* Deposita em `conta` o valor `valor`
     * retorna -1 em caso de erro
     * retorna 0 em caso de sucesso */

    if(valor <= 0){
        return -1;
    }

    conta->saldo += valor;

    return 0;
}

int sacar(Pconta conta, double valor){
    /* Deposita em `conta` o valor `valor`
     * retorna -1 em caso de erro
     * retorna 0 em caso de sucesso */

    if(valor > conta->saldo || valor <= 0){
        return -1;
    }

    conta->saldo -= valor;

    return 0;
}

void imprime_saldo(Pconta conta){
    /* Imprime o valor do saldo da conta `conta` */

    printf("\nSaldo: %.2f\n", conta->saldo);
}


int main(){
    /* Teste do TAD */

    Pconta conta = iniciar_conta(1, 0);
    depositar(conta, 10);
    imprime_saldo(conta);
    sacar(conta, 2);
    imprime_saldo(conta);

    return 0;
}
