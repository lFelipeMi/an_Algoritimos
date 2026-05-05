#include <stdlib.h>

void q13(int n)
{
    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
        int j = 1;

        while (j < n)
        {
            j *= 2;
        }
    }

    free(v);
}

void q13_expandida(int n)
{
    int *v = malloc(n * sizeof(int)); // c1 (alocação: 1 vez)

    for (int i = 0; i < n; i++)       // c2 (inicialização: 1 vez)
                                      // c3 (teste: n + 1 vezes)
                                      // c4 (passo: n vezes)
    {
        v[i] = 0;                     // c5 (corpo: n vezes)
        int j = 1;                    // c6 (corpo: n vezes)

        while (j < n)                 // c7 (teste: n * (log2(n) + 1) vezes)
        {
            j *= 2;                   // c8 (corpo loop interno: n * log2(n) vezes)
        }
    }

    free(v);                          // c9 (liberação: 1 vez)
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Loop externo roda n vezes incrementando i de 0 até n-1. 
Para cada iteração deste laço externo, é iniciado um while que inicia j em 1
e multiplica j por 2 seguidas vezes até que j alcance 'n'.  
Isso toma log2(n) iterações no while para CADA passo do laço de n,
o que totaliza n * log2(n) execuções da operação 'j *= 2'.

T(n) = c1 + c2 + (n+1)c3 + n(c4 + c5 + c6) + n*(log2(n) + 1)c7 + n*log2(n)c8 + c9

T(n) = a*(n*log(n)) + b*n + c

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*(n*log(n)) + b*n + c → O(n log n)
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
