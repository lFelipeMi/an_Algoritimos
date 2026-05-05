#include <stdlib.h>

void q14(int n)
{
    int *v = malloc(n * sizeof(int));
    int i = 0;

    while (i < n)
    {
        v[i] = i;
        i += i;

        if (i > 0)
        {
            i += i;
        }
    }

    free(v);
}

void q14_expandida(int n)
{
    int *v = malloc(n * sizeof(int)); // c1
    int i = 0;                        // c2

    while (i < n)                     // c3 (teste)
    {
        v[i] = i;                     // c4 (corpo)
        i += i;                       // c5 (corpo)

        if (i > 0)                    // c6 (teste if)
        {
            i += i;                   // c7 (corpo if)
        }
    }

    free(v);                          // c8
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Para valores de n <= 0, o loop while não é executado nenhuma vez
e o programa termina em O(1).
Para valores de n > 0, o loop inicia com i = 0.
A cada iteração, i recebe i + i (isto é, 0 + 0 = 0).
Como i nunca é maior que 0, a condição if(i > 0) nunca é verdadeira.
Portanto, i continuará sendo 0 para sempre e a condição i < n 
será sempre verdadeira, caracterizando um LOOP INFINITO.

Caso a inicialização fosse i = 1 (possível erro de digitação original),
i seria multiplicado por 4 a cada iteração, tornando T(n) em O(log n).
Mas com o código atual exato, a execução pendura.

T(n) = a*infinito (para n > 0)
T(n) = c (para n <= 0)

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso (n > 0): O(infinito) - não termina.
- Melhor caso (n <= 0): O(1) - tempo constante.

CONCLUSÃO
=========================================================================
O algoritmo apresenta um loop infinito para n > 0 pelo fato da variável i 
não crescer, ficando estagnada em O.
Se a análise desconsiderar o loop infinito (assumindo i iniciando em 1),
ele teria um crescimento logarítmico O(log n). Como está escrito 
atualmente, o custo é não-limitado.
========================================================================= 
*/
