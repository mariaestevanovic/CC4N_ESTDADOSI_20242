// Selection Sort (selectionsort.c): Em cada posição do array, encontra o menor valor no restante do array e o troca com o elemento 
// na posição atual. Esse processo garante que os menores elementos sejam colocados nas primeiras posições, em ordem crescente.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_ARRAY 50

// Função para ordenar o array usando Selection Sort
void selectionSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[indiceMenor]) {
                indiceMenor = j;  // Atualiza o índice do menor valor encontrado
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        int temp = array[indiceMenor];
        array[indiceMenor] = array[i];
        array[i] = temp;
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

    // Ordena o array usando Selection Sort
    selectionSort(numeros, TAMANHO_ARRAY);

    printf("Array ordenado com Selection Sort:\n");
    exibirArray(numeros, TAMANHO_ARRAY);

    return 0;
}
