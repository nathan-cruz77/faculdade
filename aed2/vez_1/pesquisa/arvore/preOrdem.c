#include <stdio.h>
#include <stdlib.h>

typedef int TChave;
typedef struct {
    TChave Chave;
    /* outros compomentes */
} TItem;

typedef struct SNo *TArvore;
typedef struct SNo {
    TItem Item;
    TArvore ArvEsq, ArvDir;
} TNo;

TArvore Carrega() {
    char c;
    TArvore No;
    scanf("%c", &c);
    if (c == '(') {
        scanf("%c", &c);
        if (c == 'C') {
            No = (TArvore) malloc(sizeof(TNo));
            scanf("%d", &No->Item.Chave);
            No->ArvEsq = Carrega();
            No->ArvDir = Carrega();
            scanf("%c", &c);
        }
        else if (c == ')') 
            No = NULL;
    } return No;
} 

void Libera(TArvore *pNo) {
    TArvore No;
    No = *pNo;
    if (No != NULL) { 
        Libera(&No->ArvEsq);
        Libera(&No->ArvDir);
        free(No);
        (*pNo) = NULL;
    }
}

/* Pre-ordem */
void Percurso(TArvore No) { 
    if(No == NULL) return;
    printf("%d\n", No->Item.Chave);
    Percurso(No->ArvEsq);
    Percurso(No->ArvDir);
}

int main() {
    TArvore Raiz;
    Raiz = Carrega();
    Percurso(Raiz);
    Libera(&Raiz);
    return 0;
} 
