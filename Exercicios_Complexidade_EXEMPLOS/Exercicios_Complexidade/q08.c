int q8(int v[], int n, int x)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int q8_expandida(int v[], int n, int x)
{
    int i;                 // c1

    for (i = 0; i < n; i++)   // c2 (inicialização 1 vez)
                               // + c3 (teste n+1 vezes)
                               // + c4 (passo n vezes)
    {
        if (v[i] == x)        // c5 (teste n vezes no pior caso, ≤ n no melhor caso)
        {
            return i;         // c6 (executa 1 vez no melhor caso, 
                              //     0 no pior caso se não encontrado)
        }
    }
    return -1;                // c7 (executa 1 vez)
}

/*
FUNÇÃO DE CUSTO T(n)

FUNÇÃO DE CUSTO T(n)
T(n) = c1 
     + c2 + (n+1)c3 + n c4
     + n c5 + c6 ou 0
     + c7

PIOR CASO
O elemento x não está no vetor, então o laço percorre todos os elementos:

T_pior(n) = c1 
          + c2 + (n+1)c3 + n c4
          + n c5
          + c7

MELHOR CASO
O elemento x está na primeira posição:

T_melhor(n) = c1 
            + c2 + 1*c3 + 1*c4
            + 1*c5 + c6
            + c7

ANÁLISE ASSINTÓTICA

Pior caso: T(n) ∈ O(n) e Ω(n)
Melhor caso: T(n) ∈ O(1) e Ω(1)

CONCLUSÃO

A busca linear tem complexidade linear no pior caso e constante no melhor caso.
*/