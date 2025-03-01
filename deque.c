#include <stdio.h>
#include <stdlib.h>

#define MAX 52 // Tamanho máximo para um baralho

struct deque_ {
    ITEM* itens[MAX];
    int inicio;
    int fim;
    int tamanho;
};

// Função para criar o deque
DEQUE* deque_criar() {
    DEQUE* deque = (DEQUE*) malloc(sizeof(DEQUE));
    if (deque) {
        deque->inicio = 0;
        deque->fim = 0;
        deque->tamanho = 0;
    }
    return deque;
}

// Função para apagar o deque
void deque_apagar(DEQUE** deque) {
    if (deque && *deque) {
        free(*deque);
        *deque = NULL;
    }
}

// Inserir no início do deque
bool deque_inserir_inicio(DEQUE* deque, ITEM* item) {
    if (deque->tamanho == MAX) return false; // Deque cheio
    deque->inicio = (deque->inicio - 1 + MAX) % MAX;
    deque->itens[deque->inicio] = item;
    deque->tamanho++;
    return true;
}

// Inserir no fim do deque
bool deque_inserir_fim(DEQUE* deque, ITEM* item) {
    if (deque->tamanho == MAX) return false; // Deque cheio
    deque->itens[deque->fim] = item;
    deque->fim = (deque->fim + 1) % MAX;
    deque->tamanho++;
    return true;
}

// Remover do início do deque
ITEM* deque_remover_inicio(DEQUE* deque) {
    if (deque->tamanho == 0) return NULL; // Deque vazio
    ITEM* item = deque->itens[deque->inicio];
    deque->inicio = (deque->inicio + 1) % MAX;
    deque->tamanho--;
    return item;
}

// Remover do fim do deque
ITEM* deque_remover_fim(DEQUE* deque) {
    if (deque->tamanho == 0) return NULL; // Deque vazio
    deque->fim = (deque->fim - 1 + MAX) % MAX;
    ITEM* item = deque->itens[deque->fim];
    deque->tamanho--;
    return item;
}

// Retornar o primeiro item
ITEM* deque_primeiro(DEQUE* deque) {
    if (deque->tamanho == 0) return NULL;
    return deque->itens[deque->inicio];
}

// Retornar o último item
ITEM* deque_ultimo(DEQUE* deque) {
    if (deque->tamanho == 0) return NULL;
    int ultimo_index = (deque->fim - 1 + MAX) % MAX;
    return deque->itens[ultimo_index];
}

// Retornar o número de itens no deque
int deque_contar(DEQUE* deque) {
    return deque->tamanho;
}

// Verificar se o deque está vazio
bool deque_vazia(DEQUE* deque) {
    return deque->tamanho == 0;
}

// Verificar se o deque está cheio
bool deque_cheia(DEQUE* deque) {
    return deque->tamanho == MAX;
}
