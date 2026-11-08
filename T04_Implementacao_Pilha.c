#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* topo;
    int tamanho;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

// Empilhar (Push)
bool empilha(Pilha* p, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) return false;
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
    return true;
}

// Desempilhar (Pop)
int desempilha(Pilha* p) {
    if (!p || !p->topo) return -1;
    No* aux = p->topo;
    int valor = aux->dado;
    p->topo = p->topo->prox;
    free(aux);
    p->tamanho--;
    return valor;
}

void imprime(Pilha* p) {
    for (No* aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("[%d] ", aux->dado);
    }
    printf("\n");
}

int main() {
    Pilha* p = criarPilha();
    empilha(p, 10);
    empilha(p, 20);
    empilha(p, 40);

    imprime(p); // Exibe: [40] [20] [10] 
    desempilha(p);
    imprime(p); // Exibe: [20] [10]

    return 0;
}