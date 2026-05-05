#include <stdlib.h>

void q11(int LIN, int COL)
{
    int **p = (int**) malloc(LIN*sizeof(int));
    int i, j;

    int matriz[LIN][COL];

    for (i=LIN-1; i>=0; i--)
    {
        p[i] = (int*) malloc(COL*sizeof(int));
        for (j=0; j<COL; j++)
        {
            p[i][j] = 10*(i+1) + (j+1); matriz[i][j] = p[i][j];
        }
    }

    for (i=LIN-1; i>=0; i--)
    {
        free(p[i]);
        p[i] = NULL;
    }

    free(p);
    p = NULL;
}

void q11_expandida(int LIN, int COL)
{
    int **p = (int**) malloc(LIN*sizeof(int));  // c1
    int i, j;                                   // c2

    int matriz[LIN][COL];                       // c3

    for (i=LIN-1; i>=0; i--)                    // c4 (inicialização: 1 vez)
                                                // c5 (teste: LIN + 1 vezes)
                                                // c6 (passo: LIN vezes)
    {
        p[i] = (int*) malloc(COL*sizeof(int));  // c7 (alocação: LIN vezes)
        for (j=0; j<COL; j++)                   // c8 (inicialização: LIN vezes)
                                                // c9 (teste: LIN*(COL + 1) vezes)
                                                // c10 (passo: LIN*COL vezes)
        {
            p[i][j] = 10*(i+1) + (j+1);         // c11 (corpo: LIN*COL vezes)
            matriz[i][j] = p[i][j];             // c12 (corpo: LIN*COL vezes)
        }
    }

    for (i=LIN-1; i>=0; i--)                    // c13 (inicialização: 1 vez)
                                                // c14 (teste: LIN + 1 vezes)
                                                // c15 (passo: LIN vezes)
    {
        free(p[i]);                             // c16 (corpo: LIN vezes)
        p[i] = NULL;                            // c17 (corpo: LIN vezes)
    }

    free(p);                                    // c18
    p = NULL;                                   // c19
}

/*
FUNÇÃO DE CUSTO T(LIN, COL)
=========================================================================
Como a entrada do problema envolve 2 variáveis independentes de tamanho
LIN e COL, a função de custo irá depender de ambas.

O primeiro laço executa LIN vezes e para cada iteração do mesmo o laço interno 
executa COL vezes, totalizando LIN*COL operações no corpo.
O segundo laço executa LIN vezes liberando a memória alocada.
Não há quebras de laços antecipadas (break/return).

T(LIN, COL) = c1 + c2 + c3 + c4 + (LIN+1)c5 + LIN(c6) + LIN(c7) + LIN(c8) 
              + LIN*(COL+1)c9 + LIN*COL(c10) +  LIN*COL(c11 + c12) 
              + c13 + (LIN+1)c14 + LIN(c15 + c16 + c17) + c18 + c19
              
T(LIN, COL) = a*LIN*COL + b*LIN + c

O desempenho é estritamente atrelado às dimensões LIN e COL sem variação
extra baseada nos valores.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(LIN, COL) = a*LIN*COL + b*LIN + c → O(LIN * COL)
- Melhor caso: T(LIN, COL) = a*LIN*COL + b*LIN + c → Ω(LIN * COL)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(N * M) (assumindo N=LIN, M=COL)
- Big Ω: Ω(N * M)
- Big Θ: Θ(N * M)

Portanto, o algoritmo possui crescimento polinomial de grau 2 (bilinear).
========================================================================= 
*/

