void q01()
{
    int i, n = 100, count = 0;
    int v[n];

    for (i = 0; i < n; i++) 
    {
        if (v[i] > 0)
        {
            count++;
        }
    }
}



void q01_expandida()
{
    int i;                // c1
    int n = 100;          // c2
    int count = 0;        // c3
    int v[n];             // c4

    for (i = 0; i < n; i++)   // c5 (inicialização)
                              // c6 (teste: executa n + 1 vezes)
                              // c7 (passo: executa n vezes)
    {
        if (v[i] > 0)         // c8 (executa n vezes)
        {
            count++;          // c9 (executa dependendo do caso)
        }
    }
}



/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando:
- Inicializações: c1 + c2 + c3 + c4
- For:
    - Inicialização: c5
    - Teste: (n + 1) * c6
    - Passo: n * c7
    - Corpo:
        - if: n * c8
        - count++: depende da condição

PIOR CASO (todos v[i] > 0):
--------------------------------------------------
T_pior(n) =
    c1 + c2 + c3 + c4
    + c5
    + (n + 1)c6
    + n c7
    + n c8
    + n c9

T_pior(n) = a*n + b

MELHOR CASO (nenhum v[i] > 0):
--------------------------------------------------
T_melhor(n) =
c1 + c2 + c3 + c4
+ c5
+ (n + 1)c6
+ n c7
+ n c8

T_melhor(n) = a*n + b
(sem execução de c9)

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n + b  → O(n)
- Melhor caso: T(n) = a*n + b → Ω(n)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n)
- Big Ω: Ω(n)

Portanto, o algoritmo possui 
crescimento linear em todos os casos.
========================================================================= 
*/