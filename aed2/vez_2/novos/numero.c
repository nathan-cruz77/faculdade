#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    double real;
    double imaginario;
} Complexo;

typedef Complexo* Pcomplexo;


Pcomplexo iniciar_complexo(double real, double imaginario){
    /* Inicia um numero complexo com partes, real e imaginaria, determinada
     * por `real` e `imaginario`, respectivamente
     * retorna uma referencia ao numero criado */

    Pcomplexo complexo = (Pcomplexo) malloc(sizeof(Complexo));

    complexo->real = real;
    complexo->imaginario = imaginario;

    return complexo;
}

void imprimir_complexo(Pcomplexo complexo){
    /* Imprime o numero complexo `complexo` na forma 'R + Ci' */

    printf("\n%.2f + %.2f i\n", complexo->real, complexo->imaginario);
}

int copiar_complexo(Pcomplexo c1, Pcomplexo c2){
    /* Copia o valor de um numero complexo `c1` para outro numero
     * complexo `c2`
     * retorna -1 em caso de erro
     * retorna 0 em caso de sucesso */

    if(c1 == NULL || c2 == NULL){
        return -1;
    }

    c2->real = c1->real;
    c2->imaginario = c1->imaginario;

    return 0;
}

Pcomplexo somar_complexo(Pcomplexo c1, Pcomplexo c2){
    /* Soma dois numeros complexos, `c1` e `c2`
     * retorna uma referencia ao numero resultante */

    Pcomplexo result = iniciar_complexo(0, 0);

    result->real = c1->real + c2->real;
    result->imaginario = c1->imaginario + c2->imaginario;

    return result;
}

bool eh_real(Pcomplexo complexo){
    /* Testa se um numero eh real
     * retorna true em caso verdadeiro
     * retorna false em caso falso */

    if(complexo->imaginario == 0){
        return true;
    }

    return false;
}

int main(){
    /* Teste do TAD */

    Pcomplexo c = iniciar_complexo(0, 0);

    imprimir_complexo(c);
    copiar_complexo(iniciar_complexo(10.654, 65.1235), c);
    imprimir_complexo(c);
    c = somar_complexo(c, iniciar_complexo(123, 6589.11));
    imprimir_complexo(c);

    if(eh_real(c)){
        printf("\ntrue\n");
    }
    else{
        printf("\nfalse\n");
    }

    if(eh_real(iniciar_complexo(12.54, 0))){
        printf("\ntrue\n");
    }
    else{
        printf("\nfalse\n");
    }

    return 0;
}
