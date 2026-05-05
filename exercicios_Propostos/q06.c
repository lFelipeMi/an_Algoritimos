void q06(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = i; j < i + n; j++)
        {
        }
    }
}

void q06_expandida(int n)
{
    int i, j;                     // c1

    for (i = 0; i < n; i++)       // c2 (inicialização: 1 vez)
                                  // c3 (teste: n + 1 vezes)
                                  // c4 (passo: n vezes)
    {
        for (j = i; j < i + n; j++) // c5 (inicialização: n vezes)
                                    // c6 (teste: n * (n + 1) vezes)
                                    // c7 (passo: n * n vezes)
        {
                                    // c8 (corpo: n * n vezes)
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que o loop externo roda n vezes.
O loop interno começa em 'i' e vai até 'i+n-1'. Como j é incrementado 
em 1 a cada passo, ele faz sempre exatamente ((i+n-1) - i) + 1 = n iterações
para cada passo do loop externo.

T(n) = c1 + c2 + (n + 1)c3 + nc4 + nc5 + (n^2 + n)c6 + (n^2)c7 + (n^2)c8

T(n) = a*n^2 + b*n + c

Este valor é fixo para o n, resultando em desempenho idêntico 
para melhor e pior caso.

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
