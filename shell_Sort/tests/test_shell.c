#include <stdio.h>
#include "../include/shell_Sort.h"

void print_array(int *v, int n, const char *label) {
    printf("%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void test_best_case() {
    printf("\n=== TESTE: MELHOR CASO ===\n");
    // Vetor já ordenado (n = 8). Gaps: 4, 2, 1
    int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    print_array(v, 8, "Antes");
    
    // Ponto ideal para colocar um breakpoint no GDB
    shell_sort(v, 8);
    
    print_array(v, 8, "Depois");
}

void test_worst_case() {
    printf("\n=== TESTE: PIOR CASO ===\n");
    // Vetor desenhado para o pior caso com gaps N/2 (N = 8, gaps = 4, 2, 1)
    // Maiores nas posições pares, menores nas ímpares, sempre ordenados entre si.
    // Assim eles não realizam trocas nos gaps pares (4 e 2), empurrando todo o
    // trabalho pesado para o gap 1 (virando um Insertion Sort massivo).
    int v[8] = {10, 1, 11, 2, 12, 3, 13, 4};
    
    print_array(v, 8, "Antes");
    
    // Ponto ideal para colocar um breakpoint no GDB
    shell_sort(v, 8);
    
    print_array(v, 8, "Depois");
}

int main() {
    test_best_case();
    test_worst_case();
    return 0;
}
