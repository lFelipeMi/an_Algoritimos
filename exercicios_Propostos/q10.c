#include <stdlib.h>

void q10(int n)
{
    int **m = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        m[i] = malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
        {
            m[i][j] = i + j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(m[i]);
    }

    free(m);
}

void q10_expandida(int n)
{
    int **m = malloc(n * sizeof(int*)); // c1 (alocação array de pos: 1 vez)

    for (int i = 0; i < n; i++)         // c2 (inicialização: 1 vez)
                                        // c3 (teste: n + 1 vezes)
                                        // c4 (passo: n vezes)
    {
        m[i] = malloc(n * sizeof(int)); // c5 (alocação linha: n vezes)

        for (int j = 0; j < n; j++)     // c6 (inicialização: n vezes)
                                        // c7 (teste: n * (n + 1) vezes)
                                        // c8 (passo: n * n vezes)
        {
            m[i][j] = i + j;            // c9 (corpo: n * n vezes)
        }
    }

    for (int i = 0; i < n; i++)         // c10 (inicialização: 1 vez)
                                        // c11 (teste: n + 1 vezes)
                                        // c12 (passo: n vezes)
    {
        free(m[i]);                     // c13 (corpo - liberação linha: n vezes)
    }

    free(m);                            // c14 (liberação principal: 1 vez)
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Primeiro for percorre n vezes. O de dentro mais n vezes. Malloc entra nas 
operações de tempo fixo no laço principal e O(n^2) no interior, atribuindo 
somas para cada índice da matriz NxN.
Temos mais um array for após o primeiro de duas vias. Ele roda n vezes e 
libera linha por linha.
Finalizando com um free fora do laço.

T(n) = c1 + c2 + (n+1)c3 + nc4 + nc5 + nc6 + (n^2+n)c7 + (n^2)c8 + (n^2)c9 
       + c10 + (n+1)c11 + nc12 + nc13 + c14

T(n) = a*n^2 + b*n + c

Este valor é determinístico e não possui nenhuma condicional oculta.
Logo o custo continua simétrico tanto para melhor quanto a pior suposição.

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

Portanto, o algoritmo possui crescimento polinomial quadrático dominado
pelo aninhamento duplo.
========================================================================= 
*/
