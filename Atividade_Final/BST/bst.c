#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore
struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
};

// Função para criar um novo nó com o valor especificado
struct Node* criarNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na BST
struct Node* inserir(struct Node* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

// Função para buscar um valor na BST
struct Node* buscar(struct Node* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    else
        return buscar(raiz->direita, valor);
}

// Função para encontrar o menor valor (usada na remoção)
struct Node* encontrarMinimo(struct Node* raiz) {
    while (raiz->esquerda != NULL) raiz = raiz->esquerda;
    return raiz;
}

// Função para remover um nó específico da BST
struct Node* remover(struct Node* raiz, int valor) {
    if (raiz == NULL) return raiz;
    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL) {
            struct Node* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        struct Node* temp = encontrarMinimo(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

// Função para exibir a árvore em ordem (crescente)
void exibirEmOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

int main() {
    struct Node* raiz = NULL;
    int valores[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);
    
    // Inserir valores na árvore
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Árvore em ordem: ");
    exibirEmOrdem(raiz);

    int valorBusca = 40;
    struct Node* encontrado = buscar(raiz, valorBusca);
    if (encontrado)
        printf("\nValor %d encontrado na árvore.\n", valorBusca);
    else
        printf("\nValor %d não encontrado na árvore.\n", valorBusca);

    // Remover um valor e exibir a árvore novamente
    raiz = remover(raiz, 30);
    printf("Árvore após remover 30: ");
    exibirEmOrdem(raiz);

    return 0;
}
