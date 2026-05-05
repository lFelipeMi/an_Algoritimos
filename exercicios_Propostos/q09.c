#include <stdlib.h>

void q09(int n)
{
    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i] += j;
        }
    }

    free(v);
}

void q09_expandida(int n)
{
    int *v = malloc(n * sizeof(int)); // c1 (alocação: 1 vez)

    for (int i = 0; i < n; i++)       // c2 (inicialização: 1 vez)
                                      // c3 (teste: n + 1 vezes)
                                      // c4 (passo: n vezes)
    {
        for (int j = 0; j < n; j++)   // c5 (inicialização: n vezes)
                                      // c6 (teste: n * (n + 1) vezes)
                                      // c7 (passo: n * n vezes)
        {
            v[i] += j;                // c8 (corpo: n * n vezes)
        }
    }

    free(v);                          // c9 (liberação: 1 vez)
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que a alocação é O(1) com respeito ao nosso modelo de T(n):
Loop externo executa n iterações completas.
Loop interno sempre executa completamente 0 a n-1, logo n vezes para cada
iteração do externo, totalizando n*n.

T(n) = c1 + c2 + (n+1)c3 + nc4 + nc5 + (n^2 + n)c6 + (n^2)c7 + (n^2)c8 + c9

T(n) = a*n^2 + b*n + c

Este valor é determinístico e independente do conteúdo dos dados, sem
variações de percurso (branches) condicionais além das contagens dos
próprios laços.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n^2 + b*n + c → O(n^2)
- Melhor caso: T(n) = a*n^2 + b*n + c → Ω(n^2)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n^2)
- Big Ω: Ω(n^2)
- Big Θ: Θ(n^2)

Portanto, o algoritmo possui crescimento polinomial quadrático.
========================================================================= 
*/
