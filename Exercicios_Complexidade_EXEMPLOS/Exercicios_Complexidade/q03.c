void q3()
{
    int i, j, n = 100;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
        }
    }
}

void q3_expandida()
{
    int i;            // c1
    int j;            // c2
    int n;            // c3
    n = 100;          // c4

    for (i = 0; i < n; i++)   // c5 (inicialização) 
                              // + c6 (teste n+1 vezes) 
                              // + c7 (passo n vezes)
    {
        for (j = 0; j < n; j++)   // c8 (inicialização) 
                                  // + c9 (teste n*(n+1) vezes) 
                                  // + c10 (passo n*n vezes)
        {
            // corpo vazio
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
T(n) = c1 + c2 + c3 + c4 
     + c5 + (n + 1)c6 + nc7 
     + c8 + n*(n + 1)c9 + n*n*c10

PIOR CASO
Todos os laços são executados completamente, sem interrupções:

T_pior(n) = c1 + c2 + c3 + c4 
          + c5 + (n + 1)c6 + nc7 
          + c8 + n*(n + 1)c9 + n*n*c10

Simplificando:
T_pior(n) = an^2 + bn + c

MELHOR CASO
Não há condições que alterem o número de iterações, então:

T_melhor(n) = T_pior(n) = an^2 + bn + c

ANÁLISE ASSINTÓTICA

T(n) ∈ O(n^2)
T(n) ∈ Ω(n^2)

CONCLUSÃO

O algoritmo possui complexidade quadrática 
tanto no melhor quanto no pior caso
*/