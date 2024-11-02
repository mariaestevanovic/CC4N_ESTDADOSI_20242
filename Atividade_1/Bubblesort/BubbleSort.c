// Bubble Sort: Compara pares de elementos adjacentes e os troca se estiverem fora de ordem. Esse processo se repete até que todos
// os elementos estejam ordenados. O algoritmo faz múltiplas "passadas" pelo array, empurrando os maiores valores para o final em 
// cada iteração externa.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_ARRAY 50

// Função para ordenar o array usando Bubble Sort
void bubbleSort(int array[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {  // Passa por todos os elementos do array
        for (j = 0; j < tamanho - i - 1; j++) {  // Comparação entre elementos adjacentes
            if (array[j] > array[j + 1]) {
                // Troca os elementos se estiverem na ordem errada
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
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

    // Ordena o array usando Bubble Sort
    bubbleSort(numeros, TAMANHO_ARRAY);

    printf("Array ordenado com Bubble Sort:\n");
    exibirArray(numeros, TAMANHO_ARRAY);

    return 0;
}
