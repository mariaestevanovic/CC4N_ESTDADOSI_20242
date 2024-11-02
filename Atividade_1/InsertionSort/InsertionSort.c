// Insertion Sort (insertionsort.c): Insere cada elemento na posição correta dentro da porção ordenada do array. Esse algoritmo é 
// eficiente para arrays parcialmente ordenados, já que ele só move elementos enquanto necessário para que o valor atual seja 
// posicionado na ordem correta.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_ARRAY 50

// Função para ordenar o array usando Insertion Sort
void insertionSort(int array[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int valorAtual = array[i];
        int j = i - 1;
        
        // Move elementos do array que são maiores que o valorAtual uma posição à frente
        while (j >= 0 && array[j] > valorAtual) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = valorAtual;  // Insere o valor atual na posição correta
    }
}

// Função para imprimir o array
void exibirArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int numeros[TAMANHO_ARRAY];
    srand(time(0));  // Inicializa a semente para números aleatórios
    
    // Preenche o array com 50 valores aleatórios de 0 a 99
    for (int i = 0; i < TAMANHO_ARRAY; i++) {
        numeros[i] = rand() % 100;
    }

    printf("Array original:\n");
    exibirArray(numeros, TAMANHO_ARRAY);

    // Ordena o array usando Insertion Sort
    insertionSort(numeros, TAMANHO_ARRAY);

    printf("Array ordenado com Insertion Sort:\n");
    exibirArray(numeros, TAMANHO_ARRAY);

    return 0;
}
