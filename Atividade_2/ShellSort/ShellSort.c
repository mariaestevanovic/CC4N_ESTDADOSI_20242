// O Shellsort usa um intervalo (gap) para dividir e ordenar elementos distantes, reduzindo-o gradualmente até que se torne 1.
#include <stdio.h>

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: ");
    printArray(arr, n);
    
    shellSort(arr, n);
    
    printf("Array ordenado com Shellsort: ");
    printArray(arr, n);
    return 0;
}

// Complexidade de Tempo:
//   Melhor Caso: O(nlogn)
//   Caso Médio: O((nlogn)^2)
//   Pior Caso: O(n^2)
// Complexidade de Espaço: O(1)