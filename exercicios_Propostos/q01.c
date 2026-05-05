int q01(int n)
{
    int i, j, count = 0;
    int v[n];

    for (i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            for (j = 0; j < n; j++)
            {
                count = count + j;
            }
        }
    }

    return count;
}

int q01_expandida(int n)
{
    int i;                // c1
    int j;                // c2
    int count = 0;        // c3
    int v[n];             // c4

    for (i = 0; i < n; i++)   // c5 (inicialização)
                              // c6 (teste: executa n + 1 vezes)
                              // c7 (passo: executa n vezes)
    {
        if (v[i] % 2 == 0)    // c8 (executa n vezes)
        {
            for (j = 0; j < n; j++) // c9 (inicialização: executa dependendo do caso)
                                    // c10 (teste: executa dependendo do caso, n + 1 vezes por loop quando entra)
                                    // c11 (passo: executa dependendo do caso, n vezes por loop quando entra)
            {
                count = count + j;  // c12 (executa dependendo do caso, n vezes por loop quando entra)
            }
        }
    }

    return count;         // c13
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando:
- Inicializações: c1 + c2 + c3 + c4
- For externo (i):
    - Inicialização: c5
    - Teste: (n + 1) * c6
    - Passo: n * c7
    - Corpo:
        - if: n * c8
        - For interno (j):
            - Inicialização: depende da condição do if (máximo n * c9)
            - Teste: depende da condição (máximo n * (n + 1) * c10)
            - Passo: depende da condição (máximo n * n * c11)
            - Corpo count: depende da condição (máximo n * n * c12)
- Retorno: c13

PIOR CASO (todos os v[i] são pares):
--------------------------------------------------
T_pior(n) =
    c1 + c2 + c3 + c4
    + c5
    + (n + 1)c6
    + n c7
    + n c8
    + n(c9 + (n + 1)c10 + n c11 + n c12)
    + c13
    
T_pior(n) = a*n^2 + b*n + c

MELHOR CASO (nenhum v[i] é par):
--------------------------------------------------
T_melhor(n) =
    c1 + c2 + c3 + c4
    + c5
    + (n + 1)c6
    + n c7
    + n c8
    + c13

T_melhor(n) = a*n + b
(sem execução do for interno)

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n^2 + b*n + c  → O(n^2)
- Melhor caso: T(n) = a*n + b → Ω(n)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n^2)
- Big Ω: Ω(n)

Portanto, o algoritmo possui
crescimento polinomial quadrático no pior caso e linear no melhor caso.
========================================================================= 
*/
