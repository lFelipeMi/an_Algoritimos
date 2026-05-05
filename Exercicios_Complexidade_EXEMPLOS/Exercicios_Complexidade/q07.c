void q7()
{
    int i, j, n = 100;

    for (i = 0; i < n; i++)
    {
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
        }
    }
}

void q7_expandida()
{
    int i;            // c1
    int j;            // c2
    int n;            // c3
    n = 100;          // c4

    for (i = 0; i < n; i++)       // c5 (inicialização 1 vez)
                                   // + c6 (teste n+1 vezes)
                                   // + c7 (passo n vezes)
    {
        // corpo vazio
    }

    for (i = 0; i < n; i++)       // c8 (inicialização 1 vez)
                                   // + c9 (teste n+1 vezes)
                                   // + c10 (passo n vezes)
    {
        for (j = 0; j < n; j++)   // c11 (inicialização 1 vez)
                                   // + c12 (teste n+1 vezes)
                                   // + c13 (passo n vezes)
        {
            // corpo vazio
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
T(n) = c1 + c2 + c3 + c4
     + c5 + (n+1)c6 + n c7
     + c8 + (n+1)c9 + n c10
     + c11 + (n+1)c12 + n c13

PIOR CASO
Todos os laços são percorridos completamente:

T_pior(n) = c1 + c2 + c3 + c4
          + c5 + (n+1)c6 + n c7
          + c8 + (n+1)c9 + n c10
          + c11 + (n+1)c12 + n c13

MELHOR CASO
Não há condições que alterem o número de iterações, então:

T_melhor(n) = T_pior(n) = a n^2 + b n + c

ANÁLISE ASSINTÓTICA

T(n) ∈ O(n^2)
T(n) ∈ Ω(n^2)

CONCLUSÃO

O algoritmo possui complexidade quadrática no pior e no melhor caso
*/