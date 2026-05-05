void q05(int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            for (j = 0; j < n; j++)
            {
            }
        }
    }
}

void q05_expandida(int n)
{
    int i, j;                     // c1

    for (i = 0; i < n; i++)       // c2 (inicialização: 1 vez)
                                  // c3 (teste: n + 1 vezes)
                                  // c4 (passo: n vezes)
    {
        if (i == n - 1)           // c5 (teste if: n vezes)
        {
            for (j = 0; j < n; j++) // c6 (inicialização: 1 vez)
                                    // c7 (teste: n + 1 vezes)
                                    // c8 (passo: n vezes)
            {
                                    // c9 (corpo: n vezes)
            }
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que o loop externo executa de 0 a n-1, total de n vezes.
O if só tem condição verdadeira na última iteração do loop, quando i == n - 1.
Portanto, o loop interno só é alcançado e iniciado exatamente 1 vez em toda
a execução do programa. E ele roda por n vezes.

T(n) = c1 + c2 + (n + 1)c3 + nc4 + nc5 + c6 + (n + 1)c7 + nc8 + nc9

T(n) = a*n + b

A estrutura é determinística para um tamanho n. A condição if vai ser
satisfeita exatamente 1 vez independentemente da entrada (exceto do
próprio tamanho n). Por isso não há distinção para pior e melhor caso
com base no conteúdo da entrada.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n + b → O(n)
- Melhor caso: T(n) = a*n + b → Ω(n)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n)
- Big Ω: Ω(n)
- Big Θ: Θ(n)

Portanto, o algoritmo possui crescimento linear.
========================================================================= 
*/
