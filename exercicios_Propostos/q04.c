void q04(int n)
{
    int i, j;

    for (i = 1; i < n; i *= 2)
    {
        for (j = 0; j < n; j++)
        {
        }
    }
}

void q04_expandida(int n)
{
    int i, j;                     // c1

    for (i = 1; i < n; i *= 2)    // c2 (inicialização: 1 vez)
                                  // c3 (teste: log2(n) + 1 vezes)
                                  // c4 (passo: log2(n) vezes)
    {
        for (j = 0; j < n; j++)   // c5 (inicialização: log2(n) vezes)
                                  // c6 (teste: log2(n) * (n + 1) vezes)
                                  // c7 (passo: log2(n) * n vezes)
        {
                                  // c8 (corpo: log2(n) * n vezes)
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que o loop de fora começa com i=1 e dobra a cada iteração, ele 
executa log2(n) vezes.
Para cada vez, o loop interno executa n vezes.

T(n) = c1 + c2 + (log2(n) + 1)c3 + log2(n)c4 
       + log2(n)c5 + (n*log2(n) + log2(n))c6 + n*log2(n)c7 + n*log2(n)c8

T(n) = a*(n*log(n)) + b*log(n) + c

Os loops são determinísticos para um dado N e não dependem do arranjo 
interno dos dados. Melhor e pior caso têm a mesma complexidade.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*(n*log(n)) + b*log(n) + c → O(n log n)
- Melhor caso: T(n) = a*(n*log(n)) + b*log(n) + c → Ω(n log n)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n log n)
- Big Ω: Ω(n log n)
- Big Θ: Θ(n log n)

Portanto, o algoritmo possui crescimento linearítmico.
========================================================================= 
*/
