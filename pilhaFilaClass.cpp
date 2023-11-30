#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* prox;
};

struct Fila {
    struct No* inicio;
    struct No* fim;
    int n;
};

void inicializarFila(struct Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->n = 0;
}

int isFilaVazia(struct Fila* fila) {
    return fila->inicio == NULL;
}

void enqueue(struct Fila* fila, int value) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = value;
    novo->prox = NULL;

    if (isFilaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fila->n++;
}

int dequeue(struct Fila* fila) {
    if (isFilaVazia(fila)) {
        printf("Erro: Fila vazia\n");
        return -1;
    }

    struct No* r = fila->inicio;
    int value = r->valor;
    fila->inicio = r->prox;
    free(r);
    fila->n--;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return value;
}

void inverterOrdem(struct Fila* fila) {
    struct No* anterior = NULL;
    struct No* atual = fila->inicio;
    struct No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    fila->inicio = anterior;
}

void imprimirFila(struct Fila* fila) {
    struct No* aux = fila->inicio;

    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

int main() {
    struct Fila minhaFila;
    inicializarFila(&minhaFila);

    enqueue(&minhaFila, 1);
    enqueue(&minhaFila, 2);
    enqueue(&minhaFila, 3);

    printf("Fila original:\n");
    imprimirFila(&minhaFila);

    inverterOrdem(&minhaFila);

    printf("Fila invertida:\n");
    imprimirFila(&minhaFila);

    return 0;
}



