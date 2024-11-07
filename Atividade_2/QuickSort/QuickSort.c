// O Quicksort usa um pivô e particiona o array em duas partes. É recursivo e eficiente em muitos casos práticos.

#include <stdio.h>

void trocar(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particionar(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = particionar(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: ");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    printf("Array ordenado com Quicksort: ");
    printArray(arr, n);
    return 0;
}

// Complexidade de Tempo:
//   Melhor Caso: O(nlogn)
//   Caso Médio: O(nlogn)
//   Pior Caso: O(n^2)
// Complexidade de Espaço: O(logn)