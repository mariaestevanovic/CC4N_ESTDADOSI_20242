#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
    int altura;
};

// Função para obter a altura de um nó
int altura(struct Node* N) {
    if (N == NULL) return 0;
    return N->altura;
}

// Função para obter o fator de balanceamento
int obterBalanceamento(struct Node* N) {
    if (N == NULL) return 0;
    return altura(N->esquerda) - altura(N->direita);
}

// Função para criar um novo nó
struct Node* criarNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    novoNo->altura = 1;
    return novoNo;
}

// Funções de rotação
struct Node* rotacaoDireita(struct Node* y) {
    struct Node* x = y->esquerda;
    struct Node* T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    y->altura = 1 + (altura(y->esquerda) > altura(y->direita) ? altura(y->esquerda) : altura(y->direita));
    x->altura = 1 + (altura(x->esquerda) > altura(x->direita) ? altura(x->esquerda) : altura(x->direita));
    return x;
}

struct Node* rotacaoEsquerda(struct Node* x) {
    struct Node* y = x->direita;
    struct Node* T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    x->altura = 1 + (altura(x->esquerda) > altura(x->direita) ? altura(x->esquerda) : altura(x->direita));
    y->altura = 1 + (altura(y->esquerda) > altura(y->direita) ? altura(y->esquerda) : altura(y->direita));
    return y;
}

// Função para inserir um valor na árvore AVL
struct Node* inserir(struct Node* node, int valor) {
    if (node == NULL) return criarNo(valor);
    
    if (valor < node->valor)
        node->esquerda = inserir(node->esquerda, valor);
    else if (valor > node->valor)
        node->direita = inserir(node->direita, valor);
    else
        return node;

    node->altura = 1 + (altura(node->esquerda) > altura(node->direita) ? altura(node->esquerda) : altura(node->direita));

    int balance = obterBalanceamento(node);

    if (balance > 1 && valor < node->esquerda->valor)
        return rotacaoDireita(node);
    if (balance < -1 && valor > node->direita->valor)
        return rotacaoEsquerda(node);
    if (balance > 1 && valor > node->esquerda->valor) {
        node->esquerda = rotacaoEsquerda(node->esquerda);
        return rotacaoDireita(node);
    }
    if (balance < -1 && valor < node->direita->valor) {
        node->direita = rotacaoDireita(node->direita);
        return rotacaoEsquerda(node);
    }

    return node;
}

// Função para exibir a árvore AVL em ordem
void exibirEmOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

int main() {
    struct Node* raiz = NULL;
    int valores[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Árvore AVL em ordem: ");
    exibirEmOrdem(raiz);

    return 0;
}
