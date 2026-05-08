#ifndef SHELL_SORT_H
#define SHELL_SORT_H

/**
 * Ordena um vetor utilizando o algoritmo Shell Sort.
 *
 * @param v Ponteiro para o vetor a ser ordenado.
 * @param n Tamanho do vetor.
 */
void shell_sort(int *v, int n);

/* Contadores de instrumentação — exportados para uso no harness de teste.
 * Zerados manualmente antes de cada chamada para medir isoladamente. */
extern long long g_comparacoes; /* total de comparações no laço j */
extern long long g_trocas;      /* comparações que deslocaram elemento */
extern long long g_sem_troca;   /* comparações que NÃO deslocaram */

#endif /* SHELL_SORT_H */
