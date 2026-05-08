/* ==========================================================================
 * test_shell.c — Harness de teste para análise didática com GDB
 *
 * Dois cenários são executados em sequência:
 *
 *   test_best_case()  → vetor já ordenado  → mínimo de comparações → Ω(n log n)
 *   test_worst_case() → vetor adverso      → máximo de comparações → O(n²)
 *
 * Para cada caso, os contadores globais (g_comparacoes, g_trocas, g_sem_troca)
 * são zerados antes da chamada e impressos ao final, confirmando a teoria.
 * =========================================================================*/

#include "../include/shell_Sort.h"
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------
 * Utilitários de apresentação
 * --------------------------------------------------------------------- */
static void print_array(int *v, int n, const char *label) {
  printf("  %-8s [ ", label);
  for (int i = 0; i < n; i++) {
    printf("%3d", v[i]);
    if (i < n - 1)
      printf(", ");
  }
  printf(" ]\n");
}

static void print_separator(void) {
  printf("  %s\n", "─────────────────────────────────────────────────────");
}

static void reset_counters(void) {
  g_comparacoes = 0;
  g_trocas = 0;
  g_sem_troca = 0;
}

static void print_report(void) {
  printf("\n  ┌─── Relatório de Operações ─────────────────────────┐\n");
  printf("  │  Comparações totais  (laço j):  %8lld               │\n",
         g_comparacoes);
  printf("  │  Com deslocamento   (troca):    %8lld               │\n",
         g_trocas);
  printf("  │  Sem deslocamento   (sem troca):%8lld               │\n",
         g_sem_troca);
  printf("  └────────────────────────────────────────────────────┘\n");
}

/* =========================================================================
 * MELHOR CASO — Vetor já ordenado (n = 8)
 *
 * v = { 1, 2, 3, 4, 5, 6, 7, 8 }
 *
 * Gaps usados: 4 → 2 → 1
 *
 * Em TODOS os gaps, a condição `v[j-gap] > temp` será FALSA imediatamente,
 * pois o vetor já está ordenado. O laço j nunca executa seu corpo.
 *
 * Expectativa teórica: ≈ n·log₂(n) comparações, 0 trocas.
 *   n=8, log₂(8)=3 → S ≈ 8·3 = 24 → ~S comparações sem troca.
 *
 * GDB — sugestão de breakpoints:
 *   break shell_sort   (BP-1: observe gap a cada fase)
 *   break 47           (BP-2: elemento sendo considerado, temp = v[i])
 *   break 57           (BP-3: linha da comparação no laço j)
 *   Não há BP-4 aqui:  o corpo do laço j nunca executa no melhor caso.
 *   break 70           (BP-5: v[j] = temp, sempre j == i, sem mover)
 * ========================================================================= */
void test_best_case(void) {
  int v[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  int n = 8;

  printf("\n");
  printf("╔══════════════════════════════════════════════════════╗\n");
  printf("║          MELHOR CASO — Vetor Já Ordenado            ║\n");
  printf("║   Complexidade esperada: Ω(n log n)                 ║\n");
  printf("╚══════════════════════════════════════════════════════╝\n");
  print_separator();

  print_array(v, n, "Entrada");
  printf("  Gaps: 4 → 2 → 1\n");
  printf("  Hipótese: `v[j-gap] > temp` sempre FALSA → 0 trocas\n");
  print_separator();

  reset_counters();

  /* ── BREAKPOINT SUGERIDO: antes de chamar shell_sort ──────────────────
   * (gdb) break test_best_case
   * (gdb) break shell_sort
   * (gdb) watch g_trocas          ← dispara quando há deslocamento
   * ─────────────────────────────────────────────────────────────────── */
  shell_sort(v, n);

  print_array(v, n, "Saída");
  print_report();
}

/* =========================================================================
 * PIOR CASO — Vetor adverso (n = 8, sequência de Shell)
 *
 * v = { 10, 1, 11, 2, 12, 3, 13, 4 }
 *
 * Construção: maiores nas posições PARES (0,2,4,6), menores nas ÍMPARES
 * (1,3,5,7). Os pares e ímpares já estão ordenados entre si → gap=4 e gap=2 não
 * produzem trocas entre os grupos, acumulando todo o trabalho no gap=1. No
 * gap=1, o algoritmo degenera num Insertion Sort sobre o vetor
 * quase-embaralhado.
 *
 * Expectativa teórica: comparações ≈ O(n²), maioria resultando em trocas.
 *
 * GDB — sugestão de breakpoints:
 *   break shell_sort   (BP-1: observe gap — repare que gap=4 e gap=2 geram
 * poucas trocas) break 47           (BP-2: temp = v[i], anote qual elemento
 * entra) break 57           (BP-3: comparação — verifique v[j-gap] vs temp)
 *   break 65           (BP-4: TROCA confirmada — v[j] = v[j-gap])
 *   break 70           (BP-5: inserção final — v[j] = temp)
 * ========================================================================= */
void test_worst_case(void) {
  int v[8] = {10, 1, 11, 2, 12, 3, 13, 4};
  int n = 8;

  printf("\n");
  printf("╔══════════════════════════════════════════════════════╗\n");
  printf("║          PIOR CASO — Vetor Adverso                  ║\n");
  printf("║   Complexidade esperada: O(n²)                      ║\n");
  printf("╚══════════════════════════════════════════════════════╝\n");
  print_separator();

  print_array(v, n, "Entrada");
  printf("  Gaps: 4 → 2 → 1\n");
  printf("  Hipótese: maioria das comparações resulta em troca\n");
  print_separator();

  reset_counters();

  /* ── BREAKPOINT SUGERIDO: antes de chamar shell_sort ──────────────────
   * (gdb) break test_worst_case
   * (gdb) break shell_sort
   * (gdb) watch g_trocas          ← veja o contador aumentar a cada swap
   * (gdb) watch g_sem_troca       ← poucas vezes disparará aqui
   * ─────────────────────────────────────────────────────────────────── */
  shell_sort(v, n);

  print_array(v, n, "Saída");
  print_report();
}

/* =========================================================================
 * main — ponto de entrada da sessão de depuração
 * ========================================================================= */
int main(void) {
  printf("\n");
  printf("══════════════════════════════════════════════════════════\n");
  printf("  Análise de Algoritmos — Shell Sort com GDB\n");
  printf("  Sequência de gaps: n/2, n/4, ..., 1  (Shell clássico)\n");
  printf("══════════════════════════════════════════════════════════\n");

  test_best_case();
  test_worst_case();

  printf("\n══════════════════════════════════════════════════════════\n");
  printf("  Fim da sessão. Compare os relatórios acima.\n");
  printf("══════════════════════════════════════════════════════════\n\n");

  return 0;
}
