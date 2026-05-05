#include <stdio.h>

void q03(int n) {
  int i, j;
  // assuma n > 0

  for (i = 0; i < n; i++) {
    j = n;
    printf("%d \n", i);
    if (i + j < 0) {
      return;
    }
    while (j > 0) {
      j /= 2;
      printf("\t%d", j);
    }
    printf("\n\n");
  }
}

void q03_expandida(int n) {
  int i, j; // c1
  // assuma n > 0

  for (i = 0; i < n; i++) // c2 (inicialização)
                          // c3 (teste: n + 1 vezes)
                          // c4 (passo: n vezes)
  {
    j = n;              // c5 (executa n vezes)
    printf("%d \n", i); // c6 (executa n vezes)
    if (i + j < 0)      // c7 (executa n vezes)
    {
      return; // c8 (nunca executa contanto que n > 0 e i >= 0)
    }
    while (j > 0) // c9 (teste: log2(n) + 1 vezes para cada iteração do for.
                  // Total n*(log2(n) + 1))
    {
      j /= 2; // c10 (passo: log2(n) vezes para cada iteração do for. Total
              // n*log2(n))
      printf("\t%d", j); // c11 (passo: log2(n) vezes para cada iteração do for.
                         // Total n*log2(n))
    }
    printf("\n\n"); // c12 (executa n vezes)
  }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que n > 0, e 'i' vai de 0 a n-1, i+j = i+n será > 0,
logo nunca entrará no if e não haverá interrupção precoce.
O loop interno divide j por 2, então será executado aproximadamente log2(n)
vezes.

T(n) = c1 + c2 + (n + 1)c3 + nc4 + nc5 + nc6 + nc7
       + n*(log2(n) + 1)c9 + n*log2(n)c10 + n*log2(n)c11 + nc12

T(n) = a*(n*log(n)) + b*n + c

Não há variação dependendo do conteúdo da entrada, apenas do tamanho n.
Logo, melhor e pior caso são iguais.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*(n*log(n)) + b*n + c  → O(n log n)
- Melhor caso: T(n) = a*(n*log(n)) + b*n + c → Ω(n log n)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n log n)
- Big Ω: Ω(n log n)
- Big Θ: Θ(n log n)

Portanto, o algoritmo possui crescimento linearítmico.
=========================================================================
*/
